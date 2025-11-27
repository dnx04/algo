---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/Dominator.h
    title: graph/Dominator.h
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
    PROBLEM: https://judge.yosupo.jp/problem/dominatortree
    links:
    - https://judge.yosupo.jp/problem/dominatortree
  bundledCode: "#line 1 \"tests/Dominator_Tree.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/dominatortree\"\
    \n\n#line 1 \"misc/macros.h\"\n// #pragma GCC optimize(\"Ofast,unroll-loops\"\
    )       // unroll long, simple loops\n// #pragma GCC target(\"avx2,fma\")    \
    \               // vectorizing code\n// #pragma GCC target(\"lzcnt,popcnt,abm,bmi,bmi2\"\
    )  // for fast bitset operation\n\n#include <bits/extc++.h>\n\nusing namespace\
    \ std;\nusing namespace __gnu_pbds;  // ordered_set, gp_hash_table\n// using namespace\
    \ __gnu_cxx; // rope\n\n// for templates to work\n#define all(s) s.begin(), s.end()\n\
    #define sz(x) (int) (x).size()\n#define pb push_back\n#define eb emplace_back\n\
    using i32 = int32_t;\nusing u32 = uint32_t;\nusing i64 = int64_t;\nusing u64 =\
    \ uint64_t;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\nusing ld = long\
    \ double;\nusing pii = pair<i32, i32>;\nusing vi = vector<i32>;\n\n// fast map\n\
    const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();\n\
    struct chash {  // customize hash function for gp_hash_table\n  int operator()(int\
    \ x) const { return x ^ RANDOM; }\n};\ngp_hash_table<int, int, chash> table;\n\
    \n/* ordered set\n    find_by_order(k): returns an iterator to the k-th element\
    \ (0-based)\n    order_of_key(k): returns the number of elements in the set that\
    \ are strictly less than k\n*/\ntemplate <class T>\nusing ordered_set = tree<T,\
    \ null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;\n\n/* \
    \ rope\n    rope <int> cur = v.substr(l, r - l + 1);\n    v.erase(l, r - l + 1);\n\
    \    v.insert(v.mutable_begin(), cur);\n*/\n#line 1 \"graph/Dominator.h\"\nvector<int>\
    \ DomTree(vector<vector<int>>& graph, int src) {\n  int n = graph.size();\n  vector<vector<int>>\
    \ tree(n), trans(n), buck(n);\n  vector<int> semi(n), par(n), dom(n), label(n),\
    \ atob(n, -1), btoa(n, -1), link(n, -1);\n\n  function<int(int, int)> find = [&](int\
    \ u, int d) {\n    if (link[u] == -1) return d ? -1 : u;\n    int v = find(link[u],\
    \ d + 1);\n    if (v < 0) return u;\n    if (semi[label[link[u]]] < semi[label[u]])\
    \ label[u] = label[link[u]];\n    link[u] = v;\n    return d ? v : label[u];\n\
    \  };\n  int t = 0;\n  function<void(int)> dfs = [&](int u) {\n    atob[u] = t;\n\
    \    btoa[t] = u;\n    label[t] = semi[t] = t;\n    t++;\n    for (auto v : graph[u])\
    \ {\n      if (atob[v] == -1) dfs(v), par[atob[v]] = atob[u];\n      trans[atob[v]].push_back(atob[u]);\n\
    \    }\n  };\n  dfs(src);\n  for (int u = t - 1; u >= 0; --u) {\n    for (auto\
    \ v : trans[u]) semi[u] = min(semi[u], semi[find(v, 0)]);\n    if (u) buck[semi[u]].push_back(u);\n\
    \    for (auto w : buck[u]) {\n      int v = find(w, 0);\n      dom[w] = semi[v]\
    \ == semi[w] ? semi[w] : v;\n    }\n    if (u) link[u] = par[u];\n  }\n  vector<int>\
    \ ret(n, -1);\n  for (int u = 1; u < t; ++u) {\n    if (dom[u] != semi[u]) dom[u]\
    \ = dom[dom[u]];\n    ret[btoa[u]] = btoa[dom[u]];\n  }\n  return ret;\n}\n#line\
    \ 5 \"tests/Dominator_Tree.test.cpp\"\n\nvoid solve() {\n  int n, m, s;\n  cin\
    \ >> n >> m >> s;\n  vector<vi> g(n);\n  for (int i = 0; i < m; ++i) {\n    int\
    \ u, v;\n    cin >> u >> v;\n    g[u].pb(v);\n  }\n  auto tree = DomTree(g, s);\n\
    \  tree[s] = s;\n  for (int i = 0; i < n; ++i) cout << tree[i] << ' ';\n}\n\n\
    int main() {\n  cin.tie(0)->sync_with_stdio(0);\n  cin.exceptions(cin.failbit);\n\
    \  int tc = 1;\n  // cin >> tc;\n  for (int i = 1; i <= tc; ++i) {\n    solve();\n\
    \  }\n}\n"
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
  timestamp: '2025-11-28 00:00:09+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/Dominator_Tree.test.cpp
layout: document
redirect_from:
- /verify/tests/Dominator_Tree.test.cpp
- /verify/tests/Dominator_Tree.test.cpp.html
title: tests/Dominator_Tree.test.cpp
---
