#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int INF = 0x7FFFFFFF;

pair<int,int> tree[100'000 * 4 + 16]; //val, idx

void update(int left, int right, int idx, int cidx, int cval) {
	if (cidx < left || right < cidx) {
		return;
	}
	if (left == right) {
		tree[idx] = {cval, cidx};
		return;
	}
	int mid = (left + right) / 2;
	update(left, mid, idx * 2, cidx, cval);
	update(mid+1, right, idx * 2 + 1, cidx, cval);
	tree[idx] = min(tree[idx * 2], tree[idx * 2 + 1]);
	return;
}

pair<int,int> query(int left, int right, int idx, int st, int ed) {
	if (ed < left || right < st) {
		return {INF, INF};
	}
	if (st <= left && right <= ed) {
		return tree[idx];
	}
	int mid = (left + right) / 2;
	return min(query(left, mid, idx * 2, st, ed), query(mid + 1, right, idx * 2 + 1, st, ed));
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		update(1, n, 1, i, x);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int command;
		cin >> command;
		if (command == 1) {
			int x, y;
			cin >> x >> y;
			update(1, n, 1, x, y);
		}
		else {
			cout << query(1, n, 1, 1, n).second << "\n";
		}
	}
	return 0;
}