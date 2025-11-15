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
  bundledCode: "#line 1 \"math/Lagrange.h\"\ntypedef vector<double> vd;\nvd interpolate(vd\
    \ x, vd y, int n) {\n  vd res(n), temp(n);\n  for (int k = 0; k < n - 1; ++k)\
    \ {\n    for (int i = k + 1; i < n; ++i) {\n      y[i] = (y[i] - y[k]) / (x[i]\
    \ - x[k]);\n    }\n  };\n  double last = 0;\n  temp[0] = 1;\n  for (int k = 0;\
    \ k < n; ++k) {\n    for (int i = 0; i < n; ++i) {\n      res[i] += y[k] * temp[i];\n\
    \      swap(last, temp[i]);\n      temp[i] -= last * x[k];\n    }\n  }\n  return\
    \ res;\n}\n"
  code: "typedef vector<double> vd;\nvd interpolate(vd x, vd y, int n) {\n  vd res(n),\
    \ temp(n);\n  for (int k = 0; k < n - 1; ++k) {\n    for (int i = k + 1; i < n;\
    \ ++i) {\n      y[i] = (y[i] - y[k]) / (x[i] - x[k]);\n    }\n  };\n  double last\
    \ = 0;\n  temp[0] = 1;\n  for (int k = 0; k < n; ++k) {\n    for (int i = 0; i\
    \ < n; ++i) {\n      res[i] += y[k] * temp[i];\n      swap(last, temp[i]);\n \
    \     temp[i] -= last * x[k];\n    }\n  }\n  return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/Lagrange.h
  requiredBy: []
  timestamp: '2025-11-15 18:26:28+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/Lagrange.h
layout: document
redirect_from:
- /library/math/Lagrange.h
- /library/math/Lagrange.h.html
title: math/Lagrange.h
---
