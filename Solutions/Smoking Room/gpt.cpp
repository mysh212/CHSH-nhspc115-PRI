#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K, s, t;
    cin >> N >> M >> K >> s >> t;

    vector<char> blocked(N + 1, false);

    for (int i = 0; i < K; ++i) {
        int v;
        cin >> v;
        blocked[v] = true;
    }

    vector<vector<int>> adj(N + 1);

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (blocked[s] || blocked[t]) {
        cout << "No\n";
        return 0;
    }

    vector<char> vis(N + 1, false);
    queue<int> q;

    vis[s] = true;
    q.push(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (u == t) {
            cout << "Yes\n";
            return 0;
        }

        for (int v : adj[u]) {
            if (!blocked[v] && !vis[v]) {
                vis[v] = true;
                q.push(v);
            }
        }
    }

    cout << "No\n";
    return 0;
}