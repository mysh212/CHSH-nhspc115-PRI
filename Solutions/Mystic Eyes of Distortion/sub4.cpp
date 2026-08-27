#include <bits/stdc++.h>
using namespace std;
const int INF=1e9;
vector<pair<int,int>> rc(int N,int r){
    if(r==0)return{{N,N}}; vector<pair<int,int>>v;
    for(int y=N-r;y<=N+r;y++)v.push_back({N-r,y});
    for(int x=N-r+1;x<=N+r;x++)v.push_back({x,N+r});
    for(int y=N+r-1;y>=N-r;y--)v.push_back({N+r,y});
    for(int x=N+r-1;x>=N-r+1;x--)v.push_back({x,N-r});
    return v;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int N;cin>>N;int S=2*N+1;vector<string>g(S);for(auto&s:g)cin>>s;
    vector<vector<pair<int,int>>>R(N+1);vector<vector<int>>idx(S,vector<int>(S,-1));
    for(int r=0;r<=N;r++){R[r]=rc(N,r);for(int i=0;i<(int)R[r].size();i++)idx[R[r][i].first][R[r][i].second]=i;}
    vector<int>prev(1,0);int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
    for(int r=1;r<=N;r++){
        int L=8*r;string orig(L,'#');for(int i=0;i<L;i++){auto[x,y]=R[r][i];orig[i]=g[x][y];}
        vector<int>enter(L,INF),cur(L,INF);
        for(int p=0;p<L;p++){
            auto[x,y]=R[r][p];
            for(int d=0;d<4;d++){
                int nx=x+dx[d],ny=y+dy[d];if(nx<0||nx>=S||ny<0||ny>=S)continue;
                if(max(abs(nx-N),abs(ny-N))==r-1)enter[p]=min(enter[p],prev[idx[nx][ny]]);
            }
        }
        // Exact for Subtask 4: every open cell is isolated, so no same-ring movement exists.
        for(int sh=0;sh<L;sh++){
            int add=min(sh,L-sh);
            for(int p=0;p<L;p++)if(orig[(p-sh+L)%L]=='.'&&enter[p]<INF)
                cur[p]=min(cur[p],enter[p]+add);
        }
        prev.swap(cur);
        if(*min_element(prev.begin(),prev.end())>=INF){cout<<-1<<'\n';return 0;}
    }
    cout<<*min_element(prev.begin(),prev.end())<<'\n';
}
