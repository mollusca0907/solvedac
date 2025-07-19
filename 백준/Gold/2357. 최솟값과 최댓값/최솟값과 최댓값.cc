#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
using ll = long long;

ll min_tree[1'000'000 * 4 + 16];
ll max_tree[1'000'000 * 4 + 16];

void min_update(ll left, ll right, ll idx, ll cvalue, ll cidx) {
	if (cidx < left || right < cidx) { //범위밖인경우 -> 암것도안하고리턴
		return;
	}
	if (left == right) { //리프노드인경우 = 트리최하단도달 -> 값저장
		min_tree[idx] = cvalue;
		return;
	}
	//분할
	ll mid = (left + right) / 2;
	min_update(left, mid, idx * 2, cvalue, cidx);
	min_update(mid+1, right, idx * 2 + 1, cvalue, cidx);
	min_tree[idx] = min(min_tree[idx * 2], min_tree[idx * 2 + 1]);
	return;
}
void max_update(ll left, ll right, ll idx, ll cvalue, ll cidx) {
	if (cidx < left || right < cidx) { //범위밖인경우 -> 암것도안하고리턴
		return;
	}
	if (left == right) { //리프노드인경우 = 트리최하단도달 -> 값저장
		max_tree[idx] = cvalue;
		return;
	}
	//분할
	ll mid = (left + right) / 2;
	max_update(left, mid, idx * 2, cvalue, cidx);
	max_update(mid + 1, right, idx * 2 + 1, cvalue, cidx);
	max_tree[idx] = max(max_tree[idx * 2], max_tree[idx * 2 + 1]);
	return;
}
ll min_query(ll left, ll right, ll idx, ll beg, ll end) { //left,right = 노드의담당범위 / beg,end = 구하고자하는범위
	if (end < left || right < beg) { //범위밖인경우 -> 0리턴
		return LLONG_MAX;
	}
	if (beg <= left && right <= end) { //left~right가 beg~end의 부분집합인경우 통째로 리턴
		return min_tree[idx];
	}
	//분할
	ll mid = (left + right) / 2;
	return min(min_query(left, mid, idx * 2, beg, end), min_query(mid + 1, right, idx * 2 + 1, beg, end));
}
ll max_query(ll left, ll right, ll idx, ll beg, ll end) { //left,right = 노드의담당범위 / beg,end = 구하고자하는범위
	if (end < left || right < beg) { //범위밖인경우 -> 0리턴
		return LLONG_MIN;
	}
	if (beg <= left && right <= end) { //left~right가 beg~end의 부분집합인경우 통째로 리턴
		return max_tree[idx];
	}
	//분할
	ll mid = (left + right) / 2;
	return max(max_query(left, mid, idx * 2, beg, end), max_query(mid + 1, right, idx * 2 + 1, beg, end));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		ll x;
		cin >> x;
		min_update(1, n, 1, x, i);
		max_update(1, n, 1, x, i);
	}

	for (int i = 0; i < m; i++) {
		ll a, b;
		cin >> a >> b;
		cout << min_query(1, n, 1, a, b) << " ";
		cout << max_query(1, n, 1, a, b) << "\n";
	}


	return 0;
}