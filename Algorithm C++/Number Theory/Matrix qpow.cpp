#include <algorithm>
#include <cstring>

typedef long long ll;
const int MAX_SIZE = 105;
const ll MOD = 1e9 + 7;

struct Matrix {
	ll num[MAX_SIZE][MAX_SIZE];
	int size;
	Matrix(int n = 0) {
		memset(num, 0, sizeof(num));
		size = n;
	}
	Matrix operator *(const Matrix& x) const {
		Matrix ans(x.size);
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				for (int k = 0; k < size; k++) {
					ans.num[i][j] = (ans.num[i][j] + num[i][k] * x.num[k][j]) % MOD;
				}
			}
		}
		return ans;
	}
};

ll matrix_qpow(Matrix a, ll n) {
	Matrix res(a.size);
	while (n) {
		if (n & 1)res = res * a;
		a = a * a;
		n >>= 1;
	}
	return res.num[0][0];
}
