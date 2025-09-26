#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> tree;

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

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {

		tree.assign(100'000 * 4 + 16, 0);

		int n, p, q;
		cin >> n >> p >> q;

		for (int i = 1; i <= p + q; i++) {
			char command;
			int a, b;
			cin >> command >> a >> b;
			if (command == 'P') {
				update(1, 1, n, a, b);
			}
			else {
				cout << query(1, 1, n, a, b) << "\n";
			}
		}


	}

	return 0;
}