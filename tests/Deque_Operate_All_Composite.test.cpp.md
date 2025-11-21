---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/SWAD.h
    title: ds/SWAD.h
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
    PROBLEM: https://judge.yosupo.jp/problem/deque_operate_all_composite
    links:
    - https://judge.yosupo.jp/problem/deque_operate_all_composite
  bundledCode: "#line 1 \"tests/Deque_Operate_All_Composite.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/deque_operate_all_composite\"\n\n#line 1 \"\
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
    \ 1 \"math/Affine.h\"\ntemplate <class T>\nstruct affine {\n  T a, b;\n  constexpr\
    \ affine() : a(1), b(0) {}\n  constexpr affine(T a, T b) : a(a), b(b) {}\n  T\
    \ operator()(T x) const { return a * x + b; }\n  affine operator()(const affine&\
    \ f) const {\n    return f * (*this);\n  }\n  affine operator*(const affine& g)\
    \ const {  // g(f(x))\n    return {a * g.a, b * g.a + g.b};\n  }\n  affine operator!=(const\
    \ affine& g) const {\n    return a != g.a || b != g.b;\n  }\n};\n#line 1 \"ds/SWAD.h\"\
    \ntemplate <class T, class F>\nstruct SWAD {\n  vector<T> a0, a1, r0, r1;\n  F\
    \ f;\n  T I;\n  SWAD(F f, T i) : f(f), I(i) {}\n\n private:\n  T get0() const\
    \ { return r0.empty() ? I : r0.back(); }\n  T get1() const { return r1.empty()\
    \ ? I : r1.back(); }\n\n  void push0(const T& x) {\n    a0.eb(x), r0.eb(f(x, get0()));\n\
    \  }\n  void push1(const T& x) {\n    a1.eb(x), r1.eb(f(get1(), x));\n  }\n  void\
    \ rebalance() {\n    int n = a0.size() + a1.size();\n    int s0 = n / 2 + (a0.empty()\
    \ ? n % 2 : 0);\n    vector<T> a{a0};\n    reverse(all(a));\n    copy(all(a1),\
    \ back_inserter(a));\n    a0.clear(), r0.clear(), a1.clear(), r1.clear();\n  \
    \  for (int i = s0 - 1; i >= 0; i--) push0(a[i]);\n    for (int i = s0; i < n;\
    \ i++) push1(a[i]);\n  }\n\n public:\n  void push_front(const T& t) { push0(t);\
    \ }\n  void push_back(const T& t) { push1(t); }\n  T front() const { return a0.empty()\
    \ ? a1.front() : a0.back(); }\n  T back() const { return a1.empty() ? a0.front()\
    \ : a1.back(); }\n  void pop_front() {\n    if (a0.empty()) rebalance();\n   \
    \ assert(!a0.empty());\n    a0.pop_back(), r0.pop_back();\n  }\n  void pop_back()\
    \ {\n    if (a1.empty()) rebalance();\n    assert(!a1.empty());\n    a1.pop_back(),\
    \ r1.pop_back();\n  }\n  T query() { return f(get0(), get1()); }\n};\n#line 7\
    \ \"tests/Deque_Operate_All_Composite.test.cpp\"\n\nvoid solve() {\n  using Fp\
    \ = modint<998244353>;\n  using A = affine<Fp>;\n  int q;\n  cin >> q;\n  SWAD\
    \ swag([](const A& f, const A& g) { return f * g; }, A{});\n  while (q--) {\n\
    \    int cmd;\n    cin >> cmd;\n    if (cmd == 0) {\n      int a, b;\n      cin\
    \ >> a >> b;\n      swag.push_front({a, b});\n    } else if (cmd == 1) {\n   \
    \   int a, b;\n      cin >> a >> b;\n      swag.push_back({a, b});\n    } else\
    \ if (cmd == 2) {\n      swag.pop_front();\n    } else if (cmd == 3) {\n     \
    \ swag.pop_back();\n    } else {\n      int x;\n      cin >> x;\n      cout <<\
    \ swag.query()(x) << '\\n';\n    }\n  }\n}\n\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n\
    \  cin.exceptions(cin.failbit);\n  int tc = 1;\n  //   cin >> tc;\n  for (int\
    \ i = 1; i <= tc; ++i) {\n    solve();\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/deque_operate_all_composite\"\
    \n\n#include \"../misc/macros.h\"\n#include \"../math/ModInt.h\"\n#include \"\
    ../math/Affine.h\"\n#include \"../ds/SWAD.h\"\n\nvoid solve() {\n  using Fp =\
    \ modint<998244353>;\n  using A = affine<Fp>;\n  int q;\n  cin >> q;\n  SWAD swag([](const\
    \ A& f, const A& g) { return f * g; }, A{});\n  while (q--) {\n    int cmd;\n\
    \    cin >> cmd;\n    if (cmd == 0) {\n      int a, b;\n      cin >> a >> b;\n\
    \      swag.push_front({a, b});\n    } else if (cmd == 1) {\n      int a, b;\n\
    \      cin >> a >> b;\n      swag.push_back({a, b});\n    } else if (cmd == 2)\
    \ {\n      swag.pop_front();\n    } else if (cmd == 3) {\n      swag.pop_back();\n\
    \    } else {\n      int x;\n      cin >> x;\n      cout << swag.query()(x) <<\
    \ '\\n';\n    }\n  }\n}\n\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n \
    \ cin.exceptions(cin.failbit);\n  int tc = 1;\n  //   cin >> tc;\n  for (int i\
    \ = 1; i <= tc; ++i) {\n    solve();\n  }\n}\n"
  dependsOn:
  - misc/macros.h
  - math/ModInt.h
  - math/Affine.h
  - ds/SWAD.h
  isVerificationFile: true
  path: tests/Deque_Operate_All_Composite.test.cpp
  requiredBy: []
  timestamp: '2025-11-21 16:12:02+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/Deque_Operate_All_Composite.test.cpp
layout: document
redirect_from:
- /verify/tests/Deque_Operate_All_Composite.test.cpp
- /verify/tests/Deque_Operate_All_Composite.test.cpp.html
title: tests/Deque_Operate_All_Composite.test.cpp
---
