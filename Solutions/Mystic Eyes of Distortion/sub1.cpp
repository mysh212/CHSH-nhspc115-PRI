#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin>>N; int S=2*N+1; vector<string> g(S); for(auto &s:g) cin>>s;
    // Exact for Subtask 1: N = 1.
    // Ring order: TL, T, TR, R, BR, B, BL, L; only 1,3,5,7 touch center.
    vector<pair<int,int>> c={{0,0},{0,1},{0,2},{1,2},{2,2},{2,1},{2,0},{1,0}};
    int ans=1e9;
    for(int i=0;i<8;i++) if(g[c[i].first][c[i].second]=='.')
        for(int t:{1,3,5,7}){
            int d=abs(i-t); d=min(d,8-d); ans=min(ans,d);
        }
    cout<<(ans==(int)1e9?-1:ans)<<'\n';
}
