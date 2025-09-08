#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 3;

ll dp[1001][1001];

int main() {

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		dp[i][0] = 1;
		dp[i][1] = i;
	}

	for (int i = 2; i < n; i++) {
		for (int j = 2; j <= k; j++) {
			dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % MOD;
		}
	}

	cout << (dp[n - 3][k - 1] + dp[n - 1][k]) % MOD;



	return 0;
}