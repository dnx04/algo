vector<int> DomTree(const vector<vi>& g, int s) {
  int n = len(g), t = 0;
  vector<int> arr(n, -1), rev(n), par(n), sdom(n), dom(n), dsu(n), lab(n), res(n, -1);
  vector<vi> rg(n), buck(n);
  auto dfs = [&](auto&& self, int u) -> void {
    arr[u] = t, rev[t] = u, lab[t] = sdom[t] = dsu[t] = t, t++;
    for (int v : g[u]) {
      if (arr[v] == -1) self(self, v), par[arr[v]] = arr[u];
      rg[arr[v]].pb(arr[u]);
    }
  };
  dfs(dfs, s);
  auto find = [&](auto&& self, int u) -> int {
    if (u == dsu[u]) return u;
    int v = self(self, dsu[u]);
    if (sdom[lab[dsu[u]]] < sdom[lab[u]]) lab[u] = lab[dsu[u]];
    return dsu[u] = v;
  };
  for (int i = t - 1; i; --i) {
    for (int v : rg[i]) find(find, v), sdom[i] = min(sdom[i], sdom[lab[v]]);
    buck[sdom[i]].pb(i);
    int p = par[i];
    dsu[i] = p;
    for (int v : buck[p]) find(find, v), dom[v] = (sdom[lab[v]] == sdom[v] ? p : lab[v]);
    buck[p].clear();
  }
  for (int i = 1; i < t; ++i) {
    if (dom[i] != sdom[i]) dom[i] = dom[dom[i]];
    res[rev[i]] = rev[dom[i]];
  }
  return res;
}