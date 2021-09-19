/**
 * Miller Rabin素性检验  时间复杂度为 \theta(T×logN) 级别
 *
 * 其中 T 为测试的次数，此模板中为20
 *
 * N 为判断的数
 *
 * 由于此算法为概率算法，因此是存在误判的，误判的概率为 1/4^T
 * 因此当T较大时可视为完备算法
 *
 * 需要头文件 #include <cmath>
 **/
typedef long long ll;

const ll MOD = 1e9 + 7;
ll qpow(ll a, ll n, ll mod) {
  ll res = 1;
  while (n) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

ll qmul(ll a, ll b, ll mod) {
  ll res = 0;
  while (b) {
    if (b & 1) res = (a + res) % mod;
    a = a * 2 % mod;
    b >>= 1;
  }
  return res;
}

bool Miller_Rabin(ll n) {
  if (n == 2) return true;
  if (!(n & 1) || n < 2) return false;
  ll s = 0, t = n - 1;
  while (!(t & 1)) {
    s++;
    t >>= 1;
  }
  for (int i = 0; i < 20; i++) {
    ll a = rand() % (n - 1) + 1;
    ll x = qpow(a, t, n);
    for (int j = 1; j <= s; j++) {
      ll test = qmul(x, x, n);
      if (test == 1 && x != 1 && x != n - 1) return false;
      x = test;
    }
    if (x != 1) return false;
  }
  return true;
}