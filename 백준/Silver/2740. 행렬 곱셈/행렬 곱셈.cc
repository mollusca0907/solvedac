#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

vvi mmul(vvi& v1, vvi& v2, int N, int M, int K) {
	vvi res(N,vi(K,0));

	for (int i = 0; i < N; i++){
		for (int j = 0; j < K; j++) {
			int val = 0;
			for (int k = 0; k < M; k++) {
				val += v1[i][k] * v2[k][j];
			}
			res[i][j] = val;
		}
	}

	return res;

}


int main() {

	int n, m, k;
	cin >> n >> m;
	vvi v1(n, vi(m, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v1[i][j];
		}
	}

	cin >> m >> k;
	vvi v2(m, vi(k, 0));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < k; j++) {
			cin >> v2[i][j];
		}
	}

	vvi res = mmul(v1, v2, n, m, k);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			cout << res[i][j] << " ";
		}
		cout << "\n";
	}



	return 0;
}