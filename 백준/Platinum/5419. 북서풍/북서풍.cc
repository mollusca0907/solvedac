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
	update(idx * 2 + 1, mid + 1, right, cidx, cval);
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

	int tc;
	cin >> tc;

	while (tc--) {

		tree.assign(75'000 * 4 + 16, 0);

		int n;
		cin >> n;

		vector<pair<int, int>> point;
		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			point.push_back({x, y});
		}

		sort(point.begin(), point.end(), [](auto a, auto b) {
			return a.second < b.second;
			});

		int cnt = 0;
		int prev = -1e9;
		for (int i = 0; i < n; i++) {
			if (point[i].second != prev) {
				cnt++;
			}
			prev = point[i].second;
			point[i].second = cnt;
		}

		sort(point.begin(), point.end(), [](auto a, auto b) {
			if (a.first == b.first) {
				return a.second > b.second;
			}
			else {
				return a.first < b.first;
			}
		});

		long long ans = 0;
		for (int i = 0; i < n; i++) {
			ans += query(1, 1, n, point[i].second, cnt);
			update(1, 1, n, point[i].second, 1);
		}

		cout << ans << "\n";


	}



	return 0;
}