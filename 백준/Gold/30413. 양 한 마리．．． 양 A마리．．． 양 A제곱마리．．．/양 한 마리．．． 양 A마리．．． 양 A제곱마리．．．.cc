#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1'000'000'007;

ll dpow(ll n, ll k) {
	if (k == 0) {
		return 1;
	}
	if (k == 1) {
		return n;
	}
	ll x = dpow(n, k / 2) % mod;
	if (k % 2 == 1) {
		return ((x * x) % mod * n) % mod;
	}
	else {
		return (x * x) % mod;
	}
}

int main() {

	//등비수열의 합 공식 (일반항==1), r=공비, n항까지.
	//S = (r^n -1) / (r-1)

	//페르마의 소정리 적용 (mod 1e9+7)
	// ( (r^n - 1) % mod ) * (r-1)^(mod-2) % mod

	ll r, n;
	cin >> r >> n;

	if (r == 1) {
		cout << n % mod;
	}
	else {
		ll c = (dpow(r, n) - 1) % mod;
		ll p = dpow(r - 1, mod - 2) % mod;
		cout << c * p % mod;
	}
	return 0;
}