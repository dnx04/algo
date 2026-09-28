---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/Bitwise_And_Convolution.test.cpp
    title: tests/Bitwise_And_Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Bitwise_Subset_Convolution.test.cpp
    title: tests/Bitwise_Subset_Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Bitwise_Xor_Convolution.test.cpp
    title: tests/Bitwise_Xor_Convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/FST.h\"\n#define pc __builtin_popcount\n\nnamespace\
    \ FST {\n  enum { OR, AND, XOR };\n  template<class T>\n  void fwht(vector<T>&\
    \ a, int op, int inv) {\n    int n = sz(a);\n    for (int l = 1; l < n; l <<=\
    \ 1)\n      for (int i = 0; i < n; i += 2 * l)\n        for (int j = 0; j < l;\
    \ ++j) {\n          T u = a[i + j], v = a[i + j + l];\n          if (op == OR)\
    \ a[i + j + l] += inv ? -u : u;\n          else if (op == AND) a[i + j] += inv\
    \ ? -v : v;\n          else a[i + j] = u + v, a[i + j + l] = u - v;\n        }\n\
    \    if (op == XOR && inv) {\n      T in = T(1) / n;\n      for (auto& x : a)\
    \ x *= in;\n    }\n  }\n  template<class T>\n  vector<T> conv(vector<T> a, vector<T>\
    \ b, int op) {\n    int n = 1; while (n < max(sz(a), sz(b))) n <<= 1;\n    a.resize(n),\
    \ b.resize(n);\n    fwht(a, op, 0), fwht(b, op, 0);\n    for (int i = 0; i < n;\
    \ ++i) a[i] *= b[i];\n    fwht(a, op, 1);\n    return a;\n  }\n  template<class\
    \ T>\n  vector<T> subsetConv(const vector<T>& a, const vector<T>& b) {\n    int\
    \ n = 1, k = 0;\n    while (n < max(sz(a), sz(b))) n <<= 1, k++;\n    vector<vector<T>>\
    \ fa(k + 1, vector<T>(n)), fb(k + 1, vector<T>(n)), h(k + 1, vector<T>(n));\n\
    \    for (int i = 0; i < n; ++i) {\n      if (i < sz(a)) fa[pc(i)][i] = a[i];\n\
    \      if (i < sz(b)) fb[pc(i)][i] = b[i];\n    }\n    for (int i = 0; i <= k;\
    \ ++i) fwht(fa[i], OR, 0), fwht(fb[i], OR, 0);\n    for (int i = 0; i <= k; ++i)\n\
    \      for (int j = 0; j <= i; ++j)\n        for (int x = 0; x < n; ++x) h[i][x]\
    \ += fa[j][x] * fb[i - j][x];\n    for (int i = 0; i <= k; ++i) fwht(h[i], OR,\
    \ 1);\n    vector<T> res(n);\n    for (int i = 0; i < n; ++i) res[i] = h[pc(i)][i];\n\
    \    return res;\n  }\n}\n"
  code: "#define pc __builtin_popcount\n\nnamespace FST {\n  enum { OR, AND, XOR };\n\
    \  template<class T>\n  void fwht(vector<T>& a, int op, int inv) {\n    int n\
    \ = sz(a);\n    for (int l = 1; l < n; l <<= 1)\n      for (int i = 0; i < n;\
    \ i += 2 * l)\n        for (int j = 0; j < l; ++j) {\n          T u = a[i + j],\
    \ v = a[i + j + l];\n          if (op == OR) a[i + j + l] += inv ? -u : u;\n \
    \         else if (op == AND) a[i + j] += inv ? -v : v;\n          else a[i +\
    \ j] = u + v, a[i + j + l] = u - v;\n        }\n    if (op == XOR && inv) {\n\
    \      T in = T(1) / n;\n      for (auto& x : a) x *= in;\n    }\n  }\n  template<class\
    \ T>\n  vector<T> conv(vector<T> a, vector<T> b, int op) {\n    int n = 1; while\
    \ (n < max(sz(a), sz(b))) n <<= 1;\n    a.resize(n), b.resize(n);\n    fwht(a,\
    \ op, 0), fwht(b, op, 0);\n    for (int i = 0; i < n; ++i) a[i] *= b[i];\n   \
    \ fwht(a, op, 1);\n    return a;\n  }\n  template<class T>\n  vector<T> subsetConv(const\
    \ vector<T>& a, const vector<T>& b) {\n    int n = 1, k = 0;\n    while (n < max(sz(a),\
    \ sz(b))) n <<= 1, k++;\n    vector<vector<T>> fa(k + 1, vector<T>(n)), fb(k +\
    \ 1, vector<T>(n)), h(k + 1, vector<T>(n));\n    for (int i = 0; i < n; ++i) {\n\
    \      if (i < sz(a)) fa[pc(i)][i] = a[i];\n      if (i < sz(b)) fb[pc(i)][i]\
    \ = b[i];\n    }\n    for (int i = 0; i <= k; ++i) fwht(fa[i], OR, 0), fwht(fb[i],\
    \ OR, 0);\n    for (int i = 0; i <= k; ++i)\n      for (int j = 0; j <= i; ++j)\n\
    \        for (int x = 0; x < n; ++x) h[i][x] += fa[j][x] * fb[i - j][x];\n   \
    \ for (int i = 0; i <= k; ++i) fwht(h[i], OR, 1);\n    vector<T> res(n);\n   \
    \ for (int i = 0; i < n; ++i) res[i] = h[pc(i)][i];\n    return res;\n  }\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/FST.h
  requiredBy: []
  timestamp: '2025-11-28 12:47:29+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/Bitwise_And_Convolution.test.cpp
  - tests/Bitwise_Subset_Convolution.test.cpp
  - tests/Bitwise_Xor_Convolution.test.cpp
documentation_of: math/FST.h
layout: document
redirect_from:
- /library/math/FST.h
- /library/math/FST.h.html
title: math/FST.h
---
