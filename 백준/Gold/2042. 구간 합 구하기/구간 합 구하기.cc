#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

ll tree[1'000'000 * 4 + 16];

void update(ll left, ll right, ll idx, ll cvalue, ll cidx) {
	if (cidx < left || right < cidx) { //범위밖인경우 -> 암것도안하고리턴
		return;
	}
	if (left == right) { //리프노드인경우 = 트리최하단도달 -> 값저장
		tree[idx] = cvalue;
		return;
	}
	//분할
	ll mid = (left + right) / 2;
	update(left, mid, idx * 2, cvalue, cidx);
	update(mid+1, right, idx * 2 + 1, cvalue, cidx);
	tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
	return;
}

ll query(ll left, ll right, ll idx, ll beg, ll end) { //left,right = 노드의담당범위 / beg,end = 구하고자하는범위
	if (end < left || right < beg) { //범위밖인경우 -> 0리턴
		return 0;
	}
	if (beg <= left && right <= end) { //left~right가 beg~end의 부분집합인경우 통째로 리턴
		return tree[idx];
	}
	//분할
	ll mid = (left + right) / 2;
	return query(left, mid, idx * 2, beg, end) + query(mid + 1, right, idx * 2 + 1, beg, end);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		ll x;
		cin >> x;
		update(1, n, 1, x, i);
	}
	for (int i = 0; i < m + k; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			update(1, n, 1, c, b);
		}
		else {
			cout << 1LL * query(1, n, 1, b, c) << "\n";
		}
	}
	return 0;
}