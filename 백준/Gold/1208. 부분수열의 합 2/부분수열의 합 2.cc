#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int>vl;
vector<int>vr;
map<ll, ll> cnt;
ll ans = 0;

int n, s;

void dfsl(int i, ll sum) {
	if (i == n / 2) {
		cnt[sum]++;
		return;
	}
	dfsl(i + 1, sum);
	dfsl(i + 1, sum + vl[i]);
}

void dfsr(int i, ll sum) {
	if (i == n - (n / 2)) {
		ans += cnt[s - sum];
		return;
	}
	dfsr(i + 1, sum);
	dfsr(i + 1, sum + vr[i]);
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;

	for (int i = 0; i < n / 2; i++) {
		int x;
		cin >> x;
		vl.push_back(x);
	}
	for (int i = 0; i < n - (n / 2); i++) {
		int x;
		cin >> x;
		vr.push_back(x);
	}

	dfsl(0, 0);
	dfsr(0, 0);

	if (!s) ans--;

	cout << ans;

	return 0;
}