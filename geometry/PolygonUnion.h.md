---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
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
    #line 1 \"geometry/Point.h\"\ntemplate <class T>\nint sgn(T x) {\n  return (x\
    \ > 0) - (x < 0);\n}\ntemplate <class T>\nstruct Point {\n  typedef Point P;\n\
    \  T x, y;\n  explicit Point(T x = 0, T y = 0) : x(x), y(y) {}\n  bool operator<(P\
    \ p) const { return tie(x, y) < tie(p.x, p.y); }\n  bool operator==(P p) const\
    \ { return tie(x, y) == tie(p.x, p.y); }\n  P operator+(P p) const { return P(x\
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
    #line 2 \"geometry/SideOf.h\"\n\ntemplate <class P>\nint sideOf(P s, P e, P p)\
    \ {\n  return sgn(s.cross(e, p));\n}\n\ntemplate <class P>\nint sideOf(const P&\
    \ s, const P& e, const P& p, double eps) {\n  auto a = (e - s).cross(p - s);\n\
    \  double l = (e - s).dist() * eps;\n  return (a > l) - (a < -l);\n}\n#line 3\
    \ \"geometry/PolygonUnion.h\"\n\ntypedef Point<double> P;\ndouble rat(P a, P b)\
    \ { return sgn(b.x) ? a.x / b.x : a.y / b.y; }\ndouble polyUnion(vector<vector<P>>&\
    \ poly) {\n  double ret = 0;\n  for (int i = 0; i < n; ++i)i, 0, sz(poly)) for(int\
    \ i = 0; i < n; ++i)v, 0, sz(poly[i])) {\n      P A = poly[i][v], B = poly[i][(v\
    \ + 1) % sz(poly[i])];\n      vector<pair<double, int>> segs = {{0, 0}, {1, 0}};\n\
    \      for (int i = 0; i < n; ++i)j, 0, sz(poly)) if (i != j) {\n          for\
    \ (int i = 0; i < n; ++i)u, 0, sz(poly[j])) {\n              P C = poly[j][u],\
    \ D = poly[j][(u + 1) % sz(poly[j])];\n              int sc = sideOf(A, B, C),\
    \ sd = sideOf(A, B, D);\n              if (sc != sd) {\n                double\
    \ sa = C.cross(D, A), sb = C.cross(D, B);\n                if (min(sc, sd) < 0)\
    \ segs.emplace_back(sa / (sa - sb), sgn(sc - sd));\n              } else if (!sc\
    \ && !sd && j < i && sgn((B - A).dot(D - C)) > 0) {\n                segs.emplace_back(rat(C\
    \ - A, B - A), 1);\n                segs.emplace_back(rat(D - A, B - A), -1);\n\
    \              }\n            }\n        }\n      sort(all(segs));\n      for\
    \ (auto& s : segs) s.first = min(max(s.first, 0.0), 1.0);\n      double sum =\
    \ 0;\n      int cnt = segs[0].second;\n      for (int i = 0; i < n; ++i)j, 1,\
    \ sz(segs)) {\n          if (!cnt) sum += segs[j].first - segs[j - 1].first;\n\
    \          cnt += segs[j].second;\n        }\n      ret += A.cross(B) * sum;\n\
    \    }\n  return ret / 2;\n}\n"
  code: "#include \"Point.h\"\n#include \"SideOf.h\"\n\ntypedef Point<double> P;\n\
    double rat(P a, P b) { return sgn(b.x) ? a.x / b.x : a.y / b.y; }\ndouble polyUnion(vector<vector<P>>&\
    \ poly) {\n  double ret = 0;\n  for (int i = 0; i < n; ++i)i, 0, sz(poly)) for(int\
    \ i = 0; i < n; ++i)v, 0, sz(poly[i])) {\n      P A = poly[i][v], B = poly[i][(v\
    \ + 1) % sz(poly[i])];\n      vector<pair<double, int>> segs = {{0, 0}, {1, 0}};\n\
    \      for (int i = 0; i < n; ++i)j, 0, sz(poly)) if (i != j) {\n          for\
    \ (int i = 0; i < n; ++i)u, 0, sz(poly[j])) {\n              P C = poly[j][u],\
    \ D = poly[j][(u + 1) % sz(poly[j])];\n              int sc = sideOf(A, B, C),\
    \ sd = sideOf(A, B, D);\n              if (sc != sd) {\n                double\
    \ sa = C.cross(D, A), sb = C.cross(D, B);\n                if (min(sc, sd) < 0)\
    \ segs.emplace_back(sa / (sa - sb), sgn(sc - sd));\n              } else if (!sc\
    \ && !sd && j < i && sgn((B - A).dot(D - C)) > 0) {\n                segs.emplace_back(rat(C\
    \ - A, B - A), 1);\n                segs.emplace_back(rat(D - A, B - A), -1);\n\
    \              }\n            }\n        }\n      sort(all(segs));\n      for\
    \ (auto& s : segs) s.first = min(max(s.first, 0.0), 1.0);\n      double sum =\
    \ 0;\n      int cnt = segs[0].second;\n      for (int i = 0; i < n; ++i)j, 1,\
    \ sz(segs)) {\n          if (!cnt) sum += segs[j].first - segs[j - 1].first;\n\
    \          cnt += segs[j].second;\n        }\n      ret += A.cross(B) * sum;\n\
    \    }\n  return ret / 2;\n}"
  dependsOn:
  - geometry/Point.h
  - geometry/SideOf.h
  isVerificationFile: false
  path: geometry/PolygonUnion.h
  requiredBy: []
  timestamp: '2025-11-15 18:26:28+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/PolygonUnion.h
layout: document
redirect_from:
- /library/geometry/PolygonUnion.h
- /library/geometry/PolygonUnion.h.html
title: geometry/PolygonUnion.h
---
