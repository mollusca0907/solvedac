#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[105][105];

int main(){

	int n;
	cin >> n;

	for (int i = 1; i <= 9; i++){
		dp[1][i] = 1;
	}

	for (int i = 2; i <= n; i++){
		dp[i][0] = dp[i-1][1];
		dp[i][9] = dp[i-1][8];
		for (int j = 1; j <= 8; j++){
			dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % 1'000'000'000;
		}
	}

	ll sum = 0;
	for (int i = 0; i <= 9; i++){
		sum += dp[n][i];
		sum %= 1'000'000'000;
	}

	cout << sum % 1'000'000'000;
	


	return 0;
}