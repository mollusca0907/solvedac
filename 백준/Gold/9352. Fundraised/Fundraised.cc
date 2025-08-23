#include <bits/stdc++.h>
using namespace std;

long long w[101];
long long v[101];

long long dp[10001];

int main() {

	int tc;
	cin >> tc;
	while (tc--) {


		int n, k;
		cin >> n >> k;
		fill(dp, dp + k + 1, 0);

		for (int i = 1; i <= n; i++) {
			cin >> v[i];
		}
		for (int i = 1; i <= n; i++) {
			cin >> w[i];
		}

		for (int i = 1; i <= n; i++) {
			for (int j = w[i]; j <= k; j++) {
				dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
			}
		}
		
		cout << dp[k] << "\n";


	}


	return 0;
}