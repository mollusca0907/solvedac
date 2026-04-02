#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

int main() {

    int n;
    cin >> n;

    vector<Point> pts(n,{0,0});
    for (int i = 0; i < n; i++) {
        cin >> pts[i].x >> pts[i].y;
    }

    sort(pts.begin(), pts.end(), [](auto a, auto b) {
        if (a.x == b.x) {
            return a.y < b.y;
        }
        return a.x < b.x;
    });

    for (Point it : pts) {
        cout << it.x << " " << it.y << "\n";
    }


}