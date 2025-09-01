#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

int n;

vector<ll> min_tree(1'000'000 * 4 + 16);

vector<ll> arr(1'000'000 + 16);

void min_update(ll idx, ll left, ll right, ll cidx) {
	if (right < cidx || cidx < left) {
		return;
	}
	if (left == right) {
		min_tree[idx] = cidx;
		return;
	}

	ll mid = (left + right) / 2;
	min_update(idx * 2, left, mid, cidx);
	min_update(idx * 2 + 1, mid + 1, right, cidx);

	min_tree[idx] = (arr[min_tree[idx * 2]] < arr[min_tree[idx * 2 + 1]]) ? min_tree[idx * 2] : min_tree[idx * 2 + 1];
	return;
}

ll min_query(ll idx, ll left, ll right, ll st, ll ed) {
	if (right < st || ed < left) {
		return -1;
	}
	if (st <= left && right <= ed) {
		return min_tree[idx];
	}
	ll mid = (left + right) / 2;
	ll lc = min_query(idx * 2, left, mid, st, ed);
	ll rc = min_query(idx * 2 + 1, mid + 1, right, st, ed);
	if (lc == -1) {
		return rc;
	}
	if (rc == -1) {
		return lc;
	}
	return (arr[lc] < arr[rc]) ? lc : rc;
}

ll solve(ll left, ll right) {

	if (right < left) {
		return 0;
	}

	ll min_idx = min_query(1, 1, n, left, right);
	ll s = arr[min_idx] * (right - left + 1);
	ll lc = solve(left, min_idx - 1);
	ll rc = solve(min_idx + 1, right);
	return max({ s, lc, rc });
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);



	cin >> n;
	if (n == 0) {
		return 0;
	}

	for (int i = 1; i <= n; i++) {
		ll x;
		cin >> x;
		arr[i] = x;
		min_update(1, 1, n, i);
	}

	cout << 1LL * solve(1, n) << "\n";

	
	return 0;
}