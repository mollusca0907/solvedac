#include <bits/stdc++.h>
using namespace std;

int main() {


	int a, b, c;
	cin >> a >> b >> c;
	int k = (a / (c - b)+1);

	if (c-b<=0) {
		cout << -1;
	}
	else {
		cout << k;
	}
	

	return 0;
}