---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/ConvexHull.h
    title: geometry/ConvexHull.h
  - icon: ':heavy_check_mark:'
    path: geometry/HullDiameter.h
    title: geometry/HullDiameter.h
  - icon: ':heavy_check_mark:'
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
    PROBLEM: https://judge.yosupo.jp/problem/furthest_pair
    links:
    - https://judge.yosupo.jp/problem/furthest_pair
  bundledCode: "#line 1 \"tests/Furthest_Pair_of_Points.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/furthest_pair\"\n\n#line 1 \"misc/macros.h\"\
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
    \    v.insert(v.mutable_begin(), cur);\n*/\n#line 2 \"geometry/Point.h\"\n\ntemplate\
    \ <class T>\nint sgn(T x) { return (x > 0) - (x < 0); }\ntemplate <class T>\n\
    struct Point {\n  typedef Point P;\n  T x, y;\n  explicit Point(T x = 0, T y =\
    \ 0) : x(x), y(y) {}\n  bool operator<(P p) const { return tie(x, y) < tie(p.x,\
    \ p.y); }\n  bool operator==(P p) const { return tie(x, y) == tie(p.x, p.y); }\n\
    \  P operator+(P p) const { return P(x + p.x, y + p.y); }\n  P operator-(P p)\
    \ const { return P(x - p.x, y - p.y); }\n  P operator*(T d) const { return P(x\
    \ * d, y * d); }\n  P operator/(T d) const { return P(x / d, y / d); }\n  T dot(P\
    \ p) const { return x * p.x + y * p.y; }\n  T cross(P p) const { return x * p.y\
    \ - y * p.x; }\n  T cross(P a, P b) const { return (a - *this).cross(b - *this);\
    \ }\n  T dist2() const { return x * x + y * y; }\n  T dist() const { return sqrt(dist2());\
    \ }\n  // angle to x-axis in interval [-pi, pi]\n  T angle() const { return atan2l(y,\
    \ x); }\n  P unit() const { return *this / dist(); }  // makes dist()=1\n  P perp()\
    \ const { return P(-y, x); }        // rotates +90 degrees\n  P normal() const\
    \ { return perp().unit(); }\n  // returns point rotated 'a' radians ccw around\
    \ the origin\n  P rotate(ld a) const {\n    return P(x * cos(a) - y * sin(a),\
    \ x * sin(a) + y * cos(a));\n  }\n  friend ostream& operator<<(ostream& os, P\
    \ p) {\n    return os << \"(\" << p.x << \",\" << p.y << \")\";\n  }\n};\n#line\
    \ 2 \"geometry/ConvexHull.h\"\n\ntemplate <class P>\nvector<P> convexHull(vector<P>\
    \ pts) {\n  if (sz(pts) <= 1) return pts;\n  sort(all(pts));\n  vector<P> h(2\
    \ * sz(pts) + 2);\n  int s = 0, t = 0;\n  for (int it = 2; it--; s = --t, reverse(all(pts)))\
    \ {\n    for (P p : pts) {\n      while (t >= s + 2 && h[t - 2].cross(h[t - 1],\
    \ p) <= 0) t--;\n      h[t++] = p;\n    }\n  }\n  return {h.begin(), h.begin()\
    \ + t - (t == 2 && h[0] == h[1])};\n}\n#line 2 \"geometry/HullDiameter.h\"\n\n\
    // S must already be a convex hull\ntemplate<class P>\narray<P, 2> hullDiameter(vector<P>\
    \ S) {\n  int n = sz(S), j = n < 2 ? 0 : 1;\n  pair<i64, array<P, 2>> res({0,\
    \ {S[0], S[0]}});\n  for (int i = 0; i < j; ++i) {\n    for (;; j = (j + 1) %\
    \ n) {\n      res = max(res, {(S[i] - S[j]).dist2(), {S[i], S[j]}});\n      if\
    \ ((S[(j + 1) % n] - S[j]).cross(S[i + 1] - S[i]) >= 0) break;\n    }\n  }\n \
    \ return res.second;\n}\n#line 6 \"tests/Furthest_Pair_of_Points.test.cpp\"\n\n\
    using P = Point<ld>;\n\nvoid solve() {\n  int n;\n  cin >> n;\n  vector<P> pts(n);\n\
    \  for (auto& [x, y] : pts) cin >> x >> y;\n  auto cvh = convexHull(pts);\n  auto\
    \ [pi, pj] = hullDiameter(cvh);\n  int i, j;\n  for (i = 0; i < n; ++i) {\n  \
    \  if (pts[i] == pi) {\n      cout << i << ' ';\n      break;\n    }\n  }\n  for\
    \ (j = 0; j < n; ++j) {\n    if (pts[j] == pj && j != i) {\n      cout << j <<\
    \ '\\n';\n      break;\n    }\n  }\n}\n\nint main() {\n  int tc;\n  cin >> tc;\n\
    \  while (tc--) solve();\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/furthest_pair\"\n\n#include\
    \ \"../misc/macros.h\"\n#include \"../geometry/ConvexHull.h\"\n#include \"../geometry/HullDiameter.h\"\
    \n\nusing P = Point<ld>;\n\nvoid solve() {\n  int n;\n  cin >> n;\n  vector<P>\
    \ pts(n);\n  for (auto& [x, y] : pts) cin >> x >> y;\n  auto cvh = convexHull(pts);\n\
    \  auto [pi, pj] = hullDiameter(cvh);\n  int i, j;\n  for (i = 0; i < n; ++i)\
    \ {\n    if (pts[i] == pi) {\n      cout << i << ' ';\n      break;\n    }\n \
    \ }\n  for (j = 0; j < n; ++j) {\n    if (pts[j] == pj && j != i) {\n      cout\
    \ << j << '\\n';\n      break;\n    }\n  }\n}\n\nint main() {\n  int tc;\n  cin\
    \ >> tc;\n  while (tc--) solve();\n}"
  dependsOn:
  - misc/macros.h
  - geometry/ConvexHull.h
  - geometry/Point.h
  - geometry/HullDiameter.h
  isVerificationFile: true
  path: tests/Furthest_Pair_of_Points.test.cpp
  requiredBy: []
  timestamp: '2025-11-28 02:09:51+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/Furthest_Pair_of_Points.test.cpp
layout: document
redirect_from:
- /verify/tests/Furthest_Pair_of_Points.test.cpp
- /verify/tests/Furthest_Pair_of_Points.test.cpp.html
title: tests/Furthest_Pair_of_Points.test.cpp
---
