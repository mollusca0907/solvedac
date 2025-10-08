#include <bits/stdc++.h>
using namespace std;

const int MAX = 500'005;
const int LOG = 19;

int f[MAX][LOG]; //i번 노드에서 2^j번 이동한 후의 노드

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int m, q;
	cin >> m;

	for (int i = 1; i <= m; i++) {
		cin >> f[i][0];
	}

	for (int j = 1; j < LOG; j++) {
		for (int i = 1; i <= m; i++) {
			f[i][j] = f[ f[i][j - 1] ][j - 1];
		}
	}

	cin >> q;
	for (int i = 0; i < q; i++) {
		int n, x;
		cin >> n >> x;
		for (int j = LOG - 1; j >= 0; j--) {
			if (n >= (1 << j)) {
				n -= (1 << j);
				x = f[x][j];
			}
		}
		cout << x << "\n";
	}
	





	return 0;
}