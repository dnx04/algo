---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/Dominator_Tree.test.cpp
    title: tests/Dominator_Tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/Dominator.h\"\nvector<int> DomTree(const vector<vi>&\
    \ g, int s) {\n  int n = len(g), t = 0;\n  vector<int> arr(n, -1), rev(n), par(n),\
    \ sdom(n), dom(n), dsu(n), lab(n), res(n, -1);\n  vector<vi> rg(n), buck(n);\n\
    \  auto dfs = [&](auto&& self, int u) -> void {\n    arr[u] = t, rev[t] = u, lab[t]\
    \ = sdom[t] = dsu[t] = t, t++;\n    for (int v : g[u]) {\n      if (arr[v] ==\
    \ -1) self(self, v), par[arr[v]] = arr[u];\n      rg[arr[v]].pb(arr[u]);\n   \
    \ }\n  };\n  dfs(dfs, s);\n  auto find = [&](auto&& self, int u) -> int {\n  \
    \  if (u == dsu[u]) return u;\n    int v = self(self, dsu[u]);\n    if (sdom[lab[dsu[u]]]\
    \ < sdom[lab[u]]) lab[u] = lab[dsu[u]];\n    return dsu[u] = v;\n  };\n  for (int\
    \ i = t - 1; i; --i) {\n    for (int v : rg[i]) find(find, v), sdom[i] = min(sdom[i],\
    \ sdom[lab[v]]);\n    buck[sdom[i]].pb(i);\n    int p = par[i];\n    dsu[i] =\
    \ p;\n    for (int v : buck[p]) find(find, v), dom[v] = (sdom[lab[v]] == sdom[v]\
    \ ? p : lab[v]);\n    buck[p].clear();\n  }\n  for (int i = 1; i < t; ++i) {\n\
    \    if (dom[i] != sdom[i]) dom[i] = dom[dom[i]];\n    res[rev[i]] = rev[dom[i]];\n\
    \  }\n  return res;\n}\n"
  code: "vector<int> DomTree(const vector<vi>& g, int s) {\n  int n = len(g), t =\
    \ 0;\n  vector<int> arr(n, -1), rev(n), par(n), sdom(n), dom(n), dsu(n), lab(n),\
    \ res(n, -1);\n  vector<vi> rg(n), buck(n);\n  auto dfs = [&](auto&& self, int\
    \ u) -> void {\n    arr[u] = t, rev[t] = u, lab[t] = sdom[t] = dsu[t] = t, t++;\n\
    \    for (int v : g[u]) {\n      if (arr[v] == -1) self(self, v), par[arr[v]]\
    \ = arr[u];\n      rg[arr[v]].pb(arr[u]);\n    }\n  };\n  dfs(dfs, s);\n  auto\
    \ find = [&](auto&& self, int u) -> int {\n    if (u == dsu[u]) return u;\n  \
    \  int v = self(self, dsu[u]);\n    if (sdom[lab[dsu[u]]] < sdom[lab[u]]) lab[u]\
    \ = lab[dsu[u]];\n    return dsu[u] = v;\n  };\n  for (int i = t - 1; i; --i)\
    \ {\n    for (int v : rg[i]) find(find, v), sdom[i] = min(sdom[i], sdom[lab[v]]);\n\
    \    buck[sdom[i]].pb(i);\n    int p = par[i];\n    dsu[i] = p;\n    for (int\
    \ v : buck[p]) find(find, v), dom[v] = (sdom[lab[v]] == sdom[v] ? p : lab[v]);\n\
    \    buck[p].clear();\n  }\n  for (int i = 1; i < t; ++i) {\n    if (dom[i] !=\
    \ sdom[i]) dom[i] = dom[dom[i]];\n    res[rev[i]] = rev[dom[i]];\n  }\n  return\
    \ res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/Dominator.h
  requiredBy: []
  timestamp: '2026-10-03 15:27:40+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/Dominator_Tree.test.cpp
documentation_of: graph/Dominator.h
layout: document
redirect_from:
- /library/graph/Dominator.h
- /library/graph/Dominator.h.html
title: graph/Dominator.h
---
