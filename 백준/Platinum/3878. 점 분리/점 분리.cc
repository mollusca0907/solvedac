#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

struct Point {
	ll x;
	ll y;
	bool operator<(const Point& other) const {
		return x < other.x || (x == other.x && y < other.y);
	}
};

Point p0;

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

vector<Point> graham(vector<Point>&pts){
	int n = pts.size();
	vector<Point> h;
	for (int i = 0; i < n; i++){
		while(h.size()>= 2 && ccw(h[h.size()-2], h[h.size()-1], pts[i]) <= 0){ //cw or line (not ccw)
			h.pop_back();
		}
		h.push_back(pts[i]);
	}
	return h;
}

bool iscross(Point a, Point b, Point c, Point d){
	int ab = ccw(a,b,c) * ccw(a,b,d);
	int cd = ccw(c,d,a) * ccw(c,d,b);
	if (ab == 0 && cd == 0){
		if (b < a) swap(b,a);
		if (d < c) swap(d,c);
		return !(d < a) && !(b < c);
	}
	return ab <= 0 && cd <= 0;
}

bool isinside(vector<Point>& h, Point p){
	int sz = h.size();
	if (sz < 3) return false;

	if (ccw(h[0],h[1], p) <= 0) return false;
	if (ccw(h[0],h[sz-1],p) >= 0) return false;

	int l = 1;
	int r = sz-1;
	
	//[l, l+1]구간에속할거에요
	while(l+1 < r){
		int mid = (l + r) / 2;
		if (ccw(h[0],h[mid],p) >= 0){
			l = mid;
		}
		else {
			r = mid;
		}
	}

	return ccw(h[l],h[l+1],p) > 0;
}

vector<pair<Point,Point>> lines(vector<Point>& h){
	vector<pair<Point,Point>> res;
	int sz = h.size();
	if (sz == 1){
		res.push_back({h[0],h[0]});
	} else if (sz == 2){
		res.push_back({h[0], h[1]});
	} else {
		for (int i = 0; i < sz; i++){
			res.push_back({h[i],h[(i+1)%sz]});
		}
	}
	return res;
}

int main(){

	int t;
	cin >> t;
	while(t--){


		int n,m;
		cin >> n >> m;

		vector<Point>pts;
		Point p0_0;
		vector<Point>pts1;
		Point p0_1;
		for (int i =0 ; i < n; i++){
			int x,y;
			cin >> x >> y;
			pts.push_back({x,y});
		}
		for (int i =0; i < m; i++){
			int x,y;
			cin >> x >> y;
			pts1.push_back({x,y});	
		}
////////////////////////////////////////
		int idx = 0;
		for (int i = 1; i < n; i++){
			if (pts[i].y < pts[idx].y || (pts[i].y == pts[idx].y && pts[i].x < pts[idx].x)){
				idx = i;
			}
		}
		swap(pts[0],pts[idx]);
		p0 = p0_0=pts[0];
		sort(pts.begin()+1, pts.end(), compare);
		auto h = graham(pts);
////////////////////////////////////////
		idx = 0;
		for (int i = 1; i < m; i++){
			if (pts1[i].y < pts1[idx].y || (pts1[i].y == pts1[idx].y && pts1[i].x < pts1[idx].x)){
				idx = i;
			}
		}
		swap(pts1[0],pts1[idx]);
		p0 = p0_1 =pts1[0];
		sort(pts1.begin()+1, pts1.end(), compare);
		auto h1 = graham(pts1);
///////////////////////////////////////
		bool flag = false;
		for (int i = 0; i < m; i++){
			if (isinside(h,pts1[i])){
				flag = true;
				break;
			}
		}
		for (int i = 0; i < n; i++){
			if (isinside(h1,pts[i])){
				flag = true;
				break;
			}
		}

		if (!flag){
			auto l1 = lines(h);
			auto l2 = lines(h1);
			for (auto [a,b] : l1){
				for (auto [c,d] : l2){
					if (iscross(a,b,c,d)){
						flag = true;
						break;
					}
				}
				if (flag) break;
			}
		}


		if (flag){
			cout << "NO\n";
		} else {
			cout << "YES\n";
		}






	}


	return 0;
}