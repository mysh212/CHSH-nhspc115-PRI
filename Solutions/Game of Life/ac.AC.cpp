#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 18;
constexpr int MAXS = 1 << MAXN;
constexpr int LG = 60;
constexpr int RULE = 45;

int up[LG][MAXS];

int N;

int next_state(int state) {
    int nxt = 0;

    for (int i = 0; i < N; i++) {
        int l = (i - 1 + N) % N;
        int r = (i + 1) % N;

        int L = (state >> l) & 1;
        int C = (state >> i) & 1;
        int R = (state >> r) & 1;

        int pattern = (L << 2) | (C << 1) | R;

        int bit = (RULE >> pattern) & 1;

        if (bit) {
            nxt |= (1 << i);
        }
    }

    return nxt;
}

int encode(const string &s) {
    int state = 0;

    for (int i = 0; i < N; i++) {
        if (s[i] == '1') {
            state |= (1 << i);
        }
    }

    return state;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> N >> Q;

    int S = 1 << N;

    for (int state = 0; state < S; state++) {
        up[0][state] = next_state(state);
    }

    for (int b = 1; b < LG; b++) {
        for (int state = 0; state < S; state++) {
            up[b][state] = up[b - 1][up[b - 1][state]];
        }
    }

    while (Q--) {
        string s;
        unsigned long long K;
        int i;

        cin >> s >> K >> i;

        int state = encode(s);

        for (int b = 0; b < LG; b++) {
            if ((K >> b) & 1ULL) {
                state = up[b][state];
            }
        }

        --i;

        cout << ((state >> i) & 1) << '\n';
    }

    return 0;
}