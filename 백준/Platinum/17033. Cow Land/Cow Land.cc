#include <bits/stdc++.h>
using namespace std;

const int MAX = 200'005;

int sz[MAX]; //i를 루트로 하는 서브트리 크기
int dep[MAX]; //i의 깊이
int par[MAX]; //i의 부모 노드
int top[MAX]; //i가 속한 체인의 최상단 정점
int in[MAX], rin[MAX]; //ETT
vector<int> g[MAX]; // graph

int seg[MAX * 4 + 16];
int val[MAX];


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
	rin[cnt] = v;
	for (auto i : g[v]) {
		if (p == i) {
			continue;
		}
		top[i] = (i == g[v][0] ? top[v] : i);
		dfs2(i, v);
	}
}

void build(int idx, int left, int right) {
	if (left == right) {
		seg[idx] = val[rin[left]];
		return;
	}
	int mid = (left + right) / 2;
	build(idx * 2, left, mid);
	build(idx * 2 + 1, mid+1, right);
	seg[idx] = seg[idx * 2] ^ seg[idx * 2 + 1];
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
	seg[idx] = seg[idx * 2] ^ seg[idx * 2 + 1];
	return;
}

int s_query(int idx, int left, int right, int qleft, int qright) {
	if (qright < left || right < qleft) {
		return 0;
	}
	if (qleft <= left && right <= qright) {
		return seg[idx];
	}
	int mid = (left + right) / 2;
	return s_query(idx * 2, left, mid, qleft, qright) ^ s_query(idx * 2 + 1, mid + 1, right, qleft, qright);
}

int query(int u, int v) {
	int res = 0;
	while (top[u] != top[v]) {
		if (dep[top[u]] < dep[top[v]]) {
			swap(u, v);
		}
		int st = top[u];
		res ^= s_query(1, 1, n, in[st], in[u]);
		u = par[st];
	}
	if (dep[u] > dep[v]) {
		swap(u, v);
	}
	res ^= s_query(1, 1, n, in[u], in[v]);
	return res;
}



int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	int m;
	cin >> n >> m;


	for (int i = 1; i <= n; i++) {
		cin >> val[i];
	}
	for (int i = 1; i < n; i++) {

		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);

	}

	dep[1] = 0;
	par[1] = 0;
	top[1] = 1;

	dfs1();
	dfs2();
	
	build(1, 1, n);

	for (int i = 1; i <= m; i++) {
		int command, a, b;
		cin >> command >> a >> b;

		if (command == 1) {
			update(1, 1, n, in[a], b);
		}
		else {
			cout << query(a, b) << "\n";
		}
	}

	return 0;
}