#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node {
	ll mx;
	ll mn;
	ll sum;
};

Node tree[100'000 * 4 + 16];

ll arr[100'005];

ll lz1[100'000 * 4 + 16];//sum
ll lz2[100'000 * 4 + 16];//sqrt

void push(ll idx, ll left, ll right) {
	if (!lz1[idx] && !lz2[idx]) {
		return;
	}
	if (!lz2[idx]) {
		tree[idx].mx += lz1[idx];
		tree[idx].mn += lz1[idx];
		tree[idx].sum += (right - left + 1) * lz1[idx];
		if (left != right) {
			lz1[idx * 2] += lz1[idx];
			lz1[idx * 2 + 1] += lz1[idx];
		}
	}
	else {
		tree[idx].mx = lz1[idx] + lz2[idx];
		tree[idx].mn = lz1[idx] + lz2[idx];
		tree[idx].sum = (right - left + 1) * (lz1[idx] + lz2[idx]);
		if (left != right) {
			lz1[idx * 2] = lz1[idx];
			lz1[idx * 2 + 1] = lz1[idx];
			lz2[idx * 2] = lz2[idx];
			lz2[idx * 2 + 1] = lz2[idx];
		}
	}
	lz1[idx] = 0;
	lz2[idx] = 0;
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
		lz1[idx] = val;
		push(idx, left, right);
		return;
	}
	ll mid = (left + right) / 2;
	add(idx * 2, left, mid, cleft, cright, val);
	add(idx * 2 + 1, mid + 1, right, cleft, cright, val);
	tree[idx] = f(tree[idx * 2], tree[idx * 2 + 1]);
	return;
}

void sq(ll idx, ll left, ll right, ll cleft, ll cright) {
	push(idx, left, right);
	if (cright < left || right < cleft) {
		return;
	}
	if (cleft <= left && right <= cright) {
		if (floor(sqrt(tree[idx].mx)) == floor(sqrt(tree[idx].mn))) {
			lz2[idx] = floor(sqrt(tree[idx].mx));
			push(idx, left, right);
			return;
		}
		if (tree[idx].mn + 1 == tree[idx].mx) {
			lz1[idx] = floor(sqrt(tree[idx].mn)) - tree[idx].mn;
			push(idx, left, right);
			return;
		}
	}
	ll mid = (left + right) / 2;
	sq(idx * 2, left, mid, cleft, cright);
	sq(idx * 2 + 1, mid + 1, right, cleft, cright);
	tree[idx] = f(tree[idx * 2], tree[idx * 2 + 1]);
	return;
}

ll query(ll idx, ll left, ll right, ll qleft, ll qright) {
	push(idx, left, right);
	if (qright < left || right < qleft) {
		return 0;
	}
	if (qleft <= left && right <= qright) {
		return tree[idx].sum;
	}
	ll mid = (left + right) / 2;
	return query(idx * 2, left, mid, qleft, qright) + query(idx * 2 + 1, mid + 1, right, qleft, qright);
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

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	init(1, 1, n);

	cin >> m;
	for (int i = 1; i <= m; i++) {
		int command;
		cin >> command;
		if (command == 1) {
			ll l, r, x;
			cin >> l >> r >> x;
			add(1, 1, n, l, r, x);
		}
		else if (command == 2) {
			ll l, r;
			cin >> l >> r;
			sq(1, 1, n, l, r);
		}
		else {
			ll l, r;
			cin >> l >> r;
			cout << query(1, 1, n, l, r) << "\n";
		}
	}


	return 0;
}