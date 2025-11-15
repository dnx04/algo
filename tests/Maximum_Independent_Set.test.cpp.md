---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: misc/MaximumClique.h
    title: misc/MaximumClique.h
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
    PROBLEM: https://judge.yosupo.jp/problem/maximum_independent_set
    links:
    - https://judge.yosupo.jp/problem/maximum_independent_set
  bundledCode: "#line 1 \"tests/Maximum_Independent_Set.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/maximum_independent_set\"\n\n#line 1 \"misc/macros.h\"\
    \n// #ifdef LOCAL\n// #define __GLIBCXX_DEBUG 1\n// #endif\n\n// #pragma GCC optimize(\"\
    Ofast,unroll-loops\")       // unroll long, simple loops\n// #pragma GCC target(\"\
    avx2,fma\")                   // vectorizing code\n// #pragma GCC target(\"lzcnt,popcnt,abm,bmi,bmi2\"\
    )  // for fast bitset operation\n\n#include <bits/extc++.h>\n\n#include <tr2/dynamic_bitset>\n\
    \nusing namespace std;\nusing namespace __gnu_pbds;  // ordered_set, gp_hash_table\n\
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
    #endif\n#line 1 \"misc/MaximumClique.h\"\nstruct Maxclique {\n  double limit =\
    \ 0.025, pk = 0;\n  struct Vertex {\n    int i, d = 0;\n  };\n  typedef vector<Vertex>\
    \ vv;\n  vector<bs> e;\n  vv V;\n  vector<vi> C;\n  vi qmax, q, S, old;  // qmax\
    \ = vertices in maximum clique, q = current clique\n  void init(vv& r) {\n   \
    \ for (auto& v : r) v.d = 0;\n    for (auto& v : r) {\n      for (auto j : r)\
    \ v.d += e[v.i][j.i];\n    }\n    sort(all(r), [](auto a, auto b) { return a.d\
    \ > b.d; });\n    int mxD = r[0].d;\n    for (int i = 0; i < sz(r); ++i) r[i].d\
    \ = min(i, mxD) + 1;\n  }\n  void expand(vv& R, int lev = 1) {\n    S[lev] +=\
    \ S[lev - 1] - old[lev];\n    old[lev] = S[lev - 1];\n    while (sz(R)) {\n  \
    \    if (sz(q) + R.back().d <= sz(qmax)) return;\n      q.push_back(R.back().i);\n\
    \      vv T;\n      for (auto v : R)\n        if (e[R.back().i][v.i]) T.push_back({v.i});\n\
    \      if (sz(T)) {\n        if (S[lev]++ / ++pk < limit) init(T);\n        int\
    \ j = 0, mxk = 1, mnk = max(sz(qmax) - sz(q) + 1, 1);\n        C[1].clear(), C[2].clear();\n\
    \        for (auto v : T) {\n          int k = 1;\n          auto f = [&](int\
    \ i) { return e[v.i][i]; };\n          while (any_of(all(C[k]), f)) k++;\n   \
    \       if (k > mxk) mxk = k, C[mxk + 1].clear();\n          if (k < mnk) T[j++].i\
    \ = v.i;\n          C[k].push_back(v.i);\n        }\n        if (j > 0) T[j -\
    \ 1].d = 0;\n        for (int k = mnk; k <= mxk; ++k) {\n          for (int i\
    \ : C[k]) T[j].i = i, T[j++].d = k;\n        }\n        expand(T, lev + 1);\n\
    \      } else if (sz(q) > sz(qmax))\n        qmax = q;\n      q.pop_back(), R.pop_back();\n\
    \    }\n  }\n  vi maxClique() {\n    init(V), expand(V);\n    return qmax;\n \
    \ }\n  Maxclique(vector<bs> conn) : e(conn), C(sz(e) + 1), S(sz(C)), old(S) {\n\
    \    for (int i = 0; i < sz(e); ++i) V.push_back({i});\n  }\n};\n#line 5 \"tests/Maximum_Independent_Set.test.cpp\"\
    \n\nsigned main() {\n  cin.tie(0)->sync_with_stdio(0);\n  cin.exceptions(cin.failbit);\n\
    \  int n, m;\n  cin >> n >> m;\n  vector<bs> eds(n, bs(n));\n  for (int i = 0;\
    \ i < m; ++i) {\n    int u, v;\n    cin >> u >> v;\n    eds[u][v] = eds[v][u]\
    \ = 1;\n  }\n  for (int i = 0; i < n; ++i) {\n    eds[i].flip();\n    eds[i][i]\
    \ = 0;\n  }\n  Maxclique mc(eds);\n  auto ans = mc.maxClique();\n  cout << sz(ans)\
    \ << '\\n';\n  for (auto i : mc.qmax) cout << i << ' ';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/maximum_independent_set\"\
    \n\n#include \"../misc/macros.h\"\n#include \"../misc/MaximumClique.h\"\n\nsigned\
    \ main() {\n  cin.tie(0)->sync_with_stdio(0);\n  cin.exceptions(cin.failbit);\n\
    \  int n, m;\n  cin >> n >> m;\n  vector<bs> eds(n, bs(n));\n  for (int i = 0;\
    \ i < m; ++i) {\n    int u, v;\n    cin >> u >> v;\n    eds[u][v] = eds[v][u]\
    \ = 1;\n  }\n  for (int i = 0; i < n; ++i) {\n    eds[i].flip();\n    eds[i][i]\
    \ = 0;\n  }\n  Maxclique mc(eds);\n  auto ans = mc.maxClique();\n  cout << sz(ans)\
    \ << '\\n';\n  for (auto i : mc.qmax) cout << i << ' ';\n}\n"
  dependsOn:
  - misc/macros.h
  - misc/MaximumClique.h
  isVerificationFile: true
  path: tests/Maximum_Independent_Set.test.cpp
  requiredBy: []
  timestamp: '2025-11-15 18:26:28+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/Maximum_Independent_Set.test.cpp
layout: document
redirect_from:
- /verify/tests/Maximum_Independent_Set.test.cpp
- /verify/tests/Maximum_Independent_Set.test.cpp.html
title: tests/Maximum_Independent_Set.test.cpp
---
