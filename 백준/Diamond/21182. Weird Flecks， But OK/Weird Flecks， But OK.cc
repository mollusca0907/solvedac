#include <bits/stdc++.h>
using namespace std;
using ld = long double;

struct Point {
    ld x, y, z;
};

ld f(int n, vector<pair<ld,ld>>& pts) {


    ld x = 0;
    ld y = 0;

    for (int i = 0; i < n; i++) {
        x += pts[i].first;
        y += pts[i].second;
    }

    x /= n;
    y /= n;

    ld ratio = 0.1;
    for (int i =0; i < 50'000; i++) {
        int mx_dist_idx= 0;
        ld mx_dist = -1.0;

        for (int j = 0; j < n; j++) {

            ld dist = (x-pts[j].first)*(x-pts[j].first) + (y-pts[j].second)*(y-pts[j].second);
            if (dist > mx_dist) {
                mx_dist = dist;
                mx_dist_idx = j;
            }

        }

        x += (pts[mx_dist_idx].first - x) * ratio;
        y += (pts[mx_dist_idx].second - y) * ratio;

        ratio *= 0.9997;

    }

    ld mx_dist = 0;
    for (int i =0; i < n; i++) {
        ld dist = sqrt((x-pts[i].first)*(x-pts[i].first) + (y-pts[i].second)*(y-pts[i].second));
        if (dist > mx_dist) {
            mx_dist = dist;
        }
    }
    return mx_dist;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >>n;


    vector<pair<ld,ld>>xy(n);
    vector<pair<ld,ld>>yz(n);
    vector<pair<ld,ld>>zx(n);
    ld x = 0;
    ld y = 0;
    ld z = 0;

    for (int i = 0; i < n; i++) {
        ld _x,_y,_z;
        cin >> _x >> _y >> _z;
        xy[i] = {_x, _y};
        yz[i] = {_y, _z};
        zx[i] = {_z, _x};
    }

    ld xy_dist = f(n, xy);
    ld yz_dist = f(n, yz);
    ld zx_dist = f(n, zx);

    ld ans = min({xy_dist, yz_dist, zx_dist});
    ans *= 2.0;

    cout << fixed << setprecision(4) << ans;


    return 0;
}