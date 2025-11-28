---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/Min25.h
    title: math/Min25.h
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
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_multiplicative_function
    links:
    - https://judge.yosupo.jp/problem/sum_of_multiplicative_function
  bundledCode: "#line 1 \"math/Sum_of_Multiplicative_Function.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/sum_of_multiplicative_function\"\n\
    \n#line 1 \"misc/macros.h\"\n// #pragma GCC optimize(\"Ofast,unroll-loops\") \
    \      // unroll long, simple loops\n// #pragma GCC target(\"avx2,fma\")     \
    \              // vectorizing code\n// #pragma GCC target(\"lzcnt,popcnt,abm,bmi,bmi2\"\
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
    \    v.insert(v.mutable_begin(), cur);\n*/\n#line 1 \"math/Min25.h\"\ntemplate\
    \ <class T>\nstruct Min25 {\n  i64 n;\n  int sq;\n  vector<int> primes, id1, id2;\n\
    \  vector<i64> vals;\n  vector<T> g0, g1;  // g0: sum p^0, g1: sum p^1\n  int\
    \ id(i64 x) { return x <= sq ? id1[x] : id2[n / x]; }\n  void init(i64 N) {\n\
    \    n = N, sq = sqrt(n);\n    primes.clear();\n    vector<bool> is_p(sq + 1,\
    \ true);\n    for (int i = 2; i <= sq; ++i) {\n      if (is_p[i]) {\n        primes.pb(i);\n\
    \        for (int j = i * 2; j <= sq; j += i) is_p[j] = false;\n      }\n    }\n\
    \    vals.clear(), id1.assign(sq + 1, 0), id2.assign(sq + 1, 0);\n    for (i64\
    \ l = 1, r; l <= n; l = r + 1) {\n      i64 v = n / l;\n      r = n / v;\n   \
    \   vals.pb(v);\n      if (v <= sq) id1[v] = sz(vals) - 1;\n      else id2[n /\
    \ v] = sz(vals) - 1;\n    }\n    g0.resize(sz(vals)), g1.resize(sz(vals));\n \
    \   T inv2 = T(1) / T(2);\n    for (int i = 0; i < sz(vals); ++i) {\n      T v\
    \ = T(vals[i]);\n      g0[i] = v - 1;\n      g1[i] = v * (v + 1) * inv2 - 1;\n\
    \    }\n    for (int p : primes) {\n      T sp0 = g0[id(p - 1)], sp1 = g1[id(p\
    \ - 1)];\n      i64 p2 = (i64) p * p;\n      T tp = T(p);\n      for (int i =\
    \ 0; i < sz(vals); ++i) {\n        if (vals[i] < p2) break;\n        int k = id(vals[i]\
    \ / p);\n        g0[i] -= g0[k] - sp0;\n        g1[i] -= tp * (g1[k] - sp1);\n\
    \      }\n    }\n  }\n  // A, B: f(p) = A*1 + B*p\n  // func: (p, e) -> f(p^e)\
    \ tr\u1EA3 v\u1EC1 T\n  template <class Func>\n  T solve(T A, T B, Func f_pe)\
    \ {\n    vector<T> s_fp(sz(primes) + 1);\n    for (int i = 0; i < sz(primes);\
    \ ++i)\n      s_fp[i + 1] = s_fp[i] + A + B * T(primes[i]);\n\n    auto S = [&](auto&&\
    \ self, i64 x, int j) -> T {\n      if (x <= 1 || (j < sz(primes) && primes[j]\
    \ > x)) return 0;\n      int k = id(x);\n      T ans = A * g0[k] + B * g1[k];\n\
    \      ans -= s_fp[j];\n      for (int i = j; i < sz(primes); ++i) {\n       \
    \ i64 p = primes[i];\n        if (p * p > x) break;\n        i64 pe = p;\n   \
    \     for (int e = 1; pe * p <= x; ++e) {\n          ans += f_pe(p, e) * self(self,\
    \ x / pe, i + 1);\n          ans += f_pe(p, e + 1);\n          pe *= p;\n    \
    \    }\n      }\n      return ans;\n    };\n    return S(S, n, 0) + 1;\n  }\n\
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
    \ x, m);\n    k >>= 1;\n  }\n  return res;\n}\n#line 6 \"math/Sum_of_Multiplicative_Function.test.cpp\"\
    \n\nusing Fp = modint<469762049>;\n\nvoid solve() {\n  Min25<Fp> solver;\n  i64\
    \ n;\n  Fp a, b;\n  cin >> n >> a >> b;\n  solver.init(n);\n  cout << solver.solve(a,\
    \ b, [&](i64 p, int e) {\n    return a * e + b * p;\n  }) << '\\n';\n}\n\nsigned\
    \ main() {\n  ios::sync_with_stdio(false);\n  cin.tie(0);\n  int tc = 1;\n  cin\
    \ >> tc;\n  while (tc--) solve();\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_multiplicative_function\"\
    \n\n#include \"../misc/macros.h\"\n#include \"../math/Min25.h\"\n#include \"../math/ModInt.h\"\
    \n\nusing Fp = modint<469762049>;\n\nvoid solve() {\n  Min25<Fp> solver;\n  i64\
    \ n;\n  Fp a, b;\n  cin >> n >> a >> b;\n  solver.init(n);\n  cout << solver.solve(a,\
    \ b, [&](i64 p, int e) {\n    return a * e + b * p;\n  }) << '\\n';\n}\n\nsigned\
    \ main() {\n  ios::sync_with_stdio(false);\n  cin.tie(0);\n  int tc = 1;\n  cin\
    \ >> tc;\n  while (tc--) solve();\n}"
  dependsOn:
  - misc/macros.h
  - math/Min25.h
  - math/ModInt.h
  isVerificationFile: true
  path: math/Sum_of_Multiplicative_Function.test.cpp
  requiredBy: []
  timestamp: '2025-11-28 10:18:48+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: math/Sum_of_Multiplicative_Function.test.cpp
layout: document
redirect_from:
- /verify/math/Sum_of_Multiplicative_Function.test.cpp
- /verify/math/Sum_of_Multiplicative_Function.test.cpp.html
title: math/Sum_of_Multiplicative_Function.test.cpp
---
