template <class G>
struct HLD {
  const G& g;
  int n, t = 0;
  vi sub, dep, par, head, pos, heavy;
  HLD(const G& g, int root = 0) : g(g), n(len(g)), sub(n), dep(n), par(n), head(n), pos(n), heavy(n, -1) {
    par[root] = -1;
    dfs_sub(root);
    dfs_hld(root, root);
  }
  void dfs_sub(int u) {
    sub[u] = 1;
    for (int v : g[u])
      if (v != par[u]) {
        dep[v] = dep[u] + 1, par[v] = u;
        dfs_sub(v);
        sub[u] += sub[v];
        if (heavy[u] == -1 || sub[v] > sub[heavy[u]]) heavy[u] = v;
      }
  }
  void dfs_hld(int u, int h) {
    head[u] = h, pos[u] = ++t;
    if (heavy[u] != -1) dfs_hld(heavy[u], h);
    for (int v : g[u])
      if (v != par[u] && v != heavy[u]) dfs_hld(v, v);
  }
  int idx(int u) const { return pos[u]; }
  pii query_subtree(int u) { return {pos[u], pos[u] + sub[u] - 1}; }
  vector<pii> query_path(int u, int v) {
    vector<pii> l, r;
    while (head[u] != head[v]) {
      if (dep[head[u]] > dep[head[v]]) {
        l.pb({pos[u], pos[head[u]]});
        u = par[head[u]];
      } else {
        r.pb({pos[head[v]], pos[v]});
        v = par[head[v]];
      }
    }
    if (dep[u] > dep[v])
      l.pb({pos[u], pos[v]});
    else
      r.pb({pos[u], pos[v]});
    reverse(all(r));
    l.insert(l.end(), all(r));
    return l;
  }
  int lca(int u, int v) {
    for (; head[u] != head[v]; u = par[head[u]])
      if (dep[head[u]] < dep[head[v]]) swap(u, v);
    return dep[u] < dep[v] ? u : v;
  }
};