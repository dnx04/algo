---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: geometry/CircleIntersection.h
    title: geometry/CircleIntersection.h
  - icon: ':warning:'
    path: geometry/CircleLine.h
    title: geometry/CircleLine.h
  - icon: ':warning:'
    path: geometry/CirclePolygonIntersection.h
    title: geometry/CirclePolygonIntersection.h
  - icon: ':warning:'
    path: geometry/CircleTangents.h
    title: geometry/CircleTangents.h
  - icon: ':heavy_check_mark:'
    path: geometry/Circumcircle.h
    title: geometry/Circumcircle.h
  - icon: ':heavy_check_mark:'
    path: geometry/ClosestPair.h
    title: geometry/ClosestPair.h
  - icon: ':question:'
    path: geometry/ConvexHull.h
    title: geometry/ConvexHull.h
  - icon: ':warning:'
    path: geometry/HalfplaneSet.h
    title: geometry/HalfplaneSet.h
  - icon: ':heavy_check_mark:'
    path: geometry/HullDiameter.h
    title: geometry/HullDiameter.h
  - icon: ':warning:'
    path: geometry/InsidePolygon.h
    title: geometry/InsidePolygon.h
  - icon: ':warning:'
    path: geometry/LineDistance.h
    title: geometry/LineDistance.h
  - icon: ':warning:'
    path: geometry/LineHullIntersection.h
    title: geometry/LineHullIntersection.h
  - icon: ':warning:'
    path: geometry/LineIntersection.h
    title: geometry/LineIntersection.h
  - icon: ':warning:'
    path: geometry/LineProjectionReflection.h
    title: geometry/LineProjectionReflection.h
  - icon: ':warning:'
    path: geometry/LinearTransformation.h
    title: geometry/LinearTransformation.h
  - icon: ':heavy_check_mark:'
    path: geometry/MinimumEnclosingCircle.h
    title: geometry/MinimumEnclosingCircle.h
  - icon: ':warning:'
    path: geometry/Minkowski.h
    title: geometry/Minkowski.h
  - icon: ':warning:'
    path: geometry/OnSegment.h
    title: geometry/OnSegment.h
  - icon: ':warning:'
    path: geometry/PointInsideHull.h
    title: geometry/PointInsideHull.h
  - icon: ':warning:'
    path: geometry/PolygonArea.h
    title: geometry/PolygonArea.h
  - icon: ':warning:'
    path: geometry/PolygonCenter.h
    title: geometry/PolygonCenter.h
  - icon: ':warning:'
    path: geometry/SegmentDistance.h
    title: geometry/SegmentDistance.h
  - icon: ':warning:'
    path: geometry/SegmentIntersection.h
    title: geometry/SegmentIntersection.h
  - icon: ':warning:'
    path: geometry/SideOf.h
    title: geometry/SideOf.h
  - icon: ':heavy_check_mark:'
    path: geometry/TrianglePointCount.h
    title: geometry/TrianglePointCount.h
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/Closest_Pair_of_Points.test.cpp
    title: tests/Closest_Pair_of_Points.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Count_Points_in_Triangle.test.cpp
    title: tests/Count_Points_in_Triangle.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Furthest_Pair_of_Points.test.cpp
    title: tests/Furthest_Pair_of_Points.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Minimum_Enclosing_Circle.test.cpp
    title: tests/Minimum_Enclosing_Circle.test.cpp
  - icon: ':x:'
    path: tests/Sort_Points_by_Argument.test.cpp
    title: tests/Sort_Points_by_Argument.test.cpp
  - icon: ':x:'
    path: tests/Static_Convex_Hull.test.cpp
    title: tests/Static_Convex_Hull.test.cpp
  _isVerificationFailed: true
  _pathExtension: h
  _verificationStatusIcon: ':question:'
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
    \ << p.x << \",\" << p.y << \")\";\n  }\n};\n"
  code: "#pragma once\n\ntemplate <class T>\nint sgn(T x) { return (x > 0) - (x <\
    \ 0); }\ntemplate <class T>\nstruct Point {\n  typedef Point P;\n  T x, y;\n \
    \ explicit Point(T x = 0, T y = 0) : x(x), y(y) {}\n  bool operator<(P p) const\
    \ { return tie(x, y) < tie(p.x, p.y); }\n  bool operator==(P p) const { return\
    \ tie(x, y) == tie(p.x, p.y); }\n  P operator+(P p) const { return P(x + p.x,\
    \ y + p.y); }\n  P operator-(P p) const { return P(x - p.x, y - p.y); }\n  P operator*(T\
    \ d) const { return P(x * d, y * d); }\n  P operator/(T d) const { return P(x\
    \ / d, y / d); }\n  T dot(P p) const { return x * p.x + y * p.y; }\n  T cross(P\
    \ p) const { return x * p.y - y * p.x; }\n  T cross(P a, P b) const { return (a\
    \ - *this).cross(b - *this); }\n  T dist2() const { return x * x + y * y; }\n\
    \  T dist() const { return sqrt(dist2()); }\n  // angle to x-axis in interval\
    \ [-pi, pi]\n  T angle() const { return atan2l(y, x); }\n  P unit() const { return\
    \ *this / dist(); }  // makes dist()=1\n  P perp() const { return P(-y, x); }\
    \        // rotates +90 degrees\n  P normal() const { return perp().unit(); }\n\
    \  // returns point rotated 'a' radians ccw around the origin\n  P rotate(ld a)\
    \ const {\n    return P(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a));\n \
    \ }\n  friend ostream& operator<<(ostream& os, P p) {\n    return os << \"(\"\
    \ << p.x << \",\" << p.y << \")\";\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: geometry/Point.h
  requiredBy:
  - geometry/InsidePolygon.h
  - geometry/LineIntersection.h
  - geometry/PolygonCenter.h
  - geometry/OnSegment.h
  - geometry/SegmentDistance.h
  - geometry/CirclePolygonIntersection.h
  - geometry/ClosestPair.h
  - geometry/HalfplaneSet.h
  - geometry/LineHullIntersection.h
  - geometry/PointInsideHull.h
  - geometry/SegmentIntersection.h
  - geometry/SideOf.h
  - geometry/LineProjectionReflection.h
  - geometry/CircleLine.h
  - geometry/CircleIntersection.h
  - geometry/Minkowski.h
  - geometry/PolygonArea.h
  - geometry/ConvexHull.h
  - geometry/CircleTangents.h
  - geometry/TrianglePointCount.h
  - geometry/HullDiameter.h
  - geometry/Circumcircle.h
  - geometry/MinimumEnclosingCircle.h
  - geometry/LineDistance.h
  - geometry/LinearTransformation.h
  timestamp: '2025-11-21 16:12:02+07:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - tests/Static_Convex_Hull.test.cpp
  - tests/Minimum_Enclosing_Circle.test.cpp
  - tests/Furthest_Pair_of_Points.test.cpp
  - tests/Closest_Pair_of_Points.test.cpp
  - tests/Sort_Points_by_Argument.test.cpp
  - tests/Count_Points_in_Triangle.test.cpp
documentation_of: geometry/Point.h
layout: document
redirect_from:
- /library/geometry/Point.h
- /library/geometry/Point.h.html
title: geometry/Point.h
---
