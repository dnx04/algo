---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/Bitwise_And_Convolution.test.cpp
    title: tests/Bitwise_And_Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Bitwise_Xor_Convolution.test.cpp
    title: tests/Bitwise_Xor_Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Deque_Operate_All_Composite.test.cpp
    title: tests/Deque_Operate_All_Composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Enumerate_Cliques.test.cpp
    title: tests/Enumerate_Cliques.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Enumerate_Triangles.test.cpp
    title: tests/Enumerate_Triangles.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Factorize.test.cpp
    title: tests/Factorize.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Find_Linear_Recurrence.test.cpp
    title: tests/Find_Linear_Recurrence.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Number_of_Subsequences.test.cpp
    title: tests/Number_of_Subsequences.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Point_Set_Range_Composite.test.cpp
    title: tests/Point_Set_Range_Composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Point_Set_Range_Composite_Large.test.cpp
    title: tests/Point_Set_Range_Composite_Large.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Primality_Test.test.cpp
    title: tests/Primality_Test.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Range_Affine_Point_Get.test.cpp
    title: tests/Range_Affine_Point_Get.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Range_Affine_Range_Sum.test.cpp
    title: tests/Range_Affine_Range_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Sqrt_Mod.test.cpp
    title: tests/Sqrt_Mod.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/ModInt.h\"\ntemplate <int mod>\nstruct modint {\n \
    \ using Fp = modint;\n  int x;\n  modint() : x(0) {}\n  modint(i64 y) : x(y >=\
    \ 0 ? y % mod : (mod - (-y) % mod) % mod) {}\n  Fp& operator+=(const Fp& p) {\n\
    \    if ((x += p.x) >= mod) x -= mod;\n    return *this;\n  }\n  Fp& operator-=(const\
    \ Fp& p) {\n    if ((x += mod - p.x) >= mod) x -= mod;\n    return *this;\n  }\n\
    \  Fp& operator*=(const Fp& p) {\n    x = (int) (1ll * x * p.x % mod);\n    return\
    \ *this;\n  }\n  Fp& operator/=(const Fp& p) {\n    *this *= p.inv();\n    return\
    \ *this;\n  }\n  Fp operator-() const { return Fp(-x); }\n  Fp operator+(const\
    \ Fp& p) const { return Fp(*this) += p; }\n  Fp operator-(const Fp& p) const {\
    \ return Fp(*this) -= p; }\n  Fp operator*(const Fp& p) const { return Fp(*this)\
    \ *= p; }\n  Fp operator/(const Fp& p) const { return Fp(*this) /= p; }\n  bool\
    \ operator==(const Fp& p) const { return x == p.x; }\n  bool operator!=(const\
    \ Fp& p) const { return x != p.x; }\n  Fp inv() const { return *this ^ (mod -\
    \ 2); }\n  Fp operator^(i64 n) const {\n    Fp ret(1), mul(x);\n    while (n >\
    \ 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n    }\n\
    \    return ret;\n  }\n  friend ostream& operator<<(ostream& os, const Fp& p)\
    \ { return os << p.x; }\n  friend istream& operator>>(istream& is, Fp& a) {\n\
    \    i64 t;\n    is >> t;\n    a = modint<mod>(t);\n    return (is);\n  }\n};\n\
    \nu64 modmul(u64 x, u64 y, u64 m) { return u128(x) * y % m; }\nu64 modpow(u64\
    \ x, u64 k, u64 m) {\n  u64 res = 1;\n  while (k) {\n    if (k & 1) res = modmul(res,\
    \ x, m);\n    x = modmul(x, x, m);\n    k >>= 1;\n  }\n  return res;\n}\n"
  code: "template <int mod>\nstruct modint {\n  using Fp = modint;\n  int x;\n  modint()\
    \ : x(0) {}\n  modint(i64 y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod)\
    \ {}\n  Fp& operator+=(const Fp& p) {\n    if ((x += p.x) >= mod) x -= mod;\n\
    \    return *this;\n  }\n  Fp& operator-=(const Fp& p) {\n    if ((x += mod -\
    \ p.x) >= mod) x -= mod;\n    return *this;\n  }\n  Fp& operator*=(const Fp& p)\
    \ {\n    x = (int) (1ll * x * p.x % mod);\n    return *this;\n  }\n  Fp& operator/=(const\
    \ Fp& p) {\n    *this *= p.inv();\n    return *this;\n  }\n  Fp operator-() const\
    \ { return Fp(-x); }\n  Fp operator+(const Fp& p) const { return Fp(*this) +=\
    \ p; }\n  Fp operator-(const Fp& p) const { return Fp(*this) -= p; }\n  Fp operator*(const\
    \ Fp& p) const { return Fp(*this) *= p; }\n  Fp operator/(const Fp& p) const {\
    \ return Fp(*this) /= p; }\n  bool operator==(const Fp& p) const { return x ==\
    \ p.x; }\n  bool operator!=(const Fp& p) const { return x != p.x; }\n  Fp inv()\
    \ const { return *this ^ (mod - 2); }\n  Fp operator^(i64 n) const {\n    Fp ret(1),\
    \ mul(x);\n    while (n > 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul;\n\
    \      n >>= 1;\n    }\n    return ret;\n  }\n  friend ostream& operator<<(ostream&\
    \ os, const Fp& p) { return os << p.x; }\n  friend istream& operator>>(istream&\
    \ is, Fp& a) {\n    i64 t;\n    is >> t;\n    a = modint<mod>(t);\n    return\
    \ (is);\n  }\n};\n\nu64 modmul(u64 x, u64 y, u64 m) { return u128(x) * y % m;\
    \ }\nu64 modpow(u64 x, u64 k, u64 m) {\n  u64 res = 1;\n  while (k) {\n    if\
    \ (k & 1) res = modmul(res, x, m);\n    x = modmul(x, x, m);\n    k >>= 1;\n \
    \ }\n  return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/ModInt.h
  requiredBy: []
  timestamp: '2025-11-18 16:58:39+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/Bitwise_Xor_Convolution.test.cpp
  - tests/Enumerate_Triangles.test.cpp
  - tests/Deque_Operate_All_Composite.test.cpp
  - tests/Range_Affine_Point_Get.test.cpp
  - tests/Factorize.test.cpp
  - tests/Find_Linear_Recurrence.test.cpp
  - tests/Primality_Test.test.cpp
  - tests/Sqrt_Mod.test.cpp
  - tests/Range_Affine_Range_Sum.test.cpp
  - tests/Enumerate_Cliques.test.cpp
  - tests/Point_Set_Range_Composite.test.cpp
  - tests/Point_Set_Range_Composite_Large.test.cpp
  - tests/Bitwise_And_Convolution.test.cpp
  - tests/Number_of_Subsequences.test.cpp
documentation_of: math/ModInt.h
layout: document
redirect_from:
- /library/math/ModInt.h
- /library/math/ModInt.h.html
title: math/ModInt.h
---
