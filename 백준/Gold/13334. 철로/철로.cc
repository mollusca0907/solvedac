#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<pair<ll,ll>> v;

	ll n, d;
	cin >> n;
	for (ll i = 0; i < n; i++) {
		ll a, b;
		cin >> a >> b;
		if (a > b) swap(a, b);
		v.push_back({ a,b });
	}

	cin >> d;

	sort(v.begin(), v.end(), [](auto a, auto b) {
		return a.second < b.second;
		});

	priority_queue<ll, vector<ll>, greater<>> pq;
	ll mx_cnt = 0;
	for (int i = 0; i < n; i++) {
		pq.push(v[i].first);
		while (!pq.empty() && v[i].second - d > pq.top()) {
			pq.pop();
		}
		mx_cnt = max(mx_cnt, (ll)pq.size());
	}

	cout << mx_cnt;

	return 0;
}