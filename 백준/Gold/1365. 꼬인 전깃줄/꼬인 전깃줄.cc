#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	vector<int> v;
	vector<int> lis;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	lis.push_back(v[0]);

	for (int i = 0; i < n; i++) {
		if (lis.back() < v[i]) {
			lis.push_back(v[i]);
		}
		else {
			int idx = lower_bound(lis.begin(), lis.end(), v[i]) - lis.begin();
			lis[idx] = v[i];
		}
	}

	cout << n - lis.size();


	return 0;
}