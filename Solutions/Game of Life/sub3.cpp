#include <bits/stdc++.h>
using namespace std;

constexpr int RULE = 45;

struct Query {
    int state;
    unsigned long long k;
    int pos;
};

int next_state(int state, int N) {
    int nxt = 0;

    for (int i = 0; i < N; i++) {
        int l = (i - 1 + N) % N;
        int r = (i + 1) % N;

        int L = (state >> l) & 1;
        int C = (state >> i) & 1;
        int R = (state >> r) & 1;

        int pattern = (L << 2) | (C << 1) | R;

        if ((RULE >> pattern) & 1)
            nxt |= 1 << i;
    }

    return nxt;
}

int encode(const string &s) {
    int state = 0;

    for (int i = 0; i < (int)s.size(); i++)
        if (s[i] == '1')
            state |= 1 << i;

    return state;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<Query> query(Q);

    bool same = true;
    int first_state = -1;

    for (int q = 0; q < Q; q++) {
        string S;

        cin >> S >> query[q].k >> query[q].pos;

        query[q].state = encode(S);

        if (q == 0)
            first_state = query[q].state;
        else if (query[q].state != first_state)
            same = false;
    }

    // Subtask 2 / 3
    if (same) {
        vector<int> first(1 << N, -1);
        vector<int> seq;

        int cur = first_state;

        while (first[cur] == -1) {
            first[cur] = seq.size();
            seq.push_back(cur);

            cur = next_state(cur, N);
        }

        int mu = first[cur];
        int lambda = (int)seq.size() - mu;

        for (auto &q : query) {
            unsigned long long index;

            if (q.k < seq.size()) {
                index = q.k;
            } else {
                index = mu + (q.k - mu) % lambda;
            }

            int state = seq[index];

            cout << ((state >> (q.pos - 1)) & 1) << '\n';
        }

        return 0;
    }

    // Subtask 1 fallback
    for (auto &q : query) {
        int cur = q.state;

        for (unsigned long long step = 0; step < q.k; step++)
            cur = next_state(cur, N);

        cout << ((cur >> (q.pos - 1)) & 1) << '\n';
    }
}