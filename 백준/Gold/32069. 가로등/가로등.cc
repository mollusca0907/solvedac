#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int d[] = { 1,-1 };

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll l, n, k;
	cin >> l >> n >> k;

	queue<ll> q;
	map<ll, ll> dist;

	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		dist[x] = 0;
		q.push(x);
	}

	int cnt = 1;

	while (cnt < k && !q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < 2; i++) {
			int next = cur + d[i];
			if (0 <= next && next <= l && dist.count(next) == 0) {
				dist[next] = dist[cur] + 1;
				q.push(next);
				cnt++;
			}
		}
	}
	
	vector<int> v;
	for (auto i : dist) {
		v.push_back(i.second);
	}

	sort(v.begin(), v.end());

	cnt = 0;
	for (auto i : v) {
		cout << i << "\n";
		if (++cnt == k) return 0;
	}




	return 0;
}