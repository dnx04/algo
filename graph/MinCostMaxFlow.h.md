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
  bundledCode: "#line 1 \"graph/MinCostMaxFlow.h\"\nconst ll INF = numeric_limits<ll>::max()\
    \ / 4;\n\nstruct MCMF {\n  struct edge {\n    int from, to, rev;\n    ll cap,\
    \ cost, flow;\n  };\n  int N;\n  vector<vector<edge>> ed;\n  vi seen;\n  vector<ll>\
    \ dist, pi;\n  vector<edge*> par;\n\n  MCMF(int N) : N(N), ed(N), seen(N), dist(N),\
    \ pi(N), par(N) {}\n\n  void addEdge(int from, int to, ll cap, ll cost) {\n  \
    \  if (from == to) return;\n    ed[from].push_back(edge{from, to, sz(ed[to]),\
    \ cap, cost, 0});\n    ed[to].push_back(edge{to, from, sz(ed[from]) - 1, 0, -cost,\
    \ 0});\n  }\n\n  void path(int s) {\n    fill(all(seen), 0);\n    fill(all(dist),\
    \ INF);\n    dist[s] = 0;\n    ll di;\n\n    __gnu_pbds::priority_queue<pair<ll,\
    \ int>> q;\n    vector<decltype(q)::point_iterator> its(N);\n    q.push({0, s});\n\
    \n    while (!q.empty()) {\n      s = q.top().second;\n      q.pop();\n      seen[s]\
    \ = 1;\n      di = dist[s] + pi[s];\n      for (edge& e : ed[s]) {\n        if\
    \ (!seen[e.to]) {\n          ll val = di - pi[e.to] + e.cost;\n          if (e.cap\
    \ - e.flow > 0 && val < dist[e.to]) {\n            dist[e.to] = val;\n       \
    \     par[e.to] = &e;\n            if (its[e.to] == q.end())\n              its[e.to]\
    \ = q.push({-dist[e.to], e.to});\n            else\n              q.modify(its[e.to],\
    \ {-dist[e.to], e.to});\n          }\n        }\n      }\n    }\n    for (int\
    \ i = 0; i < N; ++i) pi[i] = min(pi[i] + dist[i], INF);\n  }\n\n  pair<ll, ll>\
    \ maxflow(int s, int t) {\n    ll totflow = 0, totcost = 0;\n    while (path(s),\
    \ seen[t]) {\n      ll fl = INF;\n      for (edge* x = par[t]; x; x = par[x->from])\n\
    \        fl = min(fl, x->cap - x->flow);\n\n      totflow += fl;\n      for (edge*\
    \ x = par[t]; x; x = par[x->from]) {\n        x->flow += fl;\n        ed[x->to][x->rev].flow\
    \ -= fl;\n      }\n    }\n    for (int i = 0; i < N; ++i)\n      for (edge& e\
    \ : ed[i]) totcost += e.cost * e.flow;\n    return {totflow, totcost / 2};\n \
    \ }\n\n  // If some costs can be negative, call this before maxflow:\n  void setpi(int\
    \ s) {  // (otherwise, leave this out)\n    fill(all(pi), INF);\n    pi[s] = 0;\n\
    \    int it = N, ch = 1;\n    ll v;\n    while (ch-- && it--) {\n      for (int\
    \ i = 0; i < N; ++i) {\n        if (pi[i] != INF) {\n          for (edge& e :\
    \ ed[i]) {\n            if (e.cap) {\n              if ((v = pi[i] + e.cost) <\
    \ pi[e.to]) pi[e.to] = v, ch = 1;\n            }\n          }\n        }\n   \
    \   }\n    }\n    assert(it >= 0);  // negative cost cycle\n  }\n};\n"
  code: "const ll INF = numeric_limits<ll>::max() / 4;\n\nstruct MCMF {\n  struct\
    \ edge {\n    int from, to, rev;\n    ll cap, cost, flow;\n  };\n  int N;\n  vector<vector<edge>>\
    \ ed;\n  vi seen;\n  vector<ll> dist, pi;\n  vector<edge*> par;\n\n  MCMF(int\
    \ N) : N(N), ed(N), seen(N), dist(N), pi(N), par(N) {}\n\n  void addEdge(int from,\
    \ int to, ll cap, ll cost) {\n    if (from == to) return;\n    ed[from].push_back(edge{from,\
    \ to, sz(ed[to]), cap, cost, 0});\n    ed[to].push_back(edge{to, from, sz(ed[from])\
    \ - 1, 0, -cost, 0});\n  }\n\n  void path(int s) {\n    fill(all(seen), 0);\n\
    \    fill(all(dist), INF);\n    dist[s] = 0;\n    ll di;\n\n    __gnu_pbds::priority_queue<pair<ll,\
    \ int>> q;\n    vector<decltype(q)::point_iterator> its(N);\n    q.push({0, s});\n\
    \n    while (!q.empty()) {\n      s = q.top().second;\n      q.pop();\n      seen[s]\
    \ = 1;\n      di = dist[s] + pi[s];\n      for (edge& e : ed[s]) {\n        if\
    \ (!seen[e.to]) {\n          ll val = di - pi[e.to] + e.cost;\n          if (e.cap\
    \ - e.flow > 0 && val < dist[e.to]) {\n            dist[e.to] = val;\n       \
    \     par[e.to] = &e;\n            if (its[e.to] == q.end())\n              its[e.to]\
    \ = q.push({-dist[e.to], e.to});\n            else\n              q.modify(its[e.to],\
    \ {-dist[e.to], e.to});\n          }\n        }\n      }\n    }\n    for (int\
    \ i = 0; i < N; ++i) pi[i] = min(pi[i] + dist[i], INF);\n  }\n\n  pair<ll, ll>\
    \ maxflow(int s, int t) {\n    ll totflow = 0, totcost = 0;\n    while (path(s),\
    \ seen[t]) {\n      ll fl = INF;\n      for (edge* x = par[t]; x; x = par[x->from])\n\
    \        fl = min(fl, x->cap - x->flow);\n\n      totflow += fl;\n      for (edge*\
    \ x = par[t]; x; x = par[x->from]) {\n        x->flow += fl;\n        ed[x->to][x->rev].flow\
    \ -= fl;\n      }\n    }\n    for (int i = 0; i < N; ++i)\n      for (edge& e\
    \ : ed[i]) totcost += e.cost * e.flow;\n    return {totflow, totcost / 2};\n \
    \ }\n\n  // If some costs can be negative, call this before maxflow:\n  void setpi(int\
    \ s) {  // (otherwise, leave this out)\n    fill(all(pi), INF);\n    pi[s] = 0;\n\
    \    int it = N, ch = 1;\n    ll v;\n    while (ch-- && it--) {\n      for (int\
    \ i = 0; i < N; ++i) {\n        if (pi[i] != INF) {\n          for (edge& e :\
    \ ed[i]) {\n            if (e.cap) {\n              if ((v = pi[i] + e.cost) <\
    \ pi[e.to]) pi[e.to] = v, ch = 1;\n            }\n          }\n        }\n   \
    \   }\n    }\n    assert(it >= 0);  // negative cost cycle\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/MinCostMaxFlow.h
  requiredBy: []
  timestamp: '2025-11-15 18:26:28+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/MinCostMaxFlow.h
layout: document
redirect_from:
- /library/graph/MinCostMaxFlow.h
- /library/graph/MinCostMaxFlow.h.html
title: graph/MinCostMaxFlow.h
---
