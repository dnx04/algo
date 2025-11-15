---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/Vertex_Add_Path_Sum.test.cpp
    title: tests/Vertex_Add_Path_Sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/HLD.h\"\ntemplate <typename G>\nstruct HLD {\n private:\n\
    \  void dfs_sz(int cur) {\n    size[cur] = 1;\n    for (auto& dst : g[cur]) {\n\
    \      if (dst == par[cur]) {\n        if (g[cur].size() >= 2 && int(dst) == int(g[cur][0]))\n\
    \          swap(g[cur][0], g[cur][1]);\n        else\n          continue;\n  \
    \    }\n      depth[dst] = depth[cur] + 1;\n      par[dst] = cur;\n      dfs_sz(dst);\n\
    \      size[cur] += size[dst];\n      if (size[dst] > size[g[cur][0]]) {\n   \
    \     swap(dst, g[cur][0]);\n      }\n    }\n  }\n\n  void dfs_hld(int cur) {\n\
    \    down[cur] = id++;\n    for (auto dst : g[cur]) {\n      if (dst == par[cur])\
    \ continue;\n      nxt[dst] = (int(dst) == int(g[cur][0]) ? nxt[cur] : int(dst));\n\
    \      dfs_hld(dst);\n    }\n    up[cur] = id;\n  }\n\n  // [u, v)\n  vector<pii>\
    \ ascend(int u, int v) const {\n    vector<pii> res;\n    while (nxt[u] != nxt[v])\
    \ {\n      res.eb(down[u], down[nxt[u]]);\n      u = par[nxt[u]];\n    }\n   \
    \ if (u != v) res.eb(down[u], down[v] + 1);\n    return res;\n  }\n\n  // (u,\
    \ v]\n  vector<pii> descend(int u, int v) const {\n    if (u == v) return {};\n\
    \    if (nxt[u] == nxt[v]) return {{down[u] + 1, down[v]}};\n    auto res = descend(u,\
    \ par[nxt[v]]);\n    res.eb(down[nxt[v]], down[v]);\n    return res;\n  }\n\n\
    \ public:\n  G& g;\n  int root, id;\n  vector<int> size, depth, down, up, nxt,\
    \ par;\n  HLD(G& g, int root = 0) : g(g), root(root), id(0), size(sz(g), 0), depth(sz(g),\
    \ 0), down(sz(g), -1), up(sz(g), -1), nxt(sz(g), root), par(sz(g), root) {\n \
    \   dfs_sz(root);\n    dfs_hld(root);\n  }\n\n  pii idx(int i) const { return\
    \ make_pair(down[i], up[i]); }\n\n  template <typename F>\n  void path_query(int\
    \ u, int v, bool vertex, const F& f) {\n    int l = lca(u, v);\n    for (auto&&\
    \ [a, b] : ascend(u, l)) {\n      int s = a + 1, t = b;\n      s > t ? f(t, s)\
    \ : f(s, t);\n    }\n    if (vertex) f(down[l], down[l] + 1);\n    for (auto&&\
    \ [a, b] : descend(l, v)) {\n      int s = a, t = b + 1;\n      s > t ? f(t, s)\
    \ : f(s, t);\n    }\n  }\n\n  template <typename F>\n  void path_noncommutative_query(int\
    \ u, int v, bool vertex, const F& f) {\n    int l = lca(u, v);\n    for (auto&&\
    \ [a, b] : ascend(u, l)) f(a + 1, b);\n    if (vertex) f(down[l], down[l] + 1);\n\
    \    for (auto&& [a, b] : descend(l, v)) f(a, b + 1);\n  }\n\n  template <typename\
    \ F>\n  void subtree_query(int u, bool vertex, const F& f) {\n    f(down[u] +\
    \ int(!vertex), up[u]);\n  }\n\n  int lca(int a, int b) {\n    while (nxt[a] !=\
    \ nxt[b]) {\n      if (down[a] < down[b]) swap(a, b);\n      a = par[nxt[a]];\n\
    \    }\n    return depth[a] < depth[b] ? a : b;\n  }\n\n  int dist(int a, int\
    \ b) { return depth[a] + depth[b] - depth[lca(a, b)] * 2; }\n};\n"
  code: "template <typename G>\nstruct HLD {\n private:\n  void dfs_sz(int cur) {\n\
    \    size[cur] = 1;\n    for (auto& dst : g[cur]) {\n      if (dst == par[cur])\
    \ {\n        if (g[cur].size() >= 2 && int(dst) == int(g[cur][0]))\n         \
    \ swap(g[cur][0], g[cur][1]);\n        else\n          continue;\n      }\n  \
    \    depth[dst] = depth[cur] + 1;\n      par[dst] = cur;\n      dfs_sz(dst);\n\
    \      size[cur] += size[dst];\n      if (size[dst] > size[g[cur][0]]) {\n   \
    \     swap(dst, g[cur][0]);\n      }\n    }\n  }\n\n  void dfs_hld(int cur) {\n\
    \    down[cur] = id++;\n    for (auto dst : g[cur]) {\n      if (dst == par[cur])\
    \ continue;\n      nxt[dst] = (int(dst) == int(g[cur][0]) ? nxt[cur] : int(dst));\n\
    \      dfs_hld(dst);\n    }\n    up[cur] = id;\n  }\n\n  // [u, v)\n  vector<pii>\
    \ ascend(int u, int v) const {\n    vector<pii> res;\n    while (nxt[u] != nxt[v])\
    \ {\n      res.eb(down[u], down[nxt[u]]);\n      u = par[nxt[u]];\n    }\n   \
    \ if (u != v) res.eb(down[u], down[v] + 1);\n    return res;\n  }\n\n  // (u,\
    \ v]\n  vector<pii> descend(int u, int v) const {\n    if (u == v) return {};\n\
    \    if (nxt[u] == nxt[v]) return {{down[u] + 1, down[v]}};\n    auto res = descend(u,\
    \ par[nxt[v]]);\n    res.eb(down[nxt[v]], down[v]);\n    return res;\n  }\n\n\
    \ public:\n  G& g;\n  int root, id;\n  vector<int> size, depth, down, up, nxt,\
    \ par;\n  HLD(G& g, int root = 0) : g(g), root(root), id(0), size(sz(g), 0), depth(sz(g),\
    \ 0), down(sz(g), -1), up(sz(g), -1), nxt(sz(g), root), par(sz(g), root) {\n \
    \   dfs_sz(root);\n    dfs_hld(root);\n  }\n\n  pii idx(int i) const { return\
    \ make_pair(down[i], up[i]); }\n\n  template <typename F>\n  void path_query(int\
    \ u, int v, bool vertex, const F& f) {\n    int l = lca(u, v);\n    for (auto&&\
    \ [a, b] : ascend(u, l)) {\n      int s = a + 1, t = b;\n      s > t ? f(t, s)\
    \ : f(s, t);\n    }\n    if (vertex) f(down[l], down[l] + 1);\n    for (auto&&\
    \ [a, b] : descend(l, v)) {\n      int s = a, t = b + 1;\n      s > t ? f(t, s)\
    \ : f(s, t);\n    }\n  }\n\n  template <typename F>\n  void path_noncommutative_query(int\
    \ u, int v, bool vertex, const F& f) {\n    int l = lca(u, v);\n    for (auto&&\
    \ [a, b] : ascend(u, l)) f(a + 1, b);\n    if (vertex) f(down[l], down[l] + 1);\n\
    \    for (auto&& [a, b] : descend(l, v)) f(a, b + 1);\n  }\n\n  template <typename\
    \ F>\n  void subtree_query(int u, bool vertex, const F& f) {\n    f(down[u] +\
    \ int(!vertex), up[u]);\n  }\n\n  int lca(int a, int b) {\n    while (nxt[a] !=\
    \ nxt[b]) {\n      if (down[a] < down[b]) swap(a, b);\n      a = par[nxt[a]];\n\
    \    }\n    return depth[a] < depth[b] ? a : b;\n  }\n\n  int dist(int a, int\
    \ b) { return depth[a] + depth[b] - depth[lca(a, b)] * 2; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/HLD.h
  requiredBy: []
  timestamp: '2025-11-15 18:26:28+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/Vertex_Add_Path_Sum.test.cpp
documentation_of: ds/HLD.h
layout: document
redirect_from:
- /library/ds/HLD.h
- /library/ds/HLD.h.html
title: ds/HLD.h
---
