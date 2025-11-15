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
  bundledCode: "#line 1 \"ds/DSU.h\"\nstruct DSU {\n public:\n  DSU(int _n) : n(_n),\
    \ p(_n, -1) {}\n\n  int merge(int a, int b) {\n    int x = head(a), y = head(b);\n\
    \    if (x == y) return x;\n    if (-p[x] < -p[y]) swap(x, y);\n    p[x] += p[y];\n\
    \    p[y] = x;\n    return x;\n  }\n\n  bool same(int a, int b) { return head(a)\
    \ == head(b); }\n\n  int head(int a) {\n    if (p[a] < 0) return a;\n    return\
    \ p[a] = head(p[a]);\n  }\n\n  int size(int a) { return -p[head(a)]; }\n\n private:\n\
    \  int n;\n  vector<int> p;\n};\n"
  code: "struct DSU {\n public:\n  DSU(int _n) : n(_n), p(_n, -1) {}\n\n  int merge(int\
    \ a, int b) {\n    int x = head(a), y = head(b);\n    if (x == y) return x;\n\
    \    if (-p[x] < -p[y]) swap(x, y);\n    p[x] += p[y];\n    p[y] = x;\n    return\
    \ x;\n  }\n\n  bool same(int a, int b) { return head(a) == head(b); }\n\n  int\
    \ head(int a) {\n    if (p[a] < 0) return a;\n    return p[a] = head(p[a]);\n\
    \  }\n\n  int size(int a) { return -p[head(a)]; }\n\n private:\n  int n;\n  vector<int>\
    \ p;\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/DSU.h
  requiredBy: []
  timestamp: '2025-11-15 18:26:28+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/DSU.h
layout: document
redirect_from:
- /library/ds/DSU.h
- /library/ds/DSU.h.html
title: ds/DSU.h
---
