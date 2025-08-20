#include <bits/stdc++.h>
using namespace std;

int parent[1'000'000];

int find(int x) { //find root
	if (parent[x] != x) {
		parent[x] = find(parent[x]);
	}
	return parent[x];
}

void unite(int x, int y) { 
	x = find(x);
	y = find(y);
	if (x != y) {
		parent[y] = x;
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int connect;
			cin >> connect;
			if (connect == 1) {
				unite(i, j);
			}
		}
	}
	vector<int> plan(m);
	for (int i = 0; i < m; i++) {
		cin >> plan[i];
	}

	int root = find(plan[0]);
	bool ok = true;
	for (int i = 0; i < m; i++) {
		if (find(plan[i]) != root) {
			ok = false;
			break;
		}
	}
	if (ok) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}


	return 0;
}