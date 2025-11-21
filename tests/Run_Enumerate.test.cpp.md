---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/RMQ.h
    title: ds/RMQ.h
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
    PROBLEM: https://judge.yosupo.jp/problem/runenumerate
    links:
    - https://judge.yosupo.jp/problem/runenumerate
  bundledCode: "#line 1 \"tests/Run_Enumerate.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/runenumerate\"\
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
    \ 1 \"strings/SuffixArray.h\"\nstruct SuffixArray {\n  vector<int> sa, lcp, rank;\n\
    \  SuffixArray(string s, int lim = 256) {\n    int n = s.size() + 1, k = 0, a,\
    \ b;\n    s.push_back(0);\n    vector<int> y(n), cnt(max(n, lim));\n    sa.resize(n),\
    \ lcp.resize(n), rank.resize(n);\n    for (int i = 0; i < n; ++i) rank[i] = s[i];\n\
    \    iota(sa.begin(), sa.end(), 0);\n    \n    for (int j = 0, p = 0; p < n; j\
    \ = max(1, j * 2), lim = p) {\n      p = j;\n      iota(all(y), n - j);\n    \
    \  for (int i = 0; i < n; ++i)\n        if (sa[i] >= j) y[p++] = sa[i] - j;\n\
    \      fill(all(cnt), 0);\n      for (int i = 0; i < n; ++i) cnt[rank[i]]++;\n\
    \      for (int i = 1; i < lim; ++i) cnt[i] += cnt[i - 1];\n      for (int i =\
    \ n; i--;) sa[--cnt[rank[y[i]]]] = y[i];\n      swap(rank, y), p = 1, rank[sa[0]]\
    \ = 0;\n      for (int i = 1; i < n; ++i) {\n        a = sa[i - 1], b = sa[i];\n\
    \        int val_a = (a + j < n) ? y[a + j] : -1;\n        int val_b = (b + j\
    \ < n) ? y[b + j] : -1;\n        rank[b] = (y[a] == y[b] && val_a == val_b) ?\
    \ p - 1 : p++;\n      }\n    }\n    \n    for (int i = 0; i < n; ++i) rank[sa[i]]\
    \ = i;\n    for (int i = 0, j; i < n - 1; lcp[rank[i++]] = k)\n      for (k &&\
    \ k--, j = sa[rank[i] - 1]; s[i + k] == s[j + k]; k++);\n  }\n};\n#line 6 \"tests/Run_Enumerate.test.cpp\"\
    \n\nstruct Run {\n  int t, l, r;\n  // So s\xE1nh \u0111\u1EC3 sort candidates:\
    \ \u01B0u ti\xEAn l, r, r\u1ED3i \u0111\u1EBFn t nh\u1ECF nh\u1EA5t\n  bool operator<(const\
    \ Run& other) const {\n    if (l != other.l) return l < other.l;\n    if (r !=\
    \ other.r) return r < other.r;\n    return t < other.t;\n  }\n  // So s\xE1nh\
    \ \u0111\u1EC3 sort output cu\u1ED1i c\xF9ng (theo y\xEAu c\u1EA7u \u0111\u1EC1\
    \ b\xE0i: th\u01B0\u1EDDng l\xE0 t, l, r)\n  static bool compareOutput(const Run&\
    \ a, const Run& b) {\n    if (a.t != b.t) return a.t < b.t;\n    if (a.l != b.l)\
    \ return a.l < b.l;\n    return a.r < b.r;\n  }\n};\n\ntemplate <class R>\nint\
    \ get_lcp(const SuffixArray& sa, R& rmq, int i, int j) {\n  if (i == j) return\
    \ sz(sa.sa) - 1 - i;\n  int l = sa.rank[i], r = sa.rank[j];\n  if (l > r) swap(l,\
    \ r);\n  return rmq.query(l + 1, r + 1);\n}\n\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n\
    \  string s;\n  cin >> s;\n  int n = sz(s);\n\n  auto min_func = [](int a, int\
    \ b) { return min(a, b); };\n\n  SuffixArray sa(s);\n  RMQ rmq(sa.lcp, min_func);\n\
    \n  string s_rev = s;\n  reverse(all(s_rev));\n  SuffixArray sa_rev(s_rev);\n\
    \  RMQ rmq_rev(sa_rev.lcp, min_func);\n\n  vector<Run> candidates;\n\n  for (int\
    \ t = 1; t <= n / 2; ++t) {\n    for (int i = 0; i + t < n; i += t) {\n      int\
    \ j = i + t;\n      int l1 = get_lcp(sa, rmq, i, j);\n      int l2 = 0;\n    \
    \  if (i > 0) l2 = get_lcp(sa_rev, rmq_rev, n - i, n - j);\n\n      if (l1 + l2\
    \ >= t && l2 < t) {\n        // L\u01B0u l\u1EA1i \u1EE9ng vi\xEAn (t, l, r)\n\
    \        candidates.push_back({t, i - l2, i - l2 + t + l1 + l2});\n      }\n \
    \   }\n  }\n\n  // B\u01AF\u1EDAC 1: Sort candidates theo (l, r, t)\n  sort(all(candidates));\n\
    \n  // B\u01AF\u1EDAC 2: L\u1ECDc tr\xF9ng (gi\u1EEF t nh\u1ECF nh\u1EA5t cho\
    \ c\xF9ng l, r)\n  vector<Run> result;\n  for (auto& run : candidates) {\n   \
    \ if (!result.empty()) {\n      Run& last = result.back();\n      if (last.l ==\
    \ run.l && last.r == run.r) continue;  // \u0110\xE3 c\xF3 run c\xF9ng l,r v\u1EDB\
    i t nh\u1ECF h\u01A1n -> B\u1ECF qua\n    }\n    result.push_back(run);\n  }\n\
    \n  // B\u01AF\u1EDAC 3: Sort k\u1EBFt qu\u1EA3 theo (t, l, r) \u0111\u1EC3 in\
    \ ra\n  sort(all(result), Run::compareOutput);\n\n  cout << sz(result) << \"\\\
    n\";\n  for (auto& run : result) {\n    cout << run.t << \" \" << run.l << \"\
    \ \" << run.r << \"\\n\";\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/runenumerate\"\n\n#include\
    \ \"../misc/macros.h\"\n#include \"../ds/RMQ.h\"\n#include \"../strings/SuffixArray.h\"\
    \n\nstruct Run {\n  int t, l, r;\n  // So s\xE1nh \u0111\u1EC3 sort candidates:\
    \ \u01B0u ti\xEAn l, r, r\u1ED3i \u0111\u1EBFn t nh\u1ECF nh\u1EA5t\n  bool operator<(const\
    \ Run& other) const {\n    if (l != other.l) return l < other.l;\n    if (r !=\
    \ other.r) return r < other.r;\n    return t < other.t;\n  }\n  // So s\xE1nh\
    \ \u0111\u1EC3 sort output cu\u1ED1i c\xF9ng (theo y\xEAu c\u1EA7u \u0111\u1EC1\
    \ b\xE0i: th\u01B0\u1EDDng l\xE0 t, l, r)\n  static bool compareOutput(const Run&\
    \ a, const Run& b) {\n    if (a.t != b.t) return a.t < b.t;\n    if (a.l != b.l)\
    \ return a.l < b.l;\n    return a.r < b.r;\n  }\n};\n\ntemplate <class R>\nint\
    \ get_lcp(const SuffixArray& sa, R& rmq, int i, int j) {\n  if (i == j) return\
    \ sz(sa.sa) - 1 - i;\n  int l = sa.rank[i], r = sa.rank[j];\n  if (l > r) swap(l,\
    \ r);\n  return rmq.query(l + 1, r + 1);\n}\n\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n\
    \  string s;\n  cin >> s;\n  int n = sz(s);\n\n  auto min_func = [](int a, int\
    \ b) { return min(a, b); };\n\n  SuffixArray sa(s);\n  RMQ rmq(sa.lcp, min_func);\n\
    \n  string s_rev = s;\n  reverse(all(s_rev));\n  SuffixArray sa_rev(s_rev);\n\
    \  RMQ rmq_rev(sa_rev.lcp, min_func);\n\n  vector<Run> candidates;\n\n  for (int\
    \ t = 1; t <= n / 2; ++t) {\n    for (int i = 0; i + t < n; i += t) {\n      int\
    \ j = i + t;\n      int l1 = get_lcp(sa, rmq, i, j);\n      int l2 = 0;\n    \
    \  if (i > 0) l2 = get_lcp(sa_rev, rmq_rev, n - i, n - j);\n\n      if (l1 + l2\
    \ >= t && l2 < t) {\n        // L\u01B0u l\u1EA1i \u1EE9ng vi\xEAn (t, l, r)\n\
    \        candidates.push_back({t, i - l2, i - l2 + t + l1 + l2});\n      }\n \
    \   }\n  }\n\n  // B\u01AF\u1EDAC 1: Sort candidates theo (l, r, t)\n  sort(all(candidates));\n\
    \n  // B\u01AF\u1EDAC 2: L\u1ECDc tr\xF9ng (gi\u1EEF t nh\u1ECF nh\u1EA5t cho\
    \ c\xF9ng l, r)\n  vector<Run> result;\n  for (auto& run : candidates) {\n   \
    \ if (!result.empty()) {\n      Run& last = result.back();\n      if (last.l ==\
    \ run.l && last.r == run.r) continue;  // \u0110\xE3 c\xF3 run c\xF9ng l,r v\u1EDB\
    i t nh\u1ECF h\u01A1n -> B\u1ECF qua\n    }\n    result.push_back(run);\n  }\n\
    \n  // B\u01AF\u1EDAC 3: Sort k\u1EBFt qu\u1EA3 theo (t, l, r) \u0111\u1EC3 in\
    \ ra\n  sort(all(result), Run::compareOutput);\n\n  cout << sz(result) << \"\\\
    n\";\n  for (auto& run : result) {\n    cout << run.t << \" \" << run.l << \"\
    \ \" << run.r << \"\\n\";\n  }\n}"
  dependsOn:
  - misc/macros.h
  - ds/RMQ.h
  - strings/SuffixArray.h
  isVerificationFile: true
  path: tests/Run_Enumerate.test.cpp
  requiredBy: []
  timestamp: '2025-11-22 00:26:56+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/Run_Enumerate.test.cpp
layout: document
redirect_from:
- /verify/tests/Run_Enumerate.test.cpp
- /verify/tests/Run_Enumerate.test.cpp.html
title: tests/Run_Enumerate.test.cpp
---
