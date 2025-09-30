#include <bits/stdc++.h>
using namespace std;

int id = 1;
int p[10005];

bool finished[10005];
vector<int> v[10005];
stack<int> s;
vector<vector<int>> scc;

int dfs(int cur) {
	p[cur] = id++;
	s.push(cur);

	int parent = p[cur];

	int sz = v[cur].size();
	for (int i = 0; i < sz; i++) {
		int next = v[cur][i];

		if (p[next] == 0) {
			parent = min(parent, dfs(next));
		}
		else if (!finished[next]) {
			parent = min(parent, p[next]);
		}
	}

	if (parent == p[cur]) {
		vector<int> tmp;
		while (cur) {
			int next = s.top();
			s.pop();

			tmp.push_back(next);
			finished[next] = true;
			if (cur == next) {
				break;
			}
		}
		sort(tmp.begin(), tmp.end());
		scc.push_back(tmp);
	}
	return parent;
}


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, e;
	cin >> n >> e;

	for (int i = 0; i < e; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
	}

	for (int i = 1; i < n + 1; i++) {
		if (p[i] == 0) {
			dfs(i);
		}
	}

	sort(scc.begin(), scc.end());
	
	cout << scc.size() << "\n";
	for (int i = 0; i < scc.size(); i++) {
		for (int j = 0; j < scc[i].size(); j++) {
			cout << scc[i][j] << " ";
		}
		cout << "-1\n";
	}


	return 0;
}