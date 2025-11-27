---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/ModInt.h
    title: math/ModInt.h
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/Convolution.test.cpp
    title: tests/Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Exp_of_FPS.test.cpp
    title: tests/Exp_of_FPS.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Inv_of_FPS.test.cpp
    title: tests/Inv_of_FPS.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Pow_of_FPS.test.cpp
    title: tests/Pow_of_FPS.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/ModInt.h\"\n\ntemplate <int mod>\nstruct modint {\n\
    \  using M = modint;\n  static_assert(mod > 0 && mod <= 2147483647);\n  static\
    \ constexpr int modulo = mod;\n  static constexpr u32 r1 = []() {\n    u32 r1\
    \ = mod;\n    for (int i = 0; i < 5; ++i) r1 *= 2 - mod * r1;\n    return -r1;\n\
    \  }();\n  static constexpr u32 r2 = -u64(mod) % mod;\n  static u32 reduce(u64\
    \ x) {\n    u32 y = u32(x) * r1, r = (x + u64(y) * mod) >> 32;\n    return r >=\
    \ mod ? r - mod : r;\n  }\n  u32 x;\n  modint() : x(0) {}\n  modint(i64 x) : x(reduce(u64(x\
    \ % mod + mod) * r2)) {}\n  M& operator+=(const M& a) {\n    if ((x += a.x) >=\
    \ mod) x -= mod;\n    return *this;\n  }\n  M& operator-=(const M& a) {\n    if\
    \ ((x += mod - a.x) >= mod) x -= mod;\n    return *this;\n  }\n  M& operator*=(const\
    \ M& a) {\n    x = reduce(u64(x) * a.x);\n    return *this;\n  }\n  M& operator/=(const\
    \ M& a) { return *this *= a.inv(); }\n  M operator-() const { return M(0) - *this;\
    \ }\n  M operator+(const M& a) const { return M(*this) += a; }\n  M operator-(const\
    \ M& a) const { return M(*this) -= a; }\n  M operator*(const M& a) const { return\
    \ M(*this) *= a; }\n  M operator/(const M& a) const { return M(*this) /= a; }\n\
    \  bool operator==(const M& a) const { return x == a.x; }\n  bool operator!=(const\
    \ M& a) const { return x != a.x; }\n  M pow(u64 k) const {\n    M res(1), b =\
    \ *this;\n    while (k) {\n      if (k & 1) res *= b;\n      b *= b, k >>= 1;\n\
    \    }\n    return res;\n  }\n  M inv() const { return pow(mod - 2); }\n  friend\
    \ ostream& operator<<(ostream& os, const M& a) {\n    return os << reduce(a.x);\n\
    \  }\n  friend istream& operator>>(istream& is, M& a) {\n    i64 v;\n    is >>\
    \ v;\n    a = M(v);\n    return is;\n  }\n};\n\nu64 modmul(u64 x, u64 y, u64 m)\
    \ { return u128(x) * y % m; }\nu64 modpow(u64 x, u64 k, u64 m) {\n  u64 res =\
    \ 1;\n  while (k) {\n    if (k & 1) res = modmul(res, x, m);\n    x = modmul(x,\
    \ x, m);\n    k >>= 1;\n  }\n  return res;\n}\n#line 2 \"math/Poly.h\"\n\nusing\
    \ Fp = modint<998244353>;\nnamespace ntt {\nvoid ntt(vector<Fp>& a, bool inv)\
    \ {\n  int n = sz(a);\n  for (int i = 1, j = 0; i < n; i++) {\n    int bit = n\
    \ >> 1;\n    for (; j & bit; bit >>= 1) j ^= bit;\n    j ^= bit;\n    if (i <\
    \ j) swap(a[i], a[j]);\n  }\n  for (int len = 1; len < n; len <<= 1) {\n    Fp\
    \ wlen = Fp(3).pow((Fp::modulo - 1) / (2 * len));\n    if (inv) wlen = wlen.inv();\n\
    \    for (int i = 0; i < n; i += 2 * len) {\n      Fp w = 1;\n      for (int j\
    \ = 0; j < len; j++) {\n        Fp u = a[i + j], v = a[i + j + len] * w;\n   \
    \     a[i + j] = u + v, a[i + j + len] = u - v;\n        w *= wlen;\n      }\n\
    \    }\n  }\n  if (inv) {\n    Fp n_inv = Fp(n).inv();\n    for (auto& x : a)\
    \ x *= n_inv;\n  }\n}\nvector<Fp> conv(vector<Fp> a, vector<Fp> b) {\n  if (a.empty()\
    \ || b.empty()) return {};\n  int s = sz(a) + sz(b) - 1, n = 1;\n  while (n <\
    \ s) n <<= 1;\n  a.resize(n), b.resize(n);\n  ntt(a, 0), ntt(b, 0);\n  for (int\
    \ i = 0; i < n; i++) a[i] *= b[i];\n  ntt(a, 1), a.resize(s);\n  return a;\n}\n\
    }  // namespace ntt\n\nstruct Poly : vector<Fp> {\n  using vector::vector;\n \
    \ Poly(const vector<Fp>& v) : vector(v) {}\n\n  Poly cut(int n) const {\n    Poly\
    \ res = *this;\n    res.resize(n);\n    return res;\n  }\n\n  Poly operator+(const\
    \ Poly& r) const {\n    Poly res = *this;\n    res.resize(max(sz(*this), sz(r)));\n\
    \    for (int i = 0; i < sz(r); ++i) res[i] += r[i];\n    return res;\n  }\n \
    \ Poly operator-(const Poly& r) const {\n    Poly res = *this;\n    res.resize(max(sz(*this),\
    \ sz(r)));\n    for (int i = 0; i < sz(r); ++i) res[i] -= r[i];\n    return res;\n\
    \  }\n  Poly operator*(const Poly& r) const { return ntt::conv(*this, r); }\n\
    \  Poly operator*(Fp v) const {\n    Poly res = *this;\n    for (auto& x : res)\
    \ x *= v;\n    return res;\n  }\n  Poly& operator+=(const Poly& r) { return *this\
    \ = *this + r; }\n  Poly& operator-=(const Poly& r) { return *this = *this - r;\
    \ }\n  Poly& operator*=(const Poly& r) { return *this = *this * r; }\n\n  Poly\
    \ deriv() const {\n    if (empty()) return {};\n    Poly res(sz(*this) - 1);\n\
    \    for (int i = 1; i < sz(*this); ++i) res[i - 1] = data()[i] * i;\n    return\
    \ res;\n  }\n  Poly integ() const {\n    Poly res(sz(*this) + 1);\n    for (int\
    \ i = 0; i < sz(*this); ++i) res[i + 1] = data()[i] * Fp(i + 1).inv();\n    return\
    \ res;\n  }\n  Poly inv(int n) const {\n    Poly b = {data()[0].inv()};\n    for\
    \ (int k = 1; k < n; k <<= 1) {\n      Poly a = cut(2 * k);\n      Poly prod =\
    \ b * b * a;\n      b.resize(2 * k);\n      for (int i = 0; i < 2 * k; ++i) {\n\
    \        b[i] = b[i] * 2 - (i < sz(prod) ? prod[i] : Fp(0));\n      }\n    }\n\
    \    return b.cut(n);\n  }\n\n  Poly log(int n) const { return (deriv() * inv(n)).integ().cut(n);\
    \ }\n\n  Poly exp(int n) const {\n    Poly b = {1};\n    for (int k = 1; k < n;\
    \ k <<= 1) {\n      Poly ln_b = b.log(2 * k);\n      Poly a = cut(2 * k);\n  \
    \    Poly diff = a - ln_b;\n      diff[0] += 1;\n      b = (b * diff).cut(2 *\
    \ k);\n    }\n    return b.cut(n);\n  }\n\n  Poly pow(i64 k, int n) const {\n\
    \    if (n == 0) return {};\n    if (k == 0) {\n      Poly res = {1};\n      res.resize(n);\n\
    \      return res;\n    }\n    int i = 0;\n    while (i < sz(*this) && data()[i].x\
    \ == 0) i++;\n    if (i == sz(*this) || (i > 0 && k >= n / i + 2)) {\n      Poly\
    \ res;\n      res.resize(n);\n      return res;\n    }\n    i64 shift = (i64)\
    \ i * k;\n    if (shift >= n) {\n      Poly res;\n      res.resize(n);\n     \
    \ return res;\n    }\n    Poly a = {begin() + i, end()};\n    int limit = n -\
    \ shift;\n    a.resize(limit);\n    Fp lead = a[0];\n    Fp inv_lead = lead.inv();\n\
    \    a = a * inv_lead;\n    a = (a.log(limit) * Fp(k)).exp(limit);\n    a = a\
    \ * lead.pow(k);\n    Poly res(shift, 0);\n    res.insert(res.end(), a.begin(),\
    \ a.end());\n    res.resize(n);\n    return res;\n  }\n  friend ostream& operator<<(ostream&\
    \ os, const Poly& p) {\n    for (auto x : p) os << x << \" \";\n    return os;\n\
    \  }\n};\n"
  code: "#include \"ModInt.h\"\n\nusing Fp = modint<998244353>;\nnamespace ntt {\n\
    void ntt(vector<Fp>& a, bool inv) {\n  int n = sz(a);\n  for (int i = 1, j = 0;\
    \ i < n; i++) {\n    int bit = n >> 1;\n    for (; j & bit; bit >>= 1) j ^= bit;\n\
    \    j ^= bit;\n    if (i < j) swap(a[i], a[j]);\n  }\n  for (int len = 1; len\
    \ < n; len <<= 1) {\n    Fp wlen = Fp(3).pow((Fp::modulo - 1) / (2 * len));\n\
    \    if (inv) wlen = wlen.inv();\n    for (int i = 0; i < n; i += 2 * len) {\n\
    \      Fp w = 1;\n      for (int j = 0; j < len; j++) {\n        Fp u = a[i +\
    \ j], v = a[i + j + len] * w;\n        a[i + j] = u + v, a[i + j + len] = u -\
    \ v;\n        w *= wlen;\n      }\n    }\n  }\n  if (inv) {\n    Fp n_inv = Fp(n).inv();\n\
    \    for (auto& x : a) x *= n_inv;\n  }\n}\nvector<Fp> conv(vector<Fp> a, vector<Fp>\
    \ b) {\n  if (a.empty() || b.empty()) return {};\n  int s = sz(a) + sz(b) - 1,\
    \ n = 1;\n  while (n < s) n <<= 1;\n  a.resize(n), b.resize(n);\n  ntt(a, 0),\
    \ ntt(b, 0);\n  for (int i = 0; i < n; i++) a[i] *= b[i];\n  ntt(a, 1), a.resize(s);\n\
    \  return a;\n}\n}  // namespace ntt\n\nstruct Poly : vector<Fp> {\n  using vector::vector;\n\
    \  Poly(const vector<Fp>& v) : vector(v) {}\n\n  Poly cut(int n) const {\n   \
    \ Poly res = *this;\n    res.resize(n);\n    return res;\n  }\n\n  Poly operator+(const\
    \ Poly& r) const {\n    Poly res = *this;\n    res.resize(max(sz(*this), sz(r)));\n\
    \    for (int i = 0; i < sz(r); ++i) res[i] += r[i];\n    return res;\n  }\n \
    \ Poly operator-(const Poly& r) const {\n    Poly res = *this;\n    res.resize(max(sz(*this),\
    \ sz(r)));\n    for (int i = 0; i < sz(r); ++i) res[i] -= r[i];\n    return res;\n\
    \  }\n  Poly operator*(const Poly& r) const { return ntt::conv(*this, r); }\n\
    \  Poly operator*(Fp v) const {\n    Poly res = *this;\n    for (auto& x : res)\
    \ x *= v;\n    return res;\n  }\n  Poly& operator+=(const Poly& r) { return *this\
    \ = *this + r; }\n  Poly& operator-=(const Poly& r) { return *this = *this - r;\
    \ }\n  Poly& operator*=(const Poly& r) { return *this = *this * r; }\n\n  Poly\
    \ deriv() const {\n    if (empty()) return {};\n    Poly res(sz(*this) - 1);\n\
    \    for (int i = 1; i < sz(*this); ++i) res[i - 1] = data()[i] * i;\n    return\
    \ res;\n  }\n  Poly integ() const {\n    Poly res(sz(*this) + 1);\n    for (int\
    \ i = 0; i < sz(*this); ++i) res[i + 1] = data()[i] * Fp(i + 1).inv();\n    return\
    \ res;\n  }\n  Poly inv(int n) const {\n    Poly b = {data()[0].inv()};\n    for\
    \ (int k = 1; k < n; k <<= 1) {\n      Poly a = cut(2 * k);\n      Poly prod =\
    \ b * b * a;\n      b.resize(2 * k);\n      for (int i = 0; i < 2 * k; ++i) {\n\
    \        b[i] = b[i] * 2 - (i < sz(prod) ? prod[i] : Fp(0));\n      }\n    }\n\
    \    return b.cut(n);\n  }\n\n  Poly log(int n) const { return (deriv() * inv(n)).integ().cut(n);\
    \ }\n\n  Poly exp(int n) const {\n    Poly b = {1};\n    for (int k = 1; k < n;\
    \ k <<= 1) {\n      Poly ln_b = b.log(2 * k);\n      Poly a = cut(2 * k);\n  \
    \    Poly diff = a - ln_b;\n      diff[0] += 1;\n      b = (b * diff).cut(2 *\
    \ k);\n    }\n    return b.cut(n);\n  }\n\n  Poly pow(i64 k, int n) const {\n\
    \    if (n == 0) return {};\n    if (k == 0) {\n      Poly res = {1};\n      res.resize(n);\n\
    \      return res;\n    }\n    int i = 0;\n    while (i < sz(*this) && data()[i].x\
    \ == 0) i++;\n    if (i == sz(*this) || (i > 0 && k >= n / i + 2)) {\n      Poly\
    \ res;\n      res.resize(n);\n      return res;\n    }\n    i64 shift = (i64)\
    \ i * k;\n    if (shift >= n) {\n      Poly res;\n      res.resize(n);\n     \
    \ return res;\n    }\n    Poly a = {begin() + i, end()};\n    int limit = n -\
    \ shift;\n    a.resize(limit);\n    Fp lead = a[0];\n    Fp inv_lead = lead.inv();\n\
    \    a = a * inv_lead;\n    a = (a.log(limit) * Fp(k)).exp(limit);\n    a = a\
    \ * lead.pow(k);\n    Poly res(shift, 0);\n    res.insert(res.end(), a.begin(),\
    \ a.end());\n    res.resize(n);\n    return res;\n  }\n  friend ostream& operator<<(ostream&\
    \ os, const Poly& p) {\n    for (auto x : p) os << x << \" \";\n    return os;\n\
    \  }\n};"
  dependsOn:
  - math/ModInt.h
  isVerificationFile: false
  path: math/Poly.h
  requiredBy: []
  timestamp: '2025-11-26 18:05:06+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/Pow_of_FPS.test.cpp
  - tests/Inv_of_FPS.test.cpp
  - tests/Exp_of_FPS.test.cpp
  - tests/Convolution.test.cpp
documentation_of: math/Poly.h
layout: document
redirect_from:
- /library/math/Poly.h
- /library/math/Poly.h.html
title: math/Poly.h
---
