#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int mod = 1e9+7;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n,x;
    cin >> n >> x;
    vector<pair<int,int>> f(n);
    for(auto &[a,b] : f) cin >> a >> b;
    sort(f.begin(),f.end(),[&](const pair<int,int> &a, const pair<int,int> &b) {
        int lhs = a.second * (b.first - 1);
        int rhs = b.second * (a.first - 1);
        if (lhs != rhs) return lhs > rhs;
        if (a.first != b.first) return a.first < b.first;
        return a.second > b.second;
    });
    for(int i=0;i<n;i++) {
        x = (f[i].first * x % mod + f[i].second % mod) % mod;
    }
    return cout<<x%mod,0;
}