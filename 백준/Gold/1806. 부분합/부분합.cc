#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {

	int n, s;
	cin >> n >> s;
	vector<int> v(n+1);
	vector<ll> ps(n+1);

	v[0] = ps[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		ps[i] = ps[i - 1] + v[i];
	}

	int left = 1;
	int right = 1;

	int res = 2e9;
	while (left <= right && right <= n) {
		if (ps[right] - ps[left - 1] >= s) {
			res = min(res, right - left + 1);
			left++;
		}
		else {
			right++;
		}
	}

	if (res == 2e9) {
		res = 0;
	}

	cout << res;

	return 0;
}