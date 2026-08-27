// Author : ysh
// 2026/08/19 Wed 16:55:30
#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;
int main(int ac, char* as[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    registerGen(ac, as, 1);

    int n = atoi(as[1]);
    int k = atoi(as[2]);

    n = rnd.next(2, n);
    int m = n;
    cout<<n<<"\n";
    if(k == 0) {
        while(m--) cout<<rnd.next(1, n)<<" "<<rnd.next(0, 1)<<"\n";
        return 0;
    }

    while(m--) cout<<rnd.next(1, n)<<" "<<(k - 1)<<"\n";
    return 0;
}