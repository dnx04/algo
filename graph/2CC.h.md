---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/Biconnected_Components.test.cpp
    title: tests/Biconnected_Components.test.cpp
  - icon: ':x:'
    path: tests/Two_Edges_CC.test.cpp
    title: tests/Two_Edges_CC.test.cpp
  _isVerificationFailed: true
  _pathExtension: h
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/2CC.h\"\nstruct BCC {\n  const vector<vi>& g;\n  int\
    \ n, ti = 0;\n  vector<vi> tree, blks;\n  vi tin, low, st;\n  void dfs(int u,\
    \ int p = -1) {\n    tin[u] = low[u] = ++ti;\n    st.pb(u);\n    for (int v :\
    \ g[u])\n      if (v != p) {\n        if (tin[v])\n          low[u] = min(low[u],\
    \ tin[v]);\n        else {\n          dfs(v, u);\n          low[u] = min(low[u],\
    \ low[v]);\n          if (low[v] >= tin[u]) {\n            blks.pb({u});\n   \
    \         for (int x = -1; x != v; st.pop_back()) blks.back().pb(x = st.back());\n\
    \          }\n        }\n      }\n  }\n  BCC(const vector<vi>& G) : g(G), n(len(G)),\
    \ tin(n), low(n) {\n    for (int i = 0; i < n; ++i)\n      if (!tin[i]) {\n  \
    \      dfs(i);\n        if (g[i].empty()) blks.pb({i});\n      }\n    tree.assign(n\
    \ + len(blks), {});\n    for (int i = 0; i < len(blks); ++i) {\n      int bid\
    \ = n + i;\n      for (int u : blks[i]) tree[bid].pb(u), tree[u].pb(bid);\n  \
    \  }\n  }\n};\n\nstruct ECC {\n  const vector<vi>& g;\n  int n, ti = 0;\n  vector<vi>\
    \ tree, comps;\n  vi tin, low, id, st;\n  void dfs(int u, int p = -1) {\n    tin[u]\
    \ = low[u] = ++ti;\n    st.pb(u);\n    bool skipped = false;  // Fix multiple\
    \ edges\n    for (int v : g[u]) {\n      if (v == p && !skipped) {\n        skipped\
    \ = true;\n        continue;\n      }\n      if (tin[v])\n        low[u] = min(low[u],\
    \ tin[v]);\n      else {\n        dfs(v, u);\n        low[u] = min(low[u], low[v]);\n\
    \      }\n    }\n    if (low[u] == tin[u]) {  // Component root\n      comps.pb({});\n\
    \      for (int x = -1; x != u; st.pop_back()) {\n        id[x = st.back()] =\
    \ len(comps) - 1;\n        comps.back().pb(x);\n      }\n    }\n  }\n  ECC(const\
    \ vector<vi>& G) : g(G), n(len(G)), tin(n), low(n), id(n) {\n    for (int i =\
    \ 0; i < n; ++i)\n      if (!tin[i]) dfs(i);\n    tree.assign(len(comps), {});\n\
    \    for (int u = 0; u < n; ++u)\n      for (int v : g[u])\n        if (id[u]\
    \ != id[v]) tree[id[u]].pb(id[v]);\n    for (auto& adj : tree) {\n      sort(all(adj));\n\
    \      adj.erase(unique(all(adj)), adj.end());\n    }\n  }\n};\n"
  code: "struct BCC {\n  const vector<vi>& g;\n  int n, ti = 0;\n  vector<vi> tree,\
    \ blks;\n  vi tin, low, st;\n  void dfs(int u, int p = -1) {\n    tin[u] = low[u]\
    \ = ++ti;\n    st.pb(u);\n    for (int v : g[u])\n      if (v != p) {\n      \
    \  if (tin[v])\n          low[u] = min(low[u], tin[v]);\n        else {\n    \
    \      dfs(v, u);\n          low[u] = min(low[u], low[v]);\n          if (low[v]\
    \ >= tin[u]) {\n            blks.pb({u});\n            for (int x = -1; x != v;\
    \ st.pop_back()) blks.back().pb(x = st.back());\n          }\n        }\n    \
    \  }\n  }\n  BCC(const vector<vi>& G) : g(G), n(len(G)), tin(n), low(n) {\n  \
    \  for (int i = 0; i < n; ++i)\n      if (!tin[i]) {\n        dfs(i);\n      \
    \  if (g[i].empty()) blks.pb({i});\n      }\n    tree.assign(n + len(blks), {});\n\
    \    for (int i = 0; i < len(blks); ++i) {\n      int bid = n + i;\n      for\
    \ (int u : blks[i]) tree[bid].pb(u), tree[u].pb(bid);\n    }\n  }\n};\n\nstruct\
    \ ECC {\n  const vector<vi>& g;\n  int n, ti = 0;\n  vector<vi> tree, comps;\n\
    \  vi tin, low, id, st;\n  void dfs(int u, int p = -1) {\n    tin[u] = low[u]\
    \ = ++ti;\n    st.pb(u);\n    bool skipped = false;  // Fix multiple edges\n \
    \   for (int v : g[u]) {\n      if (v == p && !skipped) {\n        skipped = true;\n\
    \        continue;\n      }\n      if (tin[v])\n        low[u] = min(low[u], tin[v]);\n\
    \      else {\n        dfs(v, u);\n        low[u] = min(low[u], low[v]);\n   \
    \   }\n    }\n    if (low[u] == tin[u]) {  // Component root\n      comps.pb({});\n\
    \      for (int x = -1; x != u; st.pop_back()) {\n        id[x = st.back()] =\
    \ len(comps) - 1;\n        comps.back().pb(x);\n      }\n    }\n  }\n  ECC(const\
    \ vector<vi>& G) : g(G), n(len(G)), tin(n), low(n), id(n) {\n    for (int i =\
    \ 0; i < n; ++i)\n      if (!tin[i]) dfs(i);\n    tree.assign(len(comps), {});\n\
    \    for (int u = 0; u < n; ++u)\n      for (int v : g[u])\n        if (id[u]\
    \ != id[v]) tree[id[u]].pb(id[v]);\n    for (auto& adj : tree) {\n      sort(all(adj));\n\
    \      adj.erase(unique(all(adj)), adj.end());\n    }\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/2CC.h
  requiredBy: []
  timestamp: '2026-10-03 15:27:40+00:00'
  verificationStatus: LIBRARY_SOME_WA
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
