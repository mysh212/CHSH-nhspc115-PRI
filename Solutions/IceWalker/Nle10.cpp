#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Node {
    ll a, b;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll x0;

    cin >> n >> x0;

    vector<Node> v(n);

    for (auto &[a, b] : v)
        cin >> a >> b;

    vector<int> p(n);
    iota(p.begin(), p.end(), 0);

    ll ans = 0;

    do {
        ll x = x0;

        for (int id : p) {
            x = x * v[id].a + v[id].b;
        }

        ans = max(ans, x);

    } while (next_permutation(p.begin(), p.end()));

    cout << ans % 1000000007LL << '\n';

    return 0;
}