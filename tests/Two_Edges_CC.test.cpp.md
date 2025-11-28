---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/2CC.h
    title: graph/2CC.h
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
    PROBLEM: https://judge.yosupo.jp/problem/two_edge_connected_components
    links:
    - https://judge.yosupo.jp/problem/two_edge_connected_components
  bundledCode: "#line 1 \"tests/Two_Edges_CC.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/two_edge_connected_components\"\
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
    \    v.insert(v.mutable_begin(), cur);\n*/\n#line 1 \"graph/2CC.h\"\nstruct BCC\
    \ {\n  const vector<vi>& g;\n  int n, ti = 0;\n  vector<vi> tree, blks;\n  vi\
    \ tin, low, st;\n  void dfs(int u, int p = -1) {\n    tin[u] = low[u] = ++ti;\n\
    \    st.pb(u);\n    for (int v : g[u]) if (v != p) {\n      if (tin[v]) low[u]\
    \ = min(low[u], tin[v]);\n      else {\n        dfs(v, u);\n        low[u] = min(low[u],\
    \ low[v]);\n        if (low[v] >= tin[u]) {\n          blks.pb({u});\n       \
    \   for (int x = -1; x != v; st.pop_back()) blks.back().pb(x = st.back());\n \
    \       }\n      }\n    }\n  }\n  BCC(const vector<vi>& G) : g(G), n(sz(G)), tin(n),\
    \ low(n) {\n    for (int i = 0; i < n; ++i) if (!tin[i]) {\n      dfs(i);\n  \
    \    if (g[i].empty()) blks.pb({i});\n    }\n    tree.assign(n + sz(blks), {});\n\
    \    for (int i = 0; i < sz(blks); ++i) {\n      int bid = n + i;\n      for (int\
    \ u : blks[i]) tree[bid].pb(u), tree[u].pb(bid);\n    }\n  }\n};\n\nstruct ECC\
    \ {\n  const vector<vi>& g;\n  int n, ti = 0;\n  vector<vi> tree, comps;\n  vi\
    \ tin, low, id, st;\n  void dfs(int u, int p = -1) {\n    tin[u] = low[u] = ++ti;\n\
    \    st.pb(u);\n    bool skipped = false; // Fix multiple edges\n    for (int\
    \ v : g[u]) {\n      if (v == p && !skipped) { skipped = true; continue; }\n \
    \     if (tin[v]) low[u] = min(low[u], tin[v]);\n      else {\n        dfs(v,\
    \ u);\n        low[u] = min(low[u], low[v]);\n      }\n    }\n    if (low[u] ==\
    \ tin[u]) { // Component root\n      comps.pb({});\n      for (int x = -1; x !=\
    \ u; st.pop_back()) {\n        id[x = st.back()] = sz(comps) - 1;\n        comps.back().pb(x);\n\
    \      }\n    }\n  }\n  ECC(const vector<vi>& G) : g(G), n(sz(G)), tin(n), low(n),\
    \ id(n) {\n    for (int i = 0; i < n; ++i) if (!tin[i]) dfs(i);\n    tree.assign(sz(comps),\
    \ {});\n    for (int u = 0; u < n; ++u) for (int v : g[u])\n      if (id[u] !=\
    \ id[v]) tree[id[u]].pb(id[v]);\n    for (auto& adj : tree) {\n      sort(all(adj));\
    \ adj.erase(unique(all(adj)), adj.end());\n    }\n  }\n};\n#line 5 \"tests/Two_Edges_CC.test.cpp\"\
    \n\nvoid solve() {\n  int n, m;\n  cin >> n >> m;\n  vector<vi> g(n);\n  for(int\
    \ i = 0; i < m; ++i) {\n    int u, v;\n    cin >> u >> v;\n    g[u].eb(v), g[v].eb(u);\n\
    \  }\n  ECC t(g);\n  cout << sz(t.comps) << '\\n';\n  for(auto comp: t.comps)\
    \ {\n    cout << sz(comp) << ' ';\n    for(auto u: comp) cout << u << ' ';\n \
    \   cout << '\\n';\n  }\n}\n\nint main() {\n  ios_base::sync_with_stdio(false);\
    \ cin.tie(NULL);\n  solve();\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_edge_connected_components\"\
    \n\n#include \"../misc/macros.h\"\n#include \"../graph/2CC.h\"\n\nvoid solve()\
    \ {\n  int n, m;\n  cin >> n >> m;\n  vector<vi> g(n);\n  for(int i = 0; i < m;\
    \ ++i) {\n    int u, v;\n    cin >> u >> v;\n    g[u].eb(v), g[v].eb(u);\n  }\n\
    \  ECC t(g);\n  cout << sz(t.comps) << '\\n';\n  for(auto comp: t.comps) {\n \
    \   cout << sz(comp) << ' ';\n    for(auto u: comp) cout << u << ' ';\n    cout\
    \ << '\\n';\n  }\n}\n\nint main() {\n  ios_base::sync_with_stdio(false); cin.tie(NULL);\n\
    \  solve();\n  return 0;\n}"
  dependsOn:
  - misc/macros.h
  - graph/2CC.h
  isVerificationFile: true
  path: tests/Two_Edges_CC.test.cpp
  requiredBy: []
  timestamp: '2025-11-28 15:36:49+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/Two_Edges_CC.test.cpp
layout: document
redirect_from:
- /verify/tests/Two_Edges_CC.test.cpp
- /verify/tests/Two_Edges_CC.test.cpp.html
title: tests/Two_Edges_CC.test.cpp
---
