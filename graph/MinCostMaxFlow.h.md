---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/MinCostMaxFlow.h\"\nconst i64 INF = numeric_limits<i64>::max()\
    \ / 4;\n\nstruct MCMF {\n  struct edge { int u, v, rev; i64 cap, cost, flow; };\n\
    \  int N;\n  vector<vector<edge>> ed;\n  vi seen;\n  vector<i64> dist, pi;\n \
    \ vector<edge*> par;\n\n  MCMF(int N) : N(N), ed(N), seen(N), dist(N), pi(N),\
    \ par(N) {}\n\n  void addEdge(int u, int v, i64 cap, i64 cost) {\n    if (u ==\
    \ v) return;\n    ed[u].pb({u, v, sz(ed[v]), cap, cost, 0});\n    ed[v].pb({v,\
    \ u, sz(ed[u]) - 1, 0, -cost, 0});\n  }\n\n  void path(int s) {\n    fill(all(seen),\
    \ 0); fill(all(dist), INF); dist[s] = 0;\n    using P = pair<i64, int>;\n    __gnu_pbds::priority_queue<P,\
    \ greater<P>, __gnu_pbds::pairing_heap_tag> q;\n    vector<decltype(q)::point_iterator>\
    \ its(N, q.end());\n    its[s] = q.push({0, s});\n    while (!q.empty()) {\n \
    \     int u = q.top().second; q.pop();\n      seen[u] = 1;\n      for (edge& e\
    \ : ed[u]) {\n        i64 val = dist[u] + pi[u] - pi[e.v] + e.cost;\n        if\
    \ (!seen[e.v] && e.cap - e.flow > 0 && val < dist[e.v]) {\n          dist[e.v]\
    \ = val, par[e.v] = &e;\n          if (its[e.v] == q.end()) its[e.v] = q.push({val,\
    \ e.v});\n          else q.modify(its[e.v], {val, e.v});\n        }\n      }\n\
    \    }\n    for (int i = 0; i < N; ++i) if (dist[i] != INF) pi[i] += dist[i];\n\
    \  }\n\n  pair<i64, i64> maxflow(int s, int t) {\n    i64 totflow = 0, totcost\
    \ = 0;\n    while (path(s), seen[t]) {\n      i64 fl = INF;\n      for (edge*\
    \ x = par[t]; x; x = par[x->u]) fl = min(fl, x->cap - x->flow);\n      totflow\
    \ += fl;\n      for (edge* x = par[t]; x; x = par[x->u]) x->flow += fl, ed[x->v][x->rev].flow\
    \ -= fl;\n    }\n    for (int i = 0; i < N; ++i) for (edge& e : ed[i]) totcost\
    \ += e.cost * e.flow;\n    return {totflow, totcost / 2};\n  }\n\n  void setpi(int\
    \ s) {\n    fill(all(pi), INF); pi[s] = 0;\n    int it = N, ch = 1;\n    while\
    \ (ch-- && it--)\n      for (int i = 0; i < N; ++i) if (pi[i] != INF)\n      \
    \  for (edge& e : ed[i]) if (e.cap && pi[i] + e.cost < pi[e.v])\n          pi[e.v]\
    \ = pi[i] + e.cost, ch = 1;\n    assert(it >= 0);\n  }\n};\n"
  code: "const i64 INF = numeric_limits<i64>::max() / 4;\n\nstruct MCMF {\n  struct\
    \ edge { int u, v, rev; i64 cap, cost, flow; };\n  int N;\n  vector<vector<edge>>\
    \ ed;\n  vi seen;\n  vector<i64> dist, pi;\n  vector<edge*> par;\n\n  MCMF(int\
    \ N) : N(N), ed(N), seen(N), dist(N), pi(N), par(N) {}\n\n  void addEdge(int u,\
    \ int v, i64 cap, i64 cost) {\n    if (u == v) return;\n    ed[u].pb({u, v, sz(ed[v]),\
    \ cap, cost, 0});\n    ed[v].pb({v, u, sz(ed[u]) - 1, 0, -cost, 0});\n  }\n\n\
    \  void path(int s) {\n    fill(all(seen), 0); fill(all(dist), INF); dist[s] =\
    \ 0;\n    using P = pair<i64, int>;\n    __gnu_pbds::priority_queue<P, greater<P>,\
    \ __gnu_pbds::pairing_heap_tag> q;\n    vector<decltype(q)::point_iterator> its(N,\
    \ q.end());\n    its[s] = q.push({0, s});\n    while (!q.empty()) {\n      int\
    \ u = q.top().second; q.pop();\n      seen[u] = 1;\n      for (edge& e : ed[u])\
    \ {\n        i64 val = dist[u] + pi[u] - pi[e.v] + e.cost;\n        if (!seen[e.v]\
    \ && e.cap - e.flow > 0 && val < dist[e.v]) {\n          dist[e.v] = val, par[e.v]\
    \ = &e;\n          if (its[e.v] == q.end()) its[e.v] = q.push({val, e.v});\n \
    \         else q.modify(its[e.v], {val, e.v});\n        }\n      }\n    }\n  \
    \  for (int i = 0; i < N; ++i) if (dist[i] != INF) pi[i] += dist[i];\n  }\n\n\
    \  pair<i64, i64> maxflow(int s, int t) {\n    i64 totflow = 0, totcost = 0;\n\
    \    while (path(s), seen[t]) {\n      i64 fl = INF;\n      for (edge* x = par[t];\
    \ x; x = par[x->u]) fl = min(fl, x->cap - x->flow);\n      totflow += fl;\n  \
    \    for (edge* x = par[t]; x; x = par[x->u]) x->flow += fl, ed[x->v][x->rev].flow\
    \ -= fl;\n    }\n    for (int i = 0; i < N; ++i) for (edge& e : ed[i]) totcost\
    \ += e.cost * e.flow;\n    return {totflow, totcost / 2};\n  }\n\n  void setpi(int\
    \ s) {\n    fill(all(pi), INF); pi[s] = 0;\n    int it = N, ch = 1;\n    while\
    \ (ch-- && it--)\n      for (int i = 0; i < N; ++i) if (pi[i] != INF)\n      \
    \  for (edge& e : ed[i]) if (e.cap && pi[i] + e.cost < pi[e.v])\n          pi[e.v]\
    \ = pi[i] + e.cost, ch = 1;\n    assert(it >= 0);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/MinCostMaxFlow.h
  requiredBy: []
  timestamp: '2025-11-28 10:18:48+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/MinCostMaxFlow.h
layout: document
redirect_from:
- /library/graph/MinCostMaxFlow.h
- /library/graph/MinCostMaxFlow.h.html
title: graph/MinCostMaxFlow.h
---
