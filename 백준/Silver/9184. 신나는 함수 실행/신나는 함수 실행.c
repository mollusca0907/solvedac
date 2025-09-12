#include <stdio.h>

int dp[105][105][105];


int w(int a, int b, int c);


int main() {

	while (1) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (a == -1 && b == -1 && c == -1) {
			break;
		}
		printf("w(%d, %d, %d) = %d\n",a, b, c, w(a, b, c));
	}

	return 0;
}

int w(int a, int b, int c) {

	if (a <= 0 || b <= 0 || c <= 0) {
		return 1;
	}

	if (a > 20 || b > 20 || c > 20) {
		if (!dp[20][20][20]) {
			dp[20][20][20] = w(20, 20, 20);
		}
		return dp[20][20][20];
	}

	if (a < b && b < c) {

		if (!dp[a][b][c - 1]) {
			dp[a][b][c - 1] = w(a, b, c - 1);
		}
		if (!dp[a][b - 1][c - 1]) {
			dp[a][b - 1][c - 1] = w(a, b - 1, c - 1);
		}
		if (!dp[a][b - 1][c]) {
			dp[a][b - 1][c] = w(a, b - 1, c);
		}
		return dp[a][b][c - 1] + dp[a][b - 1][c - 1] - dp[a][b - 1][c];
	}

	if (!dp[a - 1][b][c]) {
		dp[a - 1][b][c] = w(a - 1, b, c);
	}
	if (!dp[a - 1][b - 1][c]) {
		dp[a - 1][b - 1][c] = w(a - 1, b - 1, c);
	}
	if (!dp[a - 1][b][c - 1]) {
		dp[a - 1][b][c - 1] = w(a - 1, b, c - 1);
	}
	if (!dp[a - 1][b - 1][c - 1]) {
		dp[a - 1][b - 1][c - 1] = w(a - 1, b - 1, c - 1);
	}
	return dp[a - 1][b][c] + dp[a - 1][b - 1][c] + dp[a - 1][b][c - 1] - dp[a - 1][b - 1][c - 1];

}