#include <bits/stdc++.h>
using namespace std;
using ld = long double;

int main(){


	ld a, b, c;
	cin >> a >> b >> c;

	ld s = (a+b+c )/ 2.0L;
	ld S = sqrt(s * (s-a) * (s-b) * (s-c));

	ld R = (a*b*c) / (4.0L * S);
	ld r = (2.0L * S) / (a + b + c);

	ld d;
	if ((a==b && b ==c) || R * (R - 2.0L*r) <= 0){
		d = 0.0L;
	} else {
		d = sqrt(R * (R - 2.0L*r));

	}

	ld k = R + r;

	cout << fixed << setprecision(12);

	cout << S << "\n";
	cout << R << "\n";
	cout << r << "\n";
	cout << d << "\n";
	cout << k << "\n";

	return 0;
}