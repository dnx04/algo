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
  bundledCode: "#line 1 \"graph/Biconnected.h\"\n/**\n * Usage:\n *  int eid = 0;\
    \ ed.resize(N);\n *  for each edge (a,b) {\n *    ed[a].emplace_back(b, eid);\n\
    \ *    ed[b].emplace_back(a, eid++); }\n *  bicomps([\\&](const vi\\& edgelist)\
    \ {...});\n */\n\nvi num, st;\nvector<vector<pii>> ed;\nint Time;\ntemplate <class\
    \ F>\nint dfs(int at, int par, F& f) {\n  int me = num[at] = ++Time, top = me;\n\
    \  for (auto [y, e] : ed[at])\n    if (e != par) {\n      if (num[y]) {\n    \
    \    top = min(top, num[y]);\n        if (num[y] < me) st.push_back(e);\n    \
    \  } else {\n        int si = sz(st);\n        int up = dfs(y, e, f);\n      \
    \  top = min(top, up);\n        if (up == me) {\n          st.push_back(e);\n\
    \          f(vi(st.begin() + si, st.end()));\n          st.resize(si);\n     \
    \   } else if (up < me)\n          st.push_back(e);\n        else { /* e is a\
    \ bridge */\n        }\n      }\n    }\n  return top;\n}\n\ntemplate <class F>\n\
    void bicomps(F f) {\n  num.assign(sz(ed), 0);\n  for (int i = 0; i < sz(ed); ++i)\n\
    \    if (!num[i]) dfs(i, -1, f);\n}\n"
  code: "/**\n * Usage:\n *  int eid = 0; ed.resize(N);\n *  for each edge (a,b) {\n\
    \ *    ed[a].emplace_back(b, eid);\n *    ed[b].emplace_back(a, eid++); }\n *\
    \  bicomps([\\&](const vi\\& edgelist) {...});\n */\n\nvi num, st;\nvector<vector<pii>>\
    \ ed;\nint Time;\ntemplate <class F>\nint dfs(int at, int par, F& f) {\n  int\
    \ me = num[at] = ++Time, top = me;\n  for (auto [y, e] : ed[at])\n    if (e !=\
    \ par) {\n      if (num[y]) {\n        top = min(top, num[y]);\n        if (num[y]\
    \ < me) st.push_back(e);\n      } else {\n        int si = sz(st);\n        int\
    \ up = dfs(y, e, f);\n        top = min(top, up);\n        if (up == me) {\n \
    \         st.push_back(e);\n          f(vi(st.begin() + si, st.end()));\n    \
    \      st.resize(si);\n        } else if (up < me)\n          st.push_back(e);\n\
    \        else { /* e is a bridge */\n        }\n      }\n    }\n  return top;\n\
    }\n\ntemplate <class F>\nvoid bicomps(F f) {\n  num.assign(sz(ed), 0);\n  for\
    \ (int i = 0; i < sz(ed); ++i)\n    if (!num[i]) dfs(i, -1, f);\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/Biconnected.h
  requiredBy: []
  timestamp: '2025-11-15 18:26:28+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/Biconnected.h
layout: document
redirect_from:
- /library/graph/Biconnected.h
- /library/graph/Biconnected.h.html
title: graph/Biconnected.h
---
