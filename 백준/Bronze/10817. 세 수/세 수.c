#include <stdio.h>

int main() {

	int a, b, c;
	int result;
	scanf("%d %d %d", &a, &b, &c);

	if (a > b && a > c) { 
		result = (b > c) ? b : c; 
	}
	else if (b > a && b > c) {
		result = (a > c) ? a : c;
	}
	else {
		result = (a > b) ? a : b;
	}

	printf("%d", result);

	return 0;

}