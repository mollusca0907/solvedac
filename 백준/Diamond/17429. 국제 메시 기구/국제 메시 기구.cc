#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

const ll MAX = 500'005;
const ll MOD = (ll)1 << 32;
struct Lazy {
	ll sum = 0;
	ll mul = 1;
};

ll sz[MAX];
ll dep[MAX];
ll par[MAX];
ll top[MAX];
ll in[MAX], out[MAX];
vector<ll> g[MAX];

ll seg[MAX * 4 + 16];
Lazy lazy[MAX * 4 + 16];

ll n;

void dfs1(ll v = 1, ll p = 0) {
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

ll cnt = 0;
void dfs2(ll v = 1, ll p = 0) {
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

void push(ll idx, ll left, ll right) {
	if (lazy[idx].sum != 0 || lazy[idx].mul != 1) {
		seg[idx] = (((seg[idx] * lazy[idx].mul) % MOD) + (((right - left + 1) * lazy[idx].sum) % MOD)) % MOD;
		if (left != right) {
			
			lazy[idx * 2].mul = lazy[idx * 2].mul * lazy[idx].mul % MOD;
			lazy[idx * 2 + 1].mul = lazy[idx * 2 + 1].mul * lazy[idx].mul % MOD;

			lazy[idx * 2].sum = (lazy[idx * 2].sum * lazy[idx].mul % MOD + lazy[idx].sum) % MOD;
			lazy[idx * 2 + 1].sum = (lazy[idx * 2 + 1].sum * lazy[idx].mul % MOD + lazy[idx].sum) % MOD;
			
		}
		lazy[idx].mul = 1;
		lazy[idx].sum = 0;
	}
}

void s_mul_update(ll idx, ll left, ll right, ll cleft, ll cright, ll cval) {
	push(idx, left, right);
	if (cright < left || right < cleft) {
		return;
	}
	if (cleft <= left && right <= cright) {
		lazy[idx].mul = ((lazy[idx].mul % MOD) * (cval % MOD)) % MOD;
		lazy[idx].sum = ((lazy[idx].sum % MOD) * (cval % MOD)) % MOD;
		push(idx, left, right);
		return;
	}
	ll mid = (left + right) / 2;
	s_mul_update(idx * 2, left, mid, cleft, cright, cval);
	s_mul_update(idx * 2 + 1, mid+1, right, cleft, cright, cval);
	seg[idx] = (seg[idx * 2] + seg[idx * 2 + 1]) % MOD;
}

void s_sum_update(ll idx, ll left, ll right, ll cleft, ll cright, ll cval) {
	push(idx, left, right);
	if (cright < left || right < cleft) {
		return;
	}
	if (cleft <= left && right <= cright) {
		lazy[idx].sum = ((lazy[idx].sum % MOD) + (cval % MOD)) % MOD;
		push(idx, left, right);
		return;
	}
	ll mid = (left + right) / 2;
	s_sum_update(idx * 2, left, mid, cleft, cright, cval);
	s_sum_update(idx * 2 + 1, mid + 1, right, cleft, cright, cval);
	seg[idx] = (seg[idx * 2] + seg[idx * 2 + 1]) % MOD;
}

ll s_query(ll idx, ll left, ll right, ll qleft, ll qright) {
	push(idx, left, right);
	if (qright < left || right < qleft) {
		return 0;
	}
	if (qleft <= left && right <= qright) {
		return seg[idx] % MOD;
	}
	ll mid = (left + right) / 2;
	return (s_query(idx * 2, left, mid, qleft, qright) + s_query(idx * 2 + 1, mid + 1, right, qleft, qright))%MOD;
}

void sum_update(ll u, ll v, ll val) {
	while (top[u] != top[v]) {
		if (dep[top[u]] < dep[top[v]]) {
			swap(u, v);
		}
		ll st = top[u];
		s_sum_update(1, 1, n, in[st], in[u], val);
		u = par[st];
	}
	if (dep[u] > dep[v]) {
		swap(u, v);
	}
	s_sum_update(1, 1, n, in[u], in[v], val);
}

void mul_update(ll u, ll v, ll val) {
	while (top[u] != top[v]) {
		if (dep[top[u]] < dep[top[v]]) {
			swap(u, v);
		}
		ll st = top[u];
		s_mul_update(1, 1, n, in[st], in[u], val);
		u = par[st];
	}
	if (dep[u] > dep[v]) {
		swap(u, v);
	}
	s_mul_update(1, 1, n, in[u], in[v], val);
}


ll query(ll u, ll v) {
	ll res = 0;
	while (top[u] != top[v]) {
		if (dep[top[u]] < dep[top[v]]) {
			swap(u, v);
		}
		ll st = top[u];
		res += s_query(1, 1, n, in[st], in[u]);
		res %= MOD;
		u = par[st];
	}
	if (dep[u] > dep[v]) {
		swap(u, v);
	}
	res += s_query(1, 1, n, in[u], in[v]);
	res %= MOD;
	return res;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	ll q;
	cin >> n >> q;
	for (ll i = 1; i < n; i++) {
		ll u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs1();
	dfs2();

	while (q--) {
		ll command,x,y,v;
		cin >> command;
		switch (command) {
		case 1:
			cin >> x >> v;
			s_sum_update(1, 1, n, in[x], out[x], v);
			break;
		case 2:
			cin >> x >> y >> v;
			sum_update(x, y, v);
			break;
		case 3:
			cin >> x >> v;
			s_mul_update(1, 1, n, in[x], out[x], v);
			break;
		case 4:
			cin >> x >> y >> v;
			mul_update(x, y, v);
			break;
		case 5:
			cin >> x;
			cout << s_query(1, 1, n, in[x], out[x]) << "\n";
			break;
		case 6:
			cin >> x >> y;
			cout << query(x, y) << "\n";
			break;
		}
	}

	return 0;
}