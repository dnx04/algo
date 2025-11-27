---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/Fenwick.h
    title: ds/Fenwick.h
  - icon: ':x:'
    path: ds/HLD.h
    title: ds/HLD.h
  - icon: ':question:'
    path: misc/macros.h
    title: misc/macros.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_path_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_path_sum
  bundledCode: "#line 1 \"tests/Vertex_Add_Path_Sum.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\n#line 1 \"misc/macros.h\"\
    \n// #pragma GCC optimize(\"Ofast,unroll-loops\")       // unroll long, simple\
    \ loops\n// #pragma GCC target(\"avx2,fma\")                   // vectorizing\
    \ code\n// #pragma GCC target(\"lzcnt,popcnt,abm,bmi,bmi2\")  // for fast bitset\
    \ operation\n\n#include <bits/extc++.h>\n\n#include <tr2/dynamic_bitset>\n\nusing\
    \ namespace std;\nusing namespace __gnu_pbds;  // ordered_set, gp_hash_table\n\
    // using namespace __gnu_cxx;\n\n// for templates to work\n#define all(s) s.begin(),\
    \ s.end()\n#define sz(x) (int) (x).size()\n#define pb push_back\n#define eb emplace_back\n\
    using i32 = int32_t;\nusing u32 = uint32_t;\nusing i64 = int64_t;\nusing u64 =\
    \ uint64_t;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\nusing ld = long\
    \ double;\nusing pii = pair<i32, i32>;\nusing vi = vector<i32>;\n\n// fast map\n\
    const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();\n\
    struct chash {  // customize hash function for gp_hash_table\n  int operator()(int\
    \ x) const { return x ^ RANDOM; }\n};\ngp_hash_table<int, int, chash> table;\n\
    \n/* ordered set\n    find_by_order(k): returns an iterator to the k-th element\
    \ (0-based)\n    order_of_key(k): returns the number of elements in the set that\
    \ are strictly less than k\n*/\ntemplate <class T>\nusing ordered_set = tree<T,\
    \ null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;\n\n// dynamic\
    \ bitset\nusing bs = tr2::dynamic_bitset<u64>;\n\n/*  rope\n    rope <int> cur\
    \ = v.substr(l, r - l + 1);\n    v.erase(l, r - l + 1);\n    v.insert(v.mutable_begin(),\
    \ cur);\n*/\n#line 1 \"ds/Fenwick.h\"\ntemplate <class T>\nstruct Fenwick {  //\
    \ 1-indexed\n  int n;\n  vector<T> t;\n  Fenwick(int n) : n(n), t(n + 1, T(0))\
    \ {}\n  void add(int p, T v) {\n    while (p <= n) t[p] += v, p += (p & -p);\n\
    \  }\n  T sum(int p) {\n    T res = 0;\n    while (p) res += t[p], p -= (p & -p);\n\
    \    return res;\n  }\n  // [l, r)\n  T sum(int l, int r) {\n    if (l > r) return\
    \ T(0);\n    return sum(r) - sum(l - 1);\n  }\n};\n#line 1 \"ds/HLD.h\"\ntemplate\
    \ <class G>\nstruct HLD {\n  const G& g;\n  int n, t = 0;\n  vi sz, dep, par,\
    \ head, pos, heavy;\n  HLD(const G& g, int root = 0) : g(g), n(sz(g)), sz(n),\
    \ dep(n), par(n), head(n), pos(n), heavy(n, -1) {\n    par[root] = -1;\n    dfs_sz(root);\n\
    \    dfs_hld(root, root);\n  }\n  void dfs_sz(int u) {\n    sz[u] = 1;\n    for\
    \ (int v : g[u])\n      if (v != par[u]) {\n        dep[v] = dep[u] + 1, par[v]\
    \ = u;\n        dfs_sz(v);\n        sz[u] += sz[v];\n        if (heavy[u] == -1\
    \ || sz[v] > sz[heavy[u]]) heavy[u] = v;\n      }\n  }\n  void dfs_hld(int u,\
    \ int h) {\n    head[u] = h, pos[u] = ++t;\n    if (heavy[u] != -1) dfs_hld(heavy[u],\
    \ h);\n    for (int v : g[u])\n      if (v != par[u] && v != heavy[u]) dfs_hld(v,\
    \ v);\n  }\n  pii query_subtree(int u) { return {pos[u], pos[u] + sz[u] - 1};\
    \ }\n  // Tr\u1EA3 v\u1EC1 vector c\xE1c \u0111o\u1EA1n [L, R].\n  // L > R: \u0111\
    i l\xEAn (u -> LCA). L <= R: \u0111i xu\u1ED1ng (LCA -> v).\n  vector<pii> query_path(int\
    \ u, int v) {\n    vector<pii> l, r;\n    for (; head[u] != head[v]; u = par[head[u]])\
    \ {\n      if (dep[head[u]] > dep[head[v]]) l.pb({pos[u], pos[head[u]]});\n  \
    \    else r.pb({pos[head[v]], pos[v]}), v = par[head[v]];\n    }\n    if (dep[u]\
    \ > dep[v]) l.pb({pos[u], pos[v]});\n    else r.pb({pos[u], pos[v]});\n    reverse(all(r));\n\
    \    l.insert(l.end(), all(r));\n    return l;\n  }\n\n  int lca(int u, int v)\
    \ {\n    for (; head[u] != head[v]; u = par[head[u]])\n      if (dep[head[u]]\
    \ < dep[head[v]]) swap(u, v);\n    return dep[u] < dep[v] ? u : v;\n  }\n};\n\
    #line 6 \"tests/Vertex_Add_Path_Sum.test.cpp\"\n\nsigned main() {\n  ios::sync_with_stdio(false);\n\
    \  cin.tie(0);\n\n  int n, q;\n  cin >> n >> q;\n  Fenwick<i64> fw(n);\n  vector<i64>\
    \ a(n);\n  vector<vi> g(n);\n  for (int i = 0; i < n; ++i) cin >> a[i];\n  for\
    \ (int i = 0; i < n - 1; ++i) {\n    int u, v;\n    cin >> u >> v;\n    g[u].eb(v),\
    \ g[v].eb(u);\n  }\n  auto hld = HLD(g);\n  for (int i = 0; i < n; ++i) fw.add(hld.idx(i).first\
    \ + 1, a[i]);\n  while (q--) {\n    int cmd;\n    cin >> cmd;\n    if (cmd ==\
    \ 0) {\n      int p, x;\n      cin >> p >> x;\n      fw.add(hld.idx(p).first +\
    \ 1, x);\n    } else {\n      int u, v;\n      cin >> u >> v;\n      i64 res =\
    \ 0;\n      hld.path_query(u, v, true, [&](const int& u, const int& v) {\n   \
    \     res += fw.sum(u + 1, v);\n      });\n      cout << res << '\\n';\n    }\n\
    \  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\
    \n#include \"../misc/macros.h\"\n#include \"../ds/Fenwick.h\"\n#include \"../ds/HLD.h\"\
    \n\nsigned main() {\n  ios::sync_with_stdio(false);\n  cin.tie(0);\n\n  int n,\
    \ q;\n  cin >> n >> q;\n  Fenwick<i64> fw(n);\n  vector<i64> a(n);\n  vector<vi>\
    \ g(n);\n  for (int i = 0; i < n; ++i) cin >> a[i];\n  for (int i = 0; i < n -\
    \ 1; ++i) {\n    int u, v;\n    cin >> u >> v;\n    g[u].eb(v), g[v].eb(u);\n\
    \  }\n  auto hld = HLD(g);\n  for (int i = 0; i < n; ++i) fw.add(hld.idx(i).first\
    \ + 1, a[i]);\n  while (q--) {\n    int cmd;\n    cin >> cmd;\n    if (cmd ==\
    \ 0) {\n      int p, x;\n      cin >> p >> x;\n      fw.add(hld.idx(p).first +\
    \ 1, x);\n    } else {\n      int u, v;\n      cin >> u >> v;\n      i64 res =\
    \ 0;\n      hld.path_query(u, v, true, [&](const int& u, const int& v) {\n   \
    \     res += fw.sum(u + 1, v);\n      });\n      cout << res << '\\n';\n    }\n\
    \  }\n}"
  dependsOn:
  - misc/macros.h
  - ds/Fenwick.h
  - ds/HLD.h
  isVerificationFile: true
  path: tests/Vertex_Add_Path_Sum.test.cpp
  requiredBy: []
  timestamp: '2025-11-27 09:59:02+07:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: tests/Vertex_Add_Path_Sum.test.cpp
layout: document
redirect_from:
- /verify/tests/Vertex_Add_Path_Sum.test.cpp
- /verify/tests/Vertex_Add_Path_Sum.test.cpp.html
title: tests/Vertex_Add_Path_Sum.test.cpp
---
