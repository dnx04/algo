---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/Min_of_Mod_of_Linear.test.cpp
    title: tests/Min_of_Mod_of_Linear.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Sum_of_Floor_of_Linear.test.cpp
    title: tests/Sum_of_Floor_of_Linear.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/DivModSum.h\"\n// T\xEDnh sum_{x=0}^{n-1} floor((a*x\
    \ + b) / m)\nu64 divsum(u64 n, u64 m, i64 a, i64 b) {\n  u64 ans = 0;\n  if (a\
    \ < 0) {\n    i64 a2 = (a % (i64) m + m) % m;\n    ans -= 1ULL * n * (n - 1) /\
    \ 2 * ((a2 - a) / m), a = a2;\n  }\n  if (b < 0) {\n    i64 b2 = (b % (i64) m\
    \ + m) % m;\n    ans -= 1ULL * n * ((b2 - b) / m), b = b2;\n  }\n  u64 ua = a,\
    \ ub = b;\n  while (true) {\n    if (ua >= m) ans += (n - 1) * n / 2 * (ua / m),\
    \ ua %= m;\n    if (ub >= m) ans += n * (ub / m), ub %= m;\n    u64 y_max = ua\
    \ * n + ub;\n    if (y_max < m) break;\n    n = y_max / m, ub = y_max % m, swap(m,\
    \ ua);\n  }\n  return ans;\n}\n\n// T\xEDnh sum_{x=0}^{n-1} ((a*x + b) % m)\n\
    u64 modsum(u64 n, u64 m, i64 a, i64 b) {\n  i128 sum = (i128) a * n * (n - 1)\
    \ / 2 + (i128) b * n;\n  return (u64) (sum - (i128) m * divsum(n, m, a, b));\n\
    }\n\n// T\xEDnh min_{x=0}^{n-1} ((a*x + b) % m)\ni64 minmod(u64 n, u64 m, i64\
    \ a, i64 b) {\n  i64 lo = 0, hi = m - 1, ans = b;\n  while (lo <= hi) {\n    auto\
    \ mid = (lo + hi) / 2;\n    auto cnt = divsum(n, m, a, b) - divsum(n, m, a, b\
    \ - mid - 1);\n    if (cnt > 0) ans = mid, hi = mid - 1;\n    else lo = mid +\
    \ 1;\n  }\n  return ans;\n}\n"
  code: "// T\xEDnh sum_{x=0}^{n-1} floor((a*x + b) / m)\nu64 divsum(u64 n, u64 m,\
    \ i64 a, i64 b) {\n  u64 ans = 0;\n  if (a < 0) {\n    i64 a2 = (a % (i64) m +\
    \ m) % m;\n    ans -= 1ULL * n * (n - 1) / 2 * ((a2 - a) / m), a = a2;\n  }\n\
    \  if (b < 0) {\n    i64 b2 = (b % (i64) m + m) % m;\n    ans -= 1ULL * n * ((b2\
    \ - b) / m), b = b2;\n  }\n  u64 ua = a, ub = b;\n  while (true) {\n    if (ua\
    \ >= m) ans += (n - 1) * n / 2 * (ua / m), ua %= m;\n    if (ub >= m) ans += n\
    \ * (ub / m), ub %= m;\n    u64 y_max = ua * n + ub;\n    if (y_max < m) break;\n\
    \    n = y_max / m, ub = y_max % m, swap(m, ua);\n  }\n  return ans;\n}\n\n//\
    \ T\xEDnh sum_{x=0}^{n-1} ((a*x + b) % m)\nu64 modsum(u64 n, u64 m, i64 a, i64\
    \ b) {\n  i128 sum = (i128) a * n * (n - 1) / 2 + (i128) b * n;\n  return (u64)\
    \ (sum - (i128) m * divsum(n, m, a, b));\n}\n\n// T\xEDnh min_{x=0}^{n-1} ((a*x\
    \ + b) % m)\ni64 minmod(u64 n, u64 m, i64 a, i64 b) {\n  i64 lo = 0, hi = m -\
    \ 1, ans = b;\n  while (lo <= hi) {\n    auto mid = (lo + hi) / 2;\n    auto cnt\
    \ = divsum(n, m, a, b) - divsum(n, m, a, b - mid - 1);\n    if (cnt > 0) ans =\
    \ mid, hi = mid - 1;\n    else lo = mid + 1;\n  }\n  return ans;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/DivModSum.h
  requiredBy: []
  timestamp: '2025-11-27 11:47:17+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/Min_of_Mod_of_Linear.test.cpp
  - tests/Sum_of_Floor_of_Linear.test.cpp
documentation_of: math/DivModSum.h
layout: document
redirect_from:
- /library/math/DivModSum.h
- /library/math/DivModSum.h.html
title: math/DivModSum.h
---
