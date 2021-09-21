/**
* 使用邻接矩阵存图，其中dis[i][j]表示结点i到j的距离
*/
#include <algorithm>

const int INF = 0x3f3f3f3f;
const int N = 1e5 + 10;
int dis[N][N];
int n, m;

void init() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j)dis[i][j] = INF;
		}
	}
}

void floyd() {		//若i与j不相邻，则dis[i][j] = INF; 若i==j，则dis[i][j]=0;
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dis[i][k] + dis[k][j] < dis[i][j])
					dis[i][j] = dis[i][k] + dis[k][j];
			}
		}
	}
}
