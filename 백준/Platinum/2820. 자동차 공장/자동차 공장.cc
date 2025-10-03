#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> in(500'005);
vector<ll> out(500'005);

ll seg[500'000 * 4 + 16];
ll lazy[500'000 * 4 + 16];

vector<int> g[500'005];

int cnt = 0;

void dfs(int cur) {
	in[cur] = ++cnt;
	for (auto& next : g[cur]){
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

ll query(ll idx, ll left, ll right, ll qidx) {
	push(idx, left, right);
	if (qidx < left || right < qidx) {
		return 0;
	}
	if (left == right) {
		return seg[idx];
	}
	ll mid = (left + right) / 2;
	return query(idx * 2, left, mid, qidx) + query(idx * 2 + 1, mid + 1, right, qidx);
}

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> money(n+1, 0);

	for (int i = 1; i <= n; i++) {
		cin >> money[i];
		if (i == 1) continue;
		int x;
		cin >> x;
		g[x].push_back(i);
	}
	dfs(1);

	for (int i = 1; i <= n; i++) {
		update(1, 1, n, in[i], in[i], money[i]);
	}


	for (int i = 0; i < m; i++) {
		char command;
		int a, b;
		cin >> command;
		if (command == 'p') {
			cin >> a >> b;
			update(1, 1, n, in[a]+1, out[a], b);
		}
		else {
			cin >> a;
			cout << query(1, 1, n, in[a]) << "\n";
		}
		
	}


	return 0;
}