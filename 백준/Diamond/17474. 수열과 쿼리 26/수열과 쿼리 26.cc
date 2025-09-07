#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node {
	ll mx;
	ll mx2;
	ll mxcnt;
	ll sum;
};

Node tree[1'000'000 * 4 + 16];
ll arr[1'000'005];

void push(ll idx, ll left, ll right) {
	if (left == right) {
		return;
	}
	for (auto i : { idx*2, idx*2+1 }) {
		if (tree[idx].mx < tree[i].mx) {
			tree[i].sum -= tree[i].mxcnt * (tree[i].mx - tree[idx].mx);
			tree[i].mx = tree[idx].mx;
		}
	}
}

Node f(Node a, Node b) {
	if (a.mx == b.mx) {
		return { a.mx, max(a.mx2, b.mx2), a.mxcnt + b.mxcnt, a.sum + b.sum };
	}
	if (a.mx > b.mx) {
		swap(a, b);
	}
	return { b.mx, max(a.mx, b.mx2), b.mxcnt, a.sum + b.sum };
}

Node init(ll idx, ll left, ll right) {
	if (left == right) {
		tree[idx] = { arr[left], -1, 1, arr[left] };
		return tree[idx];
	}
	ll mid = (left + right) / 2;
	tree[idx] = f(init(idx * 2, left, mid), init(idx * 2 + 1, mid + 1, right));
	return tree[idx];
}

void update(ll idx, ll left, ll right, ll cleft, ll cright, ll val) {
	push(idx, left, right);
	if (cright < left || right < cleft || tree[idx].mx < val) {
		return;
	}
	if (cleft <= left && right <= cright && tree[idx].mx2 < val) {
		tree[idx].sum -= tree[idx].mxcnt * (tree[idx].mx - val);
		tree[idx].mx = val;
		push(idx, left, right);
		return;
	}
	ll mid = (left + right) / 2;
	update(idx * 2, left, mid, cleft, cright, val);
	update(idx*2+1, mid+1, right, cleft, cright, val);
	tree[idx] = f(tree[idx * 2], tree[idx * 2 + 1]);
	return;
}

ll mx_query(ll idx, ll left, ll right, ll qleft, ll qright) {
	push(idx, left, right);
	if (qright < left || right < qleft) {
		return 0;
	}
	if (qleft <= left && right <= qright) {
		return tree[idx].mx;
	}
	ll mid = (left + right) / 2;
	return max(mx_query(idx * 2, left, mid, qleft, qright), mx_query(idx * 2 + 1, mid + 1, right, qleft, qright));
}

ll sm_query(ll idx, ll left, ll right, ll qleft, ll qright) {
	push(idx, left, right);
	if (qright < left || right < qleft) {
		return 0;
	}
	if (qleft <= left && right <= qright) {
		return tree[idx].sum;
	}
	ll mid = (left + right) / 2;
	return sm_query(idx * 2, left, mid, qleft, qright) + sm_query(idx * 2 + 1, mid + 1, right, qleft, qright);
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
			update(1, 1, n, l, r, x);
		}
		else if (command == 2) {
			ll l, r;
			cin >> l >> r;
			cout << mx_query(1, 1, n, l, r) << "\n";
		}
		else {
			ll l, r;
			cin >> l >> r;
			cout << sm_query(1, 1, n, l, r) << "\n";
		}

	}

	return 0;
}