#include <bits/stdc++.h>
using namespace std;

int main() {


	int n, w;
	cin >> n >> w;

	int res = 0;
	res += n * 10;
	if (n >= 3) {
		res += 20;
	}
	if (n == 5) {
		res += 50;
	}
	if (w > 1000) {
		res -= 15;
	}
	if (res < 0) {
		res = 0;
	}
	cout << res;

	

	return 0;
}