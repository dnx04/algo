---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/Range_Affine_Point_Get.test.cpp
    title: tests/Range_Affine_Point_Get.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Range_Affine_Range_Sum.test.cpp
    title: tests/Range_Affine_Range_Sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/LazySegTree.h\"\ntemplate <typename T, typename L>\n\
    struct LazySegTree {\n  int n, h;\n  vector<T> seg;\n  vector<L> lazy;\n  const\
    \ T I;   // Identity node (e.g., 0 for sum, INF for min)\n  const L L0;  // Identity\
    \ lazy (e.g., 0 for add, -1 for set)\n  // f: Merge 2 nodes (T, T) -> T\n  //\
    \ m: Mapping lazy to node (T, L) -> T\n  // c: Composition 2 lazy (L, L) -> L\n\
    \  function<T(T, T)> f;\n  function<T(T, L)> m;\n  function<L(L, L)> c;\n  LazySegTree(int\
    \ n, T I, L L0, auto f, auto m, auto c) : n(n), h(32 - __builtin_clz(n)), seg(2\
    \ * n, I), lazy(n, L0), I(I), L0(L0), f(f), m(m), c(c) {}\n  void apply(int p,\
    \ L val) {\n    seg[p] = m(seg[p], val);\n    if (p < n) lazy[p] = c(lazy[p],\
    \ val);\n  }\n  void pull(int p) {\n    while (p > 1) {\n      p >>= 1;\n    \
    \  seg[p] = m(f(seg[2 * p], seg[2 * p + 1]), lazy[p]);\n    }\n  }\n  void push(int\
    \ p) {\n    for (int s = h; s > 0; --s) {\n      int i = p >> s;\n      if (lazy[i]\
    \ != L0) {\n        apply(2 * i, lazy[i]);\n        apply(2 * i + 1, lazy[i]);\n\
    \        lazy[i] = L0;\n      }\n    }\n  }\n  void set(int p, T x) {\n    p +=\
    \ n;\n    for (int i = h; i > 0; --i) {  // C\u1EA7n push s\u1EA1ch \u0111\u01B0\
    \u1EDDng \u0111i tr\u01B0\u1EDBc khi set\n      int node = p >> i;\n      if (lazy[node]\
    \ != L0) {\n        apply(2 * node, lazy[node]);\n        apply(2 * node + 1,\
    \ lazy[node]);\n        lazy[node] = L0;\n      }\n    }\n    seg[p] = x, pull(p);\
    \  // C\u1EADp nh\u1EADt ng\u01B0\u1EE3c l\xEAn\n  }\n  // Update \u0111o\u1EA1\
    n [l, r)\n  void upd(int l, int r, L val) {\n    l += n, r += n;\n    int l0 =\
    \ l, r0 = r;\n    push(l0), push(r0 - 1);\n    for (; l < r; l >>= 1, r >>= 1)\
    \ {\n      if (l & 1) apply(l++, val);\n      if (r & 1) apply(--r, val);\n  \
    \  }\n    pull(l0), pull(r0 - 1);\n  }\n  // Query \u0111o\u1EA1n [l, r)\n  T\
    \ qry(int l, int r) {\n    l += n, r += n;\n    push(l), push(r - 1);\n    T resL\
    \ = I, resR = I;\n    for (; l < r; l >>= 1, r >>= 1) {\n      if (l & 1) resL\
    \ = f(resL, seg[l++]);\n      if (r & 1) resR = f(seg[--r], resR);\n    }\n  \
    \  return f(resL, resR);\n  }\n};\n"
  code: "template <typename T, typename L>\nstruct LazySegTree {\n  int n, h;\n  vector<T>\
    \ seg;\n  vector<L> lazy;\n  const T I;   // Identity node (e.g., 0 for sum, INF\
    \ for min)\n  const L L0;  // Identity lazy (e.g., 0 for add, -1 for set)\n  //\
    \ f: Merge 2 nodes (T, T) -> T\n  // m: Mapping lazy to node (T, L) -> T\n  //\
    \ c: Composition 2 lazy (L, L) -> L\n  function<T(T, T)> f;\n  function<T(T, L)>\
    \ m;\n  function<L(L, L)> c;\n  LazySegTree(int n, T I, L L0, auto f, auto m,\
    \ auto c) : n(n), h(32 - __builtin_clz(n)), seg(2 * n, I), lazy(n, L0), I(I),\
    \ L0(L0), f(f), m(m), c(c) {}\n  void apply(int p, L val) {\n    seg[p] = m(seg[p],\
    \ val);\n    if (p < n) lazy[p] = c(lazy[p], val);\n  }\n  void pull(int p) {\n\
    \    while (p > 1) {\n      p >>= 1;\n      seg[p] = m(f(seg[2 * p], seg[2 * p\
    \ + 1]), lazy[p]);\n    }\n  }\n  void push(int p) {\n    for (int s = h; s >\
    \ 0; --s) {\n      int i = p >> s;\n      if (lazy[i] != L0) {\n        apply(2\
    \ * i, lazy[i]);\n        apply(2 * i + 1, lazy[i]);\n        lazy[i] = L0;\n\
    \      }\n    }\n  }\n  void set(int p, T x) {\n    p += n;\n    for (int i =\
    \ h; i > 0; --i) {  // C\u1EA7n push s\u1EA1ch \u0111\u01B0\u1EDDng \u0111i tr\u01B0\
    \u1EDBc khi set\n      int node = p >> i;\n      if (lazy[node] != L0) {\n   \
    \     apply(2 * node, lazy[node]);\n        apply(2 * node + 1, lazy[node]);\n\
    \        lazy[node] = L0;\n      }\n    }\n    seg[p] = x, pull(p);  // C\u1EAD\
    p nh\u1EADt ng\u01B0\u1EE3c l\xEAn\n  }\n  // Update \u0111o\u1EA1n [l, r)\n \
    \ void upd(int l, int r, L val) {\n    l += n, r += n;\n    int l0 = l, r0 = r;\n\
    \    push(l0), push(r0 - 1);\n    for (; l < r; l >>= 1, r >>= 1) {\n      if\
    \ (l & 1) apply(l++, val);\n      if (r & 1) apply(--r, val);\n    }\n    pull(l0),\
    \ pull(r0 - 1);\n  }\n  // Query \u0111o\u1EA1n [l, r)\n  T qry(int l, int r)\
    \ {\n    l += n, r += n;\n    push(l), push(r - 1);\n    T resL = I, resR = I;\n\
    \    for (; l < r; l >>= 1, r >>= 1) {\n      if (l & 1) resL = f(resL, seg[l++]);\n\
    \      if (r & 1) resR = f(seg[--r], resR);\n    }\n    return f(resL, resR);\n\
    \  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/LazySegTree.h
  requiredBy: []
  timestamp: '2025-11-18 22:42:15+07:00'
  verificationStatus: LIBRARY_ALL_AC
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
