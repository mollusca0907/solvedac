#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//const int INF = 2e9;

int tree[100'000 * 4 + 16];

int n;
vector<ll> v;
vector<ll> ps;


void update(int idx, int left, int right, int cidx, int cval) {
	if (cidx < left || right < cidx) {
		return;
	}
	if (left == right) {
		tree[idx] = cval;
		return;
	}
	int mid = (left + right) / 2;
	update(idx * 2, left, mid, cidx, cval);
	update(idx * 2 + 1, mid+1, right, cidx, cval);

	tree[idx] = (v[tree[idx*2]] < v[tree[idx*2+1]]) ? tree[idx * 2] : tree[idx * 2 + 1];
	return;
}

ll query(int idx, int left, int right, int qleft, int qright) {
	if (qright < left || right < qleft) {
		return -1;
	}
	if (qleft <= left && right <= qright) {
		return tree[idx];
	}
	int mid = (left + right) / 2;
	ll lc = query(idx * 2, left, mid, qleft, qright);
	ll rc = query(idx * 2 + 1, mid + 1, right, qleft, qright);
	if (lc == -1) {
		return rc;
	}
	if (rc == -1) {
		return lc;
	}
	return (v[lc] < v[rc]) ? lc : rc;
}

struct Range {
	ll val;
	ll left;
	ll right;
};
Range solve(int left, int right) {
	if (right < left) {
		return {0,0,0};
	}
	int min_idx = query(1, 1, n, left, right);
	Range s = { (ps[right] - ps[left - 1]) * v[min_idx], left, right };
	Range lc = solve(left, min_idx - 1);
	Range rc = solve(min_idx + 1, right);

	Range m;
	if (lc.val > rc.val) {
		m = lc;
	}
	else {
		m = rc;
	}
	if (s.val > m.val) {
		m = s;
	}
	return m;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;

	v.assign(n+1,0);
	ps.assign(n+1,0);

	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		v[i] = x;
		update(1, 1, n, i, i);
	}

	ps[0] = 0;
	ps[1] = v[1];


	for (int i = 2; i <= n; i++) {
		ps[i] = ps[i - 1] + v[i];
	}

	Range res = solve(1, n);

	cout << res.val << "\n";
	//if (res.left == 0 && res.right == 0) {
	//	cout << "1 1";
	//}
	//else {
	//	cout << res.left << " " << res.right;
	//}

	return 0;
}