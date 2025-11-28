---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/FST.h
    title: math/FST.h
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
    PROBLEM: https://judge.yosupo.jp/problem/subset_convolution
    links:
    - https://judge.yosupo.jp/problem/subset_convolution
  bundledCode: "#line 1 \"tests/Bitwise_Subset_Convolution.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/subset_convolution\"\n\n#line 1 \"misc/macros.h\"\
    \n// #pragma GCC optimize(\"Ofast,unroll-loops\")       // unroll long, simple\
    \ loops\n// #pragma GCC target(\"avx2,fma\")                   // vectorizing\
    \ code\n// #pragma GCC target(\"lzcnt,popcnt,abm,bmi,bmi2\")  // for fast bitset\
    \ operation\n\n#include <bits/extc++.h>\n#include <tr2/dynamic_bitset>\n\nusing\
    \ namespace std;\nusing namespace __gnu_pbds;  // ordered_set, gp_hash_table\n\
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
    \ 1 \"math/FST.h\"\n#define pc __builtin_popcount\n\nnamespace FST {\n  enum {\
    \ OR, AND, XOR };\n  template<class T>\n  void fwht(vector<T>& a, int op, int\
    \ inv) {\n    int n = sz(a);\n    for (int l = 1; l < n; l <<= 1)\n      for (int\
    \ i = 0; i < n; i += 2 * l)\n        for (int j = 0; j < l; ++j) {\n         \
    \ T u = a[i + j], v = a[i + j + l];\n          if (op == OR) a[i + j + l] += inv\
    \ ? -u : u;\n          else if (op == AND) a[i + j] += inv ? -v : v;\n       \
    \   else a[i + j] = u + v, a[i + j + l] = u - v;\n        }\n    if (op == XOR\
    \ && inv) {\n      T in = T(1) / n;\n      for (auto& x : a) x *= in;\n    }\n\
    \  }\n  template<class T>\n  vector<T> conv(vector<T> a, vector<T> b, int op)\
    \ {\n    int n = 1; while (n < max(sz(a), sz(b))) n <<= 1;\n    a.resize(n), b.resize(n);\n\
    \    fwht(a, op, 0), fwht(b, op, 0);\n    for (int i = 0; i < n; ++i) a[i] *=\
    \ b[i];\n    fwht(a, op, 1);\n    return a;\n  }\n  template<class T>\n  vector<T>\
    \ subsetConv(const vector<T>& a, const vector<T>& b) {\n    int n = 1, k = 0;\n\
    \    while (n < max(sz(a), sz(b))) n <<= 1, k++;\n    vector<vector<T>> fa(k +\
    \ 1, vector<T>(n)), fb(k + 1, vector<T>(n)), h(k + 1, vector<T>(n));\n    for\
    \ (int i = 0; i < n; ++i) {\n      if (i < sz(a)) fa[pc(i)][i] = a[i];\n     \
    \ if (i < sz(b)) fb[pc(i)][i] = b[i];\n    }\n    for (int i = 0; i <= k; ++i)\
    \ fwht(fa[i], OR, 0), fwht(fb[i], OR, 0);\n    for (int i = 0; i <= k; ++i)\n\
    \      for (int j = 0; j <= i; ++j)\n        for (int x = 0; x < n; ++x) h[i][x]\
    \ += fa[j][x] * fb[i - j][x];\n    for (int i = 0; i <= k; ++i) fwht(h[i], OR,\
    \ 1);\n    vector<T> res(n);\n    for (int i = 0; i < n; ++i) res[i] = h[pc(i)][i];\n\
    \    return res;\n  }\n}\n#line 6 \"tests/Bitwise_Subset_Convolution.test.cpp\"\
    \n\nusing namespace FST;\nusing Fp = modint<998244353>;\n\nvoid solve() {\n  int\
    \ n;\n  cin >> n;\n  vector<Fp> a(1 << n), b(1 << n);\n  for (int i = 0; i < (1\
    \ << n); ++i) cin >> a[i];\n  for (int i = 0; i < (1 << n); ++i) cin >> b[i];\n\
    \  auto c = subsetConv(a, b);\n  for(auto e: c) cout << e << ' ';\n}\n\nsigned\
    \ main() {\n  ios::sync_with_stdio(false);\n  cin.tie(0);\n  int tc = 1;\n  //\
    \ cin >> tc;\n  while (tc--) solve();\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/subset_convolution\"\n\n\
    #include \"../misc/macros.h\"\n#include \"../math/ModInt.h\"\n#include \"../math/FST.h\"\
    \n\nusing namespace FST;\nusing Fp = modint<998244353>;\n\nvoid solve() {\n  int\
    \ n;\n  cin >> n;\n  vector<Fp> a(1 << n), b(1 << n);\n  for (int i = 0; i < (1\
    \ << n); ++i) cin >> a[i];\n  for (int i = 0; i < (1 << n); ++i) cin >> b[i];\n\
    \  auto c = subsetConv(a, b);\n  for(auto e: c) cout << e << ' ';\n}\n\nsigned\
    \ main() {\n  ios::sync_with_stdio(false);\n  cin.tie(0);\n  int tc = 1;\n  //\
    \ cin >> tc;\n  while (tc--) solve();\n}"
  dependsOn:
  - misc/macros.h
  - math/ModInt.h
  - math/FST.h
  isVerificationFile: true
  path: tests/Bitwise_Subset_Convolution.test.cpp
  requiredBy: []
  timestamp: '2025-11-28 12:47:29+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/Bitwise_Subset_Convolution.test.cpp
layout: document
redirect_from:
- /verify/tests/Bitwise_Subset_Convolution.test.cpp
- /verify/tests/Bitwise_Subset_Convolution.test.cpp.html
title: tests/Bitwise_Subset_Convolution.test.cpp
---
