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
  bundledCode: "#line 1 \"math/XorBasis.h\"\ntemplate <class T>\nstruct Basis {\n\
    \  int B; vector<T> a; vector<i64> wt;\n  Basis() : B(sizeof(T) * 8), a(B, 0),\
    \ wt(B, 0) {}\n  void insert(T x, i64 w = 0) {\n    for (int i = B - 1; i >= 0;\
    \ --i) if (x >> i & 1) {\n      if (!a[i]) { a[i] = x, wt[i] = w; return; }\n\
    \      if (wt[i] < w) swap(wt[i], w), swap(a[i], x);\n      x ^= a[i];\n    }\n\
    \  }\n  i64 query() {\n    i64 ans = 0;\n    for (auto w : wt) ans += w;\n   \
    \ return ans;\n  }\n  friend Basis intersect(const Basis& L, const Basis& R) {\n\
    \    Basis res, full; int B = L.B; vector<T> mask(B, 0);\n    for (T x : L.a)\
    \ if (x)\n      for (int j = B - 1; j >= 0; --j) if (x >> j & 1) {\n        if\
    \ (!full.a[j]) { full.a[j] = x; break; }\n        x ^= full.a[j];\n      }\n \
    \   for (T x : R.a) if (x) {\n      T m = x; bool k = 1;\n      for (int j = B\
    \ - 1; j >= 0; --j) if (x >> j & 1) {\n        if (!full.a[j]) { full.a[j] = x,\
    \ mask[j] = m, k = 0; break; }\n        x ^= full.a[j], m ^= mask[j];\n      }\n\
    \      if (k) res.insert(m);\n    }\n    return res;\n  }\n};\n"
  code: "template <class T>\nstruct Basis {\n  int B; vector<T> a; vector<i64> wt;\n\
    \  Basis() : B(sizeof(T) * 8), a(B, 0), wt(B, 0) {}\n  void insert(T x, i64 w\
    \ = 0) {\n    for (int i = B - 1; i >= 0; --i) if (x >> i & 1) {\n      if (!a[i])\
    \ { a[i] = x, wt[i] = w; return; }\n      if (wt[i] < w) swap(wt[i], w), swap(a[i],\
    \ x);\n      x ^= a[i];\n    }\n  }\n  i64 query() {\n    i64 ans = 0;\n    for\
    \ (auto w : wt) ans += w;\n    return ans;\n  }\n  friend Basis intersect(const\
    \ Basis& L, const Basis& R) {\n    Basis res, full; int B = L.B; vector<T> mask(B,\
    \ 0);\n    for (T x : L.a) if (x)\n      for (int j = B - 1; j >= 0; --j) if (x\
    \ >> j & 1) {\n        if (!full.a[j]) { full.a[j] = x; break; }\n        x ^=\
    \ full.a[j];\n      }\n    for (T x : R.a) if (x) {\n      T m = x; bool k = 1;\n\
    \      for (int j = B - 1; j >= 0; --j) if (x >> j & 1) {\n        if (!full.a[j])\
    \ { full.a[j] = x, mask[j] = m, k = 0; break; }\n        x ^= full.a[j], m ^=\
    \ mask[j];\n      }\n      if (k) res.insert(m);\n    }\n    return res;\n  }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: math/XorBasis.h
  requiredBy: []
  timestamp: '2025-12-09 07:33:19+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/XorBasis.h
layout: document
redirect_from:
- /library/math/XorBasis.h
- /library/math/XorBasis.h.html
title: math/XorBasis.h
---
