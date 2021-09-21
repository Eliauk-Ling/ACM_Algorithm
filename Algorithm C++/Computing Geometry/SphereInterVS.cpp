#include <algorithm>
#include <cmath>

const double PI = acos(-1.0);

typedef struct Point {
    double x, y, z;
    Point() {

    }
    Point(double a, double b, double c) {
        x = a;
        y = b;
        z = c;
    }
    Point operator -(const Point& b)const {    
        return Point(x - b.x, y - b.y, z - b.z);
    }
    Point operator +(const Point& b)const {     
        return Point(x + b.x, y + b.y, z + b.z);
    }

    Point operator *(const double& k)const {    
        return Point(x * k, y * k, z * k);
    }
    Point operator /(const double& k)const {    
        return Point(x / k, y / k, z / k);
    }
    double operator *(const Point& b)const {    
        return x * b.x + y * b.y + z * b.z;
    }
};
double dist(Point p1, Point p2) {       
    return sqrt((p1 - p2) * (p1 - p2));
}

struct Sphere {
	double r;
	Point center;
};

void sphereinter_vs(Sphere a, Sphere b,double& v,double& s) {
    double d = dist(a.center, b.center);
    double t = (d * d + a.r * a.r - b.r * b.r) / (2.0 * d);
    double h = sqrt((a.r * a.r) - (t * t)) * 2;
    double angle_a = 2 * acos((a.r * a.r + d * d - b.r * b.r) / (2.0 * a.r * d));
    double angle_b = 2 * acos((b.r * b.r + d * d - a.r * a.r) / (2.0 * b.r * d)); 
    double l1 = ((a.r * a.r - b.r * b.r) / d + d) / 2;
    double l2 = d - l1;
    double x1 = a.r - l1, x2 = b.r - l2;
    double v1 = PI * x1 * x1 * (a.r - x1 / 3);
    double v2 = PI * x2 * x2 * (b.r - x2 / 3);
    v = v1 + v2;//相交部分体积
    double s1 = PI * a.r * x1;
    double s2 = PI * a.r * x2;
    s = 4 * PI * (a.r * a.r + b.r * b.r) - s1 - s2;//剩余部分表面积
}
