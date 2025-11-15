---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/Fenwick.h
    title: ds/Fenwick.h
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
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_path_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_path_sum
  bundledCode: "#line 1 \"tests/Vertex_Add_Path_Sum.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\n#line 1 \"misc/macros.h\"\
    \n// #ifdef LOCAL\n// #define __GLIBCXX_DEBUG 1\n// #endif\n\n// #pragma GCC optimize(\"\
    Ofast,unroll-loops\")       // unroll long, simple loops\n// #pragma GCC target(\"\
    avx2,fma\")                   // vectorizing code\n// #pragma GCC target(\"lzcnt,popcnt,abm,bmi,bmi2\"\
    )  // for fast bitset operation\n\n#include <bits/extc++.h>\n\n#include <tr2/dynamic_bitset>\n\
    \nusing namespace std;\nusing namespace __gnu_pbds;  // ordered_set, gp_hash_table\n\
    using namespace __gnu_cxx;   // rope, cut and insert subarray in O(logn)\n\n//\
    \ for templates to work\n#define all(s) s.begin(), s.end()\n#define sz(x) (int)\
    \ (x).size()\n#define pb push_back\n#define eb emplace_back\ntypedef long long\
    \ ll;\ntypedef unsigned long long ull;\ntypedef pair<int, int> pii;\ntypedef vector<int>\
    \ vi;\n\n// fast map\nconst int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();\n\
    struct chash {  // customize hash function for gp_hash_table\n  int operator()(int\
    \ x) const { return x ^ RANDOM; }\n};\ngp_hash_table<int, int, chash> table;\n\
    \n/* ordered set\n    find_by_order(k): returns an iterator to the k-th element\
    \ (0-based)\n    order_of_key(k): returns the number of elements in the set that\
    \ are strictly less than k\n*/\ntemplate <typename T>\nusing ordered_set = tree<T,\
    \ null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;\n\n// dynamic\
    \ bitset\nusing bs = tr2::dynamic_bitset<uint64_t>;\n\n/*  rope\n    rope <int>\
    \ cur = v.substr(l, r - l + 1);\n    v.erase(l, r - l + 1);\n    v.insert(v.mutable_begin(),\
    \ cur);\n*/\n\n#define CONCAT_(x, y) x##y\n#define CONCAT(x, y) CONCAT_(x, y)\n\
    #ifdef LOCAL\n#define clog cerr << setw(__db_level * 2) << setfill(' ') << \"\"\
    \ << setw(0)\n#define DB() debug_block CONCAT(dbbl, __LINE__)\nint __db_level\
    \ = 0;\nstruct debug_block {\n  debug_block() {\n    clog << \"{\" << endl;\n\
    \    ++__db_level;\n  }\n  ~debug_block() {\n    --__db_level;\n    clog << \"\
    }\" << endl;\n  }\n};\n#else\n#define clog \\\n  if (0) cerr\n#define DB(...)\n\
    #endif\n#line 1 \"ds/Fenwick.h\"\ntemplate <typename T>\nstruct Fenwick {  //\
    \ 1-indexed\n  int n;\n  vector<T> t;\n  Fenwick(int n) : n(n), t(n + 1, T(0))\
    \ {}\n  void add(int p, T v) {\n    while (p <= n) t[p] += v, p += (p & -p);\n\
    \  }\n  T sum(int p) {\n    T res = 0;\n    while (p) res += t[p], p -= (p & -p);\n\
    \    return res;\n  }\n  T sum(int l, int r) {\n    if (l > r) return T(0);\n\
    \    return sum(r) - sum(l - 1);\n  }\n};\n#line 1 \"ds/HLD.h\"\ntemplate <typename\
    \ G>\nstruct HLD {\n private:\n  void dfs_sz(int cur) {\n    size[cur] = 1;\n\
    \    for (auto& dst : g[cur]) {\n      if (dst == par[cur]) {\n        if (g[cur].size()\
    \ >= 2 && int(dst) == int(g[cur][0]))\n          swap(g[cur][0], g[cur][1]);\n\
    \        else\n          continue;\n      }\n      depth[dst] = depth[cur] + 1;\n\
    \      par[dst] = cur;\n      dfs_sz(dst);\n      size[cur] += size[dst];\n  \
    \    if (size[dst] > size[g[cur][0]]) {\n        swap(dst, g[cur][0]);\n     \
    \ }\n    }\n  }\n\n  void dfs_hld(int cur) {\n    down[cur] = id++;\n    for (auto\
    \ dst : g[cur]) {\n      if (dst == par[cur]) continue;\n      nxt[dst] = (int(dst)\
    \ == int(g[cur][0]) ? nxt[cur] : int(dst));\n      dfs_hld(dst);\n    }\n    up[cur]\
    \ = id;\n  }\n\n  // [u, v)\n  vector<pii> ascend(int u, int v) const {\n    vector<pii>\
    \ res;\n    while (nxt[u] != nxt[v]) {\n      res.eb(down[u], down[nxt[u]]);\n\
    \      u = par[nxt[u]];\n    }\n    if (u != v) res.eb(down[u], down[v] + 1);\n\
    \    return res;\n  }\n\n  // (u, v]\n  vector<pii> descend(int u, int v) const\
    \ {\n    if (u == v) return {};\n    if (nxt[u] == nxt[v]) return {{down[u] +\
    \ 1, down[v]}};\n    auto res = descend(u, par[nxt[v]]);\n    res.eb(down[nxt[v]],\
    \ down[v]);\n    return res;\n  }\n\n public:\n  G& g;\n  int root, id;\n  vector<int>\
    \ size, depth, down, up, nxt, par;\n  HLD(G& g, int root = 0) : g(g), root(root),\
    \ id(0), size(sz(g), 0), depth(sz(g), 0), down(sz(g), -1), up(sz(g), -1), nxt(sz(g),\
    \ root), par(sz(g), root) {\n    dfs_sz(root);\n    dfs_hld(root);\n  }\n\n  pii\
    \ idx(int i) const { return make_pair(down[i], up[i]); }\n\n  template <typename\
    \ F>\n  void path_query(int u, int v, bool vertex, const F& f) {\n    int l =\
    \ lca(u, v);\n    for (auto&& [a, b] : ascend(u, l)) {\n      int s = a + 1, t\
    \ = b;\n      s > t ? f(t, s) : f(s, t);\n    }\n    if (vertex) f(down[l], down[l]\
    \ + 1);\n    for (auto&& [a, b] : descend(l, v)) {\n      int s = a, t = b + 1;\n\
    \      s > t ? f(t, s) : f(s, t);\n    }\n  }\n\n  template <typename F>\n  void\
    \ path_noncommutative_query(int u, int v, bool vertex, const F& f) {\n    int\
    \ l = lca(u, v);\n    for (auto&& [a, b] : ascend(u, l)) f(a + 1, b);\n    if\
    \ (vertex) f(down[l], down[l] + 1);\n    for (auto&& [a, b] : descend(l, v)) f(a,\
    \ b + 1);\n  }\n\n  template <typename F>\n  void subtree_query(int u, bool vertex,\
    \ const F& f) {\n    f(down[u] + int(!vertex), up[u]);\n  }\n\n  int lca(int a,\
    \ int b) {\n    while (nxt[a] != nxt[b]) {\n      if (down[a] < down[b]) swap(a,\
    \ b);\n      a = par[nxt[a]];\n    }\n    return depth[a] < depth[b] ? a : b;\n\
    \  }\n\n  int dist(int a, int b) { return depth[a] + depth[b] - depth[lca(a, b)]\
    \ * 2; }\n};\n#line 6 \"tests/Vertex_Add_Path_Sum.test.cpp\"\n\nsigned main()\
    \ {\n  ios::sync_with_stdio(false);\n  cin.tie(0);\n\n  int n, q;\n  cin >> n\
    \ >> q;\n  Fenwick<ll> fw(n);\n  vector<ll> a(n);\n  vector<vi> g(n);\n  for (int\
    \ i = 0; i < n; ++i) cin >> a[i];\n  for (int i = 0; i < n - 1; ++i) {\n    int\
    \ u, v;\n    cin >> u >> v;\n    g[u].eb(v), g[v].eb(u);\n  }\n  auto hld = HLD(g);\n\
    \  for (int i = 0; i < n; ++i) fw.add(hld.idx(i).first + 1, a[i]);\n  while (q--)\
    \ {\n    int cmd;\n    cin >> cmd;\n    if (cmd == 0) {\n      int p, x;\n   \
    \   cin >> p >> x;\n      fw.add(hld.idx(p).first + 1, x);\n    } else {\n   \
    \   int u, v;\n      cin >> u >> v;\n      ll res = 0;\n      hld.path_query(u,\
    \ v, true, [&](const int& u, const int& v) {\n        res += fw.sum(u + 1, v);\n\
    \      });\n      cout << res << '\\n';\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\
    \n#include \"../misc/macros.h\"\n#include \"../ds/Fenwick.h\"\n#include \"../ds/HLD.h\"\
    \n\nsigned main() {\n  ios::sync_with_stdio(false);\n  cin.tie(0);\n\n  int n,\
    \ q;\n  cin >> n >> q;\n  Fenwick<ll> fw(n);\n  vector<ll> a(n);\n  vector<vi>\
    \ g(n);\n  for (int i = 0; i < n; ++i) cin >> a[i];\n  for (int i = 0; i < n -\
    \ 1; ++i) {\n    int u, v;\n    cin >> u >> v;\n    g[u].eb(v), g[v].eb(u);\n\
    \  }\n  auto hld = HLD(g);\n  for (int i = 0; i < n; ++i) fw.add(hld.idx(i).first\
    \ + 1, a[i]);\n  while (q--) {\n    int cmd;\n    cin >> cmd;\n    if (cmd ==\
    \ 0) {\n      int p, x;\n      cin >> p >> x;\n      fw.add(hld.idx(p).first +\
    \ 1, x);\n    } else {\n      int u, v;\n      cin >> u >> v;\n      ll res =\
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
  timestamp: '2025-11-15 18:26:28+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/Vertex_Add_Path_Sum.test.cpp
layout: document
redirect_from:
- /verify/tests/Vertex_Add_Path_Sum.test.cpp
- /verify/tests/Vertex_Add_Path_Sum.test.cpp.html
title: tests/Vertex_Add_Path_Sum.test.cpp
---
