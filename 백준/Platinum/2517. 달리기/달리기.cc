#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int INF = 2e9;
ll ans = 0;

ll tree[500'000 * 4 + 16];

void update(ll left, ll right, ll idx, ll cidx, ll cval) {
	if (cidx < left || right < cidx) {
		return;
	}
	if (left == right) {
		tree[idx] = cval;
		return;
	}
	ll mid = (left + right) / 2;
	update(left, mid, idx * 2, cidx, cval);
	update(mid + 1, right, idx * 2 + 1, cidx, cval);
	tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
	return;
}

ll query(ll left, ll right, ll idx, ll st, ll ed) {
	if (ed < left || right < st) {
		return 0;
	}
	if (st <= left && right <= ed) {
		return tree[idx];
	}
	ll mid = (left + right) / 2;
	return query(left, mid, idx * 2, st, ed) + query(mid + 1, right, idx * 2 + 1, st, ed);
}

int main() {

	ll n;
	cin >> n;

	vector<pair<ll, ll>> v; //val, idx
	v.push_back({ -INF, -1 });
	for (int i = 1; i <= n; i++) {
		ll x;
		cin >> x;
		v.push_back({ x, i });
	}

	sort(v.begin() + 1, v.end());

	ll pre = INF;
	ll cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (v[i].first != pre) cnt++;
		pre = v[i].first;
		v[i].first = cnt;
	}

	sort(v.begin() + 1, v.end(), [](auto a, auto b) {
		return a.second < b.second;
		});

	
	for (int i = 1; i <= n; i++) {
		ans = 0;
		ans = query(1, n, 1, v[i].first + 1, cnt);
		update(1, n, 1, v[i].first, 1);
		cout << ans+1 << "\n";

	}


	return 0;
}