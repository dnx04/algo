---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/Point.h
    title: geometry/Point.h
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/Static_Convex_Hull.test.cpp
    title: tests/Static_Convex_Hull.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \ return x * x + y * y; }\n  long double dist() const { return sqrt((long double)dist2());\
    \ }\n  // angle to x-axis in interval [-pi, pi]\n  long double angle() const {\
    \ return atan2l(y, x); }\n  P unit() const { return *this / dist(); }  // makes\
    \ dist()=1\n  P perp() const { return P(-y, x); }        // rotates +90 degrees\n\
    \  P normal() const { return perp().unit(); }\n  // returns point rotated 'a'\
    \ radians ccw around the origin\n  P rotate(double a) const {\n    return P(x\
    \ * cos(a) - y * sin(a), x * sin(a) + y * cos(a));\n  }\n  friend ostream& operator<<(ostream&\
    \ os, P p) {\n    return os << \"(\" << p.x << \",\" << p.y << \")\";\n  }\n};\n\
    #line 2 \"geometry/ConvexHull.h\"\n\ntypedef Point<ll> P;\nvector<P> convexHull(vector<P>\
    \ pts) {\n  if (sz(pts) <= 1) return pts;\n  sort(all(pts));\n  vector<P> h(sz(pts)\
    \ + 1);\n  int s = 0, t = 0;\n  for (int it = 2; it--; s = --t, reverse(all(pts)))\n\
    \    for (P p : pts) {\n      while (t >= s + 2 && h[t - 2].cross(h[t - 1], p)\
    \ <= 0) t--;\n      h[t++] = p;\n    }\n  return {h.begin(), h.begin() + t - (t\
    \ == 2 && h[0] == h[1])};\n}\n"
  code: "#include \"Point.h\"\n\ntypedef Point<ll> P;\nvector<P> convexHull(vector<P>\
    \ pts) {\n  if (sz(pts) <= 1) return pts;\n  sort(all(pts));\n  vector<P> h(sz(pts)\
    \ + 1);\n  int s = 0, t = 0;\n  for (int it = 2; it--; s = --t, reverse(all(pts)))\n\
    \    for (P p : pts) {\n      while (t >= s + 2 && h[t - 2].cross(h[t - 1], p)\
    \ <= 0) t--;\n      h[t++] = p;\n    }\n  return {h.begin(), h.begin() + t - (t\
    \ == 2 && h[0] == h[1])};\n}"
  dependsOn:
  - geometry/Point.h
  isVerificationFile: false
  path: geometry/ConvexHull.h
  requiredBy: []
  timestamp: '2025-11-15 18:26:28+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/Static_Convex_Hull.test.cpp
documentation_of: geometry/ConvexHull.h
layout: document
redirect_from:
- /library/geometry/ConvexHull.h
- /library/geometry/ConvexHull.h.html
title: geometry/ConvexHull.h
---
