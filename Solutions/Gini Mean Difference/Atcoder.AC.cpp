#include <iostream>
using std::cin;
using std::cout;
#include <vector>
using std::vector;
#include <algorithm>
using std::sort;

typedef long long int ll;

const ll MOD = 998244353;

ll n, m;
vector<ll> a, b;


void solve () {
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	// sum[0, i), sum[i, n)
	vector<ll> apre(n+1, 0LL), asuf(n+1, 0LL);
	apre[0] = 0;
	for (ll i = 0; i < n; i++) {
		apre[i+1] = (apre[i] + a[i]);
	}
	asuf[n] = 0;
	for (ll i = n-1; i >= 0; i--) {
		asuf[i] = (asuf[i+1] + a[i]);
	}

	ll ans = 0;
	for (ll i = 0; i < m; i++) {
		// a[<x] < b[i], a[>=x] >= b[i]
		ll ok = n, ng = -1;
		while (ng + 1 < ok) {
			ll med = (ok + ng) / 2;
			if (a[med] >= b[i]) {
				ok = med;
			} else {
				ng = med;
			}
		}
		const ll x = ok;

		// prefix sum
		ans += ((b[i] * x) - apre[x]) % MOD;
		// suffix sum
		ans += (asuf[x] - (b[i] * (n-x))) % MOD;
	}
	ans %= MOD;

	cout << ans << "\n";
	return;	
}

int main (void) {
	cin >> n >> m;
	a.resize(n);
	b.resize(m);
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (ll i = 0; i < m; i++) {
		cin >> b[i];
	}

	solve();

	
	return 0;
}
