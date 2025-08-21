#include <stdio.h>

int main() {

	int n, m;

	scanf("%d %d", &n, &m);
	
	int arr[100] = { 0, };

	for (int i = 0; i <= n; i++) {
		arr[i] = i;
	}

	for (int x = 0; x < m; x++) {
		int i, j, temp;
		scanf("%d %d", &i, &j);
		if ((j+1 - i) % 2 == 0) {
			for (int y = 0; y <= (j - i) / 2; y++) {
				temp = arr[i + y];
				arr[i + y] = arr[j - y];
				arr[j - y] = temp;
			}
		}
		else {
			for (int y = 0; y <= (j - i) / 2 - 1; y++) {
				temp = arr[i + y];
				arr[i + y] = arr[j - y];
				arr[j - y] = temp;
			}

		}


	}

	for (int x = 1; x <= n; x++) {
		printf("%d ", arr[x]);
	}





	return 0;
}