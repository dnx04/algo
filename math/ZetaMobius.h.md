---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/GCD_Convolution.test.cpp
    title: tests/GCD_Convolution.test.cpp
  - icon: ':x:'
    path: tests/LCM_Convolution.test.cpp
    title: tests/LCM_Convolution.test.cpp
  _isVerificationFailed: true
  _pathExtension: h
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/ZetaMobius.h\"\nconstexpr int MAXN = 1e6 + 5;\nvector<int>\
    \ P;\nbitset<MAXN> is_p;\n\nvoid sieve(int n) {\n  is_p.set(); is_p[0] = is_p[1]\
    \ = 0;\n  for (int i = 2; i <= n; ++i) {\n    if (is_p[i]) P.pb(i);\n    for (int\
    \ p : P) {\n      if (i * p > n) break;\n      is_p[i * p] = 0;\n      if (i %\
    \ p == 0) break;\n    }\n  }\n}\n\n// div=0: Multiple (GCD), div=1: Divisor (LCM)\n\
    template <class Fp>\nvoid zeta(vector<Fp>& f, bool div) {\n  int n = sz(f) - 1;\n\
    \  for (int p : P) {\n    if (p > n) break;\n    if (!div) for (int j = n / p;\
    \ j >= 1; --j) f[j] += f[j * p];\n    else      for (int j = 1; j * p <= n; ++j)\
    \ f[j * p] += f[j];\n  }\n}\n\ntemplate <class Fp>\nvoid mobius(vector<Fp>& f,\
    \ bool div) {\n  int n = sz(f) - 1;\n  for (int p : P) {\n    if (p > n) break;\n\
    \    if (!div) for (int j = 1; j <= n / p; ++j) f[j] -= f[j * p];\n    else  \
    \    for (int j = n / p; j >= 1; --j) f[j * p] -= f[j];\n  }\n}\n\ntemplate <class\
    \ Fp>\nvector<Fp> convolution(vector<Fp> f, vector<Fp> g, bool div) {\n  int n\
    \ = min(sz(f), sz(g)) - 1;\n  f.resize(n + 1); g.resize(n + 1);\n  zeta(f, div),\
    \ zeta(g, div);\n  vector<Fp> h(n + 1);\n  for(int i = 1; i <= n; ++i) h[i] =\
    \ f[i] * g[i];\n  mobius(h, div);\n  return h;\n}\n"
  code: "constexpr int MAXN = 1e6 + 5;\nvector<int> P;\nbitset<MAXN> is_p;\n\nvoid\
    \ sieve(int n) {\n  is_p.set(); is_p[0] = is_p[1] = 0;\n  for (int i = 2; i <=\
    \ n; ++i) {\n    if (is_p[i]) P.pb(i);\n    for (int p : P) {\n      if (i * p\
    \ > n) break;\n      is_p[i * p] = 0;\n      if (i % p == 0) break;\n    }\n \
    \ }\n}\n\n// div=0: Multiple (GCD), div=1: Divisor (LCM)\ntemplate <class Fp>\n\
    void zeta(vector<Fp>& f, bool div) {\n  int n = sz(f) - 1;\n  for (int p : P)\
    \ {\n    if (p > n) break;\n    if (!div) for (int j = n / p; j >= 1; --j) f[j]\
    \ += f[j * p];\n    else      for (int j = 1; j * p <= n; ++j) f[j * p] += f[j];\n\
    \  }\n}\n\ntemplate <class Fp>\nvoid mobius(vector<Fp>& f, bool div) {\n  int\
    \ n = sz(f) - 1;\n  for (int p : P) {\n    if (p > n) break;\n    if (!div) for\
    \ (int j = 1; j <= n / p; ++j) f[j] -= f[j * p];\n    else      for (int j = n\
    \ / p; j >= 1; --j) f[j * p] -= f[j];\n  }\n}\n\ntemplate <class Fp>\nvector<Fp>\
    \ convolution(vector<Fp> f, vector<Fp> g, bool div) {\n  int n = min(sz(f), sz(g))\
    \ - 1;\n  f.resize(n + 1); g.resize(n + 1);\n  zeta(f, div), zeta(g, div);\n \
    \ vector<Fp> h(n + 1);\n  for(int i = 1; i <= n; ++i) h[i] = f[i] * g[i];\n  mobius(h,\
    \ div);\n  return h;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/ZetaMobius.h
  requiredBy: []
  timestamp: '2025-11-28 02:09:51+07:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - tests/LCM_Convolution.test.cpp
  - tests/GCD_Convolution.test.cpp
documentation_of: math/ZetaMobius.h
layout: document
redirect_from:
- /library/math/ZetaMobius.h
- /library/math/ZetaMobius.h.html
title: math/ZetaMobius.h
---
