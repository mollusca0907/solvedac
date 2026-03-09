#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 2e9;

struct Node {
	int mn;
	int orv;
	int andv;
};

Node tree[500'000 * 4 + 16];
int lz[500'000 * 4 + 16];
int arr[500'005];

Node f(Node a, Node b) {
	return { min(a.mn, b.mn), a.orv | b.orv, a.andv & b.andv };
}

void push(ll idx, ll left, ll right) {
	if (!lz[idx]) return;
	tree[idx].mn += lz[idx];
	tree[idx].orv += lz[idx];
	tree[idx].andv += lz[idx];
	
	if (left != right) {
		lz[idx * 2] += lz[idx];
		lz[idx * 2 + 1] += lz[idx];
	}
	lz[idx] = 0;
	return;
}


void orquery(ll idx, ll left, ll right, ll cleft, ll cright, ll val) {
	push(idx, left, right);
	if (cright < left || right < cleft) {
		return;
	}
	if (cleft <= left && right <= cright) {
		//~tree[idx].andv & val == 0인 경우에는 or연산을 해도 변화가 없기 때문에 return
		if ((~tree[idx].andv & val) == 0) return;
		//or연산자: 0->1으로 비트를 전환한다고 생각
		//변화량이 같은 경우 (여집합의 모든 비트가 val에 의해 1이 될 준비가 됨(현재 해당 비트=0))
		if (((tree[idx].orv ^ tree[idx].andv) & val) == 0) {
			// 변화량 = val - (모든 원소들에서 공통적으로 0인 비트)
			// val과 현재값의 차이를 구간에 더함
			lz[idx] += val & ~tree[idx].orv;
			push(idx, left, right);
			return;
		}
	}
	ll mid = (left + right) / 2;
	orquery(idx * 2, left, mid, cleft, cright, val);
	orquery(idx * 2 + 1, mid + 1, right, cleft, cright, val);
	tree[idx] = f(tree[idx * 2], tree[idx * 2 + 1]);
	return;
}

void andquery(ll idx, ll left, ll right, ll cleft, ll cright, ll val) {
	push(idx, left, right);
	if (cright < left || right < cleft) {
		return;
	}
	if (cleft <= left && right <= cright) {
		//tree[idx].orv & ~val == 0인 경우에는 and연산을 해도 변화가 없기 때문에 return
		if ((tree[idx].orv & ~val) == 0) return;
		//and연산자: 1->0으로 비트를 전환한다고 생각
		//변화량이 같은 경우 //여집합의 모든 비트가 val에 의해 0이 될 준비가 됨(현재 해당 비트=1))
		if (((tree[idx].orv ^ tree[idx].andv) & ~val) == 0) {
			// 변화량 = (모든 원소들에서 공통적으로 1인 비트) - val
			// val과 현재값의 차이를 구간에 뺌
			lz[idx] -= tree[idx].andv & ~val;
			push(idx, left, right);
			return;
		}
	}
	ll mid = (left + right) / 2;
	andquery(idx * 2, left, mid, cleft, cright, val);
	andquery(idx * 2 + 1, mid + 1, right, cleft, cright, val);
	tree[idx] = f(tree[idx * 2], tree[idx * 2 + 1]);
	return;
}

int minquery(ll idx, ll left, ll right, ll qleft, ll qright) {
	push(idx, left, right);
	if (qright < left || right < qleft) {
		return INF;
	}
	if (qleft <= left && right <= qright) {
		return tree[idx].mn;
	}
	ll mid = (left + right) / 2;
	return min(minquery(idx * 2, left, mid, qleft, qright), minquery(idx * 2 + 1, mid + 1, right, qleft, qright));
}

void init(ll idx, ll left, ll right) {
	if (left == right) {
		tree[idx].mn = arr[left];
		tree[idx].andv = arr[left];
		tree[idx].orv = arr[left];
		return;
	}
	ll mid = (left + right) / 2;
	init(idx * 2, left, mid);
	init(idx * 2 + 1, mid + 1, right);
	tree[idx] = f(tree[idx * 2], tree[idx * 2 + 1]);
	return;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	
	init(1, 1, n);
	
	cin >> m;

	for (int i = 0; i < m; i++) {
		char command;
		cin >> command;
		if (command == '&') {
			int l, r, x;
			cin >> l >> r >> x;
			andquery(1, 1, n, l, r, x);
		}
		else if (command == '|') {
			int l, r, x;
			cin >> l >> r >> x;
			orquery(1, 1, n, l, r, x);
		}
		else {
			int l, r;
			cin >> l >> r;
			cout << minquery(1, 1, n, l, r) << "\n";
		}
	}



	return 0;
}