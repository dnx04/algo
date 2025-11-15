---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: geometry/HalfplaneSet.h
    title: geometry/HalfplaneSet.h
  - icon: ':warning:'
    path: geometry/LineIntersection.h
    title: geometry/LineIntersection.h
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
    \ halfplane points to the left of vec.\n}\n"
  code: "using T = int; \nusing T2 = long long;\nusing T4 = __int128_t;\nconst T2\
    \ INF = 4e18;\n\nstruct Line { T a, b; T2 c; };\n\nbool half(Line m) { return\
    \ m.a < 0 || m.a == 0 && m.b < 0; };\nvoid normalize(Line& m) {\n  T2 g =gcd((T2)gcd(abs(m.a),\
    \ abs(m.b)), abs(m.c));\n  if (half(m)) g *= -1;\n  m.a /= g, m.b /= g, m.c /=\
    \ g;\n}\n// Sorts halfplanes in clockwise order. \n// To sort lines, normalize\
    \ first (gcd logic not needed).\nbool operator<(Line m, Line n) {\n  return make_pair(half(m),\
    \ (T2)m.b * n.a) < \n         make_pair(half(n), (T2)m.a * n.b);\n}\nLine LineFromPoints(T\
    \ x1, T y1, T x2, T y2) {\n  T a = y1 - y2, b = x2 - x1;\n  T2 c = (T2)a * x1\
    \ + (T2)b * y1;\n  return {a, b, c}; // halfplane points to the left of vec.\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: geometry/Line.h
  requiredBy:
  - geometry/LineIntersection.h
  - geometry/HalfplaneSet.h
  timestamp: '2025-11-15 18:26:28+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/Line.h
layout: document
redirect_from:
- /library/geometry/Line.h
- /library/geometry/Line.h.html
title: geometry/Line.h
---
