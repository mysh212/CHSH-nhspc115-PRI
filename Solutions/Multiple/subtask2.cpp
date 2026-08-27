// Author : ysh
// 2026/08/21 五 10:41:19
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b, c, d;cin>>a>>b>>c>>d;

    int carry = 0;
    vector<int>one;
    for(int i = 0;i<c;i++) {
        // a * b
        one.push_back((a * b) % 10 + carry);
        carry = (a * b) / 10;
    }
    while(carry % 10 != 0) one.push_back(carry % 10), carry = carry / 10;

    auto ans = one;
    reverse(ans.begin(), ans.end());
    for(int &i : ans) cout<<i;
    return 0;
}