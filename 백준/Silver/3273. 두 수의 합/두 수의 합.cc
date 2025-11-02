#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, x;
	cin >> n;

	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	cin >> x;


	int l = 0, r = n - 1;
	int cnt = 0;
	int sum = 0;

	while (l < r) {
		if (v[l] + v[r] == x) {
			cnt++;
			l++;
		}
		else if (v[l] + v[r] > x) {
			r--;
		}
		else {
			l++;
		}
	}

	
	cout << cnt;


	return 0;
}