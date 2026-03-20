#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {

	ll t;
	cin >> t;

	int n, m;
	
	cin >> n;
	vector<int> a(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	cin >> m;
	vector<int> b(m);

	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}

	vector<ll> asum, bsum;

	for (int i = 0; i < n; i++) {
		ll sum = 0;
		for (int j = i; j < n; j++) {
			sum += a[j];
			asum.push_back(sum);
		}
	}

	for (int i = 0; i < m; i++) {
		ll sum = 0;
		for (int j = i; j < m; j++) {
			sum += b[j];
			bsum.push_back(sum);
		}
	}

	sort(asum.begin(), asum.end());
	sort(bsum.begin(), bsum.end());

	int alen = asum.size();
	int blen = bsum.size();

	int left = 0;
	int right = blen - 1;

	ll ans = 0;

	while (left < alen && right >= 0) {
		ll tsum = asum[left] + bsum[right];
		if (tsum == t) {
			ll ta = asum[left];
			ll acnt = 0;
			while (left < alen && ta == asum[left]) {
				acnt++;
				left++;
			}

			ll tb = bsum[right];
			ll bcnt = 0;
			while (right >= 0 && tb == bsum[right]) {
				bcnt++;
				right--;
			}
		
			ans += acnt * bcnt;
		
		}
		else if (tsum < t) {
			left++;
		}
		else {
			right--;
		}
	}

	cout << ans;
	return 0;
}