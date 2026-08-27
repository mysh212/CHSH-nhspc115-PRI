#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll h1, h2;
    cin >> h1 >> h2;

    int n;
    cin >> n;

    ll d1, c1;
    cin >> d1 >> c1;

    int m;
    cin >> m;

    ll d2, c2;
    cin >> d2 >> c2;

    ll k = 1;

    while (true) {
        h2 -= d1;

        if (h2 <= 0) {
            cout << k << '\n';
            cout << "Doloris\n";
            return 0;
        }

        h1 -= d2;

        if (h1 <= 0) {
            cout << k << '\n';
            cout << "Mortis\n";
            return 0;
        }

        ++k;
    }
}