#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

ll tree[1'000'000 * 4 + 16];
ll lazy[1'000'000 * 4 + 16];

void push(ll idx, ll left, ll right) {
	if (lazy[idx] != 0) {
		tree[idx] = (right - left + 1) - tree[idx];
		if (left != right) { //not leaf then
			lazy[idx * 2] ^= 1;
			lazy[idx * 2 + 1] ^= 1;
		}
		lazy[idx] = 0;
	}
}


void update(ll idx, ll left, ll right, ll cleft, ll cright) {
	push(idx, left, right);
	if (right < cleft || cright < left) {
		return;
	}
	if (cleft <= left && right <= cright) {
		lazy[idx] ^= 1;
		push(idx, left, right);
		return;
	}

	ll mid = (left + right) / 2;
	update(idx * 2, left, mid, cleft, cright);
	update(idx * 2 + 1, mid + 1, right, cleft, cright);
	tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
}

ll query(ll idx, ll left, ll right, ll qleft, ll qright) {
	push(idx, left, right);
	if (right < qleft || qright < left) {
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
	cin.tie(nullptr);
	cout.tie(nullptr);


	ll n, m;
	cin >> n >> m;

	for (int i = 1; i <= m; i++) {
		ll command;
		cin >> command;
		if (command == 0) {//update
			ll a, b;
			cin >> a >> b;
			update(1, 1, n, a, b);
		}
		else {//query
			ll a, b;
			cin >> a >> b;
			cout << 1LL * query(1, 1, n, a, b) << "\n";
		}
	}


	return 0;
}