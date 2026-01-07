#include <bits/stdc++.h>
using namespace std;


int main() {


	int a, b, c, d;
	cin >> a >> b >> c >> d;
	bool flag = false;
	for (int i = 0; i <= d/a; i++) {
		for (int j = 0; j <= d/b; j++) {
			for (int k = 0; k <= d/c; k++) {
				if (a * i + b * j + c * k == d) {
					cout << i << " " << j << " " << k << "\n";
					flag = true;
 				}
			}
		}
	}
	if (!flag) {
		cout << "impossible";
	}


	return 0;
} 