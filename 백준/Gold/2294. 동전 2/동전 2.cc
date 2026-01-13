#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 2e9;

int main() {

	int n, k;
	cin >> n >> k;

	vector<int> v(n + 1, 0);
	vector<int> dp(k + 1, INF);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = v[i]; j <= k; j++) {
			dp[j] = min(dp[j], dp[j - v[i]] + 1);
		}
	}

	if (dp[k] == INF) {
		cout << -1;
	}
	else {
		cout << dp[k];

	}




	return 0;
}