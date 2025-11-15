---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/Bitwise_And_Convolution.test.cpp
    title: tests/Bitwise_And_Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Bitwise_Xor_Convolution.test.cpp
    title: tests/Bitwise_Xor_Convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/FST.h\"\ntemplate <typename T>\nvoid FST(vector<T>&\
    \ a, bool inv, string type) {\n  for (int n = sz(a), step = 1; step < n; step\
    \ *= 2) {\n    for (int i = 0; i < n; i += 2 * step)\n      for (int j = i; j\
    \ < i + step; ++j) {\n        T &u = a[j], &v = a[j + step];\n        if (type\
    \ == \"and\")\n          tie(u, v) = inv ? tuple{v - u, u} : tuple{v, u + v};\n\
    \        else if (type == \"or\")\n          tie(u, v) = inv ? tuple{v, u - v}\
    \ : tuple{u + v, u};\n        else if (type == \"xor\")\n          tie(u, v) =\
    \ tuple{u + v, u - v};\n      }\n  }\n  if (inv && type == \"xor\")\n    for (T&\
    \ x : a) x /= sz(a);\n}\ntemplate <typename T>\nvector<T> conv(vector<T> a, vector<T>\
    \ b, string type) {\n  FST(a, 0, type);\n  FST(b, 0, type);\n  for (int i = 0;\
    \ i < sz(a); ++i) a[i] *= b[i];\n  FST(a, 1, type);\n  return a;\n}\n"
  code: "template <typename T>\nvoid FST(vector<T>& a, bool inv, string type) {\n\
    \  for (int n = sz(a), step = 1; step < n; step *= 2) {\n    for (int i = 0; i\
    \ < n; i += 2 * step)\n      for (int j = i; j < i + step; ++j) {\n        T &u\
    \ = a[j], &v = a[j + step];\n        if (type == \"and\")\n          tie(u, v)\
    \ = inv ? tuple{v - u, u} : tuple{v, u + v};\n        else if (type == \"or\"\
    )\n          tie(u, v) = inv ? tuple{v, u - v} : tuple{u + v, u};\n        else\
    \ if (type == \"xor\")\n          tie(u, v) = tuple{u + v, u - v};\n      }\n\
    \  }\n  if (inv && type == \"xor\")\n    for (T& x : a) x /= sz(a);\n}\ntemplate\
    \ <typename T>\nvector<T> conv(vector<T> a, vector<T> b, string type) {\n  FST(a,\
    \ 0, type);\n  FST(b, 0, type);\n  for (int i = 0; i < sz(a); ++i) a[i] *= b[i];\n\
    \  FST(a, 1, type);\n  return a;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/FST.h
  requiredBy: []
  timestamp: '2025-11-15 18:26:28+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/Bitwise_Xor_Convolution.test.cpp
  - tests/Bitwise_And_Convolution.test.cpp
documentation_of: math/FST.h
layout: document
redirect_from:
- /library/math/FST.h
- /library/math/FST.h.html
title: math/FST.h
---
