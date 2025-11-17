---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: includes.h
    title: includes.h
  _extendedVerifiedWith:
  - icon: ':x:'
    path: tests/Bitwise_And_Convolution.test.cpp
    title: tests/Bitwise_And_Convolution.test.cpp
  - icon: ':x:'
    path: tests/Bitwise_Xor_Convolution.test.cpp
    title: tests/Bitwise_Xor_Convolution.test.cpp
  - icon: ':x:'
    path: tests/Deque_Operate_All_Composite.test.cpp
    title: tests/Deque_Operate_All_Composite.test.cpp
  - icon: ':x:'
    path: tests/Enumerate_Cliques.test.cpp
    title: tests/Enumerate_Cliques.test.cpp
  - icon: ':x:'
    path: tests/Enumerate_Triangles.test.cpp
    title: tests/Enumerate_Triangles.test.cpp
  - icon: ':x:'
    path: tests/Factorize.test.cpp
    title: tests/Factorize.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Number_of_Subsequences.test.cpp
    title: tests/Number_of_Subsequences.test.cpp
  - icon: ':x:'
    path: tests/Point_Set_Range_Composite.test.cpp
    title: tests/Point_Set_Range_Composite.test.cpp
  - icon: ':x:'
    path: tests/Primality_Test.test.cpp
    title: tests/Primality_Test.test.cpp
  - icon: ':x:'
    path: tests/Sqrt_Mod.test.cpp
    title: tests/Sqrt_Mod.test.cpp
  _isVerificationFailed: true
  _pathExtension: h
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/ModInt.h\"\ntemplate <int mod>\nstruct modint {\n \
    \ using Fp = modint;\n  static constexpr ull im = -1ULL / mod + 1;  // Barrett\
    \ constant\n  int x;\n  modint() : x(0) {}\n  modint(ll y) {\n    y %= mod;\n\
    \    if (y < 0) y += mod;\n    x = y;\n  }\n  static inline uint32_t reduce(ull\
    \ z) {\n    ull q = (__uint128_t(z) * im) >> 64;\n    ll r = z - q * mod;\n  \
    \  return r < mod ? r : r - mod;\n  }\n  Fp& operator+=(const Fp& p) {\n    if\
    \ ((x += p.x) >= mod) x -= mod;\n    return *this;\n  }\n  Fp& operator-=(const\
    \ Fp& p) {\n    if ((x += mod - p.x) >= mod) x -= mod;\n    return *this;\n  }\n\
    \  Fp& operator*=(const Fp& p) {\n    x = reduce(uint64_t(x) * p.x);\n    return\
    \ *this;\n  }\n  Fp& operator/=(const Fp& p) { return *this *= p.inv(); }\n\n\
    \  Fp operator-() const { return Fp(-x); }\n  Fp operator+(const Fp& p) const\
    \ { return Fp(*this) += p; }\n  Fp operator-(const Fp& p) const { return Fp(*this)\
    \ -= p; }\n  Fp operator*(const Fp& p) const { return Fp(*this) *= p; }\n  Fp\
    \ operator/(const Fp& p) const { return Fp(*this) /= p; }\n  bool operator==(const\
    \ Fp& p) const { return x == p.x; }\n  bool operator!=(const Fp& p) const { return\
    \ x != p.x; }\n  Fp inv() const { return *this ^ (mod - 2); }\n  Fp operator^(int64_t\
    \ n) const {\n    Fp r = 1, a = *this;\n    while (n) {\n      if (n & 1) r *=\
    \ a;\n      a *= a;\n      n >>= 1;\n    }\n    return r;\n  }\n  friend ostream&\
    \ operator<<(ostream& os, const Fp& p) { return os << p.x; }\n  friend istream&\
    \ operator>>(istream& is, Fp& a) {\n    int64_t t;\n    is >> t;\n    a = Fp(t);\n\
    \    return is;\n  }\n};\n"
  code: "template <int mod>\nstruct modint {\n  using Fp = modint;\n  static constexpr\
    \ ull im = -1ULL / mod + 1;  // Barrett constant\n  int x;\n  modint() : x(0)\
    \ {}\n  modint(ll y) {\n    y %= mod;\n    if (y < 0) y += mod;\n    x = y;\n\
    \  }\n  static inline uint32_t reduce(ull z) {\n    ull q = (__uint128_t(z) *\
    \ im) >> 64;\n    ll r = z - q * mod;\n    return r < mod ? r : r - mod;\n  }\n\
    \  Fp& operator+=(const Fp& p) {\n    if ((x += p.x) >= mod) x -= mod;\n    return\
    \ *this;\n  }\n  Fp& operator-=(const Fp& p) {\n    if ((x += mod - p.x) >= mod)\
    \ x -= mod;\n    return *this;\n  }\n  Fp& operator*=(const Fp& p) {\n    x =\
    \ reduce(uint64_t(x) * p.x);\n    return *this;\n  }\n  Fp& operator/=(const Fp&\
    \ p) { return *this *= p.inv(); }\n\n  Fp operator-() const { return Fp(-x); }\n\
    \  Fp operator+(const Fp& p) const { return Fp(*this) += p; }\n  Fp operator-(const\
    \ Fp& p) const { return Fp(*this) -= p; }\n  Fp operator*(const Fp& p) const {\
    \ return Fp(*this) *= p; }\n  Fp operator/(const Fp& p) const { return Fp(*this)\
    \ /= p; }\n  bool operator==(const Fp& p) const { return x == p.x; }\n  bool operator!=(const\
    \ Fp& p) const { return x != p.x; }\n  Fp inv() const { return *this ^ (mod -\
    \ 2); }\n  Fp operator^(int64_t n) const {\n    Fp r = 1, a = *this;\n    while\
    \ (n) {\n      if (n & 1) r *= a;\n      a *= a;\n      n >>= 1;\n    }\n    return\
    \ r;\n  }\n  friend ostream& operator<<(ostream& os, const Fp& p) { return os\
    \ << p.x; }\n  friend istream& operator>>(istream& is, Fp& a) {\n    int64_t t;\n\
    \    is >> t;\n    a = Fp(t);\n    return is;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: math/ModInt.h
  requiredBy:
  - includes.h
  timestamp: '2025-11-17 23:51:26+07:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - tests/Bitwise_Xor_Convolution.test.cpp
  - tests/Enumerate_Triangles.test.cpp
  - tests/Deque_Operate_All_Composite.test.cpp
  - tests/Factorize.test.cpp
  - tests/Primality_Test.test.cpp
  - tests/Sqrt_Mod.test.cpp
  - tests/Enumerate_Cliques.test.cpp
  - tests/Point_Set_Range_Composite.test.cpp
  - tests/Bitwise_And_Convolution.test.cpp
  - tests/Number_of_Subsequences.test.cpp
documentation_of: math/ModInt.h
layout: document
redirect_from:
- /library/math/ModInt.h
- /library/math/ModInt.h.html
title: math/ModInt.h
---
