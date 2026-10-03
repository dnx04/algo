---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/Eulerian_Trail_Directed.test.cpp
    title: tests/Eulerian_Trail_Directed.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Eulerian_Trail_Undirected.test.cpp
    title: tests/Eulerian_Trail_Undirected.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/EulerWalk.h\"\npair<vi, vi> EulerWalk(int n, vector<vector<pii>>&\
    \ adj, int m, bool dir, bool cyc) {\n  vi D(n), ptr(n), used(m), nodes, edges;\n\
    \  vector<pii> st;\n  int src = 0, bad = 0;\n  for (int i = 0; i < n; ++i) {\n\
    \    if (dir)\n      for (auto& p : adj[i]) D[i]++, D[p.first]--;\n    else\n\
    \      D[i] = len(adj[i]) & 1;\n  }\n  for (int i = 0; i < n; ++i) {\n    if (len(adj[i])\
    \ && adj[src].empty()) src = i;\n    if (D[i]) {\n      bad++;\n      if ((dir\
    \ && D[i] > 0) || (!dir)) src = i;\n    }\n  }\n  if (bad > 2 || (cyc && bad)\
    \ || (dir && bad && D[src] != 1)) return {};\n  st.pb({src, -1});\n  while (!st.empty())\
    \ {\n    int u = st.back().first;\n    if (ptr[u] < len(adj[u])) {\n      auto\
    \ [v, id] = adj[u][ptr[u]++];\n      if (!used[id]) used[id] = 1, st.pb({v, id});\n\
    \    } else {\n      auto [v, id] = st.back();\n      st.pop_back();\n      nodes.pb(v);\n\
    \      if (id != -1) edges.pb(id);\n    }\n  }\n  if (len(edges) != m) return\
    \ {};\n  reverse(all(nodes)), reverse(all(edges));\n  return {nodes, edges};\n\
    }\n"
  code: "pair<vi, vi> EulerWalk(int n, vector<vector<pii>>& adj, int m, bool dir,\
    \ bool cyc) {\n  vi D(n), ptr(n), used(m), nodes, edges;\n  vector<pii> st;\n\
    \  int src = 0, bad = 0;\n  for (int i = 0; i < n; ++i) {\n    if (dir)\n    \
    \  for (auto& p : adj[i]) D[i]++, D[p.first]--;\n    else\n      D[i] = len(adj[i])\
    \ & 1;\n  }\n  for (int i = 0; i < n; ++i) {\n    if (len(adj[i]) && adj[src].empty())\
    \ src = i;\n    if (D[i]) {\n      bad++;\n      if ((dir && D[i] > 0) || (!dir))\
    \ src = i;\n    }\n  }\n  if (bad > 2 || (cyc && bad) || (dir && bad && D[src]\
    \ != 1)) return {};\n  st.pb({src, -1});\n  while (!st.empty()) {\n    int u =\
    \ st.back().first;\n    if (ptr[u] < len(adj[u])) {\n      auto [v, id] = adj[u][ptr[u]++];\n\
    \      if (!used[id]) used[id] = 1, st.pb({v, id});\n    } else {\n      auto\
    \ [v, id] = st.back();\n      st.pop_back();\n      nodes.pb(v);\n      if (id\
    \ != -1) edges.pb(id);\n    }\n  }\n  if (len(edges) != m) return {};\n  reverse(all(nodes)),\
    \ reverse(all(edges));\n  return {nodes, edges};\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/EulerWalk.h
  requiredBy: []
  timestamp: '2026-10-03 15:27:40+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/Eulerian_Trail_Directed.test.cpp
  - tests/Eulerian_Trail_Undirected.test.cpp
documentation_of: graph/EulerWalk.h
layout: document
redirect_from:
- /library/graph/EulerWalk.h
- /library/graph/EulerWalk.h.html
title: graph/EulerWalk.h
---
