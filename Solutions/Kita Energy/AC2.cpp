#include <bits/stdc++.h>
#define int int64_t
using namespace std;

void solve() {
    int Q,V;
    cin >> Q >> V;
    multiset<int> charge;
    int ok = 0;
    while(Q--) {
        int op, t, w;
        cin >> op;
        if(op == 1) {
            cin >> t >> w;
            if(w >= V) ok++;
            else charge.insert(w - t);
        }
        else {
            cin >> t;
            auto it = charge.lower_bound(V - t);
            while(it != charge.end()) {
                it = charge.erase(it);
                ok++;
            }
            int ans;
            if(ok) ans = V, ok--;
            else if(!charge.empty()) {
                int w0 = *charge.rbegin();
                ans = w0 + t;
                charge.erase(prev(charge.end()));
            }
            else ans = -1;
            cout << ans << '\n';
        }
    }
}

signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int T = 1;
    // cin >> T;
    while(T--) {
        solve();
    }
}