#include<bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int Q,V;
    cin >> Q >> V;
    priority_queue<int> pq;
    while(Q--) {
        int op,t,w;
        cin >> op;
        if(op == 1) {
            cin >> t >> w;
            pq.push(w-t);
        }
        else {
            cin >> t;
            if(pq.empty()) cout << "-1\n";
            else {
                int w0 = pq.top();
                pq.pop();
                cout << min(w0+t, V) << '\n';
            }
        }
    }
    return 0;
}