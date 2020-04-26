#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

ll mod(ll a) {
	if (a > 0) return a % MOD;
	if (a % MOD == 0) return 0;
	ll x = -a / MOD + 1;
	a += x * MOD;
	return a % MOD;
}

ll powm(ll a, ll b, ll c) {
	if (b == 0)
		return 1;
	else if (b % 2 == 0) {
		ll d = powm(a, b / 2, c);
		return (d * d) % c;
	} else
		return (a * powm(a, b - 1, c)) % c;
}

ll powx(ll a, ll b) {
	if (b == 0)
		return 1;
	else if (b % 2 == 0) {
		ll d = powx(a, b / 2);
		return d * d;
	} else {
		return (a * powx(a, b - 1));
	}
}

ll pas[10000][10000] = {};

void setpascal(int n) {
	pas[0][0] = 1;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) {
				pas[i][j] = 1;
			} else
				pas[i][j] = pas[i - 1][j - 1] + pas[i - 1][j];
		}
	}
}

ll part[10000][10000] = {};

void setpart(int n, int m) { //mのn分割数
	part[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			part[i][j] = part[i - 1][j];
			if (i <= j) part[i][j] += part[i][j - i];
			part[i][j] %= MOD;
		}
	}
}

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

vector<ll> divis(ll n) {
	vector<ll> ret;
	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			ret.push_back(i);
			if (i != n / i) ret.push_back(n / i);
		}
	}
	return ret;
}

vector<ll> pfact(ll n) {
	vector<ll> ret;
	for (ll i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			ret.push_back(i);
			while (n % i == 0) n /= i;
		}
	}
	if (n != 1) ret.push_back(n);
	return ret;
}

ll digitsum(ll a) {
	int sum = 0;
	while (a) {
		sum += a % 10;
		a /= 10;
	}
	return sum;
}

int countpow(ll a, ll b) {
	int ans = 0;
	if (b == 0) return -1;
	while (1) {
		if (a % b == 0) {
			a /= b;
			ans++;
		} else
			break;
	}
	return ans;
}
