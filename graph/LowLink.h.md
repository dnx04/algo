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
    \ {\n  const G& g;\n  int N;\n  vector<int> ord, low, cut;\n  vector<pii> bridge;\n\
    \  LowLink(const G& g) : g(g), N(g.size()), ord(N, -1), low(N, -1) {\n    for\
    \ (int i = 0, k = 0; i < N; i++) {\n      if (ord[i] == -1) k = dfs(i, k, -1);\n\
    \    }\n  }\n  int dfs(int idx, int k, int par) {\n    low[idx] = (ord[idx] =\
    \ k++);\n    int cnt = 0;\n    bool arti = false, second = false;\n    for (auto&\
    \ to : g[idx]) {\n      if (ord[to] == -1) {\n        cnt++;\n        k = dfs(to,\
    \ k, idx);\n        low[idx] = min(low[idx], low[to]);\n        arti |= (par !=\
    \ -1) && (low[to] >= ord[idx]);\n        if (ord[idx] < low[to]) bridge.eb(minmax(idx,\
    \ (int) to));\n      } else if (to != par || second) {\n        low[idx] = min(low[idx],\
    \ ord[to]);\n      } else {\n        second = true;\n      }\n    }\n    arti\
    \ |= par == -1 && cnt > 1;\n    if (arti) cut.eb(idx);\n    return k;\n  }\n};\n"
  code: "template <typename G>\nstruct LowLink {\n  const G& g;\n  int N;\n  vector<int>\
    \ ord, low, cut;\n  vector<pii> bridge;\n  LowLink(const G& g) : g(g), N(g.size()),\
    \ ord(N, -1), low(N, -1) {\n    for (int i = 0, k = 0; i < N; i++) {\n      if\
    \ (ord[i] == -1) k = dfs(i, k, -1);\n    }\n  }\n  int dfs(int idx, int k, int\
    \ par) {\n    low[idx] = (ord[idx] = k++);\n    int cnt = 0;\n    bool arti =\
    \ false, second = false;\n    for (auto& to : g[idx]) {\n      if (ord[to] ==\
    \ -1) {\n        cnt++;\n        k = dfs(to, k, idx);\n        low[idx] = min(low[idx],\
    \ low[to]);\n        arti |= (par != -1) && (low[to] >= ord[idx]);\n        if\
    \ (ord[idx] < low[to]) bridge.eb(minmax(idx, (int) to));\n      } else if (to\
    \ != par || second) {\n        low[idx] = min(low[idx], ord[to]);\n      } else\
    \ {\n        second = true;\n      }\n    }\n    arti |= par == -1 && cnt > 1;\n\
    \    if (arti) cut.eb(idx);\n    return k;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/LowLink.h
  requiredBy: []
  timestamp: '2025-11-20 10:20:22+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/LowLink.h
layout: document
redirect_from:
- /library/graph/LowLink.h
- /library/graph/LowLink.h.html
title: graph/LowLink.h
---
