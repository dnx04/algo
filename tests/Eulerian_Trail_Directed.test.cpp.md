---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/EulerWalk.h
    title: graph/EulerWalk.h
  - icon: ':question:'
    path: misc/macros.h
    title: misc/macros.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/eulerian_trail_directed
    links:
    - https://judge.yosupo.jp/problem/eulerian_trail_directed
  bundledCode: "#line 1 \"tests/Eulerian_Trail_Directed.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/eulerian_trail_directed\"\n\n#line 1 \"misc/macros.h\"\
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
    \ cur);\n*/\n#line 1 \"graph/EulerWalk.h\"\npair<vi, vi> EulerWalk(int n, vector<vector<pii>>&\
    \ adj, int m, bool dir, bool cyc) {\n  vi D(n), ptr(n), used(m), nodes, edges;\n\
    \  vector<pii> st;\n  int src = 0, bad = 0;\n  for (int i = 0; i < n; ++i) {\n\
    \    if (dir) for (auto& p : adj[i]) D[i]++, D[p.first]--;\n    else D[i] = sz(adj[i])\
    \ & 1;\n  }\n  for (int i = 0; i < n; ++i) {\n    if (sz(adj[i]) && adj[src].empty())\
    \ src = i;\n    if (D[i]) {\n      bad++;\n      if ((dir && D[i] > 0) || (!dir))\
    \ src = i;\n    }\n  }\n  if (bad > 2 || (cyc && bad) || (dir && bad && D[src]\
    \ != 1)) return {};\n  st.pb({src, -1});\n  while (!st.empty()) {\n    int u =\
    \ st.back().first;\n    if (ptr[u] < sz(adj[u])) {\n      auto [v, id] = adj[u][ptr[u]++];\n\
    \      if (!used[id]) used[id] = 1, st.pb({v, id});\n    } else {\n      auto\
    \ [v, id] = st.back();\n      st.pop_back();\n      nodes.pb(v);\n      if (id\
    \ != -1) edges.pb(id);\n    }\n  }\n  if (sz(edges) != m) return {};\n  reverse(all(nodes)),\
    \ reverse(all(edges));\n  return {nodes, edges};\n}\n#line 5 \"tests/Eulerian_Trail_Directed.test.cpp\"\
    \n\nvoid solve() {\n  int n, m;\n  cin >> n >> m;\n  vector<vector<pii>> g(n);\n\
    \  for (int i = 0; i < m; ++i) {\n    int u, v;\n    cin >> u >> v;\n    g[u].eb(v,\
    \ i);\n  }\n  auto [nodes, edges] = EulerWalk(n, g, m, true, false);\n  if (!nodes.empty())\
    \ {\n    cout << \"Yes\\n\";\n    for (auto u : nodes) cout << u << ' ';\n   \
    \ cout << '\\n';\n    for (auto e : edges) cout << e << ' ';\n    cout << '\\\
    n';\n  } else {\n    cout << \"No\\n\";\n  }\n}\n\nint main() {\n  int tc;\n \
    \ cin >> tc;\n  while (tc--) solve();\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/eulerian_trail_directed\"\
    \n\n#include \"../misc/macros.h\"\n#include \"../graph/EulerWalk.h\"\n\nvoid solve()\
    \ {\n  int n, m;\n  cin >> n >> m;\n  vector<vector<pii>> g(n);\n  for (int i\
    \ = 0; i < m; ++i) {\n    int u, v;\n    cin >> u >> v;\n    g[u].eb(v, i);\n\
    \  }\n  auto [nodes, edges] = EulerWalk(n, g, m, true, false);\n  if (!nodes.empty())\
    \ {\n    cout << \"Yes\\n\";\n    for (auto u : nodes) cout << u << ' ';\n   \
    \ cout << '\\n';\n    for (auto e : edges) cout << e << ' ';\n    cout << '\\\
    n';\n  } else {\n    cout << \"No\\n\";\n  }\n}\n\nint main() {\n  int tc;\n \
    \ cin >> tc;\n  while (tc--) solve();\n}"
  dependsOn:
  - misc/macros.h
  - graph/EulerWalk.h
  isVerificationFile: true
  path: tests/Eulerian_Trail_Directed.test.cpp
  requiredBy: []
  timestamp: '2025-11-21 16:12:02+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/Eulerian_Trail_Directed.test.cpp
layout: document
redirect_from:
- /verify/tests/Eulerian_Trail_Directed.test.cpp
- /verify/tests/Eulerian_Trail_Directed.test.cpp.html
title: tests/Eulerian_Trail_Directed.test.cpp
---
