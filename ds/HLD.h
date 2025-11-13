struct HLD {
  int n;
  vector<vi>& g;
  vi parent, head, szsub, ord;
  int timer = 0;

  HLD(vector<vi>& g) : n(g.size()), g(g), parent(n, -1), head(n), szsub(n, 1), ord(n) {
    dfs_size(0);
    head[0] = 0;
    dfs_hld(0);
  }

  template <typename F>
  void path_query(int a, int b, F f) {
    for (; head[a] != head[b]; a = parent[head[a]]) {
      if (ord[head[a]] < ord[head[b]]) swap(a, b);
      f(ord[head[a]], ord[a]);
    }
    if (ord[a] > ord[b]) swap(a, b);
    f(ord[a], ord[b]);
  }

  int pos(int x) const { return ord[x]; }
  pii subtree(int x) const { return {ord[x], ord[x] + szsub[x] - 1}; }

 private:
  void dfs_size(int u, int p = -1) {
    parent[u] = p;
    for (int& v : g[u])
      if (v != p) {
        dfs_size(v, u);
        szsub[u] += szsub[v];
        if (szsub[v] > szsub[g[u][0]] || g[u][0] == p) swap(v, g[u][0]);
      }
  }
  void dfs_hld(int u) {
    ord[u] = timer++;
    for (int v : g[u])
      if (v != parent[u]) {
        head[v] = (v == g[u][0] ? head[u] : v);
        dfs_hld(v);
      }
  }
};