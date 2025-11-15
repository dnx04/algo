---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/ModLog.h
    title: math/ModLog.h
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
    PROBLEM: https://judge.yosupo.jp/problem/discrete_logarithm_mod
    links:
    - https://judge.yosupo.jp/problem/discrete_logarithm_mod
  bundledCode: "#line 1 \"tests/Discrete_Logarithm.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/discrete_logarithm_mod\"\n\n#line 1 \"misc/macros.h\"\
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
    #endif\n#line 1 \"math/ModLog.h\"\nll modLog(ll a, ll b, ll m) {\n  ll n = (ll)\
    \ sqrt(m) + 1, e = 1, f = 1, j = 1;\n  unordered_map<ll, ll> A;\n  while (j <=\
    \ n && (e = f = e * a % m) != b % m) A[e * b % m] = j++;\n  if (e == b % m) return\
    \ j;\n  if (gcd(m, e) == gcd(m, b)) {\n    for (int i = 2; i < n + 2; ++i) {\n\
    \      if (A.count(e = e * f % m)) return n * i - A[e];\n    }\n  }\n  return\
    \ -1;\n}\n#line 5 \"tests/Discrete_Logarithm.test.cpp\"\n\nvoid solve() {\n  ll\
    \ a, b, m;\n  cin >> a >> b >> m;\n  if (m == 1 || b == 1) {  // because of the\
    \ bs nonnegative and 0^0 = 1\n    cout << 0 << '\\n';\n    return;\n  }\n  cout\
    \ << modLog(a, b, m) << '\\n';\n}\n\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n\
    \  cin.exceptions(cin.failbit);\n  int tc = 1;\n  cin >> tc;\n  for (int i = 1;\
    \ i <= tc; ++i) {\n    solve();\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/discrete_logarithm_mod\"\
    \n\n#include \"../misc/macros.h\"\n#include \"../math/ModLog.h\"\n\nvoid solve()\
    \ {\n  ll a, b, m;\n  cin >> a >> b >> m;\n  if (m == 1 || b == 1) {  // because\
    \ of the bs nonnegative and 0^0 = 1\n    cout << 0 << '\\n';\n    return;\n  }\n\
    \  cout << modLog(a, b, m) << '\\n';\n}\n\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n\
    \  cin.exceptions(cin.failbit);\n  int tc = 1;\n  cin >> tc;\n  for (int i = 1;\
    \ i <= tc; ++i) {\n    solve();\n  }\n}\n"
  dependsOn:
  - misc/macros.h
  - math/ModLog.h
  isVerificationFile: true
  path: tests/Discrete_Logarithm.test.cpp
  requiredBy: []
  timestamp: '2025-11-15 18:26:28+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/Discrete_Logarithm.test.cpp
layout: document
redirect_from:
- /verify/tests/Discrete_Logarithm.test.cpp
- /verify/tests/Discrete_Logarithm.test.cpp.html
title: tests/Discrete_Logarithm.test.cpp
---
