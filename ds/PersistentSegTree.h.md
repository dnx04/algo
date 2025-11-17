---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://cses.fi/problemset/task/1737/
  bundledCode: "#line 1 \"ds/PersistentSegTree.h\"\n/*\n  Persistent Segment Tree\
    \ that supports Monoid operation.\n  Tested on https://cses.fi/problemset/task/1737/\n\
    \n  Usage:\n  - monoids = {f, id}, here f = u + v and id = 0:\n\n  PST pst((n\
    \ + q) * log(n) * 2, f, 0ll);\n  vector<PST<ll, decltype(f)>*> roots;\n  roots.reserve(q\
    \ + 1);\n  roots.push_back(pst.build(0, n - 1, a));\n*/\n\n\ntemplate <class T,\
    \ class F>\nstruct PST {\n  T v;\n  int n;\n  const F f;\n  const T I;\n  PST\
    \ *l = nullptr, *r = nullptr;\n  PST(int n, F f, const T& I) : n(n), f(f), I(I)\
    \ {}\n  PST* build(int L, int R, const vector<T>& a) {\n    PST* u = new PST(n,\
    \ f, I);\n    if (L == R) {\n      u->v = a[L];\n    } else {\n      int M = (L\
    \ + R) >> 1;\n      u->l = build(L, M, a);\n      u->r = build(M + 1, R, a);\n\
    \      u->v = f(u->l->v, u->r->v);\n    }\n    return u;\n  }\n\n  PST* update(PST*\
    \ prev, int L, int R, int pos, const T& nv) {\n    PST* u = new PST(*prev);\n\
    \    if (L == R) {\n      u->v = nv;\n    } else {\n      int M = (L + R) >> 1;\n\
    \      if (pos <= M)\n        u->l = update(prev->l, L, M, pos, nv);\n      else\n\
    \        u->r = update(prev->r, M + 1, R, pos, nv);\n      u->v = f(u->l->v, u->r->v);\n\
    \    }\n    return u;\n  }\n\n  T query(PST* u, int L, int R, int ql, int qr)\
    \ const {\n    if (!u || qr < L || R < ql) return I;\n    if (ql <= L && R <=\
    \ qr) return u->v;\n    int M = (L + R) >> 1;\n    return f(query(u->l, L, M,\
    \ ql, qr), query(u->r, M + 1, R, ql, qr));\n  }\n};\n"
  code: "/*\n  Persistent Segment Tree that supports Monoid operation.\n  Tested on\
    \ https://cses.fi/problemset/task/1737/\n\n  Usage:\n  - monoids = {f, id}, here\
    \ f = u + v and id = 0:\n\n  PST pst((n + q) * log(n) * 2, f, 0ll);\n  vector<PST<ll,\
    \ decltype(f)>*> roots;\n  roots.reserve(q + 1);\n  roots.push_back(pst.build(0,\
    \ n - 1, a));\n*/\n\n\ntemplate <class T, class F>\nstruct PST {\n  T v;\n  int\
    \ n;\n  const F f;\n  const T I;\n  PST *l = nullptr, *r = nullptr;\n  PST(int\
    \ n, F f, const T& I) : n(n), f(f), I(I) {}\n  PST* build(int L, int R, const\
    \ vector<T>& a) {\n    PST* u = new PST(n, f, I);\n    if (L == R) {\n      u->v\
    \ = a[L];\n    } else {\n      int M = (L + R) >> 1;\n      u->l = build(L, M,\
    \ a);\n      u->r = build(M + 1, R, a);\n      u->v = f(u->l->v, u->r->v);\n \
    \   }\n    return u;\n  }\n\n  PST* update(PST* prev, int L, int R, int pos, const\
    \ T& nv) {\n    PST* u = new PST(*prev);\n    if (L == R) {\n      u->v = nv;\n\
    \    } else {\n      int M = (L + R) >> 1;\n      if (pos <= M)\n        u->l\
    \ = update(prev->l, L, M, pos, nv);\n      else\n        u->r = update(prev->r,\
    \ M + 1, R, pos, nv);\n      u->v = f(u->l->v, u->r->v);\n    }\n    return u;\n\
    \  }\n\n  T query(PST* u, int L, int R, int ql, int qr) const {\n    if (!u ||\
    \ qr < L || R < ql) return I;\n    if (ql <= L && R <= qr) return u->v;\n    int\
    \ M = (L + R) >> 1;\n    return f(query(u->l, L, M, ql, qr), query(u->r, M + 1,\
    \ R, ql, qr));\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/PersistentSegTree.h
  requiredBy: []
  timestamp: '2025-11-16 01:14:31+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/PersistentSegTree.h
layout: document
redirect_from:
- /library/ds/PersistentSegTree.h
- /library/ds/PersistentSegTree.h.html
title: ds/PersistentSegTree.h
---
