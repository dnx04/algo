---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/SCC.test.cpp
    title: tests/SCC.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/SCC.h\"\ntemplate <typename G>\nstruct SCC {\n public:\n\
    \  vector<vi> dag;\n  SCC(G& g) : g(g), used(sz(g), 0) { build(); }\n  int operator[](int\
    \ k) { return comp[k]; } \n  vi& belong(int i) { return blng[i]; }\n\n private:\n\
    \  const G& g;\n  vector<vi> rg;\n  vi comp, ord;\n  vector<bool> used;\n  vector<vi>\
    \ blng;\n\n  void dfs(int idx) {\n    if (used[idx]) return;\n    used[idx] =\
    \ true;\n    for (auto to : g[idx]) dfs(int(to));\n    ord.eb(idx);\n  }\n  void\
    \ rdfs(int idx, int cnt) {\n    if (comp[idx] != -1) return;\n    comp[idx] =\
    \ cnt;\n    for (int to : rg[idx]) rdfs(to, cnt);\n  }\n  void build() {\n   \
    \ for (int i = 0; i < sz(g); i++) dfs(i);\n    reverse(all(ord));\n    used.clear(),\
    \ used.shrink_to_fit();\n    comp.resize(sz(g), -1);\n    rg.resize(sz(g));\n\
    \    for (int i = 0; i < sz(g); i++) {\n      for (auto e : g[i]) {\n        rg[e].emplace_back(i);\n\
    \      }\n    }\n    int ptr = 0;\n    for (int i : ord) if (comp[i] == -1) rdfs(i,\
    \ ptr), ptr++;\n    rg.clear(), rg.shrink_to_fit();\n    ord.clear(), ord.shrink_to_fit();\n\
    \    dag.resize(ptr), blng.resize(ptr);\n    for (int i = 0; i < (int) sz(g);\
    \ i++) {\n      blng[comp[i]].eb(i);\n      for (auto& to : g[i]) {\n        int\
    \ x = comp[i], y = comp[to];\n        if (x == y) continue;\n        dag[x].eb(y);\n\
    \      }\n    }\n  }\n};\n"
  code: "template <typename G>\nstruct SCC {\n public:\n  vector<vi> dag;\n  SCC(G&\
    \ g) : g(g), used(sz(g), 0) { build(); }\n  int operator[](int k) { return comp[k];\
    \ } \n  vi& belong(int i) { return blng[i]; }\n\n private:\n  const G& g;\n  vector<vi>\
    \ rg;\n  vi comp, ord;\n  vector<bool> used;\n  vector<vi> blng;\n\n  void dfs(int\
    \ idx) {\n    if (used[idx]) return;\n    used[idx] = true;\n    for (auto to\
    \ : g[idx]) dfs(int(to));\n    ord.eb(idx);\n  }\n  void rdfs(int idx, int cnt)\
    \ {\n    if (comp[idx] != -1) return;\n    comp[idx] = cnt;\n    for (int to :\
    \ rg[idx]) rdfs(to, cnt);\n  }\n  void build() {\n    for (int i = 0; i < sz(g);\
    \ i++) dfs(i);\n    reverse(all(ord));\n    used.clear(), used.shrink_to_fit();\n\
    \    comp.resize(sz(g), -1);\n    rg.resize(sz(g));\n    for (int i = 0; i < sz(g);\
    \ i++) {\n      for (auto e : g[i]) {\n        rg[e].emplace_back(i);\n      }\n\
    \    }\n    int ptr = 0;\n    for (int i : ord) if (comp[i] == -1) rdfs(i, ptr),\
    \ ptr++;\n    rg.clear(), rg.shrink_to_fit();\n    ord.clear(), ord.shrink_to_fit();\n\
    \    dag.resize(ptr), blng.resize(ptr);\n    for (int i = 0; i < (int) sz(g);\
    \ i++) {\n      blng[comp[i]].eb(i);\n      for (auto& to : g[i]) {\n        int\
    \ x = comp[i], y = comp[to];\n        if (x == y) continue;\n        dag[x].eb(y);\n\
    \      }\n    }\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/SCC.h
  requiredBy: []
  timestamp: '2025-11-20 20:30:36+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/SCC.test.cpp
documentation_of: graph/SCC.h
layout: document
redirect_from:
- /library/graph/SCC.h
- /library/graph/SCC.h.html
title: graph/SCC.h
---
