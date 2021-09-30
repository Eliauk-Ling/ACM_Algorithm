/**
* ŷ��ɸ������ �� ��һ���������Ӹ���
*/
#include <vector>
/*Has been checked*/

typedef long long ll;
const int N = 1e5 + 10;

ll factor[N];
std::vector<ll> primes;
void init_factors(ll n){
	factor[0] = 0;
	factor[1] = 0;
	for (ll i = 2; i <= n; i++) {
		if (!factor[i]) {
			factor[i] = 1;
			primes.push_back(i);
		}
		for (auto j : primes) {
			if (i * j > n)break;
			factor[i * j] = factor[i] + factor[j];		//�����Ӹ���
			if (i % j == 0)break;
		}
	}
}
