/**
* 使用邻接矩阵存图
*/
#include <algorithm>
#include <vector>
#include <cstring>

const int N = 1e5 + 10;
const int INF = 0x3f3f3f3f;
int dis[N], n, m;	//n为顶点数，m为边数
bool vis[N];
int prim(std::vector<std::vector<int> >& g) {
	memset(vis, 0, sizeof vis);
	memset(dis, 0, sizeof dis);
	int res = 0;
	for (int i = 0; i < n; i++) {
		int temp = -1;
		for (int j = 1; j <= n; j++) {
			if (!vis[j] && (temp == -1 || dis[temp] > dis[j]))
				temp = j;
		}
		vis[temp] = 1;
		if (i && (dis[temp] == INF))return INF;		//未连通
		if (i)
			res += dis[temp];
		for (int j = 1; j <= n; j++)
			dis[j] = std::min(dis[j], g[temp][j]);
	}
	return res;
}
