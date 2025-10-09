#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Point {
	ll x;
	ll y;
};

vector<Point> dot;

int ccw(Point A, Point B, Point C) {
	ll res = (B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y);
	if (res > 0) return 1;
	if (res < 0) return -1;
	return 0;
}

ll dist(Point A, Point B) {
	return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y);
}

bool cmp(Point& A, Point& B) {
	int val = ccw(dot[0], A, B);
	if (val > 0) return true;
	if (val < 0) return false;

	return dist(dot[0], A) < dist(dot[0], B);
}

vector<Point> hull() {
	vector<Point> s;
	int sz = dot.size();
	for (int i = 0; i < sz; i++) {
		while (2 <= s.size() && ccw(s[s.size() - 2], s[s.size() - 1], dot[i]) <= 0) {
			s.pop_back();
		}
		s.push_back(dot[i]);
	}
	return s;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		dot.push_back({ x,y });
	}

	int temp = 0;
	int sz = dot.size();
	for (int i = 1; i < sz; i++) {
		if (dot[i].y < dot[temp].y || (dot[i].y == dot[temp].y) && dot[i].x < dot[temp].x) {
			temp = i;
		}
	}

	swap(dot[0], dot[temp]);

	sort(dot.begin()+1, dot.end(), cmp);

	vector<Point> res = hull();

	cout << res.size();

	return 0;
}
