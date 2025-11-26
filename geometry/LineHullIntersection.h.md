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
    \ << p.x << \",\" << p.y << \")\";\n  }\n};\n#line 2 \"geometry/LineHullIntersection.h\"\
    \n\n#define cmp(i, j) sgn(dir.perp().cross(poly[(i) % n] - poly[(j) % n]))\n#define\
    \ extr(i) cmp(i + 1, i) >= 0 && cmp(i, i - 1 + n) < 0\n\ntemplate <class P>\n\
    int extrVertex(vector<P>& poly, P dir) {\n  int n = sz(poly), lo = 0, hi = n;\n\
    \  if (extr(0)) return 0;\n  while (lo + 1 < hi) {\n    int m = (lo + hi) / 2;\n\
    \    if (extr(m)) return m;\n    int ls = cmp(lo + 1, lo), ms = cmp(m + 1, m);\n\
    \    (ls < ms || (ls == ms && ls == cmp(lo, m)) ? hi : lo) = m;\n  }\n  return\
    \ lo;\n}\n\n#define cmpL(i) sgn(a.cross(poly[i], b))\ntemplate <class P>\narray<int,\
    \ 2> lineHull(P a, P b, vector<P>& poly) {\n  int endA = extrVertex(poly, (a -\
    \ b).perp());\n  int endB = extrVertex(poly, (b - a).perp());\n  if (cmpL(endA)\
    \ < 0 || cmpL(endB) > 0) return {-1, -1};\n  array<int, 2> res;\n  for(int i =\
    \ 0; i < 2; ++i) {\n    int lo = endB, hi = endA, n = sz(poly);\n    while ((lo\
    \ + 1) % n != hi) {\n      int m = ((lo + hi + (lo < hi ? 0 : n)) / 2) % n;\n\
    \      (cmpL(m) == cmpL(endB) ? lo : hi) = m;\n    }\n    res[i] = (lo + !cmpL(hi))\
    \ % n;\n    swap(endA, endB);\n  }\n  if (res[0] == res[1]) return {res[0], -1};\n\
    \  if (!cmpL(res[0]) && !cmpL(res[1]))\n    switch ((res[0] - res[1] + sz(poly)\
    \ + 1) % sz(poly)) {\n      case 0: return {res[0], res[0]};\n      case 2: return\
    \ {res[1], res[1]};\n    }\n  return res;\n}\n"
  code: "#include \"Point.h\"\n\n#define cmp(i, j) sgn(dir.perp().cross(poly[(i) %\
    \ n] - poly[(j) % n]))\n#define extr(i) cmp(i + 1, i) >= 0 && cmp(i, i - 1 + n)\
    \ < 0\n\ntemplate <class P>\nint extrVertex(vector<P>& poly, P dir) {\n  int n\
    \ = sz(poly), lo = 0, hi = n;\n  if (extr(0)) return 0;\n  while (lo + 1 < hi)\
    \ {\n    int m = (lo + hi) / 2;\n    if (extr(m)) return m;\n    int ls = cmp(lo\
    \ + 1, lo), ms = cmp(m + 1, m);\n    (ls < ms || (ls == ms && ls == cmp(lo, m))\
    \ ? hi : lo) = m;\n  }\n  return lo;\n}\n\n#define cmpL(i) sgn(a.cross(poly[i],\
    \ b))\ntemplate <class P>\narray<int, 2> lineHull(P a, P b, vector<P>& poly) {\n\
    \  int endA = extrVertex(poly, (a - b).perp());\n  int endB = extrVertex(poly,\
    \ (b - a).perp());\n  if (cmpL(endA) < 0 || cmpL(endB) > 0) return {-1, -1};\n\
    \  array<int, 2> res;\n  for(int i = 0; i < 2; ++i) {\n    int lo = endB, hi =\
    \ endA, n = sz(poly);\n    while ((lo + 1) % n != hi) {\n      int m = ((lo +\
    \ hi + (lo < hi ? 0 : n)) / 2) % n;\n      (cmpL(m) == cmpL(endB) ? lo : hi) =\
    \ m;\n    }\n    res[i] = (lo + !cmpL(hi)) % n;\n    swap(endA, endB);\n  }\n\
    \  if (res[0] == res[1]) return {res[0], -1};\n  if (!cmpL(res[0]) && !cmpL(res[1]))\n\
    \    switch ((res[0] - res[1] + sz(poly) + 1) % sz(poly)) {\n      case 0: return\
    \ {res[0], res[0]};\n      case 2: return {res[1], res[1]};\n    }\n  return res;\n\
    }"
  dependsOn:
  - geometry/Point.h
  isVerificationFile: false
  path: geometry/LineHullIntersection.h
  requiredBy: []
  timestamp: '2025-11-26 18:05:06+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/LineHullIntersection.h
layout: document
redirect_from:
- /library/geometry/LineHullIntersection.h
- /library/geometry/LineHullIntersection.h.html
title: geometry/LineHullIntersection.h
---
