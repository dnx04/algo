---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: ds/LineContainer.h
    title: ds/LineContainer.h
  - icon: ':question:'
    path: misc/macros.h
    title: misc/macros.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/line_add_get_min
    links:
    - https://judge.yosupo.jp/problem/line_add_get_min
  bundledCode: "#line 1 \"tests/Line_Add_Get_Min.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\
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
    \    v.insert(v.mutable_begin(), cur);\n*/\n#line 1 \"ds/LineContainer.h\"\nstruct\
    \ Line {\n  mutable i64 k, m, p;\n  bool operator<(const Line& o) const { return\
    \ k < o.k; }\n  bool operator<(i64 x) const { return p < x; }\n};\n\nstruct LineContainer\
    \ : multiset<Line, less<>> {\n  // (for lds, use inf = 1/.0, div(a,b) = a/b)\n\
    \  static const i64 inf = LLONG_MAX;\n  i64 div(i64 a, i64 b) {  // floored division\n\
    \    return a / b - ((a ^ b) < 0 && a % b);\n  }\n  bool isect(iterator x, iterator\
    \ y) {\n    if (y == end()) return x->p = inf, 0;\n    if (x->k == y->k)\n   \
    \   x->p = x->m > y->m ? inf : -inf;\n    else\n      x->p = div(y->m - x->m,\
    \ x->k - y->k);\n    return x->p >= y->p;\n  }\n  void add(i64 k, i64 m) {\n \
    \   auto z = insert({k, m, 0}), y = z++, x = y;\n    while (isect(y, z)) z = erase(z);\n\
    \    if (x != begin() && isect(--x, y)) isect(x, y = erase(y));\n    while ((y\
    \ = x) != begin() && (--x)->p >= y->p) isect(x, erase(y));\n  }\n  i64 query(i64\
    \ x) { // return max\n    assert(!empty());\n    auto l = *lower_bound(x);\n \
    \   return l.k * x + l.m;\n  }\n};\n#line 5 \"tests/Line_Add_Get_Min.test.cpp\"\
    \n\nvoid solve() {\n  int n, q;\n  cin >> n >> q;\n  LineContainer cht;\n  for\
    \ (int i = 0; i < n; ++i) {\n    i64 a, b;\n    cin >> a >> b;\n    cht.add(-a,\
    \ -b);\n  }\n  while (q--) {\n    int cmd;\n    cin >> cmd;\n    if (cmd == 0)\
    \ {\n      i64 a, b;\n      cin >> a >> b;\n      cht.add(-a, -b);\n    } else\
    \ {\n      i64 p;\n      cin >> p;\n      cout << -cht.query(p) << '\\n';\n  \
    \  }\n  }\n}\n\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n  cin.exceptions(cin.failbit);\n\
    \  int tc = 1;\n  // cin >> tc;\n  for (int i = 1; i <= tc; ++i) {\n    solve();\n\
    \  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n\n\
    #include \"../misc/macros.h\"\n#include \"../ds/LineContainer.h\"\n\nvoid solve()\
    \ {\n  int n, q;\n  cin >> n >> q;\n  LineContainer cht;\n  for (int i = 0; i\
    \ < n; ++i) {\n    i64 a, b;\n    cin >> a >> b;\n    cht.add(-a, -b);\n  }\n\
    \  while (q--) {\n    int cmd;\n    cin >> cmd;\n    if (cmd == 0) {\n      i64\
    \ a, b;\n      cin >> a >> b;\n      cht.add(-a, -b);\n    } else {\n      i64\
    \ p;\n      cin >> p;\n      cout << -cht.query(p) << '\\n';\n    }\n  }\n}\n\n\
    int main() {\n  cin.tie(0)->sync_with_stdio(0);\n  cin.exceptions(cin.failbit);\n\
    \  int tc = 1;\n  // cin >> tc;\n  for (int i = 1; i <= tc; ++i) {\n    solve();\n\
    \  }\n}"
  dependsOn:
  - misc/macros.h
  - ds/LineContainer.h
  isVerificationFile: true
  path: tests/Line_Add_Get_Min.test.cpp
  requiredBy: []
  timestamp: '2025-11-28 02:09:51+07:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: tests/Line_Add_Get_Min.test.cpp
layout: document
redirect_from:
- /verify/tests/Line_Add_Get_Min.test.cpp
- /verify/tests/Line_Add_Get_Min.test.cpp.html
title: tests/Line_Add_Get_Min.test.cpp
---
