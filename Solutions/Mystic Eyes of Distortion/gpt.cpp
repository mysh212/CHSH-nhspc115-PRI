#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct DSU {
    vector<int> p;
    DSU(int n): p(n) { iota(p.begin(), p.end(), 0); }
    int F(int x){ return p[x]==x ? x : p[x]=F(p[x]); }
    void U(int a,int b){
        a=F(a), b=F(b);
        if(a!=b) p[a]=b;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    int S=2*N+1;

    vector<string> a(S);
    for(auto &s:a) cin >> s;

    vector<vector<pair<int,int>>> R(N+1);
    R[0]={{N,N}};

    for(int r=1;r<=N;r++){
        for(int y=N-r;y<=N+r;y++) R[r].push_back({N-r,y});
        for(int x=N-r+1;x<=N+r;x++) R[r].push_back({x,N+r});
        for(int y=N+r-1;y>=N-r;y--) R[r].push_back({N+r,y});
        for(int x=N+r-1;x>N-r;x--) R[r].push_back({x,N-r});
    }

    vector<vector<int>> id(S,vector<int>(S));
    for(int r=0;r<=N;r++)
        for(int i=0;i<(int)R[r].size();i++)
            id[R[r][i].first][R[r][i].second]=i;

    vector<int> dp(1,0);

    int dx[]={1,-1,0,0};
    int dy[]={0,0,1,-1};

    for(int r=1;r<=N;r++){
        int L=8*r;
        vector<int> in(L,INF);

        // 從上一環跨進這個位置的成本
        for(int i=0;i<L;i++){
            auto [x,y]=R[r][i];

            for(int d=0;d<4;d++){
                int X=x+dx[d], Y=y+dy[d];
                if(X<0||X>=S||Y<0||Y>=S) continue;

                if(max(abs(X-N),abs(Y-N))==r-1)
                    in[i]=min(in[i],dp[id[X][Y]]);
            }
        }

        // 原始環上的 '.' connected components
        DSU dsu(L);

        for(int i=0;i<L;i++){
            int j=(i+1)%L;
            auto [x1,y1]=R[r][i];
            auto [x2,y2]=R[r][j];

            if(a[x1][y1]=='.' && a[x2][y2]=='.')
                dsu.U(i,j);
        }

        vector<int> ndp(L,INF), best(L);

        // s = 順時針旋轉 s 格
        for(int s=0;s<L;s++){
            fill(best.begin(),best.end(),INF);

            // 找每個 component 最便宜的入口
            for(int i=0;i<L;i++){
                auto [x,y]=R[r][i];
                if(a[x][y]=='#') continue;

                int p=(i+s)%L;
                best[dsu.F(i)]=min(best[dsu.F(i)],in[p]);
            }

            int cost=min(s,L-s);

            // component 裡所有位置都可以到達
            for(int i=0;i<L;i++){
                auto [x,y]=R[r][i];
                if(a[x][y]=='#') continue;

                int p=(i+s)%L;
                int b=best[dsu.F(i)];

                if(b<INF)
                    ndp[p]=min(ndp[p],b+cost);
            }
        }

        dp.swap(ndp);
    }

    int ans=*min_element(dp.begin(),dp.end());
    cout << (ans==INF ? -1 : ans) << '\n';
}