---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: ds/SegTree.h
    title: ds/SegTree.h
  - icon: ':x:'
    path: misc/Compressor.h
    title: misc/Compressor.h
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
    PROBLEM: https://judge.yosupo.jp/problem/longest_increasing_subsequence
    links:
    - https://judge.yosupo.jp/problem/longest_increasing_subsequence
  bundledCode: "#line 1 \"tests/LIS.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/longest_increasing_subsequence\"\
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
    \    v.insert(v.mutable_begin(), cur);\n*/\n#line 1 \"misc/Compressor.h\"\ntemplate\
    \ <class T>\nvi compressor(vector<T>& v) {\n  auto cv = v;\n  sort(all(cv));\n\
    \  cv.erase(unique(all(cv)), cv.end());\n  for (auto& e : v) e = lower_bound(all(cv),\
    \ e) - cv.begin();\n  return v;\n}\n#line 1 \"ds/SegTree.h\"\n// 0-indexed\ntemplate\
    \ <class T, class F>\nstruct SegTree {\n  int n, size;  // smallest size = 2^k\
    \ >= n\n  vector<T> seg;\n  const F f;\n  const T I;\n  SegTree(int n, F f, const\
    \ T& I) : n(n), f(f), I(I) {\n    size = 1;\n    while (size < n) size <<= 1;\n\
    \    seg.assign(size << 1, I);\n  }\n  T& operator[](int k) { return seg[k + size];\
    \ }\n  void set(int k, T x) { seg[k + size] = x; }  // to build\n  void build()\
    \ {\n    for (int i = size - 1; i > 0; --i) seg[i] = f(seg[i << 1], seg[i << 1\
    \ | 1]);\n  }\n  void apply(int k, T x) {\n    k += size, seg[k] = x;\n    while\
    \ (k >>= 1) seg[k] = f(seg[k << 1], seg[k << 1 | 1]);\n  }\n  // query [l, r)\n\
    \  T query(int l, int r) {\n    T L = I, R = I;\n    for (l += size, r += size;\
    \ l < r; l >>= 1, r >>= 1) {\n      if (l & 1) L = f(L, seg[l++]);\n      if (r\
    \ & 1) R = f(seg[--r], R);\n    }\n    return f(L, R);\n  }\n  template <class\
    \ C>\n  int max_right(int l, C check) {\n    assert(0 <= l && l <= n && check(I)\
    \ == true);\n    if (l == n) return n;\n    l += size;\n    T sm = I;\n    do\
    \ {\n      while (l % 2 == 0) l >>= 1;\n      if (!check(f(sm, seg[l]))) {\n \
    \       while (l < size) {\n          l = l << 1;\n          if (check(f(sm, seg[l])))\
    \ sm = f(sm, seg[l]), l++;\n        }\n        return l - size;\n      }\n   \
    \   sm = f(sm, seg[l]), l++;\n    } while ((l & -l) != l);\n    return n;\n  }\n\
    \  template <class C>\n  int min_left(int r, C check) {\n    assert(0 <= r &&\
    \ r <= n && check(I) == true);\n    if (r == 0) return 0;\n    r += size;\n  \
    \  T sm = I;\n    do {\n      r--;\n      while (r > 1 && (r % 2)) r >>= 1;\n\
    \      if (!check(f(seg[r], sm))) {\n        while (r < size) {\n          r =\
    \ r << 1 | 1;\n          if (check(f(seg[r], sm))) sm = f(seg[r], sm), r--;\n\
    \        }\n        return r + 1 - size;\n      }\n      sm = f(seg[r], sm);\n\
    \    } while ((r & -r) != r);\n    return 0;\n  }\n};\n#line 6 \"tests/LIS.test.cpp\"\
    \n\nvoid solve() {\n  int n;\n  cin >> n;\n  vi a(n), tr(n, -1);\n  for (auto&\
    \ x : a) cin >> x;\n  a = compressor(a);\n  SegTree st(n, [&](pii a, pii b) {\
    \ return max(a, b); }, pii{0, -1});\n  st.apply(a[0], {1, 0});\n  for (int i =\
    \ 1; i < n; ++i) {\n    auto [lis, idx] = st.query(0, a[i]);\n    if (idx == -1)\n\
    \      tr[i] = i;\n    else\n      tr[i] = idx;\n    st.apply(a[i], {lis + 1,\
    \ i});\n  }\n  auto [lis, u] = st.query(0, n);\n  cout << lis << '\\n';\n  vi\
    \ pos;\n  while (true) {\n    pos.eb(u);\n    if (tr[u] == -1 || tr[u] == u) break;\n\
    \    u = tr[u];\n  }\n  reverse(all(pos));\n  for (auto u : pos) cout << u <<\
    \ ' ';\n}\n\nint main() {\n  solve();\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/longest_increasing_subsequence\"\
    \n\n#include \"../misc/macros.h\"\n#include \"../misc/Compressor.h\"\n#include\
    \ \"../ds/SegTree.h\"\n\nvoid solve() {\n  int n;\n  cin >> n;\n  vi a(n), tr(n,\
    \ -1);\n  for (auto& x : a) cin >> x;\n  a = compressor(a);\n  SegTree st(n, [&](pii\
    \ a, pii b) { return max(a, b); }, pii{0, -1});\n  st.apply(a[0], {1, 0});\n \
    \ for (int i = 1; i < n; ++i) {\n    auto [lis, idx] = st.query(0, a[i]);\n  \
    \  if (idx == -1)\n      tr[i] = i;\n    else\n      tr[i] = idx;\n    st.apply(a[i],\
    \ {lis + 1, i});\n  }\n  auto [lis, u] = st.query(0, n);\n  cout << lis << '\\\
    n';\n  vi pos;\n  while (true) {\n    pos.eb(u);\n    if (tr[u] == -1 || tr[u]\
    \ == u) break;\n    u = tr[u];\n  }\n  reverse(all(pos));\n  for (auto u : pos)\
    \ cout << u << ' ';\n}\n\nint main() {\n  solve();\n}"
  dependsOn:
  - misc/macros.h
  - misc/Compressor.h
  - ds/SegTree.h
  isVerificationFile: true
  path: tests/LIS.test.cpp
  requiredBy: []
  timestamp: '2025-11-28 02:09:51+07:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: tests/LIS.test.cpp
layout: document
redirect_from:
- /verify/tests/LIS.test.cpp
- /verify/tests/LIS.test.cpp.html
title: tests/LIS.test.cpp
---
