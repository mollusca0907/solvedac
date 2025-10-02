#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> lis;

int main() {

	int n;
	cin >> n;

	vector<int> v;
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

	cout << lis.size();
	return 0;
}