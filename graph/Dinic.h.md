---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/GomoryHu.h
    title: graph/GomoryHu.h
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
    \ rcap = 0) {\n    adj[a].push_back({b, sz(adj[b]), c, c});\n    adj[b].push_back({a,\
    \ sz(adj[a]) - 1, rcap, rcap});\n  }\n  i64 dfs(int v, int t, i64 f) {\n    if\
    \ (v == t || !f) return f;\n    for (int& i = ptr[v]; i < sz(adj[v]); i++) {\n\
    \      Edge& e = adj[v][i];\n      if (lvl[e.to] == lvl[v] + 1)\n        if (i64\
    \ p = dfs(e.to, t, min(f, e.c))) {\n          e.c -= p, adj[e.to][e.rev].c +=\
    \ p;\n          return p;\n        }\n    }\n    return 0;\n  }\n  i64 calc(int\
    \ s, int t) {\n    i64 flow = 0;\n    q[0] = s;\n    // 'int L=30' maybe faster\
    \ for random data\n    for (int L = 0; L < 31; ++L) {\n      do {\n        lvl\
    \ = ptr = vi(sz(q));\n        int qi = 0, qe = lvl[s] = 1;\n        while (qi\
    \ < qe && !lvl[t]) {\n          int v = q[qi++];\n          for (Edge e : adj[v])\n\
    \            if (!lvl[e.to] && e.c >> (30 - L))\n              q[qe++] = e.to,\
    \ lvl[e.to] = lvl[v] + 1;\n        }\n        while (i64 p = dfs(s, t, LLONG_MAX))\
    \ flow += p;\n      } while (lvl[t]);\n    }\n    return flow;\n  }\n  bool leftOfMinCut(int\
    \ a) { return lvl[a] != 0; }\n};\n"
  code: "struct Dinic {\n  struct Edge {\n    int to, rev;\n    i64 c, oc;\n    i64\
    \ flow() { return max(oc - c, i64(0)); }  // if you need flows\n  };\n  vi lvl,\
    \ ptr, q;\n  vector<vector<Edge>> adj;\n  Dinic(int n) : lvl(n), ptr(n), q(n),\
    \ adj(n) {}\n  void addEdge(int a, int b, i64 c, i64 rcap = 0) {\n    adj[a].push_back({b,\
    \ sz(adj[b]), c, c});\n    adj[b].push_back({a, sz(adj[a]) - 1, rcap, rcap});\n\
    \  }\n  i64 dfs(int v, int t, i64 f) {\n    if (v == t || !f) return f;\n    for\
    \ (int& i = ptr[v]; i < sz(adj[v]); i++) {\n      Edge& e = adj[v][i];\n     \
    \ if (lvl[e.to] == lvl[v] + 1)\n        if (i64 p = dfs(e.to, t, min(f, e.c)))\
    \ {\n          e.c -= p, adj[e.to][e.rev].c += p;\n          return p;\n     \
    \   }\n    }\n    return 0;\n  }\n  i64 calc(int s, int t) {\n    i64 flow = 0;\n\
    \    q[0] = s;\n    // 'int L=30' maybe faster for random data\n    for (int L\
    \ = 0; L < 31; ++L) {\n      do {\n        lvl = ptr = vi(sz(q));\n        int\
    \ qi = 0, qe = lvl[s] = 1;\n        while (qi < qe && !lvl[t]) {\n          int\
    \ v = q[qi++];\n          for (Edge e : adj[v])\n            if (!lvl[e.to] &&\
    \ e.c >> (30 - L))\n              q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;\n  \
    \      }\n        while (i64 p = dfs(s, t, LLONG_MAX)) flow += p;\n      } while\
    \ (lvl[t]);\n    }\n    return flow;\n  }\n  bool leftOfMinCut(int a) { return\
    \ lvl[a] != 0; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/Dinic.h
  requiredBy:
  - graph/GomoryHu.h
  timestamp: '2025-11-18 16:58:39+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/Dinic.h
layout: document
redirect_from:
- /library/graph/Dinic.h
- /library/graph/Dinic.h.html
title: graph/Dinic.h
---
