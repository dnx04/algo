---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: geometry/Line.h
    title: geometry/Line.h
  - icon: ':warning:'
    path: geometry/LineIntersection.h
    title: geometry/LineIntersection.h
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
  bundledCode: "#line 1 \"geometry/Line.h\"\nusing T = int; \nusing T2 = long long;\n\
    using T4 = __int128_t;\nconst T2 INF = 4e18;\n\nstruct Line { T a, b; T2 c; };\n\
    \nbool half(Line m) { return m.a < 0 || m.a == 0 && m.b < 0; };\nvoid normalize(Line&\
    \ m) {\n  T2 g =gcd((T2)gcd(abs(m.a), abs(m.b)), abs(m.c));\n  if (half(m)) g\
    \ *= -1;\n  m.a /= g, m.b /= g, m.c /= g;\n}\n// Sorts halfplanes in clockwise\
    \ order. \n// To sort lines, normalize first (gcd logic not needed).\nbool operator<(Line\
    \ m, Line n) {\n  return make_pair(half(m), (T2)m.b * n.a) < \n         make_pair(half(n),\
    \ (T2)m.a * n.b);\n}\nLine LineFromPoints(T x1, T y1, T x2, T y2) {\n  T a = y1\
    \ - y2, b = x2 - x1;\n  T2 c = (T2)a * x1 + (T2)b * y1;\n  return {a, b, c}; //\
    \ halfplane points to the left of vec.\n}\n#line 1 \"geometry/Point.h\"\ntemplate\
    \ <class T>\nint sgn(T x) {\n  return (x > 0) - (x < 0);\n}\ntemplate <class T>\n\
    struct Point {\n  typedef Point P;\n  T x, y;\n  explicit Point(T x = 0, T y =\
    \ 0) : x(x), y(y) {}\n  bool operator<(P p) const { return tie(x, y) < tie(p.x,\
    \ p.y); }\n  bool operator==(P p) const { return tie(x, y) == tie(p.x, p.y); }\n\
    \  P operator+(P p) const { return P(x + p.x, y + p.y); }\n  P operator-(P p)\
    \ const { return P(x - p.x, y - p.y); }\n  P operator*(T d) const { return P(x\
    \ * d, y * d); }\n  P operator/(T d) const { return P(x / d, y / d); }\n  T dot(P\
    \ p) const { return x * p.x + y * p.y; }\n  T cross(P p) const { return x * p.y\
    \ - y * p.x; }\n  T cross(P a, P b) const { return (a - *this).cross(b - *this);\
    \ }\n  T dist2() const { return x * x + y * y; }\n  long double dist() const {\
    \ return sqrt((long double)dist2()); }\n  // angle to x-axis in interval [-pi,\
    \ pi]\n  long double angle() const { return atan2l(y, x); }\n  P unit() const\
    \ { return *this / dist(); }  // makes dist()=1\n  P perp() const { return P(-y,\
    \ x); }        // rotates +90 degrees\n  P normal() const { return perp().unit();\
    \ }\n  // returns point rotated 'a' radians ccw around the origin\n  P rotate(double\
    \ a) const {\n    return P(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a));\n\
    \  }\n  friend ostream& operator<<(ostream& os, P p) {\n    return os << \"(\"\
    \ << p.x << \",\" << p.y << \")\";\n  }\n};\n#line 1 \"geometry/Line.h\"\nusing\
    \ T = int; \nusing T2 = long long;\nusing T4 = __int128_t;\nconst T2 INF = 4e18;\n\
    \nstruct Line { T a, b; T2 c; };\n\nbool half(Line m) { return m.a < 0 || m.a\
    \ == 0 && m.b < 0; };\nvoid normalize(Line& m) {\n  T2 g =gcd((T2)gcd(abs(m.a),\
    \ abs(m.b)), abs(m.c));\n  if (half(m)) g *= -1;\n  m.a /= g, m.b /= g, m.c /=\
    \ g;\n}\n// Sorts halfplanes in clockwise order. \n// To sort lines, normalize\
    \ first (gcd logic not needed).\nbool operator<(Line m, Line n) {\n  return make_pair(half(m),\
    \ (T2)m.b * n.a) < \n         make_pair(half(n), (T2)m.a * n.b);\n}\nLine LineFromPoints(T\
    \ x1, T y1, T x2, T y2) {\n  T a = y1 - y2, b = x2 - x1;\n  T2 c = (T2)a * x1\
    \ + (T2)b * y1;\n  return {a, b, c}; // halfplane points to the left of vec.\n\
    }\n#line 3 \"geometry/LineIntersection.h\"\n\ntemplate <class P>\npair<int, P>\
    \ lineInter(P s1, P e1, P s2, P e2) {\n  auto d = (e1 - s1).cross(e2 - s2);\n\
    \  if (d == 0)  // if parallel\n    return {-(s1.cross(e1, s2) == 0), P(0, 0)};\n\
    \  auto p = s2.cross(e1, e2), q = s2.cross(e2, s1);\n  return {1, (s1 * p + e1\
    \ * q) / d};\n}\n\ntuple<T4, T4, T2> LineIntersection(Line m, Line n) {\n  T2\
    \ d = (T2)m.a * n.b - (T2)m.b * n.a; // assert(d);\n  T4 x = (T4)m.c * n.b - (T4)m.b\
    \ * n.c; \n  T4 y = (T4)m.a * n.c - (T4)m.c * n.a;\n  return {x, y, d}; // (x/d,\
    \ y/d) is intersection. \n}\n#line 3 \"geometry/HalfplaneSet.h\"\n\nstruct HalfplaneSet\
    \ : multiset<Line> {\n  HalfplaneSet() {\n    insert({+1, 0, INF});\n    insert({0,\
    \ +1, INF});\n    insert({-1, 0, INF});\n    insert({0, -1, INF});\n  };\n\n \
    \ auto adv(auto it, int z) {  // z = {-1, +1}\n    return (z == -1 ? --(it ==\
    \ begin() ? end() : it)\n                    : (++it == end() ? begin() : it));\n\
    \  }\n  bool chk(auto it) {\n    Line l = *it, pl = *adv(it, -1), nl = *adv(it,\
    \ +1);\n    auto [x, y, d] = LineIntersection(pl, nl);\n    T4 sat = l.a * x +\
    \ l.b * y - (T4)l.c * d;\n    if (d < 0 && sat < 0) return clear(), 0;  // unsat\n\
    \    if ((d > 0 && sat <= 0) || (d == 0 && sat < 0)) return erase(it), 1;\n  \
    \  return 0;\n  }\n  void Cut(Line l) {  // add ax + by <= c\n    if (empty())\
    \ return;\n    auto it = insert(l);\n    if (chk(it)) return;\n    for (int z\
    \ : {-1, +1})\n      while (size() && chk(adv(it, z)));\n  }\n  double Maximize(T\
    \ a, T b) {  // max ax + by\n    if (empty()) return -1 / 0.;\n    auto it = lower_bound({a,\
    \ b});\n    if (it == end()) it = begin();\n    auto [x, y, d] = LineIntersection(*adv(it,\
    \ -1), *it);\n    return (1.0 * a * x + 1.0 * b * y) / d;\n  }\n  double Area()\
    \ { // half-plane intersection area\n    double total = 0.;\n    for (auto it\
    \ = begin(); it != end(); ++it) {\n      auto [x1, y1, d1] = LineIntersection(*adv(it,\
    \ -1), *it);\n      auto [x2, y2, d2] = LineIntersection(*it, *adv(it, +1));\n\
    \      total += (1.0 * x1 * y2 - 1.0 * x2 * y1) / d1 / d2;\n    }\n    return\
    \ total * 0.5;\n  }\n};\n"
  code: "#include \"Line.h\"\n#include \"LineIntersection.h\"\n\nstruct HalfplaneSet\
    \ : multiset<Line> {\n  HalfplaneSet() {\n    insert({+1, 0, INF});\n    insert({0,\
    \ +1, INF});\n    insert({-1, 0, INF});\n    insert({0, -1, INF});\n  };\n\n \
    \ auto adv(auto it, int z) {  // z = {-1, +1}\n    return (z == -1 ? --(it ==\
    \ begin() ? end() : it)\n                    : (++it == end() ? begin() : it));\n\
    \  }\n  bool chk(auto it) {\n    Line l = *it, pl = *adv(it, -1), nl = *adv(it,\
    \ +1);\n    auto [x, y, d] = LineIntersection(pl, nl);\n    T4 sat = l.a * x +\
    \ l.b * y - (T4)l.c * d;\n    if (d < 0 && sat < 0) return clear(), 0;  // unsat\n\
    \    if ((d > 0 && sat <= 0) || (d == 0 && sat < 0)) return erase(it), 1;\n  \
    \  return 0;\n  }\n  void Cut(Line l) {  // add ax + by <= c\n    if (empty())\
    \ return;\n    auto it = insert(l);\n    if (chk(it)) return;\n    for (int z\
    \ : {-1, +1})\n      while (size() && chk(adv(it, z)));\n  }\n  double Maximize(T\
    \ a, T b) {  // max ax + by\n    if (empty()) return -1 / 0.;\n    auto it = lower_bound({a,\
    \ b});\n    if (it == end()) it = begin();\n    auto [x, y, d] = LineIntersection(*adv(it,\
    \ -1), *it);\n    return (1.0 * a * x + 1.0 * b * y) / d;\n  }\n  double Area()\
    \ { // half-plane intersection area\n    double total = 0.;\n    for (auto it\
    \ = begin(); it != end(); ++it) {\n      auto [x1, y1, d1] = LineIntersection(*adv(it,\
    \ -1), *it);\n      auto [x2, y2, d2] = LineIntersection(*it, *adv(it, +1));\n\
    \      total += (1.0 * x1 * y2 - 1.0 * x2 * y1) / d1 / d2;\n    }\n    return\
    \ total * 0.5;\n  }\n};"
  dependsOn:
  - geometry/Line.h
  - geometry/LineIntersection.h
  - geometry/Point.h
  isVerificationFile: false
  path: geometry/HalfplaneSet.h
  requiredBy: []
  timestamp: '2025-11-15 18:26:28+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/HalfplaneSet.h
layout: document
redirect_from:
- /library/geometry/HalfplaneSet.h
- /library/geometry/HalfplaneSet.h.html
title: geometry/HalfplaneSet.h
---
