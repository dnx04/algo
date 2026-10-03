---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: geometry/Point.h
    title: geometry/Point.h
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/Count_Points_in_Triangle.test.cpp
    title: tests/Count_Points_in_Triangle.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \ << p.x << \",\" << p.y << \")\";\n  }\n};\n#line 2 \"geometry/TrianglePointCount.h\"\
    \n\ntemplate <class P, int MAXN, int MAXM>\nstruct TrianglePointCount {\n  //\
    \ B\u1EA3ng l\u01B0u tr\u1EA1ng th\xE1i: side[i][j] = bitset c\xE1c \u0111i\u1EC3\
    m B n\u1EB1m b\xEAn tr\xE1i vector A[i]->A[j]\n  bitset<MAXM> side[MAXN][MAXN];\n\
    \  const vector<P>& A;  // Tham chi\u1EBFu t\u1EDBi m\u1EA3ng A \u0111\u1EC3 ki\u1EC3\
    m tra h\u01B0\u1EDBng khi truy v\u1EA5n\n  // Constructor: Th\u1EF1c hi\u1EC7\
    n Precomputation O(N^2 * M)\n  TrianglePointCount(const vector<P>& A, const vector<P>&\
    \ B)\n      : A(A) {\n    int n = len(A), m = len(B);\n    for (int i = 0; i <\
    \ n; ++i) {\n      for (int j = 0; j < n; ++j) {\n        if (i == j) continue;\n\
    \        P vecIJ = A[j] - A[i];  // Vector A[i] -> A[j]\n        for (int k =\
    \ 0; k < m; ++k) {\n          P vecIK = B[k] - A[i];  // Vector A[i] -> B[k]\n\
    \          // N\u1EBFu B[k] n\u1EB1m th\u1EF1c s\u1EF1 b\xEAn tr\xE1i A[i]->A[j]\
    \ (cross product > 0)\n          if (vecIJ.cross(vecIK) > 0) side[i][j][k] = 1;\n\
    \        }\n      }\n    }\n  }\n  // Truy v\u1EA5n: \u0110\u1EBFm s\u1ED1 \u0111\
    i\u1EC3m B n\u1EB1m trong tam gi\xE1c A[a], A[b], A[c]\n  // \u0110\u1ED9 ph\u1EE9\
    c t\u1EA1p: O(M/64) ~ O(1)\n  int query(int a, int b, int c) {\n    // Ki\u1EC3\
    m tra h\u01B0\u1EDBng c\u1EE7a tam gi\xE1c\n    auto area = A[a].cross(A[b], A[c]);\n\
    \    if (area == 0) return 0;  // Tam gi\xE1c suy bi\u1EBFn (th\u1EB3ng h\xE0\
    ng)\n    if (area > 0) {\n      // Ng\u01B0\u1EE3c chi\u1EC1u kim \u0111\u1ED3\
    ng h\u1ED3 (CCW): A->B->C\n      // \u0110i\u1EC3m trong tam gi\xE1c ph\u1EA3\
    i n\u1EB1m tr\xE1i AB, tr\xE1i BC, V\xC0 tr\xE1i CA\n      return (side[a][b]\
    \ & side[b][c] & side[c][a]).count();\n    } else {\n      // C\xF9ng chi\u1EC1\
    u kim \u0111\u1ED3ng h\u1ED3 (CW): A->C->B l\xE0 CCW\n      return (side[a][c]\
    \ & side[c][b] & side[b][a]).count();\n    }\n  }\n};\n"
  code: "#include \"Point.h\"\n\ntemplate <class P, int MAXN, int MAXM>\nstruct TrianglePointCount\
    \ {\n  // B\u1EA3ng l\u01B0u tr\u1EA1ng th\xE1i: side[i][j] = bitset c\xE1c \u0111\
    i\u1EC3m B n\u1EB1m b\xEAn tr\xE1i vector A[i]->A[j]\n  bitset<MAXM> side[MAXN][MAXN];\n\
    \  const vector<P>& A;  // Tham chi\u1EBFu t\u1EDBi m\u1EA3ng A \u0111\u1EC3 ki\u1EC3\
    m tra h\u01B0\u1EDBng khi truy v\u1EA5n\n  // Constructor: Th\u1EF1c hi\u1EC7\
    n Precomputation O(N^2 * M)\n  TrianglePointCount(const vector<P>& A, const vector<P>&\
    \ B)\n      : A(A) {\n    int n = len(A), m = len(B);\n    for (int i = 0; i <\
    \ n; ++i) {\n      for (int j = 0; j < n; ++j) {\n        if (i == j) continue;\n\
    \        P vecIJ = A[j] - A[i];  // Vector A[i] -> A[j]\n        for (int k =\
    \ 0; k < m; ++k) {\n          P vecIK = B[k] - A[i];  // Vector A[i] -> B[k]\n\
    \          // N\u1EBFu B[k] n\u1EB1m th\u1EF1c s\u1EF1 b\xEAn tr\xE1i A[i]->A[j]\
    \ (cross product > 0)\n          if (vecIJ.cross(vecIK) > 0) side[i][j][k] = 1;\n\
    \        }\n      }\n    }\n  }\n  // Truy v\u1EA5n: \u0110\u1EBFm s\u1ED1 \u0111\
    i\u1EC3m B n\u1EB1m trong tam gi\xE1c A[a], A[b], A[c]\n  // \u0110\u1ED9 ph\u1EE9\
    c t\u1EA1p: O(M/64) ~ O(1)\n  int query(int a, int b, int c) {\n    // Ki\u1EC3\
    m tra h\u01B0\u1EDBng c\u1EE7a tam gi\xE1c\n    auto area = A[a].cross(A[b], A[c]);\n\
    \    if (area == 0) return 0;  // Tam gi\xE1c suy bi\u1EBFn (th\u1EB3ng h\xE0\
    ng)\n    if (area > 0) {\n      // Ng\u01B0\u1EE3c chi\u1EC1u kim \u0111\u1ED3\
    ng h\u1ED3 (CCW): A->B->C\n      // \u0110i\u1EC3m trong tam gi\xE1c ph\u1EA3\
    i n\u1EB1m tr\xE1i AB, tr\xE1i BC, V\xC0 tr\xE1i CA\n      return (side[a][b]\
    \ & side[b][c] & side[c][a]).count();\n    } else {\n      // C\xF9ng chi\u1EC1\
    u kim \u0111\u1ED3ng h\u1ED3 (CW): A->C->B l\xE0 CCW\n      return (side[a][c]\
    \ & side[c][b] & side[b][a]).count();\n    }\n  }\n};"
  dependsOn:
  - geometry/Point.h
  isVerificationFile: false
  path: geometry/TrianglePointCount.h
  requiredBy: []
  timestamp: '2026-10-03 15:27:40+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/Count_Points_in_Triangle.test.cpp
documentation_of: geometry/TrianglePointCount.h
layout: document
redirect_from:
- /library/geometry/TrianglePointCount.h
- /library/geometry/TrianglePointCount.h.html
title: geometry/TrianglePointCount.h
---
