#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> in(100'005);
vector<ll> out(100'005);

ll seg[100'000 * 4 + 16];
ll lazy[100'000 * 4 + 16];

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
	if (lazy[idx] != -1) {
		seg[idx] = lazy[idx] * (right - left + 1);
		if (left != right) {
			lazy[idx * 2] = lazy[idx];
			lazy[idx * 2 + 1] = lazy[idx];
		}
		lazy[idx] = -1;
	}
}

void update(ll idx, ll left, ll right, ll cleft, ll cright, ll cval) {
	push(idx, left, right);
	if (cright < left || right < cleft) {
		return;
	}
	if (cleft <= left && right <= cright) {
		lazy[idx] = cval;
		push(idx, left, right);
		return;
	}
	ll mid = (left + right) / 2;
	update(idx * 2, left, mid, cleft, cright, cval);
	update(idx * 2 + 1, mid + 1, right, cleft, cright, cval);
	seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
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

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	fill(lazy, lazy + 100'000 * 4 + 16, -1);

	int n, m;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		if (x != 0) g[x].push_back(i);
	}

	dfs(1);
	
	update(1, 1, n, 1, n, 1);

	cin >> m;
	for (int i = 0; i < m; i++) {
		int command, a;
		cin >> command >> a;
		if (command == 1) {
			update(1, 1, n, in[a]+1, out[a], 1);
		}
		else if(command == 2) {
			update(1, 1, n, in[a]+1, out[a], 0);
		}
		else {
			cout << query(1, 1, n, in[a]+1, out[a]) << "\n";
		}

	}


	return 0;
}