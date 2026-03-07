#include <bits/stdc++.h>
using namespace std;
using ld = long double;

int n;

vector<ld> a;

//이 함수는 함숫값을 반환한다.

int sgn(ld x) {
	int y = 0;
	if (x > 0) y = 1;
	if (x < 0) y = -1;
	return y;
}

ld f(ld x) {
	ld y = a[0];

	ld xx = x * x;
	for (int i = 1; i <= n; i++){
		y *= xx;
		y += a[i];
	}

	return y;
}

//이 함수는 그래프와 x축과의 교점의 x좌표 (근)을 반환한다.
ld fnd(ld left, ld right, ld diff) {
	ld mid = 0;
	//if (f(left) == 0) return left;
	//if (f(right) == 0) return right;
	while ((right - left) > diff) {
		mid = (left + right) / 2;
		if (f(mid) == 0) return mid;
		if (sgn(f(left)) * sgn(f(mid)) < 0) {
			//f(l)f(m) < 0이면 [l,m] 구간에 근 존재 --> (m,r]구간 버리기
			right = mid;
		}
		else {
			left = mid;
		}
	}

	return left;

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int k;

	cin >> n;
	a.assign(n + 1, 0);
	for (int i = 0; i < n+1; i++) {
		cin >> a[i];
	}
	cin >> k;

	//주어지는 함수는 우함수이기 때문에 [0,32]의 근만 구해도 됨.
	ld x = fnd(0, 32, 0.00001); 

	ld e = (2 * x) / k;

	ld S = 0;

	//cout << "-----------------\n";


	for (int i = 1; i <= k; i++) {
		S += abs(f((i * e) - (e / 2) -x));
		//cout << "x=" << ((i * e) - (e / 2) -x) << "\n";
		//cout << "|f(x)|=" << abs(f(((i * e) - (e / 2)) - x)) << "\n";
	}
	//cout <<"-----------------\n";


	//cout << x << "\n";
	//cout << e << "\n";
	//cout << S << "\n";
	cout << S*e << "\n";

	




	return 0;
}