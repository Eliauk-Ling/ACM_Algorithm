/**
* ʹ���ڽӾ����ͼ������dis[i][j]��ʾ���i��j�ľ���
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

void floyd() {		//��i��j�����ڣ���dis[i][j] = INF; ��i==j����dis[i][j]=0;
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dis[i][k] + dis[k][j] < dis[i][j])
					dis[i][j] = dis[i][k] + dis[k][j];
			}
		}
	}
}
