#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, a, b;
	cin >> n;
	cin >> a >> b;

	cout << min(n, a / 2 + b);

	return 0;
}