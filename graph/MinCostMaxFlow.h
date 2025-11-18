const i64 INF = numeric_limits<i64>::max() / 4;

struct MCMF {
  struct edge {
    int from, to, rev;
    i64 cap, cost, flow;
  };
  int N;
  vector<vector<edge>> ed;
  vi seen;
  vector<i64> dist, pi;
  vector<edge*> par;

  MCMF(int N) : N(N), ed(N), seen(N), dist(N), pi(N), par(N) {}

  void addEdge(int from, int to, i64 cap, i64 cost) {
    if (from == to) return;
    ed[from].push_back(edge{from, to, sz(ed[to]), cap, cost, 0});
    ed[to].push_back(edge{to, from, sz(ed[from]) - 1, 0, -cost, 0});
  }

  void path(int s) {
    fill(all(seen), 0);
    fill(all(dist), INF);
    dist[s] = 0;
    i64 di;

    __gnu_pbds::priority_queue<pair<i64, int>> q;
    vector<decltype(q)::point_iterator> its(N);
    q.push({0, s});

    while (!q.empty()) {
      s = q.top().second;
      q.pop();
      seen[s] = 1;
      di = dist[s] + pi[s];
      for (edge& e : ed[s]) {
        if (!seen[e.to]) {
          i64 val = di - pi[e.to] + e.cost;
          if (e.cap - e.flow > 0 && val < dist[e.to]) {
            dist[e.to] = val;
            par[e.to] = &e;
            if (its[e.to] == q.end())
              its[e.to] = q.push({-dist[e.to], e.to});
            else
              q.modify(its[e.to], {-dist[e.to], e.to});
          }
        }
      }
    }
    for (int i = 0; i < N; ++i) pi[i] = min(pi[i] + dist[i], INF);
  }

  pair<i64, i64> maxflow(int s, int t) {
    i64 totflow = 0, totcost = 0;
    while (path(s), seen[t]) {
      i64 fl = INF;
      for (edge* x = par[t]; x; x = par[x->from])
        fl = min(fl, x->cap - x->flow);

      totflow += fl;
      for (edge* x = par[t]; x; x = par[x->from]) {
        x->flow += fl;
        ed[x->to][x->rev].flow -= fl;
      }
    }
    for (int i = 0; i < N; ++i)
      for (edge& e : ed[i]) totcost += e.cost * e.flow;
    return {totflow, totcost / 2};
  }

  // If some costs can be negative, call this before maxflow:
  void setpi(int s) {  // (otherwise, leave this out)
    fill(all(pi), INF);
    pi[s] = 0;
    int it = N, ch = 1;
    i64 v;
    while (ch-- && it--) {
      for (int i = 0; i < N; ++i) {
        if (pi[i] != INF) {
          for (edge& e : ed[i]) {
            if (e.cap) {
              if ((v = pi[i] + e.cost) < pi[e.to]) pi[e.to] = v, ch = 1;
            }
          }
        }
      }
    }
    assert(it >= 0);  // negative cost cycle
  }
};