---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/SCC.h
    title: graph/SCC.h
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
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "#line 1 \"tests/SCC.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\
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
    \    v.insert(v.mutable_begin(), cur);\n*/\n#line 1 \"graph/SCC.h\"\ntemplate\
    \ <class G>\nstruct SCC {\n public:\n  vector<vi> dag;\n  SCC(G& g) : g(g), used(sz(g),\
    \ 0) { build(); }\n  int operator[](int k) { return comp[k]; }\n  vi& belong(int\
    \ i) { return blng[i]; }\n\n private:\n  const G& g;\n  vector<vi> rg;\n  vi comp,\
    \ ord;\n  vector<bool> used;\n  vector<vi> blng;\n\n  void dfs(int idx) {\n  \
    \  if (used[idx]) return;\n    used[idx] = true;\n    for (auto to : g[idx]) dfs(int(to));\n\
    \    ord.eb(idx);\n  }\n  void rdfs(int idx, int cnt) {\n    if (comp[idx] !=\
    \ -1) return;\n    comp[idx] = cnt;\n    for (int to : rg[idx]) rdfs(to, cnt);\n\
    \  }\n  void build() {\n    for (int i = 0; i < sz(g); i++) dfs(i);\n    reverse(all(ord));\n\
    \    used.clear(), used.shrink_to_fit();\n    comp.resize(sz(g), -1);\n    rg.resize(sz(g));\n\
    \    for (int i = 0; i < sz(g); i++) {\n      for (auto e : g[i]) {\n        rg[e].emplace_back(i);\n\
    \      }\n    }\n    int ptr = 0;\n    for (int i : ord)\n      if (comp[i] ==\
    \ -1) rdfs(i, ptr), ptr++;\n    rg.clear(), rg.shrink_to_fit();\n    ord.clear(),\
    \ ord.shrink_to_fit();\n    dag.resize(ptr), blng.resize(ptr);\n    for (int i\
    \ = 0; i < (int) sz(g); i++) {\n      blng[comp[i]].eb(i);\n      for (auto& to\
    \ : g[i]) {\n        int x = comp[i], y = comp[to];\n        if (x == y) continue;\n\
    \        dag[x].eb(y);\n      }\n    }\n  }\n};\n#line 5 \"tests/SCC.test.cpp\"\
    \n\nvoid solve() {\n  int n, m;\n  cin >> n >> m;\n  vector<vi> g(n);\n  for (int\
    \ i = 0; i < m; ++i) {\n    int u, v;\n    cin >> u >> v;\n    g[u].eb(v);\n \
    \ }\n  SCC scc(g);\n  cout << sz(scc.dag) << '\\n';\n  for (int i = 0; i < sz(scc.dag);\
    \ ++i) {\n    cout << sz(scc.belong(i)) << ' ';\n    for (auto v : scc.belong(i))\
    \ cout << v << ' ';\n    cout << '\\n';\n  }\n}\n\nint main() {\n  solve();\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n\n#include \"../misc/macros.h\"\
    \n#include \"../graph/SCC.h\"\n\nvoid solve() {\n  int n, m;\n  cin >> n >> m;\n\
    \  vector<vi> g(n);\n  for (int i = 0; i < m; ++i) {\n    int u, v;\n    cin >>\
    \ u >> v;\n    g[u].eb(v);\n  }\n  SCC scc(g);\n  cout << sz(scc.dag) << '\\n';\n\
    \  for (int i = 0; i < sz(scc.dag); ++i) {\n    cout << sz(scc.belong(i)) << '\
    \ ';\n    for (auto v : scc.belong(i)) cout << v << ' ';\n    cout << '\\n';\n\
    \  }\n}\n\nint main() {\n  solve();\n}"
  dependsOn:
  - misc/macros.h
  - graph/SCC.h
  isVerificationFile: true
  path: tests/SCC.test.cpp
  requiredBy: []
  timestamp: '2025-11-28 02:09:51+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/SCC.test.cpp
layout: document
redirect_from:
- /verify/tests/SCC.test.cpp
- /verify/tests/SCC.test.cpp.html
title: tests/SCC.test.cpp
---
