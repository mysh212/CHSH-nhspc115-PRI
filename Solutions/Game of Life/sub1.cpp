#include <bits/stdc++.h>
using namespace std;

constexpr int RULE = 45;

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

    while (Q--) {
        string S;
        unsigned long long K;
        int i;

        cin >> S >> K >> i;

        int state = encode(S);

        for (unsigned long long step = 0; step < K; step++)
            state = next_state(state, N);

        cout << ((state >> (i - 1)) & 1) << '\n';
    }
}