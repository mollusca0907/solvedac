#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node {
	Node* left;
	Node* right;

	ll val;

	Node() {
		left = NULL;
		right = NULL;
		val = 0;
	}

};

Node* root[100'016];
ll arr[100'016];

void build(Node* node, ll left, ll right) {
	if (left == right) {
		node->val = arr[left];
		return;
	}
	ll mid = (left + right) / 2;
	node->left = new Node();
	node->right = new Node();

	build(node->left, left, mid);
	build(node->right, mid+1, right);

	node->val = node->left->val + node->right->val;
}

void add(Node* prev, Node* cur, ll left, ll right, ll idx, ll val) {
	if (left == right) {
		cur->val = val;
		return;
	}
	ll mid = (left + right) / 2;
	if (idx <= mid) {
		cur->left = new Node();
		cur->right = prev->right;
		add(prev->left, cur->left, left, mid, idx, val);
	}
	else {
		cur->right = new Node();
		cur->left = prev->left;
		add(prev->right, cur->right, mid + 1, right, idx, val);
	}
	cur->val = cur->left->val + cur->right->val;
}

ll query(Node* node, ll left, ll right, ll qleft, ll qright) {
	if (qright < left || right < qleft) {
		return 0;
	}
	if (qleft <= left && right <= qright) {
		return node->val;
	}
	ll mid = (left + right) / 2;
	return query(node->left, left, mid, qleft, qright) + query(node->right, mid + 1, right, qleft, qright);
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	ll n, m;
	cin >> n;


	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	root[0] = new Node();
	build(root[0], 1, n);

	cin >> m;

	int tree = 0;
	for (int i = 0; i < m; i++) {
		int command;
		cin >> command;

		if (command == 1) {
			ll a, b;
			cin >> a >> b;
			root[tree + 1] = new Node();
			add(root[tree], root[tree + 1], 1, n, a, b);
			tree++;
		}
		else {
			ll a, b, c;
			cin >> a >> b >> c;
			cout << query(root[a], 1, n, b, c) << "\n";
		}
	}


	return 0;
}