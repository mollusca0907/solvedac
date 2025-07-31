#include <iostream>
using namespace std;

int main() {

	double a, b;
	cin >> a >> b;

	b = b * 2 * 3.141592;
	a *= 2;

	printf("%.6lf", a + b);

	return 0;
}