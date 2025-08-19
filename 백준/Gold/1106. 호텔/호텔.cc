#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int w[101];
int v[101];

vector<int> dp;

int n, k;


int main() {
	dp.assign(100'001, 0);

	cin >> k >> n;
	for (int i = 1; i <= n; i++) {
		cin >> w[i] >> v[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = w[i]; j <= 100'000; j++) {
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
		}
	}

	
	for (int i = 1; i <= 100'000; i++) {
		if (dp[i] >= k) {
			cout << i;
			return 0;
		}
	}
	


	return 0;
}