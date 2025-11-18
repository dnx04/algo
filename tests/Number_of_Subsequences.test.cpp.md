---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/ModInt.h
    title: math/ModInt.h
  - icon: ':heavy_check_mark:'
    path: misc/Compressor.h
    title: misc/Compressor.h
  - icon: ':heavy_check_mark:'
    path: misc/CountSubseq.h
    title: misc/CountSubseq.h
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
    PROBLEM: https://judge.yosupo.jp/problem/number_of_subsequences
    links:
    - https://judge.yosupo.jp/problem/number_of_subsequences
  bundledCode: "#line 1 \"tests/Number_of_Subsequences.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/number_of_subsequences\"\n\n#line 1 \"misc/macros.h\"\
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
    \ 1 \"misc/Compressor.h\"\ntemplate <typename T>\nvi compressor(vector<T>& v)\
    \ {\n  auto cv = v;\n  sort(all(cv));\n  cv.erase(unique(all(cv)), cv.end());\n\
    \  for (auto& e : v) e = lower_bound(all(cv), e) - cv.begin();\n  return v;\n\
    }\n#line 2 \"misc/CountSubseq.h\"\n\ntemplate <typename T, typename Fp>\nFp CountSubseq(vector<T>\
    \ a) {\n  a = compressor<T>(a);\n  vi last(sz(a) + 1, -1);\n  vector<Fp> f(sz(a)\
    \ + 1);\n  f[0] = 1;\n  for (int i = 0; i < sz(a); ++i) {\n    f[i + 1] = f[i]\
    \ * 2;\n    if (last[a[i]] >= 0) f[i + 1] -= f[last[a[i]]];\n    last[a[i]] =\
    \ i;\n  }\n  return f.back() - 1;\n}\n#line 6 \"tests/Number_of_Subsequences.test.cpp\"\
    \n\nusing Fp = modint<998244353>;\n\nsigned main() {\n  ios::sync_with_stdio(false);\n\
    \  cin.tie(0);\n  int n;\n  cin >> n;\n  vector<int> a(n);\n  for (auto& x : a)\
    \ cin >> x;\n  cout << CountSubseq<int, Fp>(a);\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/number_of_subsequences\"\
    \n\n#include \"../misc/macros.h\"\n#include \"../math/ModInt.h\"\n#include \"\
    ../misc/CountSubseq.h\"\n\nusing Fp = modint<998244353>;\n\nsigned main() {\n\
    \  ios::sync_with_stdio(false);\n  cin.tie(0);\n  int n;\n  cin >> n;\n  vector<int>\
    \ a(n);\n  for (auto& x : a) cin >> x;\n  cout << CountSubseq<int, Fp>(a);\n}"
  dependsOn:
  - misc/macros.h
  - math/ModInt.h
  - misc/CountSubseq.h
  - misc/Compressor.h
  isVerificationFile: true
  path: tests/Number_of_Subsequences.test.cpp
  requiredBy: []
  timestamp: '2025-11-18 17:12:08+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/Number_of_Subsequences.test.cpp
layout: document
redirect_from:
- /verify/tests/Number_of_Subsequences.test.cpp
- /verify/tests/Number_of_Subsequences.test.cpp.html
title: tests/Number_of_Subsequences.test.cpp
---
