---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/Assignment_Problem.test.cpp
    title: tests/Assignment_Problem.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/MinAssignment.h\"\npair<ll, vector<int>> MinAssignment(const\
    \ vector<vector<ll>>& W) {\n  int n = W.size(), m = W[0].size();  // assert(n\
    \ <= m);\n  vector<ll> v(m), dist(m);           // v: potential\n  vector<int>\
    \ L(n, -1), R(m, -1);     // matching pairs\n  vector<int> idx(m), prev(m);\n\
    \  iota(idx.begin(), idx.end(), 0);\n\n  ll w, h;\n  int j, l, s, t;\n  auto reduce\
    \ = [&]() {\n    if (s == t) {\n      l = s;\n      w = dist[idx[t++]];\n    \
    \  for (int k = t; k < m; ++k) {\n        j = idx[k];\n        h = dist[j];\n\
    \        if (h > w) continue;\n        if (h < w) t = s, w = h;\n        idx[k]\
    \ = idx[t];\n        idx[t++] = j;\n      }\n      for (int k = s; k < t; ++k)\
    \ {\n        j = idx[k];\n        if (R[j] < 0) return 1;\n      }\n    }\n  \
    \  int q = idx[s++], p = R[q];\n    for (int k = t; k < m; ++k) {\n      j = idx[k];\n\
    \      h = W[p][j] - W[p][q] + v[q] - v[j] + w;\n      if (h < dist[j]) {\n  \
    \      dist[j] = h;\n        prev[j] = p;\n        if (h == w) {\n          if\
    \ (R[j] < 0) return 1;\n          idx[k] = idx[t];\n          idx[t++] = j;\n\
    \        }\n      }\n    }\n    return 0;\n  };\n  for (int i = 0; i < n; ++i)\
    \ {\n    for (int k = 0; k < m; ++k) dist[k] = W[i][k] - v[k], prev[k] = i;\n\
    \    s = t = 0;\n    while (!reduce());\n    for (int k = 0; k < l; ++k) v[idx[k]]\
    \ += dist[idx[k]] - w;\n    for (int k = -1; k != i;) R[j] = k = prev[j], swap(j,\
    \ L[k]);\n  }\n  ll ret = 0;\n  for (int i = 0; i < n; ++i) ret += W[i][L[i]];\
    \  // (i, L[i]) is a solution\n  return {ret, L};\n}\n"
  code: "pair<ll, vector<int>> MinAssignment(const vector<vector<ll>>& W) {\n  int\
    \ n = W.size(), m = W[0].size();  // assert(n <= m);\n  vector<ll> v(m), dist(m);\
    \           // v: potential\n  vector<int> L(n, -1), R(m, -1);     // matching\
    \ pairs\n  vector<int> idx(m), prev(m);\n  iota(idx.begin(), idx.end(), 0);\n\n\
    \  ll w, h;\n  int j, l, s, t;\n  auto reduce = [&]() {\n    if (s == t) {\n \
    \     l = s;\n      w = dist[idx[t++]];\n      for (int k = t; k < m; ++k) {\n\
    \        j = idx[k];\n        h = dist[j];\n        if (h > w) continue;\n   \
    \     if (h < w) t = s, w = h;\n        idx[k] = idx[t];\n        idx[t++] = j;\n\
    \      }\n      for (int k = s; k < t; ++k) {\n        j = idx[k];\n        if\
    \ (R[j] < 0) return 1;\n      }\n    }\n    int q = idx[s++], p = R[q];\n    for\
    \ (int k = t; k < m; ++k) {\n      j = idx[k];\n      h = W[p][j] - W[p][q] +\
    \ v[q] - v[j] + w;\n      if (h < dist[j]) {\n        dist[j] = h;\n        prev[j]\
    \ = p;\n        if (h == w) {\n          if (R[j] < 0) return 1;\n          idx[k]\
    \ = idx[t];\n          idx[t++] = j;\n        }\n      }\n    }\n    return 0;\n\
    \  };\n  for (int i = 0; i < n; ++i) {\n    for (int k = 0; k < m; ++k) dist[k]\
    \ = W[i][k] - v[k], prev[k] = i;\n    s = t = 0;\n    while (!reduce());\n   \
    \ for (int k = 0; k < l; ++k) v[idx[k]] += dist[idx[k]] - w;\n    for (int k =\
    \ -1; k != i;) R[j] = k = prev[j], swap(j, L[k]);\n  }\n  ll ret = 0;\n  for (int\
    \ i = 0; i < n; ++i) ret += W[i][L[i]];  // (i, L[i]) is a solution\n  return\
    \ {ret, L};\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/MinAssignment.h
  requiredBy: []
  timestamp: '2025-11-15 18:26:28+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/Assignment_Problem.test.cpp
documentation_of: graph/MinAssignment.h
layout: document
redirect_from:
- /library/graph/MinAssignment.h
- /library/graph/MinAssignment.h.html
title: graph/MinAssignment.h
---
