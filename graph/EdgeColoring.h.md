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
  bundledCode: "#line 1 \"graph/EdgeColoring.h\"\nvi edgeColoring(int N, vector<pii>\
    \ eds) {\n  vi cc(N + 1), ret(sz(eds)), fan(N), free(N), loc;\n  for (pii e :\
    \ eds) ++cc[e.first], ++cc[e.second];\n  int u, v, ncols = *max_element(all(cc))\
    \ + 1;\n  vector<vi> adj(N, vi(ncols, -1));\n  for (pii e : eds) {\n    tie(u,\
    \ v) = e;\n    fan[0] = v;\n    loc.assign(ncols, 0);\n    int at = u, end = u,\
    \ d, c = free[u], ind = 0, i = 0;\n    while (d = free[v], !loc[d] && (v = adj[u][d])\
    \ != -1)\n      loc[d] = ++ind, cc[ind] = d, fan[ind] = v;\n    cc[loc[d]] = c;\n\
    \    for (int cd = d; at != -1; cd ^= c ^ d, at = adj[at][cd])\n      swap(adj[at][cd],\
    \ adj[end = at][cd ^ c ^ d]);\n    while (adj[fan[i]][d] != -1) {\n      int left\
    \ = fan[i], right = fan[++i], e = cc[i];\n      adj[u][e] = left;\n      adj[left][e]\
    \ = u;\n      adj[right][e] = -1;\n      free[right] = e;\n    }\n    adj[u][d]\
    \ = fan[i];\n    adj[fan[i]][d] = u;\n    for (int y : {fan[0], u, end})\n   \
    \   for (int& z = free[y] = 0; adj[y][z] != -1; z++);\n  }\n  for (int i = 0;\
    \ i < sz(eds); ++i)\n    for (tie(u, v) = eds[i]; adj[u][ret[i]] != v;) ++ret[i];\n\
    \  return ret;\n}\n"
  code: "vi edgeColoring(int N, vector<pii> eds) {\n  vi cc(N + 1), ret(sz(eds)),\
    \ fan(N), free(N), loc;\n  for (pii e : eds) ++cc[e.first], ++cc[e.second];\n\
    \  int u, v, ncols = *max_element(all(cc)) + 1;\n  vector<vi> adj(N, vi(ncols,\
    \ -1));\n  for (pii e : eds) {\n    tie(u, v) = e;\n    fan[0] = v;\n    loc.assign(ncols,\
    \ 0);\n    int at = u, end = u, d, c = free[u], ind = 0, i = 0;\n    while (d\
    \ = free[v], !loc[d] && (v = adj[u][d]) != -1)\n      loc[d] = ++ind, cc[ind]\
    \ = d, fan[ind] = v;\n    cc[loc[d]] = c;\n    for (int cd = d; at != -1; cd ^=\
    \ c ^ d, at = adj[at][cd])\n      swap(adj[at][cd], adj[end = at][cd ^ c ^ d]);\n\
    \    while (adj[fan[i]][d] != -1) {\n      int left = fan[i], right = fan[++i],\
    \ e = cc[i];\n      adj[u][e] = left;\n      adj[left][e] = u;\n      adj[right][e]\
    \ = -1;\n      free[right] = e;\n    }\n    adj[u][d] = fan[i];\n    adj[fan[i]][d]\
    \ = u;\n    for (int y : {fan[0], u, end})\n      for (int& z = free[y] = 0; adj[y][z]\
    \ != -1; z++);\n  }\n  for (int i = 0; i < sz(eds); ++i)\n    for (tie(u, v) =\
    \ eds[i]; adj[u][ret[i]] != v;) ++ret[i];\n  return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/EdgeColoring.h
  requiredBy: []
  timestamp: '2025-11-15 18:26:28+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/EdgeColoring.h
layout: document
redirect_from:
- /library/graph/EdgeColoring.h
- /library/graph/EdgeColoring.h.html
title: graph/EdgeColoring.h
---
