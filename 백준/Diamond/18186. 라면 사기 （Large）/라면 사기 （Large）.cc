#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {

	int n;
	ll b, c;
	cin >> n >> b >> c;

	vector<int> v(n + 16, 0);
	if (b <= c) {
		ll ans = 0;
		for (int i = 1; i <= n; i++) {
			ll x;
			cin >> x;
			ans += x * b;
		}
		cout << ans;
		return 0;
	}



	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}

	ll cost = 0;

	for (int i = 1; i <= n; i++) {
		if (v[i + 1] > v[i + 2]) {
			ll ramen = min(v[i], v[i + 1] - v[i + 2]);
			v[i] -= ramen;
			v[i+1] -= ramen;
			cost += ramen * (b+c);
		}
		if (v[i] != 0) {
			ll ramen = min({v[i], v[i+1], v[i+2]});
			v[i] -= ramen;
			v[i+1] -= ramen;
			v[i+2] -= ramen;
			cost += ramen * (b+2*c);
		}

		cost += v[i] * b;

	}

	cout << cost;

	return 0;
}