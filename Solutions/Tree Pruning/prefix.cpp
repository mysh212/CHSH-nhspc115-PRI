#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<ll> pre(N + 1);
    for (int i = 1; i <= N; ++i) {
        ll x;
        cin >> x;
        pre[i] = pre[i - 1] + x;
    }

    while (Q--) {
        string t;
        int L, R;
        cin >> t >> L >> R;
        cout << pre[R] - pre[L - 1] << '\n';
    }
}