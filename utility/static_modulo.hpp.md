---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: convolution/ntt.hpp
    title: convolution/ntt.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: convolution/test/Convolution.test.cpp
    title: convolution/test/Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: data-structure/test/Dynamic_Sequence_Range_Affine_Range_Sum.test.cpp
    title: data-structure/test/Dynamic_Sequence_Range_Affine_Range_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: data-structure/test/Point_Set_Range_Composite.test.cpp
    title: data-structure/test/Point_Set_Range_Composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: data-structure/test/Queue_Operate_All_Composite.test.cpp
    title: data-structure/test/Queue_Operate_All_Composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: data-structure/test/Range_Affine_Range_Sum.test.cpp
    title: data-structure/test/Range_Affine_Range_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: math/test/Matrix_Product.test.cpp
    title: math/test/Matrix_Product.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utility/static_modulo.hpp\"\n\ntemplate <int mod>\nstruct\
    \ static_modulo {\n  using Fp = static_modulo;\n\n private:\n  int x;\n\n public:\n\
    \  static_modulo() : x(0) {}\n  static_modulo(int64_t y) : x(y >= 0 ? y % mod\
    \ : (mod - (-y) % mod) % mod) {}\n  Fp &operator+=(const Fp &p) {\n    if ((x\
    \ += p.x) >= mod) x -= mod;\n    return *this;\n  }\n  Fp &operator-=(const Fp\
    \ &p) {\n    if ((x += mod - p.x) >= mod) x -= mod;\n    return *this;\n  }\n\
    \  Fp &operator*=(const Fp &p) {\n    x = (int)(1ll * x * p.x % mod);\n    return\
    \ *this;\n  }\n  Fp &operator/=(const Fp &p) {\n    *this *= p.inv();\n    return\
    \ *this;\n  }\n  Fp operator-() const { return Fp(-x); }\n  Fp operator+(const\
    \ Fp &p) const { return Fp(*this) += p; }\n  Fp operator-(const Fp &p) const {\
    \ return Fp(*this) -= p; }\n  Fp operator*(const Fp &p) const { return Fp(*this)\
    \ *= p; }\n  Fp operator/(const Fp &p) const { return Fp(*this) /= p; }\n  bool\
    \ operator==(const Fp &p) const { return x == p.x; }\n  bool operator!=(const\
    \ Fp &p) const { return x != p.x; }\n  Fp inv() const {\n    int a = x, b = mod,\
    \ u = 1, v = 0, t;\n    while (b > 0) {\n      t = a / b;\n      swap(a -= t *\
    \ b, b);\n      swap(u -= t * v, v);\n    }\n    return Fp(u);\n  }\n  Fp pow(int64_t\
    \ n) const {\n    Fp ret(1), mul(x);\n    while (n > 0) {\n      if (n & 1) ret\
    \ *= mul;\n      mul *= mul;\n      n >>= 1;\n    }\n    return ret;\n  }\n  friend\
    \ ostream &operator<<(ostream &os, const Fp &p) { return os << p.x; }\n  friend\
    \ istream &operator>>(istream &is, Fp &a) {\n    int64_t t;\n    is >> t;\n  \
    \  a = static_modulo<mod>(t);\n    return (is);\n  }\n  int get() const { return\
    \ x; }\n  static constexpr int get_mod() { return mod; }\n};\n"
  code: "#pragma once\n\ntemplate <int mod>\nstruct static_modulo {\n  using Fp =\
    \ static_modulo;\n\n private:\n  int x;\n\n public:\n  static_modulo() : x(0)\
    \ {}\n  static_modulo(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod)\
    \ {}\n  Fp &operator+=(const Fp &p) {\n    if ((x += p.x) >= mod) x -= mod;\n\
    \    return *this;\n  }\n  Fp &operator-=(const Fp &p) {\n    if ((x += mod -\
    \ p.x) >= mod) x -= mod;\n    return *this;\n  }\n  Fp &operator*=(const Fp &p)\
    \ {\n    x = (int)(1ll * x * p.x % mod);\n    return *this;\n  }\n  Fp &operator/=(const\
    \ Fp &p) {\n    *this *= p.inv();\n    return *this;\n  }\n  Fp operator-() const\
    \ { return Fp(-x); }\n  Fp operator+(const Fp &p) const { return Fp(*this) +=\
    \ p; }\n  Fp operator-(const Fp &p) const { return Fp(*this) -= p; }\n  Fp operator*(const\
    \ Fp &p) const { return Fp(*this) *= p; }\n  Fp operator/(const Fp &p) const {\
    \ return Fp(*this) /= p; }\n  bool operator==(const Fp &p) const { return x ==\
    \ p.x; }\n  bool operator!=(const Fp &p) const { return x != p.x; }\n  Fp inv()\
    \ const {\n    int a = x, b = mod, u = 1, v = 0, t;\n    while (b > 0) {\n   \
    \   t = a / b;\n      swap(a -= t * b, b);\n      swap(u -= t * v, v);\n    }\n\
    \    return Fp(u);\n  }\n  Fp pow(int64_t n) const {\n    Fp ret(1), mul(x);\n\
    \    while (n > 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul;\n      n\
    \ >>= 1;\n    }\n    return ret;\n  }\n  friend ostream &operator<<(ostream &os,\
    \ const Fp &p) { return os << p.x; }\n  friend istream &operator>>(istream &is,\
    \ Fp &a) {\n    int64_t t;\n    is >> t;\n    a = static_modulo<mod>(t);\n   \
    \ return (is);\n  }\n  int get() const { return x; }\n  static constexpr int get_mod()\
    \ { return mod; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: utility/static_modulo.hpp
  requiredBy:
  - convolution/ntt.hpp
  timestamp: '2022-09-27 22:26:49+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - math/test/Matrix_Product.test.cpp
  - data-structure/test/Point_Set_Range_Composite.test.cpp
  - data-structure/test/Queue_Operate_All_Composite.test.cpp
  - data-structure/test/Dynamic_Sequence_Range_Affine_Range_Sum.test.cpp
  - data-structure/test/Range_Affine_Range_Sum.test.cpp
  - convolution/test/Convolution.test.cpp
documentation_of: utility/static_modulo.hpp
layout: document
redirect_from:
- /library/utility/static_modulo.hpp
- /library/utility/static_modulo.hpp.html
title: utility/static_modulo.hpp
---