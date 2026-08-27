#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> rc(int N,int r){
    vector<pair<int,int>> v;
    for(int y=N-r;y<=N+r;y++)v.push_back({N-r,y});
    for(int x=N-r+1;x<=N+r;x++)v.push_back({x,N+r});
    for(int y=N+r-1;y>=N-r;y--)v.push_back({N+r,y});
    for(int x=N+r-1;x>=N-r+1;x--)v.push_back({x,N-r});
    return v;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int N;cin>>N; int S=2*N+1; vector<string> g(S);for(auto&s:g)cin>>s;
    vector<vector<pair<int,int>>> R(N+1); vector<string> orig(N+1);
    for(int r=1;r<=N;r++){
        R[r]=rc(N,r); orig[r].resize(8*r);
        for(int i=0;i<8*r;i++)orig[r][i]=g[R[r][i].first][R[r][i].second];
    }
    vector<int> sh(N+1); int best=1e9;
    auto can_escape=[&](){
        vector<string> a(S,string(S,'#')); a[N][N]='.';
        for(int r=1;r<=N;r++){
            int L=8*r;
            for(int p=0;p<L;p++){
                char z=orig[r][(p-sh[r]+L)%L];
                auto [x,y]=R[r][p]; a[x][y]=z;
            }
        }
        queue<pair<int,int>>q; vector<vector<char>>vis(S,vector<char>(S));
        q.push({N,N});vis[N][N]=1;
        int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
        while(!q.empty()){
            auto [x,y]=q.front();q.pop(); int rr=max(abs(x-N),abs(y-N));
            if(rr==N)return true;
            for(int d=0;d<4;d++){
                int nx=x+dx[d],ny=y+dy[d];
                if(nx<0||nx>=S||ny<0||ny>=S||vis[nx][ny]||a[nx][ny]=='#')continue;
                int nr=max(abs(nx-N),abs(ny-N));
                if(nr<rr)continue;
                vis[nx][ny]=1;q.push({nx,ny});
            }
        }
        return false;
    };
    function<void(int,int)> dfs=[&](int r,int cost){
        if(cost>=best)return;
        if(r>N){ if(can_escape())best=cost; return; }
        int L=8*r;
        for(int s=0;s<L;s++){
            sh[r]=s; dfs(r+1,cost+min(s,L-s));
        }
    };
    dfs(1,0);
    cout<<(best==1e9?-1:best)<<'\n';
}
