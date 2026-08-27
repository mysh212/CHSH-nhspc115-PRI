// Author : ysh
// 2026/08/21 Fri 10:41:19
#include<bits/stdc++.h>
using namespace std;
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    int a, b, c, d;cin>>a>>b>>c>>d;

    int carry = 0;
    vector<int>one;
    for(int i = 0;i<c;i++) {
        // a * b
        one.push_back((a * b) % 10 + carry);
        carry = (a * b) / 10;
    }
    while(carry != 0) one.push_back(carry % 10), carry = carry / 10;

    vector<int>ans;
    int now = 0;
    int ct = 0;
    for(int i = 0, len = one.size() + d;i<len;i++) {
        if(i < len - d) now += one.at(i);
        if(++ct > d) now -= one.at(i - d), --ct;

        carry += now;
        if(carry == 0 && i >= len - d) break;
        ans.push_back(carry % 10);
        carry = carry / 10;
    }
    while(carry != 0) ans.push_back(carry % 10), carry = carry / 10;

    reverse(ans.begin(), ans.end());
    for(int &i : ans) cout<<i;
    return 0;
}