#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> visited;
queue<pair<int, int>> path;
int n;

int dx[] = { 1,2,2,1,-1,-2,-2,-1 };
int dy[] = { 2,1,-1,-2,-2,-1,1,2 };

int ucleed_dist(int x1, int y1) {
	int x2 = n / 2;
	int y2 = n / 2;
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int get_degree(int px, int py, int x, int y) {
	int cnt = 0;
	int p_visited = visited[px][py]; //이전에이미방문된상태일수도잇으니이전상태를저장해놔야함!!!!
	visited[px][py] = 1; //임시방문처리
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 < nx && nx <= n && 0 < ny && ny <= n) {
			if (visited[nx][ny] == 0) {
				cnt++;
			}
		}
	}
	visited[px][py] = p_visited;//임시방문해제
	return cnt;
}

bool huri(int& x, int& y) {
	int min_degree = 9;
	int mx = -1;
	int my = -1;

	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (0 < nx && nx <= n && 0 < ny && ny <= n) {
			if (visited[nx][ny] == 0) {
				int degree = get_degree(x, y, nx, ny);
				if (degree < min_degree) {
					min_degree = degree;
					mx = nx;
					my = ny;
				}
				else if (degree == min_degree) {
					if (ucleed_dist(nx, ny) > ucleed_dist(mx, my)) {
						mx = nx;
						my = ny;
					}
				}
			}
		}
	}
	if (mx == -1) {
		return false;
	}
	x = mx;
	y = my;
	path.push({ x,y });
	visited[x][y] = 1;
	return true;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int x, y;
	cin >> n;
	cin >> x >> y;
	
	visited.assign(n+1, vector<char>(n+1, 0));

	visited[x][y] = 1;
	path.push({ x,y });


	for (int i = 0; i < n * n -1; i++) {
		if (huri(x, y) == 0) {
			cout << "-1 -1";
			return 0;
		}
	}
	while (!path.empty()) {
		auto cur = path.front();
		path.pop();
		cout << cur.first << " " << cur.second << "\n";
	}

	return 0;
}