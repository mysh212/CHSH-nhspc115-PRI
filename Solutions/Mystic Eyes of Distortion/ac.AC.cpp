#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int S = 2 * N + 1;
    vector<string> grid(S);

    for (auto &row : grid)
        cin >> row;

    vector<vector<pair<int, int>>> ring(N + 1);
    ring[0].push_back({N, N});

    for (int r = 1; r <= N; r++) {
        for (int y = N - r; y <= N + r; y++)
            ring[r].push_back({N - r, y});
        for (int x = N - r + 1; x <= N + r; x++)
            ring[r].push_back({x, N + r});
        for (int y = N + r - 1; y >= N - r; y--)
            ring[r].push_back({N + r, y});
        for (int x = N + r - 1; x > N - r; x--)
            ring[r].push_back({x, N - r});
    }

    vector<vector<int>> pos(S, vector<int>(S));
    for (int r = 0; r <= N; r++) {
        for (int i = 0; i < (int)ring[r].size(); i++) {
            auto [x, y] = ring[r][i];
            pos[x][y] = i;
        }
    }

    vector<int> dp(1, 0);

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    for (int r = 1; r <= N; r++) {
        int L = 8 * r;

        vector<int> enter(L, INF);

        for (int i = 0; i < L; i++) {
            auto [x, y] = ring[r][i];

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || nx >= S || ny < 0 || ny >= S)
                    continue;

                int nr = max(abs(nx - N), abs(ny - N));

                if (nr == r - 1)
                    enter[i] = min(enter[i], dp[pos[nx][ny]]);
            }
        }

        vector<bool> open(L);

        for (int i = 0; i < L; i++) {
            auto [x, y] = ring[r][i];
            open[i] = (grid[x][y] == '.');
        }

        vector<int> comp(L, -1);
        int components = 0;
        int wall = -1;

        for (int i = 0; i < L; i++) {
            if (!open[i]) {
                wall = i;
                break;
            }
        }

        if (wall == -1) {
            fill(comp.begin(), comp.end(), 0);
            components = 1;
        } else {
            for (int t = 1; t <= L; t++) {
                int i = (wall + t) % L;

                if (!open[i])
                    continue;

                int prev = (i - 1 + L) % L;

                if (!open[prev])
                    components++;

                comp[i] = components - 1;
            }
        }

        if (components == 0) {
            cout << -1 << '\n';
            return 0;
        }

        vector<int> ndp(L, INF);
        vector<int> best(components);

        for (int shift = 0; shift < L; shift++) {
            fill(best.begin(), best.end(), INF);

            for (int i = 0; i < L; i++) {
                if (!open[i]) {
                    continue;
                }

                int p = (i + shift) % L;
                int c = comp[i];

                best[c] = min(best[c], enter[p]);
            }

            int rotateCost = min(shift, L - shift);

            for (int i = 0; i < L; i++) {
                if (!open[i]) {
                    continue;
                }

                int p = (i + shift) % L;
                int c = comp[i];

                ndp[p] = min(ndp[p], best[c] + rotateCost);
            }
        }
        dp.swap(ndp);
    }

    int ans = *min_element(dp.begin(), dp.end());

    cout << (ans == INF ? -1 : ans) << '\n';
}