---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: geometry/OnSegment.h
    title: geometry/OnSegment.h
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
    #line 2 \"geometry/OnSegment.h\"\n\ntemplate <class P>\nbool onSegment(P s, P\
    \ e, P p) {\n  return p.cross(s, e) == 0 && (s - p).dot(e - p) <= 0;\n}\n#line\
    \ 1 \"geometry/Point.h\"\ntemplate <class T>\nint sgn(T x) {\n  return (x > 0)\
    \ - (x < 0);\n}\ntemplate <class T>\nstruct Point {\n  typedef Point P;\n  T x,\
    \ y;\n  explicit Point(T x = 0, T y = 0) : x(x), y(y) {}\n  bool operator<(P p)\
    \ const { return tie(x, y) < tie(p.x, p.y); }\n  bool operator==(P p) const {\
    \ return tie(x, y) == tie(p.x, p.y); }\n  P operator+(P p) const { return P(x\
    \ + p.x, y + p.y); }\n  P operator-(P p) const { return P(x - p.x, y - p.y); }\n\
    \  P operator*(T d) const { return P(x * d, y * d); }\n  P operator/(T d) const\
    \ { return P(x / d, y / d); }\n  T dot(P p) const { return x * p.x + y * p.y;\
    \ }\n  T cross(P p) const { return x * p.y - y * p.x; }\n  T cross(P a, P b) const\
    \ { return (a - *this).cross(b - *this); }\n  T dist2() const { return x * x +\
    \ y * y; }\n  long double dist() const { return sqrt((long double)dist2()); }\n\
    \  // angle to x-axis in interval [-pi, pi]\n  long double angle() const { return\
    \ atan2l(y, x); }\n  P unit() const { return *this / dist(); }  // makes dist()=1\n\
    \  P perp() const { return P(-y, x); }        // rotates +90 degrees\n  P normal()\
    \ const { return perp().unit(); }\n  // returns point rotated 'a' radians ccw\
    \ around the origin\n  P rotate(double a) const {\n    return P(x * cos(a) - y\
    \ * sin(a), x * sin(a) + y * cos(a));\n  }\n  friend ostream& operator<<(ostream&\
    \ os, P p) {\n    return os << \"(\" << p.x << \",\" << p.y << \")\";\n  }\n};\n\
    #line 3 \"geometry/SegmentIntersection.h\"\n\ntemplate <class P>\nvector<P> segInter(P\
    \ a, P b, P c, P d) {\n  auto oa = c.cross(d, a), ob = c.cross(d, b), oc = a.cross(b,\
    \ c),\n       od = a.cross(b, d);\n  // Checks if intersection is single non-endpoint\
    \ point.\n  if (sgn(oa) * sgn(ob) < 0 && sgn(oc) * sgn(od) < 0)\n    return {(a\
    \ * ob - b * oa) / (ob - oa)};\n  set<P> s;\n  if (onSegment(c, d, a)) s.insert(a);\n\
    \  if (onSegment(c, d, b)) s.insert(b);\n  if (onSegment(a, b, c)) s.insert(c);\n\
    \  if (onSegment(a, b, d)) s.insert(d);\n  return {all(s)};\n}\n"
  code: "#include \"OnSegment.h\"\n#include \"Point.h\"\n\ntemplate <class P>\nvector<P>\
    \ segInter(P a, P b, P c, P d) {\n  auto oa = c.cross(d, a), ob = c.cross(d, b),\
    \ oc = a.cross(b, c),\n       od = a.cross(b, d);\n  // Checks if intersection\
    \ is single non-endpoint point.\n  if (sgn(oa) * sgn(ob) < 0 && sgn(oc) * sgn(od)\
    \ < 0)\n    return {(a * ob - b * oa) / (ob - oa)};\n  set<P> s;\n  if (onSegment(c,\
    \ d, a)) s.insert(a);\n  if (onSegment(c, d, b)) s.insert(b);\n  if (onSegment(a,\
    \ b, c)) s.insert(c);\n  if (onSegment(a, b, d)) s.insert(d);\n  return {all(s)};\n\
    }"
  dependsOn:
  - geometry/OnSegment.h
  - geometry/Point.h
  isVerificationFile: false
  path: geometry/SegmentIntersection.h
  requiredBy: []
  timestamp: '2025-11-15 18:26:28+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/SegmentIntersection.h
layout: document
redirect_from:
- /library/geometry/SegmentIntersection.h
- /library/geometry/SegmentIntersection.h.html
title: geometry/SegmentIntersection.h
---
