#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, k;

ll f(ll x) { //x보다 작은 수 갯수
	ll res = 0;
	for (int i = 1; i <= n; i++) {
		res += min(x / i, n);
	}
	return res;
}


int main() {

	cin >> n >> k;

	ll left = 1;
	ll right = n * n;

	ll mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (f(mid) < k) { //mid 키워야 함
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	cout << left;


	return 0;
}
