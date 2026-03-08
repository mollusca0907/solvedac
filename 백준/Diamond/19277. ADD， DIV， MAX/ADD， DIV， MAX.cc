#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 2e18;

struct Node {
	ll mx;
	ll mn;
	ll sum;
};

Node tree[200'000 * 4 + 16];

ll arr[200'005];

ll lz1[200'000 * 4 + 16];

ll floordiv(ll x, ll y) {
	if (x >= 0 || x%y==0) return x / y;
	return (x - y + 1) / y;
}

void push(ll idx, ll left, ll right) {
	if (!lz1[idx]) {
		return;
	}
	//if (!lz2[idx]) {
	//	tree[idx].mx += lz1[idx];
	//	tree[idx].mn += lz1[idx];
	//	tree[idx].sum += (right - left + 1) * lz1[idx];
	//	if (left != right) {
	//		lz1[idx * 2] += lz1[idx];
	//		lz1[idx * 2 + 1] += lz1[idx];
	//	}
	//}
	else {
		tree[idx].mx += lz1[idx];
		tree[idx].mn += lz1[idx];
		tree[idx].sum += (right - left + 1) * lz1[idx];
		if (left != right) {
			lz1[idx * 2] += lz1[idx];
			lz1[idx * 2 + 1] += lz1[idx];
		}
	}
	lz1[idx] = 0;
	return;
}

Node f(Node a, Node b) {
	return { max(a.mx, b.mx), min(a.mn, b.mn), a.sum + b.sum };
}

void add(ll idx, ll left, ll right, ll cleft, ll cright, ll val) {
	push(idx, left, right);
	if (cright < left || right < cleft) {
		return;
	}
	if (cleft <= left && right <= cright) {
		lz1[idx] += val;
		push(idx, left, right);
		return;
	}
	ll mid = (left + right) / 2;
	add(idx * 2, left, mid, cleft, cright, val);
	add(idx * 2 + 1, mid + 1, right, cleft, cright, val);
	tree[idx] = f(tree[idx * 2], tree[idx * 2 + 1]);
	return;
}

void dv(ll idx, ll left, ll right, ll cleft, ll cright, ll d) {
	push(idx, left, right);
	if (cright < left || right < cleft) {
		return;
	}
	if (cleft <= left && right <= cright) {
		//if (floordiv(tree[idx].mx, d) == floordiv(tree[idx].mn, d)) {
		//	//lz1[idx] = floordiv(tree[idx].mx, d) - tree[idx].mx; //수상함
		//	lz1[idx] = floordiv(tree[idx].mn, d) - tree[idx].mn; //수상함
		//	push(idx, left, right);
		//	return;
		//}
		if (tree[idx].mx - floordiv(tree[idx].mx, d) == tree[idx].mn - floordiv(tree[idx].mn, d)) {
			lz1[idx] = floordiv(tree[idx].mx, d) - tree[idx].mx;
			push(idx, left, right);
			return;
		}
	}
	ll mid = (left + right) / 2;
	dv(idx * 2, left, mid, cleft, cright, d);
	dv(idx * 2 + 1, mid + 1, right, cleft, cright, d);
	tree[idx] = f(tree[idx * 2], tree[idx * 2 + 1]);
	return;
}

ll sumquery(ll idx, ll left, ll right, ll qleft, ll qright) {
	push(idx, left, right);
	if (qright < left || right < qleft) {
		return 0;
	}
	if (qleft <= left && right <= qright) {
		return tree[idx].sum;
	}
	ll mid = (left + right) / 2;
	return sumquery(idx * 2, left, mid, qleft, qright) + sumquery(idx * 2 + 1, mid + 1, right, qleft, qright);
}

ll maxquery(ll idx, ll left, ll right, ll qleft, ll qright) {
	push(idx, left, right);
	if (qright < left || right < qleft) {
		return -INF;
	}
	if (qleft <= left && right <= qright) {
		return tree[idx].mx;
	}
	ll mid = (left + right) / 2;
	return max(maxquery(idx * 2, left, mid, qleft, qright), maxquery(idx * 2 + 1, mid + 1, right, qleft, qright));
}


void init(ll idx, ll left, ll right) {
	if (left == right) {
		tree[idx].mx = arr[left];
		tree[idx].mn = arr[left];
		tree[idx].sum = arr[left];
		return;
	}
	ll mid = (left + right) / 2;
	init(idx * 2, left, mid);
	init(idx * 2 + 1, mid + 1, right);
	tree[idx] = f(tree[idx * 2], tree[idx * 2 + 1]);
	return;
}


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	init(1, 1, n);

	for (int i = 1; i <= m; i++) {
		int command;
		cin >> command;
		if (command == 0) {
			ll l, r, x;
			cin >> l >> r >> x;
			add(1, 1, n, l+1, r + 1, x);
		}
		else if (command == 1) {
			ll l, r, d;
			cin >> l >> r >> d;
			dv(1, 1, n, l + 1, r + 1, d);
		}
		else if (command == 2) {
			ll l, r, x;
			cin >> l >> r >> x;
			cout << maxquery(1, 1, n, l + 1, r + 1) << "\n";
		}
		//else {
		//	ll l, r;
		//	cin >> l >> r;
		//	cout << sumquery(1, 1, n, l + 1, r + 1) << "\n";
		//}
	}


	return 0;
}