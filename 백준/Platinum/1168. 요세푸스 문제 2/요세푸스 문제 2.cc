#include <bits/stdc++.h>
using namespace std;

int tree[4 * 100'000 + 16];

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
	tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
	return;
}

int query(int idx, int left, int right, int k) {
	if (left == right) {
		return left;
	}
	int mid = (left + right) / 2;
	if (k <= tree[idx * 2]) {
		return query(idx * 2, left, mid, k);
	}
	else {
		return query(idx * 2 + 1, mid + 1, right, k - tree[idx * 2]);
	}
}

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		update(1, 1, n, i, 1);
	}

	vector<int> res;
	int ptr = 0;
	for (int i = 0; i < n; i++) {
		ptr = (ptr + k - 1) % (n - i);

		int x = query(1, 1, n, ptr+1);
		res.push_back(x);
		update(1, 1, n, x, 0);
	}

	cout << "<";
	for (int i = 0; i < res.size(); i++) {
		cout << res[i];
		if (i != res.size() - 1) {
			cout << ", ";
		}
	}
	cout << ">";
	
	
	return 0;
}