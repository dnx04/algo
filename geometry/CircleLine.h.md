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
    \ return x * x + y * y; }\n  T dist() const { return sqrt(dist2()); }\n  // angle\
    \ to x-axis in interval [-pi, pi]\n  T angle() const { return atan2l(y, x); }\n\
    \  P unit() const { return *this / dist(); }  // makes dist()=1\n  P perp() const\
    \ { return P(-y, x); }        // rotates +90 degrees\n  P normal() const { return\
    \ perp().unit(); }\n  // returns point rotated 'a' radians ccw around the origin\n\
    \  P rotate(ld a) const {\n    return P(x * cos(a) - y * sin(a), x * sin(a) +\
    \ y * cos(a));\n  }\n  friend ostream& operator<<(ostream& os, P p) {\n    return\
    \ os << \"(\" << p.x << \",\" << p.y << \")\";\n  }\n};\n#line 2 \"geometry/CircleLine.h\"\
    \n\ntemplate <class P>\nvector<P> circleLine(P c, ld r, P a, P b) {\n  P ab =\
    \ b - a;\n  ld s = a.cross(b, c);\n\n  // calculate intersection, return vector<P>\n\
    \  P p = a + ab * (c - a).dot(ab) / ab.dist2();\n  ld h2 = r * r - s * s / ab.dist2();\n\
    \  if (h2 < 0) return {};\n  if (h2 == 0) return {p};\n  P h = ab.unit() * sqrt(h2);\n\
    \  return {p - h, p + h};\n\n  // calculate smaller part area, return ld\n  //\
    \ ld dist = fabs(s) / sqrt(ab.dist2());\n  // assert(dist <= r);\n  // ld theta\
    \ = 2.0 * acos(dist / r);\n  // ld area = 0.5 * r * r * (theta - sin(theta));\n\
    \  // return area;\n}\n"
  code: "#include \"Point.h\"\n\ntemplate <class P>\nvector<P> circleLine(P c, ld\
    \ r, P a, P b) {\n  P ab = b - a;\n  ld s = a.cross(b, c);\n\n  // calculate intersection,\
    \ return vector<P>\n  P p = a + ab * (c - a).dot(ab) / ab.dist2();\n  ld h2 =\
    \ r * r - s * s / ab.dist2();\n  if (h2 < 0) return {};\n  if (h2 == 0) return\
    \ {p};\n  P h = ab.unit() * sqrt(h2);\n  return {p - h, p + h};\n\n  // calculate\
    \ smaller part area, return ld\n  // ld dist = fabs(s) / sqrt(ab.dist2());\n \
    \ // assert(dist <= r);\n  // ld theta = 2.0 * acos(dist / r);\n  // ld area =\
    \ 0.5 * r * r * (theta - sin(theta));\n  // return area;\n}"
  dependsOn:
  - geometry/Point.h
  isVerificationFile: false
  path: geometry/CircleLine.h
  requiredBy: []
  timestamp: '2025-11-18 18:21:29+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/CircleLine.h
layout: document
redirect_from:
- /library/geometry/CircleLine.h
- /library/geometry/CircleLine.h.html
title: geometry/CircleLine.h
---
