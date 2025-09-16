#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll M = 1'000'000'007;

ll dpow(ll n, ll k) {
	if (k == 0) {
		return 1;
	}
	if (k == 1) {
		return n;
	}
	ll x = dpow(n, k / 2) % M;
	if (k % 2 == 1) {
		return ((x * x) % M * n) % M;
	}
	else {
		return (x * x) % M;
	}
}

ll fact(ll n) {
	ll res = 1;
	while (n > 1) {
		res = res * n % M;
		n--;
	}
	return res;
}

int main() {

	ll n, k;
	cin >> n >> k;

	ll p = fact(n) % M;
	ll c = fact(k) * fact(n - k) % M;

	cout << p * dpow(c, M - 2) % M;



	return 0;
}