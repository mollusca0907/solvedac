#include <bits/stdc++.h>
using namespace std;

int ans = 0;
int mx[1005];

int main() {

	int n;
	cin >> n;
	vector<int>v(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}

	for (int i = 1; i <= n; i++) {
		mx[i] = v[i]; // 일단 기본적으로v[i]를 가져야 함
		for (int j = 1; j < i; j++) { //i 미만의 인덱스 j에 대해 반복
			if (v[j] < v[i]) { //j번째 수가 i번째 수보다 작다면 (= v[i]가 v[j] 대비 증가한다면)
				mx[i] = max(mx[i], mx[j] + v[i]); //j번째 수 까지의 max + i번째 수  vs i번쨰 수 까지의 max 중 큰 값
			}
		}
	}
	
	for (int i = 1; i <= n; i++) ans = max(mx[i], ans);
	
	cout << ans;

	return 0;
}