#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll INF = 1e18;

ll min_tree[50'000 * 4 + 16];
ll max_tree[50'000 * 4 + 16];

void min_update(ll idx, ll left, ll right, ll cidx, ll cval) {
	if (cidx < left || right < cidx) {
		return;
	}
	if (left == right) {
		min_tree[idx] = cval;
		return;
	}
	ll mid = (left + right) / 2;
	min_update(idx * 2, left, mid, cidx, cval);
	min_update(idx * 2 + 1, mid+1, right, cidx, cval);
	min_tree[idx] = min(min_tree[idx * 2], min_tree[idx * 2 + 1]);
	return;
}

ll min_query(ll idx, ll left, ll right, ll qleft, ll qright) {
	if (qright < left || right < qleft) {
		return INF;
	}
	if (qleft <= left && right <= qright) {
		return min_tree[idx];
	}
	ll mid = (left + right) / 2;
	return min(min_query(idx * 2, left, mid, qleft, qright), min_query(idx * 2 + 1, mid + 1, right, qleft, qright));
}

void max_update(ll idx, ll left, ll right, ll cidx, ll cval) {
	if (cidx < left || right < cidx) {
		return;
	}
	if (left == right) {
		max_tree[idx] = cval;
		return;
	}
	ll mid = (left + right) / 2;
	max_update(idx * 2, left, mid, cidx, cval);
	max_update(idx * 2 + 1, mid+1, right, cidx, cval);
	max_tree[idx] = max(max_tree[idx * 2], max_tree[idx * 2 + 1]);
	return;
}

ll max_query(ll idx, ll left, ll right, ll qleft, ll qright) {
	if (qright < left || right < qleft) {
		return -INF;
	}
	if (qleft <= left && right <= qright) {
		return max_tree[idx];
	}
	ll mid = (left + right) / 2;
	return max(max_query(idx * 2, left, mid, qleft, qright), max_query(idx * 2 + 1, mid + 1, right, qleft, qright));
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		ll x;
		cin >> x;
		min_update(1, 1, n, i, x);
		max_update(1, 1, n, i, x);
	}

	for (int i = 1; i <= q; i++) {
		ll a, b;
		cin >> a >> b;
		cout << max_query(1, 1, n, a, b) - min_query(1, 1, n, a, b) << "\n";
	}
	

	return 0;
}