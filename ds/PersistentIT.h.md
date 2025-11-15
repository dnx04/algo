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
  bundledCode: "#line 1 \"ds/PersistentIT.h\"\nstruct PST {\n  struct Node {\n   \
    \ ll v;\n    Node *l, *r;\n    Node(ll v = 0, Node* l = nullptr, Node* r = nullptr)\
    \ : v(v), l(l), r(r) {}\n  };\n  int n;\n  PST(int _n) : n(n) {}\n  Node* build(int\
    \ L, int R, vector<ll>& a) {\n    Node* u = new Node();\n    if (L == R) {\n \
    \     u->v = a[L];\n    } else {\n      int M = (L + R) >> 1;\n      u->l = build(L,\
    \ M, a);\n      u->r = build(M + 1, R, a);\n      u->v = u->l->v + u->r->v;\n\
    \    }\n    return u;\n  }\n  Node* update(Node* prev, int L, int R, int pos,\
    \ ll nv) {\n    Node* u = new Node(*prev);\n    if (L == R) {\n      u->v = nv;\n\
    \    } else {\n      int M = (L + R) >> 1;\n      if (pos <= M) {\n        u->l\
    \ = update(prev->l, L, M, pos, nv);\n      } else {\n        u->r = update(prev->r,\
    \ M + 1, R, pos, nv);\n      }\n      u->v = u->l->v + u->r->v;\n    }\n    return\
    \ u;\n  }\n  ll query(Node* u, int L, int R, int ql, int qr) {\n    if (!u ||\
    \ qr < L || R < ql) return 0;\n    if (ql <= L && R <= qr) return u->v;\n    int\
    \ M = (L + R) >> 1;\n    return query(u->l, L, M, ql, qr) + query(u->r, M + 1,\
    \ R, ql, qr);\n  }\n};\n"
  code: "struct PST {\n  struct Node {\n    ll v;\n    Node *l, *r;\n    Node(ll v\
    \ = 0, Node* l = nullptr, Node* r = nullptr) : v(v), l(l), r(r) {}\n  };\n  int\
    \ n;\n  PST(int _n) : n(n) {}\n  Node* build(int L, int R, vector<ll>& a) {\n\
    \    Node* u = new Node();\n    if (L == R) {\n      u->v = a[L];\n    } else\
    \ {\n      int M = (L + R) >> 1;\n      u->l = build(L, M, a);\n      u->r = build(M\
    \ + 1, R, a);\n      u->v = u->l->v + u->r->v;\n    }\n    return u;\n  }\n  Node*\
    \ update(Node* prev, int L, int R, int pos, ll nv) {\n    Node* u = new Node(*prev);\n\
    \    if (L == R) {\n      u->v = nv;\n    } else {\n      int M = (L + R) >> 1;\n\
    \      if (pos <= M) {\n        u->l = update(prev->l, L, M, pos, nv);\n     \
    \ } else {\n        u->r = update(prev->r, M + 1, R, pos, nv);\n      }\n    \
    \  u->v = u->l->v + u->r->v;\n    }\n    return u;\n  }\n  ll query(Node* u, int\
    \ L, int R, int ql, int qr) {\n    if (!u || qr < L || R < ql) return 0;\n   \
    \ if (ql <= L && R <= qr) return u->v;\n    int M = (L + R) >> 1;\n    return\
    \ query(u->l, L, M, ql, qr) + query(u->r, M + 1, R, ql, qr);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/PersistentIT.h
  requiredBy: []
  timestamp: '2025-11-15 18:26:28+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/PersistentIT.h
layout: document
redirect_from:
- /library/ds/PersistentIT.h
- /library/ds/PersistentIT.h.html
title: ds/PersistentIT.h
---
