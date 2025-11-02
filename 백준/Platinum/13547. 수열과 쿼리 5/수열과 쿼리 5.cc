#include<bits/stdc++.h>
using namespace std;
using ll = long long;


struct Query {
	int left, right;
	int n;
};

ll cnt = 0;
int n_count[1'000'005];

void add(int x) {
	if (n_count[x] == 0) {
		cnt++;
	}
	n_count[x]++;
}

void remove(int x) {
	n_count[x]--;
	if (n_count[x] == 0) {
		cnt--;
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n;
	int sqrtN = sqrt(n);
	vector<int>v(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	cin >> m;
	vector<Query> q(m);
	for (int i = 0; i < m; i++) {
		int left, right;
		cin >> left >> right;
		q[i] = { left,right,i };
	}

	sort(q.begin(), q.end(), [sqrtN](auto a, auto b) {
		if (a.left / sqrtN != b.left / sqrtN) {
			return a.left / sqrtN < b.left / sqrtN;
		}
		else {
			return a.right < b.right;
		}
		});

	vector<ll>res(m + 1);

	int l = q[0].left;
	int r = q[0].right;

	for (int i = l; i <= r; i++) {
		add(v[i]);
	}
	res[q[0].n] = cnt;

	for (int i = 1; i < m; i++) {
		while (q[i].left < l) add(v[--l]);
		while (r < q[i].right) add(v[++r]);
		while (q[i].left > l) remove(v[l++]);
		while (r > q[i].right) remove(v[r--]);
		res[q[i].n] = cnt;
	}

	for (int i = 0; i < m; i++) {
		cout << res[i] << "\n";
	}



	return 0;
}