---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: ds/VirtualTree.h
    title: ds/VirtualTree.h
  _extendedVerifiedWith:
  - icon: ':x:'
    path: tests/Vertex_Add_Path_Sum.test.cpp
    title: tests/Vertex_Add_Path_Sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: h
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/HLD.h\"\ntemplate <class G>\nstruct HLD {\n  const G&\
    \ g;\n  int n, t = 0;\n  vi sz, dep, par, head, pos, heavy;\n  HLD(const G& g,\
    \ int root = 0) : g(g), n(sz(g)), sz(n), dep(n), par(n), head(n), pos(n), heavy(n,\
    \ -1) {\n    par[root] = -1;\n    dfs_sz(root);\n    dfs_hld(root, root);\n  }\n\
    \  void dfs_sz(int u) {\n    sz[u] = 1;\n    for (int v : g[u])\n      if (v !=\
    \ par[u]) {\n        dep[v] = dep[u] + 1, par[v] = u;\n        dfs_sz(v);\n  \
    \      sz[u] += sz[v];\n        if (heavy[u] == -1 || sz[v] > sz[heavy[u]]) heavy[u]\
    \ = v;\n      }\n  }\n  void dfs_hld(int u, int h) {\n    head[u] = h, pos[u]\
    \ = ++t;\n    if (heavy[u] != -1) dfs_hld(heavy[u], h);\n    for (int v : g[u])\n\
    \      if (v != par[u] && v != heavy[u]) dfs_hld(v, v);\n  }\n  pii query_subtree(int\
    \ u) { return {pos[u], pos[u] + sz[u] - 1}; }\n  // Tr\u1EA3 v\u1EC1 vector c\xE1\
    c \u0111o\u1EA1n [L, R].\n  // L > R: \u0111i l\xEAn (u -> LCA). L <= R: \u0111\
    i xu\u1ED1ng (LCA -> v).\n  vector<pii> query_path(int u, int v) {\n    vector<pii>\
    \ l, r;\n    for (; head[u] != head[v]; u = par[head[u]]) {\n      if (dep[head[u]]\
    \ > dep[head[v]]) l.pb({pos[u], pos[head[u]]});\n      else r.pb({pos[head[v]],\
    \ pos[v]}), v = par[head[v]];\n    }\n    if (dep[u] > dep[v]) l.pb({pos[u], pos[v]});\n\
    \    else r.pb({pos[u], pos[v]});\n    reverse(all(r));\n    l.insert(l.end(),\
    \ all(r));\n    return l;\n  }\n\n  int lca(int u, int v) {\n    for (; head[u]\
    \ != head[v]; u = par[head[u]])\n      if (dep[head[u]] < dep[head[v]]) swap(u,\
    \ v);\n    return dep[u] < dep[v] ? u : v;\n  }\n};\n"
  code: "template <class G>\nstruct HLD {\n  const G& g;\n  int n, t = 0;\n  vi sz,\
    \ dep, par, head, pos, heavy;\n  HLD(const G& g, int root = 0) : g(g), n(sz(g)),\
    \ sz(n), dep(n), par(n), head(n), pos(n), heavy(n, -1) {\n    par[root] = -1;\n\
    \    dfs_sz(root);\n    dfs_hld(root, root);\n  }\n  void dfs_sz(int u) {\n  \
    \  sz[u] = 1;\n    for (int v : g[u])\n      if (v != par[u]) {\n        dep[v]\
    \ = dep[u] + 1, par[v] = u;\n        dfs_sz(v);\n        sz[u] += sz[v];\n   \
    \     if (heavy[u] == -1 || sz[v] > sz[heavy[u]]) heavy[u] = v;\n      }\n  }\n\
    \  void dfs_hld(int u, int h) {\n    head[u] = h, pos[u] = ++t;\n    if (heavy[u]\
    \ != -1) dfs_hld(heavy[u], h);\n    for (int v : g[u])\n      if (v != par[u]\
    \ && v != heavy[u]) dfs_hld(v, v);\n  }\n  pii query_subtree(int u) { return {pos[u],\
    \ pos[u] + sz[u] - 1}; }\n  // Tr\u1EA3 v\u1EC1 vector c\xE1c \u0111o\u1EA1n [L,\
    \ R].\n  // L > R: \u0111i l\xEAn (u -> LCA). L <= R: \u0111i xu\u1ED1ng (LCA\
    \ -> v).\n  vector<pii> query_path(int u, int v) {\n    vector<pii> l, r;\n  \
    \  for (; head[u] != head[v]; u = par[head[u]]) {\n      if (dep[head[u]] > dep[head[v]])\
    \ l.pb({pos[u], pos[head[u]]});\n      else r.pb({pos[head[v]], pos[v]}), v =\
    \ par[head[v]];\n    }\n    if (dep[u] > dep[v]) l.pb({pos[u], pos[v]});\n   \
    \ else r.pb({pos[u], pos[v]});\n    reverse(all(r));\n    l.insert(l.end(), all(r));\n\
    \    return l;\n  }\n\n  int lca(int u, int v) {\n    for (; head[u] != head[v];\
    \ u = par[head[u]])\n      if (dep[head[u]] < dep[head[v]]) swap(u, v);\n    return\
    \ dep[u] < dep[v] ? u : v;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/HLD.h
  requiredBy:
  - ds/VirtualTree.h
  timestamp: '2025-11-27 09:59:02+07:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - tests/Vertex_Add_Path_Sum.test.cpp
documentation_of: ds/HLD.h
layout: document
redirect_from:
- /library/ds/HLD.h
- /library/ds/HLD.h.html
title: ds/HLD.h
---
