---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/General_Matching.test.cpp
    title: tests/General_Matching.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/GeneralMatching.h\"\nvector<int> GeneralMatching(vector<vector<int>>&\
    \ graph) {\n  int n = graph.size(), timer = -1;\n  vector<int> mate(n, -1), label(n),\
    \ parent(n), \n              orig(n), aux(n, -1), q;\n  auto lca = [&](int x,\
    \ int y) {\n    for (timer++; ; swap(x, y)) {\n      if (x == -1) continue;\n\
    \      if (aux[x] == timer) return x;\n      aux[x] = timer;\n      x = (mate[x]\
    \ == -1 ? -1 : orig[parent[mate[x]]]);\n    }\n  };\n  auto blossom = [&](int\
    \ v, int w, int a) {\n    while (orig[v] != a) {\n      parent[v] = w; w = mate[v];\n\
    \      if (label[w] == 1) label[w] = 0, q.push_back(w);\n      orig[v] = orig[w]\
    \ = a; v = parent[w];\n    }\n  };\n  auto augment = [&](int v) {\n    while (v\
    \ != -1) {\n      int pv = parent[v], nv = mate[pv];\n      mate[v] = pv; mate[pv]\
    \ = v; v = nv;\n    }\n  };\n  auto bfs = [&](int root) {\n    fill(label.begin(),\
    \ label.end(), -1);\n    iota(orig.begin(), orig.end(), 0);\n    q.clear(); \n\
    \    label[root] = 0; q.push_back(root);\n    for (int i = 0; i < (int)q.size();\
    \ ++i) {\n      int v = q[i];\n      for (auto x : graph[v]) {\n        if (label[x]\
    \ == -1) {\n          label[x] = 1; parent[x] = v;\n          if (mate[x] == -1)\
    \ \n            return augment(x), 1;\n          label[mate[x]] = 0; q.push_back(mate[x]);\n\
    \        } else if (label[x] == 0 && orig[v] != orig[x]) {\n          int a =\
    \ lca(orig[v], orig[x]);\n          blossom(x, v, a); blossom(v, x, a);\n    \
    \    }\n      }\n    }\n    return 0;\n  };\n  // Time halves if you start with\
    \ (any) maximal matching.\n  for (int i = 0; i < n; i++) \n    if (mate[i] ==\
    \ -1) \n      bfs(i);\n  return mate;\n}\n"
  code: "vector<int> GeneralMatching(vector<vector<int>>& graph) {\n  int n = graph.size(),\
    \ timer = -1;\n  vector<int> mate(n, -1), label(n), parent(n), \n            \
    \  orig(n), aux(n, -1), q;\n  auto lca = [&](int x, int y) {\n    for (timer++;\
    \ ; swap(x, y)) {\n      if (x == -1) continue;\n      if (aux[x] == timer) return\
    \ x;\n      aux[x] = timer;\n      x = (mate[x] == -1 ? -1 : orig[parent[mate[x]]]);\n\
    \    }\n  };\n  auto blossom = [&](int v, int w, int a) {\n    while (orig[v]\
    \ != a) {\n      parent[v] = w; w = mate[v];\n      if (label[w] == 1) label[w]\
    \ = 0, q.push_back(w);\n      orig[v] = orig[w] = a; v = parent[w];\n    }\n \
    \ };\n  auto augment = [&](int v) {\n    while (v != -1) {\n      int pv = parent[v],\
    \ nv = mate[pv];\n      mate[v] = pv; mate[pv] = v; v = nv;\n    }\n  };\n  auto\
    \ bfs = [&](int root) {\n    fill(label.begin(), label.end(), -1);\n    iota(orig.begin(),\
    \ orig.end(), 0);\n    q.clear(); \n    label[root] = 0; q.push_back(root);\n\
    \    for (int i = 0; i < (int)q.size(); ++i) {\n      int v = q[i];\n      for\
    \ (auto x : graph[v]) {\n        if (label[x] == -1) {\n          label[x] = 1;\
    \ parent[x] = v;\n          if (mate[x] == -1) \n            return augment(x),\
    \ 1;\n          label[mate[x]] = 0; q.push_back(mate[x]);\n        } else if (label[x]\
    \ == 0 && orig[v] != orig[x]) {\n          int a = lca(orig[v], orig[x]);\n  \
    \        blossom(x, v, a); blossom(v, x, a);\n        }\n      }\n    }\n    return\
    \ 0;\n  };\n  // Time halves if you start with (any) maximal matching.\n  for\
    \ (int i = 0; i < n; i++) \n    if (mate[i] == -1) \n      bfs(i);\n  return mate;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: graph/GeneralMatching.h
  requiredBy: []
  timestamp: '2025-11-15 18:26:28+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/General_Matching.test.cpp
documentation_of: graph/GeneralMatching.h
layout: document
redirect_from:
- /library/graph/GeneralMatching.h
- /library/graph/GeneralMatching.h.html
title: graph/GeneralMatching.h
---
