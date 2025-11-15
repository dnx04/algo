---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/Sqrt_Mod.test.cpp
    title: tests/Sqrt_Mod.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/ModSQRT.h\"\nll modsqrt(ll a, ll p) {\n  a %= p;\n\
    \  if (a < 0) a += p;\n  if (a == 0) return 0;\n\n  if (modpow(a, (p - 1) / 2,\
    \ p) != 1) return -1;\n  if (p % 4 == 3) return modpow(a, (p + 1) / 4, p);\n \
    \ // a^(n+3)/8 or 2^(n+3)/8 * 2^(n-1)/4 works if p % 8 == 5\n  ll s = p - 1, n\
    \ = 2;\n  int r = 0, m;\n  while (s % 2 == 0) ++r, s /= 2;\n  /// find a non-square\
    \ mod p\n  while (modpow(n, (p - 1) / 2, p) != p - 1) ++n;\n  ll x = modpow(a,\
    \ (s + 1) / 2, p);\n  ll b = modpow(a, s, p), g = modpow(n, s, p);\n  for (;;\
    \ r = m) {\n    ll t = b;\n    for (m = 0; m < r && t != 1; ++m) t = t * t % p;\n\
    \    if (m == 0) return x;\n    ll gs = modpow(g, 1LL << (r - m - 1), p);\n  \
    \  g = gs * gs % p;\n    x = x * gs % p;\n    b = b * g % p;\n  }\n}\n"
  code: "ll modsqrt(ll a, ll p) {\n  a %= p;\n  if (a < 0) a += p;\n  if (a == 0)\
    \ return 0;\n\n  if (modpow(a, (p - 1) / 2, p) != 1) return -1;\n  if (p % 4 ==\
    \ 3) return modpow(a, (p + 1) / 4, p);\n  // a^(n+3)/8 or 2^(n+3)/8 * 2^(n-1)/4\
    \ works if p % 8 == 5\n  ll s = p - 1, n = 2;\n  int r = 0, m;\n  while (s % 2\
    \ == 0) ++r, s /= 2;\n  /// find a non-square mod p\n  while (modpow(n, (p - 1)\
    \ / 2, p) != p - 1) ++n;\n  ll x = modpow(a, (s + 1) / 2, p);\n  ll b = modpow(a,\
    \ s, p), g = modpow(n, s, p);\n  for (;; r = m) {\n    ll t = b;\n    for (m =\
    \ 0; m < r && t != 1; ++m) t = t * t % p;\n    if (m == 0) return x;\n    ll gs\
    \ = modpow(g, 1LL << (r - m - 1), p);\n    g = gs * gs % p;\n    x = x * gs %\
    \ p;\n    b = b * g % p;\n  }\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/ModSQRT.h
  requiredBy: []
  timestamp: '2025-11-15 18:26:28+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/Sqrt_Mod.test.cpp
documentation_of: math/ModSQRT.h
layout: document
redirect_from:
- /library/math/ModSQRT.h
- /library/math/ModSQRT.h.html
title: math/ModSQRT.h
---
