#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> e;
    DSU(int n) : e(n + 1, -1) {}
    int find(int x) {
        if (e[x] < 0) {
            return x;
        }
        e[x] = find(e[x]);
        return e[x];
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return;
        }
        if (e[x] < e[y]) {
            swap(x, y);
        }
        e[y] += e[x];
        e[x] = y;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k, s, t;
    cin >> n >> m >> k >> s >> t;
    vector<char> forbid(n + 1);
    for (int i = 0; i < k; i++) {
        int v;
        cin >> v;
        forbid[v] = true;
    }
    DSU dsu(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        if (forbid[u] || forbid[v]) {
            continue;
        }
        dsu.unite(u, v);
    }
    cout << (dsu.same(s, t) ? "Yes\n" : "No\n");
}