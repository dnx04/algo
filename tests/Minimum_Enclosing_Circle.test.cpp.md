---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: geometry/Circumcircle.h
    title: geometry/Circumcircle.h
  - icon: ':x:'
    path: geometry/MinimumEnclosingCircle.h
    title: geometry/MinimumEnclosingCircle.h
  - icon: ':question:'
    path: geometry/Point.h
    title: geometry/Point.h
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
    PROBLEM: https://judge.yosupo.jp/problem/minimum_enclosing_circle
    links:
    - https://judge.yosupo.jp/problem/minimum_enclosing_circle
  bundledCode: "#line 1 \"tests/Minimum_Enclosing_Circle.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/minimum_enclosing_circle\"\n\n#line 1 \"misc/macros.h\"\
    \n// #pragma GCC optimize(\"Ofast,unroll-loops\")       // unroll long, simple\
    \ loops\n// #pragma GCC target(\"avx2,fma\")                   // vectorizing\
    \ code\n// #pragma GCC target(\"lzcnt,popcnt,abm,bmi,bmi2\")  // for fast bitset\
    \ operation\n\n#include <bits/extc++.h>\n\nusing namespace std;\nusing namespace\
    \ __gnu_pbds;  // ordered_set, gp_hash_table\n// using namespace __gnu_cxx; //\
    \ rope\n\n// for templates to work\n#define all(s) s.begin(), s.end()\n#define\
    \ sz(x) (int) (x).size()\n#define pb push_back\n#define eb emplace_back\nusing\
    \ i32 = int32_t;\nusing u32 = uint32_t;\nusing i64 = int64_t;\nusing u64 = uint64_t;\n\
    using i128 = __int128_t;\nusing u128 = __uint128_t;\nusing ld = long double;\n\
    using pii = pair<i32, i32>;\nusing vi = vector<i32>;\n\n// fast map\nconst int\
    \ RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();\n\
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
    \ 2 \"geometry/Circumcircle.h\"\n\ntypedef Point<ld> P;\nld ccRadius(const P&\
    \ A, const P& B, const P& C) {\n  return (B - A).dist() * (C - B).dist() * (A\
    \ - C).dist() /\n         abs((B - A).cross(C - A)) / 2;\n}\nP ccCenter(const\
    \ P& A, const P& B, const P& C) {\n  P b = C - A, c = B - A;\n  return A + (b\
    \ * c.dist2() - c * b.dist2()).perp() / b.cross(c) / 2;\n}\n#line 2 \"geometry/MinimumEnclosingCircle.h\"\
    \n\npair<P, ld> mec(vector<P> ps) {\n  shuffle(all(ps), mt19937(time(0)));\n \
    \ P o = ps[0];\n  ld r = 0, EPS = 1 + 1e-12;\n  for (int i = 0; i < sz(ps); ++i)\
    \ {\n    if ((o - ps[i]).dist() > r * EPS) {\n      o = ps[i], r = 0;\n      for\
    \ (int j = 0; j < i; ++j) {\n        if ((o - ps[j]).dist() > r * EPS) {\n   \
    \       o = (ps[i] + ps[j]) / 2;\n          r = (o - ps[i]).dist();\n        \
    \  for (int k = 0; k < j; ++k) {\n            if ((o - ps[k]).dist() > r * EPS)\
    \ {\n              o = ccCenter(ps[i], ps[j], ps[k]);\n              r = (o -\
    \ ps[i]).dist();\n            }\n          }\n        }\n      }\n    }\n  }\n\
    \  return {o, r};\n}\n#line 5 \"tests/Minimum_Enclosing_Circle.test.cpp\"\n\n\
    using P = Point<ld>;\nvoid solve() {\n  int n;\n  cin >> n;\n  vector<P> pts(n);\n\
    \  for (auto& [x, y] : pts) cin >> x >> y;\n  auto [o, r] = mec(pts);\n  const\
    \ ld EPS = 1e-10;\n  for (int i = 0; i < n; ++i) {\n    if (fabsl((o - pts[i]).dist2()\
    \ - r * r) < EPS) {\n      cout << 1;\n    } else {\n      cout << 0;\n    }\n\
    \  }\n}\n\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n  cin.exceptions(cin.failbit);\n\
    \  int tc = 1;\n  // cin >> tc;\n  for (int i = 1; i <= tc; ++i) {\n    solve();\n\
    \  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/minimum_enclosing_circle\"\
    \n\n#include \"../misc/macros.h\"\n#include \"../geometry/MinimumEnclosingCircle.h\"\
    \n\nusing P = Point<ld>;\nvoid solve() {\n  int n;\n  cin >> n;\n  vector<P> pts(n);\n\
    \  for (auto& [x, y] : pts) cin >> x >> y;\n  auto [o, r] = mec(pts);\n  const\
    \ ld EPS = 1e-10;\n  for (int i = 0; i < n; ++i) {\n    if (fabsl((o - pts[i]).dist2()\
    \ - r * r) < EPS) {\n      cout << 1;\n    } else {\n      cout << 0;\n    }\n\
    \  }\n}\n\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n  cin.exceptions(cin.failbit);\n\
    \  int tc = 1;\n  // cin >> tc;\n  for (int i = 1; i <= tc; ++i) {\n    solve();\n\
    \  }\n}\n"
  dependsOn:
  - misc/macros.h
  - geometry/MinimumEnclosingCircle.h
  - geometry/Circumcircle.h
  - geometry/Point.h
  isVerificationFile: true
  path: tests/Minimum_Enclosing_Circle.test.cpp
  requiredBy: []
  timestamp: '2025-11-28 00:00:09+07:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: tests/Minimum_Enclosing_Circle.test.cpp
layout: document
redirect_from:
- /verify/tests/Minimum_Enclosing_Circle.test.cpp
- /verify/tests/Minimum_Enclosing_Circle.test.cpp.html
title: tests/Minimum_Enclosing_Circle.test.cpp
---
