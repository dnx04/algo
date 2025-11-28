---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/Dinic.h
    title: graph/Dinic.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/Dinic.h\"\nstruct Dinic {\n  struct Edge {\n    int\
    \ to, rev;\n    i64 c, oc;\n    i64 flow() { return max(oc - c, i64(0)); }  //\
    \ if you need flows\n  };\n  vi lvl, ptr, q;\n  vector<vector<Edge>> adj;\n  Dinic(int\
    \ n) : lvl(n), ptr(n), q(n), adj(n) {}\n  void addEdge(int a, int b, i64 c, i64\
    \ rcap = 0) {\n    adj[a].pb({b, sz(adj[b]), c, c});\n    adj[b].pb({a, sz(adj[a])\
    \ - 1, rcap, rcap});\n  }\n  i64 dfs(int v, int t, i64 f) {\n    if (v == t ||\
    \ !f) return f;\n    for (int& i = ptr[v]; i < sz(adj[v]); i++) {\n      Edge&\
    \ e = adj[v][i];\n      if (lvl[e.to] == lvl[v] + 1)\n        if (i64 p = dfs(e.to,\
    \ t, min(f, e.c))) {\n          e.c -= p, adj[e.to][e.rev].c += p;\n         \
    \ return p;\n        }\n    }\n    return 0;\n  }\n  i64 calc(int s, int t) {\n\
    \    i64 flow = 0;\n    q[0] = s;\n    // 'int L=30' maybe faster for random data\n\
    \    for (int L = 0; L < 31; ++L) {\n      do {\n        lvl = ptr = vi(sz(q));\n\
    \        int qi = 0, qe = lvl[s] = 1;\n        while (qi < qe && !lvl[t]) {\n\
    \          int v = q[qi++];\n          for (Edge e : adj[v])\n            if (!lvl[e.to]\
    \ && e.c >> (30 - L))\n              q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;\n\
    \        }\n        while (i64 p = dfs(s, t, LLONG_MAX)) flow += p;\n      } while\
    \ (lvl[t]);\n    }\n    return flow;\n  }\n  bool leftOfMinCut(int a) { return\
    \ lvl[a] != 0; }\n};\n#line 2 \"graph/GomoryHu.h\"\n\ntypedef array<i64, 3> Edge;\n\
    vector<Edge> gomoryHu(int N, vector<Edge> ed) {\n  vector<Edge> tree;\n  vi par(N);\n\
    \  for (int i = 1; i < N; ++i) {\n    Dinic D(N);\n    for (Edge t : ed) D.addEdge(t[0],\
    \ t[1], t[2], t[2]);\n    tree.push_back({i, par[i], D.calc(i, par[i])});\n  \
    \  for (int j = i + 1; j < N; ++j)\n      if (par[j] == par[i] && D.leftOfMinCut(j))\
    \ par[j] = i;\n  }\n  return tree;\n}\n"
  code: "#include \"Dinic.h\"\n\ntypedef array<i64, 3> Edge;\nvector<Edge> gomoryHu(int\
    \ N, vector<Edge> ed) {\n  vector<Edge> tree;\n  vi par(N);\n  for (int i = 1;\
    \ i < N; ++i) {\n    Dinic D(N);\n    for (Edge t : ed) D.addEdge(t[0], t[1],\
    \ t[2], t[2]);\n    tree.push_back({i, par[i], D.calc(i, par[i])});\n    for (int\
    \ j = i + 1; j < N; ++j)\n      if (par[j] == par[i] && D.leftOfMinCut(j)) par[j]\
    \ = i;\n  }\n  return tree;\n}"
  dependsOn:
  - graph/Dinic.h
  isVerificationFile: false
  path: graph/GomoryHu.h
  requiredBy: []
  timestamp: '2025-11-28 10:18:48+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/GomoryHu.h
layout: document
redirect_from:
- /library/graph/GomoryHu.h
- /library/graph/GomoryHu.h.html
title: graph/GomoryHu.h
---
