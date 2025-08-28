#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> tree[100'000 * 4 + 16];
vector<int> v;

void build(int idx, int left, int right) {
	if (left == right) {
		tree[idx].push_back(v[left]);
		return;
	}
	int mid = (left + right) / 2;
	build(idx * 2, left, mid);
	build(idx * 2 + 1, mid+1, right);

	merge(tree[idx * 2].begin(), tree[idx * 2].end(),
		tree[idx * 2 + 1].begin(), tree[idx * 2 + 1].end(),
		back_inserter(tree[idx]));
}

int query(int idx, int left, int right, int qleft, int qright, int val) {
	if (qright < left || right < qleft) {
		return 0;
	}
	if (qleft <= left && right <= qright) {
		return lower_bound(tree[idx].begin(), tree[idx].end(), val) - tree[idx].begin();
	}
	int mid = (left + right) / 2;
	return query(idx * 2, left, mid, qleft, qright, val) + query(idx * 2 + 1, mid + 1, right, qleft, qright, val);
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	v.assign(n+1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}

	build(1, 1, n);

	for (int i = 1; i <= m; i++) {

		int a, b, c;
		cin >> a >> b >> c;

		int left = -1e9;
		int right = 1e9;

		int ans = 0;

		while (left <= right) {
			int mid = (left + right) / 2;
			int cnt = query(1, 1, n, a, b, mid+1);
			if (cnt < c) {
				left = mid + 1;
			}
			else {
				ans = mid;
				right = mid - 1;
			}
		}
		cout << ans << "\n";
	}



	return 0;
}