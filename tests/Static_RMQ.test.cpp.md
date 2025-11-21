---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: ds/RMQ.h
    title: ds/RMQ.h
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
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"tests/Static_RMQ.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\
    \n\n#line 1 \"misc/macros.h\"\n// #pragma GCC optimize(\"Ofast,unroll-loops\"\
    )       // unroll long, simple loops\n// #pragma GCC target(\"avx2,fma\")    \
    \               // vectorizing code\n// #pragma GCC target(\"lzcnt,popcnt,abm,bmi,bmi2\"\
    )  // for fast bitset operation\n\n#include <bits/extc++.h>\n\n#include <tr2/dynamic_bitset>\n\
    \nusing namespace std;\nusing namespace __gnu_pbds;  // ordered_set, gp_hash_table\n\
    // using namespace __gnu_cxx;\n\n// for templates to work\n#define all(s) s.begin(),\
    \ s.end()\n#define sz(x) (int) (x).size()\n#define pb push_back\n#define eb emplace_back\n\
    using i32 = int32_t;\nusing u32 = uint32_t;\nusing i64 = int64_t;\nusing u64 =\
    \ uint64_t;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\nusing ld = long\
    \ double;\nusing pii = pair<i32, i32>;\nusing vi = vector<i32>;\n\n// fast map\n\
    const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();\n\
    struct chash {  // customize hash function for gp_hash_table\n  int operator()(int\
    \ x) const { return x ^ RANDOM; }\n};\ngp_hash_table<int, int, chash> table;\n\
    \n/* ordered set\n    find_by_order(k): returns an iterator to the k-th element\
    \ (0-based)\n    order_of_key(k): returns the number of elements in the set that\
    \ are strictly less than k\n*/\ntemplate <class T>\nusing ordered_set = tree<T,\
    \ null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;\n\n// dynamic\
    \ bitset\nusing bs = tr2::dynamic_bitset<u64>;\n\n/*  rope\n    rope <int> cur\
    \ = v.substr(l, r - l + 1);\n    v.erase(l, r - l + 1);\n    v.insert(v.mutable_begin(),\
    \ cur);\n*/\n#line 1 \"ds/RMQ.h\"\ntemplate <class T, class F>\nstruct RMQ {\n\
    \  vector<vector<T>> jmp;\n  const F f;\n  RMQ(const vector<T>& V, F f) : jmp(1,\
    \ V), f(f) {\n    for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {\n \
    \     jmp.eb(sz(V) - pw * 2 + 1);\n      for (int j = 0; j < sz(jmp[k]); ++j)\
    \ jmp[k][j] = f(jmp[k - 1][j], jmp[k - 1][j + pw]);\n    }\n  }\n  // [a, b)\n\
    \  T query(int a, int b) {\n    assert(a < b);\n    int dep = 31 - __builtin_clz(b\
    \ - a);\n    return f(jmp[dep][a], jmp[dep][b - (1 << dep)]);\n  }\n};\n#line\
    \ 5 \"tests/Static_RMQ.test.cpp\"\n\nvoid solve() {\n  int n, q;\n  cin >> n >>\
    \ q;\n  vector<i32> a(n);\n  for (auto& x : a) cin >> x;\n  RMQ rmq(a, [&](const\
    \ i32& x, const i32& y) { return min(x, y); });\n  for (int i = 0; i < q; ++i)\
    \ {\n    int l, r;\n    cin >> l >> r;\n    cout << rmq.query(l, r) << '\\n';\n\
    \  }\n}\n\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n  cin.exceptions(cin.failbit);\n\
    \  int tc = 1;\n  // cin >> tc;\n  for (int i = 1; i <= tc; ++i) {\n    solve();\n\
    \  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ \"../misc/macros.h\"\n#include \"../ds/RMQ.h\"\n\nvoid solve() {\n  int n, q;\n\
    \  cin >> n >> q;\n  vector<i32> a(n);\n  for (auto& x : a) cin >> x;\n  RMQ rmq(a,\
    \ [&](const i32& x, const i32& y) { return min(x, y); });\n  for (int i = 0; i\
    \ < q; ++i) {\n    int l, r;\n    cin >> l >> r;\n    cout << rmq.query(l, r)\
    \ << '\\n';\n  }\n}\n\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n  cin.exceptions(cin.failbit);\n\
    \  int tc = 1;\n  // cin >> tc;\n  for (int i = 1; i <= tc; ++i) {\n    solve();\n\
    \  }\n}\n"
  dependsOn:
  - misc/macros.h
  - ds/RMQ.h
  isVerificationFile: true
  path: tests/Static_RMQ.test.cpp
  requiredBy: []
  timestamp: '2025-11-21 16:12:02+07:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: tests/Static_RMQ.test.cpp
layout: document
redirect_from:
- /verify/tests/Static_RMQ.test.cpp
- /verify/tests/Static_RMQ.test.cpp.html
title: tests/Static_RMQ.test.cpp
---
