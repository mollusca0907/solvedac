#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

ll tree[500'000 * 4 + 16];
int n;

void update(ll left, ll right, ll idx, ll cidx) {
	if (cidx < left || right < cidx) {
		return;
	}
	if (left == right) {
		tree[idx]++;
		return;
	}
	ll mid = (left + right) / 2;
	update(left, mid, idx * 2, cidx);
	update(mid + 1, right, idx * 2 + 1, cidx);
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
	return query(left, mid, idx * 2, st, ed) + query(mid + 1, right, idx*2+1, st,ed);
}


int main() {

	ll ans = 0;

	cin >> n;
	vector<int> a(n + 1);
	vector<int> b(1'000'000 + 7);

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		b[x] = i;
	}

	for (int i = 1; i <= n; i++) {
		ans += query(1, n, 1, b[a[i]], n);
		update(1, n, 1, b[a[i]]);
	}

	cout << ans;

	return 0;
}

//https://foxtrotin.tistory.com/164 <-이해잘됨