#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
using P		 = pair<ll, ll>;
const ll INF = 1e16;
template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val) {
	fill((T *)array, (T *)(array + N), val);
}

struct edge {
	ll to, cost;
};

int n;
ll d[364364];
vector<edge> g[364364];

ll dijkstra(int s, int t) { //sからtへの最短距離
	priority_queue<P, vector<P>, greater<P>> que;
	Fill(d, INF);
	d[s] = 0;
	que.push(P(0, s));

	while (!que.empty()) {
		P now = que.top();
		que.pop();
		int v = now.second;
		if (d[v] < now.first) continue;
		for (int i = 0; i < g[v].size(); i++) {
			edge e = g[v][i];
			if (d[e.to] > d[v] + e.cost) {
				d[e.to] = d[v] + e.cost;
				que.push(P(d[e.to], e.to));
			}
		}
	}
	return d[t];
}
