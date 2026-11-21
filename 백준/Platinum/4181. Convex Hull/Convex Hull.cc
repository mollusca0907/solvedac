#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

struct Point {ll x; ll y;};

int n;
Point p0;

vector<Point>pts;

int ccw(Point a, Point b, Point c){
	ll res = (a.x*b.y + b.x*c.y + c.x*a.y) - (b.x*a.y + c.x*b.y + a.x*c.y);
	if (res > 0) return 1; //ccw
	if (res < 0) return -1; //cw
	return 0; //line
}

ll dist(Point a, Point b){
	return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

bool compare(Point a, Point b){
	int s = ccw(p0, a, b);
	if (s!=0){
		return s > 0;
	}
	return dist(p0, a) < dist(p0,b);
}

vector<Point> graham(){
	vector<Point> h;
	for (int i = 0; i < n; i++){
		while(h.size()>= 2 && ccw(h[h.size()-2], h[h.size()-1], pts[i]) < 0){ //cw or line (not ccw)
			h.pop_back();
		}
		h.push_back(pts[i]);
	}
	return h;
}

int main(){

	cin >> n;

	for (int i =0; i < n; i++){
		int x, y;
		char c;
		cin >> x >> y >> c;
		if (c == 'Y'){
			pts.push_back({x,y});
		}
	}

	n = pts.size();
	int idx = 0;
	for (int i =0; i < n; i++){
		if (pts[i].x < pts[idx].x || (pts[i].x == pts[idx].x && pts[i].y < pts[idx].y)){
			idx = i;
		}
	}
	swap(pts[0],pts[idx]);
	p0 = pts[0];
	sort(pts.begin()+1, pts.end(), compare);

	int i = pts.size()-1;
	while(i>1 && ccw(p0,pts[i-1], pts[i])==0){
		i--;
	}
	reverse(pts.begin()+i, pts.end());


	auto h = graham();

	
	cout << h.size() << "\n";
	for (auto p : h){
		cout << p.x << " " << p.y << "\n";
	}
	


	return 0;
}