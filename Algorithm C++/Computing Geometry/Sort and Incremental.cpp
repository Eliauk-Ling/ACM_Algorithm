#include <Algorithm C++/Computing Geometry/Point_double.cpp>
#include <Algorithm C++/Computing Geometry/Segement and Polygon.cpp>
#include <algorithm>
#include <cmath>

const int N = 1e5 + 10;

Point p[N];
Line l[N], que[N];

double get_angle(Point a) { return atan2(a.y, a.x); }

double get_angle(Line a) { return atan2(a.p2.y - a.p1.y, a.p2.x - a.p1.x); }

bool cmp(Line l1, Line l2) {
    Vector a = l1.p2 - l1.p1, b = l2.p2 - l2.p1;
    double angle1 = get_angle(a), angle2 = get_angle(b);
    if (sgn(angle1 - angle2) == 0) return sgn(cross(a, l2.p2 - l1.p1)) >= 0;
    return angle1 < angle2;
}

Point get_cross_point(Line a, Line b) {
    return Point((a.c * b.b - b.c * a.b) / (b.a * a.b - a.a * b.b),
        (b.a * a.c - a.a * b.c) / (a.a * b.b - b.a * a.b));
}

bool is_right(Line a, Line b, Line c) {
    Point o = get_cross_point(b, c);
    if (sgn(cross(a.p2 - a.p1, o - a.p1)) < 0) return true;
    return false;
}

bool half_plane_cross(int n) {
    std::sort(l, l + n, cmp);
    int head = 0, tail = 0, cnt = 0;
    for (auto i = 0; i < n - 1; i++) {
        if (sgn(get_angle(l[i]) - get_angle(l[i + 1])) == 0) continue;
        l[cnt++] = l[i];
    }
    l[cnt++] = l[n - 1];
    for (auto i = 0; i < cnt; i++) {
        while (tail - head > 1 && is_right(l[i], que[tail - 1], que[tail - 2]))
            tail--;
        while (tail - head > 1 && is_right(l[i], l[head], l[head + 1])) head++;
        que[tail++] = l[i];
    }
    while (tail - head > 1 && is_right(que[head], que[tail - 1], que[tail - 2]))
        tail--;
    while (tail - head > 1 && is_right(que[tail - 1], l[head], l[head + 1]))
        head++;
    if (tail - head < 3) return false;
    return true;
}

bool judge(int n) {
    double res = 0;
    for (int i = 1; i < n - 1; i++) {
        res += cross(p[i] - p[0], p[i + 1] - p[0]);
    }
    return sgn(res) < 0;
}
