/** Rank 1000 	
* Easy Version
* 
* 1.WA on test 3
* 2.WA on test 7
* 3.AC	Time : 31 ms	Memory : 3656 KB
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
	ll n;
	int x;
	cin >> n >> x;
	n %= 6;
	while (n) {
		if (n & 1) {
			if (x == 2)x = 2;
			else x = x == 1 ? 0 : 1;
		}
		else {
			if (x == 0)x = 0;
			else x = x == 2 ? 1 : 2;
		}
		n--;
	}
	cout << x << endl;
	return 0;
}
