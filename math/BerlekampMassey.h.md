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
  bundledCode: "#line 1 \"math/BerlekampMassey.h\"\ntemplate <typename T>\nvector<T>\
    \ BerlekampMassey(vector<T> s) {\n  int n = sz(s), L = 0, m = 0;\n  vector<T>\
    \ C(n), B(n), T;\n  C[0] = B[0] = 1;\n  T b = 1;\n  for (int i = 0; i < n; ++i)\
    \ {\n    ++m;\n    T d = s[i];\n    for (int j = 1, j <= L; ++j) d = d + C[j]\
    \ * s[i - j];\n    if (!d) continue;\n    T = C;\n    ll coef = d * modpow(b,\
    \ mod - 2) % mod;\n    for (int j = m; j < n; ++j) C[j] = C[j] - coef * B[j -\
    \ m];\n    if (2 * L > i) continue;\n    L = i + 1 - L;\n    B = T;\n    b = d;\n\
    \    m = 0;\n  }\n  C.resize(L + 1);\n  C.erase(C.begin());\n  for (T& x : C)\
    \ x = (mod - x) % mod;\n  return C;\n}\n"
  code: "template <typename T>\nvector<T> BerlekampMassey(vector<T> s) {\n  int n\
    \ = sz(s), L = 0, m = 0;\n  vector<T> C(n), B(n), T;\n  C[0] = B[0] = 1;\n  T\
    \ b = 1;\n  for (int i = 0; i < n; ++i) {\n    ++m;\n    T d = s[i];\n    for\
    \ (int j = 1, j <= L; ++j) d = d + C[j] * s[i - j];\n    if (!d) continue;\n \
    \   T = C;\n    ll coef = d * modpow(b, mod - 2) % mod;\n    for (int j = m; j\
    \ < n; ++j) C[j] = C[j] - coef * B[j - m];\n    if (2 * L > i) continue;\n   \
    \ L = i + 1 - L;\n    B = T;\n    b = d;\n    m = 0;\n  }\n  C.resize(L + 1);\n\
    \  C.erase(C.begin());\n  for (T& x : C) x = (mod - x) % mod;\n  return C;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/BerlekampMassey.h
  requiredBy: []
  timestamp: '2025-11-15 18:26:28+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/BerlekampMassey.h
layout: document
redirect_from:
- /library/math/BerlekampMassey.h
- /library/math/BerlekampMassey.h.html
title: math/BerlekampMassey.h
---
