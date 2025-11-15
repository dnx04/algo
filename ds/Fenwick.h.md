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
  bundledCode: "#line 1 \"ds/Fenwick.h\"\ntemplate <typename T>\nstruct Fenwick {\
    \  // 1-indexed\n  int n;\n  vector<T> t;\n  Fenwick(int n) : n(n), t(n + 1, T(0))\
    \ {}\n  void add(int p, T v) {\n    while (p <= n) t[p] += v, p += (p & -p);\n\
    \  }\n  T sum(int p) {\n    T res = 0;\n    while (p) res += t[p], p -= (p & -p);\n\
    \    return res;\n  }\n  T sum(int l, int r) {\n    if (l > r) return T(0);\n\
    \    return sum(r) - sum(l - 1);\n  }\n};\n"
  code: "template <typename T>\nstruct Fenwick {  // 1-indexed\n  int n;\n  vector<T>\
    \ t;\n  Fenwick(int n) : n(n), t(n + 1, T(0)) {}\n  void add(int p, T v) {\n \
    \   while (p <= n) t[p] += v, p += (p & -p);\n  }\n  T sum(int p) {\n    T res\
    \ = 0;\n    while (p) res += t[p], p -= (p & -p);\n    return res;\n  }\n  T sum(int\
    \ l, int r) {\n    if (l > r) return T(0);\n    return sum(r) - sum(l - 1);\n\
    \  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/Fenwick.h
  requiredBy: []
  timestamp: '2025-11-15 18:26:28+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/Vertex_Add_Path_Sum.test.cpp
documentation_of: ds/Fenwick.h
layout: document
redirect_from:
- /library/ds/Fenwick.h
- /library/ds/Fenwick.h.html
title: ds/Fenwick.h
---
