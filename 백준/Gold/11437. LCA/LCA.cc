#include <bits/stdc++.h>
using namespace std;

const int MAX = 50'005;

vector<int> g[MAX];

int par[MAX];
int dep[MAX];

void dfs(int cur = 1, int p = 0) {
	par[cur] = p;
	for (auto next : g[cur]) {
		if (next == p) continue;
		dep[next] = dep[cur] + 1;
		dfs(next, cur);
	}
}

int lca(int a, int b) {
	while (dep[a] > dep[b]) a = par[a];
	while (dep[b] > dep[a]) b = par[b];

	while (a != b) {
		a = par[a];
		b = par[b];
	}

	return a;
}

int main() {

	int n, m;
	cin >> n;

	for (int i = 0; i < n-1; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dep[1] = 0;

	dfs();

	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << lca(a, b) << "\n";
	}


	return 0;
}