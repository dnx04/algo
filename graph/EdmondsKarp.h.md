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
  bundledCode: "#line 1 \"graph/EdmondsKarp.h\"\nstruct EdmondsKarp {\n  struct Edge\
    \ {\n    int to, rev;\n    ll c, oc;\n    ll flow() { return max(oc - c, 0LL);\
    \ }  // if you need flows\n  };\n  vector<vector<Edge>> adj;\n  vector<int> par_v,\
    \ par_e;\n  int n;\n  EdmondsKarp(int n) : adj(n), par_v(n), par_e(n), n(n) {}\n\
    \n  void addEdge(int a, int b, ll c, ll rcap = 0) {\n    adj[a].push_back({b,\
    \ (int) adj[b].size(), c, c});\n    adj[b].push_back({a, (int) adj[a].size() -\
    \ 1, rcap, rcap});\n  }\n\n  ll bfs(int s, int t) {\n    fill(par_v.begin(), par_v.end(),\
    \ -1);\n    queue<int> q;\n    q.push(s);\n    par_v[s] = s;\n    while (!q.empty()\
    \ && par_v[t] == -1) {\n      int v = q.front();\n      q.pop();\n      for (int\
    \ i = 0; i < (int) adj[v].size(); i++) {\n        Edge& e = adj[v][i];\n     \
    \   if (par_v[e.to] == -1 && e.c > 0) {\n          par_v[e.to] = v;\n        \
    \  par_e[e.to] = i;\n          q.push(e.to);\n          if (e.to == t) break;\n\
    \        }\n      }\n    }\n    if (par_v[t] == -1) return 0;\n    ll f = LLONG_MAX;\n\
    \    for (int v = t; v != s; v = par_v[v])\n      f = min(f, adj[par_v[v]][par_e[v]].c);\n\
    \    for (int v = t; v != s; v = par_v[v]) {\n      Edge& e = adj[par_v[v]][par_e[v]];\n\
    \      e.c -= f;\n      adj[v][e.rev].c += f;\n    }\n    return f;\n  }\n\n \
    \ ll calc(int s, int t) {\n    ll flow = 0, p;\n    while ((p = bfs(s, t))) flow\
    \ += p;\n    return flow;\n  }\n\n  bool leftOfMinCut(int a) { return par_v[a]\
    \ != -1; }\n};\n"
  code: "struct EdmondsKarp {\n  struct Edge {\n    int to, rev;\n    ll c, oc;\n\
    \    ll flow() { return max(oc - c, 0LL); }  // if you need flows\n  };\n  vector<vector<Edge>>\
    \ adj;\n  vector<int> par_v, par_e;\n  int n;\n  EdmondsKarp(int n) : adj(n),\
    \ par_v(n), par_e(n), n(n) {}\n\n  void addEdge(int a, int b, ll c, ll rcap =\
    \ 0) {\n    adj[a].push_back({b, (int) adj[b].size(), c, c});\n    adj[b].push_back({a,\
    \ (int) adj[a].size() - 1, rcap, rcap});\n  }\n\n  ll bfs(int s, int t) {\n  \
    \  fill(par_v.begin(), par_v.end(), -1);\n    queue<int> q;\n    q.push(s);\n\
    \    par_v[s] = s;\n    while (!q.empty() && par_v[t] == -1) {\n      int v =\
    \ q.front();\n      q.pop();\n      for (int i = 0; i < (int) adj[v].size(); i++)\
    \ {\n        Edge& e = adj[v][i];\n        if (par_v[e.to] == -1 && e.c > 0) {\n\
    \          par_v[e.to] = v;\n          par_e[e.to] = i;\n          q.push(e.to);\n\
    \          if (e.to == t) break;\n        }\n      }\n    }\n    if (par_v[t]\
    \ == -1) return 0;\n    ll f = LLONG_MAX;\n    for (int v = t; v != s; v = par_v[v])\n\
    \      f = min(f, adj[par_v[v]][par_e[v]].c);\n    for (int v = t; v != s; v =\
    \ par_v[v]) {\n      Edge& e = adj[par_v[v]][par_e[v]];\n      e.c -= f;\n   \
    \   adj[v][e.rev].c += f;\n    }\n    return f;\n  }\n\n  ll calc(int s, int t)\
    \ {\n    ll flow = 0, p;\n    while ((p = bfs(s, t))) flow += p;\n    return flow;\n\
    \  }\n\n  bool leftOfMinCut(int a) { return par_v[a] != -1; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/EdmondsKarp.h
  requiredBy: []
  timestamp: '2025-11-15 18:26:28+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/EdmondsKarp.h
layout: document
redirect_from:
- /library/graph/EdmondsKarp.h
- /library/graph/EdmondsKarp.h.html
title: graph/EdmondsKarp.h
---
