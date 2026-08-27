// Author : ysh
// 2026/08/19 Wed 17:41:58
#include<bits/stdc++.h>
// #include<debug.h>
#define debug(...) '*'
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<vector<pair<int, bool>>>f(n);
    for(int i = 0;i<n;i++) {
        int a, b;cin>>a>>b;
        a--;
        f.at(i).push_back({a, b == 1});
        f.at(a).push_back({i, b == 1});
    }

    debug(f);

    #define MAX CHAR_MAX
    vector<int>mark(n, MAX);
    function<bool(int, int, int)> check = [&] (int last, int x, bool now) {
        debug(x, mark);
        if(mark.at(x) != MAX and (mark.at(x) == 1) != now) return false;
        if(mark.at(x) != MAX) return true;
        debug("ok");
        
        mark.at(x) = (now ? 1 : 0);

        for(auto &[i, t]: f.at(x)) {
            debug(x, i, t);
            if(i == last) continue;

            if(!check(x, i, now ^ t)) return false;
        }

        return true;
    };

    for(int i = 0;i<n;i++) {
        if(mark.at(i) == MAX) if(!check(-1, i, 0)) return cout<<"No", 0;
    }

    cout<<"Yes";
    return 0;
}