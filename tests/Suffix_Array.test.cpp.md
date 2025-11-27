---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: misc/macros.h
    title: misc/macros.h
  - icon: ':heavy_check_mark:'
    path: strings/SuffixArray.h
    title: strings/SuffixArray.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/suffixarray
    links:
    - https://judge.yosupo.jp/problem/suffixarray
  bundledCode: "#line 1 \"tests/Suffix_Array.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/suffixarray\"\
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
    \ cur);\n*/\n#line 1 \"strings/SuffixArray.h\"\nstruct SuffixArray {\n  vector<int>\
    \ sa, lcp, rank;\n  SuffixArray(string s, int lim = 256) {\n    int n = s.size()\
    \ + 1, k = 0, a, b;\n    s.push_back(0);\n    vector<int> y(n), cnt(max(n, lim));\n\
    \    sa.resize(n), lcp.resize(n), rank.resize(n);\n    for (int i = 0; i < n;\
    \ ++i) rank[i] = s[i];\n    iota(sa.begin(), sa.end(), 0);\n    \n    for (int\
    \ j = 0, p = 0; p < n; j = max(1, j * 2), lim = p) {\n      p = j;\n      iota(all(y),\
    \ n - j);\n      for (int i = 0; i < n; ++i)\n        if (sa[i] >= j) y[p++] =\
    \ sa[i] - j;\n      fill(all(cnt), 0);\n      for (int i = 0; i < n; ++i) cnt[rank[i]]++;\n\
    \      for (int i = 1; i < lim; ++i) cnt[i] += cnt[i - 1];\n      for (int i =\
    \ n; i--;) sa[--cnt[rank[y[i]]]] = y[i];\n      swap(rank, y), p = 1, rank[sa[0]]\
    \ = 0;\n      for (int i = 1; i < n; ++i) {\n        a = sa[i - 1], b = sa[i];\n\
    \        int val_a = (a + j < n) ? y[a + j] : -1;\n        int val_b = (b + j\
    \ < n) ? y[b + j] : -1;\n        rank[b] = (y[a] == y[b] && val_a == val_b) ?\
    \ p - 1 : p++;\n      }\n    }\n    \n    for (int i = 0; i < n; ++i) rank[sa[i]]\
    \ = i;\n    for (int i = 0, j; i < n - 1; lcp[rank[i++]] = k)\n      for (k &&\
    \ k--, j = sa[rank[i] - 1]; s[i + k] == s[j + k]; k++);\n  }\n};\n#line 5 \"tests/Suffix_Array.test.cpp\"\
    \n\nvoid solve() {\n  string s;\n  cin >> s;\n  auto sa = SuffixArray(s);\n  for\
    \ (int i = 1; i < sz(sa.sa); ++i) cout << sa.sa[i] << ' ';\n}\n\nint main() {\n\
    \  ios::sync_with_stdio(false);\n  cin.tie(0);\n  int tc = 1;\n  // cin >> tc;\n\
    \  while (tc--) solve();\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/suffixarray\"\n\n#include\
    \ \"../misc/macros.h\"\n#include \"../strings/SuffixArray.h\"\n\nvoid solve()\
    \ {\n  string s;\n  cin >> s;\n  auto sa = SuffixArray(s);\n  for (int i = 1;\
    \ i < sz(sa.sa); ++i) cout << sa.sa[i] << ' ';\n}\n\nint main() {\n  ios::sync_with_stdio(false);\n\
    \  cin.tie(0);\n  int tc = 1;\n  // cin >> tc;\n  while (tc--) solve();\n}"
  dependsOn:
  - misc/macros.h
  - strings/SuffixArray.h
  isVerificationFile: true
  path: tests/Suffix_Array.test.cpp
  requiredBy: []
  timestamp: '2025-11-22 00:26:56+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/Suffix_Array.test.cpp
layout: document
redirect_from:
- /verify/tests/Suffix_Array.test.cpp
- /verify/tests/Suffix_Array.test.cpp.html
title: tests/Suffix_Array.test.cpp
---
