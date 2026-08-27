#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 1000000007LL;

struct Node {
    ll a, b;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll x;
    cin >> n >> x;

    vector<Node> v(n);

    for (auto &[a, b] : v) {
        cin >> a >> b;
    }

    sort(v.begin(), v.end(), [](const Node &x, const Node &y) {

        if (x.a == 1 && y.a == 1)
            return x.b > y.b;

        if (x.a == 1)
            return false;

        if (y.a == 1)
            return true;

        double rx = (double)x.b / (x.a - 1);
        double ry = (double)y.b / (y.a - 1);

        return rx > ry;
    });

    x %= MOD;

    for (auto [a, b] : v) {
        x = (x * (a % MOD) + b) % MOD;
    }

    cout << x << '\n';

    return 0;
}