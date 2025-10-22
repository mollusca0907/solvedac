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
	dist.clear();

	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		dist[x] = 0;
		q.push(x);
	}

	int cnt = 0;

	while (cnt < k && !q.empty()) {
		int cur = q.front();
		q.pop();
		cout << dist[cur] << "\n";
		cnt++;
		for (int i = 0; i < 2; i++) {
			int next = cur + d[i];
			if (0 <= next && next <= l && dist.find(next) == dist.end()) {
				dist[next] = dist[cur] + 1;
				q.push(next);
			}
		}
	}
	return 0;
}