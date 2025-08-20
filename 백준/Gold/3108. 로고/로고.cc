#include <bits/stdc++.h>
using namespace std;

int parent[1001];

struct Rect {
	int x1, y1;
	int x2, y2;
};

int find(int x) { //find root
	if (parent[x] != x) {
		parent[x] = find(parent[x]);
	}
	return parent[x];
}

void unite(int x, int y) { 
	x = find(x);
	y = find(y);
	if (x != y) {
		parent[y] = x;
	}
}

bool is_con(Rect a, Rect b) {
	if (a.x2 < b.x1 || b.x2 < a.x1) return false;
	if (a.y2 < b.y1 || b.y2 < a.y1) return false;

	if (a.x1 < b.x1 && b.x2 < a.x2 && a.y1 < b.y1 && b.y2 < a.y2) return false;
	if (b.x1 < a.x1 && a.x2 < b.x2 && b.y1 < a.y1 && a.y2 < b.y2) return false;
	return true;
}

bool on_onepoint(Rect a) {
	if ((a.x1 <= 0 && 0 <= a.x2) && (a.y1 == 0 || a.y2 == 0)) return true;
	if ((a.y1 <= 0 && 0 <= a.y2) && (a.x1 == 0 || a.x2 == 0)) return true;

	//if ((a.x1 <= 0 && 0 <= a.x2) || (a.y1 <= 0 && 0 <= a.y2)) {
	//	return true;
	//}
	return false;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	vector<Rect> rects(n);
	for (int i = 0; i < n; i++) {
		cin >> rects[i].x1 >> rects[i].y1 >> rects[i].x2 >> rects[i].y2;
		if (rects[i].x1 > rects[i].x2) swap(rects[i].x1, rects[i].x2);
		if (rects[i].y1 > rects[i].y2) swap(rects[i].y1, rects[i].y2);
		parent[i] = i;
	}

	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (is_con(rects[i], rects[j])) {
				unite(i, j);
			}
		}
	}

	set<int> g;
	for (int i = 0; i < n; i++) {
		g.insert(find(i));
	}
	int ans = g.size();
	for (int i = 0; i < n; i++) {
		if (on_onepoint(rects[i])) {
			ans--;
			break;
		}
	}
	cout << ans;

	return 0;
}