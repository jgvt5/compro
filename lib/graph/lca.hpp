#include <bits/stdc++.h>

class LCA {
  private:
	int n, k, root;
	std::vector<std::vector<int>> g;
	std::vector<std::vector<int>> parent;
	std::vector<int> depth;

  public:
	LCA(int n, int root) : n(n), root(root) {
		k = 1;
		for (int i = 1; i < n; i *= 2) { k++; }
		g.resize(n);
		depth.resize(n);
		parent.resize(k);
		for (int i = 0; i < k; i++) { parent[i].resize(n); }
	}
	void setGraph(int i, int j) {
		g[i].push_back(j);
		g[j].push_back(i);
	}
	void dfs(int v, int p, int d) {
		parent[0][v] = p;
		depth[v]	 = d;
		for (int i = 0; i < g[v].size(); i++) {
			if (g[v][i] != p) dfs(g[v][i], v, d + 1);
		}
	}
	void init() {
		dfs(root, -1, 0);
		for (int i = 0; i < k - 1; i++) {
			for (int j = 0; j < n; j++) {
				if (parent[i][j] < 0)
					parent[i + 1][j] = -1;
				else
					parent[i + 1][j] = parent[i][parent[i][j]];
			}
		}
	}
	int lca(int u, int v) {
		if (depth[u] > depth[v]) std::swap(u, v);
		for (int i = 0; i < k; i++) {
			if ((depth[v] - depth[u]) >> i & 1) { v = parent[i][v]; }
		}
		if (u == v) return u;
		for (int i = k - 1; i >= 0; i--) {
			if (parent[i][u] != parent[i][v]) {
				u = parent[i][u];
				v = parent[i][v];
			}
		}
		return parent[0][u];
	}
	int dif(int u, int v) {
		int p = lca(u, v);
		int d = depth[u] + depth[v] - 2 * depth[p];
		return d;
	}
};