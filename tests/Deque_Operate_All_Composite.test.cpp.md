---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/SWAG.h
    title: ds/SWAG.h
  - icon: ':heavy_check_mark:'
    path: math/Affine.h
    title: math/Affine.h
  - icon: ':heavy_check_mark:'
    path: math/ModInt.h
    title: math/ModInt.h
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
    PROBLEM: https://judge.yosupo.jp/problem/deque_operate_all_composite
    links:
    - https://judge.yosupo.jp/problem/deque_operate_all_composite
  bundledCode: "#line 1 \"tests/Deque_Operate_All_Composite.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/deque_operate_all_composite\"\n\n#line 1 \"\
    misc/macros.h\"\n// #ifdef LOCAL\n// #define __GLIBCXX_DEBUG 1\n// #endif\n\n\
    // #pragma GCC optimize(\"Ofast,unroll-loops\")       // unroll long, simple loops\n\
    // #pragma GCC target(\"avx2,fma\")                   // vectorizing code\n//\
    \ #pragma GCC target(\"lzcnt,popcnt,abm,bmi,bmi2\")  // for fast bitset operation\n\
    \n#include <bits/extc++.h>\n\n#include <tr2/dynamic_bitset>\n\nusing namespace\
    \ std;\nusing namespace __gnu_pbds;  // ordered_set, gp_hash_table\nusing namespace\
    \ __gnu_cxx;   // rope, cut and insert subarray in O(logn)\n\n// for templates\
    \ to work\n#define all(s) s.begin(), s.end()\n#define sz(x) (int) (x).size()\n\
    #define pb push_back\n#define eb emplace_back\ntypedef long long ll;\ntypedef\
    \ unsigned long long ull;\ntypedef pair<int, int> pii;\ntypedef vector<int> vi;\n\
    \n// fast map\nconst int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();\n\
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
    \ return res;\n}\n#line 1 \"math/Affine.h\"\ntemplate <typename T>\nstruct affine\
    \ {\n  T a, b;\n  constexpr affine() : a(1), b(0) {}\n  constexpr affine(T a,\
    \ T b) : a(a), b(b) {}\n  T operator()(T x) { return a * x + b; }\n  affine operator()(const\
    \ affine& f) const {\n    return f * (*this);\n  }\n  // g(f(x))\n  affine operator*(const\
    \ affine& g) const {\n    return {a * g.a, b * g.a + g.b};\n  }\n};\n#line 1 \"\
    ds/SWAG.h\"\ntemplate <typename T, typename F>\nstruct SlideWindowAggregationDeque\
    \ {\n  vector<T> a0, a1, r0, r1;\n  F f;\n  T I;\n\n  SlideWindowAggregationDeque(F\
    \ f, T i) : f(f), I(i) {}\n\n private:\n  T get0() const { return r0.empty() ?\
    \ I : r0.back(); }\n  T get1() const { return r1.empty() ? I : r1.back(); }\n\n\
    \  void push0(const T& x) {\n    a0.push_back(x);\n    r0.push_back(f(x, get0()));\n\
    \  }\n  void push1(const T& x) {\n    a1.push_back(x);\n    r1.push_back(f(get1(),\
    \ x));\n  }\n  void rebalance() {\n    int n = a0.size() + a1.size();\n    int\
    \ s0 = n / 2 + (a0.empty() ? n % 2 : 0);\n    vector<T> a{a0};\n    reverse(begin(a),\
    \ end(a));\n    copy(begin(a1), end(a1), back_inserter(a));\n    a0.clear(), r0.clear();\n\
    \    a1.clear(), r1.clear();\n    for (int i = s0 - 1; i >= 0; i--) push0(a[i]);\n\
    \    for (int i = s0; i < n; i++) push1(a[i]);\n  }\n\n public:\n  void push_front(const\
    \ T& t) { push0(t); }\n  void push_back(const T& t) { push1(t); }\n  T front()\
    \ const { return a0.empty() ? a1.front() : a0.back(); }\n  T back() const { return\
    \ a1.empty() ? a0.front() : a1.back(); }\n  void pop_front() {\n    if (a0.empty())\
    \ rebalance();\n    assert(!a0.empty());\n    a0.pop_back(), r0.pop_back();\n\
    \  }\n  void pop_back() {\n    if (a1.empty()) rebalance();\n    assert(!a1.empty());\n\
    \    a1.pop_back(), r1.pop_back();\n  }\n  T query() { return f(get0(), get1());\
    \ }\n};\n#line 7 \"tests/Deque_Operate_All_Composite.test.cpp\"\n\nvoid solve()\
    \ {\n  using Fp = modint<998244353>;\n  using A = affine<Fp>;\n  int q;\n  cin\
    \ >> q;\n  SlideWindowAggregationDeque swag([](const A& f, const A& g) { return\
    \ f * g; }, A{});\n  while (q--) {\n    int cmd;\n    cin >> cmd;\n    if (cmd\
    \ == 0) {\n      int a, b;\n      cin >> a >> b;\n      swag.push_front({a, b});\n\
    \    } else if (cmd == 1) {\n      int a, b;\n      cin >> a >> b;\n      swag.push_back({a,\
    \ b});\n    } else if (cmd == 2) {\n      swag.pop_front();\n    } else if (cmd\
    \ == 3) {\n      swag.pop_back();\n    } else {\n      int x;\n      cin >> x;\n\
    \      cout << swag.query()(x) << '\\n';\n    }\n  }\n}\n\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n\
    \  cin.exceptions(cin.failbit);\n  int tc = 1;\n  //   cin >> tc;\n  for (int\
    \ i = 1; i <= tc; ++i) {\n    solve();\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/deque_operate_all_composite\"\
    \n\n#include \"../misc/macros.h\"\n#include \"../math/ModInt.h\"\n#include \"\
    ../math/Affine.h\"\n#include \"../ds/SWAG.h\"\n\nvoid solve() {\n  using Fp =\
    \ modint<998244353>;\n  using A = affine<Fp>;\n  int q;\n  cin >> q;\n  SlideWindowAggregationDeque\
    \ swag([](const A& f, const A& g) { return f * g; }, A{});\n  while (q--) {\n\
    \    int cmd;\n    cin >> cmd;\n    if (cmd == 0) {\n      int a, b;\n      cin\
    \ >> a >> b;\n      swag.push_front({a, b});\n    } else if (cmd == 1) {\n   \
    \   int a, b;\n      cin >> a >> b;\n      swag.push_back({a, b});\n    } else\
    \ if (cmd == 2) {\n      swag.pop_front();\n    } else if (cmd == 3) {\n     \
    \ swag.pop_back();\n    } else {\n      int x;\n      cin >> x;\n      cout <<\
    \ swag.query()(x) << '\\n';\n    }\n  }\n}\n\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n\
    \  cin.exceptions(cin.failbit);\n  int tc = 1;\n  //   cin >> tc;\n  for (int\
    \ i = 1; i <= tc; ++i) {\n    solve();\n  }\n}\n"
  dependsOn:
  - misc/macros.h
  - math/ModInt.h
  - math/Affine.h
  - ds/SWAG.h
  isVerificationFile: true
  path: tests/Deque_Operate_All_Composite.test.cpp
  requiredBy: []
  timestamp: '2025-11-15 18:26:28+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/Deque_Operate_All_Composite.test.cpp
layout: document
redirect_from:
- /verify/tests/Deque_Operate_All_Composite.test.cpp
- /verify/tests/Deque_Operate_All_Composite.test.cpp.html
title: tests/Deque_Operate_All_Composite.test.cpp
---
