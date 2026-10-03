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
  bundledCode: "#line 1 \"graph/CentroidDecomposition.h\"\nvoid dfs_len(int u, int\
    \ p) {\n  sub_len[u] = 1;\n  for (int v : adj[u]) {\n    if (v != p && !removed[v])\
    \ {\n      dfs_len(v, u);\n      sub_len[u] += sub_len[v];\n    }\n  }\n}\n\n\
    int find_centroid(int u, int p, int total) {\n  for (int v : adj[u]) {\n    if\
    \ (v != p && !removed[v] && sub_len[v] > total / 2) {\n      return find_centroid(v,\
    \ u, total);\n    }\n  }\n  return u;\n}\n\nvoid decompose(int u, int p) {\n \
    \ dfs_len(u, -1);\n  int centroid = find_centroid(u, -1, sub_len[u]);\n\n  par_centroid[centroid]\
    \ = p;\n  removed[centroid] = true;\n\n  for (int v : adj[centroid]) {\n    if\
    \ (!removed[v]) {\n      decompose(v, centroid);\n    }\n  }\n}\n"
  code: "void dfs_len(int u, int p) {\n  sub_len[u] = 1;\n  for (int v : adj[u]) {\n\
    \    if (v != p && !removed[v]) {\n      dfs_len(v, u);\n      sub_len[u] += sub_len[v];\n\
    \    }\n  }\n}\n\nint find_centroid(int u, int p, int total) {\n  for (int v :\
    \ adj[u]) {\n    if (v != p && !removed[v] && sub_len[v] > total / 2) {\n    \
    \  return find_centroid(v, u, total);\n    }\n  }\n  return u;\n}\n\nvoid decompose(int\
    \ u, int p) {\n  dfs_len(u, -1);\n  int centroid = find_centroid(u, -1, sub_len[u]);\n\
    \n  par_centroid[centroid] = p;\n  removed[centroid] = true;\n\n  for (int v :\
    \ adj[centroid]) {\n    if (!removed[v]) {\n      decompose(v, centroid);\n  \
    \  }\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/CentroidDecomposition.h
  requiredBy: []
  timestamp: '2026-10-03 15:27:40+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/CentroidDecomposition.h
layout: document
redirect_from:
- /library/graph/CentroidDecomposition.h
- /library/graph/CentroidDecomposition.h.html
title: graph/CentroidDecomposition.h
---
