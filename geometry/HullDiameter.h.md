---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: geometry/Point.h
    title: geometry/Point.h
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/Furthest_Pair_of_Points.test.cpp
    title: tests/Furthest_Pair_of_Points.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geometry/Point.h\"\n\ntemplate <class T>\nint sgn(T x) {\
    \ return (x > 0) - (x < 0); }\ntemplate <class T>\nstruct Point {\n  typedef Point\
    \ P;\n  T x, y;\n  explicit Point(T x = 0, T y = 0) : x(x), y(y) {}\n  bool operator<(P\
    \ p) const { return tie(x, y) < tie(p.x, p.y); }\n  bool operator==(P p) const\
    \ { return tie(x, y) == tie(p.x, p.y); }\n  P operator+(P p) const { return P(x\
    \ + p.x, y + p.y); }\n  P operator-(P p) const { return P(x - p.x, y - p.y); }\n\
    \  P operator*(T d) const { return P(x * d, y * d); }\n  P operator/(T d) const\
    \ { return P(x / d, y / d); }\n  T dot(P p) const { return x * p.x + y * p.y;\
    \ }\n  T cross(P p) const { return x * p.y - y * p.x; }\n  T cross(P a, P b) const\
    \ { return (a - *this).cross(b - *this); }\n  T dist2() const { return x * x +\
    \ y * y; }\n  T dist() const { return sqrt(dist2()); }\n  // angle to x-axis in\
    \ interval [-pi, pi]\n  T angle() const { return atan2l(y, x); }\n  P unit() const\
    \ { return *this / dist(); }  // makes dist()=1\n  P perp() const { return P(-y,\
    \ x); }        // rotates +90 degrees\n  P normal() const { return perp().unit();\
    \ }\n  // returns point rotated 'a' radians ccw around the origin\n  P rotate(ld\
    \ a) const {\n    return P(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a));\n\
    \  }\n  friend ostream& operator<<(ostream& os, P p) {\n    return os << \"(\"\
    \ << p.x << \",\" << p.y << \")\";\n  }\n};\n#line 2 \"geometry/HullDiameter.h\"\
    \n\n// S must already be a convex hull\ntemplate <class P>\narray<P, 2> hullDiameter(vector<P>\
    \ S) {\n  int n = len(S), j = n < 2 ? 0 : 1;\n  pair<i64, array<P, 2>> res({0,\
    \ {S[0], S[0]}});\n  for (int i = 0; i < j; ++i) {\n    for (;; j = (j + 1) %\
    \ n) {\n      res = max(res, {(S[i] - S[j]).dist2(), {S[i], S[j]}});\n      if\
    \ ((S[(j + 1) % n] - S[j]).cross(S[i + 1] - S[i]) >= 0) break;\n    }\n  }\n \
    \ return res.second;\n}\n"
  code: "#include \"Point.h\"\n\n// S must already be a convex hull\ntemplate <class\
    \ P>\narray<P, 2> hullDiameter(vector<P> S) {\n  int n = len(S), j = n < 2 ? 0\
    \ : 1;\n  pair<i64, array<P, 2>> res({0, {S[0], S[0]}});\n  for (int i = 0; i\
    \ < j; ++i) {\n    for (;; j = (j + 1) % n) {\n      res = max(res, {(S[i] - S[j]).dist2(),\
    \ {S[i], S[j]}});\n      if ((S[(j + 1) % n] - S[j]).cross(S[i + 1] - S[i]) >=\
    \ 0) break;\n    }\n  }\n  return res.second;\n}"
  dependsOn:
  - geometry/Point.h
  isVerificationFile: false
  path: geometry/HullDiameter.h
  requiredBy: []
  timestamp: '2026-10-03 15:27:40+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/Furthest_Pair_of_Points.test.cpp
documentation_of: geometry/HullDiameter.h
layout: document
redirect_from:
- /library/geometry/HullDiameter.h
- /library/geometry/HullDiameter.h.html
title: geometry/HullDiameter.h
---
