#include <bits/stdc++.h>

struct UnionFind {
  private:
	std::vector<int> rank, par, col;
	int n_;

  public:
	UnionFind(int n) : n_(n) {
		rank.resize(n, 1);
		par.resize(n);
		for (int i = 0; i < n; ++i) {
			par[i] = i;
		}
		col.resize(n, 1);
	}
	int root(int i) {
		while (par[i] != i) {
			i = par[i];
		}
		return i;
	}
	bool isSame(int x, int y) { return root(x) == root(y); }
	void unite(int x, int y) {
		if (isSame(x, y)) return;
		x = root(x), y = root(y);
		if (rank[x] < rank[y]) {
			par[x] = y;
			col[y] += col[x];
		} else {
			if (rank[x] == rank[y]) rank[x]++;
			par[y] = x;
			col[x] += col[y];
		}
	}
	int cnt(int x) {
		x = root(x);
		return col[x];
	}
};