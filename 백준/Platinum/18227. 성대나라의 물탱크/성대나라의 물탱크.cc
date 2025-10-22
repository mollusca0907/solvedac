#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX = 200'005;

vector<ll> in(MAX);
vector<ll> out(MAX);

vector<ll> depth(MAX);

ll seg[MAX * 4 + 16];

vector<int> g[MAX];

vector<char> visited(MAX, 0);

int cnt = 0;
void dfs(int cur, int dep) {
	in[cur] = ++cnt;
	depth[cur] = dep;
	visited[cur] = 1;
	for (auto& next : g[cur]) {
		if (visited[next] != 1) {
			dfs(next, dep + 1);
		}
	}
	out[cur] = cnt;
}

void update(ll idx, ll left, ll right, ll cidx, ll cval) {
	if (cidx < left || right < cidx) {
		return;
	}
	if (left == right) {
		seg[idx]+=cval;
		return;
	}
	ll mid = (left + right) / 2;
	update(idx * 2, left, mid, cidx, cval);
	update(idx * 2 + 1, mid + 1, right,cidx, cval);
	seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
	return;
}

ll query(ll idx, ll left, ll right, ll qleft, ll qright) {
	if (qright < left || right < qleft) {
		return 0;
	}
	if (qleft <= left && right <= qright) {
		return seg[idx];
	}
	ll mid = (left + right) / 2;
	return query(idx * 2, left, mid, qleft, qright) + query(idx * 2 + 1, mid + 1, right, qleft, qright);
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, r;
	cin >> n >> r;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs(r, 1);

	cin >> m;
	for (int i = 0; i < m; i++) {
		int command, a;
		cin >> command >> a;
		if (command == 1) {
			update(1, 1, n, in[a], 1);
		}
		else {
			cout << query(1, 1, n, in[a], out[a]) * depth[a] << "\n";
		}

	}


	return 0;
}