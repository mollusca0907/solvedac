#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n;
	cin >> n;
	vector<ll> v(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	vector<ll> lis;
	vector<ll> lis_idx;
	vector<ll> parent(n + 1, -1);

	for (int i = 0; i < n; i++) {

		ll idx = lower_bound(lis.begin(), lis.end(), v[i]) - lis.begin();
		if (lis.size() == idx) {
			lis_idx.push_back(i);
			lis.push_back(v[i]);
		}
		else {
			lis[idx] = v[i];
			lis_idx[idx] = i;
		}
		if (idx != 0) {
			parent[i] = lis_idx[idx - 1];
		}
	}
	vector<ll> ans;

	ll idx = lis_idx.back();
	while (idx != -1) {
		ans.push_back(v[idx]);
		idx = parent[idx];
	}
	reverse(ans.begin(), ans.end());

	ll len = ans.size();
	cout << len << "\n";
	for (int i = 0; i < len; i++) {
		cout << ans[i] << " ";
	}

	return 0;
}