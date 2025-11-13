struct EdmondsKarp {
  struct Edge {
    int to, rev;
    ll c, oc;
    ll flow() { return max(oc - c, 0LL); }  // if you need flows
  };
  vector<vector<Edge>> adj;
  vector<int> par_v, par_e;
  int n;
  EdmondsKarp(int n) : adj(n), par_v(n), par_e(n), n(n) {}

  void addEdge(int a, int b, ll c, ll rcap = 0) {
    adj[a].push_back({b, (int) adj[b].size(), c, c});
    adj[b].push_back({a, (int) adj[a].size() - 1, rcap, rcap});
  }

  ll bfs(int s, int t) {
    fill(par_v.begin(), par_v.end(), -1);
    queue<int> q;
    q.push(s);
    par_v[s] = s;
    while (!q.empty() && par_v[t] == -1) {
      int v = q.front();
      q.pop();
      for (int i = 0; i < (int) adj[v].size(); i++) {
        Edge& e = adj[v][i];
        if (par_v[e.to] == -1 && e.c > 0) {
          par_v[e.to] = v;
          par_e[e.to] = i;
          q.push(e.to);
          if (e.to == t) break;
        }
      }
    }
    if (par_v[t] == -1) return 0;
    ll f = LLONG_MAX;
    for (int v = t; v != s; v = par_v[v])
      f = min(f, adj[par_v[v]][par_e[v]].c);
    for (int v = t; v != s; v = par_v[v]) {
      Edge& e = adj[par_v[v]][par_e[v]];
      e.c -= f;
      adj[v][e.rev].c += f;
    }
    return f;
  }

  ll calc(int s, int t) {
    ll flow = 0, p;
    while ((p = bfs(s, t))) flow += p;
    return flow;
  }

  bool leftOfMinCut(int a) { return par_v[a] != -1; }
};
