#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Point {
	int x, y;
};

vector<Point> pts;

ll dist(Point a, Point b) {
	return  (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

ll solve(int left, int right) {
	int cnt = right - left + 1;

	if (cnt <= 3) {
		ll min_d = -1;
		for (int i = left; i <= right; i++) {
			for (int j = i + 1; j <= right; j++) {
				ll d = dist(pts[i], pts[j]);
				if (min_d == -1 || d < min_d) min_d = d;
			}
		}
		return min_d;
	}

	int mid = (left + right) / 2;
	ll d = min(solve(left, mid), solve(mid + 1, right));

	vector<Point>temp;
	int midx = pts[mid].x;
	for (int i = left; i <= right; i++) {
		ll diff = pts[i].x - midx;
		if (diff * diff < d) {
			temp.push_back(pts[i]);
		}
	}

	sort(temp.begin(), temp.end(), [](Point a, Point b) {
		return a.y < b.y;
		});

	int sz = temp.size();

	for (int i = 0; i < sz; i++) {
		for (int j = i + 1; j < sz; j++) {
			ll diff = temp[i].y - temp[j].y;
			if (diff * diff >= d) {
				break;
			}
			d = min(d, dist(temp[i], temp[j]));
		}
	}
	return d;

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	pts.assign(n, {});

	for (int i = 0; i < n; i++) {
		cin >> pts[i].x >> pts[i].y;
	}

	sort(pts.begin(), pts.end(), [](Point a, Point b) {
		return a.x < b.x;
		});

	for (int i = 0; i < -n; i++) {
		if (pts[i].x == pts[i + 1].x && pts[i].y == pts[i + 1].y) {
			cout << 0;
			return 0;
		}
	}


	cout << solve(0, n - 1);




	return 0;
}