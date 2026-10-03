---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/Bipartite_Matching_HopcroftKarp.test.cpp
    title: tests/Bipartite_Matching_HopcroftKarp.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/HopcroftKarp.h\"\nstruct HopcroftKarp {\n  vector<vi>\
    \ g;\n  vi btoa, A, B;\n  HopcroftKarp(int L, int R) : g(L), btoa(R, -1), A(L),\
    \ B(R) {}\n  void add(int u, int v) { g[u].pb(v); }\n  bool dfs(int a, int L)\
    \ {\n    if (A[a] != L) return 0;\n    A[a] = -1;\n    for (int b : g[a])\n  \
    \    if (B[b] == L + 1) {\n        B[b] = 0;\n        if (btoa[b] == -1 || dfs(btoa[b],\
    \ L + 1)) return btoa[b] = a, 1;\n      }\n    return 0;\n  }\n  int solve() {\n\
    \    int res = 0;\n    vi cur, next;\n    for (;;) {\n      fill(all(A), 0), fill(all(B),\
    \ 0), cur.clear();\n      for (int a : btoa)\n        if (a != -1) A[a] = -1;\n\
    \      for (int a = 0; a < len(g); ++a)\n        if (!A[a]) cur.pb(a);\n     \
    \ for (int lay = 1;; lay++) {\n        bool islast = 0;\n        next.clear();\n\
    \        for (int a : cur)\n          for (int b : g[a]) {\n            if (btoa[b]\
    \ == -1)\n              B[b] = lay, islast = 1;\n            else if (btoa[b]\
    \ != a && !B[b])\n              B[b] = lay, next.pb(btoa[b]);\n          }\n \
    \       if (islast) break;\n        if (next.empty()) return res;\n        for\
    \ (int a : next) A[a] = lay;\n        cur.swap(next);\n      }\n      for (int\
    \ a = 0; a < len(g); ++a) res += dfs(a, 0);\n    }\n  }\n};\n"
  code: "struct HopcroftKarp {\n  vector<vi> g;\n  vi btoa, A, B;\n  HopcroftKarp(int\
    \ L, int R) : g(L), btoa(R, -1), A(L), B(R) {}\n  void add(int u, int v) { g[u].pb(v);\
    \ }\n  bool dfs(int a, int L) {\n    if (A[a] != L) return 0;\n    A[a] = -1;\n\
    \    for (int b : g[a])\n      if (B[b] == L + 1) {\n        B[b] = 0;\n     \
    \   if (btoa[b] == -1 || dfs(btoa[b], L + 1)) return btoa[b] = a, 1;\n      }\n\
    \    return 0;\n  }\n  int solve() {\n    int res = 0;\n    vi cur, next;\n  \
    \  for (;;) {\n      fill(all(A), 0), fill(all(B), 0), cur.clear();\n      for\
    \ (int a : btoa)\n        if (a != -1) A[a] = -1;\n      for (int a = 0; a < len(g);\
    \ ++a)\n        if (!A[a]) cur.pb(a);\n      for (int lay = 1;; lay++) {\n   \
    \     bool islast = 0;\n        next.clear();\n        for (int a : cur)\n   \
    \       for (int b : g[a]) {\n            if (btoa[b] == -1)\n              B[b]\
    \ = lay, islast = 1;\n            else if (btoa[b] != a && !B[b])\n          \
    \    B[b] = lay, next.pb(btoa[b]);\n          }\n        if (islast) break;\n\
    \        if (next.empty()) return res;\n        for (int a : next) A[a] = lay;\n\
    \        cur.swap(next);\n      }\n      for (int a = 0; a < len(g); ++a) res\
    \ += dfs(a, 0);\n    }\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/HopcroftKarp.h
  requiredBy: []
  timestamp: '2026-10-03 15:27:40+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/Bipartite_Matching_HopcroftKarp.test.cpp
documentation_of: graph/HopcroftKarp.h
layout: document
redirect_from:
- /library/graph/HopcroftKarp.h
- /library/graph/HopcroftKarp.h.html
title: graph/HopcroftKarp.h
---
