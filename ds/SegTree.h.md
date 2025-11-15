---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/Point_Set_Range_Composite.test.cpp
    title: tests/Point_Set_Range_Composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/SegTree.h\"\ntemplate <typename T, typename F>\nstruct\
    \ SegTree {  // 1-indexed\n  int n;\n  vector<T> seg;\n  const F f;\n  const T\
    \ I;\n  SegTree(int n, F f, const T& I) : n(n), seg(2 * n + 1), f(f), I(I) {}\n\
    \  void set(int k, T x) { seg[k + n] = x; }\n  void upd(int k, T x) {\n    k +=\
    \ n, seg[k] = x;\n    while (k >>= 1) {\n      seg[k] = f(seg[k << 1], seg[k <<\
    \ 1 | 1]);\n    }\n  }\n  // query [l, r)\n  T qry(int l, int r) {\n    T L =\
    \ I, R = I;\n    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {\n      if (l\
    \ & 1) L = f(L, seg[l++]);\n      if (r & 1) R = f(seg[--r], R);\n    }\n    return\
    \ f(L, R);\n  }\n  T& operator[](const int& k) { return seg[k + n]; }\n};\n"
  code: "template <typename T, typename F>\nstruct SegTree {  // 1-indexed\n  int\
    \ n;\n  vector<T> seg;\n  const F f;\n  const T I;\n  SegTree(int n, F f, const\
    \ T& I) : n(n), seg(2 * n + 1), f(f), I(I) {}\n  void set(int k, T x) { seg[k\
    \ + n] = x; }\n  void upd(int k, T x) {\n    k += n, seg[k] = x;\n    while (k\
    \ >>= 1) {\n      seg[k] = f(seg[k << 1], seg[k << 1 | 1]);\n    }\n  }\n  //\
    \ query [l, r)\n  T qry(int l, int r) {\n    T L = I, R = I;\n    for (l += n,\
    \ r += n; l < r; l >>= 1, r >>= 1) {\n      if (l & 1) L = f(L, seg[l++]);\n \
    \     if (r & 1) R = f(seg[--r], R);\n    }\n    return f(L, R);\n  }\n  T& operator[](const\
    \ int& k) { return seg[k + n]; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/SegTree.h
  requiredBy: []
  timestamp: '2025-11-15 18:26:28+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/Point_Set_Range_Composite.test.cpp
documentation_of: ds/SegTree.h
layout: document
redirect_from:
- /library/ds/SegTree.h
- /library/ds/SegTree.h.html
title: ds/SegTree.h
---
