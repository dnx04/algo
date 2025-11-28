---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/Counting_Primes.test.cpp
    title: tests/Counting_Primes.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Sum_of_Multiplicative_Function.test.cpp
    title: tests/Sum_of_Multiplicative_Function.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/Min25.h\"\ntemplate <class T>\nstruct Min25 {\n  i64\
    \ n;\n  int sq;\n  vector<int> primes, id1, id2;\n  vector<i64> vals;\n  vector<T>\
    \ g0, g1;  // g0: sum p^0, g1: sum p^1\n  int id(i64 x) { return x <= sq ? id1[x]\
    \ : id2[n / x]; }\n  void init(i64 N) {\n    n = N, sq = sqrt(n);\n    primes.clear();\n\
    \    vector<bool> is_p(sq + 1, true);\n    for (int i = 2; i <= sq; ++i) {\n \
    \     if (is_p[i]) {\n        primes.pb(i);\n        for (int j = i * 2; j <=\
    \ sq; j += i) is_p[j] = false;\n      }\n    }\n    vals.clear(), id1.assign(sq\
    \ + 1, 0), id2.assign(sq + 1, 0);\n    for (i64 l = 1, r; l <= n; l = r + 1) {\n\
    \      i64 v = n / l;\n      r = n / v;\n      vals.pb(v);\n      if (v <= sq)\
    \ id1[v] = sz(vals) - 1;\n      else id2[n / v] = sz(vals) - 1;\n    }\n    g0.resize(sz(vals)),\
    \ g1.resize(sz(vals));\n    T inv2 = T(1) / T(2);\n    for (int i = 0; i < sz(vals);\
    \ ++i) {\n      T v = T(vals[i]);\n      g0[i] = v - 1;\n      g1[i] = v * (v\
    \ + 1) * inv2 - 1;\n    }\n    for (int p : primes) {\n      T sp0 = g0[id(p -\
    \ 1)], sp1 = g1[id(p - 1)];\n      i64 p2 = (i64) p * p;\n      T tp = T(p);\n\
    \      for (int i = 0; i < sz(vals); ++i) {\n        if (vals[i] < p2) break;\n\
    \        int k = id(vals[i] / p);\n        g0[i] -= g0[k] - sp0;\n        g1[i]\
    \ -= tp * (g1[k] - sp1);\n      }\n    }\n  }\n  // A, B: f(p) = A*1 + B*p\n \
    \ // func: (p, e) -> f(p^e) tr\u1EA3 v\u1EC1 T\n  template <class Func>\n  T solve(T\
    \ A, T B, Func f_pe) {\n    vector<T> s_fp(sz(primes) + 1);\n    for (int i =\
    \ 0; i < sz(primes); ++i)\n      s_fp[i + 1] = s_fp[i] + A + B * T(primes[i]);\n\
    \n    auto S = [&](auto&& self, i64 x, int j) -> T {\n      if (x <= 1 || (j <\
    \ sz(primes) && primes[j] > x)) return 0;\n      int k = id(x);\n      T ans =\
    \ A * g0[k] + B * g1[k];\n      ans -= s_fp[j];\n      for (int i = j; i < sz(primes);\
    \ ++i) {\n        i64 p = primes[i];\n        if (p * p > x) break;\n        i64\
    \ pe = p;\n        for (int e = 1; pe * p <= x; ++e) {\n          ans += f_pe(p,\
    \ e) * self(self, x / pe, i + 1);\n          ans += f_pe(p, e + 1);\n        \
    \  pe *= p;\n        }\n      }\n      return ans;\n    };\n    return S(S, n,\
    \ 0) + 1;\n  }\n};\n"
  code: "template <class T>\nstruct Min25 {\n  i64 n;\n  int sq;\n  vector<int> primes,\
    \ id1, id2;\n  vector<i64> vals;\n  vector<T> g0, g1;  // g0: sum p^0, g1: sum\
    \ p^1\n  int id(i64 x) { return x <= sq ? id1[x] : id2[n / x]; }\n  void init(i64\
    \ N) {\n    n = N, sq = sqrt(n);\n    primes.clear();\n    vector<bool> is_p(sq\
    \ + 1, true);\n    for (int i = 2; i <= sq; ++i) {\n      if (is_p[i]) {\n   \
    \     primes.pb(i);\n        for (int j = i * 2; j <= sq; j += i) is_p[j] = false;\n\
    \      }\n    }\n    vals.clear(), id1.assign(sq + 1, 0), id2.assign(sq + 1, 0);\n\
    \    for (i64 l = 1, r; l <= n; l = r + 1) {\n      i64 v = n / l;\n      r =\
    \ n / v;\n      vals.pb(v);\n      if (v <= sq) id1[v] = sz(vals) - 1;\n     \
    \ else id2[n / v] = sz(vals) - 1;\n    }\n    g0.resize(sz(vals)), g1.resize(sz(vals));\n\
    \    T inv2 = T(1) / T(2);\n    for (int i = 0; i < sz(vals); ++i) {\n      T\
    \ v = T(vals[i]);\n      g0[i] = v - 1;\n      g1[i] = v * (v + 1) * inv2 - 1;\n\
    \    }\n    for (int p : primes) {\n      T sp0 = g0[id(p - 1)], sp1 = g1[id(p\
    \ - 1)];\n      i64 p2 = (i64) p * p;\n      T tp = T(p);\n      for (int i =\
    \ 0; i < sz(vals); ++i) {\n        if (vals[i] < p2) break;\n        int k = id(vals[i]\
    \ / p);\n        g0[i] -= g0[k] - sp0;\n        g1[i] -= tp * (g1[k] - sp1);\n\
    \      }\n    }\n  }\n  // A, B: f(p) = A*1 + B*p\n  // func: (p, e) -> f(p^e)\
    \ tr\u1EA3 v\u1EC1 T\n  template <class Func>\n  T solve(T A, T B, Func f_pe)\
    \ {\n    vector<T> s_fp(sz(primes) + 1);\n    for (int i = 0; i < sz(primes);\
    \ ++i)\n      s_fp[i + 1] = s_fp[i] + A + B * T(primes[i]);\n\n    auto S = [&](auto&&\
    \ self, i64 x, int j) -> T {\n      if (x <= 1 || (j < sz(primes) && primes[j]\
    \ > x)) return 0;\n      int k = id(x);\n      T ans = A * g0[k] + B * g1[k];\n\
    \      ans -= s_fp[j];\n      for (int i = j; i < sz(primes); ++i) {\n       \
    \ i64 p = primes[i];\n        if (p * p > x) break;\n        i64 pe = p;\n   \
    \     for (int e = 1; pe * p <= x; ++e) {\n          ans += f_pe(p, e) * self(self,\
    \ x / pe, i + 1);\n          ans += f_pe(p, e + 1);\n          pe *= p;\n    \
    \    }\n      }\n      return ans;\n    };\n    return S(S, n, 0) + 1;\n  }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: math/Min25.h
  requiredBy: []
  timestamp: '2025-11-28 10:18:48+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/Counting_Primes.test.cpp
  - tests/Sum_of_Multiplicative_Function.test.cpp
documentation_of: math/Min25.h
layout: document
redirect_from:
- /library/math/Min25.h
- /library/math/Min25.h.html
title: math/Min25.h
---
