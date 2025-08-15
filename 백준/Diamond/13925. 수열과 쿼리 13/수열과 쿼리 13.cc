#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

struct Lazy {
	long long sum = 0;
	long long mul = 1;
};

ll tree[100'000 * 4 + 16];
Lazy lazy[100'000 * 4 + 16];

void push(ll idx, ll left, ll right) {
	if (lazy[idx].sum != 0 || lazy[idx].mul != 1) {
		tree[idx] = (((tree[idx] * lazy[idx].mul) % MOD) + (((right - left + 1) * lazy[idx].sum) % MOD)) % MOD;
		if (left != right) {

			lazy[idx * 2].mul = (lazy[idx * 2].mul * lazy[idx].mul) % MOD;
			lazy[idx * 2].sum = (lazy[idx * 2].sum * lazy[idx].mul % MOD + lazy[idx].sum) % MOD;

			lazy[idx * 2 + 1].mul = (lazy[idx * 2 + 1].mul * lazy[idx].mul) % MOD;
			lazy[idx * 2 + 1].sum = (lazy[idx * 2 + 1].sum * lazy[idx].mul % MOD + lazy[idx].sum) % MOD;
		}
		lazy[idx].mul = 1;
		lazy[idx].sum = 0;
	}	
}

void update(ll idx, ll left, ll right, ll cleft, ll cright, ll cval) {
	push(idx, left, right);
	if (cright < left || right < cleft) {
		return;
	}
	if (cleft <= left && right <= cright) {
		lazy[idx].mul = 0;
		lazy[idx].sum = cval % MOD;
		push(idx, left, right);
		return;
	}
	ll mid = (left + right) / 2;
	update(idx * 2, left, mid, cleft, cright, cval);
	update(idx * 2 + 1, mid + 1, right, cleft, cright, cval);
	tree[idx] = (tree[idx * 2] + tree[idx * 2 + 1]) % MOD;
	return;
}


void range_sum(ll idx, ll left, ll right, ll cleft, ll cright, ll val) {
	push(idx, left, right);
	if (right < cleft || cright < left) {
		return;
	}
	if (cleft <= left && right <= cright) {
		lazy[idx].sum = ((lazy[idx].sum % MOD) + (val % MOD)) % MOD;
		push(idx, left, right);
		return;
	}

	ll mid = (left + right) / 2;
	range_sum(idx * 2, left, mid, cleft, cright, val);
	range_sum(idx * 2 + 1, mid + 1, right, cleft, cright, val);
	tree[idx] = (tree[idx * 2] + tree[idx * 2 + 1]) % MOD;
}

void range_mul(ll idx, ll left, ll right, ll cleft, ll cright, ll val) {
	push(idx, left, right);
	if (right < cleft || cright < left) {
		return;
	}
	if (cleft <= left && right <= cright) {
		lazy[idx].mul = ((lazy[idx].mul % MOD) * (val % MOD)) % MOD;
		lazy[idx].sum = ((lazy[idx].sum % MOD) * (val % MOD)) % MOD;
		push(idx, left, right);
		return;
	}

	ll mid = (left + right) / 2;
	range_mul(idx * 2, left, mid, cleft, cright, val);
	range_mul(idx * 2 + 1, mid + 1, right, cleft, cright, val);
	tree[idx] = (tree[idx * 2] + tree[idx * 2 + 1]) % MOD;
}

ll query(ll idx, ll left, ll right, ll qleft, ll qright) {
	push(idx, left, right);
	if (right < qleft || qright < left) {
		return 0;
	}
	if (qleft <= left && right <= qright) {
		return tree[idx] % MOD;
	}
	ll mid = (left + right) / 2;
	return 1LL * (query(idx * 2, left, mid, qleft, qright) + query(idx * 2 + 1, mid + 1, right, qleft, qright)) % MOD;
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
		int command;
		cin >> command;
		if (command == 1) {
			ll x, y, v;
			cin >> x >> y >> v;
			range_sum(1, 1, n, x, y, v);
		}
		else if (command == 2) {
			ll x, y, v;
			cin >> x >> y >> v;
			range_mul(1, 1, n, x, y, v);
		}
		else if (command == 3) {
			ll x, y, v;
			cin >> x >> y >> v;
			update(1, 1, n, x, y, v);
		}
		else {
			ll x, y;
			cin >> x >> y;
			cout << 1LL * query(1, 1, n, x, y) << "\n";
		}
	}

	return 0;
}