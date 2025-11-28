---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/Dinic.h
    title: graph/Dinic.h
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
  bundledCode: "#line 1 \"tests/Bipartite_Matching_Dinic.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/bipartitematching\"\n\n#line 1 \"misc/macros.h\"\
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
    \    v.insert(v.mutable_begin(), cur);\n*/\n#line 1 \"graph/Dinic.h\"\nstruct\
    \ Dinic {\n  struct Edge {\n    int to, rev;\n    i64 c, oc;\n    i64 flow() {\
    \ return max(oc - c, i64(0)); }  // if you need flows\n  };\n  vi lvl, ptr, q;\n\
    \  vector<vector<Edge>> adj;\n  Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}\n\
    \  void addEdge(int a, int b, i64 c, i64 rcap = 0) {\n    adj[a].pb({b, sz(adj[b]),\
    \ c, c});\n    adj[b].pb({a, sz(adj[a]) - 1, rcap, rcap});\n  }\n  i64 dfs(int\
    \ v, int t, i64 f) {\n    if (v == t || !f) return f;\n    for (int& i = ptr[v];\
    \ i < sz(adj[v]); i++) {\n      Edge& e = adj[v][i];\n      if (lvl[e.to] == lvl[v]\
    \ + 1)\n        if (i64 p = dfs(e.to, t, min(f, e.c))) {\n          e.c -= p,\
    \ adj[e.to][e.rev].c += p;\n          return p;\n        }\n    }\n    return\
    \ 0;\n  }\n  i64 calc(int s, int t) {\n    i64 flow = 0;\n    q[0] = s;\n    //\
    \ 'int L=30' maybe faster for random data\n    for (int L = 0; L < 31; ++L) {\n\
    \      do {\n        lvl = ptr = vi(sz(q));\n        int qi = 0, qe = lvl[s] =\
    \ 1;\n        while (qi < qe && !lvl[t]) {\n          int v = q[qi++];\n     \
    \     for (Edge e : adj[v])\n            if (!lvl[e.to] && e.c >> (30 - L))\n\
    \              q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;\n        }\n        while\
    \ (i64 p = dfs(s, t, LLONG_MAX)) flow += p;\n      } while (lvl[t]);\n    }\n\
    \    return flow;\n  }\n  bool leftOfMinCut(int a) { return lvl[a] != 0; }\n};\n\
    #line 5 \"tests/Bipartite_Matching_Dinic.test.cpp\"\n\nvoid solve() {\n  int L,\
    \ R, M;\n  cin >> L >> R >> M;\n\n  // X\xE2y d\u1EF1ng \u0111\u1ED3 th\u1ECB\
    :\n  // 0 -> L-1: \u0110\u1EC9nh tr\xE1i\n  // L -> L+R-1: \u0110\u1EC9nh ph\u1EA3\
    i\n  // S = L+R, T = L+R+1\n  int S = L + R, T = L + R + 1;\n  Dinic dinic(T +\
    \ 1);\n\n  // N\u1ED1i S -> Left\n  for (int i = 0; i < L; ++i) dinic.addEdge(S,\
    \ i, 1);\n  \n  // N\u1ED1i Right -> T\n  for (int i = 0; i < R; ++i) dinic.addEdge(L\
    \ + i, T, 1);\n\n  // N\u1ED1i Left -> Right (Edges)\n  for (int i = 0; i < M;\
    \ ++i) {\n    int u, v;\n    cin >> u >> v;\n    dinic.addEdge(u, L + v, 1);\n\
    \  }\n\n  // T\xEDnh lu\u1ED3ng c\u1EF1c \u0111\u1EA1i = C\u1EB7p gh\xE9p c\u1EF1\
    c \u0111\u1EA1i\n  cout << dinic.calc(S, T) << \"\\n\";\n\n  // Truy v\u1EBFt\
    \ in k\u1EBFt qu\u1EA3\n  // Duy\u1EC7t qua c\xE1c \u0111\u1EC9nh b\xEAn tr\xE1\
    i (0 -> L-1)\n  for (int i = 0; i < L; ++i) {\n    for (auto& e : dinic.adj[i])\
    \ {\n      if (e.to >= L && e.to < L + R && e.c == 0) {\n        cout << i <<\
    \ \" \" << e.to - L << \"\\n\";\n      }\n    }\n  }\n}\n\nsigned main() {\n \
    \ ios::sync_with_stdio(false);\n  cin.tie(0);\n  int tc = 1;\n  // cin >> tc;\n\
    \  while (tc--) solve();\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\n\n\
    #include \"../misc/macros.h\"\n#include \"../graph/Dinic.h\"\n\nvoid solve() {\n\
    \  int L, R, M;\n  cin >> L >> R >> M;\n\n  // X\xE2y d\u1EF1ng \u0111\u1ED3 th\u1ECB\
    :\n  // 0 -> L-1: \u0110\u1EC9nh tr\xE1i\n  // L -> L+R-1: \u0110\u1EC9nh ph\u1EA3\
    i\n  // S = L+R, T = L+R+1\n  int S = L + R, T = L + R + 1;\n  Dinic dinic(T +\
    \ 1);\n\n  // N\u1ED1i S -> Left\n  for (int i = 0; i < L; ++i) dinic.addEdge(S,\
    \ i, 1);\n  \n  // N\u1ED1i Right -> T\n  for (int i = 0; i < R; ++i) dinic.addEdge(L\
    \ + i, T, 1);\n\n  // N\u1ED1i Left -> Right (Edges)\n  for (int i = 0; i < M;\
    \ ++i) {\n    int u, v;\n    cin >> u >> v;\n    dinic.addEdge(u, L + v, 1);\n\
    \  }\n\n  // T\xEDnh lu\u1ED3ng c\u1EF1c \u0111\u1EA1i = C\u1EB7p gh\xE9p c\u1EF1\
    c \u0111\u1EA1i\n  cout << dinic.calc(S, T) << \"\\n\";\n\n  // Truy v\u1EBFt\
    \ in k\u1EBFt qu\u1EA3\n  // Duy\u1EC7t qua c\xE1c \u0111\u1EC9nh b\xEAn tr\xE1\
    i (0 -> L-1)\n  for (int i = 0; i < L; ++i) {\n    for (auto& e : dinic.adj[i])\
    \ {\n      if (e.to >= L && e.to < L + R && e.c == 0) {\n        cout << i <<\
    \ \" \" << e.to - L << \"\\n\";\n      }\n    }\n  }\n}\n\nsigned main() {\n \
    \ ios::sync_with_stdio(false);\n  cin.tie(0);\n  int tc = 1;\n  // cin >> tc;\n\
    \  while (tc--) solve();\n}"
  dependsOn:
  - misc/macros.h
  - graph/Dinic.h
  isVerificationFile: true
  path: tests/Bipartite_Matching_Dinic.test.cpp
  requiredBy: []
  timestamp: '2025-11-28 10:18:48+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/Bipartite_Matching_Dinic.test.cpp
layout: document
redirect_from:
- /verify/tests/Bipartite_Matching_Dinic.test.cpp
- /verify/tests/Bipartite_Matching_Dinic.test.cpp.html
title: tests/Bipartite_Matching_Dinic.test.cpp
---
