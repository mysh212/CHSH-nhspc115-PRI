#include <bits/stdc++.h>
using namespace std;

const long long mod = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<long long> num(n);
    for (auto &x : num) cin >> x;

    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
    }

    sort(num.begin(), num.end());

    long long ans = 0;
    long long prefix = 0;

    for (int i = 0; i < n; ++i) {
        ans = (ans + num[i] % mod * i - prefix) % mod;
        prefix = (prefix + num[i]) % mod;
    }

    ans = ans * 2 % mod;

    cout << ans << '\n';

    return 0;
}