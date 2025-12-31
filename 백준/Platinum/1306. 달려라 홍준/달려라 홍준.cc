#include <bits/stdc++.h>
using namespace std;

int tree[1'000'000 * 4 + 16];

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
	tree[idx] = max(tree[idx * 2], tree[idx * 2 + 1]);
	return;
}

int query(int idx, int left, int right, int qleft, int qright) {
	if (qright < left || right < qleft) {
		return 0;
	}
	if (qleft <= left && right <= qright) {
		return tree[idx];
	}
	int mid = (left + right) / 2;
	return max(query(idx * 2, left, mid, qleft, qright), query(idx * 2 + 1, mid + 1, right, qleft, qright));
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		update(1, 1, n, i, x);
	}

	for (int i = m; i + m - 1 <= n; i++) {
		cout << query(1, 1, n, i-(m-1), i + m - 1) << " ";
	}


	return 0;
}