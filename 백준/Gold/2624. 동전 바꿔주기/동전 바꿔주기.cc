#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll>dp(10001);

int main() {

	dp[0] = 1;

	int t, k;
	cin >> t >> k;

	vector<pair<int, int>> c; //p,n;

	for (int i = 0; i < k; i++) {
		int p, n;
		cin >> p >> n;
		c.push_back({ p,n });
	}


	for (auto& [p, n] : c) {
		for (int i = t; i >= 1; i--) {
			for (int j = 1; j <= n; j++) {
				if (p * j > i) {
					continue;
				}
				dp[i] = dp[i - p * j] + dp[i];

			}
		}

	}

	cout << dp[t];


	return 0;
}