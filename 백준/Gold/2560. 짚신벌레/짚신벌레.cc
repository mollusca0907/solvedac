#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {

	ll a, b, d, n;
	cin >> a >> b >> d >> n;
	vector<int> dp(n + 1, 0);

	dp[0] = 1;

	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1];
		dp[i] %= 1000;
		dp[i] += (i >= a) ? dp[i - a] : 0;
		dp[i] %= 1000;
		dp[i] -= (i >= b) ? dp[i - b] : 0;
		dp[i] += 1000;
		dp[i] %= 1000;
	}

	dp[n] -= (n >= d) ? dp[n - d] : 0;
	dp[n] += 1000;
	dp[n] %= 1000;

	cout << dp[n];


	return 0;
}