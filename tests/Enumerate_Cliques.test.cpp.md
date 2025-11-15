---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/ModInt.h
    title: math/ModInt.h
  - icon: ':heavy_check_mark:'
    path: misc/MaximalCliques.h
    title: misc/MaximalCliques.h
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
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_cliques
    links:
    - https://judge.yosupo.jp/problem/enumerate_cliques
  bundledCode: "#line 1 \"tests/Enumerate_Cliques.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_cliques\"\
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
    \ Fp = modint;\n  int x;\n  modint() : x(0) {}\n  modint(int64_t y) : x(y >= 0\
    \ ? y % mod : (mod - (-y) % mod) % mod) {}\n  Fp& operator+=(const Fp& p) {\n\
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
    \ 2); }\n  Fp operator^(int64_t n) const {\n    Fp ret(1), mul(x);\n    while\
    \ (n > 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n\
    \    }\n    return ret;\n  }\n  friend ostream& operator<<(ostream& os, const\
    \ Fp& p) { return os << p.x; }\n  friend istream& operator>>(istream& is, Fp&\
    \ a) {\n    int64_t t;\n    is >> t;\n    a = modint<mod>(t);\n    return (is);\n\
    \  }\n};\n\null modmul(ull x, ull y, ull m) { return __uint128_t(x) * y % m; }\n\
    ull modpow(ull x, ull k, ull m) {\n  ull res = 1;\n  while (k) {\n    if (k &\
    \ 1) res = modmul(res, x, m);\n    x = modmul(x, x, m);\n    k >>= 1;\n  }\n \
    \ return res;\n}\n#line 1 \"misc/MaximalCliques.h\"\n// Usage: cliques(g, [&](const\
    \ bs &clique) { callback }, ~bs(n), bs(n), bs(n));\n\ntemplate <class F>\nvoid\
    \ cliques(vector<bs>& eds, F f, bs P, bs X, bs R) {\n  f(R);\n  if (!P.any() &&\
    \ !X.any()) return;\n  // if only need to find all maximal cliques\n  // auto\
    \ q = (P | X).find_first();\n  // auto cands = P & ~eds[q];\n  for (int i = 0;\
    \ i < sz(eds); ++i) {\n    if (P[i]) {\n      R[i] = 1;\n      cliques(eds, f,\
    \ P & eds[i], X & eds[i], R);\n      R[i] = P[i] = 0, X[i] = 1;\n    }\n  }\n\
    }\n#line 6 \"tests/Enumerate_Cliques.test.cpp\"\n\nusing Fp = modint<998244353>;\n\
    \nvoid solve() {\n  int n, m;\n  cin >> n >> m;\n  vector<Fp> x(n);\n  for (int\
    \ i = 0; i < n; ++i) cin >> x[i];\n  vector<bs> g(n, bs(n));\n  for (int i = 0;\
    \ i < m; ++i) {\n    int u, v;\n    cin >> u >> v;\n    g[u][v] = g[v][u] = 1;\n\
    \  }\n  Fp ans = 0;\n  cliques(g, [&](const bs& clique) {\n    if(!clique.any())\
    \ return;\n    Fp prod = 1;\n    for(int i = clique.find_first(); i < n; i = clique.find_next(i))\
    \ prod *= x[i];\n    ans += prod; }, ~bs(n), bs(n), bs(n));\n  cout << ans <<\
    \ '\\n';\n}\n\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n  cin.exceptions(cin.failbit);\n\
    \  int tc = 1;\n  //   cin >> tc;\n  for (int i = 1; i <= tc; ++i) {\n    solve();\n\
    \  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_cliques\"\n\n\
    #include \"../misc/macros.h\"\n#include \"../math/ModInt.h\"\n#include \"../misc/MaximalCliques.h\"\
    \n\nusing Fp = modint<998244353>;\n\nvoid solve() {\n  int n, m;\n  cin >> n >>\
    \ m;\n  vector<Fp> x(n);\n  for (int i = 0; i < n; ++i) cin >> x[i];\n  vector<bs>\
    \ g(n, bs(n));\n  for (int i = 0; i < m; ++i) {\n    int u, v;\n    cin >> u >>\
    \ v;\n    g[u][v] = g[v][u] = 1;\n  }\n  Fp ans = 0;\n  cliques(g, [&](const bs&\
    \ clique) {\n    if(!clique.any()) return;\n    Fp prod = 1;\n    for(int i =\
    \ clique.find_first(); i < n; i = clique.find_next(i)) prod *= x[i];\n    ans\
    \ += prod; }, ~bs(n), bs(n), bs(n));\n  cout << ans << '\\n';\n}\n\nint main()\
    \ {\n  cin.tie(0)->sync_with_stdio(0);\n  cin.exceptions(cin.failbit);\n  int\
    \ tc = 1;\n  //   cin >> tc;\n  for (int i = 1; i <= tc; ++i) {\n    solve();\n\
    \  }\n}\n"
  dependsOn:
  - misc/macros.h
  - math/ModInt.h
  - misc/MaximalCliques.h
  isVerificationFile: true
  path: tests/Enumerate_Cliques.test.cpp
  requiredBy: []
  timestamp: '2025-11-15 18:26:28+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/Enumerate_Cliques.test.cpp
layout: document
redirect_from:
- /verify/tests/Enumerate_Cliques.test.cpp
- /verify/tests/Enumerate_Cliques.test.cpp.html
title: tests/Enumerate_Cliques.test.cpp
---
