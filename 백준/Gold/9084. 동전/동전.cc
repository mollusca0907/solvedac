#include <iostream>
#include <algorithm>
using namespace std;

int dp[10016] = { 1, };
int coin[10001];

int main() {
	int tc;
	cin >> tc;
	while (tc--) {

		for (int i = 0; i < 10016; i++) {
			dp[i] = 0;
		}
		dp[0] = 1;

		int n, m;
		cin >> n;

		for (int i = 1; i <= n; i++) {
			cin >> coin[i];
		}

		cin >> m;

		for (int i = 1; i <= n; i++) {
			for (int j = coin[i]; j <= m; j++) {
				dp[j] = dp[j] + dp[j - coin[i]];
			}
		}

		cout << dp[m] << "\n";

	}

	return 0;
}