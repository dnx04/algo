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
  bundledCode: "#line 1 \"ds/DSURollback.h\"\nstruct DSURollback {\n  int n;\n  vector<int>\
    \ p;\n  vector<pair<int*, int>> his;\n  DSURollback(int n) : n(n), p(n, -1) {}\n\
    \  int root(int s) {\n    while (p[s] >= 0) s = p[s];\n    return s;\n  }\n  void\
    \ merge(int a, int b) {\n    a = root(a);\n    b = root(b);\n    if (a == b) return;\n\
    \    if (p[a] < p[b]) swap(a, b);\n    his.eb(&p[a], p[a]), his.eb(&p[b], p[b]),\
    \ his.eb(&n, n);\n    n--, p[b] += p[a], p[a] = b;\n  }\n  void undo(int cnt)\
    \ {\n    while (cnt--) {\n      auto [a, b] = his.back();\n      his.pop_back();\n\
    \      *a = b;\n    }\n  }\n};\n"
  code: "struct DSURollback {\n  int n;\n  vector<int> p;\n  vector<pair<int*, int>>\
    \ his;\n  DSURollback(int n) : n(n), p(n, -1) {}\n  int root(int s) {\n    while\
    \ (p[s] >= 0) s = p[s];\n    return s;\n  }\n  void merge(int a, int b) {\n  \
    \  a = root(a);\n    b = root(b);\n    if (a == b) return;\n    if (p[a] < p[b])\
    \ swap(a, b);\n    his.eb(&p[a], p[a]), his.eb(&p[b], p[b]), his.eb(&n, n);\n\
    \    n--, p[b] += p[a], p[a] = b;\n  }\n  void undo(int cnt) {\n    while (cnt--)\
    \ {\n      auto [a, b] = his.back();\n      his.pop_back();\n      *a = b;\n \
    \   }\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/DSURollback.h
  requiredBy: []
  timestamp: '2025-11-20 10:20:22+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/DSURollback.h
layout: document
redirect_from:
- /library/ds/DSURollback.h
- /library/ds/DSURollback.h.html
title: ds/DSURollback.h
---
