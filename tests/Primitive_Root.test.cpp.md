---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/Factor.h
    title: math/Factor.h
  - icon: ':heavy_check_mark:'
    path: math/MillerRabin.h
    title: math/MillerRabin.h
  - icon: ':question:'
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
    PROBLEM: https://judge.yosupo.jp/problem/primitive_root
    links:
    - https://judge.yosupo.jp/problem/primitive_root
  bundledCode: "#line 1 \"tests/Primitive_Root.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/primitive_root\"\
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
    \ cur);\n*/\n#line 2 \"math/ModInt.h\"\n\ntemplate <int mod>\nstruct modint {\n\
    \  using M = modint;\n  static_assert(mod > 0 && mod <= 2147483647);\n  static\
    \ constexpr int modulo = mod;\n  static constexpr u32 r1 = []() {\n    u32 r1\
    \ = mod;\n    for (int i = 0; i < 5; ++i) r1 *= 2 - mod * r1;\n    return -r1;\n\
    \  }();\n  static constexpr u32 r2 = -u64(mod) % mod;\n  static u32 reduce(u64\
    \ x) {\n    u32 y = u32(x) * r1, r = (x + u64(y) * mod) >> 32;\n    return r >=\
    \ mod ? r - mod : r;\n  }\n  u32 x;\n  modint() : x(0) {}\n  modint(i64 x) : x(reduce(u64(x\
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
    \ x, m);\n    k >>= 1;\n  }\n  return res;\n}\n#line 1 \"math/MillerRabin.h\"\n\
    bool isPrime(u64 n) {\n  if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;\n \
    \ u64 A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},\n      s = __builtin_ctzll(n\
    \ - 1), d = n >> s;\n  for (u64 a : A) {  // ^ count trailing zeroes\n    u64\
    \ p = modpow(a % n, d, n), i = s;\n    while (p != 1 && p != n - 1 && a % n &&\
    \ i--) p = modmul(p, p, n);\n    if (p != n - 1 && i != s) return 0;\n  }\n  return\
    \ 1;\n}\n#line 3 \"math/Factor.h\"\n\nu64 pollard(u64 n) {\n  u64 x = 0, y = 0,\
    \ t = 30, prd = 2, i = 1, q;\n  auto f = [&](u64 x) { return modmul(x, x, n) +\
    \ i; };\n  while (t++ % 40 || gcd(prd, n) == 1) {\n    if (x == y) x = ++i, y\
    \ = f(x);\n    if ((q = modmul(prd, max(x, y) - min(x, y), n))) prd = q;\n   \
    \ x = f(x), y = f(f(y));\n  }\n  return gcd(prd, n);\n}\nvector<u64> factor(u64\
    \ n) {\n  if (n == 1) return {};\n  if (isPrime(n)) return {n};\n  u64 x = pollard(n);\n\
    \  auto l = factor(x), r = factor(n / x);\n  l.insert(l.end(), all(r));\n  return\
    \ l;\n}\n#line 5 \"tests/Primitive_Root.test.cpp\"\n\nvoid solve() {\n  u64 p;\n\
    \  cin >> p;\n  if (p == 2) {\n    cout << \"1\\n\";\n    return;\n  }\n  auto\
    \ f = factor(p - 1);\n  sort(all(f));\n  f.erase(unique(all(f)), f.end());\n \
    \ for (int g = 2;; ++g) {\n    bool ok = true;\n    for (auto pf : f) {\n    \
    \  if (modpow(g, (p - 1) / pf, p) == 1) {\n        ok = false;\n        break;\n\
    \      }\n    }\n    if (ok) {\n      cout << g << '\\n';\n      break;\n    }\n\
    \  }\n}\n\nint main() {\n  int tc = 1;\n  cin >> tc;\n  while (tc--) solve();\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/primitive_root\"\n\n#include\
    \ \"../misc/macros.h\"\n#include \"../math/Factor.h\"\n\nvoid solve() {\n  u64\
    \ p;\n  cin >> p;\n  if (p == 2) {\n    cout << \"1\\n\";\n    return;\n  }\n\
    \  auto f = factor(p - 1);\n  sort(all(f));\n  f.erase(unique(all(f)), f.end());\n\
    \  for (int g = 2;; ++g) {\n    bool ok = true;\n    for (auto pf : f) {\n   \
    \   if (modpow(g, (p - 1) / pf, p) == 1) {\n        ok = false;\n        break;\n\
    \      }\n    }\n    if (ok) {\n      cout << g << '\\n';\n      break;\n    }\n\
    \  }\n}\n\nint main() {\n  int tc = 1;\n  cin >> tc;\n  while (tc--) solve();\n\
    }"
  dependsOn:
  - misc/macros.h
  - math/Factor.h
  - math/ModInt.h
  - math/MillerRabin.h
  isVerificationFile: true
  path: tests/Primitive_Root.test.cpp
  requiredBy: []
  timestamp: '2025-11-26 18:05:06+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/Primitive_Root.test.cpp
layout: document
redirect_from:
- /verify/tests/Primitive_Root.test.cpp
- /verify/tests/Primitive_Root.test.cpp.html
title: tests/Primitive_Root.test.cpp
---
