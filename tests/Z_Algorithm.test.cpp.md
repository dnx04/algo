---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: misc/macros.h
    title: misc/macros.h
  - icon: ':x:'
    path: strings/Z.h
    title: strings/Z.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"tests/Z_Algorithm.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\
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
    \    v.insert(v.mutable_begin(), cur);\n*/\n#line 1 \"strings/Z.h\"\nvi Z(const\
    \ string& S) {\n  vi z(sz(S));\n  int l = -1, r = -1;\n  for (int i = 1; i < sz(S);\
    \ ++i) {\n    z[i] = i >= r ? 0 : min(r - i, z[i - l]);\n    while (i + z[i] <\
    \ sz(S) && S[i + z[i]] == S[z[i]]) z[i]++;\n    if (i + z[i] > r) l = i, r = i\
    \ + z[i];\n  }\n  return z;\n}\n#line 5 \"tests/Z_Algorithm.test.cpp\"\n\nvoid\
    \ solve() {\n  string s;\n  cin >> s;\n  auto z = Z(s);\n  cout << sz(s) << '\
    \ ';\n  for (int i = 1; i < sz(z); ++i) cout << z[i] << ' ';\n}\n\nint main()\
    \ {\n  cin.tie(0)->sync_with_stdio(0);\n  cin.exceptions(cin.failbit);\n  int\
    \ tc = 1;\n  // cin >> tc;\n  for (int i = 1; i <= tc; ++i) {\n    solve();\n\
    \  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n\n#include\
    \ \"../misc/macros.h\"\n#include \"../strings/Z.h\"\n\nvoid solve() {\n  string\
    \ s;\n  cin >> s;\n  auto z = Z(s);\n  cout << sz(s) << ' ';\n  for (int i = 1;\
    \ i < sz(z); ++i) cout << z[i] << ' ';\n}\n\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n\
    \  cin.exceptions(cin.failbit);\n  int tc = 1;\n  // cin >> tc;\n  for (int i\
    \ = 1; i <= tc; ++i) {\n    solve();\n  }\n}\n"
  dependsOn:
  - misc/macros.h
  - strings/Z.h
  isVerificationFile: true
  path: tests/Z_Algorithm.test.cpp
  requiredBy: []
  timestamp: '2025-11-28 00:00:09+07:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: tests/Z_Algorithm.test.cpp
layout: document
redirect_from:
- /verify/tests/Z_Algorithm.test.cpp
- /verify/tests/Z_Algorithm.test.cpp.html
title: tests/Z_Algorithm.test.cpp
---
