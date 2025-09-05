#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;

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


Node* add(Node* cur, ll left, ll right, ll idx, ll val) {
	if (cur == NULL) cur = new Node();
	if (idx < left || right < idx) return cur;
	if (left == right) {
		Node* ans = new Node();
		ans->val = cur->val + val;
		return ans;
	}
	Node* ans = new Node();
	ll mid = (left + right) / 2;
	Node* Lnode = add(cur->left, left, mid, idx, val);
	Node* Rnode = add(cur->right, mid+1, right, idx, val);
	ans->left = Lnode;
	ans->right = Rnode;
	ans->val = (Lnode ? Lnode->val : 0) + (Rnode ? Rnode->val : 0);
	return ans;
}

ll query(Node* node, ll left, ll right, ll qleft, ll qright) {
	if (node == NULL || qright < left || right < qleft) {
		return 0;
	}
	if (qleft <= left && right <= qright) {
		return node->val;
	}
	ll mid = (left + right) / 2;
	return (node->left ? query(node->left, left, mid, qleft, qright) : 0)
		+ (node->right ? query(node->right, mid + 1, right, qleft, qright) : 0);
}


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		int n, m;
		cin >> n >> m;
		vector<pll> arr(n);
		vector<Node*> root(100'016, nullptr);

		for (int i = 0; i < n; i++) {
			cin >> arr[i].first >> arr[i].second;
		}

		sort(arr.begin(), arr.end());
		
		
		root[0] = new Node();
		int cur = 0;
		for (int i = 0; i <= 100'000; i++) {
			root[i] = i == 0 ? root[0] : root[i - 1];
			while (cur < n && arr[cur].first == i) {
				root[i] = add(root[i], 0, 100'000, arr[cur].second, 1);
				cur++;
			}
		}


		ll ans = 0;
		for (int i = 0; i < m; i++) {
			int l, r, b, t;
			cin >> l >> r >> b >> t;
			ans += query(root[r], 0, 100'000, b, t);
			ans -= l == 0 ? 0 : query(root[l - 1], 0, 100'000, b, t);
		}

		cout << ans << "\n";
	}

	return 0;
}