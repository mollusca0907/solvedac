#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX = 100'005;

int sz[MAX];
int dep[MAX];
int par[MAX];
int top[MAX];
int in[MAX], out[MAX];
vector<int> g[MAX];

ll seg[MAX * 4 + 16];

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

void s_update(int idx, int left, int right, int cidx, int cval) {
	if (cidx < left || right < cidx) {
		return;
	}
	if (left == right) {
		seg[idx] = cval;
		return;
	}
	int mid = (left + right) / 2;
	s_update(idx * 2, left, mid, cidx, cval);
	s_update(idx * 2 + 1, mid + 1, right, cidx, cval);
	seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
	return;
}

ll s_query(int idx, int left, int right, int qleft, int qright) {
	if (qright < left || right < qleft) {
		return 0;
	}
	if (qleft <= left && right <= qright) {
		return seg[idx];
	}
	int mid = (left + right) / 2;
	return s_query(idx * 2, left, mid, qleft, qright) + s_query(idx * 2 + 1, mid + 1, right, qleft, qright);
}

ll query(int u, int v) {
	ll res = 0;
	while (top[u] != top[v]) {
		if (dep[top[u]] < dep[top[v]]) {
			swap(u, v);
		}
		int st = top[u];
		res += s_query(1, 1, n, in[st], in[u]);
		u = par[st];
	}
	if (dep[u] > dep[v]) {
		swap(u, v);
	}
	res += s_query(1, 1, n, in[u]+1, in[v]);
	return res;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int m;


	cin >> n;
	for (int i = 2; i <= n; i++) {
		int p;
		cin >> p;
		g[i].push_back(p);
		g[p].push_back(i);
	}

	dep[1] = 0;
	top[1] = 1;

	dfs1();
	dfs2();

	cin >> m;

	for (int i = 1; i <= n; i++) {
		s_update(1, 1, n, i, 1);
	}


	while (m--) {
		int command;
		cin >> command;
		if (command == 1) {
			int u, v;
			cin >> u >> v;
			cout << query(u, v)<<"\n";
		}
		else {
			int u;
			cin >> u;
			s_update(1, 1, n, in[u], 0);
		}


	}
	return 0;
}