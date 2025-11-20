---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/Unionfind.test.cpp
    title: tests/Unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/DSU.h\"\nstruct DSU {\n  int n;\n  vi p;\n  DSU(int n)\
    \ : n(n), p(n, -1) {}\n  int merge(int a, int b) {\n    int x = head(a), y = head(b);\n\
    \    if (x == y) return x;\n    if (-p[x] < -p[y]) swap(x, y);\n    p[x] += p[y],\
    \ p[y] = x;\n    return x;\n  }\n  bool same(int a, int b) { return head(a) ==\
    \ head(b); }\n  int head(int a) {\n    if (p[a] < 0) return a;\n    return p[a]\
    \ = head(p[a]);\n  }\n  int size(int a) { return -p[head(a)]; }\n};\n"
  code: "struct DSU {\n  int n;\n  vi p;\n  DSU(int n) : n(n), p(n, -1) {}\n  int\
    \ merge(int a, int b) {\n    int x = head(a), y = head(b);\n    if (x == y) return\
    \ x;\n    if (-p[x] < -p[y]) swap(x, y);\n    p[x] += p[y], p[y] = x;\n    return\
    \ x;\n  }\n  bool same(int a, int b) { return head(a) == head(b); }\n  int head(int\
    \ a) {\n    if (p[a] < 0) return a;\n    return p[a] = head(p[a]);\n  }\n  int\
    \ size(int a) { return -p[head(a)]; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/DSU.h
  requiredBy: []
  timestamp: '2025-11-18 16:58:39+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/Unionfind.test.cpp
documentation_of: ds/DSU.h
layout: document
redirect_from:
- /library/ds/DSU.h
- /library/ds/DSU.h.html
title: ds/DSU.h
---
