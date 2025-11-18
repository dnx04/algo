---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/Factor.h
    title: math/Factor.h
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/Factorize.test.cpp
    title: tests/Factorize.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Primality_Test.test.cpp
    title: tests/Primality_Test.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/MillerRabin.h\"\nbool isPrime(u64 n) {\n  if (n < 2\
    \ || n % 6 % 4 != 1) return (n | 1) == 3;\n  u64 A[] = {2, 325, 9375, 28178, 450775,\
    \ 9780504, 1795265022},\n      s = __builtin_ctzll(n - 1), d = n >> s;\n  for\
    \ (u64 a : A) {  // ^ count trailing zeroes\n    u64 p = modpow(a % n, d, n),\
    \ i = s;\n    while (p != 1 && p != n - 1 && a % n && i--) p = modmul(p, p, n);\n\
    \    if (p != n - 1 && i != s) return 0;\n  }\n  return 1;\n}\n"
  code: "bool isPrime(u64 n) {\n  if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;\n\
    \  u64 A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},\n      s = __builtin_ctzll(n\
    \ - 1), d = n >> s;\n  for (u64 a : A) {  // ^ count trailing zeroes\n    u64\
    \ p = modpow(a % n, d, n), i = s;\n    while (p != 1 && p != n - 1 && a % n &&\
    \ i--) p = modmul(p, p, n);\n    if (p != n - 1 && i != s) return 0;\n  }\n  return\
    \ 1;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/MillerRabin.h
  requiredBy:
  - math/Factor.h
  timestamp: '2025-11-18 17:42:34+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/Factorize.test.cpp
  - tests/Primality_Test.test.cpp
documentation_of: math/MillerRabin.h
layout: document
redirect_from:
- /library/math/MillerRabin.h
- /library/math/MillerRabin.h.html
title: math/MillerRabin.h
---
