#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> in;
vector<int> res;
vector<vector<int>> graph;

void top_sort() {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (in[i] == 0) {
			q.push(i);
		}
	}

	for (int i = 0; i < n; i++) {
		if (q.empty()) {
			return;
		}
		int cur = q.front();
		res[i] = cur;
		q.pop();
		
		int size = graph[cur].size();
		for (int j = 0; j < size; j++) {
			int nx = graph[cur][j];
			if (--in[nx] == 0) {
				q.push(nx);
			}
		}
	}
}


int main() {

	cin >> n >> m;

	in.assign(n + 1, 0);
	res.assign(n + 1, 0);
	graph.assign(n + 1, vector<int>(0, 0));

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		in[v]++;
	}

	top_sort();

	for (int i = 0; i < n; i++) {
		cout << res[i] << " ";
	}




	return 0;
}