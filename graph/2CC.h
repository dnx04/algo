struct BCC {
  const vector<vi>& g;
  int n, ti = 0;
  vector<vi> tree, blks;
  vi tin, low, st;
  void dfs(int u, int p = -1) {
    tin[u] = low[u] = ++ti;
    st.pb(u);
    for (int v : g[u])
      if (v != p) {
        if (tin[v])
          low[u] = min(low[u], tin[v]);
        else {
          dfs(v, u);
          low[u] = min(low[u], low[v]);
          if (low[v] >= tin[u]) {
            blks.pb({u});
            for (int x = -1; x != v; st.pop_back()) blks.back().pb(x = st.back());
          }
        }
      }
  }
  BCC(const vector<vi>& G) : g(G), n(len(G)), tin(n), low(n) {
    for (int i = 0; i < n; ++i)
      if (!tin[i]) {
        dfs(i);
        if (g[i].empty()) blks.pb({i});
      }
    tree.assign(n + len(blks), {});
    for (int i = 0; i < len(blks); ++i) {
      int bid = n + i;
      for (int u : blks[i]) tree[bid].pb(u), tree[u].pb(bid);
    }
  }
};

struct ECC {
  const vector<vi>& g;
  int n, ti = 0;
  vector<vi> tree, comps;
  vi tin, low, id, st;
  void dfs(int u, int p = -1) {
    tin[u] = low[u] = ++ti;
    st.pb(u);
    bool skipped = false;  // Fix multiple edges
    for (int v : g[u]) {
      if (v == p && !skipped) {
        skipped = true;
        continue;
      }
      if (tin[v])
        low[u] = min(low[u], tin[v]);
      else {
        dfs(v, u);
        low[u] = min(low[u], low[v]);
      }
    }
    if (low[u] == tin[u]) {  // Component root
      comps.pb({});
      for (int x = -1; x != u; st.pop_back()) {
        id[x = st.back()] = len(comps) - 1;
        comps.back().pb(x);
      }
    }
  }
  ECC(const vector<vi>& G) : g(G), n(len(G)), tin(n), low(n), id(n) {
    for (int i = 0; i < n; ++i)
      if (!tin[i]) dfs(i);
    tree.assign(len(comps), {});
    for (int u = 0; u < n; ++u)
      for (int v : g[u])
        if (id[u] != id[v]) tree[id[u]].pb(id[v]);
    for (auto& adj : tree) {
      sort(all(adj));
      adj.erase(unique(all(adj)), adj.end());
    }
  }
};