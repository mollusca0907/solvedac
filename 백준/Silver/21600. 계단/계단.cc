#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	vector<int> v(n + 1, 0);
	vector<int> dp(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}

	dp[1] = 1;

	for (int i = 2; i <= n; i++) {
		if (dp[i - 1] + 1 <= v[i]) {
			dp[i] = dp[i - 1] + 1;
		}
		else {
			dp[i] = v[i];
		}
	}
	
	cout << *max_element(dp.begin(), dp.end());

	return 0;
}