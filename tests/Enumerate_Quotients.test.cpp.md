---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/EnumQuotients.h
    title: math/EnumQuotients.h
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
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_quotients
    links:
    - https://judge.yosupo.jp/problem/enumerate_quotients
  bundledCode: "#line 1 \"tests/Enumerate_Quotients.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/enumerate_quotients\"\n\n#line 1 \"misc/macros.h\"\
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
    #endif\n#line 1 \"math/EnumQuotients.h\"\nvector<ll> EnumerateQuotients(ll N)\
    \ {\n  vector<ll> res;\n  ll f = 1;\n  for (; f * f < N; f++) res.push_back(f);\n\
    \  int qp1 = res.size();\n  for (ll k = 1; k * f <= N; k++) {\n    res.push_back((k\
    \ & 1) ? (N / k) : (res[qp1 + k / 2 - 1] / 2));\n  }\n  reverse(res.begin() +\
    \ qp1, res.end());\n  return res;\n}\n#line 5 \"tests/Enumerate_Quotients.test.cpp\"\
    \n\nvoid solve() {\n  ll n;\n  cin >> n;\n  auto q = EnumerateQuotients(n);\n\
    \  cout << sz(q) << '\\n';\n  for (auto d : q) cout << d << ' ';\n}\n\nint main()\
    \ {\n  cin.tie(0)->sync_with_stdio(0);\n  cin.exceptions(cin.failbit);\n  int\
    \ tc = 1;\n  // cin >> tc;\n  for (int i = 1; i <= tc; ++i) {\n    solve();\n\
    \  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_quotients\"\n\
    \n#include \"../misc/macros.h\"\n#include \"../math/EnumQuotients.h\"\n\nvoid\
    \ solve() {\n  ll n;\n  cin >> n;\n  auto q = EnumerateQuotients(n);\n  cout <<\
    \ sz(q) << '\\n';\n  for (auto d : q) cout << d << ' ';\n}\n\nint main() {\n \
    \ cin.tie(0)->sync_with_stdio(0);\n  cin.exceptions(cin.failbit);\n  int tc =\
    \ 1;\n  // cin >> tc;\n  for (int i = 1; i <= tc; ++i) {\n    solve();\n  }\n\
    }\n"
  dependsOn:
  - misc/macros.h
  - math/EnumQuotients.h
  isVerificationFile: true
  path: tests/Enumerate_Quotients.test.cpp
  requiredBy: []
  timestamp: '2025-11-17 20:56:58+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/Enumerate_Quotients.test.cpp
layout: document
redirect_from:
- /verify/tests/Enumerate_Quotients.test.cpp
- /verify/tests/Enumerate_Quotients.test.cpp.html
title: tests/Enumerate_Quotients.test.cpp
---
