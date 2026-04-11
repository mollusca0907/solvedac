#include <bits/stdc++.h>
using namespace std;

int main() {


	string s1, s2;
	cin >> s1 >> s2;
	int m = s1.size();
	int n = s2.size();

	vector<vector<int>> lcs(m + 1, vector<int>(n + 1));

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (s1[i - 1] == s2[j - 1]) {
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			}
			else {
				lcs[i][j] = max(lcs[i][j - 1], lcs[i - 1][j]);
			}
		}
	}

	string res;
	int i = m;
	int j = n;

	while (i > 0 && j > 0) {
		if (lcs[i][j] == lcs[i - 1][j]) {
			i--;
		}
		else if (lcs[i][j] == lcs[i][j - 1]) {
			j--;
		}
		else {
			res += s1[i-1];
			i--;
			j--;
		}

	}
	
	reverse(res.begin(), res.end());
	cout << lcs[m][n] << "\n";
	cout << res;

	return 0;
}