---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: tests/Find_Linear_Recurrence.test.cpp
    title: tests/Find_Linear_Recurrence.test.cpp
  _isVerificationFailed: true
  _pathExtension: h
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/LinearRec.h\"\ntemplate <class Fp>\nvector<Fp> LinearRec(const\
    \ vector<Fp>& as) {\n  const int n = as.size();\n  int d = 0, m = 0;\n  vector<Fp>\
    \ cs(n + 1, 0), bs(n + 1, 0);\n  cs[0] = bs[0] = 1;\n  Fp invBef = 1;\n  for (int\
    \ i = 0; i < n; ++i) {\n    ++m;\n    Fp dif = as[i];\n    for (int j = 1; j <=\
    \ d; ++j) dif += cs[j] * as[i - j];\n    if (dif.x != 0) {\n      auto csDup =\
    \ cs;\n      const Fp r = dif * invBef;\n      for (int j = m; j < n; ++j) cs[j]\
    \ -= r * bs[j - m];\n      if (2 * d <= i) {\n        d = i + 1 - d, m = 0, bs\
    \ = csDup, invBef = dif.inv();\n      }\n    }\n  }\n  cs.resize(d + 1);\n  for\
    \ (auto& c : cs) c = -c;\n  return cs;\n}\n"
  code: "template <class Fp>\nvector<Fp> LinearRec(const vector<Fp>& as) {\n  const\
    \ int n = as.size();\n  int d = 0, m = 0;\n  vector<Fp> cs(n + 1, 0), bs(n + 1,\
    \ 0);\n  cs[0] = bs[0] = 1;\n  Fp invBef = 1;\n  for (int i = 0; i < n; ++i) {\n\
    \    ++m;\n    Fp dif = as[i];\n    for (int j = 1; j <= d; ++j) dif += cs[j]\
    \ * as[i - j];\n    if (dif.x != 0) {\n      auto csDup = cs;\n      const Fp\
    \ r = dif * invBef;\n      for (int j = m; j < n; ++j) cs[j] -= r * bs[j - m];\n\
    \      if (2 * d <= i) {\n        d = i + 1 - d, m = 0, bs = csDup, invBef = dif.inv();\n\
    \      }\n    }\n  }\n  cs.resize(d + 1);\n  for (auto& c : cs) c = -c;\n  return\
    \ cs;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/LinearRec.h
  requiredBy: []
  timestamp: '2025-11-18 18:21:29+07:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - tests/Find_Linear_Recurrence.test.cpp
documentation_of: math/LinearRec.h
layout: document
redirect_from:
- /library/math/LinearRec.h
- /library/math/LinearRec.h.html
title: math/LinearRec.h
---
