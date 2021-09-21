/** Rank 1000	Easy Version
* 
* 1.AC	Time : 31 ms	Memory : 3788 KB
*/
#include<algorithm>	
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
#include<stack>
#include<map>
using namespace std;
typedef long long ll;
int main(void) {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int a[105], b[105];
	map<int, int> cnt, cnta, cntb;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cnt[a[i]]++, cnta[a[i]]++;
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		cnt[b[i]]++, cntb[b[i]]++;
	}
	bool flag = 1;
	for (auto i : cnt) {
		if (i.second & 1) {
			flag = 0;
			break;
		}
	}
	if (!flag) {
		cout << -1 << endl;
	}
	else {
		int sum = 0;
		for (int i = 1; i <= 5; i++) {
			sum += abs(cnta[i] - cntb[i]) / 2;
		}
		cout << sum / 2 << endl;
	}
	return 0;
}
