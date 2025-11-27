---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: ds/VirtualTree.h
    title: ds/VirtualTree.h
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/LCA.test.cpp
    title: tests/LCA.test.cpp
  - icon: ':x:'
    path: tests/Vertex_Add_Path_Sum.test.cpp
    title: tests/Vertex_Add_Path_Sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: h
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/HLD.h\"\ntemplate <class G>\nstruct HLD {\n  const G&\
    \ g;\n  int n, t = 0;\n  vi sub, dep, par, head, pos, heavy;\n  HLD(const G& g,\
    \ int root = 0) : g(g), n(sz(g)), sub(n), dep(n), par(n), head(n), pos(n), heavy(n,\
    \ -1) {\n    par[root] = -1;\n    dfs_sub(root);\n    dfs_hld(root, root);\n \
    \ }\n  void dfs_sub(int u) {\n    sub[u] = 1;\n    for (int v : g[u])\n      if\
    \ (v != par[u]) {\n        dep[v] = dep[u] + 1, par[v] = u;\n        dfs_sub(v);\n\
    \        sub[u] += sub[v];\n        if (heavy[u] == -1 || sub[v] > sub[heavy[u]])\
    \ heavy[u] = v;\n      }\n  }\n  void dfs_hld(int u, int h) {\n    head[u] = h,\
    \ pos[u] = ++t;\n    if (heavy[u] != -1) dfs_hld(heavy[u], h);\n    for (int v\
    \ : g[u])\n      if (v != par[u] && v != heavy[u]) dfs_hld(v, v);\n  }\n  int\
    \ idx(int u) const { return pos[u]; }\n  pii query_subtree(int u) { return {pos[u],\
    \ pos[u] + sub[u] - 1}; }\n  vector<pii> query_path(int u, int v) {\n    vector<pii>\
    \ l, r;\n    while (head[u] != head[v]) {\n      if (dep[head[u]] > dep[head[v]])\
    \ {\n        l.pb({pos[u], pos[head[u]]});\n        u = par[head[u]];\n      }\
    \ else {\n        r.pb({pos[head[v]], pos[v]});\n        v = par[head[v]];\n \
    \     }\n    }\n    if (dep[u] > dep[v]) l.pb({pos[u], pos[v]});\n    else r.pb({pos[u],\
    \ pos[v]});\n    reverse(all(r));\n    l.insert(l.end(), all(r));\n    return\
    \ l;\n  }\n  int lca(int u, int v) {\n    for (; head[u] != head[v]; u = par[head[u]])\n\
    \      if (dep[head[u]] < dep[head[v]]) swap(u, v);\n    return dep[u] < dep[v]\
    \ ? u : v;\n  }\n};\n"
  code: "template <class G>\nstruct HLD {\n  const G& g;\n  int n, t = 0;\n  vi sub,\
    \ dep, par, head, pos, heavy;\n  HLD(const G& g, int root = 0) : g(g), n(sz(g)),\
    \ sub(n), dep(n), par(n), head(n), pos(n), heavy(n, -1) {\n    par[root] = -1;\n\
    \    dfs_sub(root);\n    dfs_hld(root, root);\n  }\n  void dfs_sub(int u) {\n\
    \    sub[u] = 1;\n    for (int v : g[u])\n      if (v != par[u]) {\n        dep[v]\
    \ = dep[u] + 1, par[v] = u;\n        dfs_sub(v);\n        sub[u] += sub[v];\n\
    \        if (heavy[u] == -1 || sub[v] > sub[heavy[u]]) heavy[u] = v;\n      }\n\
    \  }\n  void dfs_hld(int u, int h) {\n    head[u] = h, pos[u] = ++t;\n    if (heavy[u]\
    \ != -1) dfs_hld(heavy[u], h);\n    for (int v : g[u])\n      if (v != par[u]\
    \ && v != heavy[u]) dfs_hld(v, v);\n  }\n  int idx(int u) const { return pos[u];\
    \ }\n  pii query_subtree(int u) { return {pos[u], pos[u] + sub[u] - 1}; }\n  vector<pii>\
    \ query_path(int u, int v) {\n    vector<pii> l, r;\n    while (head[u] != head[v])\
    \ {\n      if (dep[head[u]] > dep[head[v]]) {\n        l.pb({pos[u], pos[head[u]]});\n\
    \        u = par[head[u]];\n      } else {\n        r.pb({pos[head[v]], pos[v]});\n\
    \        v = par[head[v]];\n      }\n    }\n    if (dep[u] > dep[v]) l.pb({pos[u],\
    \ pos[v]});\n    else r.pb({pos[u], pos[v]});\n    reverse(all(r));\n    l.insert(l.end(),\
    \ all(r));\n    return l;\n  }\n  int lca(int u, int v) {\n    for (; head[u]\
    \ != head[v]; u = par[head[u]])\n      if (dep[head[u]] < dep[head[v]]) swap(u,\
    \ v);\n    return dep[u] < dep[v] ? u : v;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/HLD.h
  requiredBy:
  - ds/VirtualTree.h
  timestamp: '2025-11-27 11:47:17+07:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - tests/Vertex_Add_Path_Sum.test.cpp
  - tests/LCA.test.cpp
documentation_of: ds/HLD.h
layout: document
redirect_from:
- /library/ds/HLD.h
- /library/ds/HLD.h.html
title: ds/HLD.h
---
