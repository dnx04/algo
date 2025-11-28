---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/Fenwick.h
    title: ds/Fenwick.h
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
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"tests/Point_Add_Range_Sum.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/point_add_range_sum\"\n\n#line 1 \"misc/macros.h\"\
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
    \    v.insert(v.mutable_begin(), cur);\n*/\n#line 1 \"ds/Fenwick.h\"\ntemplate\
    \ <class T>\nstruct Fenwick {  // 1-indexed\n  int n;\n  vector<T> t;\n  Fenwick(int\
    \ n) : n(n), t(n + 1, T(0)) {}\n  void add(int p, T v) {\n    while (p <= n) t[p]\
    \ += v, p += (p & -p);\n  }\n  T sum(int p) {\n    T res = 0;\n    while (p) res\
    \ += t[p], p -= (p & -p);\n    return res;\n  }\n  // [l, r)\n  T sum(int l, int\
    \ r) {\n    if (l > r) return T(0);\n    return sum(r) - sum(l - 1);\n  }\n};\n\
    #line 5 \"tests/Point_Add_Range_Sum.test.cpp\"\n\nvoid solve() {\n  int n, q;\n\
    \  cin >> n >> q;\n  Fenwick<i64> fw(n);\n  for (int i = 1; i <= n; ++i) {\n \
    \   i64 x;\n    cin >> x;\n    fw.add(i, x);\n  }\n  while (q--) {\n    int cmd;\n\
    \    cin >> cmd;\n    if (cmd == 0) {\n      int p, x;\n      cin >> p >> x;\n\
    \      ++p;\n      fw.add(p, x);\n    } else {\n      int l, r;\n      cin >>\
    \ l >> r;\n      ++l;\n      cout << fw.sum(l, r) << '\\n';\n    }\n  }\n}\n\n\
    int main() {\n  cin.tie(0)->sync_with_stdio(0);\n  cin.exceptions(cin.failbit);\n\
    \  int tc = 1;\n  // cin >> tc;\n  for (int i = 1; i <= tc; ++i) {\n    solve();\n\
    \  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include \"../misc/macros.h\"\n#include \"../ds/Fenwick.h\"\n\nvoid solve()\
    \ {\n  int n, q;\n  cin >> n >> q;\n  Fenwick<i64> fw(n);\n  for (int i = 1; i\
    \ <= n; ++i) {\n    i64 x;\n    cin >> x;\n    fw.add(i, x);\n  }\n  while (q--)\
    \ {\n    int cmd;\n    cin >> cmd;\n    if (cmd == 0) {\n      int p, x;\n   \
    \   cin >> p >> x;\n      ++p;\n      fw.add(p, x);\n    } else {\n      int l,\
    \ r;\n      cin >> l >> r;\n      ++l;\n      cout << fw.sum(l, r) << '\\n';\n\
    \    }\n  }\n}\n\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n  cin.exceptions(cin.failbit);\n\
    \  int tc = 1;\n  // cin >> tc;\n  for (int i = 1; i <= tc; ++i) {\n    solve();\n\
    \  }\n}\n"
  dependsOn:
  - misc/macros.h
  - ds/Fenwick.h
  isVerificationFile: true
  path: tests/Point_Add_Range_Sum.test.cpp
  requiredBy: []
  timestamp: '2025-11-28 02:09:51+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/Point_Add_Range_Sum.test.cpp
layout: document
redirect_from:
- /verify/tests/Point_Add_Range_Sum.test.cpp
- /verify/tests/Point_Add_Range_Sum.test.cpp.html
title: tests/Point_Add_Range_Sum.test.cpp
---
