---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/ModInt.h
    title: math/ModInt.h
  - icon: ':x:'
    path: math/ModSQRT.h
    title: math/ModSQRT.h
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
    PROBLEM: https://judge.yosupo.jp/problem/sqrt_mod
    links:
    - https://judge.yosupo.jp/problem/sqrt_mod
  bundledCode: "#line 1 \"tests/Sqrt_Mod.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/sqrt_mod\"\
    \n\n#line 1 \"misc/macros.h\"\n// #ifdef LOCAL\n// #define __GLIBCXX_DEBUG 1\n\
    // #endif\n\n// #pragma GCC optimize(\"Ofast,unroll-loops\")       // unroll long,\
    \ simple loops\n// #pragma GCC target(\"avx2,fma\")                   // vectorizing\
    \ code\n// #pragma GCC target(\"lzcnt,popcnt,abm,bmi,bmi2\")  // for fast bitset\
    \ operation\n\n#include <bits/extc++.h>\n\n#include <tr2/dynamic_bitset>\n\nusing\
    \ namespace std;\nusing namespace __gnu_pbds;  // ordered_set, gp_hash_table\n\
    using namespace __gnu_cxx;   // rope, cut and insert subarray in O(logn)\n\n//\
    \ for templates to work\n#define all(s) s.begin(), s.end()\n#define sz(x) (int)\
    \ (x).size()\n#define pb push_back\n#define eb emplace_back\ntypedef long long\
    \ ll;\ntypedef unsigned long long ull;\ntypedef pair<int, int> pii;\ntypedef vector<int>\
    \ vi;\n\n// fast map\nconst int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();\n\
    struct chash {  // customize hash function for gp_hash_table\n  int operator()(int\
    \ x) const { return x ^ RANDOM; }\n};\ngp_hash_table<int, int, chash> table;\n\
    \n/* ordered set\n    find_by_order(k): returns an iterator to the k-th element\
    \ (0-based)\n    order_of_key(k): returns the number of elements in the set that\
    \ are strictly less than k\n*/\ntemplate <typename T>\nusing ordered_set = tree<T,\
    \ null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;\n\n// dynamic\
    \ bitset\nusing bs = tr2::dynamic_bitset<uint64_t>;\n\n/*  rope\n    rope <int>\
    \ cur = v.substr(l, r - l + 1);\n    v.erase(l, r - l + 1);\n    v.insert(v.mutable_begin(),\
    \ cur);\n*/\n\n#define CONCAT_(x, y) x##y\n#define CONCAT(x, y) CONCAT_(x, y)\n\
    #ifdef LOCAL\n#define clog cerr << setw(__db_level * 2) << setfill(' ') << \"\"\
    \ << setw(0)\n#define DB() debug_block CONCAT(dbbl, __LINE__)\nint __db_level\
    \ = 0;\nstruct debug_block {\n  debug_block() {\n    clog << \"{\" << endl;\n\
    \    ++__db_level;\n  }\n  ~debug_block() {\n    --__db_level;\n    clog << \"\
    }\" << endl;\n  }\n};\n#else\n#define clog \\\n  if (0) cerr\n#define DB(...)\n\
    #endif\n#line 1 \"math/ModInt.h\"\ntemplate <int mod>\nstruct modint {\n  using\
    \ Fp = modint;\n  static constexpr ull im = -1ULL / mod + 1;  // Barrett constant\n\
    \  int x;\n  modint() : x(0) {}\n  modint(ll y) {\n    y %= mod;\n    if (y <\
    \ 0) y += mod;\n    x = y;\n  }\n  static inline uint32_t reduce(ull z) {\n  \
    \  ull q = (__uint128_t(z) * im) >> 64;\n    ll r = z - q * mod;\n    return r\
    \ < mod ? r : r - mod;\n  }\n  Fp& operator+=(const Fp& p) {\n    if ((x += p.x)\
    \ >= mod) x -= mod;\n    return *this;\n  }\n  Fp& operator-=(const Fp& p) {\n\
    \    if ((x += mod - p.x) >= mod) x -= mod;\n    return *this;\n  }\n  Fp& operator*=(const\
    \ Fp& p) {\n    x = reduce(uint64_t(x) * p.x);\n    return *this;\n  }\n  Fp&\
    \ operator/=(const Fp& p) { return *this *= p.inv(); }\n\n  Fp operator-() const\
    \ { return Fp(-x); }\n  Fp operator+(const Fp& p) const { return Fp(*this) +=\
    \ p; }\n  Fp operator-(const Fp& p) const { return Fp(*this) -= p; }\n  Fp operator*(const\
    \ Fp& p) const { return Fp(*this) *= p; }\n  Fp operator/(const Fp& p) const {\
    \ return Fp(*this) /= p; }\n  bool operator==(const Fp& p) const { return x ==\
    \ p.x; }\n  bool operator!=(const Fp& p) const { return x != p.x; }\n  Fp inv()\
    \ const { return *this ^ (mod - 2); }\n  Fp operator^(int64_t n) const {\n   \
    \ Fp r = 1, a = *this;\n    while (n) {\n      if (n & 1) r *= a;\n      a *=\
    \ a;\n      n >>= 1;\n    }\n    return r;\n  }\n  friend ostream& operator<<(ostream&\
    \ os, const Fp& p) { return os << p.x; }\n  friend istream& operator>>(istream&\
    \ is, Fp& a) {\n    int64_t t;\n    is >> t;\n    a = Fp(t);\n    return is;\n\
    \  }\n};\n#line 1 \"math/ModSQRT.h\"\nll modsqrt(ll a, ll p) {\n  a %= p;\n  if\
    \ (a < 0) a += p;\n  if (a == 0) return 0;\n\n  if (modpow(a, (p - 1) / 2, p)\
    \ != 1) return -1;\n  if (p % 4 == 3) return modpow(a, (p + 1) / 4, p);\n  //\
    \ a^(n+3)/8 or 2^(n+3)/8 * 2^(n-1)/4 works if p % 8 == 5\n  ll s = p - 1, n =\
    \ 2;\n  int r = 0, m;\n  while (s % 2 == 0) ++r, s /= 2;\n  /// find a non-square\
    \ mod p\n  while (modpow(n, (p - 1) / 2, p) != p - 1) ++n;\n  ll x = modpow(a,\
    \ (s + 1) / 2, p);\n  ll b = modpow(a, s, p), g = modpow(n, s, p);\n  for (;;\
    \ r = m) {\n    ll t = b;\n    for (m = 0; m < r && t != 1; ++m) t = t * t % p;\n\
    \    if (m == 0) return x;\n    ll gs = modpow(g, 1LL << (r - m - 1), p);\n  \
    \  g = gs * gs % p;\n    x = x * gs % p;\n    b = b * g % p;\n  }\n}\n#line 6\
    \ \"tests/Sqrt_Mod.test.cpp\"\n\nvoid solve() {\n  int y, p;\n  cin >> y >> p;\n\
    \  cout << modsqrt(y, p) << '\\n';\n}\n\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n\
    \  cin.exceptions(cin.failbit);\n  int tc = 1;\n  cin >> tc;\n  for (int i = 1;\
    \ i <= tc; ++i) {\n    solve();\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sqrt_mod\"\n\n#include\
    \ \"../misc/macros.h\"\n#include \"../math/ModInt.h\"\n#include \"../math/ModSQRT.h\"\
    \n\nvoid solve() {\n  int y, p;\n  cin >> y >> p;\n  cout << modsqrt(y, p) <<\
    \ '\\n';\n}\n\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n  cin.exceptions(cin.failbit);\n\
    \  int tc = 1;\n  cin >> tc;\n  for (int i = 1; i <= tc; ++i) {\n    solve();\n\
    \  }\n}\n"
  dependsOn:
  - misc/macros.h
  - math/ModInt.h
  - math/ModSQRT.h
  isVerificationFile: true
  path: tests/Sqrt_Mod.test.cpp
  requiredBy: []
  timestamp: '2025-11-17 23:51:26+07:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: tests/Sqrt_Mod.test.cpp
layout: document
redirect_from:
- /verify/tests/Sqrt_Mod.test.cpp
- /verify/tests/Sqrt_Mod.test.cpp.html
title: tests/Sqrt_Mod.test.cpp
---
