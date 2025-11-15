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
  bundledCode: "#line 1 \"ds/LineContainer.h\"\nstruct Line {\n  mutable ll k, m,\
    \ p;\n  bool operator<(const Line& o) const { return k < o.k; }\n  bool operator<(ll\
    \ x) const { return p < x; }\n};\n\nstruct LineContainer : multiset<Line, less<>>\
    \ {\n  // (for doubles, use inf = 1/.0, div(a,b) = a/b)\n  static const ll inf\
    \ = LLONG_MAX;\n  ll div(ll a, ll b) {  // floored division\n    return a / b\
    \ - ((a ^ b) < 0 && a % b);\n  }\n  bool isect(iterator x, iterator y) {\n   \
    \ if (y == end()) return x->p = inf, 0;\n    if (x->k == y->k)\n      x->p = x->m\
    \ > y->m ? inf : -inf;\n    else\n      x->p = div(y->m - x->m, x->k - y->k);\n\
    \    return x->p >= y->p;\n  }\n  void add(ll k, ll m) {\n    auto z = insert({k,\
    \ m, 0}), y = z++, x = y;\n    while (isect(y, z)) z = erase(z);\n    if (x !=\
    \ begin() && isect(--x, y)) isect(x, y = erase(y));\n    while ((y = x) != begin()\
    \ && (--x)->p >= y->p) isect(x, erase(y));\n  }\n  ll query(ll x) {\n    assert(!empty());\n\
    \    auto l = *lower_bound(x);\n    return l.k * x + l.m;\n  }\n};\n"
  code: "struct Line {\n  mutable ll k, m, p;\n  bool operator<(const Line& o) const\
    \ { return k < o.k; }\n  bool operator<(ll x) const { return p < x; }\n};\n\n\
    struct LineContainer : multiset<Line, less<>> {\n  // (for doubles, use inf =\
    \ 1/.0, div(a,b) = a/b)\n  static const ll inf = LLONG_MAX;\n  ll div(ll a, ll\
    \ b) {  // floored division\n    return a / b - ((a ^ b) < 0 && a % b);\n  }\n\
    \  bool isect(iterator x, iterator y) {\n    if (y == end()) return x->p = inf,\
    \ 0;\n    if (x->k == y->k)\n      x->p = x->m > y->m ? inf : -inf;\n    else\n\
    \      x->p = div(y->m - x->m, x->k - y->k);\n    return x->p >= y->p;\n  }\n\
    \  void add(ll k, ll m) {\n    auto z = insert({k, m, 0}), y = z++, x = y;\n \
    \   while (isect(y, z)) z = erase(z);\n    if (x != begin() && isect(--x, y))\
    \ isect(x, y = erase(y));\n    while ((y = x) != begin() && (--x)->p >= y->p)\
    \ isect(x, erase(y));\n  }\n  ll query(ll x) {\n    assert(!empty());\n    auto\
    \ l = *lower_bound(x);\n    return l.k * x + l.m;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/LineContainer.h
  requiredBy: []
  timestamp: '2025-11-15 18:26:28+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/LineContainer.h
layout: document
redirect_from:
- /library/ds/LineContainer.h
- /library/ds/LineContainer.h.html
title: ds/LineContainer.h
---
