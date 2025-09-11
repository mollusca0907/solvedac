#include <stdio.h>

int main() {
	
	int a, b;
	int min, max;
	int gcd = 0, lcm = 0;
	scanf("%d %d", &a, &b);

	max = (a > b) ? a : b;
	min = a + b - max;

	for (int i = min; i >= 1; i--) {
		if (a % i == 0 && b % i == 0) {
			gcd = i;
			break;
		}
	}
	for (int i = max; i <= a * b; i++) {
		if (i % a == 0 && i % b == 0) {
			lcm = i;
			break;
		}
	}

	printf("%d\n%d", gcd, lcm);

	return 0;

}