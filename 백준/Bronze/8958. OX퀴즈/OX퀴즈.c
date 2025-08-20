#include <stdio.h>
#include <string.h>

int main() {

	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		char q[80];
		scanf("%s", q);
		int len = strlen(q);
		int cnt = 0;
		int c = 1;
		for (int j = 1; j <= len; j++) {
			
			if (q[j - 1] == 'O') {
				cnt += c;
				c++;
			}
			else {
				c = 1;
			}

		}
		printf("%d\n", cnt);

	}

	return 0;
}