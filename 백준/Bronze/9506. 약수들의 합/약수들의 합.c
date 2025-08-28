#include <stdio.h>

int main() {

	int num[100] = { 0, };

	while (1) {
		int n;
		scanf("%d", &n);
		if (n == -1) {
			break;
		}

		int cnt = 0;
		int sum = 0;
		for (int i = 1; i < n; i++) {
			if (n % i == 0) {
				num[cnt] = i;
				cnt++;
				sum += i;
			}
		}
		if (sum == n) {
			printf("%d = ", n);
			for (int i = 0; i < cnt; i++) {
				if (i != 0) {
					printf("+ ");
				}
				printf("%d ", num[i]);
			}
		}
		else {
			printf("%d is NOT perfect.", n);
		}
		printf("\n");

	}

	return 0;
}