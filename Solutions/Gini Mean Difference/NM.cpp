#include <bits/stdc++.h>
#define int int64_t
using namespace std;

static constexpr int MOD = 998244353;

signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<int> A(n), B(m);
    for (int &x : A) cin >> x;
    for (int &x : B) cin >> x;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans = (ans + abs(A[i] - B[j])) % MOD;
        }
    }

    cout << ans << '\n';
    return 0;
}