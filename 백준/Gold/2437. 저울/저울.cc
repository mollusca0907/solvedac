#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	if (v[0] != 1) {
		cout << 1;
		return 0;
	}


	long long sum = 0;



	for (int i = 0; i < n-1; i++) {

		sum += v[i];
		if (sum+1 < v[i + 1]) {
			cout << sum + 1;
			return 0;
		}

	}
	sum += v[n - 1];
	cout << sum + 1;



	return 0;
}