#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+9;

long long int dp[1'000'005] = { 0, 1,1,};

int main() {

	for (int i = 3; i <= 1'000'001; i++) {
		dp[i] = (dp[i - 1] % MOD + dp[i - 2] % MOD + dp[i - 3] % MOD) % MOD;
	}


	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		cout << dp[n+1] % MOD << "\n";
	}



	return 0;
}