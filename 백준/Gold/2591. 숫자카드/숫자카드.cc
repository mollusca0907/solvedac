#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int dp[48] = {1,1};


int main() {

	string s;
	cin >> s;

	int len = s.length();

	vector<int> n;
	n.push_back(0);
	for (int i = 0; i < len; i++) {
		n.push_back(s[i] - '0');
	}

	if (n[1] > 3 || (n[1] == 3 && n[2] > 4)) {
		dp[2] = dp[1];
	}
	else {
		dp[2] = 2;
	}

	for (int i = 2; i <= len; i++) {
		if (n[i] == 0 && n[i - 1] == 0) {
			cout << 0;
			return 0;
		}

		if (n[i - 1] > 3 && n[i] == 0) {
			dp[i] = 0;
		}
		else if (n[i] == 0) {
			dp[i] = dp[i - 2];
		}
		else if (n[i - 1] > 3 || (n[i - 1] == 3 && n[i] > 4) || n[i - 1] == 0) {
			dp[i] = dp[i - 1];
		}
		else {
			dp[i] = dp[i - 1] + dp[i - 2];
		}


	}

	cout << dp[len];

	return 0;
}