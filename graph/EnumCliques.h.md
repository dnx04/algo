---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/Enumerate_Cliques.test.cpp
    title: tests/Enumerate_Cliques.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/EnumCliques.h\"\n// Usage: cliques(g, [&](const bs\
    \ &clique) { callback }, ~bs(n), bs(n), bs(n));\nusing bs = tr2::dynamic_bitset<u64>;\n\
    \ntemplate <class F>\nvoid cliques(vector<bs>& eds, F f, bs P, bs X, bs R) {\n\
    \  f(R);\n  if (!P.any() && !X.any()) return;\n  // if only need to find all maximal\
    \ cliques\n  // auto q = (P | X).find_first();\n  // auto cands = P & ~eds[q];\n\
    \  for (int i = 0; i < sz(eds); ++i) {\n    if (P[i]) {\n      R[i] = 1;\n   \
    \   cliques(eds, f, P & eds[i], X & eds[i], R);\n      R[i] = P[i] = 0, X[i] =\
    \ 1;\n    }\n  }\n}\n"
  code: "// Usage: cliques(g, [&](const bs &clique) { callback }, ~bs(n), bs(n), bs(n));\n\
    using bs = tr2::dynamic_bitset<u64>;\n\ntemplate <class F>\nvoid cliques(vector<bs>&\
    \ eds, F f, bs P, bs X, bs R) {\n  f(R);\n  if (!P.any() && !X.any()) return;\n\
    \  // if only need to find all maximal cliques\n  // auto q = (P | X).find_first();\n\
    \  // auto cands = P & ~eds[q];\n  for (int i = 0; i < sz(eds); ++i) {\n    if\
    \ (P[i]) {\n      R[i] = 1;\n      cliques(eds, f, P & eds[i], X & eds[i], R);\n\
    \      R[i] = P[i] = 0, X[i] = 1;\n    }\n  }\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/EnumCliques.h
  requiredBy: []
  timestamp: '2025-11-28 02:09:51+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/Enumerate_Cliques.test.cpp
documentation_of: graph/EnumCliques.h
layout: document
redirect_from:
- /library/graph/EnumCliques.h
- /library/graph/EnumCliques.h.html
title: graph/EnumCliques.h
---
