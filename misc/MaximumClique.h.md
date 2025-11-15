---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/Maximum_Independent_Set.test.cpp
    title: tests/Maximum_Independent_Set.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"misc/MaximumClique.h\"\nstruct Maxclique {\n  double limit\
    \ = 0.025, pk = 0;\n  struct Vertex {\n    int i, d = 0;\n  };\n  typedef vector<Vertex>\
    \ vv;\n  vector<bs> e;\n  vv V;\n  vector<vi> C;\n  vi qmax, q, S, old;  // qmax\
    \ = vertices in maximum clique, q = current clique\n  void init(vv& r) {\n   \
    \ for (auto& v : r) v.d = 0;\n    for (auto& v : r) {\n      for (auto j : r)\
    \ v.d += e[v.i][j.i];\n    }\n    sort(all(r), [](auto a, auto b) { return a.d\
    \ > b.d; });\n    int mxD = r[0].d;\n    for (int i = 0; i < sz(r); ++i) r[i].d\
    \ = min(i, mxD) + 1;\n  }\n  void expand(vv& R, int lev = 1) {\n    S[lev] +=\
    \ S[lev - 1] - old[lev];\n    old[lev] = S[lev - 1];\n    while (sz(R)) {\n  \
    \    if (sz(q) + R.back().d <= sz(qmax)) return;\n      q.push_back(R.back().i);\n\
    \      vv T;\n      for (auto v : R)\n        if (e[R.back().i][v.i]) T.push_back({v.i});\n\
    \      if (sz(T)) {\n        if (S[lev]++ / ++pk < limit) init(T);\n        int\
    \ j = 0, mxk = 1, mnk = max(sz(qmax) - sz(q) + 1, 1);\n        C[1].clear(), C[2].clear();\n\
    \        for (auto v : T) {\n          int k = 1;\n          auto f = [&](int\
    \ i) { return e[v.i][i]; };\n          while (any_of(all(C[k]), f)) k++;\n   \
    \       if (k > mxk) mxk = k, C[mxk + 1].clear();\n          if (k < mnk) T[j++].i\
    \ = v.i;\n          C[k].push_back(v.i);\n        }\n        if (j > 0) T[j -\
    \ 1].d = 0;\n        for (int k = mnk; k <= mxk; ++k) {\n          for (int i\
    \ : C[k]) T[j].i = i, T[j++].d = k;\n        }\n        expand(T, lev + 1);\n\
    \      } else if (sz(q) > sz(qmax))\n        qmax = q;\n      q.pop_back(), R.pop_back();\n\
    \    }\n  }\n  vi maxClique() {\n    init(V), expand(V);\n    return qmax;\n \
    \ }\n  Maxclique(vector<bs> conn) : e(conn), C(sz(e) + 1), S(sz(C)), old(S) {\n\
    \    for (int i = 0; i < sz(e); ++i) V.push_back({i});\n  }\n};\n"
  code: "struct Maxclique {\n  double limit = 0.025, pk = 0;\n  struct Vertex {\n\
    \    int i, d = 0;\n  };\n  typedef vector<Vertex> vv;\n  vector<bs> e;\n  vv\
    \ V;\n  vector<vi> C;\n  vi qmax, q, S, old;  // qmax = vertices in maximum clique,\
    \ q = current clique\n  void init(vv& r) {\n    for (auto& v : r) v.d = 0;\n \
    \   for (auto& v : r) {\n      for (auto j : r) v.d += e[v.i][j.i];\n    }\n \
    \   sort(all(r), [](auto a, auto b) { return a.d > b.d; });\n    int mxD = r[0].d;\n\
    \    for (int i = 0; i < sz(r); ++i) r[i].d = min(i, mxD) + 1;\n  }\n  void expand(vv&\
    \ R, int lev = 1) {\n    S[lev] += S[lev - 1] - old[lev];\n    old[lev] = S[lev\
    \ - 1];\n    while (sz(R)) {\n      if (sz(q) + R.back().d <= sz(qmax)) return;\n\
    \      q.push_back(R.back().i);\n      vv T;\n      for (auto v : R)\n       \
    \ if (e[R.back().i][v.i]) T.push_back({v.i});\n      if (sz(T)) {\n        if\
    \ (S[lev]++ / ++pk < limit) init(T);\n        int j = 0, mxk = 1, mnk = max(sz(qmax)\
    \ - sz(q) + 1, 1);\n        C[1].clear(), C[2].clear();\n        for (auto v :\
    \ T) {\n          int k = 1;\n          auto f = [&](int i) { return e[v.i][i];\
    \ };\n          while (any_of(all(C[k]), f)) k++;\n          if (k > mxk) mxk\
    \ = k, C[mxk + 1].clear();\n          if (k < mnk) T[j++].i = v.i;\n         \
    \ C[k].push_back(v.i);\n        }\n        if (j > 0) T[j - 1].d = 0;\n      \
    \  for (int k = mnk; k <= mxk; ++k) {\n          for (int i : C[k]) T[j].i = i,\
    \ T[j++].d = k;\n        }\n        expand(T, lev + 1);\n      } else if (sz(q)\
    \ > sz(qmax))\n        qmax = q;\n      q.pop_back(), R.pop_back();\n    }\n \
    \ }\n  vi maxClique() {\n    init(V), expand(V);\n    return qmax;\n  }\n  Maxclique(vector<bs>\
    \ conn) : e(conn), C(sz(e) + 1), S(sz(C)), old(S) {\n    for (int i = 0; i < sz(e);\
    \ ++i) V.push_back({i});\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: misc/MaximumClique.h
  requiredBy: []
  timestamp: '2025-11-15 18:26:28+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/Maximum_Independent_Set.test.cpp
documentation_of: misc/MaximumClique.h
layout: document
redirect_from:
- /library/misc/MaximumClique.h
- /library/misc/MaximumClique.h.html
title: misc/MaximumClique.h
---
