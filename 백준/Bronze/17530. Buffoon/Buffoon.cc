#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;
	
	int x;
	cin >> x;
	for (int i = 0; i < n - 1; i++) {
		int y;
		cin >> y;
		if (y > x) {
			cout << "N";
			return 0;
		}
	}
	cout << "S";

	return 0;
}