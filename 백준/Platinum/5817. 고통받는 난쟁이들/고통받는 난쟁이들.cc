#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;
using ll = long long;

ll min_tree[200'200 * 4 + 16] = { 0, };
ll max_tree[200'200 * 4 + 16] = { 0, };

vector<int> v;

void min_update(ll left, ll right, ll idx, ll cidx, ll cval) {
	if (cidx < left || right < cidx) {
		return;
	}
	if (left == right) {
		min_tree[idx] = cval;
		return;
	}
	ll mid = (left + right) / 2;
	min_update(left, mid, idx * 2, cidx, cval);
	min_update(mid+1, right, idx * 2+1, cidx, cval);
	min_tree[idx] = min(min_tree[idx * 2], min_tree[idx * 2 + 1]);
	return;
}

void max_update(ll left, ll right, ll idx, ll cidx, ll cval) {
	if (cidx < left || right < cidx) {
		return;
	}
	if (left == right) {
		max_tree[idx] = cval;
		return;
	}
	ll mid = (left + right) / 2;
	max_update(left, mid, idx * 2, cidx, cval);
	max_update(mid + 1, right, idx * 2 + 1, cidx, cval);
	max_tree[idx] = max(max_tree[idx * 2], max_tree[idx * 2 + 1]);
	return;
}

ll min_query(ll left, ll right, ll idx, ll st, ll ed) {
	if (ed < left || right < st) {
		return LLONG_MAX;
	}
	if (st <= left && right <= ed) {
		return min_tree[idx];
	}
	ll mid = (left + right) / 2;
	return min(min_query(left, mid, idx * 2, st, ed), min_query(mid + 1, right, idx * 2 + 1, st, ed));
}

ll max_query(ll left, ll right, ll idx, ll st, ll ed) {
	if (ed < left || right < st) {
		return LLONG_MIN;
	}
	if (st <= left && right <= ed) {
		return max_tree[idx];
	}
	ll mid = (left + right) / 2;
	return max(max_query(left, mid, idx * 2, st, ed), max_query(mid + 1, right, idx * 2 + 1, st, ed));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	v.push_back(-1);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
		min_update(1, n, 1, x, i);
		max_update(1, n, 1, x, i);
	}
	for (int i = 1; i <= m; i++) {
		int command, x, y;
		cin >> command >> x >> y;
		if (command == 1) { //swap
			min_update(1, n, 1, v[y], x);
			min_update(1, n, 1, v[x], y);
			max_update(1, n, 1, v[y], x);
			max_update(1, n, 1, v[x], y);
			swap(v[x], v[y]);
		}
		else {
			ll min = min_query(1, n, 1, x, y);
			ll max = max_query(1, n, 1, x, y);
			if (max-min == y-x) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
	}
	return 0;
}