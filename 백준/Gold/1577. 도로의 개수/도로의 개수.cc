#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m;
	cin >> k;

	map<pair<pair<int, int>, pair<int, int>>, bool> blocked;
	for (int i = 0; i < k; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		blocked[{{ a, b }, { c, d }}] = true;
		blocked[{{ c, d }, { a, b }}] = true;
	}


	vector<vector<ll>> dp(n+1, vector<ll>(m+1, 0));

	dp[0][0] = 1;

	//for (int i = 0; i < n; i++)
	//	dp[i][0] = 1;
	//for (int i = 0; i < m; i++)
	//	dp[0][i] = 1;

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (0 < i && !blocked[{{i - 1, j}, { i,j }}]) {
				dp[i][j] += dp[i - 1][j];
			}
			if (0 < j && !blocked[{{i, j-1}, { i,j }}]) {
				dp[i][j] += dp[i][j-1];
			}
		}
	}

	cout << dp[n][m];


	return 0;
}