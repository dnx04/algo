---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/HopcroftKarp.h
    title: graph/HopcroftKarp.h
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
    PROBLEM: https://judge.yosupo.jp/problem/bipartitematching
    links:
    - https://judge.yosupo.jp/problem/bipartitematching
  bundledCode: "#line 1 \"tests/Bipartite_Matching_HopcroftKarp.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\n\n#line 1 \"\
    misc/macros.h\"\n// #pragma GCC optimize(\"Ofast,unroll-loops\")       // unroll\
    \ long, simple loops\n// #pragma GCC target(\"avx2,fma\")                   //\
    \ vectorizing code\n// #pragma GCC target(\"lzcnt,popcnt,abm,bmi,bmi2\")  // for\
    \ fast bitset operation\n\n#include <bits/extc++.h>\n\nusing namespace std;\n\
    using namespace __gnu_pbds;  // ordered_set, gp_hash_table\n// using namespace\
    \ __gnu_cxx; // rope\n\n// for templates to work\n#define all(x) (x).begin(),\
    \ (x).end()\n#define len(x) (int) (x).size()\n#define pb push_back\n#define eb\
    \ emplace_back\nusing i32 = int32_t;\nusing u32 = uint32_t;\nusing i64 = int64_t;\n\
    using u64 = uint64_t;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\nusing\
    \ ld = long double;\nusing pii = pair<i32, i32>;\nusing vi = vector<i32>;\n\n\
    // fast map\nconst int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();\n\
    struct chash {  // customize hash function for gp_hash_table\n  int operator()(int\
    \ x) const { return x ^ RANDOM; }\n};\ngp_hash_table<int, int, chash> table;\n\
    \n/* ordered set\n    find_by_order(k): returns an iterator to the k-th element\
    \ (0-based)\n    order_of_key(k): returns the number of elements in the set that\
    \ are strictly less than k\n*/\ntemplate <class T>\nusing ordered_set = tree<T,\
    \ null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;\n\n/* \
    \ rope\n    rope <int> cur = v.substr(l, r - l + 1);\n    v.erase(l, r - l + 1);\n\
    \    v.insert(v.mutable_begin(), cur);\n*/\n#line 1 \"graph/HopcroftKarp.h\"\n\
    struct HopcroftKarp {\n  vector<vi> g;\n  vi btoa, A, B;\n  HopcroftKarp(int L,\
    \ int R) : g(L), btoa(R, -1), A(L), B(R) {}\n  void add(int u, int v) { g[u].pb(v);\
    \ }\n  bool dfs(int a, int L) {\n    if (A[a] != L) return 0;\n    A[a] = -1;\n\
    \    for (int b : g[a])\n      if (B[b] == L + 1) {\n        B[b] = 0;\n     \
    \   if (btoa[b] == -1 || dfs(btoa[b], L + 1)) return btoa[b] = a, 1;\n      }\n\
    \    return 0;\n  }\n  int solve() {\n    int res = 0;\n    vi cur, next;\n  \
    \  for (;;) {\n      fill(all(A), 0), fill(all(B), 0), cur.clear();\n      for\
    \ (int a : btoa)\n        if (a != -1) A[a] = -1;\n      for (int a = 0; a < len(g);\
    \ ++a)\n        if (!A[a]) cur.pb(a);\n      for (int lay = 1;; lay++) {\n   \
    \     bool islast = 0;\n        next.clear();\n        for (int a : cur)\n   \
    \       for (int b : g[a]) {\n            if (btoa[b] == -1)\n              B[b]\
    \ = lay, islast = 1;\n            else if (btoa[b] != a && !B[b])\n          \
    \    B[b] = lay, next.pb(btoa[b]);\n          }\n        if (islast) break;\n\
    \        if (next.empty()) return res;\n        for (int a : next) A[a] = lay;\n\
    \        cur.swap(next);\n      }\n      for (int a = 0; a < len(g); ++a) res\
    \ += dfs(a, 0);\n    }\n  }\n};\n#line 5 \"tests/Bipartite_Matching_HopcroftKarp.test.cpp\"\
    \n\nvoid solve() {\n  int l, r, m;\n  cin >> l >> r >> m;\n  HopcroftKarp g(l,\
    \ r);\n  for (int i = 0; i < m; ++i) {\n    int a, b;\n    cin >> a >> b;\n  \
    \  g.add(a, b);\n  }\n  cout << g.solve() << '\\n';\n  for (int i = 0; i < r;\
    \ ++i) {\n    if (g.btoa[i] != -1) {\n      cout << g.btoa[i] << ' ' << i << '\\\
    n';\n    }\n  }\n}\n\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n  cin.exceptions(cin.failbit);\n\
    \  int tc = 1;\n  //   cin >> tc;\n  for (int i = 1; i <= tc; ++i) {\n    solve();\n\
    \  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\n\n\
    #include \"../misc/macros.h\"\n#include \"../graph/HopcroftKarp.h\"\n\nvoid solve()\
    \ {\n  int l, r, m;\n  cin >> l >> r >> m;\n  HopcroftKarp g(l, r);\n  for (int\
    \ i = 0; i < m; ++i) {\n    int a, b;\n    cin >> a >> b;\n    g.add(a, b);\n\
    \  }\n  cout << g.solve() << '\\n';\n  for (int i = 0; i < r; ++i) {\n    if (g.btoa[i]\
    \ != -1) {\n      cout << g.btoa[i] << ' ' << i << '\\n';\n    }\n  }\n}\n\nint\
    \ main() {\n  cin.tie(0)->sync_with_stdio(0);\n  cin.exceptions(cin.failbit);\n\
    \  int tc = 1;\n  //   cin >> tc;\n  for (int i = 1; i <= tc; ++i) {\n    solve();\n\
    \  }\n}\n"
  dependsOn:
  - misc/macros.h
  - graph/HopcroftKarp.h
  isVerificationFile: true
  path: tests/Bipartite_Matching_HopcroftKarp.test.cpp
  requiredBy: []
  timestamp: '2026-10-03 15:27:40+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/Bipartite_Matching_HopcroftKarp.test.cpp
layout: document
redirect_from:
- /verify/tests/Bipartite_Matching_HopcroftKarp.test.cpp
- /verify/tests/Bipartite_Matching_HopcroftKarp.test.cpp.html
title: tests/Bipartite_Matching_HopcroftKarp.test.cpp
---
