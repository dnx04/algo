---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/ModInt.h
    title: math/ModInt.h
  - icon: ':x:'
    path: math/ZetaMobius.h
    title: math/ZetaMobius.h
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
    PROBLEM: https://judge.yosupo.jp/problem/lcm_convolution
    links:
    - https://judge.yosupo.jp/problem/lcm_convolution
  bundledCode: "#line 1 \"tests/LCM_Convolution.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/lcm_convolution\"\
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
    \    v.insert(v.mutable_begin(), cur);\n*/\n#line 1 \"math/ZetaMobius.h\"\nconstexpr\
    \ int MAXN = 1e6 + 5;\nvector<int> P;\nbitset<MAXN> is_p;\n\nvoid sieve(int n)\
    \ {\n  is_p.set();\n  is_p[0] = is_p[1] = 0;\n  for (int i = 2; i <= n; ++i) {\n\
    \    if (is_p[i]) P.pb(i);\n    for (int p : P) {\n      if (i * p > n) break;\n\
    \      is_p[i * p] = 0;\n      if (i % p == 0) break;\n    }\n  }\n}\n\n// div=0:\
    \ Multiple (GCD), div=1: Divisor (LCM)\ntemplate <class Fp>\nvoid zeta(vector<Fp>&\
    \ f, bool div) {\n  int n = len(f) - 1;\n  for (int p : P) {\n    if (p > n) break;\n\
    \    if (!div)\n      for (int j = n / p; j >= 1; --j) f[j] += f[j * p];\n   \
    \ else\n      for (int j = 1; j * p <= n; ++j) f[j * p] += f[j];\n  }\n}\n\ntemplate\
    \ <class Fp>\nvoid mobius(vector<Fp>& f, bool div) {\n  int n = len(f) - 1;\n\
    \  for (int p : P) {\n    if (p > n) break;\n    if (!div)\n      for (int j =\
    \ 1; j <= n / p; ++j) f[j] -= f[j * p];\n    else\n      for (int j = n / p; j\
    \ >= 1; --j) f[j * p] -= f[j];\n  }\n}\n\ntemplate <class Fp>\nvector<Fp> convolution(vector<Fp>\
    \ f, vector<Fp> g, bool div) {\n  int n = min(len(f), len(g)) - 1;\n  f.resize(n\
    \ + 1);\n  g.resize(n + 1);\n  zeta(f, div), zeta(g, div);\n  vector<Fp> h(n +\
    \ 1);\n  for (int i = 1; i <= n; ++i) h[i] = f[i] * g[i];\n  mobius(h, div);\n\
    \  return h;\n}\n#line 2 \"math/ModInt.h\"\n\ntemplate <int mod>\nstruct modint\
    \ {\n  using M = modint;\n  static_assert(mod > 0 && mod <= 2147483647);\n  static\
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
    \ x, m);\n    k >>= 1;\n  }\n  return res;\n}\n#line 6 \"tests/LCM_Convolution.test.cpp\"\
    \n\nvoid solve() {\n  using Fp = modint<998244353>;\n  int n;\n  cin >> n;\n \
    \ sieve(n);\n  vector<Fp> a(n + 1), b(n + 1);\n  for(int i = 1; i <= n; ++i) cin\
    \ >> a[i];\n  for(int i = 1; i <= n; ++i) cin >> b[i];\n  auto c = convolution(a,\
    \ b, 1);\n  // cerr << \"ok\";\n  for(int i = 1; i <= n; ++i) cout << c[i] <<\
    \ ' ';\n}\n\nsigned main() {\n  ios::sync_with_stdio(false);\n  cin.tie(0);\n\
    \  int tc = 1;\n  // cin >> tc;\n  while (tc--) solve();\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lcm_convolution\"\n\n#include\
    \ \"../misc/macros.h\"\n#include \"../math/ZetaMobius.h\"\n#include \"../math/ModInt.h\"\
    \n\nvoid solve() {\n  using Fp = modint<998244353>;\n  int n;\n  cin >> n;\n \
    \ sieve(n);\n  vector<Fp> a(n + 1), b(n + 1);\n  for(int i = 1; i <= n; ++i) cin\
    \ >> a[i];\n  for(int i = 1; i <= n; ++i) cin >> b[i];\n  auto c = convolution(a,\
    \ b, 1);\n  // cerr << \"ok\";\n  for(int i = 1; i <= n; ++i) cout << c[i] <<\
    \ ' ';\n}\n\nsigned main() {\n  ios::sync_with_stdio(false);\n  cin.tie(0);\n\
    \  int tc = 1;\n  // cin >> tc;\n  while (tc--) solve();\n}"
  dependsOn:
  - misc/macros.h
  - math/ZetaMobius.h
  - math/ModInt.h
  isVerificationFile: true
  path: tests/LCM_Convolution.test.cpp
  requiredBy: []
  timestamp: '2026-10-03 15:27:40+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: tests/LCM_Convolution.test.cpp
layout: document
redirect_from:
- /verify/tests/LCM_Convolution.test.cpp
- /verify/tests/LCM_Convolution.test.cpp.html
title: tests/LCM_Convolution.test.cpp
---
