#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll tree[65536 * 4 + 16];

void update(ll idx, ll left, ll right, ll cidx, ll cval) {
	if (cidx < left || right < cidx) {
		return;
	}
	if (left == right) {
		tree[idx] += cval;
		return;
	}
	ll mid = (left + right) / 2;
	update(idx * 2, left, mid, cidx, cval);
	update(idx * 2 + 1, mid+1, right, cidx, cval);
	tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
	return;
}

ll query(ll idx, ll left, ll right, ll val) {
	if (left == right) {
		return left;
	}
	ll mid = (left + right) / 2;
	if (tree[idx * 2] >= val) {
		return query(idx * 2, left, mid, val);
	}
	return query(idx * 2 + 1, mid + 1, right, val - tree[idx * 2]);
}


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	ll ans = 0;

	cin >> n >> k;

	vector<ll> v(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}

	for (int i = 1; i <= k; i++) {
		update(1, 1, 65536, v[i]+1, 1);
	}
	ans += query(1, 1, 65536, (k + 1) / 2) - 1;

	for (int i = k+1; i <= n; i++) {
		update(1, 1, 65536, v[i - k]+1, -1);
		update(1, 1, 65536, v[i]+1, 1);
		ans += query(1, 1, 65536, (k + 1) / 2) - 1;
	}
	cout << ans;
	return 0;
}