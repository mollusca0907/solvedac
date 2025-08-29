#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Point {
    ll x;
    ll y;
};

int ccw(Point p1, Point p2, Point p3) {
    ll ans = 0;
    ans += (p1.x * p2.y + p2.x * p3.y + p3.x * p1.y);
    ans -= (p1.x * p3.y + p3.x * p2.y + p2.x * p1.y);

    if (ans == 0) {
        return 0;
    }
    else if (ans < 0) {
        return -1;
    }
    else {
        return 1;
    }
    
}

int main() {

    vector<Point> p(4);
    
    cin >> p[0].x >> p[0].y >> p[1].x >> p[1].y;
    cin >> p[2].x >> p[2].y >> p[3].x >> p[3].y;

    int ab_cd = ccw(p[0], p[1], p[2]) * ccw(p[0], p[1], p[3]);
    int cd_ab = ccw(p[2], p[3], p[0]) * ccw(p[2], p[3], p[1]);

    if (ab_cd <= 0 && cd_ab <= 0) {
        cout << 1;
    }
    else {
        cout << 0;
    }

    return 0;
}