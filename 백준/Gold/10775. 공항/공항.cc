#include <bits/stdc++.h>
using namespace std;

vector<int> par;

int find(int i) {
	if (par[i] == i) {
		return i;
	}
	par[i] = find(par[i]);
	return par[i];
}

void uni(int i, int j) {
	int pi = find(i);
	int pj = find(j);
	if (pi != pj) {
		par[pj] = pi;
	}
}


int main() {

	int g, p;
	cin >> g >> p;
	par.assign(g+1, 0);
	for (int i = 0; i <= g; i++) {
		par[i] = i;
	}

	int cnt = 0;

	for (int i = 0; i < p; i++) {
		int cur;
		cin >> cur;
		int pcur = find(cur);
		if (pcur == 0) {
			break;
		}
		uni(pcur-1, pcur);

		cnt++;
	}

	cout << cnt;


	return 0;
}