---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/EnumTriangles.h
    title: graph/EnumTriangles.h
  - icon: ':question:'
    path: math/ModInt.h
    title: math/ModInt.h
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
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_triangles
    links:
    - https://judge.yosupo.jp/problem/enumerate_triangles
  bundledCode: "#line 1 \"tests/Enumerate_Triangles.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/enumerate_triangles\"\n\n#line 1 \"misc/macros.h\"\
    \n// #ifdef LOCAL\n// #define __GLIBCXX_DEBUG 1\n// #endif\n\n// #pragma GCC optimize(\"\
    Ofast,unroll-loops\")       // unroll long, simple loops\n// #pragma GCC target(\"\
    avx2,fma\")                   // vectorizing code\n// #pragma GCC target(\"lzcnt,popcnt,abm,bmi,bmi2\"\
    )  // for fast bitset operation\n\n#include <bits/extc++.h>\n\n#include <tr2/dynamic_bitset>\n\
    \nusing namespace std;\nusing namespace __gnu_pbds;  // ordered_set, gp_hash_table\n\
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
    \  }\n};\n#line 1 \"graph/EnumTriangles.h\"\ntemplate <typename F>\nvoid EnumTriangles(int\
    \ n, const vector<pii>& ed, F f) {  // 0-indexed graph\n  vi deg(n);\n  for (auto\
    \ [u, v] : ed) ++deg[u], ++deg[v];\n  vector<vi> g(n);  // directed\n  for (auto&\
    \ e : ed) {\n    auto [u, v] = e;\n    if (tie(deg[u], u) > tie(deg[v], v)) swap(u,\
    \ v);\n    g[u].eb(v);\n  }\n  vector<bool> adj(n);\n  for (auto& [u, v] : ed)\
    \ {\n    for (auto nu : g[u]) adj[nu] = true;\n    for (auto nv : g[v]) {\n  \
    \    if (adj[nv]) f(u, v, nv);\n    }\n    for (auto nu : g[u]) adj[nu] = false;\n\
    \  }\n}\n#line 6 \"tests/Enumerate_Triangles.test.cpp\"\n\nusing Fp = modint<998244353>;\n\
    \nsigned main() {\n  ios::sync_with_stdio(false);\n  cin.tie(0);\n  int n, m;\n\
    \  cin >> n >> m;\n  Fp x[n];\n  for (int i = 0; i < n; ++i) cin >> x[i];\n  vector<pii>\
    \ ed;\n  for (int i = 0; i < m; ++i) {\n    int u, v;\n    cin >> u >> v;\n  \
    \  ed.eb(u, v);\n  }\n  Fp res = 0;\n  EnumTriangles(n, ed, [&](int a, int b,\
    \ int c) {\n    res += x[a] * x[b] * x[c];\n  });\n  cout << res;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_triangles\"\n\
    \n#include \"../misc/macros.h\"\n#include \"../math/ModInt.h\"\n#include \"../graph/EnumTriangles.h\"\
    \n\nusing Fp = modint<998244353>;\n\nsigned main() {\n  ios::sync_with_stdio(false);\n\
    \  cin.tie(0);\n  int n, m;\n  cin >> n >> m;\n  Fp x[n];\n  for (int i = 0; i\
    \ < n; ++i) cin >> x[i];\n  vector<pii> ed;\n  for (int i = 0; i < m; ++i) {\n\
    \    int u, v;\n    cin >> u >> v;\n    ed.eb(u, v);\n  }\n  Fp res = 0;\n  EnumTriangles(n,\
    \ ed, [&](int a, int b, int c) {\n    res += x[a] * x[b] * x[c];\n  });\n  cout\
    \ << res;\n}"
  dependsOn:
  - misc/macros.h
  - math/ModInt.h
  - graph/EnumTriangles.h
  isVerificationFile: true
  path: tests/Enumerate_Triangles.test.cpp
  requiredBy: []
  timestamp: '2025-11-17 23:51:26+07:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: tests/Enumerate_Triangles.test.cpp
layout: document
redirect_from:
- /verify/tests/Enumerate_Triangles.test.cpp
- /verify/tests/Enumerate_Triangles.test.cpp.html
title: tests/Enumerate_Triangles.test.cpp
---
