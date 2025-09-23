#include <bits/stdc++.h>
using namespace std;

int tree[100'000 * 4 + 16];

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
	update(idx * 2 + 1, mid + 1, right, cidx, cval);
	tree[idx] = tree[idx * 2] * tree[idx * 2 + 1];
	return;
}

int query(int idx, int left, int right, int qleft, int qright) {
	if (right < qleft || qright < left) {
		return 1;
	}
	if (qleft <= left && right <= qright) {
		return tree[idx];
	}
	int mid = (left + right) / 2;
	return query(idx * 2, left, mid, qleft, qright) * query(idx * 2 + 1, mid + 1, right, qleft, qright);
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;

	while (cin >> n >> k) {
		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			if (x < 0) x = -1;
			if (x > 0) x = 1;
			update(1, 1, n, i, x);
		}

		for (int i = 1; i <= k; i++) {
			char command;
			int a, b;
			cin >> command >> a >> b;

			if (command == 'C') {
				if (b < 0) b = -1;
				if (b > 0) b = 1;
				update(1, 1, n, a, b);
			}
			else {
				int output = query(1, 1, n, a, b);
				if (output == 0) {
					cout << "0";
				}
				else if (output > 0) {
					cout << "+";
				}
				else {
					cout << "-";
				}
			}
		}
		cout << "\n";
	}

	return 0;
}