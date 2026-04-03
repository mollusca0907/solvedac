#include <bits/stdc++.h>
using namespace std;
using ld = long double;

struct Point {
     ld x, y, z;
};

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >>n;


    vector<Point>pts(n);

    ld x = 0;
    ld y = 0;
    ld z = 0;

    for (int i = 0; i < n; i++) {
        cin >> pts[i].x >> pts[i].y >> pts[i].z;
        x += pts[i].x;
        y += pts[i].y;
        z += pts[i].z;
    }

    x /= n;
    y /= n;
    z /= n;

    ld ratio = 0.1;
    for (int i =0; i < 100'000; i++) {
        int mx_dist_idx= 0;
        ld mx_dist = -1.0;

        for (int j = 0; j < n; j++) {

            ld dist = (x-pts[j].x)*(x-pts[j].x) + (y-pts[j].y)*(y-pts[j].y) + (z-pts[j].z)*(z-pts[j].z);
            if (dist > mx_dist) {
                mx_dist = dist;
                mx_dist_idx = j;
            }

        }

        x += (pts[mx_dist_idx].x - x) * ratio;
        y += (pts[mx_dist_idx].y - y) * ratio;
        z += (pts[mx_dist_idx].z - z) * ratio;

        ratio *= 0.9997;

    }

    ld mx_dist = 0;
    for (int i =0; i < n; i++) {
        ld dist = sqrt((x-pts[i].x)*(x-pts[i].x) + (y-pts[i].y)*(y-pts[i].y) + (z-pts[i].z)*(z-pts[i].z));
        if (dist > mx_dist) {
            mx_dist = dist;
        }
    }

    cout << fixed << setprecision(2) << mx_dist;




    return 0;
}