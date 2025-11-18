---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: geometry/Point.h
    title: geometry/Point.h
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: tests/Closest_Pair_of_Points.test.cpp
    title: tests/Closest_Pair_of_Points.test.cpp
  _isVerificationFailed: true
  _pathExtension: h
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"geometry/Point.h\"\ntemplate <class T>\nint sgn(T x) {\n\
    \  return (x > 0) - (x < 0);\n}\ntemplate <class T>\nstruct Point {\n  typedef\
    \ Point P;\n  T x, y;\n  explicit Point(T x = 0, T y = 0) : x(x), y(y) {}\n  bool\
    \ operator<(P p) const { return tie(x, y) < tie(p.x, p.y); }\n  bool operator==(P\
    \ p) const { return tie(x, y) == tie(p.x, p.y); }\n  P operator+(P p) const {\
    \ return P(x + p.x, y + p.y); }\n  P operator-(P p) const { return P(x - p.x,\
    \ y - p.y); }\n  P operator*(T d) const { return P(x * d, y * d); }\n  P operator/(T\
    \ d) const { return P(x / d, y / d); }\n  T dot(P p) const { return x * p.x +\
    \ y * p.y; }\n  T cross(P p) const { return x * p.y - y * p.x; }\n  T cross(P\
    \ a, P b) const { return (a - *this).cross(b - *this); }\n  T dist2() const {\
    \ return x * x + y * y; }\n  ld dist() const { return sqrt((ld) dist2()); }\n\
    \  // angle to x-axis in interval [-pi, pi]\n  ld angle() const { return atan2l(y,\
    \ x); }\n  P unit() const { return *this / dist(); }  // makes dist()=1\n  P perp()\
    \ const { return P(-y, x); }        // rotates +90 degrees\n  P normal() const\
    \ { return perp().unit(); }\n  // returns point rotated 'a' radians ccw around\
    \ the origin\n  P rotate(ld a) const {\n    return P(x * cos(a) - y * sin(a),\
    \ x * sin(a) + y * cos(a));\n  }\n  friend ostream& operator<<(ostream& os, P\
    \ p) {\n    return os << \"(\" << p.x << \",\" << p.y << \")\";\n  }\n};\n#line\
    \ 2 \"geometry/ClosestPair.h\"\n\ntypedef Point<i64> P;\npair<P, P> closest(vector<P>\
    \ v) {\n  assert(sz(v) > 1);\n  set<P> S;\n  sort(all(v), [](P a, P b) { return\
    \ a.y < b.y; });\n  pair<i64, pair<P, P>> ret{LLONG_MAX, {P(), P()}};\n  int j\
    \ = 0;\n  for (P p : v) {\n    P d{1 + (i64)sqrt(ret.first), 0};\n    while (v[j].y\
    \ <= p.y - d.x) S.erase(v[j++]);\n    auto lo = S.lower_bound(p - d), hi = S.upper_bound(p\
    \ + d);\n    for (; lo != hi; ++lo) ret = min(ret, {(*lo - p).dist2(), {*lo, p}});\n\
    \    S.insert(p);\n  }\n  return ret.second;\n}\n"
  code: "#include \"Point.h\"\n\ntypedef Point<i64> P;\npair<P, P> closest(vector<P>\
    \ v) {\n  assert(sz(v) > 1);\n  set<P> S;\n  sort(all(v), [](P a, P b) { return\
    \ a.y < b.y; });\n  pair<i64, pair<P, P>> ret{LLONG_MAX, {P(), P()}};\n  int j\
    \ = 0;\n  for (P p : v) {\n    P d{1 + (i64)sqrt(ret.first), 0};\n    while (v[j].y\
    \ <= p.y - d.x) S.erase(v[j++]);\n    auto lo = S.lower_bound(p - d), hi = S.upper_bound(p\
    \ + d);\n    for (; lo != hi; ++lo) ret = min(ret, {(*lo - p).dist2(), {*lo, p}});\n\
    \    S.insert(p);\n  }\n  return ret.second;\n}"
  dependsOn:
  - geometry/Point.h
  isVerificationFile: false
  path: geometry/ClosestPair.h
  requiredBy: []
  timestamp: '2025-11-18 17:04:42+07:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - tests/Closest_Pair_of_Points.test.cpp
documentation_of: geometry/ClosestPair.h
layout: document
redirect_from:
- /library/geometry/ClosestPair.h
- /library/geometry/ClosestPair.h.html
title: geometry/ClosestPair.h
---
