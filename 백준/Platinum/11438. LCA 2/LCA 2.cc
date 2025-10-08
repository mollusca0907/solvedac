#include <bits/stdc++.h>
using namespace std;

const int MAX = 100'005;
const int LOG = 17;

vector<int> g[MAX];
int par[MAX][LOG];
int dep[MAX];

void dfs(int cur = 1, int p = 0) {
	par[cur][0] = p;
	for (auto next : g[cur]) {
		if (next == p) continue;
		dep[next] = dep[cur] + 1;
		dfs(next, cur);
	}
}

int lca(int u, int v) {

	if (dep[u] < dep[v]) swap(u, v);

	int diff = dep[u] - dep[v];

	for (int i = 0; diff != 0; i++) {
		if (diff&1) {
			u = par[u][i];
		}
		diff >>= 1;
	}

	if (u == v) {
		return u;
	}

	for (int i = LOG - 1; i >= 0; i--) {
		if (par[u][i] != par[v][i]) {
			u = par[u][i];
			v = par[v][i];
		}
	}


	return par[u][0];

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, q;
	cin >> n;

	for (int i = 0; i < n-1; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs();

	for (int j = 1; j < LOG; j++) {
		for (int i = 1;i <= n; i++) {
			par[i][j] = par[par[i][j - 1]][j - 1];
		}
	}

	cin >> q;

	while (q--) {
		int u, v;
		cin >> u >> v;
		cout << lca(u, v) << "\n";
	}

	return 0;
}