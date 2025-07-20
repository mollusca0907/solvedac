#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

ll tree[1'000'000 * 4 + 16];

void update(ll left, ll right, ll idx, ll cidx, ll cval) {
	if (cidx < left || right < cidx) {
		return;
	}
	if (left == right) {
		tree[idx] = cval;
		return;
	}
	ll mid = (left + right) / 2;
	update(left, mid, idx * 2, cidx, cval);
	update(mid + 1, right, idx * 2 + 1, cidx, cval);
	tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
	return;
}

ll query(ll left, ll right, ll idx, ll st, ll ed) {
	if (ed < left || right < st) {
		return 0;
	}
	if (st <= left && right <= ed) {
		return tree[idx];
	}
	ll mid = (left + right) / 2;
	return query(left, mid, idx * 2, st, ed) + query(mid + 1, right, idx * 2 + 1, st, ed);
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= m; i++) {
		ll command, x, y;
		cin >> command >> x >> y;
		if (command == 0) { //sum
			cout << query(1, n, 1, min(x,y), max(x, y)) << "\n";
		}
		else { //modify
			update(1, n, 1, x, y);
		}
	}

	return 0;
}