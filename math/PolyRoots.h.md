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
  bundledCode: "#line 1 \"math/PolyRoots.h\"\nusing C = complex<double>;\n\nvector<C>\
    \ PolyRoots(vector<C> p) {\n  int n = p.size() - 1;\n  vector<C> ret(n);\n  for\
    \ (int i = 0; i < n; ++i) ret[i] = pow(C{0.456, 0.976}, i);\n  for (int it = 0;\
    \ it < 1000; ++it) {\n    for (int i = 0; i < n; ++i) {\n      C up = 0, dw =\
    \ 1;\n      for (int j = n; j >= 0; --j) {\n        up = up * ret[i] + p[j];\n\
    \        if (j != i && j != n) dw = dw * (ret[i] - ret[j]);\n      }\n      ret[i]\
    \ -= up / dw / p[n];\n    }\n  }\n  return ret;\n}\n"
  code: "using C = complex<double>;\n\nvector<C> PolyRoots(vector<C> p) {\n  int n\
    \ = p.size() - 1;\n  vector<C> ret(n);\n  for (int i = 0; i < n; ++i) ret[i] =\
    \ pow(C{0.456, 0.976}, i);\n  for (int it = 0; it < 1000; ++it) {\n    for (int\
    \ i = 0; i < n; ++i) {\n      C up = 0, dw = 1;\n      for (int j = n; j >= 0;\
    \ --j) {\n        up = up * ret[i] + p[j];\n        if (j != i && j != n) dw =\
    \ dw * (ret[i] - ret[j]);\n      }\n      ret[i] -= up / dw / p[n];\n    }\n \
    \ }\n  return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/PolyRoots.h
  requiredBy: []
  timestamp: '2025-11-15 18:26:28+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/PolyRoots.h
layout: document
redirect_from:
- /library/math/PolyRoots.h
- /library/math/PolyRoots.h.html
title: math/PolyRoots.h
---
