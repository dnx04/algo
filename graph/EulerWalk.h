pair<vi, vi> EulerWalk(int n, vector<vector<pii>>& adj, int m, bool dir, bool cyc) {
  vi D(n), ptr(n), used(m), nodes, edges;
  vector<pii> st;
  int src = 0, bad = 0;
  for (int i = 0; i < n; ++i) {
    if (dir)
      for (auto& p : adj[i]) D[i]++, D[p.first]--;
    else
      D[i] = len(adj[i]) & 1;
  }
  for (int i = 0; i < n; ++i) {
    if (len(adj[i]) && adj[src].empty()) src = i;
    if (D[i]) {
      bad++;
      if ((dir && D[i] > 0) || (!dir)) src = i;
    }
  }
  if (bad > 2 || (cyc && bad) || (dir && bad && D[src] != 1)) return {};
  st.pb({src, -1});
  while (!st.empty()) {
    int u = st.back().first;
    if (ptr[u] < len(adj[u])) {
      auto [v, id] = adj[u][ptr[u]++];
      if (!used[id]) used[id] = 1, st.pb({v, id});
    } else {
      auto [v, id] = st.back();
      st.pop_back();
      nodes.pb(v);
      if (id != -1) edges.pb(id);
    }
  }
  if (len(edges) != m) return {};
  reverse(all(nodes)), reverse(all(edges));
  return {nodes, edges};
}