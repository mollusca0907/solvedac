#include <iostream>
#include <algorithm>
using namespace std;

int w[101]; //비용
int v[101]; //가치

int dp[101][10001];
// 단원수, 총 시간
int n, k;

int main() {

	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> w[i] >> v[i];
	}


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j >= w[i]) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	cout << dp[n][k];
	return 0;
}