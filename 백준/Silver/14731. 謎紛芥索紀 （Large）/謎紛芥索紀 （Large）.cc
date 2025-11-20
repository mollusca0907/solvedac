#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

ll dpow(ll k, ll n) {
	k %= MOD;
	if (n == 0) {
		return 1;
	}
	if (n == 1) {
		return k;
	}
	ll x = dpow(k, n / 2) % MOD;
	if (n % 2) {
		return ((x * x) % MOD * k) % MOD;
	}
	else {
		return (x * x) % MOD;
	}

}

int main() {

	ll n;
	cin >> n;
	
	ll res = 0;

	for (ll i = 0; i < n; i++) {
		ll c, k;
		cin >> c >> k;
		if (k == 0) continue;
		res += (c * k % MOD) * dpow(2, k - 1) % MOD;
		res %= MOD;
	}
	cout << res;
	return 0;
}	