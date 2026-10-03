---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: ds/PersistentSegTree.h
    title: ds/PersistentSegTree.h
  - icon: ':question:'
    path: math/Affine.h
    title: math/Affine.h
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
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite_large_array
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite_large_array
  bundledCode: "#line 1 \"tests/Point_Set_Range_Composite_Large.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite_large_array\"\
    \n\n#line 1 \"misc/macros.h\"\n// #pragma GCC optimize(\"Ofast,unroll-loops\"\
    )       // unroll long, simple loops\n// #pragma GCC target(\"avx2,fma\")    \
    \               // vectorizing code\n// #pragma GCC target(\"lzcnt,popcnt,abm,bmi,bmi2\"\
    )  // for fast bitset operation\n\n#include <bits/extc++.h>\n\nusing namespace\
    \ std;\nusing namespace __gnu_pbds;  // ordered_set, gp_hash_table\n// using namespace\
    \ __gnu_cxx; // rope\n\n// for templates to work\n#define all(x) (x).begin(),\
    \ (x).end()\n#define len(x) (int) (x).size()\n#define pb push_back\n#define eb\
    \ emplace_back\nusing i32 = int32_t;\nusing u32 = uint32_t;\nusing i64 = int64_t;\n\
    using u64 = uint64_t;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\nusing\
    \ ld = long double;\nusing pii = pair<i32, i32>;\nusing vi = vector<i32>;\n\n\
    // fast map\nconst int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();\n\
    struct chash {  // customize hash function for gp_hash_table\n  int operator()(int\
    \ x) const { return x ^ RANDOM; }\n};\ngp_hash_table<int, int, chash> table;\n\
    \n/* ordered set\n    find_by_order(k): returns an iterator to the k-th element\
    \ (0-based)\n    order_of_key(k): returns the number of elements in the set that\
    \ are strictly less than k\n*/\ntemplate <class T>\nusing ordered_set = tree<T,\
    \ null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;\n\n/* \
    \ rope\n    rope <int> cur = v.substr(l, r - l + 1);\n    v.erase(l, r - l + 1);\n\
    \    v.insert(v.mutable_begin(), cur);\n*/\n#line 2 \"math/ModInt.h\"\n\ntemplate\
    \ <int mod>\nstruct modint {\n  using M = modint;\n  static_assert(mod > 0 &&\
    \ mod <= 2147483647);\n  static constexpr int modulo = mod;\n  static constexpr\
    \ u32 r1 = []() {\n    u32 r1 = mod;\n    for (int i = 0; i < 5; ++i) r1 *= 2\
    \ - mod * r1;\n    return -r1;\n  }();\n  static constexpr u32 r2 = -u64(mod)\
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
    \ 1 \"math/Affine.h\"\ntemplate <class T>\nstruct affine {\n  T a, b;\n  constexpr\
    \ affine() : a(1), b(0) {}\n  constexpr affine(T a, T b) : a(a), b(b) {}\n  T\
    \ operator()(T x) const { return a * x + b; }\n  affine operator()(const affine&\
    \ f) const {\n    return f * (*this);\n  }\n  affine operator*(const affine& g)\
    \ const {  // g(f(x))\n    return {a * g.a, b * g.a + g.b};\n  }\n  affine operator!=(const\
    \ affine& g) const {\n    return a != g.a || b != g.b;\n  }\n};\n#line 1 \"ds/PersistentSegTree.h\"\
    \n/*\n  Persistent + Dynamic Segment Tree that supports Monoid operation.\n  Tested\
    \ on https://cses.fi/problemset/task/1737/\n*/\n\ntemplate <class T, class F>\n\
    struct PST {\n  struct Node {\n    T v;\n    Node *l = nullptr, *r = nullptr;\n\
    \    Node(T v) : v(v) {}\n  };\n  int n;\n  const F f;\n  const T I;\n  PST(int\
    \ n, F f, const T& I) : n(n), f(f), I(I) {}\n  T get_val(Node* u) const { return\
    \ u ? u->v : I; }\n\n  Node* apply(Node* prev, int L, int R, int pos, const T&\
    \ nv) {\n    Node* u = new Node(prev ? prev->v : I);\n    if (prev) u->l = prev->l,\
    \ u->r = prev->r;\n    if (L == R) {\n      u->v = nv;\n      return u;\n    }\n\
    \    int M = (L + R) >> 1;\n    if (pos <= M) {\n      u->l = apply(u->l, L, M,\
    \ pos, nv);\n    } else {\n      u->r = apply(u->r, M + 1, R, pos, nv);\n    }\n\
    \    u->v = f(get_val(u->l), get_val(u->r));\n    return u;\n  }\n  // [ql, qr]\
    \ inclusive\n  T query(Node* u, int L, int R, int ql, int qr) const {\n    if\
    \ (!u || qr < L || R < ql) return I;\n    if (ql <= L && R <= qr) return u->v;\n\
    \    int M = (L + R) >> 1;\n    return f(query(u->l, L, M, ql, qr), query(u->r,\
    \ M + 1, R, ql, qr));\n  }\n};\n#line 7 \"tests/Point_Set_Range_Composite_Large.test.cpp\"\
    \n\nusing Fp = modint<998244353>;\nusing A = affine<Fp>;\n\nvoid solve() {\n \
    \ int n, q;\n  cin >> n >> q;\n  PST pst(n, [&](const A& l, const A& r) { return\
    \ l * r; }, A{});\n  decltype(pst)::Node* root = nullptr;\n  while (q--) {\n \
    \   int cmd;\n    cin >> cmd;\n    if (cmd == 0) {\n      int p, c, d;\n     \
    \ cin >> p >> c >> d;\n      auto new_node = pst.apply(root, 0, n - 1, p, A{c,\
    \ d});\n      root = new_node;\n    } else {\n      int l, r, x;\n      cin >>\
    \ l >> r >> x;\n      auto fc = pst.query(root, 0, n - 1, l, r - 1);\n      cout\
    \ << fc(x) << '\\n';\n    }\n  }\n}\n\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n\
    \  cin.exceptions(cin.failbit);\n  int tc = 1;\n  // cin >> tc;\n  for (int i\
    \ = 1; i <= tc; ++i) {\n    solve();\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite_large_array\"\
    \n\n#include \"../misc/macros.h\"\n#include \"../math/ModInt.h\"\n#include \"\
    ../math/Affine.h\"\n#include \"../ds/PersistentSegTree.h\"\n\nusing Fp = modint<998244353>;\n\
    using A = affine<Fp>;\n\nvoid solve() {\n  int n, q;\n  cin >> n >> q;\n  PST\
    \ pst(n, [&](const A& l, const A& r) { return l * r; }, A{});\n  decltype(pst)::Node*\
    \ root = nullptr;\n  while (q--) {\n    int cmd;\n    cin >> cmd;\n    if (cmd\
    \ == 0) {\n      int p, c, d;\n      cin >> p >> c >> d;\n      auto new_node\
    \ = pst.apply(root, 0, n - 1, p, A{c, d});\n      root = new_node;\n    } else\
    \ {\n      int l, r, x;\n      cin >> l >> r >> x;\n      auto fc = pst.query(root,\
    \ 0, n - 1, l, r - 1);\n      cout << fc(x) << '\\n';\n    }\n  }\n}\n\nint main()\
    \ {\n  cin.tie(0)->sync_with_stdio(0);\n  cin.exceptions(cin.failbit);\n  int\
    \ tc = 1;\n  // cin >> tc;\n  for (int i = 1; i <= tc; ++i) {\n    solve();\n\
    \  }\n}\n"
  dependsOn:
  - misc/macros.h
  - math/ModInt.h
  - math/Affine.h
  - ds/PersistentSegTree.h
  isVerificationFile: true
  path: tests/Point_Set_Range_Composite_Large.test.cpp
  requiredBy: []
  timestamp: '2026-10-03 15:27:40+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: tests/Point_Set_Range_Composite_Large.test.cpp
layout: document
redirect_from:
- /verify/tests/Point_Set_Range_Composite_Large.test.cpp
- /verify/tests/Point_Set_Range_Composite_Large.test.cpp.html
title: tests/Point_Set_Range_Composite_Large.test.cpp
---
