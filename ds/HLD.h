template <class G>
struct HLD {
  const G& g;
  int n, t = 0;
  vi sz, dep, par, head, pos, heavy;
  HLD(const G& g, int root = 0) : g(g), n(sz(g)), sz(n), dep(n), par(n), head(n), pos(n), heavy(n, -1) {
    par[root] = -1;
    dfs_sz(root);
    dfs_hld(root, root);
  }
  void dfs_sz(int u) {
    sz[u] = 1;
    for (int v : g[u])
      if (v != par[u]) {
        dep[v] = dep[u] + 1, par[v] = u;
        dfs_sz(v);
        sz[u] += sz[v];
        if (heavy[u] == -1 || sz[v] > sz[heavy[u]]) heavy[u] = v;
      }
  }
  void dfs_hld(int u, int h) {
    head[u] = h, pos[u] = ++t;
    if (heavy[u] != -1) dfs_hld(heavy[u], h);
    for (int v : g[u])
      if (v != par[u] && v != heavy[u]) dfs_hld(v, v);
  }
  pii query_subtree(int u) { return {pos[u], pos[u] + sz[u] - 1}; }
  // Trả về vector các đoạn [L, R].
  // L > R: đi lên (u -> LCA). L <= R: đi xuống (LCA -> v).
  vector<pii> query_path(int u, int v) {
    vector<pii> l, r;
    for (; head[u] != head[v]; u = par[head[u]]) {
      if (dep[head[u]] > dep[head[v]]) l.pb({pos[u], pos[head[u]]});
      else r.pb({pos[head[v]], pos[v]}), v = par[head[v]];
    }
    if (dep[u] > dep[v]) l.pb({pos[u], pos[v]});
    else r.pb({pos[u], pos[v]});
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