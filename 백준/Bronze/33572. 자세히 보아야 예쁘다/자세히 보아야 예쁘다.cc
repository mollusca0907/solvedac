#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {

	ll n, m;
	cin >> n >> m;
	
	ll sum = 0;
	for (ll i = 0; i < n; i++) {
		ll x;
		cin >> x;
		sum += x;
	}

	if (sum - n < m) {
		cout << "OUT";
	}
	else {
		cout << "DIMI";
	}

	return 0;
}