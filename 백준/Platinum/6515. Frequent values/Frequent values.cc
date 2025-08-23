#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct info {
	ll numL = 0;
	ll numR = 0;
	ll cntL = 0;
	ll cntR = 0;
	ll len = 0;
	ll ans = 0;
};

info zero = { 0,0,0,0,0,0 };
info tree[100'000 * 4 + 16];

info func(info L, info R) {
	info T;
	T.numL = L.numL;
	T.numR = R.numR;
	//if (L.numL == L.numR && L.numR == R.numL) {
	if (L.len == L.cntL && L.numR == R.numL){
		T.cntL = L.len + R.cntL;
	}
	else {
		T.cntL = L.cntL;
	}
	//if (R.numR == R.numL && R.numL == L.numR) {
	if (R.len == R.cntR && L.numR == R.numL) {
		T.cntR = R.len + L.cntR;
	}
	else {
		T.cntR = R.cntR;
	}
	T.len = L.len + R.len;
	if (L.numR == R.numL) {
		T.ans = max({L.ans, R.ans, L.cntR + R.cntL});
	}
	else {
		T.ans = max(L.ans, R.ans);
	}
	return T;
}

void update(ll idx, ll left, ll right, ll cidx, ll cval) {
	if (cidx < left || right < cidx) {
		return;
	}
	if (left == right) {
		tree[idx] = { cval, cval, 1,1,1,1 };
		return;
	}
	ll mid = (left + right) / 2;
	update(idx * 2, left, mid, cidx, cval);
	update(idx * 2 + 1, mid + 1, right, cidx, cval);
	tree[idx] = func(tree[idx * 2], tree[idx * 2 + 1]);
	return;
}

info query(ll idx, ll left, ll right, ll qleft, ll qright) {
	if (qright < left || right < qleft) {
		return zero;
	}
	if (qleft <= left && right <= qright) {
		return tree[idx];
	}
	ll mid = (left + right) / 2;
	return func(query(idx * 2, left, mid, qleft, qright), query(idx * 2 + 1, mid + 1, right, qleft, qright));
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	while (1) {
		int n, q;
		cin >> n;
		if (n == 0) {
			return 0;
		}
		cin >> q;

		fill(tree, tree + (100'000 * 4 + 16), zero);

		for (int i = 1; i <= n; i++) {
			ll x;
			cin >> x;
			update(1, 1, n, i, x);
		}

		for (int i = 1; i <= q; i++) {
			ll st, ed;
			cin >> st >> ed;
			cout << query(1, 1, n, st, ed).ans << "\n";
		}
	}
	return 0;
}