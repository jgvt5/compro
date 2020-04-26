#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
const ld EPS = 1e-10;

ld add(ld a, ld b) {
	if (abs(a + b) < EPS * (abs(a) + abs(b))) return 0;
	return a + b;
}

struct Point {
	ld x, y;
	int num;
	Point() {}
	Point(ld x, ld y) : x(x), y(y) {}
	Point(ld x, ld y, int n) : x(x), y(y), num(n) {}
	Point operator+(const Point &p) { return Point(add(x, p.x), add(y, p.y)); }
	Point operator-(const Point &p) {
		return Point(add(x, -p.x), add(y, -p.y));
	}
	bool operator==(const Point &p) { return x == p.x && y == p.y; }
	bool operator!=(const Point &p) { return *this == p; }
	bool operator<(const Point &p) {
		if (x != p.x)
			return x < p.x;
		else
			return y < p.y;
	}
	friend Point operator*(ld k, const Point &p) {
		return Point(k * p.x, k * p.y);
	}
	ld dot(const Point &p) { return add(x * p.x, y * p.y); }
	ld det(const Point &p) { return add(x * p.y, -y * p.x); }
};

bool on_seg(Point p1, Point p2, Point q) {
	return abs((p1 - q).det(p2 - q)) < EPS && (p1 - q).dot(p2 - q) < EPS;
}

Point intersection(Point p1, Point p2, Point q1, Point q2) {
	return p1 + ((q2 - q1).det(q1 - p1) / (q2 - q1).det(p2 - p1)) * (p2 - p1);
}

bool isCross(Point p1, Point p2, Point q1, Point q2) {
	if (abs((p1 - p2).det(q1 - q2)) < EPS) return false;
	Point r = intersection(p1, p2, q1, q2);
	return on_seg(p1, p2, r) && on_seg(q1, q2, r);
}

bool isCrossSub(Point p1, Point p2, Point q1, Point q2) {
	if (!isCross(p1, p2, q1, q2)) return false;
	Point r = intersection(p1, p2, q1, q2);
	return p1 != r && p2 != r && q1 != r && q2 != r;
}

vector<Point> convex_hull(vector<Point> p) {
	sort(p.begin(), p.end());
	int n = p.size();
	int k = 0;
	vector<Point> q(2 * n);
	for (int i = 0; i < n; i++) {
		while (k > 1 && (q[k - 1] - q[k - 2]).det(p[i] - q[k - 1]) <= 0) k--;
		q[k++] = p[i];
	}
	for (int i = n - 2, t = k; i >= 0; i--) {
		while (k > t && (q[k - 1] - q[k - 2]).det(p[i] - q[k - 1]) <= 0) k--;
		q[k++] = p[i];
	}
	q.resize(k - 1);
	return q;
}

ld dist(Point p1, Point p2) { return (p1 - p2).dot(p1 - p2); }

ld longestdist(vector<Point> t) {
	int n = t.size();
	ld M  = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) { M = max(M, dist(t[i], t[j])); }
	}
	return M;
}