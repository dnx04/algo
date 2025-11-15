---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/Matching_on_Bipartite_Graph_HopcroftKarp.test.cpp
    title: tests/Matching_on_Bipartite_Graph_HopcroftKarp.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/HopcroftKarp.h\"\nbool dfs(int a, int L, vector<vi>&\
    \ g, vi& btoa, vi& A, vi& B) {\n  if (A[a] != L) return 0;\n  A[a] = -1;\n  for\
    \ (int b : g[a]) {\n    if (B[b] == L + 1) {\n      B[b] = 0;\n      if (btoa[b]\
    \ == -1 || dfs(btoa[b], L + 1, g, btoa, A, B)) return btoa[b] = a, 1;\n    }\n\
    \  }\n  return 0;\n}\n\nint hopcroftKarp(vector<vi>& g, vi& btoa) {\n  int res\
    \ = 0;\n  vi A(g.size()), B(btoa.size()), cur, next;\n  for (;;) {\n    fill(all(A),\
    \ 0);\n    fill(all(B), 0);\n    /// Find the starting nodes for BFS (i.e. layer\
    \ 0).\n    cur.clear();\n    for (int a : btoa)\n      if (a != -1) A[a] = -1;\n\
    \    for (int a = 0; a < sz(g); ++a)\n      if (A[a] == 0) cur.push_back(a);\n\
    \    /// Find all layers using bfs.\n    for (int lay = 1;; lay++) {\n      bool\
    \ islast = 0;\n      next.clear();\n      for (int a : cur)\n        for (int\
    \ b : g[a]) {\n          if (btoa[b] == -1) {\n            B[b] = lay;\n     \
    \       islast = 1;\n          } else if (btoa[b] != a && !B[b]) {\n         \
    \   B[b] = lay;\n            next.push_back(btoa[b]);\n          }\n        }\n\
    \      if (islast) break;\n      if (next.empty()) return res;\n      for (int\
    \ a : next) A[a] = lay;\n      cur.swap(next);\n    }\n    /// Use DFS to scan\
    \ for augmenting paths.\n    for (int a = 0; a < sz(g); ++a) res += dfs(a, 0,\
    \ g, btoa, A, B);\n  }\n}\n"
  code: "bool dfs(int a, int L, vector<vi>& g, vi& btoa, vi& A, vi& B) {\n  if (A[a]\
    \ != L) return 0;\n  A[a] = -1;\n  for (int b : g[a]) {\n    if (B[b] == L + 1)\
    \ {\n      B[b] = 0;\n      if (btoa[b] == -1 || dfs(btoa[b], L + 1, g, btoa,\
    \ A, B)) return btoa[b] = a, 1;\n    }\n  }\n  return 0;\n}\n\nint hopcroftKarp(vector<vi>&\
    \ g, vi& btoa) {\n  int res = 0;\n  vi A(g.size()), B(btoa.size()), cur, next;\n\
    \  for (;;) {\n    fill(all(A), 0);\n    fill(all(B), 0);\n    /// Find the starting\
    \ nodes for BFS (i.e. layer 0).\n    cur.clear();\n    for (int a : btoa)\n  \
    \    if (a != -1) A[a] = -1;\n    for (int a = 0; a < sz(g); ++a)\n      if (A[a]\
    \ == 0) cur.push_back(a);\n    /// Find all layers using bfs.\n    for (int lay\
    \ = 1;; lay++) {\n      bool islast = 0;\n      next.clear();\n      for (int\
    \ a : cur)\n        for (int b : g[a]) {\n          if (btoa[b] == -1) {\n   \
    \         B[b] = lay;\n            islast = 1;\n          } else if (btoa[b] !=\
    \ a && !B[b]) {\n            B[b] = lay;\n            next.push_back(btoa[b]);\n\
    \          }\n        }\n      if (islast) break;\n      if (next.empty()) return\
    \ res;\n      for (int a : next) A[a] = lay;\n      cur.swap(next);\n    }\n \
    \   /// Use DFS to scan for augmenting paths.\n    for (int a = 0; a < sz(g);\
    \ ++a) res += dfs(a, 0, g, btoa, A, B);\n  }\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/HopcroftKarp.h
  requiredBy: []
  timestamp: '2025-11-15 18:26:28+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/Matching_on_Bipartite_Graph_HopcroftKarp.test.cpp
documentation_of: graph/HopcroftKarp.h
layout: document
redirect_from:
- /library/graph/HopcroftKarp.h
- /library/graph/HopcroftKarp.h.html
title: graph/HopcroftKarp.h
---
