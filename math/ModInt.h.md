---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/Factor.h
    title: math/Factor.h
  - icon: ':heavy_check_mark:'
    path: math/Poly.h
    title: math/Poly.h
  - icon: ':heavy_check_mark:'
    path: math/SumPowerPoly.h
    title: math/SumPowerPoly.h
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/Bell_Number.test.cpp
    title: tests/Bell_Number.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Bernoulli_Number.test.cpp
    title: tests/Bernoulli_Number.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Bitwise_And_Convolution.test.cpp
    title: tests/Bitwise_And_Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Bitwise_Subset_Convolution.test.cpp
    title: tests/Bitwise_Subset_Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Bitwise_Xor_Convolution.test.cpp
    title: tests/Bitwise_Xor_Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Convolution.test.cpp
    title: tests/Convolution.test.cpp
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
    path: tests/Exp_of_FPS.test.cpp
    title: tests/Exp_of_FPS.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Factorize.test.cpp
    title: tests/Factorize.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Find_Linear_Recurrence.test.cpp
    title: tests/Find_Linear_Recurrence.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/GCD_Convolution.test.cpp
    title: tests/GCD_Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Inv_of_FPS.test.cpp
    title: tests/Inv_of_FPS.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/LCM_Convolution.test.cpp
    title: tests/LCM_Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Matrix_Det.test.cpp
    title: tests/Matrix_Det.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Matrix_Inv.test.cpp
    title: tests/Matrix_Inv.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Matrix_Product.test.cpp
    title: tests/Matrix_Product.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Matrix_Solve_Linear.test.cpp
    title: tests/Matrix_Solve_Linear.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Number_of_Subsequences.test.cpp
    title: tests/Number_of_Subsequences.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Partition_Function.test.cpp
    title: tests/Partition_Function.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Point_Set_Range_Composite.test.cpp
    title: tests/Point_Set_Range_Composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Point_Set_Range_Composite_Large.test.cpp
    title: tests/Point_Set_Range_Composite_Large.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Pow_of_FPS.test.cpp
    title: tests/Pow_of_FPS.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Pow_of_Matrix.test.cpp
    title: tests/Pow_of_Matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Primality_Test.test.cpp
    title: tests/Primality_Test.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Primitive_Root.test.cpp
    title: tests/Primitive_Root.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Product_of_Polynomial_Sequence.test.cpp
    title: tests/Product_of_Polynomial_Sequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Range_Affine_Point_Get.test.cpp
    title: tests/Range_Affine_Point_Get.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Range_Affine_Range_Sum.test.cpp
    title: tests/Range_Affine_Range_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Sqrt_Mod.test.cpp
    title: tests/Sqrt_Mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Stirling_Number_1st.test.cpp
    title: tests/Stirling_Number_1st.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Stirling_Number_1st_fixed_K.test.cpp
    title: tests/Stirling_Number_1st_fixed_K.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Stirling_Number_2nd.test.cpp
    title: tests/Stirling_Number_2nd.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Stirling_Number_2nd_fixed_K.test.cpp
    title: tests/Stirling_Number_2nd_fixed_K.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Sum_of_Exponential_times_Polynomial.test.cpp
    title: tests/Sum_of_Exponential_times_Polynomial.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Sum_of_Exponential_times_Polynomial_limit.test.cpp
    title: tests/Sum_of_Exponential_times_Polynomial_limit.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Sum_of_Multiplicative_Function.test.cpp
    title: tests/Sum_of_Multiplicative_Function.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/p_Subset_Sum.test.cpp
    title: tests/p_Subset_Sum.test.cpp
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
    \ x, m);\n    k >>= 1;\n  }\n  return res;\n}\n"
  code: "#pragma once\n\ntemplate <int mod>\nstruct modint {\n  using M = modint;\n\
    \  static_assert(mod > 0 && mod <= 2147483647);\n  static constexpr int modulo\
    \ = mod;\n  static constexpr u32 r1 = []() {\n    u32 r1 = mod;\n    for (int\
    \ i = 0; i < 5; ++i) r1 *= 2 - mod * r1;\n    return -r1;\n  }();\n  static constexpr\
    \ u32 r2 = -u64(mod) % mod;\n  static u32 reduce(u64 x) {\n    u32 y = u32(x)\
    \ * r1, r = (x + u64(y) * mod) >> 32;\n    return r >= mod ? r - mod : r;\n  }\n\
    \  u32 x;\n  modint() : x(0) {}\n  modint(i64 x) : x(reduce(u64(x % mod + mod)\
    \ * r2)) {}\n  M& operator+=(const M& a) {\n    if ((x += a.x) >= mod) x -= mod;\n\
    \    return *this;\n  }\n  M& operator-=(const M& a) {\n    if ((x += mod - a.x)\
    \ >= mod) x -= mod;\n    return *this;\n  }\n  M& operator*=(const M& a) {\n \
    \   x = reduce(u64(x) * a.x);\n    return *this;\n  }\n  M& operator/=(const M&\
    \ a) { return *this *= a.inv(); }\n  M operator-() const { return M(0) - *this;\
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
    \ x, m);\n    k >>= 1;\n  }\n  return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/ModInt.h
  requiredBy:
  - math/Poly.h
  - math/SumPowerPoly.h
  - math/Factor.h
  timestamp: '2025-11-26 18:05:06+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/Stirling_Number_2nd_fixed_K.test.cpp
  - tests/Matrix_Solve_Linear.test.cpp
  - tests/Find_Linear_Recurrence.test.cpp
  - tests/Range_Affine_Point_Get.test.cpp
  - tests/Matrix_Product.test.cpp
  - tests/Sum_of_Exponential_times_Polynomial.test.cpp
  - tests/Point_Set_Range_Composite_Large.test.cpp
  - tests/Bernoulli_Number.test.cpp
  - tests/Inv_of_FPS.test.cpp
  - tests/Bitwise_And_Convolution.test.cpp
  - tests/Product_of_Polynomial_Sequence.test.cpp
  - tests/Stirling_Number_2nd.test.cpp
  - tests/Convolution.test.cpp
  - tests/Range_Affine_Range_Sum.test.cpp
  - tests/Sum_of_Exponential_times_Polynomial_limit.test.cpp
  - tests/Matrix_Inv.test.cpp
  - tests/Sum_of_Multiplicative_Function.test.cpp
  - tests/Point_Set_Range_Composite.test.cpp
  - tests/Factorize.test.cpp
  - tests/Enumerate_Triangles.test.cpp
  - tests/Primality_Test.test.cpp
  - tests/LCM_Convolution.test.cpp
  - tests/Bell_Number.test.cpp
  - tests/Number_of_Subsequences.test.cpp
  - tests/Pow_of_Matrix.test.cpp
  - tests/Deque_Operate_All_Composite.test.cpp
  - tests/Matrix_Det.test.cpp
  - tests/Primitive_Root.test.cpp
  - tests/p_Subset_Sum.test.cpp
  - tests/Enumerate_Cliques.test.cpp
  - tests/Stirling_Number_1st.test.cpp
  - tests/Pow_of_FPS.test.cpp
  - tests/Exp_of_FPS.test.cpp
  - tests/Partition_Function.test.cpp
  - tests/GCD_Convolution.test.cpp
  - tests/Bitwise_Subset_Convolution.test.cpp
  - tests/Stirling_Number_1st_fixed_K.test.cpp
  - tests/Sqrt_Mod.test.cpp
  - tests/Bitwise_Xor_Convolution.test.cpp
documentation_of: math/ModInt.h
layout: document
redirect_from:
- /library/math/ModInt.h
- /library/math/ModInt.h.html
title: math/ModInt.h
---
