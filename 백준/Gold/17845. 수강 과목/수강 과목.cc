#include <iostream>
#include <algorithm>
using namespace std;

int t[1001];
int v[1001];

int dp[1001][10001];
// [과목수][최대공부시간]

int n, k;

int main() {

	cin >> n >> k;

	for (int i = 1; i <= k; i++) {
		cin >> v[i] >> t[i];
	}

	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++) {

			if (j >= t[i]) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - t[i]] + v[i]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}

		}
	}

	cout << dp[k][n];

}