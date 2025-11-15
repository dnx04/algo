---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/Sum_of_Floor_of_Linear.test.cpp
    title: tests/Sum_of_Floor_of_Linear.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/DivModSum.h\"\nll sumsq(ll to) { return to / 2 * ((to\
    \ - 1) | 1); }\n\n// sum( (a + d*i) / m ) for i in [0, n-1]\nll divsum(ll a, ll\
    \ d, ll m, ll n) {\n  ll res = d / m * sumsq(n) + a / m * n;\n  d %= m, a %= m;\n\
    \  if (!d) return res;\n  ll to = (n * d + a) / m;\n  return res + (n - 1) * to\
    \ - divsum(m - 1 - a, m, d, to);\n}\n// sum( (a + d*i) % m ) for i in [0, n-1]\n\
    ll modsum(ll a, ll d, ll m, ll n) {\n  a = ((a % m) + m) % m, d = ((d % m) + m)\
    \ % m;\n  return n * a + d * sumsq(n) - m * divsum(a, d, m, n);\n}\n"
  code: "ll sumsq(ll to) { return to / 2 * ((to - 1) | 1); }\n\n// sum( (a + d*i)\
    \ / m ) for i in [0, n-1]\nll divsum(ll a, ll d, ll m, ll n) {\n  ll res = d /\
    \ m * sumsq(n) + a / m * n;\n  d %= m, a %= m;\n  if (!d) return res;\n  ll to\
    \ = (n * d + a) / m;\n  return res + (n - 1) * to - divsum(m - 1 - a, m, d, to);\n\
    }\n// sum( (a + d*i) % m ) for i in [0, n-1]\nll modsum(ll a, ll d, ll m, ll n)\
    \ {\n  a = ((a % m) + m) % m, d = ((d % m) + m) % m;\n  return n * a + d * sumsq(n)\
    \ - m * divsum(a, d, m, n);\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/DivModSum.h
  requiredBy: []
  timestamp: '2025-11-15 18:26:28+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/Sum_of_Floor_of_Linear.test.cpp
documentation_of: math/DivModSum.h
layout: document
redirect_from:
- /library/math/DivModSum.h
- /library/math/DivModSum.h.html
title: math/DivModSum.h
---
