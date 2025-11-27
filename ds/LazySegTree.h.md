---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: tests/Range_Affine_Point_Get.test.cpp
    title: tests/Range_Affine_Point_Get.test.cpp
  - icon: ':x:'
    path: tests/Range_Affine_Range_Sum.test.cpp
    title: tests/Range_Affine_Range_Sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: h
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/LazySegTree.h\"\n// 0-indexed\ntemplate <class T, class\
    \ L, class F, class M, class C>\nstruct LazySegTree {\n private:\n  int n, h;\n\
    \  vector<T> seg;\n  vector<L> laz;\n  const T I;   // Identity node (e.g., 0\
    \ for sum, INF for min)\n  const L L0;  // Identity laz (e.g., 0 for add, -1 for\
    \ set)\n  const F f;   // f: Merge 2 nodes (T, T) -> T\n  const M m;   // m: Mapping\
    \ laz to node (T, L) -> T\n  const C c;   // c: Composition 2 laz (L prev, L next)\
    \ -> next(prev)\n  void apply(int p, L val) {\n    seg[p] = m(seg[p], val);\n\
    \    if (p < n) laz[p] = c(laz[p], val);\n  }\n  void pull(int p) {\n    while\
    \ (p > 1) {\n      p >>= 1;\n      seg[p] = m(f(seg[p << 1], seg[p << 1 | 1]),\
    \ laz[p]);\n    }\n  }\n  void push(int p) {\n    for (int s = h; s > 0; --s)\
    \ {\n      int i = p >> s;\n      if (laz[i] != L0) apply(i << 1, laz[i]), apply(i\
    \ << 1 | 1, laz[i]), laz[i] = L0;\n    }\n  }\n\n public:\n  LazySegTree(int n,\
    \ T I, L L0, F f, M m, C c) : n(n), h(32 - __builtin_clz(n)), seg(n << 1 | 1,\
    \ I), laz(n, L0), I(I), L0(L0), f(f), m(m), c(c) {}\n  // set p to x\n  void set(int\
    \ p, T x) {\n    p += n;\n    for (int i = h; i > 0; --i) {\n      int k = p >>\
    \ i;\n      if (laz[k] != L0) apply(k << 1, laz[k]), apply(k << 1 | 1, laz[k]),\
    \ laz[k] = L0;\n    }\n    seg[p] = x, pull(p);\n  }\n  // Apply op -> [l, r)\n\
    \  void apply(int l, int r, L op) {\n    l += n, r += n;\n    int l0 = l, r0 =\
    \ r;\n    push(l0), push(r0 - 1);\n    for (; l < r; l >>= 1, r >>= 1) {\n   \
    \   if (l & 1) apply(l++, op);\n      if (r & 1) apply(--r, op);\n    }\n    pull(l0),\
    \ pull(r0 - 1);\n  }\n  // Query [l, r)\n  T query(int l, int r) {\n    l += n,\
    \ r += n;\n    push(l), push(r - 1);\n    T resL = I, resR = I;\n    for (; l\
    \ < r; l >>= 1, r >>= 1) {\n      if (l & 1) resL = f(resL, seg[l++]);\n     \
    \ if (r & 1) resR = f(seg[--r], resR);\n    }\n    return f(resL, resR);\n  }\n\
    };\n"
  code: "// 0-indexed\ntemplate <class T, class L, class F, class M, class C>\nstruct\
    \ LazySegTree {\n private:\n  int n, h;\n  vector<T> seg;\n  vector<L> laz;\n\
    \  const T I;   // Identity node (e.g., 0 for sum, INF for min)\n  const L L0;\
    \  // Identity laz (e.g., 0 for add, -1 for set)\n  const F f;   // f: Merge 2\
    \ nodes (T, T) -> T\n  const M m;   // m: Mapping laz to node (T, L) -> T\n  const\
    \ C c;   // c: Composition 2 laz (L prev, L next) -> next(prev)\n  void apply(int\
    \ p, L val) {\n    seg[p] = m(seg[p], val);\n    if (p < n) laz[p] = c(laz[p],\
    \ val);\n  }\n  void pull(int p) {\n    while (p > 1) {\n      p >>= 1;\n    \
    \  seg[p] = m(f(seg[p << 1], seg[p << 1 | 1]), laz[p]);\n    }\n  }\n  void push(int\
    \ p) {\n    for (int s = h; s > 0; --s) {\n      int i = p >> s;\n      if (laz[i]\
    \ != L0) apply(i << 1, laz[i]), apply(i << 1 | 1, laz[i]), laz[i] = L0;\n    }\n\
    \  }\n\n public:\n  LazySegTree(int n, T I, L L0, F f, M m, C c) : n(n), h(32\
    \ - __builtin_clz(n)), seg(n << 1 | 1, I), laz(n, L0), I(I), L0(L0), f(f), m(m),\
    \ c(c) {}\n  // set p to x\n  void set(int p, T x) {\n    p += n;\n    for (int\
    \ i = h; i > 0; --i) {\n      int k = p >> i;\n      if (laz[k] != L0) apply(k\
    \ << 1, laz[k]), apply(k << 1 | 1, laz[k]), laz[k] = L0;\n    }\n    seg[p] =\
    \ x, pull(p);\n  }\n  // Apply op -> [l, r)\n  void apply(int l, int r, L op)\
    \ {\n    l += n, r += n;\n    int l0 = l, r0 = r;\n    push(l0), push(r0 - 1);\n\
    \    for (; l < r; l >>= 1, r >>= 1) {\n      if (l & 1) apply(l++, op);\n   \
    \   if (r & 1) apply(--r, op);\n    }\n    pull(l0), pull(r0 - 1);\n  }\n  //\
    \ Query [l, r)\n  T query(int l, int r) {\n    l += n, r += n;\n    push(l), push(r\
    \ - 1);\n    T resL = I, resR = I;\n    for (; l < r; l >>= 1, r >>= 1) {\n  \
    \    if (l & 1) resL = f(resL, seg[l++]);\n      if (r & 1) resR = f(seg[--r],\
    \ resR);\n    }\n    return f(resL, resR);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/LazySegTree.h
  requiredBy: []
  timestamp: '2025-11-20 17:14:03+07:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - tests/Range_Affine_Point_Get.test.cpp
  - tests/Range_Affine_Range_Sum.test.cpp
documentation_of: ds/LazySegTree.h
layout: document
redirect_from:
- /library/ds/LazySegTree.h
- /library/ds/LazySegTree.h.html
title: ds/LazySegTree.h
---
