#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<ll> h(N + 1);
    for (int i = 1; i <= N; ++i) cin >> h[i];

    while (Q--) {
        string t;
        int L, R;
        cin >> t >> L >> R;

        if (t == "ask") {
            ll ans = 0;
            for (int i = L; i <= R; ++i)
                ans += h[i];
            cout << ans << '\n';
        } else {
            for (int i = L; i <= R; ++i)
                h[i] = sqrtl(h[i]);
        }
    }
}