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
  bundledCode: "#line 1 \"graph/GomoryHu.h\"\ntypedef array<ll, 3> Edge;\nvector<Edge>\
    \ gomoryHu(int N, vector<Edge> ed) {\n  vector<Edge> tree;\n  vi par(N);\n  for\
    \ (int i = 1; i < N; ++i) {\n    Dinic D(N);  // Dinic also works\n    for (Edge\
    \ t : ed) D.addEdge(t[0], t[1], t[2], t[2]);\n    tree.push_back({i, par[i], D.calc(i,\
    \ par[i])});\n    for (int j = i + 1; j < N; ++j)\n      if (par[j] == par[i]\
    \ && D.leftOfMinCut(j)) par[j] = i;\n  }\n  return tree;\n}\n"
  code: "typedef array<ll, 3> Edge;\nvector<Edge> gomoryHu(int N, vector<Edge> ed)\
    \ {\n  vector<Edge> tree;\n  vi par(N);\n  for (int i = 1; i < N; ++i) {\n   \
    \ Dinic D(N);  // Dinic also works\n    for (Edge t : ed) D.addEdge(t[0], t[1],\
    \ t[2], t[2]);\n    tree.push_back({i, par[i], D.calc(i, par[i])});\n    for (int\
    \ j = i + 1; j < N; ++j)\n      if (par[j] == par[i] && D.leftOfMinCut(j)) par[j]\
    \ = i;\n  }\n  return tree;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/GomoryHu.h
  requiredBy: []
  timestamp: '2025-11-15 18:26:28+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/GomoryHu.h
layout: document
redirect_from:
- /library/graph/GomoryHu.h
- /library/graph/GomoryHu.h.html
title: graph/GomoryHu.h
---
