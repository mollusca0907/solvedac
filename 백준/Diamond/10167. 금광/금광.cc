#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e18;

struct Info {
	ll maxL;
	ll maxR;
	ll sum;
	ll ans;
};

Info base = { -INF, -INF, 0, -INF};
Info tree[100'000 * 4 + 16];

Info Merge(Info L, Info R) {
	Info T;

	if (L.ans == -INF) {
		return R;
	}
	if (R.ans == -INF) {
		return L;
	}

	T.sum = L.sum + R.sum;

	T.maxL = max(L.maxL, L.sum + R.maxL);
	T.maxR = max(R.maxR, R.sum + L.maxR);

	T.ans = max({ L.ans, R.ans, L.maxR + R.maxL });

	return T;
}

void update(ll idx, ll left, ll right, ll cidx, ll cval) {
	if (cidx < left || right < cidx) {
		return;
	}
	if (left == right) {
		ll sum = tree[idx].sum + cval;
		tree[idx] = { sum,sum,sum,sum };
		return;
	}
	ll mid = (left + right) / 2;
	update(idx * 2, left, mid, cidx, cval);
	update(idx * 2 + 1, mid + 1, right, cidx, cval);
	tree[idx] = Merge(tree[idx * 2], tree[idx * 2 + 1]);
	return;
}

Info query(ll idx, ll left, ll right, ll qleft, ll qright) {
	if (qright < left || right < qleft) {
		return base;
	}
	if (qleft <= left && right <= qright) {
		return tree[idx];
	}
	ll mid = (left + right) / 2;
	return Merge(query(idx * 2, left, mid, qleft, qright), query(idx * 2 + 1, mid + 1, right, qleft, qright));
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	vector<pair<pair<int,int>,int>> v(n+1); //x,y,w
	for (int i = 1; i <= n; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		v[i] = { {x, y}, w };
	}

	sort(v.begin()+1, v.end(), [](auto a, auto b) {
		return a.first.second < b.first.second;
	});

	int pre = -INF;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (v[i].first.second != pre) {
			cnt++;
		}
		pre = v[i].first.second;
		v[i].first.second = cnt;
	}
	sort(v.begin()+1, v.end(), [](auto a, auto b) {
		if (a.first.first == b.first.first) {
			return a.first.second < b.first.second;
		}
		else {
			return a.first.first < b.first.first;
		}
	});

	ll ans = -INF;
	for (int i = 1; i <= n; i++) {
		if (i > 1 && v[i].first.first == v[i-1].first.first) {
			continue;
		}
		fill(tree, tree + (100'000 * 4 + 16), base);
		for (int j = i; j <= n; j++) {
			update(1, 1, n, v[j].first.second, v[j].second);
			if (j == n || v[j].first.first != v[j + 1].first.first) {
				ans = max(ans, tree[1].ans);
			}
		}
	}

	cout << ans;





	return 0;
}