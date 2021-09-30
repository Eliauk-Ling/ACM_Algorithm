#include <cmath>

const double INF = 1e200;
const double EPS = 1e-9;
const double PI = acos(-1.0);

int sgn(double x) {
	if (fabs(x) < EPS)return 0;
	else
		return x < 0 ? -1 : 1;
}

struct Point {
	Point(double a = 0, double b = 0) {
		x = a, y = b;
	}
	double x, y;

	Point operator =(Point const& rhs) {
		this->x = rhs.x;
		this->y = rhs.y;
		return *this;
	}
};

typedef Point Vector;

Point operator + (Point a, Point b) {
	return Point(a.x + b.x, a.y + b.y);
}
Point operator - (Point a, Point b) {
	return Point(a.x - b.x, a.y - b.y);
}
Point operator *(Point a, double t) {
	return Point(a.x * t, a.y * t);
}
Point operator /(Point a, double t) {
	return Point(a.x / t, a.y / t);
}
bool operator ==(Vector a, Vector b) {
	return (sgn(a.x - b.x) == 0 && sgn(a.y - b.y) == 0);
}
bool operator !=(Vector a, Vector b) {
	return !(a == b);
}
double dot(Vector a, Vector b) {
	return (a.x * b.x + a.y * b.y);
}
double cross(Vector a, Vector b) {
	return (a.x * b.y - a.y * b.x);
}
double norm(Vector a) {
	return sqrt(dot(a, a));
}
double distance(Point a, Point b) {
	return norm(a - b);
}
