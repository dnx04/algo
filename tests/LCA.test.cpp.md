---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/HLD.h
    title: ds/HLD.h
  - icon: ':heavy_check_mark:'
    path: misc/macros.h
    title: misc/macros.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"tests/LCA.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\
    \n\n#line 1 \"misc/macros.h\"\n// #pragma GCC optimize(\"Ofast,unroll-loops\"\
    )       // unroll long, simple loops\n// #pragma GCC target(\"avx2,fma\")    \
    \               // vectorizing code\n// #pragma GCC target(\"lzcnt,popcnt,abm,bmi,bmi2\"\
    )  // for fast bitset operation\n\n#include <bits/extc++.h>\n#include <tr2/dynamic_bitset>\n\
    \nusing namespace std;\nusing namespace __gnu_pbds;  // ordered_set, gp_hash_table\n\
    // using namespace __gnu_cxx; // rope\n\n// for templates to work\n#define all(x)\
    \ (x).begin(), (x).end()\n#define sz(x) (int) (x).size()\n#define pb push_back\n\
    #define eb emplace_back\nusing i32 = int32_t;\nusing u32 = uint32_t;\nusing i64\
    \ = int64_t;\nusing u64 = uint64_t;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\
    using ld = long double;\nusing pii = pair<i32, i32>;\nusing vi = vector<i32>;\n\
    \n// fast map\nconst int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();\n\
    struct chash {  // customize hash function for gp_hash_table\n  int operator()(int\
    \ x) const { return x ^ RANDOM; }\n};\ngp_hash_table<int, int, chash> table;\n\
    \n/* ordered set\n    find_by_order(k): returns an iterator to the k-th element\
    \ (0-based)\n    order_of_key(k): returns the number of elements in the set that\
    \ are strictly less than k\n*/\ntemplate <class T>\nusing ordered_set = tree<T,\
    \ null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;\n\n/* \
    \ rope\n    rope <int> cur = v.substr(l, r - l + 1);\n    v.erase(l, r - l + 1);\n\
    \    v.insert(v.mutable_begin(), cur);\n*/\n#line 1 \"ds/HLD.h\"\ntemplate <class\
    \ G>\nstruct HLD {\n  const G& g;\n  int n, t = 0;\n  vi sub, dep, par, head,\
    \ pos, heavy;\n  HLD(const G& g, int root = 0) : g(g), n(sz(g)), sub(n), dep(n),\
    \ par(n), head(n), pos(n), heavy(n, -1) {\n    par[root] = -1;\n    dfs_sub(root);\n\
    \    dfs_hld(root, root);\n  }\n  void dfs_sub(int u) {\n    sub[u] = 1;\n   \
    \ for (int v : g[u])\n      if (v != par[u]) {\n        dep[v] = dep[u] + 1, par[v]\
    \ = u;\n        dfs_sub(v);\n        sub[u] += sub[v];\n        if (heavy[u] ==\
    \ -1 || sub[v] > sub[heavy[u]]) heavy[u] = v;\n      }\n  }\n  void dfs_hld(int\
    \ u, int h) {\n    head[u] = h, pos[u] = ++t;\n    if (heavy[u] != -1) dfs_hld(heavy[u],\
    \ h);\n    for (int v : g[u])\n      if (v != par[u] && v != heavy[u]) dfs_hld(v,\
    \ v);\n  }\n  int idx(int u) const { return pos[u]; }\n  pii query_subtree(int\
    \ u) { return {pos[u], pos[u] + sub[u] - 1}; }\n  vector<pii> query_path(int u,\
    \ int v) {\n    vector<pii> l, r;\n    while (head[u] != head[v]) {\n      if\
    \ (dep[head[u]] > dep[head[v]]) {\n        l.pb({pos[u], pos[head[u]]});\n   \
    \     u = par[head[u]];\n      } else {\n        r.pb({pos[head[v]], pos[v]});\n\
    \        v = par[head[v]];\n      }\n    }\n    if (dep[u] > dep[v]) l.pb({pos[u],\
    \ pos[v]});\n    else r.pb({pos[u], pos[v]});\n    reverse(all(r));\n    l.insert(l.end(),\
    \ all(r));\n    return l;\n  }\n  int lca(int u, int v) {\n    for (; head[u]\
    \ != head[v]; u = par[head[u]])\n      if (dep[head[u]] < dep[head[v]]) swap(u,\
    \ v);\n    return dep[u] < dep[v] ? u : v;\n  }\n};\n#line 5 \"tests/LCA.test.cpp\"\
    \n\nsigned main() {\n  ios::sync_with_stdio(false);\n  cin.tie(0);\n  int n, q;\n\
    \  cin >> n >> q;\n  vector<i64> a(n);\n  vector<vi> g(n);\n  for (int i = 1;\
    \ i < n; ++i) {\n    int p;\n    cin >> p;\n    g[p].eb(i), g[i].eb(p);\n  }\n\
    \  auto hld = HLD(g);\n  while (q--) {\n    int u, v;\n    cin >> u >> v;\n  \
    \  cout << hld.lca(u, v) << '\\n';\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#include \"../misc/macros.h\"\
    \n#include \"../ds/HLD.h\"\n\nsigned main() {\n  ios::sync_with_stdio(false);\n\
    \  cin.tie(0);\n  int n, q;\n  cin >> n >> q;\n  vector<i64> a(n);\n  vector<vi>\
    \ g(n);\n  for (int i = 1; i < n; ++i) {\n    int p;\n    cin >> p;\n    g[p].eb(i),\
    \ g[i].eb(p);\n  }\n  auto hld = HLD(g);\n  while (q--) {\n    int u, v;\n   \
    \ cin >> u >> v;\n    cout << hld.lca(u, v) << '\\n';\n  }\n}"
  dependsOn:
  - misc/macros.h
  - ds/HLD.h
  isVerificationFile: true
  path: tests/LCA.test.cpp
  requiredBy: []
  timestamp: '2025-11-28 02:09:51+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/LCA.test.cpp
layout: document
redirect_from:
- /verify/tests/LCA.test.cpp
- /verify/tests/LCA.test.cpp.html
title: tests/LCA.test.cpp
---
