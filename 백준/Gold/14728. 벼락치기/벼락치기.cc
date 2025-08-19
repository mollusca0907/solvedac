#include <iostream>
#include <algorithm>
using namespace std;

int w[101];
int v[101];

int dp[10001];

int n, k;


int main() {

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> w[i] >> v[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = k; j >= 1; j--) {
			if (j >= w[i]) {
				dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
			}
		}
	}


	cout << dp[k];


	return 0;
}