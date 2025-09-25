#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct vec11 {
	int w,v,u,t,s,r,q,p,o,n,m;
};

int dW[22] = {-1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int dV[22] = {0,0,-1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int dU[22] = {0,0,0,0,-1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int dT[22] = {0,0,0,0,0,0,-1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int dS[22] = {0,0,0,0,0,0,0,0,-1,1,0,0,0,0,0,0,0,0,0,0,0,0};
int dR[22] = {0,0,0,0,0,0,0,0,0,0,-1,1,0,0,0,0,0,0,0,0,0,0};
int dQ[22] = {0,0,0,0,0,0,0,0,0,0,0,0,-1,1,0,0,0,0,0,0,0,0};
int dP[22] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,1,0,0,0,0,0,0};
int dO[22] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,1,0,0,0,0};
int dN[22] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,1,0,0};
int dM[22] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,1};

int main() {

	int w,v,u,t,s,r,q,p,o,n,m;
	cin >> m >> n >>o >> p >> q >> r >> s >> t >> u >> v >> w;

	int box[w][v][u][t][s][r][q][p][o][n][m] = {0,};

	queue<vec11> que;

	// 입력
	for (int i1 = 0; i1 < w; i1++)
	for (int i2 = 0; i2 < v; i2++)
	for (int i3 = 0; i3 < u; i3++)
	for (int i4 = 0; i4 < t; i4++)
	for (int i5 = 0; i5 < s; i5++)
	for (int i6 = 0; i6 < r; i6++)
	for (int i7 = 0; i7 < q; i7++)
	for (int i8 = 0; i8 < p; i8++)
	for (int i9 = 0; i9 < o; i9++)
	for (int i10 = 0; i10 < n; i10++)
	for (int i11 = 0; i11 < m; i11++) {
		cin >> box[i1][i2][i3][i4][i5][i6][i7][i8][i9][i10][i11];
		if (box[i1][i2][i3][i4][i5][i6][i7][i8][i9][i10][i11] == 1)
			que.push({i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11});
	}

	// BFS
	while (!que.empty()){
		vec11 cr = que.front();
		que.pop();

		for (int i = 0; i < 22; i++){
			vec11 nx = {
				cr.w + dW[i],
				cr.v + dV[i],
				cr.u + dU[i],
				cr.t + dT[i],
				cr.s + dS[i],
				cr.r + dR[i],
				cr.q + dQ[i],
				cr.p + dP[i],
				cr.o + dO[i],
				cr.n + dN[i],
				cr.m + dM[i],
			};

			if (
				0 <= nx.w && nx.w < w &&
				0 <= nx.v && nx.v < v &&
				0 <= nx.u && nx.u < u &&
				0 <= nx.t && nx.t < t &&
				0 <= nx.s && nx.s < s &&
				0 <= nx.r && nx.r < r &&
				0 <= nx.q && nx.q < q &&
				0 <= nx.p && nx.p < p &&
				0 <= nx.o && nx.o < o &&
				0 <= nx.n && nx.n < n &&
				0 <= nx.m && nx.m < m
			){
				if (box[nx.w][nx.v][nx.u][nx.t][nx.s][nx.r][nx.q][nx.p][nx.o][nx.n][nx.m] == 0){
					box[nx.w][nx.v][nx.u][nx.t][nx.s][nx.r][nx.q][nx.p][nx.o][nx.n][nx.m] =
						box[cr.w][cr.v][cr.u][cr.t][cr.s][cr.r][cr.q][cr.p][cr.o][cr.n][cr.m] + 1;
					que.push(nx);
				}
			}
		}
	}

	ll max_day = 0;

	// 결과
	for (int i1 = 0; i1 < w; i1++)
	for (int i2 = 0; i2 < v; i2++)
	for (int i3 = 0; i3 < u; i3++)
	for (int i4 = 0; i4 < t; i4++)
	for (int i5 = 0; i5 < s; i5++)
	for (int i6 = 0; i6 < r; i6++)
	for (int i7 = 0; i7 < q; i7++)
	for (int i8 = 0; i8 < p; i8++)
	for (int i9 = 0; i9 < o; i9++)
	for (int i10 = 0; i10 < n; i10++)
	for (int i11 = 0; i11 < m; i11++){
		if (box[i1][i2][i3][i4][i5][i6][i7][i8][i9][i10][i11] == 0){
			cout << -1 << endl;
			return 0;												
		}
		max_day = max(max_day, (ll)box[i1][i2][i3][i4][i5][i6][i7][i8][i9][i10][i11]);
	}

	cout << max_day-1;
	return 0;
}
