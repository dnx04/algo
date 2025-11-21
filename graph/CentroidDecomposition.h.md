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
  bundledCode: "#line 1 \"graph/CentroidDecomposition.h\"\ntemplate <class G>\nstruct\
    \ CentroidDecomposition {\n  const G& g;\n  vi sub;\n  vector<bool> v;\n  vector<vi>\
    \ tree;\n  int root;\n\n  CentroidDecomposition(const G& g, int isbuild = true)\
    \ : g(g) {\n    sub.resize(g.size(), 0);\n    v.resize(g.size(), false);\n   \
    \ if (isbuild) build();\n  }\n\n  void build() {\n    tree.resize(g.size());\n\
    \    root = build_dfs(0);\n  }\n\n  int get_size(int cur, int par) {\n    sub[cur]\
    \ = 1;\n    for (auto& dst : g[cur]) {\n      if (dst == par || v[dst]) continue;\n\
    \      sub[cur] += get_size(dst, cur);\n    }\n    return sub[cur];\n  }\n\n \
    \ int get_centroid(int cur, int par, int mid) {\n    for (auto& dst : g[cur])\
    \ {\n      if (dst == par || v[dst]) continue;\n      if (sub[dst] > mid) return\
    \ get_centroid(dst, cur, mid);\n    }\n    return cur;\n  }\n\n  int build_dfs(int\
    \ cur) {\n    int centroid = get_centroid(cur, -1, get_size(cur, -1) / 2);\n \
    \   v[centroid] = true;\n    for (auto& dst : g[centroid]) {\n      if (!v[dst])\
    \ {\n        int nxt = build_dfs(dst);\n        if (centroid != nxt) tree[centroid].eb(nxt);\n\
    \      }\n    }\n    v[centroid] = false;\n    return centroid;\n  }\n};\n"
  code: "template <class G>\nstruct CentroidDecomposition {\n  const G& g;\n  vi sub;\n\
    \  vector<bool> v;\n  vector<vi> tree;\n  int root;\n\n  CentroidDecomposition(const\
    \ G& g, int isbuild = true) : g(g) {\n    sub.resize(g.size(), 0);\n    v.resize(g.size(),\
    \ false);\n    if (isbuild) build();\n  }\n\n  void build() {\n    tree.resize(g.size());\n\
    \    root = build_dfs(0);\n  }\n\n  int get_size(int cur, int par) {\n    sub[cur]\
    \ = 1;\n    for (auto& dst : g[cur]) {\n      if (dst == par || v[dst]) continue;\n\
    \      sub[cur] += get_size(dst, cur);\n    }\n    return sub[cur];\n  }\n\n \
    \ int get_centroid(int cur, int par, int mid) {\n    for (auto& dst : g[cur])\
    \ {\n      if (dst == par || v[dst]) continue;\n      if (sub[dst] > mid) return\
    \ get_centroid(dst, cur, mid);\n    }\n    return cur;\n  }\n\n  int build_dfs(int\
    \ cur) {\n    int centroid = get_centroid(cur, -1, get_size(cur, -1) / 2);\n \
    \   v[centroid] = true;\n    for (auto& dst : g[centroid]) {\n      if (!v[dst])\
    \ {\n        int nxt = build_dfs(dst);\n        if (centroid != nxt) tree[centroid].eb(nxt);\n\
    \      }\n    }\n    v[centroid] = false;\n    return centroid;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/CentroidDecomposition.h
  requiredBy: []
  timestamp: '2025-11-21 16:12:02+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/CentroidDecomposition.h
layout: document
redirect_from:
- /library/graph/CentroidDecomposition.h
- /library/graph/CentroidDecomposition.h.html
title: graph/CentroidDecomposition.h
---
