#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {

	ll x;
	int n;
	cin >> n;
	cin >> x;
	for (int i = 1; i < n; i++) {
		int t;
		cin >> t;
		x ^= t;
	}
	if (x == 0) {
		cout << "cubelover";
	}
	else {
		cout << "koosaga";
	}

	return 0;
}