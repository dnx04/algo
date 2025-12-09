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
  bundledCode: "#line 1 \"math/CRT.h\"\nstruct CRT {\n  i64 res = 0, mod = 1;\n  i64\
    \ euclid(i64 a, i64 b, i64 &x, i64 &y) {\n    if (!b) return x = 1, y = 0, a;\n\
    \    i64 d = euclid(b, a % b, y, x);\n    return y -= a / b * x, d;\n  }\n  //\
    \ Add condition: val % m = a\n  bool add(i64 m, i64 a) {\n    i64 x, y;\n    i64\
    \ g = euclid(mod, m, x, y);\n    if ((a - res) % g) return false;  // Incompatible\
    \ condition\n    i64 m0 = m / g;\n    // k = (a - res) / g * inv(mod / g) mod\
    \ (m / g)\n    i128 k = (i128)(a - res) / g * x % m0;\n    res += (i64)k * mod;\n\
    \    mod *= m0;\n    res = (res % mod + mod) % mod;\n    return true;\n  }\n};\n"
  code: "struct CRT {\n  i64 res = 0, mod = 1;\n  i64 euclid(i64 a, i64 b, i64 &x,\
    \ i64 &y) {\n    if (!b) return x = 1, y = 0, a;\n    i64 d = euclid(b, a % b,\
    \ y, x);\n    return y -= a / b * x, d;\n  }\n  // Add condition: val % m = a\n\
    \  bool add(i64 m, i64 a) {\n    i64 x, y;\n    i64 g = euclid(mod, m, x, y);\n\
    \    if ((a - res) % g) return false;  // Incompatible condition\n    i64 m0 =\
    \ m / g;\n    // k = (a - res) / g * inv(mod / g) mod (m / g)\n    i128 k = (i128)(a\
    \ - res) / g * x % m0;\n    res += (i64)k * mod;\n    mod *= m0;\n    res = (res\
    \ % mod + mod) % mod;\n    return true;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/CRT.h
  requiredBy: []
  timestamp: '2025-12-09 07:33:19+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/CRT.h
layout: document
redirect_from:
- /library/math/CRT.h
- /library/math/CRT.h.html
title: math/CRT.h
---
