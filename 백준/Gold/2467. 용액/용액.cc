#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int l = 0;
	int r = n - 1;
	int resl = 1e9;
	int resr = 1e9;

	while (l < r) {
		if (abs(v[l] + v[r]) <= abs(resl + resr)) {
			resl = v[l];
			resr = v[r];
		}
		if (v[l]+v[r] > 0){ //너무 양수다
			r--;
		}
		else { //너무 음수다
			l++;
		}
	}

	cout << resl << " " << resr;

	return 0;
}