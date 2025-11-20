---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/GeneralMatching.h
    title: graph/GeneralMatching.h
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
    PROBLEM: https://judge.yosupo.jp/problem/general_matching
    links:
    - https://judge.yosupo.jp/problem/general_matching
  bundledCode: "#line 1 \"tests/General_Matching.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/general_matching\"\
    \n\n#line 1 \"misc/macros.h\"\n// #pragma GCC optimize(\"Ofast,unroll-loops\"\
    )       // unroll long, simple loops\n// #pragma GCC target(\"avx2,fma\")    \
    \               // vectorizing code\n// #pragma GCC target(\"lzcnt,popcnt,abm,bmi,bmi2\"\
    )  // for fast bitset operation\n\n#include <bits/extc++.h>\n\n#include <tr2/dynamic_bitset>\n\
    \nusing namespace std;\nusing namespace __gnu_pbds;  // ordered_set, gp_hash_table\n\
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
    \ are strictly less than k\n*/\ntemplate <typename T>\nusing ordered_set = tree<T,\
    \ null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;\n\n// dynamic\
    \ bitset\nusing bs = tr2::dynamic_bitset<u64>;\n\n/*  rope\n    rope <int> cur\
    \ = v.substr(l, r - l + 1);\n    v.erase(l, r - l + 1);\n    v.insert(v.mutable_begin(),\
    \ cur);\n*/\n#line 1 \"graph/GeneralMatching.h\"\nvi GeneralMatching(vector<vi>&\
    \ graph) {\n  int n = graph.size(), timer = -1;\n  vi mate(n, -1), label(n), parent(n),\
    \ orig(n), aux(n, -1), q;\n  auto lca = [&](int x, int y) {\n    for (timer++;;\
    \ swap(x, y)) {\n      if (x == -1) continue;\n      if (aux[x] == timer) return\
    \ x;\n      aux[x] = timer;\n      x = (mate[x] == -1 ? -1 : orig[parent[mate[x]]]);\n\
    \    }\n  };\n  auto blossom = [&](int v, int w, int a) {\n    while (orig[v]\
    \ != a) {\n      parent[v] = w;\n      w = mate[v];\n      if (label[w] == 1)\
    \ label[w] = 0, q.push_back(w);\n      orig[v] = orig[w] = a;\n      v = parent[w];\n\
    \    }\n  };\n  auto augment = [&](int v) {\n    while (v != -1) {\n      int\
    \ pv = parent[v], nv = mate[pv];\n      mate[v] = pv;\n      mate[pv] = v;\n \
    \     v = nv;\n    }\n  };\n  auto bfs = [&](int root) {\n    fill(label.begin(),\
    \ label.end(), -1);\n    iota(orig.begin(), orig.end(), 0);\n    q.clear();\n\
    \    label[root] = 0;\n    q.push_back(root);\n    for (int i = 0; i < (int) q.size();\
    \ ++i) {\n      int v = q[i];\n      for (auto x : graph[v]) {\n        if (label[x]\
    \ == -1) {\n          label[x] = 1;\n          parent[x] = v;\n          if (mate[x]\
    \ == -1)\n            return augment(x), 1;\n          label[mate[x]] = 0;\n \
    \         q.push_back(mate[x]);\n        } else if (label[x] == 0 && orig[v] !=\
    \ orig[x]) {\n          int a = lca(orig[v], orig[x]);\n          blossom(x, v,\
    \ a);\n          blossom(v, x, a);\n        }\n      }\n    }\n    return 0;\n\
    \  };\n  // Time halves if you start with (any) maximal matching.\n  for (int\
    \ i = 0; i < n; i++)\n    if (mate[i] == -1)\n      bfs(i);\n  return mate;\n\
    }\n#line 5 \"tests/General_Matching.test.cpp\"\n\nsigned main() {\n  ios::sync_with_stdio(false);\n\
    \  cin.tie(0);\n  int n, m;\n  cin >> n >> m;\n  vector<vi> graph(n);\n  for (int\
    \ i = 0; i < m; ++i) {\n    int u, v;\n    cin >> u >> v;\n    graph[u].pb(v),\
    \ graph[v].pb(u);\n  }\n  auto match = GeneralMatching(graph);\n  vector<pii>\
    \ mate;\n  for (int i = 0; i < n; ++i) {\n    if (i < match[i]) mate.pb({i, match[i]});\n\
    \  }\n  cout << sz(mate) << '\\n';\n  for (auto [u, v] : mate) cout << u << '\
    \ ' << v << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/general_matching\"\n\n\
    #include \"../misc/macros.h\"\n#include \"../graph/GeneralMatching.h\"\n\nsigned\
    \ main() {\n  ios::sync_with_stdio(false);\n  cin.tie(0);\n  int n, m;\n  cin\
    \ >> n >> m;\n  vector<vi> graph(n);\n  for (int i = 0; i < m; ++i) {\n    int\
    \ u, v;\n    cin >> u >> v;\n    graph[u].pb(v), graph[v].pb(u);\n  }\n  auto\
    \ match = GeneralMatching(graph);\n  vector<pii> mate;\n  for (int i = 0; i <\
    \ n; ++i) {\n    if (i < match[i]) mate.pb({i, match[i]});\n  }\n  cout << sz(mate)\
    \ << '\\n';\n  for (auto [u, v] : mate) cout << u << ' ' << v << '\\n';\n}"
  dependsOn:
  - misc/macros.h
  - graph/GeneralMatching.h
  isVerificationFile: true
  path: tests/General_Matching.test.cpp
  requiredBy: []
  timestamp: '2025-11-18 17:12:08+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/General_Matching.test.cpp
layout: document
redirect_from:
- /verify/tests/General_Matching.test.cpp
- /verify/tests/General_Matching.test.cpp.html
title: tests/General_Matching.test.cpp
---
