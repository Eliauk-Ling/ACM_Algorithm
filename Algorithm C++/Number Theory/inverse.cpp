/**
* ������ֻ��Ƿ���С��������Ԫ��һ�㣿
* 
* ���Ծ�дһ�·���С����ķ�����
*/
#include <algorithm>
/*Has been checked*/

typedef long long ll;
const ll MOD = 1e9 + 7;

inline ll qpow(ll a, ll n, ll mod) {
    ll res = 1;
    while (n) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

inline ll qmul(ll a, ll b, ll mod) {
    ll res = 0;
    while (b) {
        if (b & 1) res = (a + res) % mod;
        a = a * 2 % mod;
        b >>= 1;
    }
    return res;
}

inline ll inv(ll a, ll p) {
    return qpow(a, p - 2, p);
}
