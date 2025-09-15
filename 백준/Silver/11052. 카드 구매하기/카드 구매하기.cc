#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	//vector<int> v(n + 1, 0);
	vector<int> dp(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		cin >> dp[i];
	}

	//dp[1] = v[1];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			dp[i] = max(dp[i], dp[i - j] + dp[j]);
		}
	}

	cout << dp[n];


}