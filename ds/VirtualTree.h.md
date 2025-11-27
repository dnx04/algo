---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: ds/HLD.h
    title: ds/HLD.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
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
    \ v);\n    return dep[u] < dep[v] ? u : v;\n  }\n};\n#line 2 \"ds/VirtualTree.h\"\
    \n\ntemplate <class G>\nstruct VirtualTree : HLD<G> {\n  using HLD<G>::pos, HLD<G>::sz,\
    \ HLD<G>::lca, HLD<G>::n;\n  vector<vi> adj;  // (Directed: Parent -> Child)\n\
    \  VirtualTree(const G& g, int root = 0) : HLD<G>(g, root), adj(n) {}\n  // Input:\
    \ danh s\xE1ch \u0111\u1EC9nh c\u1EA7n d\u1EF1ng c\xE2y.\n  // Output: danh s\xE1\
    ch \u0111\u1EC9nh c\u1EE7a c\xE2y \u1EA3o (\u0111\xE3 sort theo DFS order, bao\
    \ g\u1ED3m c\u1EA3 LCAs).\n  //        \u0110\u1EC9nh \u0111\u1EA7u ti\xEAn c\u1EE7\
    a vector tr\u1EA3 v\u1EC1 l\xE0 G\u1ED1c c\u1EE7a c\xE2y \u1EA3o.\n  vi build(vi&\
    \ nodes) {\n    auto cmp = [&](int a, int b) { return pos[a] < pos[b]; };\n  \
    \  sort(all(nodes), cmp);\n    int k = sz(nodes);\n    for (int i = 0; i < k -\
    \ 1; ++i) nodes.pb(lca(nodes[i], nodes[i + 1]));\n    sort(all(nodes), cmp);\n\
    \    nodes.erase(unique(all(nodes)), nodes.end());\n    for (int u : nodes) adj[u].clear();\n\
    \    vi st;\n    for (int u : nodes) {\n      // Check if st.back() is ancestor\
    \ of u\n      while (sz(st) && !(pos[st.back()] <= pos[u] && pos[u] < pos[st.back()]\
    \ + sz[st.back()]))\n        st.pop_back();\n      if (sz(st)) adj[st.back()].pb(u);\n\
    \      st.pb(u);\n    }\n    return nodes;\n  }\n};\n"
  code: "#include \"HLD.h\"\n\ntemplate <class G>\nstruct VirtualTree : HLD<G> {\n\
    \  using HLD<G>::pos, HLD<G>::sz, HLD<G>::lca, HLD<G>::n;\n  vector<vi> adj; \
    \ // (Directed: Parent -> Child)\n  VirtualTree(const G& g, int root = 0) : HLD<G>(g,\
    \ root), adj(n) {}\n  // Input: danh s\xE1ch \u0111\u1EC9nh c\u1EA7n d\u1EF1ng\
    \ c\xE2y.\n  // Output: danh s\xE1ch \u0111\u1EC9nh c\u1EE7a c\xE2y \u1EA3o (\u0111\
    \xE3 sort theo DFS order, bao g\u1ED3m c\u1EA3 LCAs).\n  //        \u0110\u1EC9\
    nh \u0111\u1EA7u ti\xEAn c\u1EE7a vector tr\u1EA3 v\u1EC1 l\xE0 G\u1ED1c c\u1EE7\
    a c\xE2y \u1EA3o.\n  vi build(vi& nodes) {\n    auto cmp = [&](int a, int b) {\
    \ return pos[a] < pos[b]; };\n    sort(all(nodes), cmp);\n    int k = sz(nodes);\n\
    \    for (int i = 0; i < k - 1; ++i) nodes.pb(lca(nodes[i], nodes[i + 1]));\n\
    \    sort(all(nodes), cmp);\n    nodes.erase(unique(all(nodes)), nodes.end());\n\
    \    for (int u : nodes) adj[u].clear();\n    vi st;\n    for (int u : nodes)\
    \ {\n      // Check if st.back() is ancestor of u\n      while (sz(st) && !(pos[st.back()]\
    \ <= pos[u] && pos[u] < pos[st.back()] + sz[st.back()]))\n        st.pop_back();\n\
    \      if (sz(st)) adj[st.back()].pb(u);\n      st.pb(u);\n    }\n    return nodes;\n\
    \  }\n};\n"
  dependsOn:
  - ds/HLD.h
  isVerificationFile: false
  path: ds/VirtualTree.h
  requiredBy: []
  timestamp: '2025-11-27 09:59:02+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/VirtualTree.h
layout: document
redirect_from:
- /library/ds/VirtualTree.h
- /library/ds/VirtualTree.h.html
title: ds/VirtualTree.h
---
