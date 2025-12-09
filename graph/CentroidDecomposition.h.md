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
  bundledCode: "#line 1 \"graph/CentroidDecomposition.h\"\nvoid dfs_sz(int u, int\
    \ p) {\n    sub_sz[u] = 1;\n    for (int v : adj[u]) {\n        if (v != p &&\
    \ !removed[v]) {\n            dfs_sz(v, u);\n            sub_sz[u] += sub_sz[v];\n\
    \        }\n    }\n}\n \nint find_centroid(int u, int p, int total) {\n    for\
    \ (int v : adj[u]) {\n        if (v != p && !removed[v] && sub_sz[v] > total /\
    \ 2) {\n            return find_centroid(v, u, total);\n        }\n    }\n   \
    \ return u;\n}\n \nvoid decompose(int u, int p) {\n    dfs_sz(u, -1);\n    int\
    \ centroid = find_centroid(u, -1, sub_sz[u]);\n    \n    par_centroid[centroid]\
    \ = p;\n    removed[centroid] = true;\n    \n    for (int v : adj[centroid]) {\n\
    \        if (!removed[v]) {\n            decompose(v, centroid);\n        }\n\
    \    }\n}\n"
  code: "void dfs_sz(int u, int p) {\n    sub_sz[u] = 1;\n    for (int v : adj[u])\
    \ {\n        if (v != p && !removed[v]) {\n            dfs_sz(v, u);\n       \
    \     sub_sz[u] += sub_sz[v];\n        }\n    }\n}\n \nint find_centroid(int u,\
    \ int p, int total) {\n    for (int v : adj[u]) {\n        if (v != p && !removed[v]\
    \ && sub_sz[v] > total / 2) {\n            return find_centroid(v, u, total);\n\
    \        }\n    }\n    return u;\n}\n \nvoid decompose(int u, int p) {\n    dfs_sz(u,\
    \ -1);\n    int centroid = find_centroid(u, -1, sub_sz[u]);\n    \n    par_centroid[centroid]\
    \ = p;\n    removed[centroid] = true;\n    \n    for (int v : adj[centroid]) {\n\
    \        if (!removed[v]) {\n            decompose(v, centroid);\n        }\n\
    \    }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/CentroidDecomposition.h
  requiredBy: []
  timestamp: '2025-12-09 07:33:19+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/CentroidDecomposition.h
layout: document
redirect_from:
- /library/graph/CentroidDecomposition.h
- /library/graph/CentroidDecomposition.h.html
title: graph/CentroidDecomposition.h
---
