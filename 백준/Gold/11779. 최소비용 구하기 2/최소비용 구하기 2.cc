#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
const int INF = 1e9;
vector<pair<int, int> > graph[1001]; //{거리, 번호}
vector<int> dist;
int route[1001];

void daik(int start) {
	dist.assign(N + 1, INF);
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > pq;

	dist[start] = 0;
	route[start] = -1;
	pq.push({0, start});

	while (!pq.empty()) {

		auto [cur_dist, cur] = pq.top();
		pq.pop();

		if (dist[cur] < cur_dist) {
			continue;
		}

		for (auto [next, cost] : graph[cur]) {
			if (dist[next] > cur_dist + cost) {
				dist[next] = cur_dist + cost;
				route[next] = cur;
				pq.push({dist[next], next});
			}
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({ v,w });
	}
	int s, e;
	cin >> s >> e;
	daik(s);

	cout << dist[e] << "\n";

	int i = e;
	vector<int> route_v;
	for (int i = e; i != -1; i = route[i]) {
		route_v.push_back(i);
	}
	cout << route_v.size() << "\n";
	for (int i = route_v.size() - 1; i >= 0; i--) {
		cout << route_v[i] << " ";
	}

	return 0;
}