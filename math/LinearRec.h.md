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
  bundledCode: "#line 1 \"math/LinearRec.h\"\n// Usage: LinearRec({0, 1}, {1, 1},\
    \ k) -> k'th Fibonacci number\ntemplate <typename T>\nT LinearRec(const vector<T>&\
    \ S, const vector<T>& tr, ll k) {\n  int n = sz(tr);\n  auto combine = [&](Poly\
    \ a, Poly b) {\n    Poly res(n * 2 + 1);\n    for (int i = 0; i < n; ++i)\n  \
    \    for (int j = 0; j < n; ++j) res[i + j] = res[i + j] + a[i] * b[j];\n    for\
    \ (int i = 2 * n; i > n; --i)\n      for (int j = 0; j < n; ++j) res[i - 1 - j]\
    \ = res[i - 1 - j] + res[i] * tr[j];\n    res.resize(n + 1);\n    return res;\n\
    \  };\n  Poly pol(n + 1), e(pol);\n  pol[0] = e[1] = 1;\n  for (++k; k; k /= 2)\
    \ {\n    if (k % 2) pol = combine(pol, e);\n    e = combine(e, e);\n  }\n  ll\
    \ res = 0;\n  for (int i = 0; i < n; ++i) res = (res + pol[i + 1] * S[i]) % mod;\n\
    \  return res;\n}\n"
  code: "// Usage: LinearRec({0, 1}, {1, 1}, k) -> k'th Fibonacci number\ntemplate\
    \ <typename T>\nT LinearRec(const vector<T>& S, const vector<T>& tr, ll k) {\n\
    \  int n = sz(tr);\n  auto combine = [&](Poly a, Poly b) {\n    Poly res(n * 2\
    \ + 1);\n    for (int i = 0; i < n; ++i)\n      for (int j = 0; j < n; ++j) res[i\
    \ + j] = res[i + j] + a[i] * b[j];\n    for (int i = 2 * n; i > n; --i)\n    \
    \  for (int j = 0; j < n; ++j) res[i - 1 - j] = res[i - 1 - j] + res[i] * tr[j];\n\
    \    res.resize(n + 1);\n    return res;\n  };\n  Poly pol(n + 1), e(pol);\n \
    \ pol[0] = e[1] = 1;\n  for (++k; k; k /= 2) {\n    if (k % 2) pol = combine(pol,\
    \ e);\n    e = combine(e, e);\n  }\n  ll res = 0;\n  for (int i = 0; i < n; ++i)\
    \ res = (res + pol[i + 1] * S[i]) % mod;\n  return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/LinearRec.h
  requiredBy: []
  timestamp: '2025-11-15 18:26:28+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/LinearRec.h
layout: document
redirect_from:
- /library/math/LinearRec.h
- /library/math/LinearRec.h.html
title: math/LinearRec.h
---
