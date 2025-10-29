#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {

	int n;
	cin >> n;
	int cnt_1 = 0;
	int x=0;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		x ^= p;
		if (p == 1) cnt_1++;
	}
	if (cnt_1 == n) {
		if (cnt_1 % 2 == 0) {
			cout << "koosaga";
		}
		else {
			cout << "cubelover";
		}
	}
	else {
		if (x != 0) {
			cout << "koosaga";
		}
		else {
			cout << "cubelover";
		}
	}


	return 0;
}