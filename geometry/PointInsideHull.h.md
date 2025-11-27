---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: geometry/OnSegment.h
    title: geometry/OnSegment.h
  - icon: ':question:'
    path: geometry/Point.h
    title: geometry/Point.h
  - icon: ':warning:'
    path: geometry/SideOf.h
    title: geometry/SideOf.h
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
    \ << p.x << \",\" << p.y << \")\";\n  }\n};\n#line 2 \"geometry/OnSegment.h\"\n\
    \ntemplate <class P>\nbool onSegment(P s, P e, P p) {\n  return p.cross(s, e)\
    \ == 0 && (s - p).dot(e - p) <= 0;\n}\n#line 2 \"geometry/SideOf.h\"\n\ntemplate\
    \ <class P>\nint sideOf(P s, P e, P p) {\n  return sgn(s.cross(e, p));\n}\n\n\
    template <class P>\nint sideOf(const P& s, const P& e, const P& p, ld eps) {\n\
    \  auto a = (e - s).cross(p - s);\n  ld l = (e - s).dist() * eps;\n  return (a\
    \ > l) - (a < -l);\n}\n#line 4 \"geometry/PointInsideHull.h\"\n\ntypedef Point<ll>\
    \ P;\n\nbool inHull(const vector<P>& l, P p, bool strict = true) {\n  int a =\
    \ 1, b = sz(l) - 1, r = !strict;\n  if (sz(l) < 3) return r && onSegment(l[0],\
    \ l.back(), p);\n  if (sideOf(l[0], l[a], l[b]) > 0) swap(a, b);\n  if (sideOf(l[0],\
    \ l[a], p) >= r || sideOf(l[0], l[b], p) <= -r) return false;\n  while (abs(a\
    \ - b) > 1) {\n    int c = (a + b) / 2;\n    (sideOf(l[0], l[c], p) > 0 ? b :\
    \ a) = c;\n  }\n  return sgn(l[a].cross(l[b], p)) < r;\n}\n"
  code: "#include \"OnSegment.h\"\n#include \"Point.h\"\n#include \"SideOf.h\"\n\n\
    typedef Point<ll> P;\n\nbool inHull(const vector<P>& l, P p, bool strict = true)\
    \ {\n  int a = 1, b = sz(l) - 1, r = !strict;\n  if (sz(l) < 3) return r && onSegment(l[0],\
    \ l.back(), p);\n  if (sideOf(l[0], l[a], l[b]) > 0) swap(a, b);\n  if (sideOf(l[0],\
    \ l[a], p) >= r || sideOf(l[0], l[b], p) <= -r) return false;\n  while (abs(a\
    \ - b) > 1) {\n    int c = (a + b) / 2;\n    (sideOf(l[0], l[c], p) > 0 ? b :\
    \ a) = c;\n  }\n  return sgn(l[a].cross(l[b], p)) < r;\n}"
  dependsOn:
  - geometry/OnSegment.h
  - geometry/Point.h
  - geometry/SideOf.h
  isVerificationFile: false
  path: geometry/PointInsideHull.h
  requiredBy: []
  timestamp: '2025-11-21 16:12:02+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/PointInsideHull.h
layout: document
redirect_from:
- /library/geometry/PointInsideHull.h
- /library/geometry/PointInsideHull.h.html
title: geometry/PointInsideHull.h
---
