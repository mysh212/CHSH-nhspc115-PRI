#include <bits/stdc++.h>
#define int int64_t
#define first damage
#define second cd
using namespace std;
int h1,h2,n,m;
bool check(vector<pair<int,int>> &A, vector<pair<int,int>> &B, int t) { 
    int total_A = 0, total_B = 0;
    for(auto [damage, cd] : A) {
        int cnt = (t - 1) / cd + 1;
        total_A += damage * cnt;
        if(total_A >= h2) return 1;
    }
    for(auto [damage, cd] : B) {
        int cnt = t / cd;
        total_B += damage * cnt;
        if(total_B >= h1) return 1;
    }
    return 0;
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    cin >> h1 >> h2;
    cin >> n;
    vector<pair<int,int>> A(n);
    for(auto &[damage, cd] : A) {
        cin >> damage >> cd;
    }
    cin >> m;
    vector<pair<int,int>> B(m);
    for(auto &[damage, cd] : B) {
        cin >> damage >> cd;
    }
    int l = 0, r = 1e13+5;
    while(l+1 != r) {
        int mid = (l+r)>>1;
        if(check(A,B,mid)) r = mid;
        else l = mid;
    }
    int total_A = 0, total_B = 0, t = r;
    cout << t << '\n';
    for(auto [damage, cd] : A) {
        int cnt = (t - 1) / cd + 1;
        total_A += damage * cnt;
        if(total_A >= h2) return cout << "Doloris", 0;
    }
    for(auto [damage, cd] : B) {
        int cnt = t / cd;
        total_B += damage * cnt;
        if(total_B >= h1) return cout << "Mortis", 0;
    }
}