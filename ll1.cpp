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
	int n;
	cin >> n;
	map<char, vector<string>> grammer;
	map<char, bool> nullable;
	map<char, set<char>> first, follow;

	for (int i = 0; i < n; i++) {
		char a;
		string b;
		cin >> a >> b;
		if (b == "eps") {
			nullable[a] = true;
		} else {
			grammer[a].push_back(b);
		}
	}
	while (1) {
		bool update = false;
		for (auto it = grammer.begin(); it != grammer.end(); it++) {
			char a = it->first;
			if (nullable[a]) continue;
			bool ok			 = false;
			vector<string> v = it->second;
			for (int i = 0; i < v.size(); i++) {
				bool tmp = true;
				for (int j = 0; j < v[i].size(); j++) {
					tmp &= nullable[v[i][j]];
				}
				ok |= tmp;
			}
		}
		if (!update) {
			break;
		}
	}
	dump("nullables...");
	for (auto it = nullable.begin(); it != nullable.end(); it++) {
        if(it->second)cout << it->first << " ";
	}
    cout << endl;
    
	return 0;
}