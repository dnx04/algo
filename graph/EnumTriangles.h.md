---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: tests/Enumerate_Triangles.test.cpp
    title: tests/Enumerate_Triangles.test.cpp
  _isVerificationFailed: true
  _pathExtension: h
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/EnumTriangles.h\"\ntemplate <typename F>\nvoid EnumTriangles(int\
    \ n, const vector<pii>& ed, F f) {  // 0-indexed graph\n  vi deg(n);\n  for (auto\
    \ [u, v] : ed) ++deg[u], ++deg[v];\n  vector<vi> g(n);  // directed\n  for (auto&\
    \ e : ed) {\n    auto [u, v] = e;\n    if (tie(deg[u], u) > tie(deg[v], v)) swap(u,\
    \ v);\n    g[u].eb(v);\n  }\n  vector<bool> adj(n);\n  for (auto& [u, v] : ed)\
    \ {\n    for (auto nu : g[u]) adj[nu] = true;\n    for (auto nv : g[v]) {\n  \
    \    if (adj[nv]) f(u, v, nv);\n    }\n    for (auto nu : g[u]) adj[nu] = false;\n\
    \  }\n}\n"
  code: "template <typename F>\nvoid EnumTriangles(int n, const vector<pii>& ed, F\
    \ f) {  // 0-indexed graph\n  vi deg(n);\n  for (auto [u, v] : ed) ++deg[u], ++deg[v];\n\
    \  vector<vi> g(n);  // directed\n  for (auto& e : ed) {\n    auto [u, v] = e;\n\
    \    if (tie(deg[u], u) > tie(deg[v], v)) swap(u, v);\n    g[u].eb(v);\n  }\n\
    \  vector<bool> adj(n);\n  for (auto& [u, v] : ed) {\n    for (auto nu : g[u])\
    \ adj[nu] = true;\n    for (auto nv : g[v]) {\n      if (adj[nv]) f(u, v, nv);\n\
    \    }\n    for (auto nu : g[u]) adj[nu] = false;\n  }\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/EnumTriangles.h
  requiredBy: []
  timestamp: '2025-11-16 01:14:31+07:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - tests/Enumerate_Triangles.test.cpp
documentation_of: graph/EnumTriangles.h
layout: document
redirect_from:
- /library/graph/EnumTriangles.h
- /library/graph/EnumTriangles.h.html
title: graph/EnumTriangles.h
---
