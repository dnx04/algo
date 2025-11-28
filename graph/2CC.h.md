---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/Biconnected_Components.test.cpp
    title: tests/Biconnected_Components.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Two_Edges_CC.test.cpp
    title: tests/Two_Edges_CC.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/2CC.h\"\nstruct BCC {\n  const vector<vi>& g;\n  int\
    \ n, ti = 0;\n  vector<vi> tree, blks;\n  vi tin, low, st;\n  void dfs(int u,\
    \ int p = -1) {\n    tin[u] = low[u] = ++ti;\n    st.pb(u);\n    for (int v :\
    \ g[u]) if (v != p) {\n      if (tin[v]) low[u] = min(low[u], tin[v]);\n     \
    \ else {\n        dfs(v, u);\n        low[u] = min(low[u], low[v]);\n        if\
    \ (low[v] >= tin[u]) {\n          blks.pb({u});\n          for (int x = -1; x\
    \ != v; st.pop_back()) blks.back().pb(x = st.back());\n        }\n      }\n  \
    \  }\n  }\n  BCC(const vector<vi>& G) : g(G), n(sz(G)), tin(n), low(n) {\n   \
    \ for (int i = 0; i < n; ++i) if (!tin[i]) {\n      dfs(i);\n      if (g[i].empty())\
    \ blks.pb({i});\n    }\n    tree.assign(n + sz(blks), {});\n    for (int i = 0;\
    \ i < sz(blks); ++i) {\n      int bid = n + i;\n      for (int u : blks[i]) tree[bid].pb(u),\
    \ tree[u].pb(bid);\n    }\n  }\n};\n\nstruct ECC {\n  const vector<vi>& g;\n \
    \ int n, ti = 0;\n  vector<vi> tree, comps;\n  vi tin, low, id, st;\n  void dfs(int\
    \ u, int p = -1) {\n    tin[u] = low[u] = ++ti;\n    st.pb(u);\n    bool skipped\
    \ = false; // Fix multiple edges\n    for (int v : g[u]) {\n      if (v == p &&\
    \ !skipped) { skipped = true; continue; }\n      if (tin[v]) low[u] = min(low[u],\
    \ tin[v]);\n      else {\n        dfs(v, u);\n        low[u] = min(low[u], low[v]);\n\
    \      }\n    }\n    if (low[u] == tin[u]) { // Component root\n      comps.pb({});\n\
    \      for (int x = -1; x != u; st.pop_back()) {\n        id[x = st.back()] =\
    \ sz(comps) - 1;\n        comps.back().pb(x);\n      }\n    }\n  }\n  ECC(const\
    \ vector<vi>& G) : g(G), n(sz(G)), tin(n), low(n), id(n) {\n    for (int i = 0;\
    \ i < n; ++i) if (!tin[i]) dfs(i);\n    tree.assign(sz(comps), {});\n    for (int\
    \ u = 0; u < n; ++u) for (int v : g[u])\n      if (id[u] != id[v]) tree[id[u]].pb(id[v]);\n\
    \    for (auto& adj : tree) {\n      sort(all(adj)); adj.erase(unique(all(adj)),\
    \ adj.end());\n    }\n  }\n};\n"
  code: "struct BCC {\n  const vector<vi>& g;\n  int n, ti = 0;\n  vector<vi> tree,\
    \ blks;\n  vi tin, low, st;\n  void dfs(int u, int p = -1) {\n    tin[u] = low[u]\
    \ = ++ti;\n    st.pb(u);\n    for (int v : g[u]) if (v != p) {\n      if (tin[v])\
    \ low[u] = min(low[u], tin[v]);\n      else {\n        dfs(v, u);\n        low[u]\
    \ = min(low[u], low[v]);\n        if (low[v] >= tin[u]) {\n          blks.pb({u});\n\
    \          for (int x = -1; x != v; st.pop_back()) blks.back().pb(x = st.back());\n\
    \        }\n      }\n    }\n  }\n  BCC(const vector<vi>& G) : g(G), n(sz(G)),\
    \ tin(n), low(n) {\n    for (int i = 0; i < n; ++i) if (!tin[i]) {\n      dfs(i);\n\
    \      if (g[i].empty()) blks.pb({i});\n    }\n    tree.assign(n + sz(blks), {});\n\
    \    for (int i = 0; i < sz(blks); ++i) {\n      int bid = n + i;\n      for (int\
    \ u : blks[i]) tree[bid].pb(u), tree[u].pb(bid);\n    }\n  }\n};\n\nstruct ECC\
    \ {\n  const vector<vi>& g;\n  int n, ti = 0;\n  vector<vi> tree, comps;\n  vi\
    \ tin, low, id, st;\n  void dfs(int u, int p = -1) {\n    tin[u] = low[u] = ++ti;\n\
    \    st.pb(u);\n    bool skipped = false; // Fix multiple edges\n    for (int\
    \ v : g[u]) {\n      if (v == p && !skipped) { skipped = true; continue; }\n \
    \     if (tin[v]) low[u] = min(low[u], tin[v]);\n      else {\n        dfs(v,\
    \ u);\n        low[u] = min(low[u], low[v]);\n      }\n    }\n    if (low[u] ==\
    \ tin[u]) { // Component root\n      comps.pb({});\n      for (int x = -1; x !=\
    \ u; st.pop_back()) {\n        id[x = st.back()] = sz(comps) - 1;\n        comps.back().pb(x);\n\
    \      }\n    }\n  }\n  ECC(const vector<vi>& G) : g(G), n(sz(G)), tin(n), low(n),\
    \ id(n) {\n    for (int i = 0; i < n; ++i) if (!tin[i]) dfs(i);\n    tree.assign(sz(comps),\
    \ {});\n    for (int u = 0; u < n; ++u) for (int v : g[u])\n      if (id[u] !=\
    \ id[v]) tree[id[u]].pb(id[v]);\n    for (auto& adj : tree) {\n      sort(all(adj));\
    \ adj.erase(unique(all(adj)), adj.end());\n    }\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/2CC.h
  requiredBy: []
  timestamp: '2025-11-28 15:36:49+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/Biconnected_Components.test.cpp
  - tests/Two_Edges_CC.test.cpp
documentation_of: graph/2CC.h
layout: document
redirect_from:
- /library/graph/2CC.h
- /library/graph/2CC.h.html
title: graph/2CC.h
---
