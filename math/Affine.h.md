---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/Deque_Operate_All_Composite.test.cpp
    title: tests/Deque_Operate_All_Composite.test.cpp
  - icon: ':x:'
    path: tests/Point_Set_Range_Composite.test.cpp
    title: tests/Point_Set_Range_Composite.test.cpp
  - icon: ':x:'
    path: tests/Point_Set_Range_Composite_Large.test.cpp
    title: tests/Point_Set_Range_Composite_Large.test.cpp
  _isVerificationFailed: true
  _pathExtension: h
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/Affine.h\"\ntemplate <class T>\nstruct affine {\n \
    \ T a, b;\n  constexpr affine() : a(1), b(0) {}\n  constexpr affine(T a, T b)\
    \ : a(a), b(b) {}\n  T operator()(T x) const { return a * x + b; }\n  affine operator()(const\
    \ affine& f) const {\n    return f * (*this);\n  }\n  affine operator*(const affine&\
    \ g) const {  // g(f(x))\n    return {a * g.a, b * g.a + g.b};\n  }\n  affine\
    \ operator!=(const affine& g) const {\n    return a != g.a || b != g.b;\n  }\n\
    };\n"
  code: "template <class T>\nstruct affine {\n  T a, b;\n  constexpr affine() : a(1),\
    \ b(0) {}\n  constexpr affine(T a, T b) : a(a), b(b) {}\n  T operator()(T x) const\
    \ { return a * x + b; }\n  affine operator()(const affine& f) const {\n    return\
    \ f * (*this);\n  }\n  affine operator*(const affine& g) const {  // g(f(x))\n\
    \    return {a * g.a, b * g.a + g.b};\n  }\n  affine operator!=(const affine&\
    \ g) const {\n    return a != g.a || b != g.b;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/Affine.h
  requiredBy: []
  timestamp: '2025-11-21 16:12:02+07:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - tests/Deque_Operate_All_Composite.test.cpp
  - tests/Point_Set_Range_Composite.test.cpp
  - tests/Point_Set_Range_Composite_Large.test.cpp
documentation_of: math/Affine.h
layout: document
redirect_from:
- /library/math/Affine.h
- /library/math/Affine.h.html
title: math/Affine.h
---
