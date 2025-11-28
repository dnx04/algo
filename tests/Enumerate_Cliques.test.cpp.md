---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/Cliques.h
    title: graph/Cliques.h
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
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_cliques
    links:
    - https://judge.yosupo.jp/problem/enumerate_cliques
  bundledCode: "#line 1 \"tests/Enumerate_Cliques.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_cliques\"\
    \n\n#line 1 \"misc/macros.h\"\n// #pragma GCC optimize(\"Ofast,unroll-loops\"\
    )       // unroll long, simple loops\n// #pragma GCC target(\"avx2,fma\")    \
    \               // vectorizing code\n// #pragma GCC target(\"lzcnt,popcnt,abm,bmi,bmi2\"\
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
    \ 1 \"graph/Cliques.h\"\nusing bs = tr2::dynamic_bitset<uint64_t>;\n\n// Usage:\
    \ bs P(n), X(n), R(n); P.set(); EnumClique(g, [&](bs& c){...}, P, X, R);\ntemplate\
    \ <class F>\nvoid EnumClique(vector<bs>& g, F f, bs P, bs X, bs R) {\n  f(R);\
    \ \n  if (P.none() && X.none()) return;\n  // if only need to find all maximal\
    \ cliques\n  // auto q = (P | X).find_first();\n  // auto cands = P & ~g[q]; //\
    \ then trav through cands\n  for (auto i = P.find_first(); i < P.size(); i = P.find_next(i))\
    \ {\n    R[i] = 1;\n    EnumClique(g, f, P & g[i], X & g[i], R);\n    R[i] = 0,\
    \ P[i] = 0, X[i] = 1;\n  }\n}\n\n// Usage: bs P(n), R(n), sol; u64 ans=0; P.set();\
    \ MaxClique(g, P, R, sol, ans);\nvoid MaxClique(vector<bs>& g, bs P, bs R, bs&\
    \ sol, u32& res) {\n  if (R.count() + P.count() <= res) return;\n  if (P.none())\
    \ { res = R.count(), sol = R; return; }\n  auto q = P.find_first(), max_k = u64(0);\n\
    \  for (auto i = q; i < P.size(); i = P.find_next(i)) {\n    auto k = (P & g[i]).count();\n\
    \    if (k > max_k) max_k = k, q = i;\n  }\n  bs cands = P & ~g[q];\n  for (auto\
    \ i = cands.find_first(); i < cands.size(); i = cands.find_next(i)) {\n    R[i]\
    \ = 1, MaxClique(g, P & g[i], R, sol, res);\n    R[i] = P[i] = 0;\n  }\n}\n#line\
    \ 6 \"tests/Enumerate_Cliques.test.cpp\"\n\nusing Fp = modint<998244353>;\n\n\
    void solve() {\n  int n, m;\n  cin >> n >> m;\n  vector<Fp> x(n);\n  for (int\
    \ i = 0; i < n; ++i) cin >> x[i];\n  vector<bs> g(n, bs(n));\n  for (int i = 0;\
    \ i < m; ++i) {\n    int u, v;\n    cin >> u >> v;\n    g[u][v] = g[v][u] = 1;\n\
    \  }\n  Fp ans = 0;\n  EnumClique(g, [&](const bs& clique) {\n    if(!clique.any())\
    \ return;\n    Fp prod = 1;\n    for(int i = clique.find_first(); i < n; i = clique.find_next(i))\
    \ prod *= x[i];\n    ans += prod; }, ~bs(n), bs(n), bs(n));\n  cout << ans <<\
    \ '\\n';\n}\n\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n  cin.exceptions(cin.failbit);\n\
    \  int tc = 1;\n  //   cin >> tc;\n  for (int i = 1; i <= tc; ++i) {\n    solve();\n\
    \  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_cliques\"\n\n\
    #include \"../misc/macros.h\"\n#include \"../math/ModInt.h\"\n#include \"../graph/Cliques.h\"\
    \n\nusing Fp = modint<998244353>;\n\nvoid solve() {\n  int n, m;\n  cin >> n >>\
    \ m;\n  vector<Fp> x(n);\n  for (int i = 0; i < n; ++i) cin >> x[i];\n  vector<bs>\
    \ g(n, bs(n));\n  for (int i = 0; i < m; ++i) {\n    int u, v;\n    cin >> u >>\
    \ v;\n    g[u][v] = g[v][u] = 1;\n  }\n  Fp ans = 0;\n  EnumClique(g, [&](const\
    \ bs& clique) {\n    if(!clique.any()) return;\n    Fp prod = 1;\n    for(int\
    \ i = clique.find_first(); i < n; i = clique.find_next(i)) prod *= x[i];\n   \
    \ ans += prod; }, ~bs(n), bs(n), bs(n));\n  cout << ans << '\\n';\n}\n\nint main()\
    \ {\n  cin.tie(0)->sync_with_stdio(0);\n  cin.exceptions(cin.failbit);\n  int\
    \ tc = 1;\n  //   cin >> tc;\n  for (int i = 1; i <= tc; ++i) {\n    solve();\n\
    \  }\n}\n"
  dependsOn:
  - misc/macros.h
  - math/ModInt.h
  - graph/Cliques.h
  isVerificationFile: true
  path: tests/Enumerate_Cliques.test.cpp
  requiredBy: []
  timestamp: '2025-11-28 12:47:29+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/Enumerate_Cliques.test.cpp
layout: document
redirect_from:
- /verify/tests/Enumerate_Cliques.test.cpp
- /verify/tests/Enumerate_Cliques.test.cpp.html
title: tests/Enumerate_Cliques.test.cpp
---
