---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/Directed_MST.test.cpp
    title: tests/Directed_MST.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/DirectedMST.h\"\nstruct DSU {\n  vector<int> link;\n\
    \  DSU(int n) : link(n, -1) {}\n  int Find(int x) { return link[x] == -1 ? x :\
    \ link[x] = Find(link[x]); }\n};\n\nstruct SkewHeap {\n  struct Node { ll key,\
    \ lazy = 0; int l = -1, r = -1; };\n  vector<Node> T;\n\n  void push(int x) {\n\
    \    if (x == -1 || !T[x].lazy) return;\n    for (int y : {T[x].l, T[x].r}) if\
    \ (y != -1) \n      T[y].lazy += T[x].lazy;\n    T[x].key += T[x].lazy, T[x].lazy\
    \ = 0;\n  }\n  // Make new node. Returns its index. Indexes go 0, 1, ...\n  int\
    \ New(ll key) { \n    T.push_back(Node{key}); \n    return (int)T.size() - 1;\n\
    \  }\n  // Increment all values in heap p by v\n  void Add(int x, ll v) { if (~x)\
    \ T[x].lazy += v, push(x); }\n  // Merge heaps a and b\n  int Merge(int a, int\
    \ b) {\n    if (b == -1 || a == -1) return a + b + 1;\n    if (T[a].key > T[b].key)\
    \ swap(a, b);\n    int &l = T[a].l, &r = T[a].r;\n    push(r); swap(l, r); l =\
    \ Merge(l, b);\n    return a;\n  }\n  void Pop(int& x) { x = Merge(T[x].l, T[x].r);\
    \ }\n  ll Get(int x) { return T[x].key; }\n};\n\nstruct Edge { int a, b; ll c;\
    \ }; \n\npair<ll, vector<int>> DMST(int n, int src, vector<Edge> es) {\n  // Compress\
    \ graph - O(M logN)\n  SkewHeap H; DSU D(2 * n); int x = 0;\n  vector<int> par(2\
    \ * n, -1), ins(par), vis(par);\n  for (auto e : es) ins[e.b] = H.Merge(ins[e.b],\
    \ H.New(e.c));\n  auto go = [&](int x) { return D.Find(es[ins[x]].a); };\n  for\
    \ (int i = n; ins[x] != -1; ++i) {\n    for (; vis[x] == -1; x = go(x)) vis[x]\
    \ = 0;\n    for (; x != i; x = go(x)) {\n      int rem = ins[x]; ll w = H.Get(rem);\
    \ H.Pop(rem);\n      H.Add(rem, -w); ins[i] = H.Merge(ins[i], rem);\n      par[x]\
    \ = i; D.link[x] = i;\n    }\n    for (; ins[x] != -1 && go(x) == x; H.Pop(ins[x]));\n\
    \  }\n  // Expand graph - O(N)\n  ll cost = 0; vector<int> ans;\n  for (int i\
    \ = src; i != -1; i = par[i]) vis[i] = 1;\n  for (int i = x; i >= 0; --i) {\n\
    \    if (vis[i]) continue;\n    cost += es[ins[i]].c; ans.push_back(ins[i]);\n\
    \    for (int j = es[ins[i]].b; j != -1 && !vis[j]; j = par[j]) \n      vis[j]\
    \ = 1;\n  }\n  return {cost, ans};\n}\n"
  code: "struct DSU {\n  vector<int> link;\n  DSU(int n) : link(n, -1) {}\n  int Find(int\
    \ x) { return link[x] == -1 ? x : link[x] = Find(link[x]); }\n};\n\nstruct SkewHeap\
    \ {\n  struct Node { ll key, lazy = 0; int l = -1, r = -1; };\n  vector<Node>\
    \ T;\n\n  void push(int x) {\n    if (x == -1 || !T[x].lazy) return;\n    for\
    \ (int y : {T[x].l, T[x].r}) if (y != -1) \n      T[y].lazy += T[x].lazy;\n  \
    \  T[x].key += T[x].lazy, T[x].lazy = 0;\n  }\n  // Make new node. Returns its\
    \ index. Indexes go 0, 1, ...\n  int New(ll key) { \n    T.push_back(Node{key});\
    \ \n    return (int)T.size() - 1;\n  }\n  // Increment all values in heap p by\
    \ v\n  void Add(int x, ll v) { if (~x) T[x].lazy += v, push(x); }\n  // Merge\
    \ heaps a and b\n  int Merge(int a, int b) {\n    if (b == -1 || a == -1) return\
    \ a + b + 1;\n    if (T[a].key > T[b].key) swap(a, b);\n    int &l = T[a].l, &r\
    \ = T[a].r;\n    push(r); swap(l, r); l = Merge(l, b);\n    return a;\n  }\n \
    \ void Pop(int& x) { x = Merge(T[x].l, T[x].r); }\n  ll Get(int x) { return T[x].key;\
    \ }\n};\n\nstruct Edge { int a, b; ll c; }; \n\npair<ll, vector<int>> DMST(int\
    \ n, int src, vector<Edge> es) {\n  // Compress graph - O(M logN)\n  SkewHeap\
    \ H; DSU D(2 * n); int x = 0;\n  vector<int> par(2 * n, -1), ins(par), vis(par);\n\
    \  for (auto e : es) ins[e.b] = H.Merge(ins[e.b], H.New(e.c));\n  auto go = [&](int\
    \ x) { return D.Find(es[ins[x]].a); };\n  for (int i = n; ins[x] != -1; ++i) {\n\
    \    for (; vis[x] == -1; x = go(x)) vis[x] = 0;\n    for (; x != i; x = go(x))\
    \ {\n      int rem = ins[x]; ll w = H.Get(rem); H.Pop(rem);\n      H.Add(rem,\
    \ -w); ins[i] = H.Merge(ins[i], rem);\n      par[x] = i; D.link[x] = i;\n    }\n\
    \    for (; ins[x] != -1 && go(x) == x; H.Pop(ins[x]));\n  }\n  // Expand graph\
    \ - O(N)\n  ll cost = 0; vector<int> ans;\n  for (int i = src; i != -1; i = par[i])\
    \ vis[i] = 1;\n  for (int i = x; i >= 0; --i) {\n    if (vis[i]) continue;\n \
    \   cost += es[ins[i]].c; ans.push_back(ins[i]);\n    for (int j = es[ins[i]].b;\
    \ j != -1 && !vis[j]; j = par[j]) \n      vis[j] = 1;\n  }\n  return {cost, ans};\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: graph/DirectedMST.h
  requiredBy: []
  timestamp: '2025-11-15 18:26:28+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/Directed_MST.test.cpp
documentation_of: graph/DirectedMST.h
layout: document
redirect_from:
- /library/graph/DirectedMST.h
- /library/graph/DirectedMST.h.html
title: graph/DirectedMST.h
---
