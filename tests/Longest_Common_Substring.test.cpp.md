---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: misc/macros.h
    title: misc/macros.h
  - icon: ':x:'
    path: strings/SuffixArray.h
    title: strings/SuffixArray.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/longest_common_substring
    links:
    - https://judge.yosupo.jp/problem/longest_common_substring
  bundledCode: "#line 1 \"tests/Longest_Common_Substring.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/longest_common_substring\"\n\n#line 1 \"misc/macros.h\"\
    \n// #pragma GCC optimize(\"Ofast,unroll-loops\")       // unroll long, simple\
    \ loops\n// #pragma GCC target(\"avx2,fma\")                   // vectorizing\
    \ code\n// #pragma GCC target(\"lzcnt,popcnt,abm,bmi,bmi2\")  // for fast bitset\
    \ operation\n\n#include <bits/extc++.h>\n\nusing namespace std;\nusing namespace\
    \ __gnu_pbds;  // ordered_set, gp_hash_table\n// using namespace __gnu_cxx; //\
    \ rope\n\n// for templates to work\n#define all(s) s.begin(), s.end()\n#define\
    \ sz(x) (int) (x).size()\n#define pb push_back\n#define eb emplace_back\nusing\
    \ i32 = int32_t;\nusing u32 = uint32_t;\nusing i64 = int64_t;\nusing u64 = uint64_t;\n\
    using i128 = __int128_t;\nusing u128 = __uint128_t;\nusing ld = long double;\n\
    using pii = pair<i32, i32>;\nusing vi = vector<i32>;\n\n// fast map\nconst int\
    \ RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();\n\
    struct chash {  // customize hash function for gp_hash_table\n  int operator()(int\
    \ x) const { return x ^ RANDOM; }\n};\ngp_hash_table<int, int, chash> table;\n\
    \n/* ordered set\n    find_by_order(k): returns an iterator to the k-th element\
    \ (0-based)\n    order_of_key(k): returns the number of elements in the set that\
    \ are strictly less than k\n*/\ntemplate <class T>\nusing ordered_set = tree<T,\
    \ null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;\n\n/* \
    \ rope\n    rope <int> cur = v.substr(l, r - l + 1);\n    v.erase(l, r - l + 1);\n\
    \    v.insert(v.mutable_begin(), cur);\n*/\n#line 1 \"strings/SuffixArray.h\"\n\
    struct SuffixArray {\n  vector<int> sa, lcp, rank;\n  SuffixArray(string s, int\
    \ lim = 256) {\n    int n = s.size() + 1, k = 0, a, b;\n    s.push_back(0);\n\
    \    vector<int> y(n), cnt(max(n, lim));\n    sa.resize(n), lcp.resize(n), rank.resize(n);\n\
    \    for (int i = 0; i < n; ++i) rank[i] = s[i];\n    iota(sa.begin(), sa.end(),\
    \ 0);\n    \n    for (int j = 0, p = 0; p < n; j = max(1, j * 2), lim = p) {\n\
    \      p = j;\n      iota(all(y), n - j);\n      for (int i = 0; i < n; ++i)\n\
    \        if (sa[i] >= j) y[p++] = sa[i] - j;\n      fill(all(cnt), 0);\n     \
    \ for (int i = 0; i < n; ++i) cnt[rank[i]]++;\n      for (int i = 1; i < lim;\
    \ ++i) cnt[i] += cnt[i - 1];\n      for (int i = n; i--;) sa[--cnt[rank[y[i]]]]\
    \ = y[i];\n      swap(rank, y), p = 1, rank[sa[0]] = 0;\n      for (int i = 1;\
    \ i < n; ++i) {\n        a = sa[i - 1], b = sa[i];\n        int val_a = (a + j\
    \ < n) ? y[a + j] : -1;\n        int val_b = (b + j < n) ? y[b + j] : -1;\n  \
    \      rank[b] = (y[a] == y[b] && val_a == val_b) ? p - 1 : p++;\n      }\n  \
    \  }\n    \n    for (int i = 0; i < n; ++i) rank[sa[i]] = i;\n    for (int i =\
    \ 0, j; i < n - 1; lcp[rank[i++]] = k)\n      for (k && k--, j = sa[rank[i] -\
    \ 1]; s[i + k] == s[j + k]; k++);\n  }\n};\n#line 5 \"tests/Longest_Common_Substring.test.cpp\"\
    \n\nvoid solve() {\n  string S, T;\n  cin >> S >> T;\n  SuffixArray sa(S + '$'\
    \ + T);  // N\u1ED1i chu\u1ED7i\n  int n = sz(S);\n  int maxL = 0, pS = -1, pT\
    \ = -1;\n\n  // Duy\u1EC7t m\u1EA3ng LCP \u0111\u1EC3 t\xECm max\n  for (int i\
    \ = 1; i < sz(sa.lcp); ++i) {\n    int u = sa.sa[i], v = sa.sa[i - 1];\n\n   \
    \ // Ki\u1EC3m tra u, v c\xF3 n\u1EB1m \u1EDF 2 x\xE2u kh\xE1c nhau kh\xF4ng (m\u1ED9\
    t c\xE1i < n, m\u1ED9t c\xE1i > n)\n    if ((u < n) != (v < n)) {\n      if (sa.lcp[i]\
    \ > maxL) {\n        maxL = sa.lcp[i];\n        pS = (u < n ? u : v);        \
    \  // V\u1ECB tr\xED b\xEAn S\n        pT = (u > n ? u : v) - n - 1;  // V\u1ECB\
    \ tr\xED b\xEAn T (tr\u1EEB \u0111\u1ED9 d\xE0i S v\xE0 d\u1EA5u $)\n      }\n\
    \    }\n  }\n\n  if (maxL > 0) {\n    cout << pS << \" \" << pS + maxL << \" \"\
    \ << pT << \" \" << pT + maxL;\n  } else {\n    cout << \"0 0 0 0\";\n  }\n}\n\
    \nint main() {\n  solve();\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/longest_common_substring\"\
    \n\n#include \"../misc/macros.h\"\n#include \"../strings/SuffixArray.h\"\n\nvoid\
    \ solve() {\n  string S, T;\n  cin >> S >> T;\n  SuffixArray sa(S + '$' + T);\
    \  // N\u1ED1i chu\u1ED7i\n  int n = sz(S);\n  int maxL = 0, pS = -1, pT = -1;\n\
    \n  // Duy\u1EC7t m\u1EA3ng LCP \u0111\u1EC3 t\xECm max\n  for (int i = 1; i <\
    \ sz(sa.lcp); ++i) {\n    int u = sa.sa[i], v = sa.sa[i - 1];\n\n    // Ki\u1EC3\
    m tra u, v c\xF3 n\u1EB1m \u1EDF 2 x\xE2u kh\xE1c nhau kh\xF4ng (m\u1ED9t c\xE1\
    i < n, m\u1ED9t c\xE1i > n)\n    if ((u < n) != (v < n)) {\n      if (sa.lcp[i]\
    \ > maxL) {\n        maxL = sa.lcp[i];\n        pS = (u < n ? u : v);        \
    \  // V\u1ECB tr\xED b\xEAn S\n        pT = (u > n ? u : v) - n - 1;  // V\u1ECB\
    \ tr\xED b\xEAn T (tr\u1EEB \u0111\u1ED9 d\xE0i S v\xE0 d\u1EA5u $)\n      }\n\
    \    }\n  }\n\n  if (maxL > 0) {\n    cout << pS << \" \" << pS + maxL << \" \"\
    \ << pT << \" \" << pT + maxL;\n  } else {\n    cout << \"0 0 0 0\";\n  }\n}\n\
    \nint main() {\n  solve();\n}"
  dependsOn:
  - misc/macros.h
  - strings/SuffixArray.h
  isVerificationFile: true
  path: tests/Longest_Common_Substring.test.cpp
  requiredBy: []
  timestamp: '2025-11-28 00:00:09+07:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: tests/Longest_Common_Substring.test.cpp
layout: document
redirect_from:
- /verify/tests/Longest_Common_Substring.test.cpp
- /verify/tests/Longest_Common_Substring.test.cpp.html
title: tests/Longest_Common_Substring.test.cpp
---
