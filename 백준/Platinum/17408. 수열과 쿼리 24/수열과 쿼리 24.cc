#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>; //firstMax, secondMax

pii tree[4 * 100'000 + 16];

pii f(pii a, pii b) {
	vector<int> v = { a.first, a.second,b.first,b.second };
	sort(v.begin(), v.end(), [](auto a, auto b) {
		return a > b;
		});
	return { v[0], v[1] };
}

void update(int idx, int left, int right, int cidx, int cval) {
	if (cidx < left || right < cidx) {
		return;
	}
	if (left == right) {
		tree[idx].first = cval;
		tree[idx].second = 0;
		return;
	}
	int mid = (left + right) / 2;
	update(idx*2, left, mid, cidx, cval);
	update(idx*2+1, mid+1, right, cidx, cval);
	tree[idx] = f(tree[idx * 2], tree[idx * 2 + 1]);
	return;
}

pii query(int idx, int left, int right, int qleft, int qright) {
	if (qright < left || right < qleft) {
		return { 0,0 };
	}
	if (qleft <= left && right <= qright) {
		return tree[idx];
	}
	int mid = (left + right) / 2;
	return f(query(idx * 2, left, mid, qleft, qright), query(idx * 2 + 1, mid + 1, right, qleft, qright));
}



int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		update(1, 1, n, i, x);
	}

	cin >> m;

	for (int i = 0; i < m; i++) {
		int command, a, b;
		cin >> command >> a >> b;
		if (command == 1) {
			update(1, 1, n, a, b);
		}
		else {
			pii res = query(1, 1, n, a, b);
			cout << res.first + res.second << "\n";
		}
	}

	return 0;
}