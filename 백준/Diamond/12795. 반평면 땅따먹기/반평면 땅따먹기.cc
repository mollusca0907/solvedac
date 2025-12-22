#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 2e18;

struct Line {
	ll a, b;
	ll get(ll x) {
		return a * x + b;
	}
};

struct Node {
	int left, right;
	ll s, e;
	Line line;
};


struct Lichao{
	vector<Node> tree;

	void init(ll s, ll e) {
		tree.push_back({ -1,-1,s,e,{0, -inf} });
	}
	
	void update(int idx, Line v) {
		ll s = tree[idx].s;
		ll e = tree[idx].e;
		ll m = (s + e) >> 1;

		Line low = tree[idx].line;
		Line high = v;
		
		if (low.get(s) > high.get(s)) swap(low, high);
		
		if (low.get(e) <= high.get(e)) {
			tree[idx].line = high;
			return;
		}

		if (low.get(m) < high.get(m)) {
			tree[idx].line = high;
			if (tree[idx].right == -1) {
				tree[idx].right = tree.size();
				tree.push_back({ -1, -1, m + 1, e, {0, -inf} });
			}
			update(tree[idx].right, low);
		}
		else {
			tree[idx].line = low;
			if (tree[idx].left == -1) {
				tree[idx].left = tree.size();
				tree.push_back({ -1, -1, s, m, {0, -inf} });
			}
			update(tree[idx].left, high);
		}

	}

	ll query(int idx, ll x) {
		if (idx == -1) {
			return -inf;
		}
		ll s = tree[idx].s;
		ll e = tree[idx].e;
		ll m = (s + e) >> 1;

		if (x <= m) {
			return max(tree[idx].line.get(x), query(tree[idx].left, x));
		}
		else {
			return max(tree[idx].line.get(x), query(tree[idx].right, x));
		}
	}
} tree;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int q;
	cin >> q;
	
	tree.init(-2e12, 2e12);

	for (int i = 0; i < q; i++) {
		int command;
		cin >> command;

		if (command == 1) {
			ll a, b;
			cin >> a >> b;
			tree.update(0, { a,b });
		}
		else {
			ll x;
			cin >> x;
			cout << tree.query(0, x) << "\n";
		}
	}

	return 0;
}
