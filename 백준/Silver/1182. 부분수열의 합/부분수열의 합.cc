#include <iostream>
#include <algorithm>
using namespace std;

int n, s;
int arr[21];
int cnt = 0;

void dfs(int i, int sum) {

	if (i == n) {
		if (sum == s) {
			cnt++;
		}
		return;
	}

	dfs(i + 1, sum + arr[i]);
	dfs(i + 1, sum);

}

int main() {
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	dfs(0, 0);

	if (s == 0) {
		cnt--;
	}
	cout << cnt;
	return 0;
}