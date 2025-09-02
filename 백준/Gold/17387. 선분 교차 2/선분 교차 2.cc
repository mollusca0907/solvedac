#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Point {
    ll x;
    ll y;
    bool operator<=(const Point& other) {
        if (x == other.x) {
            return y <= other.y;
        }
        else {
            return x <= other.x;
        }
    }
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

bool is_cross(Point& p1, Point& p2, Point& p3, Point& p4) {
    int ab_cd = ccw(p1, p2, p3) * ccw(p1, p2, p4);
    int cd_ab = ccw(p3, p4, p1) * ccw(p3, p4, p2);

    if (ab_cd <= 0 && cd_ab <= 0) {
        if (ab_cd == 0 && cd_ab == 0) {
            if (p2 <= p1) swap(p1, p2);
            if (p4 <= p3) swap(p3, p4);

            return p1 <= p4 && p3 <= p2;
        }
        else {
            return true;
        }
    }
    else {
        return false;
    }
}

int main() {

    vector<Point> p(4);

    cin >> p[0].x >> p[0].y >> p[1].x >> p[1].y;
    cin >> p[2].x >> p[2].y >> p[3].x >> p[3].y;

    cout << is_cross(p[0], p[1], p[2], p[3]);

    return 0;
}