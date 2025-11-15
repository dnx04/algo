---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/MinAssignment.h
    title: graph/MinAssignment.h
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
    PROBLEM: https://judge.yosupo.jp/problem/assignment
    links:
    - https://judge.yosupo.jp/problem/assignment
  bundledCode: "#line 1 \"tests/Assignment_Problem.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/assignment\"\n\n#line 1 \"misc/macros.h\"\n//\
    \ #ifdef LOCAL\n// #define __GLIBCXX_DEBUG 1\n// #endif\n\n// #pragma GCC optimize(\"\
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
    #endif\n#line 1 \"graph/MinAssignment.h\"\npair<ll, vector<int>> MinAssignment(const\
    \ vector<vector<ll>>& W) {\n  int n = W.size(), m = W[0].size();  // assert(n\
    \ <= m);\n  vector<ll> v(m), dist(m);           // v: potential\n  vector<int>\
    \ L(n, -1), R(m, -1);     // matching pairs\n  vector<int> idx(m), prev(m);\n\
    \  iota(idx.begin(), idx.end(), 0);\n\n  ll w, h;\n  int j, l, s, t;\n  auto reduce\
    \ = [&]() {\n    if (s == t) {\n      l = s;\n      w = dist[idx[t++]];\n    \
    \  for (int k = t; k < m; ++k) {\n        j = idx[k];\n        h = dist[j];\n\
    \        if (h > w) continue;\n        if (h < w) t = s, w = h;\n        idx[k]\
    \ = idx[t];\n        idx[t++] = j;\n      }\n      for (int k = s; k < t; ++k)\
    \ {\n        j = idx[k];\n        if (R[j] < 0) return 1;\n      }\n    }\n  \
    \  int q = idx[s++], p = R[q];\n    for (int k = t; k < m; ++k) {\n      j = idx[k];\n\
    \      h = W[p][j] - W[p][q] + v[q] - v[j] + w;\n      if (h < dist[j]) {\n  \
    \      dist[j] = h;\n        prev[j] = p;\n        if (h == w) {\n          if\
    \ (R[j] < 0) return 1;\n          idx[k] = idx[t];\n          idx[t++] = j;\n\
    \        }\n      }\n    }\n    return 0;\n  };\n  for (int i = 0; i < n; ++i)\
    \ {\n    for (int k = 0; k < m; ++k) dist[k] = W[i][k] - v[k], prev[k] = i;\n\
    \    s = t = 0;\n    while (!reduce());\n    for (int k = 0; k < l; ++k) v[idx[k]]\
    \ += dist[idx[k]] - w;\n    for (int k = -1; k != i;) R[j] = k = prev[j], swap(j,\
    \ L[k]);\n  }\n  ll ret = 0;\n  for (int i = 0; i < n; ++i) ret += W[i][L[i]];\
    \  // (i, L[i]) is a solution\n  return {ret, L};\n}\n#line 5 \"tests/Assignment_Problem.test.cpp\"\
    \n\nvoid solve() {\n  int n;\n  cin >> n;\n  vector<vector<ll>> W(n, vector<ll>(n));\n\
    \  for (int i = 0; i < n; ++i) {\n    for (int j = 0; j < n; ++j) {\n      cin\
    \ >> W[i][j];\n    }\n  }\n  auto [ret, L] = MinAssignment(W);\n  cout << ret\
    \ << '\\n';\n  for (int i = 0; i < n; ++i) cout << L[i] << ' ';\n}\n\nint main()\
    \ {\n  cin.tie(0)->sync_with_stdio(0);\n  cin.exceptions(cin.failbit);\n  int\
    \ tc = 1;\n  // cin >> tc;\n  for (int i = 1; i <= tc; ++i) {\n    solve();\n\
    \  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/assignment\"\n\n#include\
    \ \"../misc/macros.h\"\n#include \"../graph/MinAssignment.h\"\n\nvoid solve()\
    \ {\n  int n;\n  cin >> n;\n  vector<vector<ll>> W(n, vector<ll>(n));\n  for (int\
    \ i = 0; i < n; ++i) {\n    for (int j = 0; j < n; ++j) {\n      cin >> W[i][j];\n\
    \    }\n  }\n  auto [ret, L] = MinAssignment(W);\n  cout << ret << '\\n';\n  for\
    \ (int i = 0; i < n; ++i) cout << L[i] << ' ';\n}\n\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n\
    \  cin.exceptions(cin.failbit);\n  int tc = 1;\n  // cin >> tc;\n  for (int i\
    \ = 1; i <= tc; ++i) {\n    solve();\n  }\n}\n"
  dependsOn:
  - misc/macros.h
  - graph/MinAssignment.h
  isVerificationFile: true
  path: tests/Assignment_Problem.test.cpp
  requiredBy: []
  timestamp: '2025-11-15 18:26:28+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/Assignment_Problem.test.cpp
layout: document
redirect_from:
- /verify/tests/Assignment_Problem.test.cpp
- /verify/tests/Assignment_Problem.test.cpp.html
title: tests/Assignment_Problem.test.cpp
---
