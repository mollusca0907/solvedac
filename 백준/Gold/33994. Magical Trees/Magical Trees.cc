#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int n;
	cin >> n;
	if (n % 2 == 0) {
		cout << "No";
		return 0;
	}
	cout << "Yes\n";
	for (int i = 1; i < n; i++) {
		cout << i << " " << i + 1 << "\n";
	}
	///////////////////////////////////////////////
	for (int i = 1; i <= (n - 1) / 2; i++) {
		cout << i << " " << i + 1 << "\n";
	}
	for (int i = 1; i <= (n - 1) / 2; i++) {
		cout << i << " " << n + 1 - i << "\n";
	}
	///////////////////////////////////////////////
	for (int i = 1; i <= (n - 1) / 2; i++) {
		cout << i << " " << n + 1 - i << "\n";
	}
	for (int i = (n - 1) / 2 + 1; i < n; i++) {
		cout << i << " " << i + 1 << "\n";
	}

	return 0;
}