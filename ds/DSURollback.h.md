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
  bundledCode: "#line 1 \"ds/DSURollback.h\"\nstruct DSURollback {\n  // Stores the\
    \ number of disjoint trees.\n  int n;\n  // If p[i] < 0, i is a root node with\
    \ a tree size of -p[i].\n  // Otherwise, p[i] represents the parent of i.\n  vector<int>\
    \ p;\n  vector<pair<int *, int>> changes;\n  DSURollback(int n) : n(n), p(n, -1)\
    \ {}\n  int root(int s) {\n    while (p[s] >= 0) s = p[s];\n    return s;\n  }\n\
    \  void merge(int a, int b) {\n    a = root(a);\n    b = root(b);\n    if (a ==\
    \ b) return;\n    if (p[a] < p[b]) swap(a, b);\n    changes.emplace_back(&p[a],\
    \ p[a]);\n    changes.emplace_back(&p[b], p[b]);\n    changes.emplace_back(&n,\
    \ n);\n    n--;\n    p[b] += p[a];\n    p[a] = b;\n  }\n  void undo(int cnt) {\n\
    \    while (cnt--) {\n      auto [a, b] = changes.back();\n      changes.pop_back();\n\
    \      *a = b;\n    }\n  }\n};\n"
  code: "struct DSURollback {\n  // Stores the number of disjoint trees.\n  int n;\n\
    \  // If p[i] < 0, i is a root node with a tree size of -p[i].\n  // Otherwise,\
    \ p[i] represents the parent of i.\n  vector<int> p;\n  vector<pair<int *, int>>\
    \ changes;\n  DSURollback(int n) : n(n), p(n, -1) {}\n  int root(int s) {\n  \
    \  while (p[s] >= 0) s = p[s];\n    return s;\n  }\n  void merge(int a, int b)\
    \ {\n    a = root(a);\n    b = root(b);\n    if (a == b) return;\n    if (p[a]\
    \ < p[b]) swap(a, b);\n    changes.emplace_back(&p[a], p[a]);\n    changes.emplace_back(&p[b],\
    \ p[b]);\n    changes.emplace_back(&n, n);\n    n--;\n    p[b] += p[a];\n    p[a]\
    \ = b;\n  }\n  void undo(int cnt) {\n    while (cnt--) {\n      auto [a, b] =\
    \ changes.back();\n      changes.pop_back();\n      *a = b;\n    }\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/DSURollback.h
  requiredBy: []
  timestamp: '2025-11-15 18:26:28+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/DSURollback.h
layout: document
redirect_from:
- /library/ds/DSURollback.h
- /library/ds/DSURollback.h.html
title: ds/DSURollback.h
---
