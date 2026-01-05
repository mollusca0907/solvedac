#include <stdio.h>
int arr[1000000] = { 0, };

int main() {

	int n, m;

	
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	int min = arr[0];
	int max = arr[0];

	for (int i = 1; i < n; i++) {
		max = (max < arr[i]) ? arr[i] : max;
		min = (min > arr[i]) ? arr[i] : min;
	}


	printf("%d %d", min, max);


	//int basket[100] = { 0, };
	//int n, m;
	//scanf("%d %d", &n, &m);

	//for (int x = 0; x <= n; x++) {
	//	basket[x] = x;
	//}

	//for (int x = 1; x <= m; x++) {
	//	int i, j;
	//	scanf("%d %d", &i, &j);
	//	basket[i] = j;
	//	basket[j] = i;

	//}
	

	return 0;
}