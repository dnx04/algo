---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/Point.h
    title: geometry/Point.h
  _extendedRequiredBy:
  - icon: ':warning:'
    path: geometry/InsidePolygon.h
    title: geometry/InsidePolygon.h
  - icon: ':warning:'
    path: geometry/PointInsideHull.h
    title: geometry/PointInsideHull.h
  - icon: ':warning:'
    path: geometry/SegmentIntersection.h
    title: geometry/SegmentIntersection.h
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
    #line 2 \"geometry/OnSegment.h\"\n\ntemplate <class P>\nbool onSegment(P s, P\
    \ e, P p) {\n  return p.cross(s, e) == 0 && (s - p).dot(e - p) <= 0;\n}\n"
  code: "#include \"Point.h\"\n\ntemplate <class P>\nbool onSegment(P s, P e, P p)\
    \ {\n  return p.cross(s, e) == 0 && (s - p).dot(e - p) <= 0;\n}"
  dependsOn:
  - geometry/Point.h
  isVerificationFile: false
  path: geometry/OnSegment.h
  requiredBy:
  - geometry/InsidePolygon.h
  - geometry/PointInsideHull.h
  - geometry/SegmentIntersection.h
  timestamp: '2025-11-15 18:26:28+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/OnSegment.h
layout: document
redirect_from:
- /library/geometry/OnSegment.h
- /library/geometry/OnSegment.h.html
title: geometry/OnSegment.h
---
