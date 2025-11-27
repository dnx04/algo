---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/XorBasis.h
    title: math/XorBasis.h
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
    PROBLEM: https://judge.yosupo.jp/problem/intersection_of_f2_vector_spaces
    links:
    - https://judge.yosupo.jp/problem/intersection_of_f2_vector_spaces
  bundledCode: "#line 1 \"tests/Intersection_of_F2_vector_spaces.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/intersection_of_f2_vector_spaces\"\
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
    \    v.insert(v.mutable_begin(), cur);\n*/\n#line 1 \"math/XorBasis.h\"\nstruct\
    \ XorBasis {\n  vector<i64> b;\n  XorBasis() {}\n  void add(int x) {\n    x =\
    \ this->sift(x);\n    if (x != 0) this->b.pb(x);\n  }\n  i64 sift(i64 x) const\
    \ {\n    for (i64 b : this->b) {\n      x = min(x, x ^ b);\n      if (x == 0)\
    \ return 0;\n    }\n    return x;\n  }\n  bool is_indep(i64 x) const {\n    return\
    \ this->sift(x) != 0;\n  }\n  vector<i64> basis() const {\n    return this->b;\n\
    \  }\n};\n\nvector<i64> XorInter(const vector<i64>& u, const vector<i64>& v) {\n\
    \  XorBasis X;\n  for (auto x : u) X.add(x);\n  vector<pair<i64, i64>> basis;\n\
    \  XorBasis inter;\n  for (auto x : v) {\n    auto y = X.sift(x), pu = y ^ x,\
    \ sy = y;\n    for (auto v : basis) {\n      i64 tmp = sy ^ v.second;\n      if\
    \ (tmp < sy) {\n        sy = tmp;\n        pu ^= v.first;\n      }\n    }\n  \
    \  if (sy != 0) {\n      basis.pb({pu, sy});\n    } else {\n      inter.add(pu);\n\
    \    }\n  }\n  return inter.basis();\n}\n#line 5 \"tests/Intersection_of_F2_vector_spaces.test.cpp\"\
    \n\nsigned main() {\n  ios::sync_with_stdio(false);\n  cin.tie(0);\n  int tc;\n\
    \  cin >> tc;\n  while (tc--) {\n    vector<vector<i64>> basis(2);\n    for (int\
    \ i : {0, 1}) {\n      int s;\n      cin >> s;\n      basis[i].resize(s);\n  \
    \    for (auto& x : basis[i]) cin >> x;\n    }\n    auto xi = XorInter(basis[0],\
    \ basis[1]);\n    cout << sz(xi) << ' ';\n    for (auto v : xi) cout << v << '\
    \ ';\n    cout << '\\n';\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/intersection_of_f2_vector_spaces\"\
    \n\n#include \"../misc/macros.h\"\n#include \"../math/XorBasis.h\"\n\nsigned main()\
    \ {\n  ios::sync_with_stdio(false);\n  cin.tie(0);\n  int tc;\n  cin >> tc;\n\
    \  while (tc--) {\n    vector<vector<i64>> basis(2);\n    for (int i : {0, 1})\
    \ {\n      int s;\n      cin >> s;\n      basis[i].resize(s);\n      for (auto&\
    \ x : basis[i]) cin >> x;\n    }\n    auto xi = XorInter(basis[0], basis[1]);\n\
    \    cout << sz(xi) << ' ';\n    for (auto v : xi) cout << v << ' ';\n    cout\
    \ << '\\n';\n  }\n}"
  dependsOn:
  - misc/macros.h
  - math/XorBasis.h
  isVerificationFile: true
  path: tests/Intersection_of_F2_vector_spaces.test.cpp
  requiredBy: []
  timestamp: '2025-11-28 02:09:51+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/Intersection_of_F2_vector_spaces.test.cpp
layout: document
redirect_from:
- /verify/tests/Intersection_of_F2_vector_spaces.test.cpp
- /verify/tests/Intersection_of_F2_vector_spaces.test.cpp.html
title: tests/Intersection_of_F2_vector_spaces.test.cpp
---
