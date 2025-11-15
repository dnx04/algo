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
  bundledCode: "#line 1 \"graph/Dominator.h\"\nvector<int> DomTree(vector<vector<int>>&\
    \ graph, int src) {\n  int n = graph.size();\n  vector<vector<int>> tree(n), trans(n),\
    \ buck(n);\n  vector<int> semi(n), par(n), dom(n), label(n), atob(n, -1), btoa(n,\
    \ -1), link(n, -1);\n\n  function<int(int, int)> find = [&](int u, int d) {\n\
    \    if (link[u] == -1) return d ? -1 : u;\n    int v = find(link[u], d + 1);\n\
    \    if (v < 0) return u;\n    if (semi[label[link[u]]] < semi[label[u]]) label[u]\
    \ = label[link[u]];\n    link[u] = v;\n    return d ? v : label[u];\n  };\n  int\
    \ t = 0;\n  function<void(int)> dfs = [&](int u) {\n    atob[u] = t;\n    btoa[t]\
    \ = u;\n    label[t] = semi[t] = t;\n    t++;\n    for (auto v : graph[u]) {\n\
    \      if (atob[v] == -1) dfs(v), par[atob[v]] = atob[u];\n      trans[atob[v]].push_back(atob[u]);\n\
    \    }\n  };\n  dfs(src);\n  for (int u = t - 1; u >= 0; --u) {\n    for (auto\
    \ v : trans[u]) semi[u] = min(semi[u], semi[find(v, 0)]);\n    if (u) buck[semi[u]].push_back(u);\n\
    \    for (auto w : buck[u]) {\n      int v = find(w, 0);\n      dom[w] = semi[v]\
    \ == semi[w] ? semi[w] : v;\n    }\n    if (u) link[u] = par[u];\n  }\n  vector<int>\
    \ ret(n, -1);\n  for (int u = 1; u < t; ++u) {\n    if (dom[u] != semi[u]) dom[u]\
    \ = dom[dom[u]];\n    ret[btoa[u]] = btoa[dom[u]];\n  }\n  return ret;\n}\n"
  code: "vector<int> DomTree(vector<vector<int>>& graph, int src) {\n  int n = graph.size();\n\
    \  vector<vector<int>> tree(n), trans(n), buck(n);\n  vector<int> semi(n), par(n),\
    \ dom(n), label(n), atob(n, -1), btoa(n, -1), link(n, -1);\n\n  function<int(int,\
    \ int)> find = [&](int u, int d) {\n    if (link[u] == -1) return d ? -1 : u;\n\
    \    int v = find(link[u], d + 1);\n    if (v < 0) return u;\n    if (semi[label[link[u]]]\
    \ < semi[label[u]]) label[u] = label[link[u]];\n    link[u] = v;\n    return d\
    \ ? v : label[u];\n  };\n  int t = 0;\n  function<void(int)> dfs = [&](int u)\
    \ {\n    atob[u] = t;\n    btoa[t] = u;\n    label[t] = semi[t] = t;\n    t++;\n\
    \    for (auto v : graph[u]) {\n      if (atob[v] == -1) dfs(v), par[atob[v]]\
    \ = atob[u];\n      trans[atob[v]].push_back(atob[u]);\n    }\n  };\n  dfs(src);\n\
    \  for (int u = t - 1; u >= 0; --u) {\n    for (auto v : trans[u]) semi[u] = min(semi[u],\
    \ semi[find(v, 0)]);\n    if (u) buck[semi[u]].push_back(u);\n    for (auto w\
    \ : buck[u]) {\n      int v = find(w, 0);\n      dom[w] = semi[v] == semi[w] ?\
    \ semi[w] : v;\n    }\n    if (u) link[u] = par[u];\n  }\n  vector<int> ret(n,\
    \ -1);\n  for (int u = 1; u < t; ++u) {\n    if (dom[u] != semi[u]) dom[u] = dom[dom[u]];\n\
    \    ret[btoa[u]] = btoa[dom[u]];\n  }\n  return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/Dominator.h
  requiredBy: []
  timestamp: '2025-11-15 18:26:28+07:00'
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
