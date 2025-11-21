---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/ClosestPair.h
    title: geometry/ClosestPair.h
  - icon: ':question:'
    path: geometry/Point.h
    title: geometry/Point.h
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
    PROBLEM: https://judge.yosupo.jp/problem/closest_pair
    links:
    - https://judge.yosupo.jp/problem/closest_pair
  bundledCode: "#line 1 \"tests/Closest_Pair_of_Points.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/closest_pair\"\n\n#line 1 \"misc/macros.h\"\
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
    \ cur);\n*/\n#line 2 \"geometry/Point.h\"\n\ntemplate <class T>\nint sgn(T x)\
    \ { return (x > 0) - (x < 0); }\ntemplate <class T>\nstruct Point {\n  typedef\
    \ Point P;\n  T x, y;\n  explicit Point(T x = 0, T y = 0) : x(x), y(y) {}\n  bool\
    \ operator<(P p) const { return tie(x, y) < tie(p.x, p.y); }\n  bool operator==(P\
    \ p) const { return tie(x, y) == tie(p.x, p.y); }\n  P operator+(P p) const {\
    \ return P(x + p.x, y + p.y); }\n  P operator-(P p) const { return P(x - p.x,\
    \ y - p.y); }\n  P operator*(T d) const { return P(x * d, y * d); }\n  P operator/(T\
    \ d) const { return P(x / d, y / d); }\n  T dot(P p) const { return x * p.x +\
    \ y * p.y; }\n  T cross(P p) const { return x * p.y - y * p.x; }\n  T cross(P\
    \ a, P b) const { return (a - *this).cross(b - *this); }\n  T dist2() const {\
    \ return x * x + y * y; }\n  T dist() const { return sqrt(dist2()); }\n  // angle\
    \ to x-axis in interval [-pi, pi]\n  T angle() const { return atan2l(y, x); }\n\
    \  P unit() const { return *this / dist(); }  // makes dist()=1\n  P perp() const\
    \ { return P(-y, x); }        // rotates +90 degrees\n  P normal() const { return\
    \ perp().unit(); }\n  // returns point rotated 'a' radians ccw around the origin\n\
    \  P rotate(ld a) const {\n    return P(x * cos(a) - y * sin(a), x * sin(a) +\
    \ y * cos(a));\n  }\n  friend ostream& operator<<(ostream& os, P p) {\n    return\
    \ os << \"(\" << p.x << \",\" << p.y << \")\";\n  }\n};\ntypedef Point<i64> P;\n\
    #line 2 \"geometry/ClosestPair.h\"\n\ntypedef Point<i64> P;\npair<P, P> closest(vector<P>\
    \ v) {\n  assert(sz(v) > 1);\n  set<P> S;\n  sort(all(v), [](P a, P b) { return\
    \ a.y < b.y; });\n  pair<i64, pair<P, P>> ret{LLONG_MAX, {P(), P()}};\n  int j\
    \ = 0;\n  for (P p : v) {\n    P d{1 + (i64)sqrt(ret.first), 0};\n    while (v[j].y\
    \ <= p.y - d.x) S.erase(v[j++]);\n    auto lo = S.lower_bound(p - d), hi = S.upper_bound(p\
    \ + d);\n    for (; lo != hi; ++lo) ret = min(ret, {(*lo - p).dist2(), {*lo, p}});\n\
    \    S.insert(p);\n  }\n  return ret.second;\n}\n#line 5 \"tests/Closest_Pair_of_Points.test.cpp\"\
    \n\nvoid solve() {\n  int n;\n  cin >> n;\n  vector<Point<i64>> p(n);\n  for (int\
    \ i = 0; i < n; ++i) cin >> p[i].x >> p[i].y;\n  auto ans = closest(p);\n  int\
    \ p1, p2;\n  for (int i = 0; i < n; ++i) {\n    if (p[i] == ans.first) {\n   \
    \   p1 = i;\n      break;\n    }\n  }\n  for (int i = 0; i < n; ++i) {\n    if\
    \ (i != p1 && p[i] == ans.second) {\n      p2 = i;\n      break;\n    }\n  }\n\
    \  cout << p1 << ' ' << p2 << '\\n';\n}\n\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n\
    \  cin.exceptions(cin.failbit);\n  int tc = 1;\n  cin >> tc;\n  for (int i = 1;\
    \ i <= tc; ++i) {\n    solve();\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/closest_pair\"\n\n#include\
    \ \"../misc/macros.h\"\n#include \"../geometry/ClosestPair.h\"\n\nvoid solve()\
    \ {\n  int n;\n  cin >> n;\n  vector<Point<i64>> p(n);\n  for (int i = 0; i <\
    \ n; ++i) cin >> p[i].x >> p[i].y;\n  auto ans = closest(p);\n  int p1, p2;\n\
    \  for (int i = 0; i < n; ++i) {\n    if (p[i] == ans.first) {\n      p1 = i;\n\
    \      break;\n    }\n  }\n  for (int i = 0; i < n; ++i) {\n    if (i != p1 &&\
    \ p[i] == ans.second) {\n      p2 = i;\n      break;\n    }\n  }\n  cout << p1\
    \ << ' ' << p2 << '\\n';\n}\n\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n\
    \  cin.exceptions(cin.failbit);\n  int tc = 1;\n  cin >> tc;\n  for (int i = 1;\
    \ i <= tc; ++i) {\n    solve();\n  }\n}\n"
  dependsOn:
  - misc/macros.h
  - geometry/ClosestPair.h
  - geometry/Point.h
  isVerificationFile: true
  path: tests/Closest_Pair_of_Points.test.cpp
  requiredBy: []
  timestamp: '2025-11-21 16:03:24+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/Closest_Pair_of_Points.test.cpp
layout: document
redirect_from:
- /verify/tests/Closest_Pair_of_Points.test.cpp
- /verify/tests/Closest_Pair_of_Points.test.cpp.html
title: tests/Closest_Pair_of_Points.test.cpp
---
