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
  bundledCode: "#line 1 \"math/CRT.h\"\ntemplate <typename T>\nstruct CRT {\n  T res;\n\
    \  CRT() { res = 0, prd = 1; }\n  // Add condition: res % p == r\n  void add(T\
    \ p, T r) {\n    res += mul(r - res % p + p, euclid(prd, p).first + p, p) * prd;\n\
    \    prd *= p;\n    if (res >= prd) res -= prd;\n  }\n\n private:\n  T prd;\n\
    \  T mul(T a, T b, T p) {\n    a %= p, b %= p;\n    T q = (T)((long double)a *\
    \ b / p);\n    T r = a * b - q * p;\n    while (r < 0) r += p;\n    while (r >=\
    \ p) r -= p;\n    return r;\n  }\n  pair<T, T> euclid(T a, T b) {\n    if (!b)\
    \ return make_pair(1, 0);\n    pair<T, T> r = euclid(b, a % b);\n    return make_pair(r.second,\
    \ r.first - a / b * r.second);\n  }\n};\n"
  code: "template <typename T>\nstruct CRT {\n  T res;\n  CRT() { res = 0, prd = 1;\
    \ }\n  // Add condition: res % p == r\n  void add(T p, T r) {\n    res += mul(r\
    \ - res % p + p, euclid(prd, p).first + p, p) * prd;\n    prd *= p;\n    if (res\
    \ >= prd) res -= prd;\n  }\n\n private:\n  T prd;\n  T mul(T a, T b, T p) {\n\
    \    a %= p, b %= p;\n    T q = (T)((long double)a * b / p);\n    T r = a * b\
    \ - q * p;\n    while (r < 0) r += p;\n    while (r >= p) r -= p;\n    return\
    \ r;\n  }\n  pair<T, T> euclid(T a, T b) {\n    if (!b) return make_pair(1, 0);\n\
    \    pair<T, T> r = euclid(b, a % b);\n    return make_pair(r.second, r.first\
    \ - a / b * r.second);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/CRT.h
  requiredBy: []
  timestamp: '2025-11-15 18:26:28+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/CRT.h
layout: document
redirect_from:
- /library/math/CRT.h
- /library/math/CRT.h.html
title: math/CRT.h
---
