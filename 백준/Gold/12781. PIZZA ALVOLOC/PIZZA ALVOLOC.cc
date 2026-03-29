#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Point {
    int x, y;

};

int ccw(Point a, Point b, Point c) {
    ll res = ((a.x * b.y) + (b.x * c.y) + (c.x * a.y)) - ((b.x * a.y) + (c.x * b.y) + (a.x * c.y));
    if (res > 0) return 1;
    if (res < 0) return -1;
    return 0;
}

int main() {

    Point pts[4];

    for (int i = 0; i < 4; i++) {
        cin >> pts[i].x >> pts[i].y;
    }

    if (ccw(pts[0], pts[1], pts[2]) * ccw(pts[0], pts[1], pts[3]) < 0) {
        cout << 1;
    }
    else {
        cout << 0;
    }

	return 0;
}