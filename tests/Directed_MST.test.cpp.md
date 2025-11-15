---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/DirectedMST.h
    title: graph/DirectedMST.h
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
    PROBLEM: https://judge.yosupo.jp/problem/directedmst
    links:
    - https://judge.yosupo.jp/problem/directedmst
  bundledCode: "#line 1 \"tests/Directed_MST.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/directedmst\"\
    \n\n#line 1 \"misc/macros.h\"\n// #ifdef LOCAL\n// #define __GLIBCXX_DEBUG 1\n\
    // #endif\n\n// #pragma GCC optimize(\"Ofast,unroll-loops\")       // unroll long,\
    \ simple loops\n// #pragma GCC target(\"avx2,fma\")                   // vectorizing\
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
    #endif\n#line 1 \"graph/DirectedMST.h\"\nstruct DSU {\n  vector<int> link;\n \
    \ DSU(int n) : link(n, -1) {}\n  int Find(int x) { return link[x] == -1 ? x :\
    \ link[x] = Find(link[x]); }\n};\n\nstruct SkewHeap {\n  struct Node { ll key,\
    \ lazy = 0; int l = -1, r = -1; };\n  vector<Node> T;\n\n  void push(int x) {\n\
    \    if (x == -1 || !T[x].lazy) return;\n    for (int y : {T[x].l, T[x].r}) if\
    \ (y != -1) \n      T[y].lazy += T[x].lazy;\n    T[x].key += T[x].lazy, T[x].lazy\
    \ = 0;\n  }\n  // Make new node. Returns its index. Indexes go 0, 1, ...\n  int\
    \ New(ll key) { \n    T.push_back(Node{key}); \n    return (int)T.size() - 1;\n\
    \  }\n  // Increment all values in heap p by v\n  void Add(int x, ll v) { if (~x)\
    \ T[x].lazy += v, push(x); }\n  // Merge heaps a and b\n  int Merge(int a, int\
    \ b) {\n    if (b == -1 || a == -1) return a + b + 1;\n    if (T[a].key > T[b].key)\
    \ swap(a, b);\n    int &l = T[a].l, &r = T[a].r;\n    push(r); swap(l, r); l =\
    \ Merge(l, b);\n    return a;\n  }\n  void Pop(int& x) { x = Merge(T[x].l, T[x].r);\
    \ }\n  ll Get(int x) { return T[x].key; }\n};\n\nstruct Edge { int a, b; ll c;\
    \ }; \n\npair<ll, vector<int>> DMST(int n, int src, vector<Edge> es) {\n  // Compress\
    \ graph - O(M logN)\n  SkewHeap H; DSU D(2 * n); int x = 0;\n  vector<int> par(2\
    \ * n, -1), ins(par), vis(par);\n  for (auto e : es) ins[e.b] = H.Merge(ins[e.b],\
    \ H.New(e.c));\n  auto go = [&](int x) { return D.Find(es[ins[x]].a); };\n  for\
    \ (int i = n; ins[x] != -1; ++i) {\n    for (; vis[x] == -1; x = go(x)) vis[x]\
    \ = 0;\n    for (; x != i; x = go(x)) {\n      int rem = ins[x]; ll w = H.Get(rem);\
    \ H.Pop(rem);\n      H.Add(rem, -w); ins[i] = H.Merge(ins[i], rem);\n      par[x]\
    \ = i; D.link[x] = i;\n    }\n    for (; ins[x] != -1 && go(x) == x; H.Pop(ins[x]));\n\
    \  }\n  // Expand graph - O(N)\n  ll cost = 0; vector<int> ans;\n  for (int i\
    \ = src; i != -1; i = par[i]) vis[i] = 1;\n  for (int i = x; i >= 0; --i) {\n\
    \    if (vis[i]) continue;\n    cost += es[ins[i]].c; ans.push_back(ins[i]);\n\
    \    for (int j = es[ins[i]].b; j != -1 && !vis[j]; j = par[j]) \n      vis[j]\
    \ = 1;\n  }\n  return {cost, ans};\n}\n#line 5 \"tests/Directed_MST.test.cpp\"\
    \n\nvoid solve() {\n  int n, m, s;\n  cin >> n >> m >> s;\n  vector<Edge> edges;\n\
    \  for (int i = 0; i < m; ++i) {\n    int a, b;\n    ll w;\n    cin >> a >> b\
    \ >> w;\n    edges.push_back({a, b, w});\n  }\n  for (int i = 0; i < n; i++) {\n\
    \    if (i != s) edges.push_back({i, s, 0});\n  }\n  auto [res, par] = DMST(n,\
    \ s, edges);\n  vi ans(n);\n  ans[s] = s;\n  for (auto i : par) {\n    ans[edges[i].b]\
    \ = edges[i].a;\n  }\n  cout << res << '\\n';\n  if (res != -1) {\n    for (auto\
    \ x : ans) cout << x << ' ';\n  }\n  // if (res == -1) {\n  //   cout << \"NO\\\
    n\";\n  // } else {\n  //   cout << \"YES\\n\";\n  //   for(int i = 0; i < n;\
    \ ++i) {\n  //     if (i == s) continue;\n  //     cout << par[i] << '\\n';\n\
    \  //   }\n  // }\n}\n\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n  cin.exceptions(cin.failbit);\n\
    \  int tc = 1;\n  // cin >> tc;\n  for (int i = 1; i <= tc; ++i) {\n    solve();\n\
    \  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/directedmst\"\n\n#include\
    \ \"../misc/macros.h\"\n#include \"../graph/DirectedMST.h\"\n\nvoid solve() {\n\
    \  int n, m, s;\n  cin >> n >> m >> s;\n  vector<Edge> edges;\n  for (int i =\
    \ 0; i < m; ++i) {\n    int a, b;\n    ll w;\n    cin >> a >> b >> w;\n    edges.push_back({a,\
    \ b, w});\n  }\n  for (int i = 0; i < n; i++) {\n    if (i != s) edges.push_back({i,\
    \ s, 0});\n  }\n  auto [res, par] = DMST(n, s, edges);\n  vi ans(n);\n  ans[s]\
    \ = s;\n  for (auto i : par) {\n    ans[edges[i].b] = edges[i].a;\n  }\n  cout\
    \ << res << '\\n';\n  if (res != -1) {\n    for (auto x : ans) cout << x << '\
    \ ';\n  }\n  // if (res == -1) {\n  //   cout << \"NO\\n\";\n  // } else {\n \
    \ //   cout << \"YES\\n\";\n  //   for(int i = 0; i < n; ++i) {\n  //     if (i\
    \ == s) continue;\n  //     cout << par[i] << '\\n';\n  //   }\n  // }\n}\n\n\
    int main() {\n  cin.tie(0)->sync_with_stdio(0);\n  cin.exceptions(cin.failbit);\n\
    \  int tc = 1;\n  // cin >> tc;\n  for (int i = 1; i <= tc; ++i) {\n    solve();\n\
    \  }\n}\n"
  dependsOn:
  - misc/macros.h
  - graph/DirectedMST.h
  isVerificationFile: true
  path: tests/Directed_MST.test.cpp
  requiredBy: []
  timestamp: '2025-11-15 18:26:28+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/Directed_MST.test.cpp
layout: document
redirect_from:
- /verify/tests/Directed_MST.test.cpp
- /verify/tests/Directed_MST.test.cpp.html
title: tests/Directed_MST.test.cpp
---
