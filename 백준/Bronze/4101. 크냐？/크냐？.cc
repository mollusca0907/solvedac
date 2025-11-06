#include <bits/stdc++.h>
using namespace std;

int main() {

	while (1) {
		int a, b;
		cin >> a >> b;
		if (a == 0 && b == 0) {
			return 0;
		}
		cout << ((a > b) ? "Yes\n" : "No\n");
	}

	return 0;
}