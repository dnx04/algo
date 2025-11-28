---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/Enumerate_Cliques.test.cpp
    title: tests/Enumerate_Cliques.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Maximum_Independent_Set.test.cpp
    title: tests/Maximum_Independent_Set.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/Cliques.h\"\nusing bs = tr2::dynamic_bitset<uint64_t>;\n\
    \n// Usage: bs P(n), X(n), R(n); P.set(); EnumClique(g, [&](bs& c){...}, P, X,\
    \ R);\ntemplate <class F>\nvoid EnumClique(vector<bs>& g, F f, bs P, bs X, bs\
    \ R) {\n  f(R); \n  if (P.none() && X.none()) return;\n  // if only need to find\
    \ all maximal cliques\n  // auto q = (P | X).find_first();\n  // auto cands =\
    \ P & ~g[q]; // then trav through cands\n  for (auto i = P.find_first(); i < sz(P);\
    \ i = P.find_next(i)) {\n    R[i] = 1;\n    EnumClique(g, f, P & g[i], X & g[i],\
    \ R);\n    R[i] = 0, P[i] = 0, X[i] = 1;\n  }\n}\n\n// Usage: bs P(n), R(n), sol;\
    \ u64 ans=0; P.set(); MaxClique(g, P, R, sol, ans);\nvoid MaxClique(vector<bs>&\
    \ g, bs P, bs R, bs& sol, u32& res) {\n  if (R.count() + P.count() <= res) return;\n\
    \  if (P.none()) { res = R.count(), sol = R; return; }\n  auto q = P.find_first(),\
    \ max_k = u64(0);\n  for (auto i = q; i < sz(P); i = P.find_next(i)) {\n    auto\
    \ k = (P & g[i]).count();\n    if (k > max_k) max_k = k, q = i;\n  }\n  bs cands\
    \ = P & ~g[q];\n  for (auto i = cands.find_first(); i < sz(cands); i = cands.find_next(i))\
    \ {\n    R[i] = 1, MaxClique(g, P & g[i], R, sol, res);\n    R[i] = P[i] = 0;\n\
    \  }\n}\n"
  code: "using bs = tr2::dynamic_bitset<uint64_t>;\n\n// Usage: bs P(n), X(n), R(n);\
    \ P.set(); EnumClique(g, [&](bs& c){...}, P, X, R);\ntemplate <class F>\nvoid\
    \ EnumClique(vector<bs>& g, F f, bs P, bs X, bs R) {\n  f(R); \n  if (P.none()\
    \ && X.none()) return;\n  // if only need to find all maximal cliques\n  // auto\
    \ q = (P | X).find_first();\n  // auto cands = P & ~g[q]; // then trav through\
    \ cands\n  for (auto i = P.find_first(); i < sz(P); i = P.find_next(i)) {\n  \
    \  R[i] = 1;\n    EnumClique(g, f, P & g[i], X & g[i], R);\n    R[i] = 0, P[i]\
    \ = 0, X[i] = 1;\n  }\n}\n\n// Usage: bs P(n), R(n), sol; u64 ans=0; P.set();\
    \ MaxClique(g, P, R, sol, ans);\nvoid MaxClique(vector<bs>& g, bs P, bs R, bs&\
    \ sol, u32& res) {\n  if (R.count() + P.count() <= res) return;\n  if (P.none())\
    \ { res = R.count(), sol = R; return; }\n  auto q = P.find_first(), max_k = u64(0);\n\
    \  for (auto i = q; i < sz(P); i = P.find_next(i)) {\n    auto k = (P & g[i]).count();\n\
    \    if (k > max_k) max_k = k, q = i;\n  }\n  bs cands = P & ~g[q];\n  for (auto\
    \ i = cands.find_first(); i < sz(cands); i = cands.find_next(i)) {\n    R[i] =\
    \ 1, MaxClique(g, P & g[i], R, sol, res);\n    R[i] = P[i] = 0;\n  }\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/Cliques.h
  requiredBy: []
  timestamp: '2025-11-28 13:07:52+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/Maximum_Independent_Set.test.cpp
  - tests/Enumerate_Cliques.test.cpp
documentation_of: graph/Cliques.h
layout: document
redirect_from:
- /library/graph/Cliques.h
- /library/graph/Cliques.h.html
title: graph/Cliques.h
---
