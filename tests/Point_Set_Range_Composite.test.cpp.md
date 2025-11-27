---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/SegTree.h
    title: ds/SegTree.h
  - icon: ':heavy_check_mark:'
    path: math/Affine.h
    title: math/Affine.h
  - icon: ':heavy_check_mark:'
    path: math/ModInt.h
    title: math/ModInt.h
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
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"tests/Point_Set_Range_Composite.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/point_set_range_composite\"\n\n#line 1 \"\
    misc/macros.h\"\n// #pragma GCC optimize(\"Ofast,unroll-loops\")       // unroll\
    \ long, simple loops\n// #pragma GCC target(\"avx2,fma\")                   //\
    \ vectorizing code\n// #pragma GCC target(\"lzcnt,popcnt,abm,bmi,bmi2\")  // for\
    \ fast bitset operation\n\n#include <bits/extc++.h>\n\n#include <tr2/dynamic_bitset>\n\
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
    \ cur);\n*/\n#line 1 \"math/Affine.h\"\ntemplate <class T>\nstruct affine {\n\
    \  T a, b;\n  constexpr affine() : a(1), b(0) {}\n  constexpr affine(T a, T b)\
    \ : a(a), b(b) {}\n  T operator()(T x) const { return a * x + b; }\n  affine operator()(const\
    \ affine& f) const {\n    return f * (*this);\n  }\n  affine operator*(const affine&\
    \ g) const {  // g(f(x))\n    return {a * g.a, b * g.a + g.b};\n  }\n  affine\
    \ operator!=(const affine& g) const {\n    return a != g.a || b != g.b;\n  }\n\
    };\n#line 2 \"math/ModInt.h\"\n\ntemplate <int mod>\nstruct modint {\n  using\
    \ M = modint;\n  static_assert(mod > 0 && mod <= 2147483647);\n  static constexpr\
    \ int modulo = mod;\n  static constexpr u32 r1 = []() {\n    u32 r1 = mod;\n \
    \   for (int i = 0; i < 5; ++i) r1 *= 2 - mod * r1;\n    return -r1;\n  }();\n\
    \  static constexpr u32 r2 = -u64(mod) % mod;\n  static u32 reduce(u64 x) {\n\
    \    u32 y = u32(x) * r1, r = (x + u64(y) * mod) >> 32;\n    return r >= mod ?\
    \ r - mod : r;\n  }\n  u32 x;\n  modint() : x(0) {}\n  modint(i64 x) : x(reduce(u64(x\
    \ % mod + mod) * r2)) {}\n  M& operator+=(const M& a) {\n    if ((x += a.x) >=\
    \ mod) x -= mod;\n    return *this;\n  }\n  M& operator-=(const M& a) {\n    if\
    \ ((x += mod - a.x) >= mod) x -= mod;\n    return *this;\n  }\n  M& operator*=(const\
    \ M& a) {\n    x = reduce(u64(x) * a.x);\n    return *this;\n  }\n  M& operator/=(const\
    \ M& a) { return *this *= a.inv(); }\n  M operator-() const { return M(0) - *this;\
    \ }\n  M operator+(const M& a) const { return M(*this) += a; }\n  M operator-(const\
    \ M& a) const { return M(*this) -= a; }\n  M operator*(const M& a) const { return\
    \ M(*this) *= a; }\n  M operator/(const M& a) const { return M(*this) /= a; }\n\
    \  bool operator==(const M& a) const { return x == a.x; }\n  bool operator!=(const\
    \ M& a) const { return x != a.x; }\n  M pow(u64 k) const {\n    M res(1), b =\
    \ *this;\n    while (k) {\n      if (k & 1) res *= b;\n      b *= b, k >>= 1;\n\
    \    }\n    return res;\n  }\n  M inv() const { return pow(mod - 2); }\n  friend\
    \ ostream& operator<<(ostream& os, const M& a) {\n    return os << reduce(a.x);\n\
    \  }\n  friend istream& operator>>(istream& is, M& a) {\n    i64 v;\n    is >>\
    \ v;\n    a = M(v);\n    return is;\n  }\n};\n\nu64 modmul(u64 x, u64 y, u64 m)\
    \ { return u128(x) * y % m; }\nu64 modpow(u64 x, u64 k, u64 m) {\n  u64 res =\
    \ 1;\n  while (k) {\n    if (k & 1) res = modmul(res, x, m);\n    x = modmul(x,\
    \ x, m);\n    k >>= 1;\n  }\n  return res;\n}\n#line 1 \"ds/SegTree.h\"\n// 0-indexed\n\
    template <class T, class F>\nstruct SegTree {\n  int n, size;  // smallest size\
    \ = 2^k >= n\n  vector<T> seg;\n  const F f;\n  const T I;\n  SegTree(int n, F\
    \ f, const T& I) : n(n), f(f), I(I) {\n    size = 1;\n    while (size < n) size\
    \ <<= 1;\n    seg.assign(size << 1, I);\n  }\n  T& operator[](int k) { return\
    \ seg[k + size]; }\n  void set(int k, T x) { seg[k + size] = x; }  // to build\n\
    \  void build() {\n    for (int i = size - 1; i > 0; --i) seg[i] = f(seg[i <<\
    \ 1], seg[i << 1 | 1]);\n  }\n  void apply(int k, T x) {\n    k += size, seg[k]\
    \ = x;\n    while (k >>= 1) seg[k] = f(seg[k << 1], seg[k << 1 | 1]);\n  }\n \
    \ // query [l, r)\n  T query(int l, int r) {\n    T L = I, R = I;\n    for (l\
    \ += size, r += size; l < r; l >>= 1, r >>= 1) {\n      if (l & 1) L = f(L, seg[l++]);\n\
    \      if (r & 1) R = f(seg[--r], R);\n    }\n    return f(L, R);\n  }\n  template\
    \ <class C>\n  int max_right(int l, C check) {\n    assert(0 <= l && l <= n &&\
    \ check(I) == true);\n    if (l == n) return n;\n    l += size;\n    T sm = I;\n\
    \    do {\n      while (l % 2 == 0) l >>= 1;\n      if (!check(f(sm, seg[l])))\
    \ {\n        while (l < size) {\n          l = l << 1;\n          if (check(f(sm,\
    \ seg[l]))) sm = f(sm, seg[l]), l++;\n        }\n        return l - size;\n  \
    \    }\n      sm = f(sm, seg[l]), l++;\n    } while ((l & -l) != l);\n    return\
    \ n;\n  }\n  template <class C>\n  int min_left(int r, C check) {\n    assert(0\
    \ <= r && r <= n && check(I) == true);\n    if (r == 0) return 0;\n    r += size;\n\
    \    T sm = I;\n    do {\n      r--;\n      while (r > 1 && (r % 2)) r >>= 1;\n\
    \      if (!check(f(seg[r], sm))) {\n        while (r < size) {\n          r =\
    \ r << 1 | 1;\n          if (check(f(seg[r], sm))) sm = f(seg[r], sm), r--;\n\
    \        }\n        return r + 1 - size;\n      }\n      sm = f(seg[r], sm);\n\
    \    } while ((r & -r) != r);\n    return 0;\n  }\n};\n#line 7 \"tests/Point_Set_Range_Composite.test.cpp\"\
    \n\nusing Fp = modint<998244353>;\nusing A = affine<Fp>;\n\nvoid solve() {\n \
    \ int n, q;\n  cin >> n >> q;\n  SegTree st(n, [&](const A& l, const A& r) { return\
    \ l * r; }, A{});\n  for (int i = 0; i < n; ++i) {\n    int a, b;\n    cin >>\
    \ a >> b;\n    st.apply(i, {a, b});\n  }\n  while (q--) {\n    int cmd;\n    cin\
    \ >> cmd;\n    if (cmd == 0) {\n      int p, c, d;\n      cin >> p >> c >> d;\n\
    \      st.apply(p, {c, d});\n    } else {\n      int l, r, x;\n      cin >> l\
    \ >> r >> x;\n      auto fc = st.query(l, r);\n      cout << fc(x) << '\\n';\n\
    \    }\n  }\n}\n\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n  cin.exceptions(cin.failbit);\n\
    \  int tc = 1;\n  // cin >> tc;\n  for (int i = 1; i <= tc; ++i) {\n    solve();\n\
    \  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#include \"../misc/macros.h\"\n#include \"../math/Affine.h\"\n#include \"\
    ../math/ModInt.h\"\n#include \"../ds/SegTree.h\"\n\nusing Fp = modint<998244353>;\n\
    using A = affine<Fp>;\n\nvoid solve() {\n  int n, q;\n  cin >> n >> q;\n  SegTree\
    \ st(n, [&](const A& l, const A& r) { return l * r; }, A{});\n  for (int i = 0;\
    \ i < n; ++i) {\n    int a, b;\n    cin >> a >> b;\n    st.apply(i, {a, b});\n\
    \  }\n  while (q--) {\n    int cmd;\n    cin >> cmd;\n    if (cmd == 0) {\n  \
    \    int p, c, d;\n      cin >> p >> c >> d;\n      st.apply(p, {c, d});\n   \
    \ } else {\n      int l, r, x;\n      cin >> l >> r >> x;\n      auto fc = st.query(l,\
    \ r);\n      cout << fc(x) << '\\n';\n    }\n  }\n}\n\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n\
    \  cin.exceptions(cin.failbit);\n  int tc = 1;\n  // cin >> tc;\n  for (int i\
    \ = 1; i <= tc; ++i) {\n    solve();\n  }\n}\n"
  dependsOn:
  - misc/macros.h
  - math/Affine.h
  - math/ModInt.h
  - ds/SegTree.h
  isVerificationFile: true
  path: tests/Point_Set_Range_Composite.test.cpp
  requiredBy: []
  timestamp: '2025-11-26 18:05:06+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/Point_Set_Range_Composite.test.cpp
layout: document
redirect_from:
- /verify/tests/Point_Set_Range_Composite.test.cpp
- /verify/tests/Point_Set_Range_Composite.test.cpp.html
title: tests/Point_Set_Range_Composite.test.cpp
---
