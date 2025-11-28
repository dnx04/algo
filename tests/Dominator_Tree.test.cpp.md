---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/Dominator.h
    title: graph/Dominator.h
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
    PROBLEM: https://judge.yosupo.jp/problem/dominatortree
    links:
    - https://judge.yosupo.jp/problem/dominatortree
  bundledCode: "#line 1 \"tests/Dominator_Tree.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/dominatortree\"\
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
    \    v.insert(v.mutable_begin(), cur);\n*/\n#line 1 \"graph/Dominator.h\"\nvector<int>\
    \ DomTree(const vector<vi>& g, int s) {\n  int n = sz(g), t = 0;\n  vector<int>\
    \ arr(n, -1), rev(n), par(n), sdom(n), dom(n), dsu(n), lab(n), res(n, -1);\n \
    \ vector<vi> rg(n), buck(n);\n  auto dfs = [&](auto&& self, int u) -> void {\n\
    \    arr[u] = t, rev[t] = u, lab[t] = sdom[t] = dsu[t] = t, t++;\n    for (int\
    \ v : g[u]) {\n      if (arr[v] == -1) self(self, v), par[arr[v]] = arr[u];\n\
    \      rg[arr[v]].pb(arr[u]);\n    }\n  };\n  dfs(dfs, s);\n  auto find = [&](auto&&\
    \ self, int u) -> int {\n    if (u == dsu[u]) return u;\n    int v = self(self,\
    \ dsu[u]);\n    if (sdom[lab[dsu[u]]] < sdom[lab[u]]) lab[u] = lab[dsu[u]];\n\
    \    return dsu[u] = v;\n  };\n  for (int i = t - 1; i; --i) {\n    for (int v\
    \ : rg[i]) find(find, v), sdom[i] = min(sdom[i], sdom[lab[v]]);\n    buck[sdom[i]].pb(i);\n\
    \    int p = par[i]; dsu[i] = p;\n    for (int v : buck[p]) find(find, v), dom[v]\
    \ = (sdom[lab[v]] == sdom[v] ? p : lab[v]);\n    buck[p].clear();\n  }\n  for\
    \ (int i = 1; i < t; ++i) {\n    if (dom[i] != sdom[i]) dom[i] = dom[dom[i]];\n\
    \    res[rev[i]] = rev[dom[i]];\n  }\n  return res;\n}\n#line 5 \"tests/Dominator_Tree.test.cpp\"\
    \n\nvoid solve() {\n  int n, m, s;\n  cin >> n >> m >> s;\n  vector<vi> g(n);\n\
    \  for (int i = 0; i < m; ++i) {\n    int u, v;\n    cin >> u >> v;\n    g[u].pb(v);\n\
    \  }\n  auto tree = DomTree(g, s);\n  tree[s] = s;\n  for (int i = 0; i < n; ++i)\
    \ cout << tree[i] << ' ';\n}\n\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n\
    \  cin.exceptions(cin.failbit);\n  int tc = 1;\n  // cin >> tc;\n  for (int i\
    \ = 1; i <= tc; ++i) {\n    solve();\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/dominatortree\"\n\n#include\
    \ \"../misc/macros.h\"\n#include \"../graph/Dominator.h\"\n\nvoid solve() {\n\
    \  int n, m, s;\n  cin >> n >> m >> s;\n  vector<vi> g(n);\n  for (int i = 0;\
    \ i < m; ++i) {\n    int u, v;\n    cin >> u >> v;\n    g[u].pb(v);\n  }\n  auto\
    \ tree = DomTree(g, s);\n  tree[s] = s;\n  for (int i = 0; i < n; ++i) cout <<\
    \ tree[i] << ' ';\n}\n\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n  cin.exceptions(cin.failbit);\n\
    \  int tc = 1;\n  // cin >> tc;\n  for (int i = 1; i <= tc; ++i) {\n    solve();\n\
    \  }\n}\n"
  dependsOn:
  - misc/macros.h
  - graph/Dominator.h
  isVerificationFile: true
  path: tests/Dominator_Tree.test.cpp
  requiredBy: []
  timestamp: '2025-11-28 02:09:51+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/Dominator_Tree.test.cpp
layout: document
redirect_from:
- /verify/tests/Dominator_Tree.test.cpp
- /verify/tests/Dominator_Tree.test.cpp.html
title: tests/Dominator_Tree.test.cpp
---
