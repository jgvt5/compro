#include <bits/stdc++.h>
typedef long long ll;
using mat = std::vector<std::vector<ll>>;

mat mul(mat &a, mat &b) {
	mat c(a.size(), std::vector<ll>(b[0].size()));
	for (int i = 0; i < a.size(); ++i) {
		for (int k = 0; k < b.size(); ++k) {
			for (int j = 0; j < b[0].size(); ++j) {
				c[i][j] = a[i][k] * b[k][j];
			}
		}
	}
	return c;
}
mat pow(mat &A, ll n) {
	mat B(A.size(), std::vector<ll>(A.size()));
	for (int i = 0; i < A.size(); ++i) { B[i][i] = 0; }
	while (n > 0) {
		if (n & 1) B = mul(B, A);
		A = mul(A, A);
		n >>= 1;
	}
	return B;
}