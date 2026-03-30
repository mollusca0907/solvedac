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

int f(Point a, Point b, Point c, Point d) {
    int res1 = ccw(a, b, c) * ccw(a,b,d);
    int res2 = ccw(c,d,a) * ccw(c,d,b);

    if (res1 == 0 && res2 == 0) {
        if (max(a.x,b.x) < min(c.x,d.x) || max(c.x,d.x) < min(a.x,b.x)) return 0;
        if (max(a.y,b.y) < min(c.y,d.y) || max(c.y,d.y) < min(a.y,b.y)) return 0;
        return 1;
    }

    return res1 <= 0 && res2 <= 0;

}

int main() {

    int t;
    cin >> t;
    while (t--) {

        Point pts[4];

        Point line[2];

        cin >> line[0].x >> line[0].y >> line[1].x >> line[1].y >> pts[0].x >> pts[0].y >> pts[1].x >> pts[1].y;

        int minx = min(pts[0].x, pts[1].x);
        int maxx = max(pts[0].x, pts[1].x);
        int miny = min(pts[0].y, pts[1].y);
        int maxy = max(pts[0].y, pts[1].y);

        pts[0] = {minx, miny};
        pts[1] = {maxx, miny};
        pts[2] = {maxx, maxy};
        pts[3] = {minx, maxy};

        bool flag = false;
        for (int i = 0; i < 2; i++) {
            if (minx <= line[i].x && line[i].x <= maxx && miny <= line[i].y && line[i].y <= maxy) {
                flag = true;
            }
        }
        if (flag) {
            cout << "T\n";
            continue;
        }

        for (int i =0; i < 4; i++) {
            if (f(line[0],line[1],pts[i],pts[(i+1)%4])) {
                flag = true;
            }
        }
        if (flag) {
            cout << "T\n";
            continue;
        }

        cout << "F\n";


    }
    return 0;
}
