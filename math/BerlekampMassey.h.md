---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/Find_Linear_Recurrence.test.cpp
    title: tests/Find_Linear_Recurrence.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/BerlekampMassey.h\"\ntemplate <class Fp>\nvector<Fp>\
    \ BerlekampMassey(const vector<Fp>& s) {\n  if (s.empty()) return {};\n  int n\
    \ = len(s), L = 0, m = 0;\n  vector<Fp> C(n), B(n), T;\n  C[0] = B[0] = 1;\n \
    \ Fp b = 1;\n  for (int i = 0; i < n; ++i) {\n    ++m;\n    Fp d = s[i];\n   \
    \ for (int j = 1; j <= L; ++j) d += C[j] * s[i - j];\n    if (d == 0) continue;\n\
    \    T = C;\n    Fp coeff = d / b;\n    for (int j = m; j < n; ++j) C[j] -= coeff\
    \ * B[j - m];\n    if (2 * L > i) continue;\n    L = i + 1 - L, B = T, b = d,\
    \ m = 0;\n  }\n  C.resize(L + 1), C.erase(C.begin());\n  for (Fp& x : C) x = -x;\n\
    \  return C;\n}\n"
  code: "template <class Fp>\nvector<Fp> BerlekampMassey(const vector<Fp>& s) {\n\
    \  if (s.empty()) return {};\n  int n = len(s), L = 0, m = 0;\n  vector<Fp> C(n),\
    \ B(n), T;\n  C[0] = B[0] = 1;\n  Fp b = 1;\n  for (int i = 0; i < n; ++i) {\n\
    \    ++m;\n    Fp d = s[i];\n    for (int j = 1; j <= L; ++j) d += C[j] * s[i\
    \ - j];\n    if (d == 0) continue;\n    T = C;\n    Fp coeff = d / b;\n    for\
    \ (int j = m; j < n; ++j) C[j] -= coeff * B[j - m];\n    if (2 * L > i) continue;\n\
    \    L = i + 1 - L, B = T, b = d, m = 0;\n  }\n  C.resize(L + 1), C.erase(C.begin());\n\
    \  for (Fp& x : C) x = -x;\n  return C;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/BerlekampMassey.h
  requiredBy: []
  timestamp: '2026-10-03 15:27:40+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/Find_Linear_Recurrence.test.cpp
documentation_of: math/BerlekampMassey.h
layout: document
redirect_from:
- /library/math/BerlekampMassey.h
- /library/math/BerlekampMassey.h.html
title: math/BerlekampMassey.h
---
