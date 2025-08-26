#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAX = 1'000'000'000;

struct Node {
	Node* left;
	Node* right;
	ll val;
	ll lazy;
	Node() {
		left = nullptr;
		right = nullptr;
		val= 0;
		lazy = 0;
	}
};

void push(Node* node, ll left, ll right) {
	if (node == nullptr || node->lazy == 0) {
		return;
	}
	
	if (node->left == nullptr) {
		node->left = new Node();
	}
	if (node->right == nullptr) {
		node->right = new Node();
	}

	ll mid = (left + right) / 2;
	node->left->lazy += node->lazy;
	node->right->lazy += node->lazy;
	
	node->left->val += (mid - left + 1) * node->lazy;
	node->right->val += (right - mid) * node->lazy;

	node->lazy = 0;
}

ll update(Node*& node, ll left, ll right, ll cleft, ll cright, ll cval) {
	if (cright < left || right < cleft) {
		return (node ? node->val : 0);
	}
	if (node == nullptr) {
		node = new Node();
	}
	if (cleft <= left && right <= cright) {
		node->val += (right - left + 1) * cval;
		node->lazy += cval;
		return node->val;
	}
	push(node, left, right);

	ll mid = (left + right) / 2;
	node->val = update(node->left, left, mid, cleft, cright, cval) + update(node->right, mid + 1, right, cleft, cright, cval);
	return node->val;
}

ll query(Node*& node, ll left, ll right, ll qleft, ll qright) {
	if (node == nullptr) {
		return 0;
	}
	if (qright < left || right < qleft) {
		return 0;
	}
	if (qleft <= left && right <= qright) {
		return node->val;
	}
	push(node, left, right);
	ll mid = (left + right) / 2;
	return query(node->left, left, mid, qleft, qright) + query(node->right, mid + 1, right, qleft, qright);
}

struct Q {
	ll i,j,k,idx;
};

Node* root;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	vector<Q> upd;
	vector<Q> qry;

	for (int i = 1; i <= n; i++) {
		ll a, b, c;
		int command;
		cin >> command >> a >> b >> c;
		if (command == 1) {
			upd.push_back({ a,b,c,i });
		}
		else {
			qry.push_back({ a,b,c,i });
		}
	}

	sort(qry.begin(), qry.end(), [](Q q1, Q q2) {
		if (q1.k == q2.k){
			return q1.idx < q2.idx;
		}
		else {
			return q1.k < q2.k;
		}
	});

	vector<pair<ll,ll>> ans;

	int cnt_upd = 0;

	for (auto q : qry) {
		while (cnt_upd < q.k) {
			auto u = upd[cnt_upd];
			cnt_upd++;
			update(root, 1, MAX, u.i, u.j, u.k);
		}
		ans.push_back({query(root, 1, MAX, q.i, q.j), q.idx});
	}

	sort(ans.begin(), ans.end(), [](auto a, auto b) {
		return a.second < b.second;
	});

	int len = ans.size();
	for (int i = 0; i < len; i++) {
		cout << ans[i].first << "\n";
	}
	return 0;
}