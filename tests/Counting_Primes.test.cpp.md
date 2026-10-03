---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/Min25.h
    title: math/Min25.h
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
    PROBLEM: https://judge.yosupo.jp/problem/counting_primes
    links:
    - https://judge.yosupo.jp/problem/counting_primes
  bundledCode: "#line 1 \"tests/Counting_Primes.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/counting_primes\"\
    \n\n#line 1 \"misc/macros.h\"\n// #pragma GCC optimize(\"Ofast,unroll-loops\"\
    )       // unroll long, simple loops\n// #pragma GCC target(\"avx2,fma\")    \
    \               // vectorizing code\n// #pragma GCC target(\"lzcnt,popcnt,abm,bmi,bmi2\"\
    )  // for fast bitset operation\n\n#include <bits/extc++.h>\n\nusing namespace\
    \ std;\nusing namespace __gnu_pbds;  // ordered_set, gp_hash_table\n// using namespace\
    \ __gnu_cxx; // rope\n\n// for templates to work\n#define all(x) (x).begin(),\
    \ (x).end()\n#define len(x) (int) (x).size()\n#define pb push_back\n#define eb\
    \ emplace_back\nusing i32 = int32_t;\nusing u32 = uint32_t;\nusing i64 = int64_t;\n\
    using u64 = uint64_t;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\nusing\
    \ ld = long double;\nusing pii = pair<i32, i32>;\nusing vi = vector<i32>;\n\n\
    // fast map\nconst int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();\n\
    struct chash {  // customize hash function for gp_hash_table\n  int operator()(int\
    \ x) const { return x ^ RANDOM; }\n};\ngp_hash_table<int, int, chash> table;\n\
    \n/* ordered set\n    find_by_order(k): returns an iterator to the k-th element\
    \ (0-based)\n    order_of_key(k): returns the number of elements in the set that\
    \ are strictly less than k\n*/\ntemplate <class T>\nusing ordered_set = tree<T,\
    \ null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;\n\n/* \
    \ rope\n    rope <int> cur = v.substr(l, r - l + 1);\n    v.erase(l, r - l + 1);\n\
    \    v.insert(v.mutable_begin(), cur);\n*/\n#line 1 \"math/Min25.h\"\ntemplate\
    \ <class T>\nstruct Min25 {\n  i64 n;\n  int sq;\n  vector<int> primes, id1, id2;\n\
    \  vector<i64> vals;\n  vector<T> g0, g1;  // g0: sum p^0, g1: sum p^1\n  int\
    \ id(i64 x) { return x <= sq ? id1[x] : id2[n / x]; }\n  void init(i64 N) {\n\
    \    n = N, sq = sqrt(n);\n    primes.clear();\n    vector<bool> is_p(sq + 1,\
    \ true);\n    for (int i = 2; i <= sq; ++i) {\n      if (is_p[i]) {\n        primes.pb(i);\n\
    \        for (int j = i * 2; j <= sq; j += i) is_p[j] = false;\n      }\n    }\n\
    \    vals.clear(), id1.assign(sq + 1, 0), id2.assign(sq + 1, 0);\n    for (i64\
    \ l = 1, r; l <= n; l = r + 1) {\n      i64 v = n / l;\n      r = n / v;\n   \
    \   vals.pb(v);\n      if (v <= sq)\n        id1[v] = len(vals) - 1;\n      else\n\
    \        id2[n / v] = len(vals) - 1;\n    }\n    g0.resize(len(vals)), g1.resize(len(vals));\n\
    \    T inv2 = T(1) / T(2);\n    for (int i = 0; i < len(vals); ++i) {\n      T\
    \ v = T(vals[i]);\n      g0[i] = v - 1;\n      g1[i] = v * (v + 1) * inv2 - 1;\n\
    \    }\n    for (int p : primes) {\n      T sp0 = g0[id(p - 1)], sp1 = g1[id(p\
    \ - 1)];\n      i64 p2 = (i64) p * p;\n      T tp = T(p);\n      for (int i =\
    \ 0; i < len(vals); ++i) {\n        if (vals[i] < p2) break;\n        int k =\
    \ id(vals[i] / p);\n        g0[i] -= g0[k] - sp0;\n        g1[i] -= tp * (g1[k]\
    \ - sp1);\n      }\n    }\n  }\n  // A, B: f(p) = A*1 + B*p\n  // func: (p, e)\
    \ -> f(p^e) tr\u1EA3 v\u1EC1 T\n  template <class Func>\n  T solve(T A, T B, Func\
    \ f_pe) {\n    vector<T> s_fp(len(primes) + 1);\n    for (int i = 0; i < len(primes);\
    \ ++i)\n      s_fp[i + 1] = s_fp[i] + A + B * T(primes[i]);\n\n    auto S = [&](auto&&\
    \ self, i64 x, int j) -> T {\n      if (x <= 1 || (j < len(primes) && primes[j]\
    \ > x)) return 0;\n      int k = id(x);\n      T ans = A * g0[k] + B * g1[k];\n\
    \      ans -= s_fp[j];\n      for (int i = j; i < len(primes); ++i) {\n      \
    \  i64 p = primes[i];\n        if (p * p > x) break;\n        i64 pe = p;\n  \
    \      for (int e = 1; pe * p <= x; ++e) {\n          ans += f_pe(p, e) * self(self,\
    \ x / pe, i + 1);\n          ans += f_pe(p, e + 1);\n          pe *= p;\n    \
    \    }\n      }\n      return ans;\n    };\n    return S(S, n, 0) + 1;\n  }\n\
    };\n#line 5 \"tests/Counting_Primes.test.cpp\"\n\nvoid solve() {\n  Min25<i64>\
    \ solver;\n  i64 n;\n  cin >> n;\n  solver.init(n);\n  cout << solver.g0[solver.id(n)];\n\
    }\n\nsigned main() {\n  ios::sync_with_stdio(false);\n  cin.tie(0);\n  int tc\
    \ = 1;\n  // cin >> tc;\n  while (tc--) solve();\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/counting_primes\"\n\n#include\
    \ \"../misc/macros.h\"\n#include \"../math/Min25.h\"\n\nvoid solve() {\n  Min25<i64>\
    \ solver;\n  i64 n;\n  cin >> n;\n  solver.init(n);\n  cout << solver.g0[solver.id(n)];\n\
    }\n\nsigned main() {\n  ios::sync_with_stdio(false);\n  cin.tie(0);\n  int tc\
    \ = 1;\n  // cin >> tc;\n  while (tc--) solve();\n}"
  dependsOn:
  - misc/macros.h
  - math/Min25.h
  isVerificationFile: true
  path: tests/Counting_Primes.test.cpp
  requiredBy: []
  timestamp: '2026-10-03 15:27:40+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/Counting_Primes.test.cpp
layout: document
redirect_from:
- /verify/tests/Counting_Primes.test.cpp
- /verify/tests/Counting_Primes.test.cpp.html
title: tests/Counting_Primes.test.cpp
---
