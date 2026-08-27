// Author : ysh
// 2026/08/19 Wed 17:06:11
#include<bits/stdc++.h>
using namespace std;
vector<int>color;
inline int ff(int x) {
    if(color.at(x) == x) return x;
    return color.at(x) = ff(color.at(x));
}
inline void mg(int a, int b) {
    color.at(ff(a)) = ff(b);
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;

    color = vector<int>(n << 1);
    iota(color.begin(), color.end(), 0);

    for(int i = 0;i<n;i++) {
        int a, b;cin>>a>>b;
        a--;
        if(b == 1) mg(i, a + n), mg(a, i + n);
        else mg(i, a), mg(i + n, a + n);
    }

    for(int i = 0;i<n;i++) {
        if(ff(i) == ff(i + n)) goto no;
    }

    yes:
    cout<<"Yes";
    return 0;

    no:
    cout<<"No";
    return 0;
}