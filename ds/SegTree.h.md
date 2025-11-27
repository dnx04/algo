---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: tests/LIS.test.cpp
    title: tests/LIS.test.cpp
  - icon: ':x:'
    path: tests/Point_Set_Range_Composite.test.cpp
    title: tests/Point_Set_Range_Composite.test.cpp
  _isVerificationFailed: true
  _pathExtension: h
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/SegTree.h\"\n// 0-indexed\ntemplate <class T, class F>\n\
    struct SegTree {\n  int n, size;  // smallest size = 2^k >= n\n  vector<T> seg;\n\
    \  const F f;\n  const T I;\n  SegTree(int n, F f, const T& I) : n(n), f(f), I(I)\
    \ {\n    size = 1;\n    while (size < n) size <<= 1;\n    seg.assign(size << 1,\
    \ I);\n  }\n  T& operator[](int k) { return seg[k + size]; }\n  void set(int k,\
    \ T x) { seg[k + size] = x; }  // to build\n  void build() {\n    for (int i =\
    \ size - 1; i > 0; --i) seg[i] = f(seg[i << 1], seg[i << 1 | 1]);\n  }\n  void\
    \ apply(int k, T x) {\n    k += size, seg[k] = x;\n    while (k >>= 1) seg[k]\
    \ = f(seg[k << 1], seg[k << 1 | 1]);\n  }\n  // query [l, r)\n  T query(int l,\
    \ int r) {\n    T L = I, R = I;\n    for (l += size, r += size; l < r; l >>= 1,\
    \ r >>= 1) {\n      if (l & 1) L = f(L, seg[l++]);\n      if (r & 1) R = f(seg[--r],\
    \ R);\n    }\n    return f(L, R);\n  }\n  template <class C>\n  int max_right(int\
    \ l, C check) {\n    assert(0 <= l && l <= n && check(I) == true);\n    if (l\
    \ == n) return n;\n    l += size;\n    T sm = I;\n    do {\n      while (l % 2\
    \ == 0) l >>= 1;\n      if (!check(f(sm, seg[l]))) {\n        while (l < size)\
    \ {\n          l = l << 1;\n          if (check(f(sm, seg[l]))) sm = f(sm, seg[l]),\
    \ l++;\n        }\n        return l - size;\n      }\n      sm = f(sm, seg[l]),\
    \ l++;\n    } while ((l & -l) != l);\n    return n;\n  }\n  template <class C>\n\
    \  int min_left(int r, C check) {\n    assert(0 <= r && r <= n && check(I) ==\
    \ true);\n    if (r == 0) return 0;\n    r += size;\n    T sm = I;\n    do {\n\
    \      r--;\n      while (r > 1 && (r % 2)) r >>= 1;\n      if (!check(f(seg[r],\
    \ sm))) {\n        while (r < size) {\n          r = r << 1 | 1;\n          if\
    \ (check(f(seg[r], sm))) sm = f(seg[r], sm), r--;\n        }\n        return r\
    \ + 1 - size;\n      }\n      sm = f(seg[r], sm);\n    } while ((r & -r) != r);\n\
    \    return 0;\n  }\n};\n"
  code: "// 0-indexed\ntemplate <class T, class F>\nstruct SegTree {\n  int n, size;\
    \  // smallest size = 2^k >= n\n  vector<T> seg;\n  const F f;\n  const T I;\n\
    \  SegTree(int n, F f, const T& I) : n(n), f(f), I(I) {\n    size = 1;\n    while\
    \ (size < n) size <<= 1;\n    seg.assign(size << 1, I);\n  }\n  T& operator[](int\
    \ k) { return seg[k + size]; }\n  void set(int k, T x) { seg[k + size] = x; }\
    \  // to build\n  void build() {\n    for (int i = size - 1; i > 0; --i) seg[i]\
    \ = f(seg[i << 1], seg[i << 1 | 1]);\n  }\n  void apply(int k, T x) {\n    k +=\
    \ size, seg[k] = x;\n    while (k >>= 1) seg[k] = f(seg[k << 1], seg[k << 1 |\
    \ 1]);\n  }\n  // query [l, r)\n  T query(int l, int r) {\n    T L = I, R = I;\n\
    \    for (l += size, r += size; l < r; l >>= 1, r >>= 1) {\n      if (l & 1) L\
    \ = f(L, seg[l++]);\n      if (r & 1) R = f(seg[--r], R);\n    }\n    return f(L,\
    \ R);\n  }\n  template <class C>\n  int max_right(int l, C check) {\n    assert(0\
    \ <= l && l <= n && check(I) == true);\n    if (l == n) return n;\n    l += size;\n\
    \    T sm = I;\n    do {\n      while (l % 2 == 0) l >>= 1;\n      if (!check(f(sm,\
    \ seg[l]))) {\n        while (l < size) {\n          l = l << 1;\n          if\
    \ (check(f(sm, seg[l]))) sm = f(sm, seg[l]), l++;\n        }\n        return l\
    \ - size;\n      }\n      sm = f(sm, seg[l]), l++;\n    } while ((l & -l) != l);\n\
    \    return n;\n  }\n  template <class C>\n  int min_left(int r, C check) {\n\
    \    assert(0 <= r && r <= n && check(I) == true);\n    if (r == 0) return 0;\n\
    \    r += size;\n    T sm = I;\n    do {\n      r--;\n      while (r > 1 && (r\
    \ % 2)) r >>= 1;\n      if (!check(f(seg[r], sm))) {\n        while (r < size)\
    \ {\n          r = r << 1 | 1;\n          if (check(f(seg[r], sm))) sm = f(seg[r],\
    \ sm), r--;\n        }\n        return r + 1 - size;\n      }\n      sm = f(seg[r],\
    \ sm);\n    } while ((r & -r) != r);\n    return 0;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/SegTree.h
  requiredBy: []
  timestamp: '2025-11-21 16:12:02+07:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - tests/LIS.test.cpp
  - tests/Point_Set_Range_Composite.test.cpp
documentation_of: ds/SegTree.h
layout: document
redirect_from:
- /library/ds/SegTree.h
- /library/ds/SegTree.h.html
title: ds/SegTree.h
---
