#include <bits/stdc++.h>
using namespace std;
using ll = long long;

using vll = vector<ll>;
using vvll = vector<vll>;

const int MOD = 1000;

int n;

vvll mmul(const vvll& v1, const vvll& v2, int N, int M, int K) {
	vvll res(N,vll(K,0));

	for (int i = 0; i < N; i++){
		for (int j = 0; j < K; j++) {
			int val = 0;
			for (int k = 0; k < M; k++) {
				val += v1[i][k] * v2[k][j] % MOD;
			}
			res[i][j] = val % MOD;
		}
	}

	return res;

}

vvll dpow(vvll& v, ll b) {
	if (b == 1) {
		return v;
	}
	vvll x = dpow(v, b / 2);
	if (b % 2 == 1) {
		return mmul(mmul(x, x, n, n, n), v, n, n, n);
	}
	else {
		return mmul(x, x, n, n, n);
	}
}


int main() {


	ll b;
	cin >> n >> b;
	vvll v(n, vll(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v[i][j];
			v[i][j] %= MOD;

		}
	}

	vvll res = dpow(v, b);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << res[i][j] << " ";
		}
		cout << "\n";
	}



	return 0;
}