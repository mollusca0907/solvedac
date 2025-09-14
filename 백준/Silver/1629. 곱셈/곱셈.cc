#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll a, b, c;

ll dpow(ll k, ll n) {
	k %= c;
	if (n == 1) {
		return k;
	}
	ll x = dpow(k, n / 2) % c;
	if (n % 2) {
		return ((x * x)%c * k) % c;
	}
	else {
		return (x * x) % c;
	}

}


int main() {

	cin >> a >> b >> c;

	cout << dpow(a, b);

	return 0;
}