#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n, c;
vector<int>v;

bool fn(ll x) {

	int prev = v[0];
	int cnt = 1;

	for (int i = 1; i < n; i++) {
		if (v[i] - prev >= x) {
			cnt++;
			prev = v[i];
		}
	}

	return cnt >= c;
}



int main() {

	cin >> n >> c;
	v.assign(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	int left = 1;
	int right = v[n - 1] - v[0];
	int res = 0;

	int mid;

	while (left <= right) {
		mid = (left + right) / 2;
		if (fn(mid)) {
			res = max(res, mid);
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}

	}

	cout << res;



	return 0;
}