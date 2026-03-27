#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int temp[1025][1025];
int ps[1025][1025];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> temp[i][j];
			ps[i][j] = ps[i][j - 1] + temp[i][j];
		}
	}

	while (m--) {
		int command;
		cin >> command;
		
		if (command == 1) {
			int x1, x2, y1, y2;
			ll ans = 0;
			cin >> y1 >> x1 >> y2 >> x2;
			for (int i = y1; i <= y2; i++) {
				ans += ps[i][x2] - ps[i][x1-1];
			}
			cout << ans << "\n";
		}
		else {
			int x, y, c;
			cin >> y >> x >> c;
			c = c - (ps[y][x] - ps[y][x - 1]);
			for (int i = x; i <= n; i++){
				ps[y][i] += c;
			}
		}
	}

	return 0;
}