---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: tests/Matrix_Det.test.cpp
    title: tests/Matrix_Det.test.cpp
  - icon: ':x:'
    path: tests/Matrix_Inv.test.cpp
    title: tests/Matrix_Inv.test.cpp
  - icon: ':x:'
    path: tests/Matrix_Product.test.cpp
    title: tests/Matrix_Product.test.cpp
  - icon: ':x:'
    path: tests/Matrix_Solve_Linear.test.cpp
    title: tests/Matrix_Solve_Linear.test.cpp
  - icon: ':x:'
    path: tests/Pow_of_Matrix.test.cpp
    title: tests/Pow_of_Matrix.test.cpp
  _isVerificationFailed: true
  _pathExtension: h
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/Matrix.h\"\ntemplate <class T>\nstruct Matrix {\n \
    \ int r, c;\n  vector<vector<T>> a;\n  Matrix(int n) : Matrix(n, n) {}\n  Matrix(int\
    \ r, int c) : r(r), c(c), a(r, vector<T>(c, T(0))) {}\n  Matrix(const vector<vector<T>>&\
    \ v) : r(len(v)), c(v.empty() ? 0 : len(v[0])), a(v) {}\n  vector<T>& operator[](int\
    \ i) { return a[i]; }\n  const vector<T>& operator[](int i) const { return a[i];\
    \ }\n  static Matrix eye(int n) {\n    Matrix res(n);\n    for (int i = 0; i <\
    \ n; ++i) res[i][i] = 1;\n    return res;\n  }\n  Matrix operator*(const Matrix&\
    \ b) const {\n    Matrix res(r, b.c);\n    for (int i = 0; i < r; ++i)\n     \
    \ for (int k = 0; k < c; ++k)\n        if (a[i][k] != T(0))\n          for (int\
    \ j = 0; j < b.c; ++j) res[i][j] += a[i][k] * b[k][j];\n    return res;\n  }\n\
    \  Matrix pow(u64 k) const {\n    Matrix res = eye(r), b = *this;\n    while (k)\
    \ {\n      if (k & 1) res = res * b;\n      b = b * b, k >>= 1;\n    }\n    return\
    \ res;\n  }\n  // destructive\n  pair<T, int> gauss() {\n    int rank = 0;\n \
    \   T det = 1;\n    for (int j = 0; j < c && rank < r; ++j) {\n      int k = rank;\n\
    \      while (k < r && a[k][j] == T(0)) k++;\n      if (k == r) {\n        det\
    \ = 0;\n        continue;\n      }\n      swap(a[rank], a[k]);\n      if (rank\
    \ != k) det = -det;\n      det *= a[rank][j];\n      T inv = T(1) / a[rank][j];\n\
    \      for (int l = j; l < c; ++l) a[rank][l] *= inv;\n      for (int i = 0; i\
    \ < r; ++i)\n        if (i != rank && a[i][j] != T(0)) {\n          T fac = a[i][j];\n\
    \          for (int l = j; l < c; ++l) a[i][l] -= a[rank][l] * fac;\n        }\n\
    \      rank++;\n    }\n    return {det, rank};\n  }\n  pair<vector<T>, vector<vector<T>>>\
    \ solve(const Matrix& b) const {\n    if (r != b.r || b.c != 1) return {{}, {}};\n\
    \    Matrix mat(r, c + 1);\n    for (int i = 0; i < r; ++i) {\n      for (int\
    \ j = 0; j < c; ++j) mat[i][j] = a[i][j];\n      mat[i][c] = b[i][0];\n    }\n\
    \    int rank = mat.gauss().second;\n    vector<T> sol(c, T(0));\n    vector<int>\
    \ piv;\n    vector<bool> is_free(c, 1);\n    for (int i = 0; i < rank; ++i) {\n\
    \      int j = 0;\n      while (j <= c && mat[i][j] == T(0)) j++;\n      if (j\
    \ == c) return {{}, {}};\n      piv.push_back(j);\n      is_free[j] = 0;\n   \
    \   sol[j] = mat[i][c];\n    }\n    for (int i = rank; i < r; ++i)\n      if (mat[i][c]\
    \ != T(0)) return {{}, {}};\n    vector<vector<T>> ker;\n    for (int j = 0; j\
    \ < c; ++j) {\n      if (is_free[j]) {\n        vector<T> v(c, T(0));\n      \
    \  v[j] = T(1);\n        for (int i = 0; i < len(piv); ++i) v[piv[i]] = T(0) -\
    \ mat[i][j];\n        ker.push_back(v);\n      }\n    }\n    return {sol, ker};\n\
    \  }\n  T det() const {\n    if (r != c) return T(0);\n    Matrix tmp = *this;\n\
    \    auto [d, rank] = tmp.gauss();\n    return (rank == r) ? d : T(0);\n  }\n\
    \  int rank() const {\n    Matrix tmp = *this;\n    return tmp.gauss().second;\n\
    \  }\n  Matrix inv() const {\n    if (r != c) return Matrix(0, 0);\n    Matrix\
    \ tmp(r, 2 * c);\n    for (int i = 0; i < r; ++i) {\n      for (int j = 0; j <\
    \ c; ++j) tmp[i][j] = a[i][j];\n      tmp[i][i + c] = 1;\n    }\n    auto [d,\
    \ rank] = tmp.gauss();\n    if (rank != r) return Matrix(0, 0);\n    Matrix res(r,\
    \ c);\n    for (int i = 0; i < r; ++i)\n      for (int j = 0; j < c; ++j) res[i][j]\
    \ = tmp[i][j + c];\n    return res;\n  }\n};\n"
  code: "template <class T>\nstruct Matrix {\n  int r, c;\n  vector<vector<T>> a;\n\
    \  Matrix(int n) : Matrix(n, n) {}\n  Matrix(int r, int c) : r(r), c(c), a(r,\
    \ vector<T>(c, T(0))) {}\n  Matrix(const vector<vector<T>>& v) : r(len(v)), c(v.empty()\
    \ ? 0 : len(v[0])), a(v) {}\n  vector<T>& operator[](int i) { return a[i]; }\n\
    \  const vector<T>& operator[](int i) const { return a[i]; }\n  static Matrix\
    \ eye(int n) {\n    Matrix res(n);\n    for (int i = 0; i < n; ++i) res[i][i]\
    \ = 1;\n    return res;\n  }\n  Matrix operator*(const Matrix& b) const {\n  \
    \  Matrix res(r, b.c);\n    for (int i = 0; i < r; ++i)\n      for (int k = 0;\
    \ k < c; ++k)\n        if (a[i][k] != T(0))\n          for (int j = 0; j < b.c;\
    \ ++j) res[i][j] += a[i][k] * b[k][j];\n    return res;\n  }\n  Matrix pow(u64\
    \ k) const {\n    Matrix res = eye(r), b = *this;\n    while (k) {\n      if (k\
    \ & 1) res = res * b;\n      b = b * b, k >>= 1;\n    }\n    return res;\n  }\n\
    \  // destructive\n  pair<T, int> gauss() {\n    int rank = 0;\n    T det = 1;\n\
    \    for (int j = 0; j < c && rank < r; ++j) {\n      int k = rank;\n      while\
    \ (k < r && a[k][j] == T(0)) k++;\n      if (k == r) {\n        det = 0;\n   \
    \     continue;\n      }\n      swap(a[rank], a[k]);\n      if (rank != k) det\
    \ = -det;\n      det *= a[rank][j];\n      T inv = T(1) / a[rank][j];\n      for\
    \ (int l = j; l < c; ++l) a[rank][l] *= inv;\n      for (int i = 0; i < r; ++i)\n\
    \        if (i != rank && a[i][j] != T(0)) {\n          T fac = a[i][j];\n   \
    \       for (int l = j; l < c; ++l) a[i][l] -= a[rank][l] * fac;\n        }\n\
    \      rank++;\n    }\n    return {det, rank};\n  }\n  pair<vector<T>, vector<vector<T>>>\
    \ solve(const Matrix& b) const {\n    if (r != b.r || b.c != 1) return {{}, {}};\n\
    \    Matrix mat(r, c + 1);\n    for (int i = 0; i < r; ++i) {\n      for (int\
    \ j = 0; j < c; ++j) mat[i][j] = a[i][j];\n      mat[i][c] = b[i][0];\n    }\n\
    \    int rank = mat.gauss().second;\n    vector<T> sol(c, T(0));\n    vector<int>\
    \ piv;\n    vector<bool> is_free(c, 1);\n    for (int i = 0; i < rank; ++i) {\n\
    \      int j = 0;\n      while (j <= c && mat[i][j] == T(0)) j++;\n      if (j\
    \ == c) return {{}, {}};\n      piv.push_back(j);\n      is_free[j] = 0;\n   \
    \   sol[j] = mat[i][c];\n    }\n    for (int i = rank; i < r; ++i)\n      if (mat[i][c]\
    \ != T(0)) return {{}, {}};\n    vector<vector<T>> ker;\n    for (int j = 0; j\
    \ < c; ++j) {\n      if (is_free[j]) {\n        vector<T> v(c, T(0));\n      \
    \  v[j] = T(1);\n        for (int i = 0; i < len(piv); ++i) v[piv[i]] = T(0) -\
    \ mat[i][j];\n        ker.push_back(v);\n      }\n    }\n    return {sol, ker};\n\
    \  }\n  T det() const {\n    if (r != c) return T(0);\n    Matrix tmp = *this;\n\
    \    auto [d, rank] = tmp.gauss();\n    return (rank == r) ? d : T(0);\n  }\n\
    \  int rank() const {\n    Matrix tmp = *this;\n    return tmp.gauss().second;\n\
    \  }\n  Matrix inv() const {\n    if (r != c) return Matrix(0, 0);\n    Matrix\
    \ tmp(r, 2 * c);\n    for (int i = 0; i < r; ++i) {\n      for (int j = 0; j <\
    \ c; ++j) tmp[i][j] = a[i][j];\n      tmp[i][i + c] = 1;\n    }\n    auto [d,\
    \ rank] = tmp.gauss();\n    if (rank != r) return Matrix(0, 0);\n    Matrix res(r,\
    \ c);\n    for (int i = 0; i < r; ++i)\n      for (int j = 0; j < c; ++j) res[i][j]\
    \ = tmp[i][j + c];\n    return res;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/Matrix.h
  requiredBy: []
  timestamp: '2026-10-03 15:27:40+00:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - tests/Matrix_Solve_Linear.test.cpp
  - tests/Matrix_Product.test.cpp
  - tests/Matrix_Inv.test.cpp
  - tests/Pow_of_Matrix.test.cpp
  - tests/Matrix_Det.test.cpp
documentation_of: math/Matrix.h
layout: document
redirect_from:
- /library/math/Matrix.h
- /library/math/Matrix.h.html
title: math/Matrix.h
---
