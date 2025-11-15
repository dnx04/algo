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
    #line 2 \"geometry/CirclePolygonIntersection.h\"\n\ntypedef Point<double> P;\n\
    #define arg(p, q) atan2(p.cross(q), p.dot(q))\ndouble circlePoly(P c, double r,\
    \ vector<P> ps) {\n  auto tri = [&](P p, P q) {\n    auto r2 = r * r / 2;\n  \
    \  P d = q - p;\n    auto a = d.dot(p) / d.dist2(), b = (p.dist2() - r * r) /\
    \ d.dist2();\n    auto det = a * a - b;\n    if (det <= 0) return arg(p, q) *\
    \ r2;\n    auto s = max(0., -a - sqrt(det)), t = min(1., -a + sqrt(det));\n  \
    \  if (t < 0 || 1 <= s) return arg(p, q) * r2;\n    P u = p + d * s, v = p + d\
    \ * t;\n    return arg(p, u) * r2 + u.cross(v) / 2 + arg(v, q) * r2;\n  };\n \
    \ auto sum = 0.0;\n  for (int i = 0; i < n; ++i)i, 0, sz(ps)) sum += tri(ps[i]\
    \ - c, ps[(i + 1) % sz(ps)] - c);\n  return sum;\n}\n"
  code: "#include \"Point.h\"\n\ntypedef Point<double> P;\n#define arg(p, q) atan2(p.cross(q),\
    \ p.dot(q))\ndouble circlePoly(P c, double r, vector<P> ps) {\n  auto tri = [&](P\
    \ p, P q) {\n    auto r2 = r * r / 2;\n    P d = q - p;\n    auto a = d.dot(p)\
    \ / d.dist2(), b = (p.dist2() - r * r) / d.dist2();\n    auto det = a * a - b;\n\
    \    if (det <= 0) return arg(p, q) * r2;\n    auto s = max(0., -a - sqrt(det)),\
    \ t = min(1., -a + sqrt(det));\n    if (t < 0 || 1 <= s) return arg(p, q) * r2;\n\
    \    P u = p + d * s, v = p + d * t;\n    return arg(p, u) * r2 + u.cross(v) /\
    \ 2 + arg(v, q) * r2;\n  };\n  auto sum = 0.0;\n  for (int i = 0; i < n; ++i)i,\
    \ 0, sz(ps)) sum += tri(ps[i] - c, ps[(i + 1) % sz(ps)] - c);\n  return sum;\n\
    }"
  dependsOn:
  - geometry/Point.h
  isVerificationFile: false
  path: geometry/CirclePolygonIntersection.h
  requiredBy: []
  timestamp: '2025-11-15 18:26:28+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/CirclePolygonIntersection.h
layout: document
redirect_from:
- /library/geometry/CirclePolygonIntersection.h
- /library/geometry/CirclePolygonIntersection.h.html
title: geometry/CirclePolygonIntersection.h
---
