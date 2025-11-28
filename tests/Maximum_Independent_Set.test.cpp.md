---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/Cliques.h
    title: graph/Cliques.h
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
    PROBLEM: https://judge.yosupo.jp/problem/maximum_independent_set
    links:
    - https://judge.yosupo.jp/problem/maximum_independent_set
  bundledCode: "#line 1 \"tests/Maximum_Independent_Set.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/maximum_independent_set\"\n\n#line 1 \"misc/macros.h\"\
    \n// #pragma GCC optimize(\"Ofast,unroll-loops\")       // unroll long, simple\
    \ loops\n// #pragma GCC target(\"avx2,fma\")                   // vectorizing\
    \ code\n// #pragma GCC target(\"lzcnt,popcnt,abm,bmi,bmi2\")  // for fast bitset\
    \ operation\n\n#include <bits/extc++.h>\n#include <tr2/dynamic_bitset>\n\nusing\
    \ namespace std;\nusing namespace __gnu_pbds;  // ordered_set, gp_hash_table\n\
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
    \    v.insert(v.mutable_begin(), cur);\n*/\n#line 1 \"graph/Cliques.h\"\nusing\
    \ bs = tr2::dynamic_bitset<uint64_t>;\n\n// Usage: bs P(n), X(n), R(n); P.set();\
    \ EnumClique(g, [&](bs& c){...}, P, X, R);\ntemplate <class F>\nvoid EnumClique(vector<bs>&\
    \ g, F f, bs P, bs X, bs R) {\n  f(R); \n  if (P.none() && X.none()) return;\n\
    \  // if only need to find all maximal cliques\n  // auto q = (P | X).find_first();\n\
    \  // auto cands = P & ~g[q]; // then trav through cands\n  for (auto i = P.find_first();\
    \ i < P.size(); i = P.find_next(i)) {\n    R[i] = 1;\n    EnumClique(g, f, P &\
    \ g[i], X & g[i], R);\n    R[i] = 0, P[i] = 0, X[i] = 1;\n  }\n}\n\n// Usage:\
    \ bs P(n), R(n), sol; u64 ans=0; P.set(); MaxClique(g, P, R, sol, ans);\nvoid\
    \ MaxClique(vector<bs>& g, bs P, bs R, bs& sol, u32& res) {\n  if (R.count() +\
    \ P.count() <= res) return;\n  if (P.none()) { res = R.count(), sol = R; return;\
    \ }\n  auto q = P.find_first(), max_k = u64(0);\n  for (auto i = q; i < P.size();\
    \ i = P.find_next(i)) {\n    auto k = (P & g[i]).count();\n    if (k > max_k)\
    \ max_k = k, q = i;\n  }\n  bs cands = P & ~g[q];\n  for (auto i = cands.find_first();\
    \ i < cands.size(); i = cands.find_next(i)) {\n    R[i] = 1, MaxClique(g, P &\
    \ g[i], R, sol, res);\n    R[i] = P[i] = 0;\n  }\n}\n#line 5 \"tests/Maximum_Independent_Set.test.cpp\"\
    \n\nsigned main() {\n  cin.tie(0)->sync_with_stdio(0);\n  cin.exceptions(cin.failbit);\n\
    \  int n, m;\n  cin >> n >> m;\n  vector<bs> adj(n, bs(n));\n  for (int i = 0;\
    \ i < m; ++i) {\n    int u, v;\n    cin >> u >> v;\n    adj[u][v] = adj[v][u]\
    \ = 1;\n  }\n  for (int i = 0; i < n; ++i) {\n    adj[i].set(), adj[i][i] = 0;\n\
    \  }\n  bs P(n), R(n), sol(n); \n  int ans=0; P.set(); \n  MaxClique(adj, P, R,\
    \ sol, ans);\n  cout << ans << '\\n';\n  // for (int i = sol.find_first(); i !=\
    \ bs::npos; i = sol.find_next(i)) {\n  //   cout << i << ' ';\n  // }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/maximum_independent_set\"\
    \n\n#include \"../misc/macros.h\"\n#include \"../graph/Cliques.h\"\n\nsigned main()\
    \ {\n  cin.tie(0)->sync_with_stdio(0);\n  cin.exceptions(cin.failbit);\n  int\
    \ n, m;\n  cin >> n >> m;\n  vector<bs> adj(n, bs(n));\n  for (int i = 0; i <\
    \ m; ++i) {\n    int u, v;\n    cin >> u >> v;\n    adj[u][v] = adj[v][u] = 1;\n\
    \  }\n  for (int i = 0; i < n; ++i) {\n    adj[i].set(), adj[i][i] = 0;\n  }\n\
    \  bs P(n), R(n), sol(n); \n  int ans=0; P.set(); \n  MaxClique(adj, P, R, sol,\
    \ ans);\n  cout << ans << '\\n';\n  // for (int i = sol.find_first(); i != bs::npos;\
    \ i = sol.find_next(i)) {\n  //   cout << i << ' ';\n  // }\n}\n"
  dependsOn:
  - misc/macros.h
  - graph/Cliques.h
  isVerificationFile: true
  path: tests/Maximum_Independent_Set.test.cpp
  requiredBy: []
  timestamp: '2025-11-28 12:47:29+07:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: tests/Maximum_Independent_Set.test.cpp
layout: document
redirect_from:
- /verify/tests/Maximum_Independent_Set.test.cpp
- /verify/tests/Maximum_Independent_Set.test.cpp.html
title: tests/Maximum_Independent_Set.test.cpp
---
