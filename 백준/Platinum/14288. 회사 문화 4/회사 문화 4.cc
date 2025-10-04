#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> in(100'005);
vector<ll> out(100'005);

ll seg[100'000 * 4 + 16];
ll seg1[100'000 * 4 + 16];
ll lazy[100'000 * 4 + 16];
ll lazy1[100'000 * 4 + 16];

vector<int> g[100'005];

int cnt = 0;

void dfs(int cur) {
	in[cur] = ++cnt;
	for (auto& next : g[cur]) {
		dfs(next);
	}
	out[cur] = cnt;
}

void push(ll idx, ll left, ll right) {
	if (lazy[idx] != 0) {
		seg[idx] += lazy[idx] * (right - left + 1);
		if (left != right) {
			lazy[idx * 2] += lazy[idx];
			lazy[idx * 2 + 1] += lazy[idx];
		}
		lazy[idx] = 0;
	}
}
void push1(ll idx, ll left, ll right) {
	if (lazy1[idx] != 0) {
		seg1[idx] += lazy1[idx] * (right - left + 1);
		if (left != right) {
			lazy1[idx * 2] += lazy1[idx];
			lazy1[idx * 2 + 1] += lazy1[idx];
		}
		lazy1[idx] = 0;
	}
}

void update(ll idx, ll left, ll right, ll cleft, ll cright, ll cval) {
	push(idx, left, right);
	if (cright < left || right < cleft) {
		return;
	}
	if (cleft <= left && right <= cright) {
		lazy[idx] += cval;
		push(idx, left, right);
		return;
	}
	ll mid = (left + right) / 2;
	update(idx * 2, left, mid, cleft, cright, cval);
	update(idx * 2 + 1, mid + 1, right, cleft, cright, cval);
	seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
	return;
}

void update1(ll idx, ll left, ll right, ll cleft, ll cright, ll cval) {
	push1(idx, left, right);
	if (cright < left || right < cleft) {
		return;
	}
	if (cleft <= left && right <= cright) {
		lazy1[idx] += cval;
		push1(idx, left, right);
		return;
	}
	ll mid = (left + right) / 2;
	update1(idx * 2, left, mid, cleft, cright, cval);
	update1(idx * 2 + 1, mid + 1, right, cleft, cright, cval);
	seg1[idx] = seg1[idx * 2] + seg1[idx * 2 + 1];
	return;
}


ll query(ll idx, ll left, ll right, ll qleft, ll qright) {
	push(idx, left, right);
	if (qright < left || right < qleft) {
		return 0;
	}
	if (qleft <= left && right <= qright) {
		return seg[idx];
	}
	ll mid = (left + right) / 2;
	return query(idx * 2, left, mid, qleft, qright) + query(idx * 2 + 1, mid + 1, right, qleft, qright);
}
ll query1(ll idx, ll left, ll right, ll qleft, ll qright) {
	push1(idx, left, right);
	if (qright < left || right < qleft) {
		return 0;
	}
	if (qleft <= left && right <= qright) {
		return seg1[idx];
	}
	ll mid = (left + right) / 2;
	return query1(idx * 2, left, mid, qleft, qright) + query1(idx * 2 + 1, mid + 1, right, qleft, qright);
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		if (x != -1) g[x].push_back(i);
	}

	dfs(1);

	bool dir = 1;

	for (int i = 0; i < m; i++) {
		int command, a, b;
		cin >> command;
		if (command == 1) {
			cin >> a >> b;
			if (dir) {
				update(1, 1, n, in[a], out[a], b);
			}
			else {
				update1(1, 1, n, in[a], in[a], b);
			}
		}
		else if (command == 2) {
			cin >> a;
			cout << query(1, 1, n, in[a], in[a]) + query1(1, 1, n, in[a], out[a]) << "\n";
		}
		else {
			dir ^= 1;
		}

	}


	return 0;
}