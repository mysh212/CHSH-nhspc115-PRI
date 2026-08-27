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
    sort(f.begin(),f.end(),[&](pair<int,int> &a,pair<int,int> &b) {
        return a.second * (b.first-1) > b.second * (a.first-1);
    });
    for(int i=0;i<n;i++) {
        x = (f[i].first * x % mod + f[i].second % mod) % mod;
    }
    return cout<<x%mod,0;
}