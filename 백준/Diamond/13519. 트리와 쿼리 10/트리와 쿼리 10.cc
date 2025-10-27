#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX = 100'005;
const ll INF = 1e18;

struct Info {
	ll maxL;
	ll maxR;
	ll sum;
	ll ans;
};


int sz[MAX];
int dep[MAX];
int par[MAX];
int top[MAX];
int in[MAX], out[MAX];
vector<int> g[MAX];

Info base = { 0,0,0,0};
Info seg[MAX * 4 + 16];
ll lazy[MAX * 4 + 16];

int n;

void dfs1(int v = 1, int p = 0) {
	par[v] = p;
	sz[v] = 1;
	for (auto& i : g[v]) {
		if (p == i) {
			continue;
		}

		dep[i] = dep[v] + 1;
		par[i] = v;

		dfs1(i, v);

		sz[v] += sz[i];
		if (g[v][0] == p || sz[i] > sz[g[v][0]]) {
			swap(i, g[v][0]);
		}
	}
}

int cnt = 0;
void dfs2(int v = 1, int p = 0) {
	in[v] = ++cnt;
	for (auto i : g[v]) {
		if (p == i) {
			continue;
		}
		top[i] = (i == g[v][0] ? top[v] : i);
		dfs2(i, v);
	}
	out[v] = cnt;
}

Info Merge(Info L, Info R) {
	Info T;
	T.sum = L.sum + R.sum;
	T.maxL = max(L.maxL, L.sum + R.maxL);
	T.maxR = max(R.maxR, R.sum + L.maxR);
	T.ans = max({ L.ans, R.ans, L.maxR + R.maxL });
	return T;
}

void push(ll idx, ll left, ll right) {
	if (lazy[idx] != -INF) {
		seg[idx].sum = (right - left + 1) * lazy[idx];
		seg[idx].ans = seg[idx].maxL = seg[idx].maxR = max({ seg[idx].sum, lazy[idx], (ll)0 });
		if (left != right) {
			lazy[idx * 2] = lazy[idx];
			lazy[idx * 2 + 1] = lazy[idx];
		}
		lazy[idx] = -INF;
	}
}

void s_update(ll idx, ll left, ll right, ll cleft, ll cright, ll cval) {
	push(idx, left, right);
	if (cright < left || right < cleft) {
		return;
	}
	if (cleft <= left && right <= cright) {
		lazy[idx] = cval;
		push(idx, left, right);
		return;
	}
	ll mid = (left + right) / 2;
	s_update(idx * 2, left, mid, cleft, cright, cval);
	s_update(idx * 2 + 1, mid + 1, right, cleft, cright, cval);
	seg[idx] = Merge(seg[idx * 2], seg[idx * 2 + 1]);
	return;
}

Info s_query(ll idx, ll left, ll right, ll qleft, ll qright) {
	push(idx, left, right);
	if (qright < left || right < qleft) {
		return base;
	}
	if (qleft <= left && right <= qright) {
		return seg[idx];
	}
	ll mid = (left + right) / 2;
	return Merge(s_query(idx * 2, left, mid, qleft, qright), s_query(idx * 2 + 1, mid + 1, right, qleft, qright));
}

void update(int u, int v, int val) {
	while (top[u] != top[v]) {
		if (dep[top[u]] < dep[top[v]]) {
			swap(u, v);
		}
		int st = top[u];
		s_update(1, 1, n, in[st], in[u], val);
		u = par[st];
	}
	if (dep[u] > dep[v]) {
		swap(u, v);
	}
	s_update(1, 1, n, in[u], in[v], val);
}

ll query(int u, int v) {
	Info Tu = base;
	Info Tv = base;
	if (in[u] > in[v]) {
		swap(u, v);
	}
	while (top[u] != top[v]) {
		//멋대로스왑하면순서가꼬여요
		if (dep[top[u]] > dep[top[v]]) { //u체인이 더 깊으니까 이거부터할래요 
			Tu = Merge(s_query(1, 1, n, in[top[u]], in[u]), Tu); //머징
			u = par[top[u]];
		}
		else {
			Tv = Merge(s_query(1, 1, n, in[top[v]], in[v]), Tv);
			v = par[top[v]];
		}
	}
	//마지막체인도 저짓을해야해요
	if (dep[u] > dep[v]) { //작은거부터할게요
		Tu = Merge(s_query(1, 1, n, in[v], in[u]), Tu);
	}
	else {
		Tv = Merge(s_query(1, 1, n, in[u], in[v]), Tv);
	}
	swap(Tu.maxL, Tu.maxR);
	return Merge(Tu, Tv).ans;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	cin >> n;
	vector<int> weights(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> weights[i];
	}


	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dep[1] = 0;
	top[1] = 1;

	dfs1();
	dfs2();


	fill(lazy, lazy + (MAX * 4 + 16), -INF);
	for (int i = 1; i <= n; i++) {
		s_update(1, 1, n, in[i], in[i], weights[i]);
	}

	int m;
	cin >> m;
	while (m--) {
		int command;
		ll u, v, w;
		cin >> command;
		if (command == 1) {
			cin >> u >> v;
			cout << query(u, v) << "\n";
		}
		else {
			cin >> u >> v >> w;
			update(u, v, w);
		}
	}


	return 0;
}