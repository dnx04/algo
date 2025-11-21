---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: ds/LazySegTree.h
    title: ds/LazySegTree.h
  - icon: ':question:'
    path: math/ModInt.h
    title: math/ModInt.h
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
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_point_get
    links:
    - https://judge.yosupo.jp/problem/range_affine_point_get
  bundledCode: "#line 1 \"tests/Range_Affine_Point_Get.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/range_affine_point_get\"\n\n#line 1 \"misc/macros.h\"\
    \n// #pragma GCC optimize(\"Ofast,unroll-loops\")       // unroll long, simple\
    \ loops\n// #pragma GCC target(\"avx2,fma\")                   // vectorizing\
    \ code\n// #pragma GCC target(\"lzcnt,popcnt,abm,bmi,bmi2\")  // for fast bitset\
    \ operation\n\n#include <bits/extc++.h>\n\n#include <tr2/dynamic_bitset>\n\nusing\
    \ namespace std;\nusing namespace __gnu_pbds;  // ordered_set, gp_hash_table\n\
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
    \ cur);\n*/\n#line 2 \"math/ModInt.h\"\n\ntemplate <int mod>\nstruct modint {\n\
    \  using M = modint;\n  static_assert(mod > 0 && mod <= 2147483647);\n  static\
    \ constexpr u32 r1 = []() {\n    u32 r1 = mod;\n    for (int i = 0; i < 5; ++i)\
    \ r1 *= 2 - mod * r1;\n    return -r1;\n  }();\n  static constexpr u32 r2 = -u64(mod)\
    \ % mod;\n  static u32 reduce(u64 x) {\n    u32 y = u32(x) * r1, r = (x + u64(y)\
    \ * mod) >> 32;\n    return r >= mod ? r - mod : r;\n  }\n  u32 x;\n  modint()\
    \ : x(0) {}\n  modint(i64 x) : x(reduce(u64(x % mod + mod) * r2)) {}\n  M& operator+=(const\
    \ M& a) {\n    if ((x += a.x) >= mod) x -= mod;\n    return *this;\n  }\n  M&\
    \ operator-=(const M& a) {\n    if ((x += mod - a.x) >= mod) x -= mod;\n    return\
    \ *this;\n  }\n  M& operator*=(const M& a) {\n    x = reduce(u64(x) * a.x);\n\
    \    return *this;\n  }\n  M& operator/=(const M& a) { return *this *= a.inv();\
    \ }\n  M operator-() const { return M(0) - *this; }\n  M operator+(const M& a)\
    \ const { return M(*this) += a; }\n  M operator-(const M& a) const { return M(*this)\
    \ -= a; }\n  M operator*(const M& a) const { return M(*this) *= a; }\n  M operator/(const\
    \ M& a) const { return M(*this) /= a; }\n  bool operator==(const M& a) const {\
    \ return x == a.x; }\n  bool operator!=(const M& a) const { return x != a.x; }\n\
    \  M pow(u64 k) const {\n    M res(1), b = *this;\n    while (k) {\n      if (k\
    \ & 1) res *= b;\n      b *= b, k >>= 1;\n    }\n    return res;\n  }\n  M inv()\
    \ const { return pow(mod - 2); }\n  friend ostream& operator<<(ostream& os, const\
    \ M& a) {\n    return os << reduce(a.x);\n  }\n  friend istream& operator>>(istream&\
    \ is, M& a) {\n    i64 v;\n    is >> v;\n    a = M(v);\n    return is;\n  }\n\
    };\n\nu64 modmul(u64 x, u64 y, u64 m) { return u128(x) * y % m; }\nu64 modpow(u64\
    \ x, u64 k, u64 m) {\n  u64 res = 1;\n  while (k) {\n    if (k & 1) res = modmul(res,\
    \ x, m);\n    x = modmul(x, x, m);\n    k >>= 1;\n  }\n  return res;\n}\n#line\
    \ 1 \"ds/LazySegTree.h\"\n// 0-indexed\ntemplate <class T, class L, class F, class\
    \ M, class C>\nstruct LazySegTree {\n private:\n  int n, h;\n  vector<T> seg;\n\
    \  vector<L> laz;\n  const T I;   // Identity node (e.g., 0 for sum, INF for min)\n\
    \  const L L0;  // Identity laz (e.g., 0 for add, -1 for set)\n  const F f;  \
    \ // f: Merge 2 nodes (T, T) -> T\n  const M m;   // m: Mapping laz to node (T,\
    \ L) -> T\n  const C c;   // c: Composition 2 laz (L prev, L next) -> next(prev)\n\
    \  void apply(int p, L val) {\n    seg[p] = m(seg[p], val);\n    if (p < n) laz[p]\
    \ = c(laz[p], val);\n  }\n  void pull(int p) {\n    while (p > 1) {\n      p >>=\
    \ 1;\n      seg[p] = m(f(seg[p << 1], seg[p << 1 | 1]), laz[p]);\n    }\n  }\n\
    \  void push(int p) {\n    for (int s = h; s > 0; --s) {\n      int i = p >> s;\n\
    \      if (laz[i] != L0) apply(i << 1, laz[i]), apply(i << 1 | 1, laz[i]), laz[i]\
    \ = L0;\n    }\n  }\n\n public:\n  LazySegTree(int n, T I, L L0, F f, M m, C c)\
    \ : n(n), h(32 - __builtin_clz(n)), seg(n << 1 | 1, I), laz(n, L0), I(I), L0(L0),\
    \ f(f), m(m), c(c) {}\n  // set p to x\n  void set(int p, T x) {\n    p += n;\n\
    \    for (int i = h; i > 0; --i) {\n      int k = p >> i;\n      if (laz[k] !=\
    \ L0) apply(k << 1, laz[k]), apply(k << 1 | 1, laz[k]), laz[k] = L0;\n    }\n\
    \    seg[p] = x, pull(p);\n  }\n  // Apply op -> [l, r)\n  void apply(int l, int\
    \ r, L op) {\n    l += n, r += n;\n    int l0 = l, r0 = r;\n    push(l0), push(r0\
    \ - 1);\n    for (; l < r; l >>= 1, r >>= 1) {\n      if (l & 1) apply(l++, op);\n\
    \      if (r & 1) apply(--r, op);\n    }\n    pull(l0), pull(r0 - 1);\n  }\n \
    \ // Query [l, r)\n  T query(int l, int r) {\n    l += n, r += n;\n    push(l),\
    \ push(r - 1);\n    T resL = I, resR = I;\n    for (; l < r; l >>= 1, r >>= 1)\
    \ {\n      if (l & 1) resL = f(resL, seg[l++]);\n      if (r & 1) resR = f(seg[--r],\
    \ resR);\n    }\n    return f(resL, resR);\n  }\n};\n#line 6 \"tests/Range_Affine_Point_Get.test.cpp\"\
    \n\nusing Fp = modint<998244353>;\n\nvoid solve() {\n  int n, q;\n  cin >> n >>\
    \ q;\n\n  using P = pair<Fp, Fp>;\n  auto f = [](P a, P b) { return P{a.first\
    \ + b.first, a.second + b.second}; };\n  auto m = [](P a, P b) { return P{a.first\
    \ * b.first + a.second * b.second, a.second}; };\n  auto c = [](P a, P b) { return\
    \ P{a.first * b.first, a.second * b.first + b.second}; };\n  P I = {0, 0};\n \
    \ P L0 = {1, 0};\n  LazySegTree t(n, I, L0, f, m, c);\n  for (int i = 0; i < n;\
    \ ++i) {\n    int x;\n    cin >> x;\n    t.set(i, P{x, 1});\n  }\n  while (q--)\
    \ {\n    int cmd;\n    cin >> cmd;\n    if (cmd == 0) {\n      int l, r, c, d;\n\
    \      cin >> l >> r >> c >> d;\n      t.apply(l, r, P{c, d});\n    } else {\n\
    \      int i;\n      cin >> i;\n      cout << t.query(i, i + 1).first << '\\n';\n\
    \    }\n  }\n}\n\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n  cin.exceptions(cin.failbit);\n\
    \  int tc = 1;\n  // cin >> tc;\n  for (int i = 1; i <= tc; ++i) {\n    solve();\n\
    \  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_point_get\"\
    \n\n#include \"../misc/macros.h\"\n#include \"../math/ModInt.h\"\n#include \"\
    ../ds/LazySegTree.h\"\n\nusing Fp = modint<998244353>;\n\nvoid solve() {\n  int\
    \ n, q;\n  cin >> n >> q;\n\n  using P = pair<Fp, Fp>;\n  auto f = [](P a, P b)\
    \ { return P{a.first + b.first, a.second + b.second}; };\n  auto m = [](P a, P\
    \ b) { return P{a.first * b.first + a.second * b.second, a.second}; };\n  auto\
    \ c = [](P a, P b) { return P{a.first * b.first, a.second * b.first + b.second};\
    \ };\n  P I = {0, 0};\n  P L0 = {1, 0};\n  LazySegTree t(n, I, L0, f, m, c);\n\
    \  for (int i = 0; i < n; ++i) {\n    int x;\n    cin >> x;\n    t.set(i, P{x,\
    \ 1});\n  }\n  while (q--) {\n    int cmd;\n    cin >> cmd;\n    if (cmd == 0)\
    \ {\n      int l, r, c, d;\n      cin >> l >> r >> c >> d;\n      t.apply(l, r,\
    \ P{c, d});\n    } else {\n      int i;\n      cin >> i;\n      cout << t.query(i,\
    \ i + 1).first << '\\n';\n    }\n  }\n}\n\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n\
    \  cin.exceptions(cin.failbit);\n  int tc = 1;\n  // cin >> tc;\n  for (int i\
    \ = 1; i <= tc; ++i) {\n    solve();\n  }\n}\n"
  dependsOn:
  - misc/macros.h
  - math/ModInt.h
  - ds/LazySegTree.h
  isVerificationFile: true
  path: tests/Range_Affine_Point_Get.test.cpp
  requiredBy: []
  timestamp: '2025-11-21 16:12:02+07:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: tests/Range_Affine_Point_Get.test.cpp
layout: document
redirect_from:
- /verify/tests/Range_Affine_Point_Get.test.cpp
- /verify/tests/Range_Affine_Point_Get.test.cpp.html
title: tests/Range_Affine_Point_Get.test.cpp
---
