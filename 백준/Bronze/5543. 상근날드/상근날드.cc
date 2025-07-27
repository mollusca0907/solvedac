#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int a, b, c;
	cin >> a >> b >> c;
	int d, e;
	cin >> d >> e;

	cout << min(a,min(b,c)) + min(d,e) - 50;


	return 0;
}