---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: tests/Point_Set_Range_Composite_Large.test.cpp
    title: tests/Point_Set_Range_Composite_Large.test.cpp
  _isVerificationFailed: true
  _pathExtension: h
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://cses.fi/problemset/task/1737/
  bundledCode: "#line 1 \"ds/PersistentSegTree.h\"\n/*\n  Persistent + Dynamic Segment\
    \ Tree that supports Monoid operation.\n  Tested on https://cses.fi/problemset/task/1737/\n\
    */\n\ntemplate <class T, class F>\nstruct PST {\n  struct Node {\n    T v;\n \
    \   Node *l = nullptr, *r = nullptr;\n    Node(T v) : v(v) {}\n  };\n  int n;\n\
    \  const F f;\n  const T I;\n  PST(int n, F f, const T& I) : n(n), f(f), I(I)\
    \ {}\n  T get_val(Node* u) const { return u ? u->v : I; }\n\n  Node* apply(Node*\
    \ prev, int L, int R, int pos, const T& nv) {\n    Node* u = new Node(prev ? prev->v\
    \ : I);\n    if (prev) u->l = prev->l, u->r = prev->r;\n    if (L == R) {\n  \
    \    u->v = nv;\n      return u;\n    }\n    int M = (L + R) >> 1;\n    if (pos\
    \ <= M) {\n      u->l = apply(u->l, L, M, pos, nv);\n    } else {\n      u->r\
    \ = apply(u->r, M + 1, R, pos, nv);\n    }\n    u->v = f(get_val(u->l), get_val(u->r));\n\
    \    return u;\n  }\n  // [ql, qr] inclusive\n  T query(Node* u, int L, int R,\
    \ int ql, int qr) const {\n    if (!u || qr < L || R < ql) return I;\n    if (ql\
    \ <= L && R <= qr) return u->v;\n    int M = (L + R) >> 1;\n    return f(query(u->l,\
    \ L, M, ql, qr), query(u->r, M + 1, R, ql, qr));\n  }\n};\n"
  code: "/*\n  Persistent + Dynamic Segment Tree that supports Monoid operation.\n\
    \  Tested on https://cses.fi/problemset/task/1737/\n*/\n\ntemplate <class T, class\
    \ F>\nstruct PST {\n  struct Node {\n    T v;\n    Node *l = nullptr, *r = nullptr;\n\
    \    Node(T v) : v(v) {}\n  };\n  int n;\n  const F f;\n  const T I;\n  PST(int\
    \ n, F f, const T& I) : n(n), f(f), I(I) {}\n  T get_val(Node* u) const { return\
    \ u ? u->v : I; }\n\n  Node* apply(Node* prev, int L, int R, int pos, const T&\
    \ nv) {\n    Node* u = new Node(prev ? prev->v : I);\n    if (prev) u->l = prev->l,\
    \ u->r = prev->r;\n    if (L == R) {\n      u->v = nv;\n      return u;\n    }\n\
    \    int M = (L + R) >> 1;\n    if (pos <= M) {\n      u->l = apply(u->l, L, M,\
    \ pos, nv);\n    } else {\n      u->r = apply(u->r, M + 1, R, pos, nv);\n    }\n\
    \    u->v = f(get_val(u->l), get_val(u->r));\n    return u;\n  }\n  // [ql, qr]\
    \ inclusive\n  T query(Node* u, int L, int R, int ql, int qr) const {\n    if\
    \ (!u || qr < L || R < ql) return I;\n    if (ql <= L && R <= qr) return u->v;\n\
    \    int M = (L + R) >> 1;\n    return f(query(u->l, L, M, ql, qr), query(u->r,\
    \ M + 1, R, ql, qr));\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/PersistentSegTree.h
  requiredBy: []
  timestamp: '2025-11-19 14:43:55+07:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - tests/Point_Set_Range_Composite_Large.test.cpp
documentation_of: ds/PersistentSegTree.h
layout: document
redirect_from:
- /library/ds/PersistentSegTree.h
- /library/ds/PersistentSegTree.h.html
title: ds/PersistentSegTree.h
---
