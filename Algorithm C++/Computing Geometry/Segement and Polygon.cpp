#include <Algorithm C++/Computing Geometry/Point_double.cpp>
#include <algorithm>
#include <vector>

struct Line {
    Point p1, p2;
    double a, b, c;
    Line(double x1 = 1, double x2 = -1, double x3 = 0) { a = x1, b = x2, c = x3; }
    Line(const Point& x1, const Point& x2) {
        p1 = x1, p2 = x2;
        a = x1.y - x2.y;
        b = x2.x - x1.x;
        c = x1.y * (x1.x - x2.x) - x1.x * (x1.y - x2.y);
    }
};

//  判断两条线段是否相交

bool iscross(Line l1, Line l2) {
    Point a = l1.p1, b = l1.p2;
    Point c = l2.p1, d = l2.p2;
    if (sgn(cross(b - 1, c - a) * cross(b - 1, d - a)) < 0 &&
        sgn(cross(c - d, c - a) * cross(c - d, c - b)) < 0)
        return true;
    return false;
}

// 计算多边形面积

double calc_area(std::vector<Point>& p) {
    double sum = 0;
    for (int i = 0; i < p.size(); i++) {
        i != p.size() - 1 ? sum += cross(p[i], p[i + 1])
            : sum += cross(p[p.size() - 1], p[0]);
    }
    sum /= 2;
    return fabs(sum);
}

// 判断点是否在多边形内部

std::vector<Point> pol;

bool is_on_segment(Point a, Point b, Point p) {
    if (sgn(cross(a - p, b - p)) == 0 && sgn(dot(a - p, b - p)) <= 0) return true;
    return false;
}

bool is_in_polygon(Point p) {
    bool flag = 0;
    Point p1, p2;
    for (int i = 0, j = pol.size() - 1; i < pol.size(); j = i++) {
        p1 = pol[i], p2 = pol[j];
        if (is_on_segment(p1, p2, p)) return true;
        if (sgn(p1.y - p.y) > 0 != sgn(p2.y - p.y) > 0 &&
            sgn(p.x - (p.y - p1.y) * (p1.x - p2.x) / (p1.y - p2.y) - p1.x) < 0)
            flag = !flag;
    }
    return flag;
}

//两线段间的最短距离

int judge_dir(Point a, Point b, Point c) {
    Vector v1 = b - a, v2 = c - a;
    if (cross(v1, v2) < -EPS)return -1;		//顺时针
    else if (cross(v1, v2) > EPS)return 1;		//逆时针
    else if (dot(v1, v2) < 0)return -2;		//反向延长线
    else if (dot(v1, v2) >= 0) {
        if (sgn(norm(v1) - norm(v2)) == 0)return 2;		//延长线
        return 0;		//在线上
    }
}

double calc_dis(Point a, Point b, Point c) {
    Vector v1 = a - b, v2 = a - c;
    if (dot(v1, v2) < 0)
        return norm(v2);
    else if (dot(v1, v2) >= norm(v1))
        return norm(v1 - v2);
    else
        return cross(v1, v2) / norm(v1);
}

double min_dis(Point a, Point b, Point c, Point d) {
    return std::min(std::min(std::min(calc_dis(a, b, c), calc_dis(a, b, d)),
        calc_dis(c, d, a)),
        calc_dis(c, d, b));
}
