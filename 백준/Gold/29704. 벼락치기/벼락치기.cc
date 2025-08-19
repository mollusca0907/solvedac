#include <iostream>
#include <algorithm>
using namespace std;

int w[1001];
int v[1001];

int dp[1001];

int n, t;

int main() {
	
	cin >> n >> t;

	long long sum = 0;

	for (int i = 1; i <= n; i++) {
		cin >> w[i] >> v[i];
		sum += v[i];
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = t; j >= 1; j--) {
			if (j >= w[i]) {
				dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
			}
		}
	}

	cout << sum - dp[t];

	return 0;
}