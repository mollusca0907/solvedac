#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 0x7FFFFFFF;

int N, M;

vector<pair<int, int>> graph[501];
vector<int> dist;
vector<int> route[501];

void daik(int start) {
	dist.assign(N + 1, INF);
	dist[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	pq.push({ 0, start });

	while (!pq.empty()) {

		auto [cur_dist, cur] = pq.top();
		pq.pop();

		if (dist[cur] < cur_dist) {
			continue;
		}

		for (auto [next, cost] : graph[cur]) {
			if (dist[next] > cur_dist + cost) {
				dist[next] = cur_dist + cost;
				route[next].clear();
				route[next].push_back(cur);
				pq.push({dist[next], next});
			}
			else if (dist[next] == cur_dist + cost) {
				route[next].push_back(cur);
			}
		}
	}
}

void reverse_track(int end) {

	queue<int> q;
	q.push(end);
	vector<bool> visited(N+1, false);
	visited[end] = true;

	while (!q.empty()) {

		int cur = q.front();
		q.pop();

		for (int from : route[cur]) {

			auto& lines = graph[from];
			lines.erase(remove_if(lines.begin(), lines.end(),
				[cur](pair<int, int>& p) {
					return p.first == cur;
				}),
				lines.end()
			);

			if (!visited[from]) {
				visited[from] = true;
				q.push(from);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	while (1) {

		cin >> N >> M;
		if (N == 0 && M == 0) {
			return 0;
		}

		for (int i = 0; i <= N; i++) {
			graph[i].clear();
			route[i].clear();
		}

		int S, D;
		cin >> S >> D;

		for (int i = 0; i < M; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			graph[u].push_back({v, w});
		}

		daik(S);
		reverse_track(D);
		daik(S);
		if (dist[D] >= INF) {
			cout << -1 << "\n";
		}
		else {
			cout << dist[D] << "\n";
		}

	}
}