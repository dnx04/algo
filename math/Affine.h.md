---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/Deque_Operate_All_Composite.test.cpp
    title: tests/Deque_Operate_All_Composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Point_Set_Range_Composite.test.cpp
    title: tests/Point_Set_Range_Composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/Affine.h\"\ntemplate <typename T>\nstruct affine {\n\
    \  T a, b;\n  constexpr affine() : a(1), b(0) {}\n  constexpr affine(T a, T b)\
    \ : a(a), b(b) {}\n  T operator()(T x) { return a * x + b; }\n  affine operator()(const\
    \ affine& f) const {\n    return f * (*this);\n  }\n  // g(f(x))\n  affine operator*(const\
    \ affine& g) const {\n    return {a * g.a, b * g.a + g.b};\n  }\n};\n"
  code: "template <typename T>\nstruct affine {\n  T a, b;\n  constexpr affine() :\
    \ a(1), b(0) {}\n  constexpr affine(T a, T b) : a(a), b(b) {}\n  T operator()(T\
    \ x) { return a * x + b; }\n  affine operator()(const affine& f) const {\n   \
    \ return f * (*this);\n  }\n  // g(f(x))\n  affine operator*(const affine& g)\
    \ const {\n    return {a * g.a, b * g.a + g.b};\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/Affine.h
  requiredBy: []
  timestamp: '2025-11-15 18:26:28+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/Deque_Operate_All_Composite.test.cpp
  - tests/Point_Set_Range_Composite.test.cpp
documentation_of: math/Affine.h
layout: document
redirect_from:
- /library/math/Affine.h
- /library/math/Affine.h.html
title: math/Affine.h
---
