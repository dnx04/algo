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
  bundledCode: "#line 1 \"misc/MaximalCliques.h\"\n// Usage: cliques(g, [&](const\
    \ bs &clique) { callback }, ~bs(n), bs(n), bs(n));\n\ntemplate <class F>\nvoid\
    \ cliques(vector<bs>& eds, F f, bs P, bs X, bs R) {\n  f(R);\n  if (!P.any() &&\
    \ !X.any()) return;\n  // if only need to find all maximal cliques\n  // auto\
    \ q = (P | X).find_first();\n  // auto cands = P & ~eds[q];\n  for (int i = 0;\
    \ i < sz(eds); ++i) {\n    if (P[i]) {\n      R[i] = 1;\n      cliques(eds, f,\
    \ P & eds[i], X & eds[i], R);\n      R[i] = P[i] = 0, X[i] = 1;\n    }\n  }\n\
    }\n"
  code: "// Usage: cliques(g, [&](const bs &clique) { callback }, ~bs(n), bs(n), bs(n));\n\
    \ntemplate <class F>\nvoid cliques(vector<bs>& eds, F f, bs P, bs X, bs R) {\n\
    \  f(R);\n  if (!P.any() && !X.any()) return;\n  // if only need to find all maximal\
    \ cliques\n  // auto q = (P | X).find_first();\n  // auto cands = P & ~eds[q];\n\
    \  for (int i = 0; i < sz(eds); ++i) {\n    if (P[i]) {\n      R[i] = 1;\n   \
    \   cliques(eds, f, P & eds[i], X & eds[i], R);\n      R[i] = P[i] = 0, X[i] =\
    \ 1;\n    }\n  }\n}"
  dependsOn: []
  isVerificationFile: false
  path: misc/MaximalCliques.h
  requiredBy: []
  timestamp: '2025-11-15 18:26:28+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/Enumerate_Cliques.test.cpp
documentation_of: misc/MaximalCliques.h
layout: document
redirect_from:
- /library/misc/MaximalCliques.h
- /library/misc/MaximalCliques.h.html
title: misc/MaximalCliques.h
---
