template <class Abel> struct UnionFind2 {
    vector<ll> par, rank, link;
    vector<Abel> dif_weight;
    UnionFind2(int n = 1, Abel SUM_UNIT = 0) {
        par.resize(n);
        rank.resize(n);
        dif_weight.resize(n);
        link.resize(n);
        for (int i = 0; i < n; i++) {
            par[i]        = i;
            rank[i]       = 0;
            link[i]       = 1;
            dif_weight[i] = SUM_UNIT;
        }
    }
    Abel weight(int i) {
        root(i);
        return dif_weight[i];
    }
    int linksum(int i) { return link[root(i)]; }
    bool merge(int x, int y, Abel w) {
        w += dif_weight[x];
        w -= dif_weight[y];
        x = root(x), y = root(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y), w = -w;
        link[x] += link[y];
        if (rank[x] == rank[y]) ++rank[x];
        par[y]        = x;
        dif_weight[y] = w;
        return true;
    }
    bool isSame(int x, int y) { return root(x) == root(y); }
    int root(int x) {
        if (x == par[x])
            return x;
        else {
            int r = root(par[x]);
            dif_weight[x] += dif_weight[par[x]];
            return par[x] = r;
        }
    }
    Abel dif(int x, int y) { return dif_weight[y] - dif_weight[x]; }
};