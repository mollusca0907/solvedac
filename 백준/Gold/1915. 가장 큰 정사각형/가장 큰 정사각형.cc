#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	vector<vector<int>> v(n + 1, vector<int>(m + 1, 0));
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

	for (int i = 1; i <= n; i++) {
		string input;
		cin >> input;
		for (int j = 1; j <= m; j++) {
			v[i][j] = input[j-1] - '0';
		}
	}

	int mx = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (v[i][j]) {
				dp[i][j] = min({ dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1] }) + 1;
				mx = max(mx, dp[i][j]);
			}
		}
	}

	cout << mx * mx;

	return 0;
}