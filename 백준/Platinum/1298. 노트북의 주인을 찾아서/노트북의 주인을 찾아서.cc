#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> vtx;
vector<int> match; //match[i] = i번째 노트북에 매칭된 학생
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
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		vtx[a].push_back(b);
	}

	match.assign(n + 1, 0);
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		visited.assign(n + 1, 0);
		if (dfs(i)) {
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}