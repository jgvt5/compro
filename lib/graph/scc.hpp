#include <bits/stdc++.h>

class SCC {
  private:
	int n;
	std::vector<bool> used;
	std::vector<std::vector<int>> G, rG;

	void dfs(int v) {
		used[v] = true;
		for (int i = 0; i < G[v].size(); i++) {
			if (!used[G[v][i]]) dfs(G[v][i]);
		}
		vs.push_back(v);
	}
	void rdfs(int v, int k) {
		used[v] = true;
		cmp[v]  = k;
		for (int i = 0; i < rG[v].size(); i++) {
			if (!used[rG[v][i]]) rdfs(rG[v][i], k);
		}
	}

  public:
	std::vector<int> vs, cmp;
	SCC(int n) : n(n) {
		used.resize(n, false);
		G.resize(n);
		rG.resize(n);
		cmp.resize(n);
	}
	void add_edge(int u, int v) {
		G[u].push_back(v);
		rG[v].push_back(u);
	}
	int scc() {
		fill(used.begin(), used.end(), false);
		vs.clear();
		for (int i = 0; i < n; i++) {
			if (!used[i]) dfs(i);
		}
		int k = 0;
		fill(used.begin(), used.end(), false);
		for (int i = vs.size() - 1; i >= 0; i--) {
			if (!used[vs[i]]) rdfs(vs[i], k++);
		}
		return k;
	}
};
