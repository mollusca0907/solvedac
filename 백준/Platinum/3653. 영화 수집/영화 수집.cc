#include <bits/stdc++.h>
using namespace std;

vector<int> tree;

void update(int idx, int left, int right, int cidx, int cval) {
	if (cidx < left || right < cidx) {
		return;
	}
	if (left == right) {
		tree[idx] += cval;
		return;
	}
	int mid = (left + right) / 2;
	update(idx * 2, left, mid, cidx, cval);
	update(idx * 2 + 1, mid+1, right, cidx, cval);
	tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
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
	return query(idx * 2, left, mid, qleft, qright) + query(idx * 2 + 1, mid + 1, right, qleft, qright);
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {
		tree.assign(200'000 * 4 + 16, 0);
		int n, m;
		cin >> n >> m;

		vector<int> idx(n + 1);
		for (int i = 1; i <= n; i++) {
			idx[i] = m + i;
			update(1, 1, m+n, idx[i], 1);
		}

		int top = m;
		for (int i = 1; i <= m; i++) {
			int x;
			cin >> x;

			cout << query(1, 1, m + n, 1, idx[x]-1) << " ";
			update(1, 1, m + n, idx[x], -1);
			idx[x] = top;
			update(1, 1, m + n, idx[x], 1);
			top--;
		}
		cout << "\n";
	}

	return 0;
}