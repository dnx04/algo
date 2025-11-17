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
  bundledCode: "#line 1 \"graph/LowLink.h\"\ntemplate <typename G>\nstruct LowLink\
    \ {\n  const G& g;\n  int N;\n  vector<int> ord, low, articulation;\n  vector<pair<int,\
    \ int> > bridge;\n\n  LowLink(const G& g) : g(g), N(g.size()), ord(N, -1), low(N,\
    \ -1) {\n    for (int i = 0, k = 0; i < N; i++) {\n      if (ord[i] == -1) {\n\
    \        k = dfs(i, k, -1);\n      }\n    }\n  }\n\n  int dfs(int idx, int k,\
    \ int par) {\n    low[idx] = (ord[idx] = k++);\n    int cnt = 0;\n    bool arti\
    \ = false, second = false;\n    for (auto& to : g[idx]) {\n      if (ord[to] ==\
    \ -1) {\n        cnt++;\n        k = dfs(to, k, idx);\n        low[idx] = min(low[idx],\
    \ low[to]);\n        arti |= (par != -1) && (low[to] >= ord[idx]);\n        if\
    \ (ord[idx] < low[to]) {\n          bridge.emplace_back(minmax(idx, (int) to));\n\
    \        }\n      } else if (to != par || second) {\n        low[idx] = min(low[idx],\
    \ ord[to]);\n      } else {\n        second = true;\n      }\n    }\n    arti\
    \ |= par == -1 && cnt > 1;\n    if (arti) articulation.push_back(idx);\n    return\
    \ k;\n  }\n};\n"
  code: "template <typename G>\nstruct LowLink {\n  const G& g;\n  int N;\n  vector<int>\
    \ ord, low, articulation;\n  vector<pair<int, int> > bridge;\n\n  LowLink(const\
    \ G& g) : g(g), N(g.size()), ord(N, -1), low(N, -1) {\n    for (int i = 0, k =\
    \ 0; i < N; i++) {\n      if (ord[i] == -1) {\n        k = dfs(i, k, -1);\n  \
    \    }\n    }\n  }\n\n  int dfs(int idx, int k, int par) {\n    low[idx] = (ord[idx]\
    \ = k++);\n    int cnt = 0;\n    bool arti = false, second = false;\n    for (auto&\
    \ to : g[idx]) {\n      if (ord[to] == -1) {\n        cnt++;\n        k = dfs(to,\
    \ k, idx);\n        low[idx] = min(low[idx], low[to]);\n        arti |= (par !=\
    \ -1) && (low[to] >= ord[idx]);\n        if (ord[idx] < low[to]) {\n         \
    \ bridge.emplace_back(minmax(idx, (int) to));\n        }\n      } else if (to\
    \ != par || second) {\n        low[idx] = min(low[idx], ord[to]);\n      } else\
    \ {\n        second = true;\n      }\n    }\n    arti |= par == -1 && cnt > 1;\n\
    \    if (arti) articulation.push_back(idx);\n    return k;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/LowLink.h
  requiredBy: []
  timestamp: '2025-11-17 23:51:26+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/LowLink.h
layout: document
redirect_from:
- /library/graph/LowLink.h
- /library/graph/LowLink.h.html
title: graph/LowLink.h
---
