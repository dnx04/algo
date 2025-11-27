---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/Matrix.h
    title: math/Matrix.h
  - icon: ':question:'
    path: math/ModInt.h
    title: math/ModInt.h
  - icon: ':question:'
    path: misc/macros.h
    title: misc/macros.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/pow_of_matrix
    links:
    - https://judge.yosupo.jp/problem/pow_of_matrix
  bundledCode: "#line 1 \"tests/Pow_of_Matrix.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/pow_of_matrix\"\
    \n\n#line 1 \"misc/macros.h\"\n// #pragma GCC optimize(\"Ofast,unroll-loops\"\
    )       // unroll long, simple loops\n// #pragma GCC target(\"avx2,fma\")    \
    \               // vectorizing code\n// #pragma GCC target(\"lzcnt,popcnt,abm,bmi,bmi2\"\
    )  // for fast bitset operation\n\n#include <bits/extc++.h>\n#include <tr2/dynamic_bitset>\n\
    \nusing namespace std;\nusing namespace __gnu_pbds;  // ordered_set, gp_hash_table\n\
    // using namespace __gnu_cxx; // rope\n\n// for templates to work\n#define all(x)\
    \ (x).begin(), (x).end()\n#define sz(x) (int) (x).size()\n#define pb push_back\n\
    #define eb emplace_back\nusing i32 = int32_t;\nusing u32 = uint32_t;\nusing i64\
    \ = int64_t;\nusing u64 = uint64_t;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\
    using ld = long double;\nusing pii = pair<i32, i32>;\nusing vi = vector<i32>;\n\
    \n// fast map\nconst int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();\n\
    struct chash {  // customize hash function for gp_hash_table\n  int operator()(int\
    \ x) const { return x ^ RANDOM; }\n};\ngp_hash_table<int, int, chash> table;\n\
    \n/* ordered set\n    find_by_order(k): returns an iterator to the k-th element\
    \ (0-based)\n    order_of_key(k): returns the number of elements in the set that\
    \ are strictly less than k\n*/\ntemplate <class T>\nusing ordered_set = tree<T,\
    \ null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;\n\n/* \
    \ rope\n    rope <int> cur = v.substr(l, r - l + 1);\n    v.erase(l, r - l + 1);\n\
    \    v.insert(v.mutable_begin(), cur);\n*/\n#line 2 \"math/ModInt.h\"\n\ntemplate\
    \ <int mod>\nstruct modint {\n  using M = modint;\n  static_assert(mod > 0 &&\
    \ mod <= 2147483647);\n  static constexpr int modulo = mod;\n  static constexpr\
    \ u32 r1 = []() {\n    u32 r1 = mod;\n    for (int i = 0; i < 5; ++i) r1 *= 2\
    \ - mod * r1;\n    return -r1;\n  }();\n  static constexpr u32 r2 = -u64(mod)\
    \ % mod;\n  static u32 reduce(u64 x) {\n    u32 y = u32(x) * r1, r = (x + u64(y)\
    \ * mod) >> 32;\n    return r >= mod ? r - mod : r;\n  }\n  u32 x;\n  modint()\
    \ : x(0) {}\n  modint(i64 x) : x(reduce(u64(x % mod + mod) * r2)) {}\n  M& operator+=(const\
    \ M& a) {\n    if ((x += a.x) >= mod) x -= mod;\n    return *this;\n  }\n  M&\
    \ operator-=(const M& a) {\n    if ((x += mod - a.x) >= mod) x -= mod;\n    return\
    \ *this;\n  }\n  M& operator*=(const M& a) {\n    x = reduce(u64(x) * a.x);\n\
    \    return *this;\n  }\n  M& operator/=(const M& a) { return *this *= a.inv();\
    \ }\n  M operator-() const { return M(0) - *this; }\n  M operator+(const M& a)\
    \ const { return M(*this) += a; }\n  M operator-(const M& a) const { return M(*this)\
    \ -= a; }\n  M operator*(const M& a) const { return M(*this) *= a; }\n  M operator/(const\
    \ M& a) const { return M(*this) /= a; }\n  bool operator==(const M& a) const {\
    \ return x == a.x; }\n  bool operator!=(const M& a) const { return x != a.x; }\n\
    \  M pow(u64 k) const {\n    M res(1), b = *this;\n    while (k) {\n      if (k\
    \ & 1) res *= b;\n      b *= b, k >>= 1;\n    }\n    return res;\n  }\n  M inv()\
    \ const { return pow(mod - 2); }\n  friend ostream& operator<<(ostream& os, const\
    \ M& a) {\n    return os << reduce(a.x);\n  }\n  friend istream& operator>>(istream&\
    \ is, M& a) {\n    i64 v;\n    is >> v;\n    a = M(v);\n    return is;\n  }\n\
    };\n\nu64 modmul(u64 x, u64 y, u64 m) { return u128(x) * y % m; }\nu64 modpow(u64\
    \ x, u64 k, u64 m) {\n  u64 res = 1;\n  while (k) {\n    if (k & 1) res = modmul(res,\
    \ x, m);\n    x = modmul(x, x, m);\n    k >>= 1;\n  }\n  return res;\n}\n#line\
    \ 1 \"math/Matrix.h\"\ntemplate <class T>\nstruct Matrix {\n  int r, c;\n  vector<vector<T>>\
    \ a;\n  Matrix(int n) : Matrix(n, n) {}\n  Matrix(int r, int c) : r(r), c(c),\
    \ a(r, vector<T>(c, T(0))) {}\n  Matrix(const vector<vector<T>>& v) : r(sz(v)),\
    \ c(v.empty() ? 0 : sz(v[0])), a(v) {}\n  vector<T>& operator[](int i) { return\
    \ a[i]; }\n  const vector<T>& operator[](int i) const { return a[i]; }\n  static\
    \ Matrix eye(int n) {\n    Matrix res(n);\n    for (int i = 0; i < n; ++i) res[i][i]\
    \ = 1;\n    return res;\n  }\n  Matrix operator*(const Matrix& b) const {\n  \
    \  Matrix res(r, b.c);\n    for (int i = 0; i < r; ++i)\n      for (int k = 0;\
    \ k < c; ++k)\n        if (a[i][k] != T(0))\n          for (int j = 0; j < b.c;\
    \ ++j) res[i][j] += a[i][k] * b[k][j];\n    return res;\n  }\n  Matrix pow(u64\
    \ k) const {\n    Matrix res = eye(r), b = *this;\n    while (k) {\n      if (k\
    \ & 1) res = res * b;\n      b = b * b, k >>= 1;\n    }\n    return res;\n  }\n\
    \  // destructive\n  pair<T, int> gauss() {\n    int rank = 0;\n    T det = 1;\n\
    \    for (int j = 0; j < c && rank < r; ++j) {\n      int k = rank;\n      while\
    \ (k < r && a[k][j] == T(0)) k++;\n      if (k == r) {\n        det = 0;\n   \
    \     continue;\n      }\n      swap(a[rank], a[k]);\n      if (rank != k) det\
    \ = -det;\n      det *= a[rank][j];\n      T inv = T(1) / a[rank][j];\n      for\
    \ (int l = j; l < c; ++l) a[rank][l] *= inv;\n      for (int i = 0; i < r; ++i)\n\
    \        if (i != rank && a[i][j] != T(0)) {\n          T fac = a[i][j];\n   \
    \       for (int l = j; l < c; ++l) a[i][l] -= a[rank][l] * fac;\n        }\n\
    \      rank++;\n    }\n    return {det, rank};\n  }\n  pair<vector<T>, vector<vector<T>>>\
    \ solve(const Matrix& b) const {\n    if (r != b.r || b.c != 1) return {{}, {}};\n\
    \    Matrix mat(r, c + 1);\n    for (int i = 0; i < r; ++i) {\n      for (int\
    \ j = 0; j < c; ++j) mat[i][j] = a[i][j];\n      mat[i][c] = b[i][0];\n    }\n\
    \    int rank = mat.gauss().second;\n    vector<T> sol(c, T(0));\n    vector<int>\
    \ piv;\n    vector<bool> is_free(c, 1);\n    for (int i = 0; i < rank; ++i) {\n\
    \      int j = 0;\n      while (j <= c && mat[i][j] == T(0)) j++;\n      if (j\
    \ == c) return {{}, {}};\n      piv.push_back(j);\n      is_free[j] = 0;\n   \
    \   sol[j] = mat[i][c];\n    }\n    for (int i = rank; i < r; ++i)\n      if (mat[i][c]\
    \ != T(0)) return {{}, {}};\n    vector<vector<T>> ker;\n    for (int j = 0; j\
    \ < c; ++j) {\n      if (is_free[j]) {\n        vector<T> v(c, T(0));\n      \
    \  v[j] = T(1);\n        for (int i = 0; i < sz(piv); ++i) v[piv[i]] = T(0) -\
    \ mat[i][j];\n        ker.push_back(v);\n      }\n    }\n    return {sol, ker};\n\
    \  }\n  T det() const {\n    if (r != c) return T(0);\n    Matrix tmp = *this;\n\
    \    auto [d, rank] = tmp.gauss();\n    return (rank == r) ? d : T(0);\n  }\n\
    \  int rank() const {\n    Matrix tmp = *this;\n    return tmp.gauss().second;\n\
    \  }\n  Matrix inv() const {\n    if (r != c) return Matrix(0, 0);\n    Matrix\
    \ tmp(r, 2 * c);\n    for (int i = 0; i < r; ++i) {\n      for (int j = 0; j <\
    \ c; ++j) tmp[i][j] = a[i][j];\n      tmp[i][i + c] = 1;\n    }\n    auto [d,\
    \ rank] = tmp.gauss();\n    if (rank != r) return Matrix(0, 0);\n    Matrix res(r,\
    \ c);\n    for (int i = 0; i < r; ++i)\n      for (int j = 0; j < c; ++j) res[i][j]\
    \ = tmp[i][j + c];\n    return res;\n  }\n};\n#line 6 \"tests/Pow_of_Matrix.test.cpp\"\
    \n\nusing Fp = modint<998244353>;\n\nvoid solve() {\n  int n;\n  u64 k;\n  cin\
    \ >> n >> k;\n  Matrix<Fp> a(n);\n  for (int i = 0; i < n; ++i)\n    for (int\
    \ j = 0; j < n; ++j) cin >> a[i][j];\n  a = a.pow(k);\n  for (int i = 0; i < n;\
    \ ++i)\n    for (int j = 0; j < n; ++j) cout << a[i][j] << \" \\n\"[j + 1 == n];\n\
    }\n\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n  cin.exceptions(cin.failbit);\n\
    \  int tc = 1;\n  // cin >> tc;\n  for (int i = 1; i <= tc; ++i) {\n    solve();\n\
    \  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/pow_of_matrix\"\n\n#include\
    \ \"../misc/macros.h\"\n#include \"../math/ModInt.h\"\n#include \"../math/Matrix.h\"\
    \n\nusing Fp = modint<998244353>;\n\nvoid solve() {\n  int n;\n  u64 k;\n  cin\
    \ >> n >> k;\n  Matrix<Fp> a(n);\n  for (int i = 0; i < n; ++i)\n    for (int\
    \ j = 0; j < n; ++j) cin >> a[i][j];\n  a = a.pow(k);\n  for (int i = 0; i < n;\
    \ ++i)\n    for (int j = 0; j < n; ++j) cout << a[i][j] << \" \\n\"[j + 1 == n];\n\
    }\n\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n  cin.exceptions(cin.failbit);\n\
    \  int tc = 1;\n  // cin >> tc;\n  for (int i = 1; i <= tc; ++i) {\n    solve();\n\
    \  }\n}\n"
  dependsOn:
  - misc/macros.h
  - math/ModInt.h
  - math/Matrix.h
  isVerificationFile: true
  path: tests/Pow_of_Matrix.test.cpp
  requiredBy: []
  timestamp: '2025-11-28 02:09:51+07:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: tests/Pow_of_Matrix.test.cpp
layout: document
redirect_from:
- /verify/tests/Pow_of_Matrix.test.cpp
- /verify/tests/Pow_of_Matrix.test.cpp.html
title: tests/Pow_of_Matrix.test.cpp
---
