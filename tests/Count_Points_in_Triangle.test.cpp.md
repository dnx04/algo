---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/Point.h
    title: geometry/Point.h
  - icon: ':heavy_check_mark:'
    path: geometry/TrianglePointCount.h
    title: geometry/TrianglePointCount.h
  - icon: ':heavy_check_mark:'
    path: misc/macros.h
    title: misc/macros.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/count_points_in_triangle
    links:
    - https://judge.yosupo.jp/problem/count_points_in_triangle
  bundledCode: "#line 1 \"tests/Count_Points_in_Triangle.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/count_points_in_triangle\"\n\n#line 1 \"misc/macros.h\"\
    \n// #pragma GCC optimize(\"Ofast,unroll-loops\")       // unroll long, simple\
    \ loops\n// #pragma GCC target(\"avx2,fma\")                   // vectorizing\
    \ code\n// #pragma GCC target(\"lzcnt,popcnt,abm,bmi,bmi2\")  // for fast bitset\
    \ operation\n\n#include <bits/extc++.h>\n\n#include <tr2/dynamic_bitset>\n\nusing\
    \ namespace std;\nusing namespace __gnu_pbds;  // ordered_set, gp_hash_table\n\
    // using namespace __gnu_cxx;\n\n// for templates to work\n#define all(s) s.begin(),\
    \ s.end()\n#define sz(x) (int) (x).size()\n#define pb push_back\n#define eb emplace_back\n\
    using i32 = int32_t;\nusing u32 = uint32_t;\nusing i64 = int64_t;\nusing u64 =\
    \ uint64_t;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\nusing ld = long\
    \ double;\nusing pii = pair<i32, i32>;\nusing vi = vector<i32>;\n\n// fast map\n\
    const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();\n\
    struct chash {  // customize hash function for gp_hash_table\n  int operator()(int\
    \ x) const { return x ^ RANDOM; }\n};\ngp_hash_table<int, int, chash> table;\n\
    \n/* ordered set\n    find_by_order(k): returns an iterator to the k-th element\
    \ (0-based)\n    order_of_key(k): returns the number of elements in the set that\
    \ are strictly less than k\n*/\ntemplate <class T>\nusing ordered_set = tree<T,\
    \ null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;\n\n// dynamic\
    \ bitset\nusing bs = tr2::dynamic_bitset<u64>;\n\n/*  rope\n    rope <int> cur\
    \ = v.substr(l, r - l + 1);\n    v.erase(l, r - l + 1);\n    v.insert(v.mutable_begin(),\
    \ cur);\n*/\n#line 2 \"geometry/Point.h\"\n\ntemplate <class T>\nint sgn(T x)\
    \ { return (x > 0) - (x < 0); }\ntemplate <class T>\nstruct Point {\n  typedef\
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
    \ os << \"(\" << p.x << \",\" << p.y << \")\";\n  }\n};\n#line 2 \"geometry/TrianglePointCount.h\"\
    \n\ntemplate <class P, int MAXN, int MAXM>\nstruct TrianglePointCount {\n  //\
    \ B\u1EA3ng l\u01B0u tr\u1EA1ng th\xE1i: side[i][j] = bitset c\xE1c \u0111i\u1EC3\
    m B n\u1EB1m b\xEAn tr\xE1i vector A[i]->A[j]\n  bitset<MAXM> side[MAXN][MAXN];\n\
    \  const vector<P>& A;  // Tham chi\u1EBFu t\u1EDBi m\u1EA3ng A \u0111\u1EC3 ki\u1EC3\
    m tra h\u01B0\u1EDBng khi truy v\u1EA5n\n  // Constructor: Th\u1EF1c hi\u1EC7\
    n Precomputation O(N^2 * M)\n  TrianglePointCount(const vector<P>& A, const vector<P>&\
    \ B)\n      : A(A) {\n    int n = sz(A), m = sz(B);\n    for (int i = 0; i < n;\
    \ ++i) {\n      for (int j = 0; j < n; ++j) {\n        if (i == j) continue;\n\
    \        P vecIJ = A[j] - A[i]; // Vector A[i] -> A[j]\n        for (int k = 0;\
    \ k < m; ++k) {\n          P vecIK = B[k] - A[i]; // Vector A[i] -> B[k]\n   \
    \       // N\u1EBFu B[k] n\u1EB1m th\u1EF1c s\u1EF1 b\xEAn tr\xE1i A[i]->A[j]\
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
    \ & side[c][b] & side[b][a]).count();\n    }\n  }\n};\n#line 5 \"tests/Count_Points_in_Triangle.test.cpp\"\
    \n\nusing P = Point<i64>;\n\nvoid solve() {\n  vector<P> A, B;\n  int n, m;\n\
    \  cin >> n;\n  A.resize(n);\n  for (auto& [x, y] : A) cin >> x >> y;\n  cin >>\
    \ m;\n  B.resize(m);\n  for (auto& [x, y] : B) cin >> x >> y;\n  TrianglePointCount<P,\
    \ 500, 500> tpc(A, B);\n  int q;\n  cin >> q;\n  while (q--) {\n    int a, b,\
    \ c;\n    cin >> a >> b >> c;\n    cout << tpc.query(a, b, c) << '\\n';\n  }\n\
    }\n\nint main() {\n  ios::sync_with_stdio(false);\n  cin.tie(0);\n  int tc = 1;\n\
    \  // cin >> tc;\n  while (tc--) solve();\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/count_points_in_triangle\"\
    \n\n#include \"../misc/macros.h\"\n#include \"../geometry/TrianglePointCount.h\"\
    \n\nusing P = Point<i64>;\n\nvoid solve() {\n  vector<P> A, B;\n  int n, m;\n\
    \  cin >> n;\n  A.resize(n);\n  for (auto& [x, y] : A) cin >> x >> y;\n  cin >>\
    \ m;\n  B.resize(m);\n  for (auto& [x, y] : B) cin >> x >> y;\n  TrianglePointCount<P,\
    \ 500, 500> tpc(A, B);\n  int q;\n  cin >> q;\n  while (q--) {\n    int a, b,\
    \ c;\n    cin >> a >> b >> c;\n    cout << tpc.query(a, b, c) << '\\n';\n  }\n\
    }\n\nint main() {\n  ios::sync_with_stdio(false);\n  cin.tie(0);\n  int tc = 1;\n\
    \  // cin >> tc;\n  while (tc--) solve();\n}"
  dependsOn:
  - misc/macros.h
  - geometry/TrianglePointCount.h
  - geometry/Point.h
  isVerificationFile: true
  path: tests/Count_Points_in_Triangle.test.cpp
  requiredBy: []
  timestamp: '2025-11-22 00:26:56+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/Count_Points_in_Triangle.test.cpp
layout: document
redirect_from:
- /verify/tests/Count_Points_in_Triangle.test.cpp
- /verify/tests/Count_Points_in_Triangle.test.cpp.html
title: tests/Count_Points_in_Triangle.test.cpp
---
