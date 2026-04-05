#include <bits/stdc++.h>
using namespace std;
using ld = long double;

struct Point {
    ld x, y;
};

ld dist2(Point a, Point b) {
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    vector<Point>pts(n);

    Point p = {0,0};

    for (int i = 0; i < n; i++) {
        cin >> pts[i].x >> pts[i].y;
        p.x += pts[i].x;
        p.y += pts[i].y;
    }

    p.x /= n;
    p.y /= n;

    ld ratio = 1e3;
    for (int i =0; i < 300'000; i++) {

        ld dx = 0;
        ld dy = 0;
        ld dz = 0;

        for (int j = 0; j < n; j++) {

            ld dist = sqrt(dist2(p, pts[j]));

            if (dist > 0) {
                dx += (pts[j].x - p.x) / dist;
                dy += (pts[j].y - p.y) / dist;
            }


        }

        p.x += dx * ratio;
        p.y += dy * ratio;

        ratio *= 0.9997;

    }

    ld sum = 0;
    for (int i =0 ; i < n; i++) {
        sum += sqrt(dist2(p, pts[i]));
    }

    cout << round(sum) << "\n";

    return 0;
}