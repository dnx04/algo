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
  bundledCode: "#line 1 \"ds/Treap.h\"\nstruct Node {\n  Node *l = 0, *r = 0;\n  int\
    \ val, y, c = 1;\n  Node(int val) : val(val), y(rand()) {}\n  void recalc();\n\
    };\n\nint cnt(Node* n) { return n ? n->c : 0; }\nvoid Node::recalc() { c = cnt(l)\
    \ + cnt(r) + 1; }\n\ntemplate <class F>\nvoid each(Node* n, F f) {\n  if (n) {\n\
    \    each(n->l, f);\n    f(n->val);\n    each(n->r, f);\n  }\n}\n\npair<Node*,\
    \ Node*> split(Node* n, int k) {\n  if (!n) return {};\n  if (cnt(n->l) >= k)\
    \ {  // \"n->val >= k\" for lower_bound(k)\n    auto [L, R] = split(n->l, k);\n\
    \    n->l = R;\n    n->recalc();\n    return {L, n};\n  } else {\n    auto [L,\
    \ R] = split(n->r, k - cnt(n->l) - 1);  // and just \"k\"\n    n->r = L;\n   \
    \ n->recalc();\n    return {n, R};\n  }\n}\n\nNode* merge(Node* l, Node* r) {\n\
    \  if (!l) return r;\n  if (!r) return l;\n  if (l->y > r->y) {\n    l->r = merge(l->r,\
    \ r);\n    return l->recalc(), l;\n  } else {\n    r->l = merge(l, r->l);\n  \
    \  return r->recalc(), r;\n  }\n}\n\nNode* ins(Node* t, Node* n, int pos) {\n\
    \  auto [l, r] = split(t, pos);\n  return merge(merge(l, n), r);\n}\n\n// Example\
    \ application: move the range [l, r) to index k\nvoid move(Node*& t, int l, int\
    \ r, int k) {\n  Node *a, *b, *c;\n  tie(a, b) = split(t, l);\n  tie(b, c) = split(b,\
    \ r - l);\n  if (k <= l)\n    t = merge(ins(a, b, k), c);\n  else\n    t = merge(a,\
    \ ins(c, b, k - r));\n}\n"
  code: "struct Node {\n  Node *l = 0, *r = 0;\n  int val, y, c = 1;\n  Node(int val)\
    \ : val(val), y(rand()) {}\n  void recalc();\n};\n\nint cnt(Node* n) { return\
    \ n ? n->c : 0; }\nvoid Node::recalc() { c = cnt(l) + cnt(r) + 1; }\n\ntemplate\
    \ <class F>\nvoid each(Node* n, F f) {\n  if (n) {\n    each(n->l, f);\n    f(n->val);\n\
    \    each(n->r, f);\n  }\n}\n\npair<Node*, Node*> split(Node* n, int k) {\n  if\
    \ (!n) return {};\n  if (cnt(n->l) >= k) {  // \"n->val >= k\" for lower_bound(k)\n\
    \    auto [L, R] = split(n->l, k);\n    n->l = R;\n    n->recalc();\n    return\
    \ {L, n};\n  } else {\n    auto [L, R] = split(n->r, k - cnt(n->l) - 1);  // and\
    \ just \"k\"\n    n->r = L;\n    n->recalc();\n    return {n, R};\n  }\n}\n\n\
    Node* merge(Node* l, Node* r) {\n  if (!l) return r;\n  if (!r) return l;\n  if\
    \ (l->y > r->y) {\n    l->r = merge(l->r, r);\n    return l->recalc(), l;\n  }\
    \ else {\n    r->l = merge(l, r->l);\n    return r->recalc(), r;\n  }\n}\n\nNode*\
    \ ins(Node* t, Node* n, int pos) {\n  auto [l, r] = split(t, pos);\n  return merge(merge(l,\
    \ n), r);\n}\n\n// Example application: move the range [l, r) to index k\nvoid\
    \ move(Node*& t, int l, int r, int k) {\n  Node *a, *b, *c;\n  tie(a, b) = split(t,\
    \ l);\n  tie(b, c) = split(b, r - l);\n  if (k <= l)\n    t = merge(ins(a, b,\
    \ k), c);\n  else\n    t = merge(a, ins(c, b, k - r));\n}"
  dependsOn: []
  isVerificationFile: false
  path: ds/Treap.h
  requiredBy: []
  timestamp: '2025-11-15 18:26:28+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/Treap.h
layout: document
redirect_from:
- /library/ds/Treap.h
- /library/ds/Treap.h.html
title: ds/Treap.h
---
