#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int B = 700;

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

    int numBlocks = (N + B - 1) / B;

    vector<ll> sum(numBlocks);
    vector<ll> mx(numBlocks);

    for (int i = 1; i <= N; ++i)
        cin >> h[i];

    auto rebuild = [&](int b) {
        int l = b * B + 1;
        int r = min(N, (b + 1) * B);

        sum[b] = 0;
        mx[b] = 0;

        for (int i = l; i <= r; ++i) {
            sum[b] += h[i];
            mx[b] = max(mx[b], h[i]);
        }
    };

    for (int b = 0; b < numBlocks; ++b)
        rebuild(b);

    while (Q--) {
        string t;
        int L, R;

        cin >> t >> L >> R;

        int bl = (L - 1) / B;
        int br = (R - 1) / B;

        if (t == "ask") {
            ll ans = 0;

            if (bl == br) {
                for (int i = L; i <= R; ++i)
                    ans += h[i];
            } else {
                int endL = min(N, (bl + 1) * B);

                for (int i = L; i <= endL; ++i)
                    ans += h[i];

                for (int b = bl + 1; b < br; ++b)
                    ans += sum[b];

                int startR = br * B + 1;

                for (int i = startR; i <= R; ++i)
                    ans += h[i];
            }

            cout << ans << '\n';
        } else {
            if (bl == br) {
                if (mx[bl] > 1) {
                    for (int i = L; i <= R; ++i)
                        h[i] = isqrt(h[i]);

                    rebuild(bl);
                }

                continue;
            }

            int endL = min(N, (bl + 1) * B);

            for (int i = L; i <= endL; ++i)
                h[i] = isqrt(h[i]);

            rebuild(bl);

            for (int b = bl + 1; b < br; ++b) {
                if (mx[b] <= 1)
                    continue;

                int l = b * B + 1;
                int r = min(N, (b + 1) * B);

                for (int i = l; i <= r; ++i)
                    h[i] = isqrt(h[i]);

                rebuild(b);
            }

            int startR = br * B + 1;

            for (int i = startR; i <= R; ++i)
                h[i] = isqrt(h[i]);

            rebuild(br);
        }
    }

    return 0;
}