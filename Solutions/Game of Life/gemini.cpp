#include <iostream>
#include <vector>
#include <string>

using namespace std;

static const int RULE = 45;

int main() {
    // 優化標準 I/O 速度
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    if (!(cin >> N >> Q))
        return 0;

    int M = 1 << N;
    vector<int> nxt(M, 0);
    vector<int> in_deg(M, 0);

    // 1. 預處理每個狀態在 Rule 45 下的下一個狀態
    for (int u = 0; u < M; ++u) {
        int next_u = 0;
        for (int j = 0; j < N; ++j) {
            int L = (u >> ((j - 1 + N) % N)) & 1;
            int C = (u >> j) & 1;
            int R = (u >> ((j + 1) % N)) & 1;
            int pattern = (L << 2) | (C << 1) | R;
            int next_bit = (RULE >> pattern) & 1;
            next_u |= (next_bit << j);
        }
        nxt[u] = next_u;
        in_deg[next_u]++;
    }

    // 2. 拓撲排序找出樹枝節點
    vector<int> q;
    q.reserve(M);
    for (int i = 0; i < M; ++i) {
        if (in_deg[i] == 0) {
            q.push_back(i);
        }
    }
    for (size_t head = 0; head < q.size(); ++head) {
        int u = q[head];
        int v = nxt[u];
        if (--in_deg[v] == 0) {
            q.push_back(v);
        }
    }

    // 3. 找出所有環 (in_deg > 0 的節點即在環上)
    vector<int> cycle_id(M, -1);
    vector<int> cycle_pos(M, -1);
    vector<int> depth(M, 0);
    vector<int> entry(M, 0);
    vector<vector<int>> cycles;

    int cid = 0;
    for (int i = 0; i < M; ++i) {
        if (in_deg[i] > 0 && cycle_id[i] == -1) {
            vector<int> cyc;
            int curr = i;
            while (cycle_id[curr] == -1) {
                cycle_id[curr] = cid;
                cycle_pos[curr] = cyc.size();
                entry[curr] = curr;
                depth[curr] = 0;
                cyc.push_back(curr);
                curr = nxt[curr];
            }
            cycles.push_back(cyc);
            cid++;
        }
    }

    // 4. 反向遍歷拓撲序，計算樹枝節點的 depth 與 entry
    for (int i = (int)q.size() - 1; i >= 0; --i) {
        int u = q[i];
        int v = nxt[u];
        depth[u] = depth[v] + 1;
        entry[u] = entry[v];
    }

    // 5. 建立倍增表 (用於在樹枝上快速跳躍)
    // 最大深度不超過 M = 2^18，所以 19 層足夠
    vector<vector<int>> up(19, vector<int>(M));
    for (int u = 0; u < M; ++u) {
        up[0][u] = nxt[u];
    }
    for (int k = 1; k < 19; ++k) {
        for (int u = 0; u < M; ++u) {
            up[k][u] = up[k - 1][up[k - 1][u]];
        }
    }

    // 6. 回答 Q 筆詢問
    while (Q--) {
        string S;
        long long K;
        int idx;
        cin >> S >> K >> idx;

        // 將狀態字串轉換成二進位整數
        int u = 0;
        for (int j = 0; j < N; ++j) {
            if (S[j] == '1') {
                u |= (1 << j);
            }
        }

        int final_state = 0;
        if (K < depth[u]) {
            // 仍在樹枝上，使用倍增法跳 K 步
            int curr = u;
            for (int k = 18; k >= 0; --k) {
                if ((K >> k) & 1) {
                    curr = up[k][curr];
                }
            }
            final_state = curr;
        } else {
            // 已進入環，計算環上偏移量
            long long rem = K - depth[u];
            int r = entry[u];
            int c = cycle_id[r];
            int len = cycles[c].size();
            int final_pos = (cycle_pos[r] + (rem % len)) % len;
            final_state = cycles[c][final_pos];
        }

        // 輸出第 idx 個細胞（1-based，對應第 idx - 1 個 bit）
        cout << ((final_state >> (idx - 1)) & 1) << "\n";
    }

    return 0;
}