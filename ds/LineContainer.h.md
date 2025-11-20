---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/Line_Add_Get_Min.test.cpp
    title: tests/Line_Add_Get_Min.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/LineContainer.h\"\nstruct Line {\n  mutable i64 k, m,\
    \ p;\n  bool operator<(const Line& o) const { return k < o.k; }\n  bool operator<(i64\
    \ x) const { return p < x; }\n};\n\nstruct LineContainer : multiset<Line, less<>>\
    \ {\n  // (for lds, use inf = 1/.0, div(a,b) = a/b)\n  static const i64 inf =\
    \ LLONG_MAX;\n  i64 div(i64 a, i64 b) {  // floored division\n    return a / b\
    \ - ((a ^ b) < 0 && a % b);\n  }\n  bool isect(iterator x, iterator y) {\n   \
    \ if (y == end()) return x->p = inf, 0;\n    if (x->k == y->k)\n      x->p = x->m\
    \ > y->m ? inf : -inf;\n    else\n      x->p = div(y->m - x->m, x->k - y->k);\n\
    \    return x->p >= y->p;\n  }\n  void add(i64 k, i64 m) {\n    auto z = insert({k,\
    \ m, 0}), y = z++, x = y;\n    while (isect(y, z)) z = erase(z);\n    if (x !=\
    \ begin() && isect(--x, y)) isect(x, y = erase(y));\n    while ((y = x) != begin()\
    \ && (--x)->p >= y->p) isect(x, erase(y));\n  }\n  i64 query(i64 x) {\n    assert(!empty());\n\
    \    auto l = *lower_bound(x);\n    return l.k * x + l.m;\n  }\n};\n"
  code: "struct Line {\n  mutable i64 k, m, p;\n  bool operator<(const Line& o) const\
    \ { return k < o.k; }\n  bool operator<(i64 x) const { return p < x; }\n};\n\n\
    struct LineContainer : multiset<Line, less<>> {\n  // (for lds, use inf = 1/.0,\
    \ div(a,b) = a/b)\n  static const i64 inf = LLONG_MAX;\n  i64 div(i64 a, i64 b)\
    \ {  // floored division\n    return a / b - ((a ^ b) < 0 && a % b);\n  }\n  bool\
    \ isect(iterator x, iterator y) {\n    if (y == end()) return x->p = inf, 0;\n\
    \    if (x->k == y->k)\n      x->p = x->m > y->m ? inf : -inf;\n    else\n   \
    \   x->p = div(y->m - x->m, x->k - y->k);\n    return x->p >= y->p;\n  }\n  void\
    \ add(i64 k, i64 m) {\n    auto z = insert({k, m, 0}), y = z++, x = y;\n    while\
    \ (isect(y, z)) z = erase(z);\n    if (x != begin() && isect(--x, y)) isect(x,\
    \ y = erase(y));\n    while ((y = x) != begin() && (--x)->p >= y->p) isect(x,\
    \ erase(y));\n  }\n  i64 query(i64 x) {\n    assert(!empty());\n    auto l = *lower_bound(x);\n\
    \    return l.k * x + l.m;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/LineContainer.h
  requiredBy: []
  timestamp: '2025-11-18 16:58:39+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/Line_Add_Get_Min.test.cpp
documentation_of: ds/LineContainer.h
layout: document
redirect_from:
- /library/ds/LineContainer.h
- /library/ds/LineContainer.h.html
title: ds/LineContainer.h
---
