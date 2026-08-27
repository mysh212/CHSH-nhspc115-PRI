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

    ll damageA = 0;

    for (int i = 0; i < n; ++i) {
        ll d, c;
        cin >> d >> c;
        damageA += d;
    }

    int m;
    cin >> m;

    ll damageB = 0;

    for (int i = 0; i < m; ++i) {
        ll d, c;
        cin >> d >> c;
        damageB += d;
    }

    /*
        第 k 回合初華造成 k * damageA。
        如果：
            k * damageA >= h2
        則初華在第 k 回合獲勝。

        小睦在第 k 回合也會攻擊，
        但因為初華先手，所以只需要比較
        小睦是否能在更早的回合殺死初華。
    */

    ll turnA = (h2 + damageA - 1) / damageA;
    ll turnB = (h1 + damageB - 1) / damageB;

    if (turnA <= turnB) {
        cout << turnA << '\n';
        cout << "Doloris\n";
    }
    else {
        cout << turnB << '\n';
        cout << "Mortis\n";
    }

    return 0;
}