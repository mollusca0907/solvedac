#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> vtx;
vector<int> match; //match[i] = i번째 축사에 매치된 소
vector<char> visited;

bool dfs(int u) {
	for (auto v : vtx[u]) {
		if (visited[v]) {
			continue;
		}
		visited[v] = 1;
		if (match[v] == 0 || dfs(match[v])) {
			match[v] = u;
			return true;
		}
	}
	return false;
}


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	vtx.assign(n + 1, {});
	for (int i = 1; i <= n; i++) {
		int u;
		cin >> u;
		for (int j = 0; j < u; j++) {
			int v;
			cin >> v;
			vtx[i].push_back(v);
		}
	}

	match.assign(m + 1, 0);
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		visited.assign(m + 1, 0);
		if (dfs(i)) {
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}