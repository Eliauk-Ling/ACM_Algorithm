#include <Algorithm C++/Computing Geometry/Point_double.cpp>
#include <algorithm>
/*Has been checked*/

// p[] 为存点的数组
const int N = 1e5 + 10;

Point p[N];
int temp[N];

bool cmpx(Point a, Point b){
	return a.x < b.x;
}

bool cmp(int a,int b) {
	return p[a].y < p[b].y;
}

double conquer_pair(int start, int end) {
	double res = INF;
	int mid = (start + end) / 2;
	if (start == end)return INF;
	else if (start + 1 == end)return distance(p[0], p[1]);
	res = std::min(conquer_pair(start, mid), conquer_pair(mid, end));
	int k = 0;
	for (int i = start; i < end; i++) {
		if (sgn(p[mid].x - p[i].x - res) <= 0)temp[k++] = i;
	}
	std::sort(temp, temp + k, cmp);
	for (int i = 0; i < k; i++) {
		for (int j = i + 1; j < k; j++) {
			if (sgn(p[temp[j]].y - p[temp[i]].y - res) < 0)
				res = std::min(res, distance(p[temp[j]], p[temp[i]]));
			else break;
		}
	}
	return res;
}

double find_closest_dis(int length) {
	std::sort(p, p + length, cmpx);
	return conquer_pair(0, length);
}