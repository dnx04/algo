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
  bundledCode: "#line 1 \"graph/GlobalMinCut.h\"\npair<int, vi> globalMinCut(vector<vi>\
    \ mat) {\n  pair<int, vi> best = {INT_MAX, {}};\n  int n = sz(mat);\n  vector<vi>\
    \ co(n);\n  for (int i = 0; i < n; ++i) co[i] = {i};\n  for (int ph = 1; ph <\
    \ n; ++ph) {\n    vi w = mat[0];\n    size_t s = 0, t = 0;\n    for (int it =\
    \ 0; it < n - ph; ++it) {  // O(V^2) -> O(E log V) with prio. queue\n      w[t]\
    \ = INT_MIN;\n      s = t, t = max_element(all(w)) - w.begin();\n      for (int\
    \ i = 0; i < n; ++i) w[i] += mat[t][i];\n    }\n    best = min(best, {w[t] - mat[t][t],\
    \ co[t]});\n    co[s].insert(co[s].end(), all(co[t]));\n    for (int i = 0; i\
    \ < n; ++i) mat[s][i] += mat[t][i];\n    for (int i = 0; i < n; ++i) mat[i][s]\
    \ = mat[s][i];\n    mat[0][t] = INT_MIN;\n  }\n  return best;\n}\n"
  code: "pair<int, vi> globalMinCut(vector<vi> mat) {\n  pair<int, vi> best = {INT_MAX,\
    \ {}};\n  int n = sz(mat);\n  vector<vi> co(n);\n  for (int i = 0; i < n; ++i)\
    \ co[i] = {i};\n  for (int ph = 1; ph < n; ++ph) {\n    vi w = mat[0];\n    size_t\
    \ s = 0, t = 0;\n    for (int it = 0; it < n - ph; ++it) {  // O(V^2) -> O(E log\
    \ V) with prio. queue\n      w[t] = INT_MIN;\n      s = t, t = max_element(all(w))\
    \ - w.begin();\n      for (int i = 0; i < n; ++i) w[i] += mat[t][i];\n    }\n\
    \    best = min(best, {w[t] - mat[t][t], co[t]});\n    co[s].insert(co[s].end(),\
    \ all(co[t]));\n    for (int i = 0; i < n; ++i) mat[s][i] += mat[t][i];\n    for\
    \ (int i = 0; i < n; ++i) mat[i][s] = mat[s][i];\n    mat[0][t] = INT_MIN;\n \
    \ }\n  return best;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/GlobalMinCut.h
  requiredBy: []
  timestamp: '2025-11-15 18:26:28+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/GlobalMinCut.h
layout: document
redirect_from:
- /library/graph/GlobalMinCut.h
- /library/graph/GlobalMinCut.h.html
title: graph/GlobalMinCut.h
---
