#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Fenwick {
    int n;
    vector<ll> bit;

    Fenwick(int n) : n(n), bit(n + 1) {}

    void add(int x, ll v) {
        for (; x <= n; x += x & -x)
            bit[x] += v;
    }

    ll sum(int x) {
        ll res = 0;
        for (; x > 0; x -= x & -x)
            res += bit[x];
        return res;
    }

    ll query(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<ll> h(N + 1);
    Fenwick fw(N);

    for (int i = 1; i <= N; ++i) {
        cin >> h[i];
        fw.add(i, h[i]);
    }

    while (Q--) {
        string t;
        int L, R;
        cin >> t >> L >> R;

        if (t == "ask") {
            cout << fw.query(L, R) << '\n';
        } else {
            ll nh = sqrtl(h[L]);
            fw.add(L, nh - h[L]);
            h[L] = nh;
        }
    }
}