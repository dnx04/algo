---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/ModInt.h
    title: math/ModInt.h
  - icon: ':question:'
    path: math/Poly.h
    title: math/Poly.h
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
    PROBLEM: https://judge.yosupo.jp/problem/stirling_number_of_the_first_kind_fixed_k
    links:
    - https://judge.yosupo.jp/problem/stirling_number_of_the_first_kind_fixed_k
  bundledCode: "#line 1 \"tests/Stirling_Number_1st_fixed_K.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/stirling_number_of_the_first_kind_fixed_k\"\
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
    \ 2 \"math/Poly.h\"\n\nusing Fp = modint<998244353>;\nnamespace ntt {\nconst Fp\
    \ G = 3;\nvoid ntt(vector<Fp>& a, bool inv) {\n  int n = len(a);\n  for (int i\
    \ = 1, j = 0; i < n; i++) {\n    int bit = n >> 1;\n    for (; j & bit; bit >>=\
    \ 1) j ^= bit;\n    j ^= bit;\n    if (i < j) swap(a[i], a[j]);\n  }\n  for (int\
    \ len = 1; len < n; len <<= 1) {\n    Fp wlen = G.pow((Fp::modulo - 1) / (2 *\
    \ len));\n    if (inv) wlen = wlen.inv();\n    for (int i = 0; i < n; i += 2 *\
    \ len) {\n      Fp w = 1;\n      for (int j = 0; j < len; j++) {\n        Fp u\
    \ = a[i + j], v = a[i + j + len] * w;\n        a[i + j] = u + v, a[i + j + len]\
    \ = u - v;\n        w *= wlen;\n      }\n    }\n  }\n  if (inv) {\n    Fp n_inv\
    \ = Fp(n).inv();\n    for (auto& x : a) x *= n_inv;\n  }\n}\nvector<Fp> conv(vector<Fp>\
    \ a, vector<Fp> b) {\n  if (a.empty() || b.empty()) return {};\n  int s = len(a)\
    \ + len(b) - 1, n = 1;\n  while (n < s) n <<= 1;\n  a.resize(n), b.resize(n);\n\
    \  ntt(a, 0), ntt(b, 0);\n  for (int i = 0; i < n; i++) a[i] *= b[i];\n  ntt(a,\
    \ 1), a.resize(s);\n  return a;\n}\n}  // namespace ntt\n\nstruct Poly : vector<Fp>\
    \ {\n  using vector::vector;\n  Poly(const vector<Fp>& v) : vector(v) {}\n\n \
    \ Poly cut(int n) const {\n    Poly res = *this;\n    res.resize(n);\n    return\
    \ res;\n  }\n\n  Poly operator+(const Poly& r) const {\n    Poly res = *this;\n\
    \    res.resize(max(len(*this), len(r)));\n    for (int i = 0; i < len(r); ++i)\
    \ res[i] += r[i];\n    return res;\n  }\n  Poly operator-(const Poly& r) const\
    \ {\n    Poly res = *this;\n    res.resize(max(len(*this), len(r)));\n    for\
    \ (int i = 0; i < len(r); ++i) res[i] -= r[i];\n    return res;\n  }\n  Poly operator*(const\
    \ Poly& r) const { return ntt::conv(*this, r); }\n  Poly operator*(Fp v) const\
    \ {\n    Poly res = *this;\n    for (auto& x : res) x *= v;\n    return res;\n\
    \  }\n  Poly& operator+=(const Poly& r) { return *this = *this + r; }\n  Poly&\
    \ operator-=(const Poly& r) { return *this = *this - r; }\n  Poly& operator*=(const\
    \ Poly& r) { return *this = *this * r; }\n\n  Poly deriv() const {\n    if (empty())\
    \ return {};\n    Poly res(len(*this) - 1);\n    for (int i = 1; i < len(*this);\
    \ ++i) res[i - 1] = data()[i] * i;\n    return res;\n  }\n  Poly integ() const\
    \ {\n    Poly res(len(*this) + 1);\n    for (int i = 0; i < len(*this); ++i) res[i\
    \ + 1] = data()[i] * Fp(i + 1).inv();\n    return res;\n  }\n  Poly inv(int n)\
    \ const {\n    Poly b = {data()[0].inv()};\n    for (int k = 1; k < n; k <<= 1)\
    \ {\n      Poly a = cut(2 * k), prod = b * b * a;\n      b.resize(2 * k);\n  \
    \    for (int i = 0; i < 2 * k; ++i) {\n        b[i] = b[i] * 2 - (i < len(prod)\
    \ ? prod[i] : Fp(0));\n      }\n    }\n    return b.cut(n);\n  }\n\n  Poly log(int\
    \ n) const { return (deriv() * inv(n)).integ().cut(n); }\n\n  Poly exp(int n)\
    \ const {\n    Poly b = {1};\n    for (int k = 1; k < n; k <<= 1) {\n      Poly\
    \ ln_b = b.log(2 * k), a = cut(2 * k), diff = a - ln_b;\n      diff[0] += 1, b\
    \ = (b * diff).cut(2 * k);\n    }\n    return b.cut(n);\n  }\n\n  Poly pow(i64\
    \ k, int n) const {\n    if (n == 0) return {};\n    if (k == 0) {\n      Poly\
    \ res = {1};\n      res.resize(n);\n      return res;\n    }\n    int i = 0;\n\
    \    while (i < len(*this) && data()[i].x == 0) i++;\n    if (i == len(*this)\
    \ || (i > 0 && k >= n / i + 2)) {\n      Poly res;\n      res.resize(n);\n   \
    \   return res;\n    }\n    i64 shift = (i64) i * k;\n    if (shift >= n) {\n\
    \      Poly res;\n      res.resize(n);\n      return res;\n    }\n    Poly a =\
    \ {begin() + i, end()};\n    int limit = n - shift;\n    a.resize(limit);\n  \
    \  Fp lead = a[0];\n    Fp inv_lead = lead.inv();\n    a = a * inv_lead;\n   \
    \ a = (a.log(limit) * Fp(k)).exp(limit);\n    a = a * lead.pow(k);\n    Poly res(shift,\
    \ 0);\n    res.insert(res.end(), a.begin(), a.end());\n    res.resize(n);\n  \
    \  return res;\n  }\n  friend ostream& operator<<(ostream& os, const Poly& p)\
    \ {\n    for (auto x : p) os << x << \" \";\n    return os;\n  }\n};\n#line 5\
    \ \"tests/Stirling_Number_1st_fixed_K.test.cpp\"\n\nvector<Fp> fact, invFact;\n\
    void init_fact(int n) {\n  fact.resize(n + 1);\n  invFact.resize(n + 1);\n  fact[0]\
    \ = 1;\n  for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i;\n  invFact[n]\
    \ = fact[n].inv();\n  for (int i = n - 1; i >= 0; i--) invFact[i] = invFact[i\
    \ + 1] * (i + 1);\n}\n\nFp nCk(int n, int k) {\n  if (k < 0 || k > n) return 0;\n\
    \  return fact[n] * invFact[k] * invFact[n - k];\n}\n\nvoid solve() {\n  // Stirling\
    \ lo\u1EA1i 1 v\u1EDBi k c\u1ED1 \u0111\u1ECBnh\n  // N\u1EBFu l\xE0 Stirling\
    \ lo\u1EA1i 1 kh\xF4ng d\u1EA5u th\xEC l\xE0 s\u1ED1 ho\xE1n v\u1ECB n ph\u1EA7\
    n t\u1EED c\xF3 \u0111\xFAng k chu tr\xECnh\n  // EGF: (ln(1/(1-x)))^k / k!\n\
    \  // ln(1/(1-x)) = x + x^2/2 + x^3/3 + ...\n  int N, K;\n  cin >> N >> K;\n \
    \ init_fact(N + 1);\n  if (K == 0) {\n    cout << \"1 \";  // S(0,0)\n    for\
    \ (int i = 1; i <= N; ++i) cout << \"0 \";\n    cout << \"\\n\";\n    return;\n\
    \  }\n\n  // 1. T\u1EA1o \u0111a th\u1EE9c A(x) = sum(x^i / i)\n  vector<Fp> a(N\
    \ + 1, 0);\n  for (int i = 1; i <= N; ++i) {\n    // 1/i = (i-1)! / i! = fact[i-1]\
    \ * invFact[i]\n    a[i] = fact[i - 1] * invFact[i];\n  }\n  Poly A(a);\n\n  //\
    \ 2. T\xEDnh G(x) = A(x)^K\n  Poly G = A.pow(K, N + 1);\n\n  // 3. K\u1EBFt qu\u1EA3\
    \ S(n, K) = G[n] * n! / K!\n  Fp invK = invFact[K];\n  for (int n = K; n <= N;\
    \ ++n) {\n    Fp val = G[n] * fact[n] * invK;\n    if((n - K) % 2 == 1) val =\
    \ -val;\n    cout << val << ' ';\n  }\n  cout << \"\\n\";\n}\n\nint main() {\n\
    \  ios_base::sync_with_stdio(false);\n  cin.tie(NULL);\n  solve();\n  return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/stirling_number_of_the_first_kind_fixed_k\"\
    \n\n#include \"../misc/macros.h\"\n#include \"../math/Poly.h\"\n\nvector<Fp> fact,\
    \ invFact;\nvoid init_fact(int n) {\n  fact.resize(n + 1);\n  invFact.resize(n\
    \ + 1);\n  fact[0] = 1;\n  for (int i = 1; i <= n; i++) fact[i] = fact[i - 1]\
    \ * i;\n  invFact[n] = fact[n].inv();\n  for (int i = n - 1; i >= 0; i--) invFact[i]\
    \ = invFact[i + 1] * (i + 1);\n}\n\nFp nCk(int n, int k) {\n  if (k < 0 || k >\
    \ n) return 0;\n  return fact[n] * invFact[k] * invFact[n - k];\n}\n\nvoid solve()\
    \ {\n  // Stirling lo\u1EA1i 1 v\u1EDBi k c\u1ED1 \u0111\u1ECBnh\n  // N\u1EBF\
    u l\xE0 Stirling lo\u1EA1i 1 kh\xF4ng d\u1EA5u th\xEC l\xE0 s\u1ED1 ho\xE1n v\u1ECB\
    \ n ph\u1EA7n t\u1EED c\xF3 \u0111\xFAng k chu tr\xECnh\n  // EGF: (ln(1/(1-x)))^k\
    \ / k!\n  // ln(1/(1-x)) = x + x^2/2 + x^3/3 + ...\n  int N, K;\n  cin >> N >>\
    \ K;\n  init_fact(N + 1);\n  if (K == 0) {\n    cout << \"1 \";  // S(0,0)\n \
    \   for (int i = 1; i <= N; ++i) cout << \"0 \";\n    cout << \"\\n\";\n    return;\n\
    \  }\n\n  // 1. T\u1EA1o \u0111a th\u1EE9c A(x) = sum(x^i / i)\n  vector<Fp> a(N\
    \ + 1, 0);\n  for (int i = 1; i <= N; ++i) {\n    // 1/i = (i-1)! / i! = fact[i-1]\
    \ * invFact[i]\n    a[i] = fact[i - 1] * invFact[i];\n  }\n  Poly A(a);\n\n  //\
    \ 2. T\xEDnh G(x) = A(x)^K\n  Poly G = A.pow(K, N + 1);\n\n  // 3. K\u1EBFt qu\u1EA3\
    \ S(n, K) = G[n] * n! / K!\n  Fp invK = invFact[K];\n  for (int n = K; n <= N;\
    \ ++n) {\n    Fp val = G[n] * fact[n] * invK;\n    if((n - K) % 2 == 1) val =\
    \ -val;\n    cout << val << ' ';\n  }\n  cout << \"\\n\";\n}\n\nint main() {\n\
    \  ios_base::sync_with_stdio(false);\n  cin.tie(NULL);\n  solve();\n  return 0;\n\
    }"
  dependsOn:
  - misc/macros.h
  - math/Poly.h
  - math/ModInt.h
  isVerificationFile: true
  path: tests/Stirling_Number_1st_fixed_K.test.cpp
  requiredBy: []
  timestamp: '2026-10-03 15:27:40+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: tests/Stirling_Number_1st_fixed_K.test.cpp
layout: document
redirect_from:
- /verify/tests/Stirling_Number_1st_fixed_K.test.cpp
- /verify/tests/Stirling_Number_1st_fixed_K.test.cpp.html
title: tests/Stirling_Number_1st_fixed_K.test.cpp
---
