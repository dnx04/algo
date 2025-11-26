---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/FFT.h\"\ntypedef complex<ld> C;\ntypedef vector<ld>\
    \ vd;\nvoid fft(vector<C>& a) {\n  int n = a.size(), L = 31 - __builtin_clz(n);\n\
    \  static vector<complex<ld>> R(2, 1);\n  static vector<C> rt(2, 1);\n  for (static\
    \ int k = 2; k < n; k *= 2) {\n    R.resize(n), rt.resize(n);\n    auto x = polar(1.0L,\
    \ acos(-1.0L) / k);\n    for (int i = k; i < 2 * k; ++i) rt[i] = R[i] = i & 1\
    \ ? R[i / 2] * x : R[i / 2];\n  }\n  vi rev(n);\n  for (int i = 0; i < n; ++i)\
    \ rev[i] = (rev[i / 2] | (i & 1) << L) / 2;\n  for (int i = 0; i < n; ++i)\n \
    \   if (i < rev[i]) swap(a[i], a[rev[i]]);\n  for (int k = 1; k < n; k *= 2) {\n\
    \    for (int i = 0; i < n; i += 2 * k) {\n      for (int j = 0; j < k; ++j) {\n\
    \        auto x = (ld*) &rt[j + k], y = (ld*) &a[i + j + k];\n        C z(x[0]\
    \ * y[0] - x[1] * y[1], x[0] * y[1] + x[1] * y[0]);\n        a[i + j + k] = a[i\
    \ + j] - z;\n        a[i + j] += z;\n      }\n    }\n  }\n}\nvd convolution(const\
    \ vd& a, const vd& b) {\n  if (a.empty() || b.empty()) return {};\n  vd res(sz(a)\
    \ + sz(b) - 1);\n  int L = 32 - __builtin_clz(sz(res)), n = 1 << L;\n  vector<C>\
    \ in(n), out(n);\n  copy(all(a), begin(in));\n  for (int i = 0; i < sz(b); ++i)\
    \ in[i].imag(b[i]);\n  fft(in);\n  for (C& x : in) x *= x;\n  for (int i = 0;\
    \ i < n; ++i) out[i] = in[-i & (n - 1)] - conj(in[i]);\n  fft(out);\n  for (int\
    \ i = 0; i < sz(res); ++i) res[i] = imag(out[i]) / (4 * n);\n  return res;\n}\n"
  code: "typedef complex<ld> C;\ntypedef vector<ld> vd;\nvoid fft(vector<C>& a) {\n\
    \  int n = a.size(), L = 31 - __builtin_clz(n);\n  static vector<complex<ld>>\
    \ R(2, 1);\n  static vector<C> rt(2, 1);\n  for (static int k = 2; k < n; k *=\
    \ 2) {\n    R.resize(n), rt.resize(n);\n    auto x = polar(1.0L, acos(-1.0L) /\
    \ k);\n    for (int i = k; i < 2 * k; ++i) rt[i] = R[i] = i & 1 ? R[i / 2] * x\
    \ : R[i / 2];\n  }\n  vi rev(n);\n  for (int i = 0; i < n; ++i) rev[i] = (rev[i\
    \ / 2] | (i & 1) << L) / 2;\n  for (int i = 0; i < n; ++i)\n    if (i < rev[i])\
    \ swap(a[i], a[rev[i]]);\n  for (int k = 1; k < n; k *= 2) {\n    for (int i =\
    \ 0; i < n; i += 2 * k) {\n      for (int j = 0; j < k; ++j) {\n        auto x\
    \ = (ld*) &rt[j + k], y = (ld*) &a[i + j + k];\n        C z(x[0] * y[0] - x[1]\
    \ * y[1], x[0] * y[1] + x[1] * y[0]);\n        a[i + j + k] = a[i + j] - z;\n\
    \        a[i + j] += z;\n      }\n    }\n  }\n}\nvd convolution(const vd& a, const\
    \ vd& b) {\n  if (a.empty() || b.empty()) return {};\n  vd res(sz(a) + sz(b) -\
    \ 1);\n  int L = 32 - __builtin_clz(sz(res)), n = 1 << L;\n  vector<C> in(n),\
    \ out(n);\n  copy(all(a), begin(in));\n  for (int i = 0; i < sz(b); ++i) in[i].imag(b[i]);\n\
    \  fft(in);\n  for (C& x : in) x *= x;\n  for (int i = 0; i < n; ++i) out[i] =\
    \ in[-i & (n - 1)] - conj(in[i]);\n  fft(out);\n  for (int i = 0; i < sz(res);\
    \ ++i) res[i] = imag(out[i]) / (4 * n);\n  return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/FFT.h
  requiredBy: []
  timestamp: '2025-11-26 18:05:06+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/FFT.h
layout: document
redirect_from:
- /library/math/FFT.h
- /library/math/FFT.h.html
title: math/FFT.h
---
