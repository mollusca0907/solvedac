#include <bits/stdc++.h>
using namespace std;
int main() {

	int n;
	cin >> n;

	if (n % 5 == 0) {
		cout << n / 5;
		return 0;
	}
	else {
		int ans = 0;
		
		while (n > 0) {
			n -= 3;
			ans += 1;
			if (n % 5 == 0) {
				ans += n / 5;
				cout << ans;
				return 0;
			}
			else if (n==1 || n==2) {
				cout << -1;
				return 0;
			}
			else if (n == 0) {
				cout << ans;
				return 0;
			}
		}

	}

	return 0;
}