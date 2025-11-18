#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n, m;
vector<int> v;

bool fn(ll x) {
	ll res = 0;
	for (int i = 0; i < n; i++) {
		if (v[i] - x > 0) {
			res += v[i] - x;
		}
	}
	return res >= m;
}



int main() {

	cin >> n >> m;
	v.assign(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	ll left = 1;
	ll right = *max_element(v.begin(), v.end());
	ll mid = (left + right) / 2;

	ll res = 0;

	while (left <= right) {
		mid = (left + right) / 2;
		if (fn(mid)) { //얻는 나무가 필요한 양보다 많으면
			left = mid + 1; //좀 높게 == 나무수가 적어지도록 잘라도 됨
			res = max(res, mid);
		}
		else {
			right = mid - 1;
		}
	}

	cout << res;



	return 0;
}