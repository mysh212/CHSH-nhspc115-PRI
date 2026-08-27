#include <bits/stdc++.h>
#define int int64_t
using namespace std;

static constexpr int MOD = 998244353;

signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;

    vector<int> A(n), B(m);
    for (int &x : A) cin >> x;
    for (int &x : B) cin >> x;

    sort(B.begin(), B.end());

    vector<int> pref(m + 1, 0);
    for (int i = 0; i < m; i++) {
        pref[i + 1] = (pref[i] + B[i]) % MOD;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int idx = lower_bound(B.begin(), B.end(), A[i]) - B.begin();

        int left_sum = pref[idx];
        int left_val = (A[i] % MOD * idx % MOD - left_sum + MOD) % MOD;

        int right_sum = (pref[m] - pref[idx] + MOD) % MOD;
        int right_val = (right_sum - A[i] % MOD * (m - idx) % MOD + MOD) % MOD;

        ans = (ans + left_val + right_val) % MOD;
    }

    cout << ans << '\n';
    return 0;
}