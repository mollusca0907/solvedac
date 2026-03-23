#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

struct Point {
    ll x, y;
};

int n;
Point p0;
vector<Point>pts;

int ccw(Point a, Point b, Point c) {
    ll res = ((a.x * b.y) + (b.x * c.y) + (c.x * a.y)) - ((b.x * a.y) + (c.x * b.y) + (a.x * c.y));
    if (res > 0) return 1;
    if (res < 0) return -1;
    return 0;
}

ll dist(Point a, Point b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool compare(Point a, Point b) {
    int sign = ccw(p0, a, b);
    if (sign != 0) {
        return sign > 0;
    }
    return dist(p0, a) < dist(p0, b);
}

vector<Point> graham() {
    vector<Point> hull;
    for (int i = 0; i < n; i++) {
        //반시계방향아니면 pop
        while (hull.size() >= 2 && ccw(hull[hull.size() - 2], hull.back(), pts[i]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(pts[i]);
    }
    return hull;
}

int main() {

    int l;
    cin >> n >> l;

    pts.assign(n, {});

    for (int i = 0; i < n; i++) {
        cin >> pts[i].x >> pts[i].y;
    }

    //1. y최소   2. x최소
    int min_idx = 0;
    for (int i = 0; i < n; i++) {
        if (pts[i].y < pts[min_idx].y || ((pts[i].y == pts[min_idx].y) && (pts[i].x < pts[min_idx].x))) {
            min_idx = i;
        }
    }

    swap(pts[0], pts[min_idx]);
    p0 = pts[0];

    sort(pts.begin() + 1, pts.end(), compare);

    vector<Point> hull = graham();

    ld sum = 0;
    int sz = hull.size();
    for (int i = 0; i < sz; i++) {
        int j = (i == sz - 1) ? 0 : i + 1;

        sum += sqrt(dist(hull[i], hull[j]));

    }

    sum += 4 * l * sqrt(2);

    cout << fixed << setprecision(6);
    cout << sum;


    return 0;
}