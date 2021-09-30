#include <Algorithm C++/Computing Geometry/Point_double.cpp>
#include <algorithm>
#include <cmath>
#include <vector>
/*Has been checked, but does not Accept*/

const int N = 1e5 + 10;
Point p[N / 2];
int pos[N], top, bot;//pos为凸包顶点的下标
std::vector<Point> Vec;//凸包顶点

inline int isleft(Point a, Point b, Point c) {
	return sgn(cross(b - a, c - b));
}

inline void melkman(int n) {
	bot = n - 1, top = n;
	pos[top++] = 0, pos[top++] = 1;
	int i = 0;
	for (i = 2; !isleft(p[pos[top - 2]], p[pos[top - 1]], p[i]); i++)
		pos[top - 1] = i;
	pos[bot--] = i, pos[top++] = i;
	if (isleft(p[pos[n]], p[pos[n + 1]], p[pos[n + 2]]) < 0)
		std::swap(pos[n], pos[n + 1]);
	for (i++; i < n; i++) {
		if (isleft(p[pos[top - 2]], p[pos[top - 1]], p[i]) <= 0 ||
			isleft(p[pos[bot + 1]], p[pos[bot + 2]], p[i]) <= 0) {
			while (isleft(p[pos[top - 2]], p[pos[top - 1]], p[i]) <= 0)
				top--;
			pos[top++] = i;
			while (isleft(p[pos[bot + 1]], p[pos[bot + 2]], p[i]) <= 0)
				bot++;
			pos[bot--] = i;
		}
	}
	for (int i = bot + 1; i < top; i++)Vec.push_back(p[pos[i]]);
}
