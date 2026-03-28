#include <bits/stdc++.h>
using namespace std;

int dx[] = { -1,0,1,-1,1,-1,0,1 };
int dy[] = { 1,1,1,0,0,-1,-1,-1 };
int m, n;//행,열

vector<vector<int>> g;//y,x
vector<vector<bool>> visited;//y,x


void dfs(int x, int y) {
	visited[y][x] = true;
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < n && 0 <= ny && ny < m) {
			if (visited[ny][nx] || g[ny][nx] == 0) continue;
			dfs(nx, ny);

		}
	}
}

int main() {

	cin >> m >> n;

	g.assign(m, vector<int>(n,0));
	visited.assign(m, vector<bool>(n, false));

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			char x;
			cin >> x;
			if (x == '.') {
				g[i][j] = 0;
			}
			else {
				g[i][j] = 1;
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j] && g[i][j] == 1) {
				dfs(j, i);
				cnt++;
			}
		}
	}

	cout << cnt;


	

	return 0;
}