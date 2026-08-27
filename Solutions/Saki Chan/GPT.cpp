#include <bits/stdc++.h>
using namespace std;

#define int long long

int a[1005], b[1005];
int h1, h2;

bool kill1(int k) {
    __int128 sum = 0;

    for (int c = 1; c <= 1000; ++c) {
        if (!a[c]) continue;

        int cnt = (k + c - 1) / c;

        sum += (__int128)a[c] * cnt;

        if (sum >= h2)
            return true;
    }

    return false;
}

bool kill2(int k) {
    __int128 sum = 0;

    for (int c = 1; c <= 1000; ++c) {
        if (!b[c]) continue;

        int cnt = k / c;

        sum += (__int128)b[c] * cnt;

        if (sum >= h1)
            return true;
    }

    return false;
}

int firstKill(bool first) {
    int lo = 1, hi = 4000000000000000000LL;

    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;

        if (first ? kill1(mid) : kill2(mid))
            hi = mid;
        else
            lo = mid + 1;
    }

    return lo;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> h1 >> h2;

    int n;
    cin >> n;

    while (n--) {
        int d, c;
        cin >> d >> c;
        a[c] += d;
    }

    int m;
    cin >> m;

    while (m--) {
        int d, c;
        cin >> d >> c;
        b[c] += d;
    }

    int t1 = firstKill(true);
    int t2 = firstKill(false);

    if (t1 <= t2) {
        cout << t1 << '\n';
        cout << "Doloris\n";
    } else {
        cout << t2 << '\n';
        cout << "Mortis\n";
    }

    return 0;
}