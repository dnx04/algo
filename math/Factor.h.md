---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/MillerRabin.h
    title: math/MillerRabin.h
  - icon: ':heavy_check_mark:'
    path: math/ModInt.h
    title: math/ModInt.h
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/Factorize.test.cpp
    title: tests/Factorize.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Primitive_Root.test.cpp
    title: tests/Primitive_Root.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/ModInt.h\"\n\ntemplate <int mod>\nstruct modint {\n\
    \  using M = modint;\n  static_assert(mod > 0 && mod <= 2147483647);\n  static\
    \ constexpr int modulo = mod;\n  static constexpr u32 r1 = []() {\n    u32 r1\
    \ = mod;\n    for (int i = 0; i < 5; ++i) r1 *= 2 - mod * r1;\n    return -r1;\n\
    \  }();\n  static constexpr u32 r2 = -u64(mod) % mod;\n  static u32 reduce(u64\
    \ x) {\n    u32 y = u32(x) * r1, r = (x + u64(y) * mod) >> 32;\n    return r >=\
    \ mod ? r - mod : r;\n  }\n  u32 x;\n  modint() : x(0) {}\n  modint(i64 x) : x(reduce(u64(x\
    \ % mod + mod) * r2)) {}\n  M& operator+=(const M& a) {\n    if ((x += a.x) >=\
    \ mod) x -= mod;\n    return *this;\n  }\n  M& operator-=(const M& a) {\n    if\
    \ ((x += mod - a.x) >= mod) x -= mod;\n    return *this;\n  }\n  M& operator*=(const\
    \ M& a) {\n    x = reduce(u64(x) * a.x);\n    return *this;\n  }\n  M& operator/=(const\
    \ M& a) { return *this *= a.inv(); }\n  M operator-() const { return M(0) - *this;\
    \ }\n  M operator+(const M& a) const { return M(*this) += a; }\n  M operator-(const\
    \ M& a) const { return M(*this) -= a; }\n  M operator*(const M& a) const { return\
    \ M(*this) *= a; }\n  M operator/(const M& a) const { return M(*this) /= a; }\n\
    \  bool operator==(const M& a) const { return x == a.x; }\n  bool operator!=(const\
    \ M& a) const { return x != a.x; }\n  M pow(u64 k) const {\n    M res(1), b =\
    \ *this;\n    while (k) {\n      if (k & 1) res *= b;\n      b *= b, k >>= 1;\n\
    \    }\n    return res;\n  }\n  M inv() const { return pow(mod - 2); }\n  friend\
    \ ostream& operator<<(ostream& os, const M& a) {\n    return os << reduce(a.x);\n\
    \  }\n  friend istream& operator>>(istream& is, M& a) {\n    i64 v;\n    is >>\
    \ v;\n    a = M(v);\n    return is;\n  }\n};\n\nu64 modmul(u64 x, u64 y, u64 m)\
    \ { return u128(x) * y % m; }\nu64 modpow(u64 x, u64 k, u64 m) {\n  u64 res =\
    \ 1;\n  while (k) {\n    if (k & 1) res = modmul(res, x, m);\n    x = modmul(x,\
    \ x, m);\n    k >>= 1;\n  }\n  return res;\n}\n#line 1 \"math/MillerRabin.h\"\n\
    bool isPrime(u64 n) {\n  if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;\n \
    \ u64 A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},\n      s = __builtin_ctzll(n\
    \ - 1), d = n >> s;\n  for (u64 a : A) {  // ^ count trailing zeroes\n    u64\
    \ p = modpow(a % n, d, n), i = s;\n    while (p != 1 && p != n - 1 && a % n &&\
    \ i--) p = modmul(p, p, n);\n    if (p != n - 1 && i != s) return 0;\n  }\n  return\
    \ 1;\n}\n#line 3 \"math/Factor.h\"\n\nu64 pollard(u64 n) {\n  u64 x = 0, y = 0,\
    \ t = 30, prd = 2, i = 1, q;\n  auto f = [&](u64 x) { return modmul(x, x, n) +\
    \ i; };\n  while (t++ % 40 || gcd(prd, n) == 1) {\n    if (x == y) x = ++i, y\
    \ = f(x);\n    if ((q = modmul(prd, max(x, y) - min(x, y), n))) prd = q;\n   \
    \ x = f(x), y = f(f(y));\n  }\n  return gcd(prd, n);\n}\nvector<u64> factor(u64\
    \ n) {\n  if (n == 1) return {};\n  if (isPrime(n)) return {n};\n  u64 x = pollard(n);\n\
    \  auto l = factor(x), r = factor(n / x);\n  l.insert(l.end(), all(r));\n  return\
    \ l;\n}\n"
  code: "#include \"ModInt.h\"\n#include \"MillerRabin.h\"\n\nu64 pollard(u64 n) {\n\
    \  u64 x = 0, y = 0, t = 30, prd = 2, i = 1, q;\n  auto f = [&](u64 x) { return\
    \ modmul(x, x, n) + i; };\n  while (t++ % 40 || gcd(prd, n) == 1) {\n    if (x\
    \ == y) x = ++i, y = f(x);\n    if ((q = modmul(prd, max(x, y) - min(x, y), n)))\
    \ prd = q;\n    x = f(x), y = f(f(y));\n  }\n  return gcd(prd, n);\n}\nvector<u64>\
    \ factor(u64 n) {\n  if (n == 1) return {};\n  if (isPrime(n)) return {n};\n \
    \ u64 x = pollard(n);\n  auto l = factor(x), r = factor(n / x);\n  l.insert(l.end(),\
    \ all(r));\n  return l;\n}"
  dependsOn:
  - math/ModInt.h
  - math/MillerRabin.h
  isVerificationFile: false
  path: math/Factor.h
  requiredBy: []
  timestamp: '2025-11-26 18:05:06+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/Factorize.test.cpp
  - tests/Primitive_Root.test.cpp
documentation_of: math/Factor.h
layout: document
redirect_from:
- /library/math/Factor.h
- /library/math/Factor.h.html
title: math/Factor.h
---
