---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/Sum_of_Floor_of_Linear.test.cpp
    title: tests/Sum_of_Floor_of_Linear.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/DivModSum.h\"\ni64 sumsq(i64 to) { return to / 2 *\
    \ ((to - 1) | 1); }\n\n// sum( (a + d*i) / m ) for i in [0, n-1]\ni64 divsum(i64\
    \ a, i64 d, i64 m, i64 n) {\n  i64 res = d / m * sumsq(n) + a / m * n;\n  d %=\
    \ m, a %= m;\n  if (!d) return res;\n  i64 to = (n * d + a) / m;\n  return res\
    \ + (n - 1) * to - divsum(m - 1 - a, m, d, to);\n}\n// sum( (a + d*i) % m ) for\
    \ i in [0, n-1]\ni64 modsum(i64 a, i64 d, i64 m, i64 n) {\n  a = ((a % m) + m)\
    \ % m, d = ((d % m) + m) % m;\n  return n * a + d * sumsq(n) - m * divsum(a, d,\
    \ m, n);\n}\n"
  code: "i64 sumsq(i64 to) { return to / 2 * ((to - 1) | 1); }\n\n// sum( (a + d*i)\
    \ / m ) for i in [0, n-1]\ni64 divsum(i64 a, i64 d, i64 m, i64 n) {\n  i64 res\
    \ = d / m * sumsq(n) + a / m * n;\n  d %= m, a %= m;\n  if (!d) return res;\n\
    \  i64 to = (n * d + a) / m;\n  return res + (n - 1) * to - divsum(m - 1 - a,\
    \ m, d, to);\n}\n// sum( (a + d*i) % m ) for i in [0, n-1]\ni64 modsum(i64 a,\
    \ i64 d, i64 m, i64 n) {\n  a = ((a % m) + m) % m, d = ((d % m) + m) % m;\n  return\
    \ n * a + d * sumsq(n) - m * divsum(a, d, m, n);\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/DivModSum.h
  requiredBy: []
  timestamp: '2025-11-18 17:42:34+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/Sum_of_Floor_of_Linear.test.cpp
documentation_of: math/DivModSum.h
layout: document
redirect_from:
- /library/math/DivModSum.h
- /library/math/DivModSum.h.html
title: math/DivModSum.h
---
