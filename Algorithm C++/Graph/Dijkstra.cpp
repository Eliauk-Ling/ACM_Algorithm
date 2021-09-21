/**
* dijkstra最短路 + heap优化
* 采用链式前向星存图
*/

#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

const int INF = 0x3f3f3f3f;
const int N = 1e5 + 10;
struct Edge {
	int w, to, next;
	Edge() {};
	bool operator <(const Edge& rhs)const {
		return w > rhs.w;
	}
}e[N];
int head[N], cnt, n, m, dis[N];
bool vis[N];
std::priority_queue<Edge> q;

void add(int u, int v, int w) {
	e[cnt].to = v;
	e[cnt].w = w;
	e[cnt].next = head[u];
	head[u] = cnt++;
}

bool dijkstra(int start,int end) {
	Edge e1, e2;
	e1.to = start;
	e1.w = 0;
	dis[start] = 0;
	q.push(e1);
	while (!q.empty()) {
		e1 = q.top();
		q.pop();
		if (vis[e1.to])continue;
		vis[e1.to] = 1;
		for (int i = head[e1.to]; ~i; i = e[i].next) {
			int u = e[i].to;
			if (!vis[u] && dis[u] > dis[e1.to] + e[i].w) {
				dis[u] = dis[e1.to] + e[i].w;
				e2.to = u;
				e2.w = dis[u];
				q.push(e2);
			}
		}
	}
	if (dis[end] >= INF)return false;
	return true;
}
