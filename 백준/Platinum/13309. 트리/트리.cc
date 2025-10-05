#include <bits/stdc++.h>
using namespace std;

const int MAX = 200'005;

int sz[MAX]; //i를 루트로 하는 서브트리 크기
int dep[MAX]; //i의 깊이
int par[MAX]; //i의 부모 노드
int top[MAX]; //i가 속한 체인의 최상단 정점
int in[MAX], out[MAX]; //ETT
vector<int> g[MAX]; // graph

bool seg[MAX * 4 + 16];

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

void update(int idx, int left, int right, int cidx, int cval) {
	if (cidx < left || right < cidx) {
		return;
	}
	if (left == right) {
		seg[idx] = cval;
		return;
	}
	int mid = (left + right) / 2;
	update(idx * 2, left, mid, cidx, cval);
	update(idx * 2 + 1, mid + 1, right, cidx, cval);
	seg[idx] = seg[idx * 2] && seg[idx * 2 + 1];
	return;
}

bool s_query(int idx, int left, int right, int qleft, int qright) {
	if (qright < left || right < qleft) {
		return 1;
	}
	if (qleft <= left && right <= qright) {
		return seg[idx];
	}
	int mid = (left + right) / 2;
	return s_query(idx * 2, left, mid, qleft, qright) && s_query(idx * 2 + 1, mid + 1, right, qleft, qright);
}

int query(int u, int v) {
	bool res = 1;
	while (top[u] != top[v]) {
		if (dep[top[u]] < dep[top[v]]) {
			swap(u, v);
		}
		int st = top[u];
		res = res && s_query(1, 1, n, in[st], in[u]);
		u = par[st];
	}
	if (dep[u] > dep[v]) {
		swap(u, v);
	}
	res = res && s_query(1, 1, n, in[u]+1, in[v]);
	return res;
}



int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	
	int m;
	cin >> n >> m;
	
	vector<pair<int, int>> edge(n, {0,0});

	for (int i = 1; i <= n-1; i++) {

		int u = i + 1;
		int v;
		cin >> v;
		g[u].push_back(v);
		g[v].push_back(u);
		edge[i] = { u,v };

	}

	dep[1] = 0;
	par[1] = 0;
	top[1] = 1;

	dfs1();
	dfs2();

	for (int i = 1; i <= n - 1; i++) {
		int u = edge[i].first;
		int v = edge[i].second;
		if (dep[u] < dep[v]) {
			swap(u, v);
		}
		update(1, 1, n, in[u], 1);
	}


	for (int i = 1; i <= m; i++) {
		int command, a, b;
		cin >> a >> b >> command;
		bool res = query(a, b);
		if (res) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
		if (command == 1) {
			if (res) {
				if (a != 1) update(1, 1, n, in[a], 0);
				
			}
			else {
				if (b != 1) update(1, 1, n, in[b], 0);
			}
		}
	}

	return 0;
}