#include <bits/stdc++.h>
using namespace std;
vector<int> tree[100'000 * 4 + 16];
int arr[100'000 + 16];

void build(int idx, int left, int right) {
	if (left == right) {
		tree[idx] = { arr[left] };
		return;
	}
	int mid = (left + right) / 2;
	build(idx * 2, left, mid);
	build(idx * 2 + 1, mid + 1, right);
	merge(tree[idx * 2].begin(), tree[idx * 2].end(),
		tree[idx * 2 + 1].begin(), tree[idx * 2 + 1].end(),
		back_inserter(tree[idx]));
	return;
}

int query(int idx, int left, int right, int qleft, int qright, int val) {
	if (qright < left || right < qleft) {
		return 0;
	}
	if (qleft <= left && right <= qright) {
		return tree[idx].end() - upper_bound(tree[idx].begin(), tree[idx].end(), val);
	}
	int mid = (left + right) / 2;
	return query(idx * 2, left, mid, qleft, qright, val) + query(idx * 2 + 1, mid + 1, right, qleft, qright, val);
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	build(1, 1, n);
	cin >> m;
	int last_ans = 0;
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a ^= last_ans;
		b ^= last_ans;
		c ^= last_ans;
		last_ans = query(1, 1, n, a, b, c);
		cout << last_ans << "\n";
	}
	return 0;
}