#include <iostream>
using namespace std;

int sum[100'002];

int main() {

	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		sum[i + 1] = num + sum[i];
	}

	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);

		printf("%d\n", sum[y] - sum[x - 1]);
	}


}