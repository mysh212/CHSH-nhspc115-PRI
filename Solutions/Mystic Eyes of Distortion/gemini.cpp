#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int INF = 1e9;

// 儲存網格坐標
struct Point {
    int x, y;
};

int main() {
    // 優化 I/O 速度
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N))
        return 0;

    int total_size = 2 * N + 1;
    vector<string> grid(total_size);
    for (int i = 0; i < total_size; ++i) {
        cin >> grid[i];
    }

    // 建立每個環的坐標與對應的原始狀態
    vector<vector<Point>> ring_coords(N + 1);
    vector<vector<int>> orig_state(N + 1);
    vector<vector<int>> ring_id(total_size, vector<int>(total_size, 0));
    vector<vector<int>> pos_in_ring(total_size, vector<int>(total_size, 0));

    ring_coords[0].push_back({N, N});
    orig_state[0].push_back(1); // 中心必定可通行

    for (int r = 1; r <= N; ++r) {
        // 依照順時針方向依序加入第 r 環的坐標
        // 1. 上邊 (從左上到右上，不含右上角)
        for (int k = 0; k < 2 * r; ++k)
            ring_coords[r].push_back({N - r, N - r + k});
        // 2. 右邊 (從右上到右下，不含右下角)
        for (int k = 0; k < 2 * r; ++k)
            ring_coords[r].push_back({N - r + k, N + r});
        // 3. 下邊 (從右下到左下，不含左下角)
        for (int k = 0; k < 2 * r; ++k)
            ring_coords[r].push_back({N + r, N + r - k});
        // 4. 左邊 (從左下到左上，不含左上角)
        for (int k = 0; k < 2 * r; ++k)
            ring_coords[r].push_back({N + r - k, N - r});

        int len = 8 * r;
        orig_state[r].resize(len);
        for (int i = 0; i < len; ++i) {
            Point p = ring_coords[r][i];
            ring_id[p.x][p.y] = r;
            pos_in_ring[p.x][p.y] = i;
            orig_state[r][i] = (grid[p.x][p.y] == '.' ? 1 : 0);
        }
    }

    // 預先計算每個環上位置向內相鄰的格子索引
    // 每個格子最多只有 1 個向內的相鄰格子
    vector<vector<int>> inner_neighbor(N + 1);
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    for (int r = 1; r <= N; ++r) {
        int len = 8 * r;
        inner_neighbor[r].assign(len, -1);
        for (int i = 0; i < len; ++i) {
            Point p = ring_coords[r][i];
            for (int d = 0; d < 4; ++d) {
                int nx = p.x + dx[d];
                int ny = p.y + dy[d];
                if (nx >= 0 && nx < total_size && ny >= 0 && ny < total_size) {
                    if (ring_id[nx][ny] == r - 1) {
                        inner_neighbor[r][i] = pos_in_ring[nx][ny];
                        break;
                    }
                }
            }
        }
    }

    // DP 陣列：dp[r][i] 表示到達第 r 環位置 i 的最小消耗魔力
    vector<vector<int>> dp(N + 1);
    dp[0] = {0}; // 第 0 環只有中心格

    for (int r = 1; r <= N; ++r) {
        int len = 8 * r;
        dp[r].assign(len, INF);

        // 枚舉順時針旋轉量 s
        for (int s = 0; s < len; ++s) {
            int cost_s = min(s, len - s);

            // 當前旋轉下的盤面狀態
            vector<int> cur_state(len);
            int count_ones = 0;
            for (int j = 0; j < len; ++j) {
                cur_state[j] = orig_state[r][(j - s + len) % len];
                if (cur_state[j] == 1)
                    count_ones++;
            }

            if (count_ones == 0)
                continue;

            // 尋找環狀連通塊
            vector<vector<int>> components;
            if (count_ones == len) {
                vector<int> comp(len);
                for (int j = 0; j < len; ++j)
                    comp[j] = j;
                components.push_back(comp);
            } else {
                for (int j = 0; j < len; ++j) {
                    int prev = (j - 1 + len) % len;
                    // 連通塊的起點：前一個是 0 且當前是 1
                    if (cur_state[j] == 1 && cur_state[prev] == 0) {
                        vector<int> comp;
                        int curr = j;
                        while (cur_state[curr] == 1) {
                            comp.push_back(curr);
                            curr = (curr + 1) % len;
                        }
                        components.push_back(comp);
                    }
                }
            }

            // 對於每個連通塊，計算從第 r-1 環進入所需的最小總魔力
            for (const auto &comp : components) {
                int min_in_cost = INF;
                for (int u : comp) {
                    int v = inner_neighbor[r][u];
                    if (v != -1 && dp[r - 1][v] < INF) {
                        min_in_cost = min(min_in_cost, dp[r - 1][v]);
                    }
                }

                // 若能進入該連通塊，則更新連通塊內所有位置的最短距離
                if (min_in_cost < INF) {
                    int total_cost = min_in_cost + cost_s;
                    for (int u : comp) {
                        dp[r][u] = min(dp[r][u], total_cost);
                    }
                }
            }
        }
    }

    // 取得抵達最外層（第 N 環）的最小花費
    int ans = INF;
    for (int cost : dp[N]) {
        ans = min(ans, cost);
    }

    if (ans >= INF) {
        cout << -1 << "\n";
    } else {
        cout << ans << "\n";
    }

    return 0;
}