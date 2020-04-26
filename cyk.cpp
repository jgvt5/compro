#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using P	  = pair<ll, ll>;
using mat = vector<vector<ll>>;
typedef string::const_iterator State;
class ParseError {};

void IOS() { ios::sync_with_stdio(false), cin.tie(0); }

constexpr ll INF = 1e16;
constexpr ll INM = 114514;
constexpr ll MOD = 1e9 + 7;
constexpr ld EPS = 1e-12;

template <typename T>
void dump(T x) { cout << x << endl; }
void dumpf(ld x, int t) { cout << setprecision(t) << fixed << x << endl; }
template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val) {
	fill((T *)array, (T *)(array + N), val);
}
inline ll mod(ll a, ll b) {
	if (a > 0) return a % b;
	if (a % b == 0) return 0;
	ll x = -a / b + 1;
	a += x * b;
	return a % b;
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
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll dx[4] = {1, 0, -1, 0};
ll dy[4] = {0, 1, 0, -1};

set<int> x[100][100];

set<int> unzipChar[100];
set<int> unzipVar[100][100];

int main() {
	IOS();
	string target;
	int n, count = 0;
	cin >> n;
	map<char, int> mp;
	char start;
	for (int i = 0; i < n; i++) {
		char from;
		string to;
		cin >> from >> to;
		if (i == 0) {
			start = from;
		}
		if (mp.find(from) == mp.end()) {
			mp[from] = count;
			count++;
		}
		for (int j = 0; j < to.size(); j++) {
			if (mp.find(to[j]) == mp.end()) {
				mp[to[j]] = count;
				count++;
			}
		}
		if (to.size() == 1) {
			unzipChar[mp[to[0]]].insert(mp[from]);
		}
		if (to.size() == 2) {
			unzipVar[mp[to[0]]][mp[to[1]]].insert(mp[from]);
		}
	}
	cin >> target;
	for (int i = 0; i < target.size(); i++) {
		for (auto j : unzipChar[mp[target[i]]]) {
			x[i][i].insert(j);
		}
		cout << x[i][i].size() << " ";
	}
	cout << endl;
	for (int i = 1; i < target.size(); i++) {
		for (int j = 0; j + i < target.size(); j++) {
			for (int k = j; k < j + i; k++) {
				for (int a : x[j][k]) {
					for (int b : x[k + 1][j + i]) {
						for (int c : unzipVar[a][b]) {
							x[j][j + i].insert(c);
						}
					}
				}
			}
			cout << x[j][j + i].size() << " ";
		}
		cout << endl;
	}
	bool ans = false;
	for (auto i : x[0][target.size() - 1]) {
		ans |= i == 0;
	}

	dump(ans ? "Yes" : "No");
	return 0;
}