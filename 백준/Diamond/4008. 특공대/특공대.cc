#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;

const int MAX = 1'000'005;

struct Line {
	ll m, b; //기울기, y절편
	db start; //스타트포인트 (반직선형태)
};

ll a, b, c;
vector<ll>s(MAX), dp(MAX);
vector<Line>hull;

db cross(Line& a, Line& b) { //두 직선의 교점의 x좌표를 구하는 함수
	return (db)(a.b - b.b) / (db)(b.m - a.m);
}

ll constant(ll i) {
	return a * s[i] *s[i] + b * s[i]+ c;
}

ll m(ll j) {
	return 1LL * -2 * a * s[j];
}

ll k(ll j) {
	return (1LL * a * s[j] * s[j]) - (1LL * b * s[j]) + (1LL * dp[j]);
}


int main() {

	int n;
	cin >> n;
	
	cin >> a >> b >> c;
	for (int i = 1; i <= n; i++) {
		ll x;
		cin >> x;
		s[i] = s[i - 1] + x;
	}

	int idx = 0;

	for (int i = 1; i <= n; i++) {
		dp[i] = constant(i); //상수항
		
		if (!hull.empty()) {
			while (idx + 1 < hull.size() && hull[idx + 1].start < s[i]) {
				idx++;
			}
			dp[i] = max(dp[i], hull[idx].m * s[i] + hull[idx].b + constant(i));
		}

		Line l = { m(i), k(i), 0};

		while (!hull.empty()) {
			l.start = cross(hull.back(), l);
			if (hull.back().start < l.start) {
				break;
			}
			hull.pop_back();
		}
		hull.push_back(l);
	}

	cout << dp[n];

	return 0;
}


