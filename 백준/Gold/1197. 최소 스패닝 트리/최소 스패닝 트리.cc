#include <bits/stdc++.h>
using namespace std;

int parent[10016];

struct Edge {
	int u, v, w;
};

int find(int x) {
	if (parent[x] == x) {
		return x;
	}
	return parent[x] = find(parent[x]);
}

bool unite(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) {
		return false;
	}
	parent[b] = a;
	return true;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int v, e;
	cin >> v >> e;

	vector<Edge> edges(e);

	for (int i = 0; i < e; i++) {
		cin >> edges[i].u >> edges[i].v >> edges[i].w;
	}

	sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
		return a.w < b.w;
		});

	for (int i = 1; i <= v; i++) {
		parent[i] = i;
	}

	long long ans = 0;

	for (auto& edge : edges) {
		if (unite(edge.u, edge.v)) {
			ans += edge.w;
		}
	}

	cout << ans;

	return 0;
}