---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/Matrix.h\"\nusing vec = array<Fp, 3>;\nusing matrix\
    \ = array<vec, 3>;\nconst matrix id = matrix({vec{1, 0, 0}, vec{0, 1, 0}, vec{0,\
    \ 0, 1}});\n\nmatrix operator*(const matrix& a, const matrix& b) {\n  matrix res;\n\
    \  for (int i = 0; i < 3; ++i) {\n    for (int j = 0; j < 3; ++j) {\n      for\
    \ (int k = 0; k < 3; ++k) {\n        res[i][j] += a[i][k] * b[k][j];\n      }\n\
    \    }\n  }\n  return res;\n}\n\nmatrix operator^(matrix a, ll k) {\n  matrix\
    \ res = id;\n  while (k) {\n    if (k & 1) res = res * a;\n    a = a * a;\n  \
    \  k >>= 1;\n  }\n  return res;\n}\n\nvec operator*(const matrix& a, const vec&\
    \ b) {\n  vec c;\n  for (int i = 0; i < 3; ++i) {\n    for (int j = 0; j < 3;\
    \ ++j) {\n      c[i] += a[i][j] * b[j];\n    }\n  }\n  return c;\n}\n"
  code: "using vec = array<Fp, 3>;\nusing matrix = array<vec, 3>;\nconst matrix id\
    \ = matrix({vec{1, 0, 0}, vec{0, 1, 0}, vec{0, 0, 1}});\n\nmatrix operator*(const\
    \ matrix& a, const matrix& b) {\n  matrix res;\n  for (int i = 0; i < 3; ++i)\
    \ {\n    for (int j = 0; j < 3; ++j) {\n      for (int k = 0; k < 3; ++k) {\n\
    \        res[i][j] += a[i][k] * b[k][j];\n      }\n    }\n  }\n  return res;\n\
    }\n\nmatrix operator^(matrix a, ll k) {\n  matrix res = id;\n  while (k) {\n \
    \   if (k & 1) res = res * a;\n    a = a * a;\n    k >>= 1;\n  }\n  return res;\n\
    }\n\nvec operator*(const matrix& a, const vec& b) {\n  vec c;\n  for (int i =\
    \ 0; i < 3; ++i) {\n    for (int j = 0; j < 3; ++j) {\n      c[i] += a[i][j] *\
    \ b[j];\n    }\n  }\n  return c;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/Matrix.h
  requiredBy: []
  timestamp: '2025-11-15 18:26:28+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/Matrix.h
layout: document
redirect_from:
- /library/math/Matrix.h
- /library/math/Matrix.h.html
title: math/Matrix.h
---
