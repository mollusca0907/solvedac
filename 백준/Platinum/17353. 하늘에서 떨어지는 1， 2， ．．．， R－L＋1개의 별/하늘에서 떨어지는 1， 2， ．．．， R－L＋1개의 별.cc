#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll tree[100'000 * 4 + 16];
ll lazy[100'000 * 4 + 16];

void push(ll idx, ll left, ll right) {
	if (lazy[idx] != 0) {
		tree[idx] += (right - left + 1) * lazy[idx];
		if (left != right) { //not leaf then
			lazy[idx * 2] += lazy[idx];
			lazy[idx * 2 + 1] += lazy[idx];
		}
		lazy[idx] = 0;
	}
}


void update(ll idx, ll left, ll right, ll cleft, ll cright, ll val) {
	push(idx, left, right);
	if (right < cleft || cright < left) {
		return;
	}
	if (cleft <= left && right <= cright) {
		lazy[idx] += val;
		push(idx, left, right);
		return;
	}

	ll mid = (left + right) / 2;
	update(idx * 2, left, mid, cleft, cright, val);
	update(idx * 2 + 1, mid + 1, right, cleft, cright, val);
	tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
}

ll query(ll idx, ll left, ll right, ll qleft, ll qright) {
	push(idx, left, right);
	if (right < qleft || qright < left) {
		return 0;
	}
	if (qleft <= left && right <= qright) {
		return tree[idx];
	}
	ll mid = (left + right) / 2;
	return query(idx * 2, left, mid, qleft, qright) + query(idx * 2 + 1, mid + 1, right, qleft, qright);
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	ll n, m;
	cin >> n;

	vector<int> v(n + 1);
	vector<int> arr(n + 1);


	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		arr[i] = v[i] - v[i - 1];
	}

	for (int i = 1; i <= n; i++) {
		update(1, 1, n, i, i, arr[i]);
	}

	cin >> m;

	for (int i = 1; i <= m; i++) {
		ll command;
		cin >> command;
		if (command == 1) {//update
			ll a, b;
			cin >> a >> b;
			update(1, 1, n, a, b, 1);
			update(1, 1, n, b+1, b+1, -(b-a+1));
		}
		else {//query
			ll a;
			cin >> a;
			cout << 1LL * query(1, 1, n, 1, a) << "\n";
		}
	}


	return 0;
}