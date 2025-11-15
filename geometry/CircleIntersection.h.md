---
data:
  _extendedDependsOn:
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
    #line 2 \"geometry/CircleIntersection.h\"\n\ntypedef Point<double> P;\nbool circleInter(P\
    \ a, P b, double r1, double r2, pair<P, P>* out) {\n  if (a == b) {\n    assert(r1\
    \ != r2);\n    return false;\n  }\n  P vec = b - a;\n  double d2 = vec.dist2(),\
    \ sum = r1 + r2, dif = r1 - r2,\n         p = (d2 + r1 * r1 - r2 * r2) / (d2 *\
    \ 2), h2 = r1 * r1 - p * p * d2;\n  if (sum * sum < d2 || dif * dif > d2) return\
    \ false;\n  P mid = a + vec * p, per = vec.perp() * sqrt(fmax(0, h2) / d2);\n\
    \  *out = {mid + per, mid - per};\n  return true;\n}\n"
  code: "#include \"Point.h\"\n\ntypedef Point<double> P;\nbool circleInter(P a, P\
    \ b, double r1, double r2, pair<P, P>* out) {\n  if (a == b) {\n    assert(r1\
    \ != r2);\n    return false;\n  }\n  P vec = b - a;\n  double d2 = vec.dist2(),\
    \ sum = r1 + r2, dif = r1 - r2,\n         p = (d2 + r1 * r1 - r2 * r2) / (d2 *\
    \ 2), h2 = r1 * r1 - p * p * d2;\n  if (sum * sum < d2 || dif * dif > d2) return\
    \ false;\n  P mid = a + vec * p, per = vec.perp() * sqrt(fmax(0, h2) / d2);\n\
    \  *out = {mid + per, mid - per};\n  return true;\n}"
  dependsOn:
  - geometry/Point.h
  isVerificationFile: false
  path: geometry/CircleIntersection.h
  requiredBy: []
  timestamp: '2025-11-15 18:26:28+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/CircleIntersection.h
layout: document
redirect_from:
- /library/geometry/CircleIntersection.h
- /library/geometry/CircleIntersection.h.html
title: geometry/CircleIntersection.h
---
