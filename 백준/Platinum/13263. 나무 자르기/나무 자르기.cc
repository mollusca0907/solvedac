#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;

struct Line {
	ll m, b; //기울기, y절편
	db start; //스타트포인트 (반직선형태)
};

db cross(Line& a, Line& b) { //두 직선의 교점의 x좌표를 구하는 함수
	return (db)(a.b - b.b) / (db)(b.m - a.m);
}

int main() {

	int n;
	cin >> n;
	vector<ll> va(n), vb(n), dp(n);
	for (int i = 0; i < n; i++) {
		cin >> va[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> vb[i];
	}

	vector<Line>hull; //직선을 담을 컨테이너

	for (int i = 1; i < n; i++) {

		Line l = { vb[i - 1], dp[i - 1], 0 }; //새로운 직선 정의

		while (!hull.empty()) { //가장 최근 직선과의 교점을 보고, 새로운 직선에 의해 쓸모없어지는 기존 직선을 삭제.
			l.start = cross(hull.back(), l);
			if (hull.back().start < l.start) {
				break;
			}
			hull.pop_back();
		}

		hull.push_back(l);

		ll x = va[i]; //함숫값을 구하려는 x좌표

		//이분탐색을 통해 함숫값을 구하려는 x좌표가 포함된 구간을 담당하는 직선을 찾음
		int pos = hull.size() - 1; //res
		if (x < hull.back().start) {
			int left = 0;
			int right = hull.size() - 1;
			while (left + 1 < right) {
				int mid = (left + right) / 2;
				if (x < hull[mid].start) {
					right = mid;
				}
				else {
					left = mid;
				}
			}
			pos = left;
		}

		dp[i] = hull[pos].m * x + hull[pos].b;
	}

	cout << dp[n-1];


	return 0;
}


