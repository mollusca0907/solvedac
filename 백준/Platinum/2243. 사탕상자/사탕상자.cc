#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll tree[1'000'000 * 4 + 16];

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

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int command;
		cin >> command;
		if (command == 1) {
			ll a;
			cin >> a;
			ll umai = query(1, 1, 1'000'000, a);
			cout << umai << "\n";
			update(1, 1, 1'000'000, umai, -1);
		}
		else {
			ll a, b;
			cin >> a >> b;
			update(1, 1, 1'000'000, a, b);
		}
	}

	return 0;
}