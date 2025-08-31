#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll tree[1'000'000 * 4 + 16];

void update(ll idx, ll left, ll right, ll cidx, ll cval) {
	if (cidx < left || right < cidx) {
		return;
	}
	if (left == right) {
		tree[idx] = cval%2;
		return;
	}

	ll mid = (left + right) / 2;
	update(idx * 2, left, mid, cidx, cval);
	update(idx * 2 + 1, mid + 1, right, cidx, cval);
	tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
	return;
}

ll query(ll idx, ll left, ll right, ll qleft, ll qright) {
	if (qright < left || right < qleft) {
		return 0;
	}
	if (qleft <= left && right <= qright) {
		return tree[idx];
	}
	ll mid = (left + right) / 2;
	return query(idx * 2, left, mid, qleft, qright) + query(idx * 2 + 1, mid + 1, right, qleft, qright);
}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		ll x;
		cin >> x;
		update(1, 1, n, i, x);
	}

	cin >> m;

	for (int i = 1; i <= m; i++) {
		int command, a, b;
		cin >> command >> a >> b;

		if (command == 1) {
			update(1, 1, n, a, b);
		}
		else if (command == 2) {
			cout << (b - a + 1) - query(1, 1, n, a, b) << "\n";
		}
		
		else {
			cout << query(1, 1, n, a, b) << "\n";
		}
	}
	

	return 0;
}