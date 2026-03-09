#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> prime;
ll k;

void init() {
	vector<int> a(k+1, 0);

	for (int i = 2; i <= k; i++) {
		a[i] = i;
	}

	for (int i = 2; i*i <= k; i++) {
		if (a[i] == 0) continue;

		for (int j = i * i; j <= k; j += i) {
			a[j] = 0;
		}
	}

	for (int i = 2; i <= k; i++) {
		if (a[i] != 0) {
			prime.push_back(a[i]);
		}
	}

}



int main() {
	cin >> k;
	if (k < 2) {
		cout << 0;
		return 0;
	}

	init();


	int l = 0;
	int r = l;
	ll sum = prime[l];
	int cnt = 0;
	int sz = prime.size();
	while (l<=r) {
		if (sum == k) {
			cnt++;
			sum -= prime[l++];
		}
		else if (sum > k) {
			sum -= prime[l++];
		}
		else if (sum < k) {
			if (++r == sz) break;
			sum += prime[r];
		}
	}

	cout << cnt;

	return 0;
}