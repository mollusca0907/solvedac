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

info zero = {0,0,0,0,0,0};
info tree[200'000 * 4 + 16];

info func(info L, info R) {
	info T;
	T.numL = L.numL;
	T.numR = R.numR;

	if (L.len == L.cntL && L.numR != R.numL) {
		T.cntL = L.len + R.cntL;
	}
	else {
		T.cntL = L.cntL;
	}

	if (R.len == R.cntR && R.numL != L.numR) {
		T.cntR = R.len + L.cntR;
	}
	else {
		T.cntR = R.cntR;
	}

	if (L.numR != R.numL) {
		T.ans = max({ L.ans, R.ans, L.cntR + R.cntL });
	}
	else {
		T.ans = max(L.ans, R.ans);
	}
	T.len = L.len + R.len;

	return T;
}

void update(ll idx, ll left, ll right, ll cidx) {
	if (cidx < left || right < cidx) {
		return;
	}
	if (left == right) {
		tree[idx] = { tree[idx].numL^1, tree[idx].numR ^ 1, 1,1,1,1};
		return;
	}
	ll mid = (left + right) / 2;
	update(idx * 2, left, mid, cidx);
	update(idx * 2 + 1, mid + 1, right, cidx);
	tree[idx] = func(tree[idx * 2], tree[idx * 2 + 1]);
	return;
}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	fill(tree, tree + (200'000 * 4 + 16), zero);

	ll n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		update(1, 1, n, i);
	}

	for (int i = 1; i <= q; i++) {
		ll x;
		cin >> x;
		update(1, 1, n, x);
		cout << tree[1].ans << "\n";
	}
	return 0;
}