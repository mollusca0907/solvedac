#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

ll tree[500'000 * 4 + 16];
ll lazy[500'000 * 4 + 16];

void push(ll idx, ll left, ll right) {
	if (lazy[idx] != 0) {
		if ((right - left + 1) % 2 != 0) {
			tree[idx] ^= lazy[idx];
		}
		if (left != right) { //not leaf then
			lazy[idx * 2] ^= lazy[idx];
			lazy[idx * 2 + 1] ^= lazy[idx];
		}
		lazy[idx] = 0;
	}
}


void update(ll idx, ll left, ll right, ll cleft, ll cright, ll val) {
	push(idx, left, right);
	if (right < cleft || cright < left) {
		return;
	}
	if (cleft <= left && right <= cright) {
		lazy[idx] ^= val;
		push(idx, left, right);
		return;
	}

	ll mid = (left + right) / 2;
	update(idx * 2, left, mid, cleft, cright, val);
	update(idx * 2 + 1, mid + 1, right, cleft, cright, val);
	tree[idx] = tree[idx * 2] ^ tree[idx * 2 + 1];
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
	ll lchild = query(idx * 2, left, mid, qleft, qright);
	ll rchild = query(idx * 2 + 1, mid + 1, right, qleft, qright);
	return lchild ^ rchild;
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	ll n, m;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		ll x;
		cin >> x;
		update(1, 1, n, i, i, x);
	}

	cin >> m;

	for (int i = 1; i <= m; i++) {
		ll command;
		cin >> command;
		if (command == 1) {//update
			ll a, b, c;
			cin >> a >> b >> c;
			update(1, 1, n, a + 1, b + 1, c);
		}
		else {//query
			ll a, b;
			cin >> a >> b;
			cout << 1LL * query(1, 1, n, a + 1, b + 1) << "\n";
		}
	}


	return 0;
}