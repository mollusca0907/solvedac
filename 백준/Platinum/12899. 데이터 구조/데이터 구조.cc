#include <bits/stdc++.h>
using namespace std;

const int MAX = 2'000'000;
int tree[MAX * 4 + 16];

void update(int idx, int left, int right, int cidx){
	if (cidx < left || right < cidx) {
		return;
	}
	if (left == right) {
		tree[idx]++;
		return;
	}
	int mid = (left + right) / 2;
	update(idx * 2, left, mid, cidx);
	update(idx * 2 + 1, mid + 1, right, cidx);
	tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
	return;
}

int query(int idx, int left, int right, int k) {
	if (left == right) {
		tree[idx]--;
		return left;
	}
	int mid = (left + right) / 2;
	int res;
	if (k <= tree[idx * 2]) {
		res = query(idx * 2, left, mid, k);
	}
	else {
		k -= tree[idx * 2];
		res = query(idx * 2 + 1, mid + 1, right, k);
	}
	tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
	return res;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	while (n--) {
		int t, x;
		cin >> t >> x;
		if (t == 1) {
			update(1, 1, MAX, x);
		}
		else {
			cout << query(1, 1, MAX, x) << "\n";
		}
	}

	return 0;
}