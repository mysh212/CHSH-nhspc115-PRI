#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct BIT {
    int n;
    vector<ll> bit;

    BIT(int n) : n(n), bit(n + 1, 0) {}

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

ll isqrt(ll x) {
    ll y = sqrtl((long double)x);

    while ((__int128)(y + 1) * (y + 1) <= x)
        ++y;

    while ((__int128)y * y > x)
        --y;

    return y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<ll> h(N + 1);
    BIT bit(N);
    set<int> alive;

    for (int i = 1; i <= N; ++i) {
        cin >> h[i];
        bit.add(i, h[i]);

        if (h[i] > 1)
            alive.insert(i);
    }

    while (Q--) {
        string t;
        int L, R;

        cin >> t >> L >> R;

        if (t == "ask") {
            cout << bit.query(L, R) << '\n';
        } else {
            auto it = alive.lower_bound(L);

            while (it != alive.end() && *it <= R) {
                int i = *it;

                ll old = h[i];
                ll nw = isqrt(old);

                h[i] = nw;
                bit.add(i, nw - old);

                if (nw == 1) {
                    it = alive.erase(it);
                } else {
                    ++it;
                }
            }
        }
    }

    return 0;
}