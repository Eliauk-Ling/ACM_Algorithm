#include <Algorithm C++/Computing Geometry/Point_double.cpp>
#include <algorithm>
#include <vector>
/*Has been checked*/

struct Circle {
	Point o;
	double r;
	Circle(Point p = Point(0, 0), double x = 0) {
		o = p;
		r = x;
	}
};

Point turn_ninty(Point p) {
	return Point(p.y, -p.x);
}

Circle get_circle(Point a, Point b) {
	return Circle((a + b) / 2, distance(a, b) / 2);
}

Circle get_circle(Point a, Point b, Point c) {
	Vector v1 = turn_ninty(b - a), v2 = turn_ninty(c - a);
	Point mid1 = (a + b) / 2, mid2 = (a + c) / 2;
	return Circle(
		mid1 + v1 * (cross(mid2 - mid1, v2) / cross(v1, v2)), distance((mid1 + v1 * (cross((mid2 - mid1), v2) / cross(v1, v2))), a)
	);
}

// vector<Point> p 为输入点的集合

Circle min_covering_circle(std::vector<Point>& p) {
	std::random_shuffle(p.begin(), p.end());
	Circle ans = Circle(p[0], 0);
	for (int i = 1; i < p.size(); i++) {
		if (sgn(distance(p[i], ans.o) - ans.r) > 0) {
			ans = Circle(p[i], 0);
			for (int j = 1; j <= i; j++) {
				if (sgn(distance(ans.o, p[j]) - ans.r)) {
					ans = get_circle(p[j], p[i]);
					for (int k = 1; k <= j; k++) {
						if (sgn(distance(ans.o, p[k]) - ans.r) > 0)
							ans = get_circle(p[i], p[k], p[j]);
					}
				}
			}
		}
	}
	return ans;
}
