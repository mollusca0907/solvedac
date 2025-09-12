#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {

		vector<vector<ll>> dp(2, vector<ll>(100'004, 0));

		int n;
		cin >> n;
		vector<vector<ll>> v(2,vector<ll>(n,0));

		for (int i = 0; i < n; i++) {
			cin >> v[0][i];
		}

		for (int i = 0; i < n; i++) {
			cin >> v[1][i];
		}

		dp[0][0] = v[0][0];
		dp[1][0] = v[1][0];
		if (n > 1) {
			dp[0][1] = dp[1][0] + v[0][1];
			dp[1][1] = dp[0][0] + v[1][1];

		}
		ll max_val = max({dp[0][0], dp[0][1], dp[1][0], dp[1][1]});

		for (int i = 2; i < n; i++) {
			dp[0][i] = v[0][i] + max({ dp[1][i - 1], dp[0][i - 2], dp[1][i - 2] });
			dp[1][i] = v[1][i] + max({ dp[0][i - 1], dp[0][i - 2], dp[1][i - 2] });
			max_val = max({ max_val, dp[0][i], dp[1][i] });
		}

		cout << max_val << "\n";

	}


	return 0;
}