const i64 INF = numeric_limits<i64>::max() / 4;

struct MCMF {
  struct edge {
    int u, v, rev;
    i64 cap, cost, flow;
  };
  int N;
  vector<vector<edge>> ed;
  vi seen;
  vector<i64> dist, pi;
  vector<edge*> par;

  MCMF(int N) : N(N), ed(N), seen(N), dist(N), pi(N), par(N) {}

  void addEdge(int u, int v, i64 cap, i64 cost) {
    if (u == v) return;
    ed[u].pb({u, v, len(ed[v]), cap, cost, 0});
    ed[v].pb({v, u, len(ed[u]) - 1, 0, -cost, 0});
  }

  void path(int s) {
    fill(all(seen), 0);
    fill(all(dist), INF);
    dist[s] = 0;
    using P = pair<i64, int>;
    __gnu_pbds::priority_queue<P, greater<P>, __gnu_pbds::pairing_heap_tag> q;
    vector<decltype(q)::point_iterator> its(N, q.end());
    its[s] = q.push({0, s});
    while (!q.empty()) {
      int u = q.top().second;
      q.pop();
      seen[u] = 1;
      for (edge& e : ed[u]) {
        i64 val = dist[u] + pi[u] - pi[e.v] + e.cost;
        if (!seen[e.v] && e.cap - e.flow > 0 && val < dist[e.v]) {
          dist[e.v] = val, par[e.v] = &e;
          if (its[e.v] == q.end())
            its[e.v] = q.push({val, e.v});
          else
            q.modify(its[e.v], {val, e.v});
        }
      }
    }
    for (int i = 0; i < N; ++i)
      if (dist[i] != INF) pi[i] += dist[i];
  }

  pair<i64, i64> maxflow(int s, int t) {
    i64 totflow = 0, totcost = 0;
    while (path(s), seen[t]) {
      i64 fl = INF;
      for (edge* x = par[t]; x; x = par[x->u]) fl = min(fl, x->cap - x->flow);
      totflow += fl;
      for (edge* x = par[t]; x; x = par[x->u]) x->flow += fl, ed[x->v][x->rev].flow -= fl;
    }
    for (int i = 0; i < N; ++i)
      for (edge& e : ed[i]) totcost += e.cost * e.flow;
    return {totflow, totcost / 2};
  }

  void setpi(int s) {
    fill(all(pi), INF);
    pi[s] = 0;
    int it = N, ch = 1;
    while (ch-- && it--)
      for (int i = 0; i < N; ++i)
        if (pi[i] != INF)
          for (edge& e : ed[i])
            if (e.cap && pi[i] + e.cost < pi[e.v])
              pi[e.v] = pi[i] + e.cost, ch = 1;
    assert(it >= 0);
  }
};