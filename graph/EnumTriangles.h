template <typename F>
void EnumTriangles(int n, const vector<pii>& ed, F f) {  // 0-indexed graph
  vi deg(n);
  for (auto [u, v] : ed) ++deg[u], ++deg[v];
  vector<vi> g(n);  // directed
  for (auto& e : ed) {
    auto [u, v] = e;
    if (tie(deg[u], u) > tie(deg[v], v)) swap(u, v);
    g[u].eb(v);
  }
  vector<bool> adj(n);
  for (auto& [u, v] : ed) {
    for (auto nu : g[u]) adj[nu] = true;
    for (auto nv : g[v]) {
      if (adj[nv]) f(u, v, nv);
    }
    for (auto nu : g[u]) adj[nu] = false;
  }
}