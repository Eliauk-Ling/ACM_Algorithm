/**
 * 1.WA on test 2
 * 2.WA on test 2
 * 3.WA on test 1
 * 4.AC   Time:31ms   Memory:4048KB
 **/
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

bool isprime[100005];
vector<ll> primes;
void init(int n) {     //初始化质数表
    for (int i = 2; i <= n; i++) {
        if (!isprime[i])
            primes.push_back(i);
        for (auto p : primes) {
            if (p * i > n)
                break;
            isprime[p * i] = 1;
            if (i % p == 0)
                break;
        }
    }
}
int main(void) {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    init(100000);
    while (t--) {
        int d;
        cin >> d;
        int pos1 = int(lower_bound(primes.begin(), primes.end(), 1 + d) - primes.begin());
        int pos2 = int(lower_bound(primes.begin(), primes.end(), d + primes[pos1]) - primes.begin());
        cout << primes[pos1] * primes[pos2] << endl;
    }
    return 0;
}
