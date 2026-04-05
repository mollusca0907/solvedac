#include <bits/stdc++.h>
using namespace std;
using ld = long double;

struct Point {
    ld x, y, z;
};

ld dist3(Point a, Point b) {
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) + (a.z-b.z)*(a.z-b.z);
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n=3;

    vector<Point>pts(n);

    Point p = {0,0,0};

    for (int i = 0; i < n; i++) {
        cin >> pts[i].x >> pts[i].y >> pts[i].z;
        p.x += pts[i].x;
        p.y += pts[i].y;
        p.z += pts[i].z;
    }

    p.x /= n;
    p.y /= n;
    p.z /= n;

    ld ratio = 1e7;
    for (int i =0; i < 300'000; i++) {

        ld dx = 0;
        ld dy = 0;
        ld dz = 0;

        for (int j = 0; j < n; j++) {

            ld dist = sqrt(dist3(p, pts[j]));

            if (dist > 0) {
                dx += (pts[j].x - p.x) / dist;
                dy += (pts[j].y - p.y) / dist;
                dz += (pts[j].z - p.z) / dist;
            }


        }

        p.x += dx * ratio;
        p.y += dy * ratio;
        p.z += dz * ratio;

        ratio *= 0.9997;

    }

    cout << fixed << setprecision(5) << sqrt(dist3(p, pts[0])) + sqrt(dist3(p, pts[1])) + sqrt(dist3(p, pts[2]))  << "\n";

    return 0;
}