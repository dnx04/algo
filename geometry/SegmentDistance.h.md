---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: geometry/Point.h
    title: geometry/Point.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
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
    \ << p.x << \",\" << p.y << \")\";\n  }\n};\ntypedef Point<i64> P;\n#line 2 \"\
    geometry/SegmentDistance.h\"\n\ntypedef Point<ld> P;\nld segDist(P& s, P& e, P&\
    \ p) {\n  if (s == e) return (p - s).dist();\n  auto d = (e - s).dist2(), t =\
    \ min(d, max(.0, (p - s).dot(e - s)));\n  return ((p - s) * d - (e - s) * t).dist()\
    \ / d;\n}\n"
  code: "#include \"Point.h\"\n\ntypedef Point<ld> P;\nld segDist(P& s, P& e, P& p)\
    \ {\n  if (s == e) return (p - s).dist();\n  auto d = (e - s).dist2(), t = min(d,\
    \ max(.0, (p - s).dot(e - s)));\n  return ((p - s) * d - (e - s) * t).dist() /\
    \ d;\n}"
  dependsOn:
  - geometry/Point.h
  isVerificationFile: false
  path: geometry/SegmentDistance.h
  requiredBy: []
  timestamp: '2025-11-21 16:03:24+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/SegmentDistance.h
layout: document
redirect_from:
- /library/geometry/SegmentDistance.h
- /library/geometry/SegmentDistance.h.html
title: geometry/SegmentDistance.h
---
