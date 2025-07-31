#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;

vector<tuple<int,int,int>> graph;
int dist[216][216];

int n, m;

int main() {

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)continue;
			dist[i][j] = INF;
		}
	}

	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		dist[u][v] = dist[v][u] = min(dist[u][v], w);
		graph.push_back({u, v, w});
	}

	for (int m = 1; m <= n; m++) {
		for (int s = 1; s <= n; s++) {
			for (int e = 1; e <= n; e++) {
				if (dist[s][m] + dist[m][e] < dist[s][e]) {
					dist[s][e] = dist[s][m] + dist[m][e];
				}
			}
		}
	}

	double ans = INF;

	for (int s = 1; s <= n; s++) {
		double max_t = 0.0;
		for (auto [u, v, w] : graph) {

			int du = dist[s][u];
			int dv = dist[s][v];

			int fast = min(du, dv);
			int late = max(du, dv);

			double t = late + max(0, w - (late - fast)) / 2.0;
			max_t = max(max_t, t);

		}
		ans = min(ans, max_t);
	}

	printf("%.1lf", ans);

	return 0;
}