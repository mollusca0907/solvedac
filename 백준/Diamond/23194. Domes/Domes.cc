#include <bits/stdc++.h>
using namespace std;
using ld = long double;

constexpr ld EPS = 1e-12;

struct Point {
    ld x, y;

    Point operator+(Point other) { return { x + other.x, y + other.y }; }
    Point operator-(Point other) { return { x - other.x, y - other.y }; }
    Point operator*(ld k) { return { x * k, y * k }; }
};

ld cross(Point a, Point b) {
    //0보다크면왼쪽, 0보다작으면오른쪽
    return a.x * b.y - b.x * a.y; //외적이긴 한데 한점을 원점으로 옮겨버려서 간단해짐
}

struct Line {
    Point p, v; //직선을 한 점 p와 방향벡터 v로 표현
    ld angle;

    Line(Point p1, Point p2) { //p1->p2직선
        p = p1;
        v = p2 - p1;
        angle = atan2l(v.y, v.x); //아크탄젠트함수로 각 구하기
    }

    Line(ld a, ld b, ld c) {
        if (abs(a) > abs(b)) p = { -c / a, 0 };
        else p = { 0, -c / b };
        v = { b, -a };
        angle = atan2l(v.y, v.x);
    }

    bool in(Point other) {
        return cross(v, other - p) >= -EPS;
    }

};

ld dist(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

Point crossPoint(Line a, Line b) {
    ld s = cross(b.v, a.p - b.p) / cross(a.v, b.v);
    return a.p + a.v * s;
}

vector<Point> HPI(vector<Line>& lines) {

    sort(lines.begin(), lines.end(), [](Line a, Line b) {
        if (abs(a.angle - b.angle) > EPS) return a.angle < b.angle;
        return cross(a.v, b.p - a.p) < -EPS;
        });

    vector<Line>temp;
    for (int i = 0; i < lines.size(); i++) {
        if (i > 0 && abs(lines[i].angle - lines[i - 1].angle) < EPS) continue;
        temp.push_back(lines[i]);
    }

    lines = temp;


    deque<Line>dq;
    for (int i = 0; i < lines.size(); i++) {
        while (dq.size() >= 2 && !lines[i].in(crossPoint(dq[dq.size() - 2], dq[dq.size() - 1]))) {
            dq.pop_back();
        }
        while (dq.size() >= 2 && !lines[i].in(crossPoint(dq[0], dq[1]))) {
            dq.pop_front();
        }
        dq.push_back(lines[i]);
    }
    while (dq.size() >= 3 && !dq[0].in(crossPoint(dq[dq.size() - 2], dq[dq.size() - 1]))) {
        dq.pop_back();
    }
    while (dq.size() >= 3 && !dq[dq.size() - 1].in(crossPoint(dq[0], dq[1]))) {
        dq.pop_front();
    }

    if (dq.size() < 3) return { };

    vector<Point> ans;
    for (int i = 0; i < dq.size(); i++) {
        ans.push_back(crossPoint(dq[i], dq[(i + 1) % dq.size()]));
    }

    return ans;

}

ld godmad(vector<Point>& pts) {
    ld s = 0;
    for (int i = 0; i < pts.size(); i++) {
        s += cross(pts[i], pts[(i + 1) % pts.size()]); //신발끈공식과 외적은 같은 식을 사용함
    }
    return abs(s) / 2;
}

int main() {

    cout << fixed << setprecision(4);

    ld dx, dy, n;
    cin >> dx >> dy >> n;

    vector<Point>pts(n);
    for (int i = 0; i < n; i++) {
        cin >> pts[i].x >> pts[i].y;
    }

    vector<int> order(n);
    for (int i = 0; i < n; i++) {
        cin >> order[i];
    }

    vector<Line>lns;
    lns.push_back(Line({ 0, 0 }, { dx, 0 }));
    lns.push_back(Line({ dx, 0 }, { dx, dy }));
    lns.push_back(Line({ dx, dy }, { 0, dy }));
    lns.push_back(Line({ 0, dy }, { 0, 0 }));


    if (n > 1) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                lns.push_back(Line(pts[order[j] - 1], pts[order[i] - 1]));
            }
        }


        lns.push_back(Line(pts[order[n - 1] - 1], pts[order[0] - 1]));
    }

    auto v = HPI(lns);
    cout << godmad(v);


    //if (v.empty()) {
    //    cout << 0;
    //}
    //else {
    //    cout << godmad(v);
    //}





    return 0;
}