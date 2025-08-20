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

	for (int i = 0; i < m; i++) {
		int command, a, b;
		cin >> command >> a >> b;
		if (command == 0) {
			unite(a, b);
		}
		else {
			if (find(a) == find(b)) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
	}


	return 0;
}