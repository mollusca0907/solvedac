#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll M = 1'000'000'007;

ll fact[4'000'005] = { 1, };


ll dpow(ll n, ll k) {
	if (k == 0) {
		return 1;
	}
	if (k == 1) {
		return n;
	}
	ll x = dpow(n, k/2) % M;
	if (k % 2 == 1) {
		return ((x * x) % M * n) % M;
	}
	else {
		return (x * x) % M;
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (ll i = 1; i <= 4'000'000; i++) {
		fact[i] = (fact[i - 1] % M) * (i % M) % M;
	}

	int tc;
	cin >> tc;
	
	while (tc--) {

		ll n, k;
		cin >> n >> k;



		ll p = fact[n] % M;
		ll c = fact[k] * fact[n - k] % M;

		cout << p * dpow(c, M - 2) % M << "\n";


	}

	
	return 0;
}