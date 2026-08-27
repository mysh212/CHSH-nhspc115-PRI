// Author : ysh
// 2026/08/21 Fri 10:20:50
#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;
int main(int ac, char* as[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    registerGen(ac, as, 1);

    int n = atoi(as[1]);
    int m = atoi(as[2]);
    int k = atoi(as[3]);

    n = rnd.next(1, n);
    m = rnd.next(1, m);
    k = rnd.next(1, k);

    cout<<rnd.next(1, k)<<" "<<rnd.next(1, k)<<" "<<n<<" "<<m<<"\n";
    return 0;
}