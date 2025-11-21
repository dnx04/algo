---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/ModInt.h
    title: math/ModInt.h
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/Sum_of_Exponential_times_Polynomial.test.cpp
    title: tests/Sum_of_Exponential_times_Polynomial.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Sum_of_Exponential_times_Polynomial_limit.test.cpp
    title: tests/Sum_of_Exponential_times_Polynomial_limit.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/ModInt.h\"\n\ntemplate <int mod>\nstruct modint {\n\
    \  using M = modint;\n  static_assert(mod > 0 && mod <= 2147483647);\n  static\
    \ constexpr u32 r1 = []() {\n    u32 r1 = mod;\n    for (int i = 0; i < 5; ++i)\
    \ r1 *= 2 - mod * r1;\n    return -r1;\n  }();\n  static constexpr u32 r2 = -u64(mod)\
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
    \ 2 \"math/SumPowerPoly.h\"\n\nusing Fp = modint<998244353>;\n\nvector<Fp> fac,\
    \ invFac;\nvoid prepareFac(int n) {\n  fac.resize(n + 1);\n  invFac.resize(n +\
    \ 1);\n  fac[0] = 1;\n  for (int i = 1; i <= n; ++i) fac[i] = fac[i - 1] * i;\n\
    \  invFac[n] = fac[n].inv();\n  for (int i = n; i >= 1; --i) invFac[i - 1] = invFac[i]\
    \ * i;\n}\n\n// Lagrange interpolation [0,...,n-1] in O(n)\nFp interpolate(const\
    \ vector<Fp>& y, i64 n) {\n  int k = sz(y) - 1;\n  if (n <= k) return y[n];\n\
    \  vector<Fp> pre(k + 1), suf(k + 1);\n  pre[0] = suf[k] = 1;\n  for (int i =\
    \ 0; i < k; ++i) pre[i + 1] = pre[i] * (n - i);\n  for (int i = k; i > 0; --i)\
    \ suf[i - 1] = suf[i] * (n - i);\n  Fp ans = 0;\n  for (int i = 0; i <= k; ++i)\
    \ {\n    Fp val = pre[i] * suf[i] * y[i] * invFac[i] * invFac[k - i];\n    if\
    \ ((k - i) & 1) ans -= val;\n    else ans += val;\n  }\n  return ans;\n}\n\n//\
    \ C = sum_{i=0->inf} r^i * fs[i] (r != 1)\nFp sumPolyLimit(Fp r, const vector<Fp>&\
    \ fs) {\n  int d = fs.size() - 1;\n  if (r.x == 0) return fs[0];\n  vector<Fp>\
    \ rr(d + 1);\n  rr[0] = 1;\n  for (int i = 1; i <= d; ++i) rr[i] = rr[i - 1] *\
    \ r;\n  Fp ans = 0, S = 0;\n  for (int i = 0; i <= d; ++i) {\n    S += rr[i] *\
    \ fs[i];\n    Fp term = invFac[d - i] * invFac[i + 1] * rr[d - i] * S;\n    if\
    \ ((d - i) & 1) ans -= term;\n    else ans += term;\n  }\n  return ans * fac[d\
    \ + 1] / (Fp(1) - r).pow(d + 1);\n}\n\n// Sum_{i=0->n-1} r^i * fs[i]\nFp sumPoly(Fp\
    \ r, const vector<Fp>& fs, u64 n) {\n  if (n == 0) return 0;\n  if (r == 0) return\
    \ fs[0];\n  int d = sz(fs) - 1;\n  if (r == 1) {\n    vector<Fp> S(d + 2);\n \
    \   S[0] = 0;\n    for (int i = 0; i <= d; ++i) S[i + 1] = S[i] + fs[i];\n   \
    \ return interpolate(S, n);\n  }\n  Fp C = sumPolyLimit(r, fs), S_curr = 0, rp\
    \ = 1, rip = 1, ri = r.inv();\n  vector<Fp> g(d + 1);\n  for (int k = 0; k <=\
    \ d; ++k) {\n    g[k] = (S_curr - C) * rip;\n    S_curr += rp * fs[k], rp *= r,\
    \ rip *= ri;\n  }\n  return C + r.pow(n) * interpolate(g, n);\n}\n"
  code: "#include \"ModInt.h\"\n\nusing Fp = modint<998244353>;\n\nvector<Fp> fac,\
    \ invFac;\nvoid prepareFac(int n) {\n  fac.resize(n + 1);\n  invFac.resize(n +\
    \ 1);\n  fac[0] = 1;\n  for (int i = 1; i <= n; ++i) fac[i] = fac[i - 1] * i;\n\
    \  invFac[n] = fac[n].inv();\n  for (int i = n; i >= 1; --i) invFac[i - 1] = invFac[i]\
    \ * i;\n}\n\n// Lagrange interpolation [0,...,n-1] in O(n)\nFp interpolate(const\
    \ vector<Fp>& y, i64 n) {\n  int k = sz(y) - 1;\n  if (n <= k) return y[n];\n\
    \  vector<Fp> pre(k + 1), suf(k + 1);\n  pre[0] = suf[k] = 1;\n  for (int i =\
    \ 0; i < k; ++i) pre[i + 1] = pre[i] * (n - i);\n  for (int i = k; i > 0; --i)\
    \ suf[i - 1] = suf[i] * (n - i);\n  Fp ans = 0;\n  for (int i = 0; i <= k; ++i)\
    \ {\n    Fp val = pre[i] * suf[i] * y[i] * invFac[i] * invFac[k - i];\n    if\
    \ ((k - i) & 1) ans -= val;\n    else ans += val;\n  }\n  return ans;\n}\n\n//\
    \ C = sum_{i=0->inf} r^i * fs[i] (r != 1)\nFp sumPolyLimit(Fp r, const vector<Fp>&\
    \ fs) {\n  int d = fs.size() - 1;\n  if (r.x == 0) return fs[0];\n  vector<Fp>\
    \ rr(d + 1);\n  rr[0] = 1;\n  for (int i = 1; i <= d; ++i) rr[i] = rr[i - 1] *\
    \ r;\n  Fp ans = 0, S = 0;\n  for (int i = 0; i <= d; ++i) {\n    S += rr[i] *\
    \ fs[i];\n    Fp term = invFac[d - i] * invFac[i + 1] * rr[d - i] * S;\n    if\
    \ ((d - i) & 1) ans -= term;\n    else ans += term;\n  }\n  return ans * fac[d\
    \ + 1] / (Fp(1) - r).pow(d + 1);\n}\n\n// Sum_{i=0->n-1} r^i * fs[i]\nFp sumPoly(Fp\
    \ r, const vector<Fp>& fs, u64 n) {\n  if (n == 0) return 0;\n  if (r == 0) return\
    \ fs[0];\n  int d = sz(fs) - 1;\n  if (r == 1) {\n    vector<Fp> S(d + 2);\n \
    \   S[0] = 0;\n    for (int i = 0; i <= d; ++i) S[i + 1] = S[i] + fs[i];\n   \
    \ return interpolate(S, n);\n  }\n  Fp C = sumPolyLimit(r, fs), S_curr = 0, rp\
    \ = 1, rip = 1, ri = r.inv();\n  vector<Fp> g(d + 1);\n  for (int k = 0; k <=\
    \ d; ++k) {\n    g[k] = (S_curr - C) * rip;\n    S_curr += rp * fs[k], rp *= r,\
    \ rip *= ri;\n  }\n  return C + r.pow(n) * interpolate(g, n);\n}"
  dependsOn:
  - math/ModInt.h
  isVerificationFile: false
  path: math/SumPowerPoly.h
  requiredBy: []
  timestamp: '2025-11-21 16:12:02+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/Sum_of_Exponential_times_Polynomial.test.cpp
  - tests/Sum_of_Exponential_times_Polynomial_limit.test.cpp
documentation_of: math/SumPowerPoly.h
layout: document
redirect_from:
- /library/math/SumPowerPoly.h
- /library/math/SumPowerPoly.h.html
title: math/SumPowerPoly.h
---
