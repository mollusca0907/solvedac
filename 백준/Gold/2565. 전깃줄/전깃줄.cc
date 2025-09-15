#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	vector<pair<int, int>> v;
	vector<int> lis;

	for (int i = 0; i < n; i++) {
		int l, r;
		cin >> l >> r;
		v.push_back({ l,r });
	}

	sort(v.begin(), v.end(), [](auto a, auto b) {
		return a.first < b.first;
		});

	lis.push_back(v[0].second);

	for (int i = 0; i < n; i++) {
		if (lis.back() < v[i].second) {
			lis.push_back(v[i].second);
		}
		else {
			int idx = lower_bound(lis.begin(), lis.end(), v[i].second) - lis.begin();
			lis[idx] = v[i].second;
		}
	}

	cout << n - lis.size();

	return 0;
}