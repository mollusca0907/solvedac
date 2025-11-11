#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;

ll dpow(ll n, ll k) {
	if (k <= 0) {
		return 1;
	}
	if (k == 1) {
		return n;
	}
	ll x = dpow(n, k / 2) % MOD;
	if (k % 2 == 1) {
		return ((x * x) % MOD * n) % MOD;
	}
	else {
		return (x * x) % MOD;
	}
}


int main() {

	int t;
	cin >> t;

	while (t--) {

		int n;
		cin >> n;

		cout << dpow(2, n - 2) << "\n";

	}

	return 0;
}