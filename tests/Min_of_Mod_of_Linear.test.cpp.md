---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/DivModSum.h
    title: math/DivModSum.h
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
    PROBLEM: https://judge.yosupo.jp/problem/min_of_mod_of_linear
    links:
    - https://judge.yosupo.jp/problem/min_of_mod_of_linear
  bundledCode: "#line 1 \"tests/Min_of_Mod_of_Linear.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/min_of_mod_of_linear\"\n\n#line 1 \"misc/macros.h\"\
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
    \    v.insert(v.mutable_begin(), cur);\n*/\n#line 1 \"math/DivModSum.h\"\n// T\xED\
    nh sum_{x=0}^{n-1} floor((a*x + b) / m)\nu64 divsum(u64 n, u64 m, i64 a, i64 b)\
    \ {\n  u64 ans = 0;\n  if (a < 0) {\n    i64 a2 = (a % (i64) m + m) % m;\n   \
    \ ans -= 1ULL * n * (n - 1) / 2 * ((a2 - a) / m), a = a2;\n  }\n  if (b < 0) {\n\
    \    i64 b2 = (b % (i64) m + m) % m;\n    ans -= 1ULL * n * ((b2 - b) / m), b\
    \ = b2;\n  }\n  u64 ua = a, ub = b;\n  while (true) {\n    if (ua >= m) ans +=\
    \ (n - 1) * n / 2 * (ua / m), ua %= m;\n    if (ub >= m) ans += n * (ub / m),\
    \ ub %= m;\n    u64 y_max = ua * n + ub;\n    if (y_max < m) break;\n    n = y_max\
    \ / m, ub = y_max % m, swap(m, ua);\n  }\n  return ans;\n}\n\n// T\xEDnh sum_{x=0}^{n-1}\
    \ ((a*x + b) % m)\nu64 modsum(u64 n, u64 m, i64 a, i64 b) {\n  i128 sum = (i128)\
    \ a * n * (n - 1) / 2 + (i128) b * n;\n  return (u64) (sum - (i128) m * divsum(n,\
    \ m, a, b));\n}\n\n// T\xEDnh min_{x=0}^{n-1} ((a*x + b) % m)\ni64 minmod(u64\
    \ n, u64 m, i64 a, i64 b) {\n  i64 lo = 0, hi = m - 1, ans = b;\n  while (lo <=\
    \ hi) {\n    auto mid = (lo + hi) / 2;\n    auto cnt = divsum(n, m, a, b) - divsum(n,\
    \ m, a, b - mid - 1);\n    if (cnt > 0) ans = mid, hi = mid - 1;\n    else lo\
    \ = mid + 1;\n  }\n  return ans;\n}\n#line 5 \"tests/Min_of_Mod_of_Linear.test.cpp\"\
    \n\nvoid solve() {\n  int n, m, a, b;\n  cin >> n >> m >> a >> b;\n  cout << minmod(n,\
    \ m, a, b) << '\\n';\n}\n\nsigned main() {\n  ios::sync_with_stdio(false);\n \
    \ cin.tie(0);\n  int tc;\n  cin >> tc;\n  while (tc--) solve();\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/min_of_mod_of_linear\"\n\
    \n#include \"../misc/macros.h\"\n#include \"../math/DivModSum.h\"\n\nvoid solve()\
    \ {\n  int n, m, a, b;\n  cin >> n >> m >> a >> b;\n  cout << minmod(n, m, a,\
    \ b) << '\\n';\n}\n\nsigned main() {\n  ios::sync_with_stdio(false);\n  cin.tie(0);\n\
    \  int tc;\n  cin >> tc;\n  while (tc--) solve();\n}"
  dependsOn:
  - misc/macros.h
  - math/DivModSum.h
  isVerificationFile: true
  path: tests/Min_of_Mod_of_Linear.test.cpp
  requiredBy: []
  timestamp: '2025-11-28 02:09:51+07:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: tests/Min_of_Mod_of_Linear.test.cpp
layout: document
redirect_from:
- /verify/tests/Min_of_Mod_of_Linear.test.cpp
- /verify/tests/Min_of_Mod_of_Linear.test.cpp.html
title: tests/Min_of_Mod_of_Linear.test.cpp
---
