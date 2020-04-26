#include <bits/stdc++.h>

struct edge {
	int to, cap, rev;
};

class Flow {
	int n;
	std::vector<std::vector<edge>> G;
	std::vector<int> level, iter;

	void bfs(int s) {
		fill(level.begin(), level.end(), -1);
		std::queue<int> que;
		level[s] = 0;
		que.push(s);
		while (!que.empty()) {
			int v = que.front();
			que.pop();
			for (int i = 0; i < G[v].size(); i++) {
				edge &e = G[v][i];
				if (e.cap > 0 && level[e.to] < 0) {
					level[e.to] = level[v] + 1;
					que.push(e.to);
				}
			}
		}
	}
	int dfs(int v, int t, int f) {
		if (v == t) return f;
		for (int &i = iter[v]; i < G[v].size(); i++) {
			edge &e = G[v][i];
			if (level[v] < level[e.to] && e.cap > 0) {
				int d = dfs(e.to, t, std::min(f, e.cap));
				if (d > 0) {
					e.cap -= d;
					G[e.to][e.rev].cap += d;
					return d;
				}
			}
		}
		return 0;
	}

  public:
	Flow(int n) : n(n) {
		G.resize(n);
		level.resize(n);
		iter.resize(n);
	}
	void add_edge(int from, int to, int cap) {
		G[from].push_back((edge){to, cap, (int)G[to].size()});
		G[to].push_back((edge){from, 0ll, (int)G[from].size() - 1});
	}
	int max_flow(int s, int t) {
		int flow = 0;
		while (1) {
			bfs(s);
			if (level[t] < 0) return flow;
			fill(iter.begin(), iter.end(), 0);
			int f;
			while ((f = dfs(s, t, 1e9)) > 0) { flow += f; }
		}
	}
};