#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1'000'007;

int main() {

	int w, h;
	int x, y;
	cin >> w >> h;
	cin >> x >> y;

	vector<vector<ll>> dp(h+1, vector<ll>(w+1, 0));

	for (int i = 1; i <= y; i++) {
		for (int j = 1; j <= x; j++) {
			if (i == 1 || j == 1) {
				dp[i][j] = 1;
				continue;
			}
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
		}
	}
	ll s2m = dp[y][x];
	
	dp.assign(h + 1, vector<ll>(w + 1, 0));
	dp[y][x] = 1;

	for (int i = y; i <= h; i++) {
		for (int j = x; j <= w; j++) {
			if (i == y || j == x) {
				dp[i][j] = 1;
				continue;
			}
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
		}
	}

	ll m2e = dp[h][w];

	cout << (s2m * m2e) % MOD;
	

	return 0;
}