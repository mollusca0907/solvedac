#include <bits/stdc++.h>
using namespace std;

const int MAX = 100'005;
const int INF = 1e9;

int sz[MAX]; //i를 루트로 하는 서브트리 크기
int dep[MAX]; //i의 깊이
int par[MAX]; //i의 부모 노드
int top[MAX]; //i가 속한 체인의 최상단 정점
int in[MAX], f[MAX]; //ETT
vector<int> g[MAX]; // graph
vector<pair<pair<int, int>, int>> edge;

int seg[MAX * 4 + 16];

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
	f[cnt] = v;
	for (auto i : g[v]) {
		if (p == i) {
			continue;
		}
		top[i] = (i == g[v][0] ? top[v] : i);
		dfs2(i, v);
	}
}

void update(int idx, int left, int right, int cidx) {
	if (cidx < left || right < cidx) {
		return;
	}
	if (left == right) {
		if (seg[idx] != INF) {
			seg[idx] = INF;
		}
		else {
			seg[idx] = cidx;
		}
		return;
	}
	int mid = (left + right) / 2;
	update(idx * 2, left, mid, cidx);
	update(idx * 2 + 1, mid + 1, right, cidx);
	seg[idx] = min(seg[idx * 2], seg[idx * 2 + 1]);
	return;
}

int s_query(int idx, int left, int right, int qleft, int qright) {
	if (qright < left || right < qleft) {
		return INF;
	}
	if (qleft <= left && right <= qright) {
		return seg[idx];
	}
	int mid = (left + right) / 2;
	return min(s_query(idx * 2, left, mid, qleft, qright), s_query(idx * 2 + 1, mid + 1, right, qleft, qright));
}

int query(int u, int v) {
	int res = INF;
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
	cin >> n;

	for (int i = 1; i <= n-1; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	top[1] = 1;
	dfs1();
	dfs2();

	for (int i = 0; i < MAX * 4 + 16; i++) {
		seg[i] = INF;
	}

	cin >> m;

	for (int i = 0; i < m; i++) {
		int command, a;
		cin >> command >> a;
		if (command == 1) {
			update(1, 1, n, in[a]);
		}
		else {
			int res = query(1, a);
			if (res == INF) {
				cout << -1 << "\n";
			}
			else {
				cout << f[res] << "\n";
			}
		}

	}

	return 0;
}