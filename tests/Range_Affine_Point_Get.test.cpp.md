---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/LazySegTree.h
    title: ds/LazySegTree.h
  - icon: ':heavy_check_mark:'
    path: math/ModInt.h
    title: math/ModInt.h
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
    \ are strictly less than k\n*/\ntemplate <typename T>\nusing ordered_set = tree<T,\
    \ null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;\n\n// dynamic\
    \ bitset\nusing bs = tr2::dynamic_bitset<u64>;\n\n/*  rope\n    rope <int> cur\
    \ = v.substr(l, r - l + 1);\n    v.erase(l, r - l + 1);\n    v.insert(v.mutable_begin(),\
    \ cur);\n*/\n#line 1 \"math/ModInt.h\"\ntemplate <int mod>\nstruct modint {\n\
    \  using Fp = modint;\n  int x;\n  modint() : x(0) {}\n  modint(i64 y) : x(y >=\
    \ 0 ? y % mod : (mod - (-y) % mod) % mod) {}\n  Fp& operator+=(const Fp& p) {\n\
    \    if ((x += p.x) >= mod) x -= mod;\n    return *this;\n  }\n  Fp& operator-=(const\
    \ Fp& p) {\n    if ((x += mod - p.x) >= mod) x -= mod;\n    return *this;\n  }\n\
    \  Fp& operator*=(const Fp& p) {\n    x = (int) (1ll * x * p.x % mod);\n    return\
    \ *this;\n  }\n  Fp& operator/=(const Fp& p) {\n    *this *= p.inv();\n    return\
    \ *this;\n  }\n  Fp operator-() const { return Fp(-x); }\n  Fp operator+(const\
    \ Fp& p) const { return Fp(*this) += p; }\n  Fp operator-(const Fp& p) const {\
    \ return Fp(*this) -= p; }\n  Fp operator*(const Fp& p) const { return Fp(*this)\
    \ *= p; }\n  Fp operator/(const Fp& p) const { return Fp(*this) /= p; }\n  bool\
    \ operator==(const Fp& p) const { return x == p.x; }\n  bool operator!=(const\
    \ Fp& p) const { return x != p.x; }\n  Fp inv() const { return *this ^ (mod -\
    \ 2); }\n  Fp operator^(i64 n) const {\n    Fp ret(1), mul(x);\n    while (n >\
    \ 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n    }\n\
    \    return ret;\n  }\n  friend ostream& operator<<(ostream& os, const Fp& p)\
    \ { return os << p.x; }\n  friend istream& operator>>(istream& is, Fp& a) {\n\
    \    i64 t;\n    is >> t;\n    a = modint<mod>(t);\n    return (is);\n  }\n};\n\
    \nu64 modmul(u64 x, u64 y, u64 m) { return u128(x) * y % m; }\nu64 modpow(u64\
    \ x, u64 k, u64 m) {\n  u64 res = 1;\n  while (k) {\n    if (k & 1) res = modmul(res,\
    \ x, m);\n    x = modmul(x, x, m);\n    k >>= 1;\n  }\n  return res;\n}\n#line\
    \ 1 \"ds/LazySegTree.h\"\ntemplate <typename T, typename L>\nstruct LazySegTree\
    \ {\n  int n, h;\n  vector<T> seg;\n  vector<L> lazy;\n  const T I;   // Identity\
    \ node (e.g., 0 for sum, INF for min)\n  const L L0;  // Identity lazy (e.g.,\
    \ 0 for add, -1 for set)\n  // f: Merge 2 nodes (T, T) -> T\n  // m: Mapping lazy\
    \ to node (T, L) -> T\n  // c: Composition 2 lazy (L, L) -> L\n  function<T(T,\
    \ T)> f;\n  function<T(T, L)> m;\n  function<L(L, L)> c;\n  LazySegTree(int n,\
    \ T I, L L0, auto f, auto m, auto c) : n(n), h(32 - __builtin_clz(n)), seg(2 *\
    \ n, I), lazy(n, L0), I(I), L0(L0), f(f), m(m), c(c) {}\n  void apply(int p, L\
    \ val) {\n    seg[p] = m(seg[p], val);\n    if (p < n) lazy[p] = c(lazy[p], val);\n\
    \  }\n  void pull(int p) {\n    while (p > 1) {\n      p >>= 1;\n      seg[p]\
    \ = m(f(seg[2 * p], seg[2 * p + 1]), lazy[p]);\n    }\n  }\n  void push(int p)\
    \ {\n    for (int s = h; s > 0; --s) {\n      int i = p >> s;\n      if (lazy[i]\
    \ != L0) {\n        apply(2 * i, lazy[i]);\n        apply(2 * i + 1, lazy[i]);\n\
    \        lazy[i] = L0;\n      }\n    }\n  }\n  void set(int p, T x) {\n    p +=\
    \ n;\n    for (int i = h; i > 0; --i) {  // C\u1EA7n push s\u1EA1ch \u0111\u01B0\
    \u1EDDng \u0111i tr\u01B0\u1EDBc khi set\n      int node = p >> i;\n      if (lazy[node]\
    \ != L0) {\n        apply(2 * node, lazy[node]);\n        apply(2 * node + 1,\
    \ lazy[node]);\n        lazy[node] = L0;\n      }\n    }\n    seg[p] = x, pull(p);\
    \  // C\u1EADp nh\u1EADt ng\u01B0\u1EE3c l\xEAn\n  }\n  // Update \u0111o\u1EA1\
    n [l, r)\n  void upd(int l, int r, L val) {\n    l += n, r += n;\n    int l0 =\
    \ l, r0 = r;\n    push(l0), push(r0 - 1);\n    for (; l < r; l >>= 1, r >>= 1)\
    \ {\n      if (l & 1) apply(l++, val);\n      if (r & 1) apply(--r, val);\n  \
    \  }\n    pull(l0), pull(r0 - 1);\n  }\n  // Query \u0111o\u1EA1n [l, r)\n  T\
    \ qry(int l, int r) {\n    l += n, r += n;\n    push(l), push(r - 1);\n    T resL\
    \ = I, resR = I;\n    for (; l < r; l >>= 1, r >>= 1) {\n      if (l & 1) resL\
    \ = f(resL, seg[l++]);\n      if (r & 1) resR = f(seg[--r], resR);\n    }\n  \
    \  return f(resL, resR);\n  }\n};\n#line 6 \"tests/Range_Affine_Point_Get.test.cpp\"\
    \n\nusing Fp = modint<998244353>;\n\nvoid solve() {\n  int n, q;\n  cin >> n >>\
    \ q;\n\n  using P = pair<Fp, Fp>;\n  auto f = [](P a, P b) { return P{a.first\
    \ + b.first, a.second + b.second}; };\n  auto m = [](P a, P b) { return P{a.first\
    \ * b.first + a.second * b.second, a.second}; };\n  auto c = [](P a, P b) { return\
    \ P{a.first * b.first, a.second * b.first + b.second}; };\n  P I = {0, 0};\n \
    \ P L0 = {1, 0};\n  LazySegTree t(n, I, L0, f, m, c);\n  for (int i = 0; i < n;\
    \ ++i) {\n    int x;\n    cin >> x;\n    t.set(i, P{x, 1});\n  }\n  while (q--)\
    \ {\n    int cmd;\n    cin >> cmd;\n    if (cmd == 0) {\n      int l, r, c, d;\n\
    \      cin >> l >> r >> c >> d;\n      t.upd(l, r, P{c, d});\n    } else {\n \
    \     int i;\n      cin >> i;\n      cout << t.qry(i, i + 1).first << '\\n';\n\
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
    \ {\n      int l, r, c, d;\n      cin >> l >> r >> c >> d;\n      t.upd(l, r,\
    \ P{c, d});\n    } else {\n      int i;\n      cin >> i;\n      cout << t.qry(i,\
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
  timestamp: '2025-11-18 22:42:15+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/Range_Affine_Point_Get.test.cpp
layout: document
redirect_from:
- /verify/tests/Range_Affine_Point_Get.test.cpp
- /verify/tests/Range_Affine_Point_Get.test.cpp.html
title: tests/Range_Affine_Point_Get.test.cpp
---
