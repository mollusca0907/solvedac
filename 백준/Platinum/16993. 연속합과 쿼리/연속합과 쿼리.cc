#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e18;

struct Info {
	ll maxL;
	ll maxR;
	ll sum;
	ll ans;
};

Info base = { -INF, -INF, 0, -INF};
Info tree[100'000 * 4 + 16];

Info Merge(Info L, Info R) {
	Info T;
	if (L.ans == -INF) {
		return R;
	}
	if (R.ans == -INF) {
		return L;
	}
	T.sum = L.sum + R.sum;
	T.maxL = max(L.maxL, L.sum + R.maxL);
	T.maxR = max(R.maxR, R.sum + L.maxR);
	T.ans = max({L.ans, R.ans, L.maxR + R.maxL});
	return T;
}

void update(ll idx, ll left, ll right, ll cidx, ll cval) {
	if (cidx < left || right < cidx) {
		return;
	}
	if (left == right) {
		tree[idx] = { cval,cval,cval,cval };
		return;
	}
	ll mid = (left + right) / 2;
	update(idx * 2, left, mid, cidx, cval);
	update(idx * 2 + 1, mid + 1, right, cidx, cval);
	tree[idx] = Merge(tree[idx * 2], tree[idx * 2 + 1]);
	return;
}

Info query(ll idx, ll left, ll right, ll qleft, ll qright) {
	if (qright < left || right < qleft) {
		return base;
	}
	if (qleft <= left && right <= qright) {
		return tree[idx];
	}
	ll mid = (left + right) / 2;
	return Merge(query(idx * 2, left, mid, qleft, qright), query(idx * 2 + 1, mid + 1, right, qleft, qright));
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		ll x;
		cin >> x;
		update(1, 1, n, i, x);
	}

	cin >> m;
	for (int i = 1; i <= m; i++) {
		ll a, b;
		cin >> a >> b;
		cout << query(1, 1, n, a, b).ans << "\n";
	}

	return 0;
}