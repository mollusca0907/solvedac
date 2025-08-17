#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {

	int n;
	cin >> n;

	vector<int> v(n + 16, 0);

	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}

	ll cost = 0;

	for (int i = 1; i <= n; i++) {
		if (v[i + 1] > v[i + 2]) {
			ll ramen = min(v[i], v[i + 1] - v[i + 2]);
			v[i] -= ramen;
			v[i+1] -= ramen;
			cost += ramen * 5;
		}
		if (v[i] != 0) {
			ll ramen = min({v[i], v[i+1], v[i+2]});
			v[i] -= ramen;
			v[i+1] -= ramen;
			v[i+2] -= ramen;
			cost += ramen * 7;
		}

		cost += v[i] * 3;

	}

	cout << cost;

	return 0;
}