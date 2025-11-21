---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/Pow_of_Matrix.test.cpp
    title: tests/Pow_of_Matrix.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/Matrix.h\"\ntemplate <class T>\nstruct Matrix {\n \
    \ using vec = vector<T>;\n  int n;\n  vector<vec> a;\n  Matrix(int n = 0) : n(n),\
    \ a(n, vec(n, 0)) {}\n  Matrix(const vector<vec>& a) : n(sz(a)), a(a) {}\n  vec&\
    \ operator[](int i) { return a[i]; }\n  const vec& operator[](int i) const { return\
    \ a[i]; }\n  Matrix operator*(const Matrix& b) const {\n    Matrix res(n);\n \
    \   for (int i = 0; i < n; ++i)\n      for (int k = 0; k < n; ++k)\n        for\
    \ (int j = 0; j < n; ++j)\n          res[i][j] += a[i][k] * b[k][j];\n    return\
    \ res;\n  }\n  Matrix operator^(u64 k) const {\n    Matrix res(n), b = *this;\n\
    \    for (int i = 0; i < n; ++i) res[i][i] = 1;\n    while (k) {\n      if (k\
    \ & 1) res = res * b;\n      b = b * b, k >>= 1;\n    }\n    return res;\n  }\n\
    \  vec operator*(const vec& v) const {  // b(v)\n    vec c(n);\n    for (int i\
    \ = 0; i < n; ++i)\n      for (int j = 0; j < n; ++j) c[i] += a[i][j] * v[j];\n\
    \    return c;\n  }\n};\n"
  code: "template <class T>\nstruct Matrix {\n  using vec = vector<T>;\n  int n;\n\
    \  vector<vec> a;\n  Matrix(int n = 0) : n(n), a(n, vec(n, 0)) {}\n  Matrix(const\
    \ vector<vec>& a) : n(sz(a)), a(a) {}\n  vec& operator[](int i) { return a[i];\
    \ }\n  const vec& operator[](int i) const { return a[i]; }\n  Matrix operator*(const\
    \ Matrix& b) const {\n    Matrix res(n);\n    for (int i = 0; i < n; ++i)\n  \
    \    for (int k = 0; k < n; ++k)\n        for (int j = 0; j < n; ++j)\n      \
    \    res[i][j] += a[i][k] * b[k][j];\n    return res;\n  }\n  Matrix operator^(u64\
    \ k) const {\n    Matrix res(n), b = *this;\n    for (int i = 0; i < n; ++i) res[i][i]\
    \ = 1;\n    while (k) {\n      if (k & 1) res = res * b;\n      b = b * b, k >>=\
    \ 1;\n    }\n    return res;\n  }\n  vec operator*(const vec& v) const {  // b(v)\n\
    \    vec c(n);\n    for (int i = 0; i < n; ++i)\n      for (int j = 0; j < n;\
    \ ++j) c[i] += a[i][j] * v[j];\n    return c;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/Matrix.h
  requiredBy: []
  timestamp: '2025-11-21 16:12:02+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/Pow_of_Matrix.test.cpp
documentation_of: math/Matrix.h
layout: document
redirect_from:
- /library/math/Matrix.h
- /library/math/Matrix.h.html
title: math/Matrix.h
---
