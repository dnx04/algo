---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/Discrete_Logarithm.test.cpp
    title: tests/Discrete_Logarithm.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/ModLog.h\"\nll modLog(ll a, ll b, ll m) {\n  ll n =\
    \ (ll) sqrt(m) + 1, e = 1, f = 1, j = 1;\n  unordered_map<ll, ll> A;\n  while\
    \ (j <= n && (e = f = e * a % m) != b % m) A[e * b % m] = j++;\n  if (e == b %\
    \ m) return j;\n  if (gcd(m, e) == gcd(m, b)) {\n    for (int i = 2; i < n + 2;\
    \ ++i) {\n      if (A.count(e = e * f % m)) return n * i - A[e];\n    }\n  }\n\
    \  return -1;\n}\n"
  code: "ll modLog(ll a, ll b, ll m) {\n  ll n = (ll) sqrt(m) + 1, e = 1, f = 1, j\
    \ = 1;\n  unordered_map<ll, ll> A;\n  while (j <= n && (e = f = e * a % m) !=\
    \ b % m) A[e * b % m] = j++;\n  if (e == b % m) return j;\n  if (gcd(m, e) ==\
    \ gcd(m, b)) {\n    for (int i = 2; i < n + 2; ++i) {\n      if (A.count(e = e\
    \ * f % m)) return n * i - A[e];\n    }\n  }\n  return -1;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/ModLog.h
  requiredBy: []
  timestamp: '2025-11-15 18:26:28+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/Discrete_Logarithm.test.cpp
documentation_of: math/ModLog.h
layout: document
redirect_from:
- /library/math/ModLog.h
- /library/math/ModLog.h.html
title: math/ModLog.h
---
