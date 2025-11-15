---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/HopcroftKarp.h
    title: graph/HopcroftKarp.h
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
    PROBLEM: https://judge.yosupo.jp/problem/bipartitematching
    links:
    - https://judge.yosupo.jp/problem/bipartitematching
  bundledCode: "#line 1 \"tests/Matching_on_Bipartite_Graph_HopcroftKarp.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\n\n#line\
    \ 1 \"misc/macros.h\"\n// #ifdef LOCAL\n// #define __GLIBCXX_DEBUG 1\n// #endif\n\
    \n// #pragma GCC optimize(\"Ofast,unroll-loops\")       // unroll long, simple\
    \ loops\n// #pragma GCC target(\"avx2,fma\")                   // vectorizing\
    \ code\n// #pragma GCC target(\"lzcnt,popcnt,abm,bmi,bmi2\")  // for fast bitset\
    \ operation\n\n#include <bits/extc++.h>\n\n#include <tr2/dynamic_bitset>\n\nusing\
    \ namespace std;\nusing namespace __gnu_pbds;  // ordered_set, gp_hash_table\n\
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
    #endif\n#line 1 \"graph/HopcroftKarp.h\"\nbool dfs(int a, int L, vector<vi>& g,\
    \ vi& btoa, vi& A, vi& B) {\n  if (A[a] != L) return 0;\n  A[a] = -1;\n  for (int\
    \ b : g[a]) {\n    if (B[b] == L + 1) {\n      B[b] = 0;\n      if (btoa[b] ==\
    \ -1 || dfs(btoa[b], L + 1, g, btoa, A, B)) return btoa[b] = a, 1;\n    }\n  }\n\
    \  return 0;\n}\n\nint hopcroftKarp(vector<vi>& g, vi& btoa) {\n  int res = 0;\n\
    \  vi A(g.size()), B(btoa.size()), cur, next;\n  for (;;) {\n    fill(all(A),\
    \ 0);\n    fill(all(B), 0);\n    /// Find the starting nodes for BFS (i.e. layer\
    \ 0).\n    cur.clear();\n    for (int a : btoa)\n      if (a != -1) A[a] = -1;\n\
    \    for (int a = 0; a < sz(g); ++a)\n      if (A[a] == 0) cur.push_back(a);\n\
    \    /// Find all layers using bfs.\n    for (int lay = 1;; lay++) {\n      bool\
    \ islast = 0;\n      next.clear();\n      for (int a : cur)\n        for (int\
    \ b : g[a]) {\n          if (btoa[b] == -1) {\n            B[b] = lay;\n     \
    \       islast = 1;\n          } else if (btoa[b] != a && !B[b]) {\n         \
    \   B[b] = lay;\n            next.push_back(btoa[b]);\n          }\n        }\n\
    \      if (islast) break;\n      if (next.empty()) return res;\n      for (int\
    \ a : next) A[a] = lay;\n      cur.swap(next);\n    }\n    /// Use DFS to scan\
    \ for augmenting paths.\n    for (int a = 0; a < sz(g); ++a) res += dfs(a, 0,\
    \ g, btoa, A, B);\n  }\n}\n#line 5 \"tests/Matching_on_Bipartite_Graph_HopcroftKarp.test.cpp\"\
    \n\nvoid solve() {\n  int l, r, m;\n  cin >> l >> r >> m;\n  vector<vi> g(l);\n\
    \  vi btoa(r, -1);\n  for (int i = 0; i < m; ++i) {\n    int a, b;\n    cin >>\
    \ a >> b;\n    g[a].push_back(b);\n  }\n  cout << hopcroftKarp(g, btoa) << '\\\
    n';\n  for (int i = 0; i < r; ++i) {\n    if (btoa[i] != -1) {\n      cout <<\
    \ btoa[i] << ' ' << i << '\\n';\n    }\n  }\n}\n\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n\
    \  cin.exceptions(cin.failbit);\n  int tc = 1;\n  //   cin >> tc;\n  for (int\
    \ i = 1; i <= tc; ++i) {\n    solve();\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\n\n\
    #include \"../misc/macros.h\"\n#include \"../graph/HopcroftKarp.h\"\n\nvoid solve()\
    \ {\n  int l, r, m;\n  cin >> l >> r >> m;\n  vector<vi> g(l);\n  vi btoa(r, -1);\n\
    \  for (int i = 0; i < m; ++i) {\n    int a, b;\n    cin >> a >> b;\n    g[a].push_back(b);\n\
    \  }\n  cout << hopcroftKarp(g, btoa) << '\\n';\n  for (int i = 0; i < r; ++i)\
    \ {\n    if (btoa[i] != -1) {\n      cout << btoa[i] << ' ' << i << '\\n';\n \
    \   }\n  }\n}\n\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n  cin.exceptions(cin.failbit);\n\
    \  int tc = 1;\n  //   cin >> tc;\n  for (int i = 1; i <= tc; ++i) {\n    solve();\n\
    \  }\n}\n"
  dependsOn:
  - misc/macros.h
  - graph/HopcroftKarp.h
  isVerificationFile: true
  path: tests/Matching_on_Bipartite_Graph_HopcroftKarp.test.cpp
  requiredBy: []
  timestamp: '2025-11-15 18:26:28+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/Matching_on_Bipartite_Graph_HopcroftKarp.test.cpp
layout: document
redirect_from:
- /verify/tests/Matching_on_Bipartite_Graph_HopcroftKarp.test.cpp
- /verify/tests/Matching_on_Bipartite_Graph_HopcroftKarp.test.cpp.html
title: tests/Matching_on_Bipartite_Graph_HopcroftKarp.test.cpp
---
