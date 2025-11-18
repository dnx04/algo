---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/PersistentSegTree.h
    title: ds/PersistentSegTree.h
  - icon: ':heavy_check_mark:'
    path: math/Affine.h
    title: math/Affine.h
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
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite_large_array
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite_large_array
  bundledCode: "#line 1 \"tests/Point_Set_Range_Composite_Large.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite_large_array\"\
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
    \ 1 \"math/Affine.h\"\ntemplate <typename T>\nstruct affine {\n  T a, b;\n  constexpr\
    \ affine() : a(1), b(0) {}\n  constexpr affine(T a, T b) : a(a), b(b) {}\n  T\
    \ operator()(T x) const { return a * x + b; }\n  affine operator()(const affine&\
    \ f) const {\n    return f * (*this);\n  }\n  affine operator*(const affine& g)\
    \ const {  // g(f(x))\n    return {a * g.a, b * g.a + g.b};\n  }\n  affine operator!=(const\
    \ affine& g) const {\n    return a != g.a || b != g.b;\n  }\n};\n#line 1 \"ds/PersistentSegTree.h\"\
    \n/*\n  Persistent + Dynamic Segment Tree that supports Monoid operation.\n  Tested\
    \ on https://cses.fi/problemset/task/1737/\n\n  Usage:\n  - monoids = {f, id},\
    \ here f = u + v and id = 0:\n\n  PST pst((n + q) * log(n) * 2, f, 0ll);\n  vector<PST<ll,\
    \ decltype(f)>*> roots;\n  roots.reserve(q + 1);\n  roots.push_back(pst.build(0,\
    \ n - 1, a));\n*/\n\ntemplate <class T, class F>\nstruct PST {\n  struct Node\
    \ {\n    T v;\n    Node *l = nullptr, *r = nullptr;\n    Node(T v) : v(v) {}\n\
    \  };\n  int n;\n  const F f;\n  const T I;\n  PST(int n, F f, const T& I) : n(n),\
    \ f(f), I(I) {}\n  T get_val(Node* u) const { return u ? u->v : I; }\n\n  Node*\
    \ update(Node* prev, int L, int R, int pos, const T& nv) {\n    Node* u = new\
    \ Node(prev ? prev->v : I);\n    if (prev) u->l = prev->l, u->r = prev->r;\n \
    \   if (L == R) {\n      u->v = nv;\n      return u;\n    }\n    int M = (L +\
    \ R) >> 1;\n    if (pos <= M) {\n      u->l = update(u->l, L, M, pos, nv);\n \
    \   } else {\n      u->r = update(u->r, M + 1, R, pos, nv);\n    }\n    u->v =\
    \ f(get_val(u->l), get_val(u->r));\n    return u;\n  }\n  // [ql, qr] inclusive\n\
    \  T query(Node* u, int L, int R, int ql, int qr) const {\n    if (!u || qr <\
    \ L || R < ql) return I;\n    if (ql <= L && R <= qr) return u->v;\n    int M\
    \ = (L + R) >> 1;\n    return f(query(u->l, L, M, ql, qr), query(u->r, M + 1,\
    \ R, ql, qr));\n  }\n};\n#line 7 \"tests/Point_Set_Range_Composite_Large.test.cpp\"\
    \n\nusing Fp = modint<998244353>;\nusing A = affine<Fp>;\n\nvoid solve() {\n \
    \ int n, q;\n  cin >> n >> q;\n  PST pst(n, [&](const A& l, const A& r) { return\
    \ l * r; }, A{});\n  decltype(pst)::Node* root = nullptr;\n  while (q--) {\n \
    \   int cmd;\n    cin >> cmd;\n    if (cmd == 0) {\n      int p, c, d;\n     \
    \ cin >> p >> c >> d;\n      auto new_node = pst.update(root, 0, n - 1, p, A{c,\
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
    \ = pst.update(root, 0, n - 1, p, A{c, d});\n      root = new_node;\n    } else\
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
  timestamp: '2025-11-18 22:42:15+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/Point_Set_Range_Composite_Large.test.cpp
layout: document
redirect_from:
- /verify/tests/Point_Set_Range_Composite_Large.test.cpp
- /verify/tests/Point_Set_Range_Composite_Large.test.cpp.html
title: tests/Point_Set_Range_Composite_Large.test.cpp
---
