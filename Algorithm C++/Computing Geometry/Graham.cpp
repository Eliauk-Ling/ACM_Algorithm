#include <Algorithm_C++/Computing Geometry/Point_double.cpp>
#include <vector>
#include <algorithm>
#include <cmath>

struct Stack {
	std::vector<Point> p;
	Stack() {};
	void push(Point const& a) {
		p.push_back(a);
	}
	void pop() {
		p.pop_back();
	}
	bool empty()const {
		return p.empty();
	}
	Point top() const {
		return p.back();
	}
	Point next_top()const {
		return p[p.size() - 2];
	}
	unsigned int size() {
		return p.size();
	}
}S;

std::vector<Point> Q;

double get_angle(Point v) {
	if (std::atan2(v.y, v.x) < 0)return std::atan2(v.y,v.x) + 2 * PI;
	else return std::atan2(v.y, v.x);

}

bool operator <(Point a, Point b) {
	a = Q[0];
	if (sgn(get_angle(a) - get_angle(b)) == 0)return a.x < b.x;
	else return get_angle(a) < get_angle(b);
}

void graham( ) {
	int k = 0;
	for (int i = 1; i < Q.size(); i++) {
		if (Q[i].y < Q[k].y || (Q[i].y == Q[k].y && Q[i].x < Q[k].x))
			k = i;
	}
	std::swap(Q[k], Q[0]);
	std::sort(Q.begin() + 1, Q.end());
	bool flag = 1;
	if (Q.size() < 2) {
		flag = 0;
	}
	else {
		S.push(Q[0]), S.push(Q[1]), S.push(Q[2]);
		for (int i = 3; i < Q.size(); i++) {
			while (S.size() > 1 && (sgn(cross(S.top() - S.next_top(), Q[i] - S.next_top())) >= 0))
				S.pop();
			S.push(Q[i]);
		}
	}
}