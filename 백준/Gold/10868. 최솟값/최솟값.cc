#include <bits/stdc++.h>
using namespace std;

const int MAX = 100005;

int arr[MAX];
int st[MAX][18];
int lt[MAX];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;


	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	lt[1] = 0;
	for (int i = 2; i <= n; i++) {
		lt[i] = lt[i / 2] + 1;
	}

	for (int i = 1; i <= n; i++) {
		st[i][0] = arr[i];
	}

	for (int k = 1; (1 << k) <= n; k++) {
		for (int i = 1; (i + (1 << k) - 1) <= n; i++) {
			st[i][k] = min(st[i][k - 1], st[i + (1 << (k - 1))][k - 1]);
		}
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		if (a > b) swap(a, b);

		int len = b - a + 1;
		int k = lt[len];
		int ans = min(st[a][k], st[b - (1 << k) + 1][k]);
		cout << ans << "\n";


	}



	return 0;
}