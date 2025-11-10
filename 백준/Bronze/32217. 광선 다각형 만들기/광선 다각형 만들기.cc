#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;
	int res=0;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		res += x * 2;
	}

	res = (n - 1) * 180 - res;

	cout << res;

	return 0;
}