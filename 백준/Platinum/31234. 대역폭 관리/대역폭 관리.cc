#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX = 100'005;
const int INF = 1e9 * 2;

int sz[MAX];
int dep[MAX];
int par[MAX];
int top[MAX];
int in[MAX], out[MAX];
vector<int> g[MAX];

ll seg[MAX * 4 + 16];
ll lazy[MAX * 4 + 16];

int n;

void dfs1(int v = 1, int p = 0) {
	par[v] = p;
	sz[v] = 1;
	for (auto& i : g[v]) {
		if (p == i) {
			continue;
		}

		dep[i] = dep[v] + 1;
		par[i] = v;

		dfs1(i, v);

		sz[v] += sz[i];
		if (g[v][0] == p || sz[i] > sz[g[v][0]]) {
			swap(i, g[v][0]);
		}
	}
}

int cnt = 0;
void dfs2(int v = 1, int p = 0) {
	in[v] = ++cnt;
	for (auto i : g[v]) {
		if (p == i) {
			continue;
		}
		top[i] = (i == g[v][0] ? top[v] : i);
		dfs2(i, v);
	}
	out[v] = cnt;
}

void push(int idx, int left, int right) {
	if (lazy[idx] != 0) {
		seg[idx] += lazy[idx];
		if (left != right) {
			lazy[idx * 2] += lazy[idx];
			lazy[idx * 2 + 1] += lazy[idx];
		}
		lazy[idx] = 0;
	}
}

void s_update(int idx, int left, int right, int cleft, int cright, int cval) {
	push(idx, left, right);
	if (cright < left || right < cleft) {
		return;
	}
	if (cleft <= left && right <= cright) {
		lazy[idx] += cval;
		push(idx, left, right);
		return;
	}
	int mid = (left + right) / 2;
	s_update(idx * 2, left, mid, cleft, cright, cval);
	s_update(idx * 2 + 1, mid + 1, right, cleft, cright, cval);
	seg[idx] = min(seg[idx * 2], seg[idx * 2 + 1]);
	return;
}

ll s_query(int idx, int left, int right, int qleft, int qright) {
	push(idx, left, right);
	if (qright < left || right < qleft) {
		return INF;
	}
	if (qleft <= left && right <= qright) {
		return seg[idx];
	}
	int mid = (left + right) / 2;
	return min(s_query(idx * 2, left, mid, qleft, qright), s_query(idx * 2 + 1, mid + 1, right, qleft, qright));
}

void update(int u, int v, int val) {
	while (top[u] != top[v]) {
		if (dep[top[u]] < dep[top[v]]) {
			swap(u, v);
		}
		int st = top[u];
		s_update(1, 1, n, in[st], in[u], val);
		u = par[st];
	}
	if (dep[u] > dep[v]) {
		swap(u, v);
	}
	s_update(1, 1, n, in[u], in[v], val);
}

ll query(int u, int v) {
	ll res = INF;
	while (top[u] != top[v]) {
		if (dep[top[u]] < dep[top[v]]) {
			swap(u, v);
		}
		int st = top[u];
		res = min(res, s_query(1, 1, n, in[st], in[u]));
		u = par[st];
	}
	if (dep[u] > dep[v]) {
		swap(u, v);
	}
	res = min(res, s_query(1, 1, n, in[u], in[v]));
	return res;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int m;


	cin >> n >> m;
	for (int i = 1; i <n; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dep[1] = 0;
	top[1] = 1;

	dfs1();
	dfs2();

	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		s_update(1, 1, n, in[i], in[i], x);
	}

	int cnt = 0;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		update(u, v, -w);
		if (query(u, v) >= 0) {
			cnt++;
		}
		else {
			break;
		}
	}

	cout << cnt;

	return 0;
}