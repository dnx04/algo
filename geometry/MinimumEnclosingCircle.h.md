---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: geometry/Circumcircle.h
    title: geometry/Circumcircle.h
  - icon: ':heavy_check_mark:'
    path: geometry/Point.h
    title: geometry/Point.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
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
    #line 2 \"geometry/Circumcircle.h\"\n\ntypedef Point<double> P;\ndouble ccRadius(const\
    \ P& A, const P& B, const P& C) {\n  return (B - A).dist() * (C - B).dist() *\
    \ (A - C).dist() /\n         abs((B - A).cross(C - A)) / 2;\n}\nP ccCenter(const\
    \ P& A, const P& B, const P& C) {\n  P b = C - A, c = B - A;\n  return A + (b\
    \ * c.dist2() - c * b.dist2()).perp() / b.cross(c) / 2;\n}\n#line 2 \"geometry/MinimumEnclosingCircle.h\"\
    \n\npair<P, long double> mec(vector<P> ps) {\n  shuffle(all(ps), mt19937(time(0)));\n\
    \  P o = ps[0];\n  long double r = 0, EPS = 1 + 1e-12;\n  for (int i = 0; i <\
    \ sz(ps); ++i) {\n    if ((o - ps[i]).dist() > r * EPS) {\n      o = ps[i], r\
    \ = 0;\n      for (int j = 0; j < i; ++j) {\n        if ((o - ps[j]).dist() >\
    \ r * EPS) {\n          o = (ps[i] + ps[j]) / 2;\n          r = (o - ps[i]).dist();\n\
    \          for (int k = 0; k < j; ++k) {\n            if ((o - ps[k]).dist() >\
    \ r * EPS) {\n              o = ccCenter(ps[i], ps[j], ps[k]);\n             \
    \ r = (o - ps[i]).dist();\n            }\n          }\n        }\n      }\n  \
    \  }\n  }\n  return {o, r};\n}\n"
  code: "#include \"Circumcircle.h\"\n\npair<P, long double> mec(vector<P> ps) {\n\
    \  shuffle(all(ps), mt19937(time(0)));\n  P o = ps[0];\n  long double r = 0, EPS\
    \ = 1 + 1e-12;\n  for (int i = 0; i < sz(ps); ++i) {\n    if ((o - ps[i]).dist()\
    \ > r * EPS) {\n      o = ps[i], r = 0;\n      for (int j = 0; j < i; ++j) {\n\
    \        if ((o - ps[j]).dist() > r * EPS) {\n          o = (ps[i] + ps[j]) /\
    \ 2;\n          r = (o - ps[i]).dist();\n          for (int k = 0; k < j; ++k)\
    \ {\n            if ((o - ps[k]).dist() > r * EPS) {\n              o = ccCenter(ps[i],\
    \ ps[j], ps[k]);\n              r = (o - ps[i]).dist();\n            }\n     \
    \     }\n        }\n      }\n    }\n  }\n  return {o, r};\n}"
  dependsOn:
  - geometry/Circumcircle.h
  - geometry/Point.h
  isVerificationFile: false
  path: geometry/MinimumEnclosingCircle.h
  requiredBy: []
  timestamp: '2025-11-15 18:26:28+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/MinimumEnclosingCircle.h
layout: document
redirect_from:
- /library/geometry/MinimumEnclosingCircle.h
- /library/geometry/MinimumEnclosingCircle.h.html
title: geometry/MinimumEnclosingCircle.h
---
