---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/Enumerate_Quotients.test.cpp
    title: tests/Enumerate_Quotients.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/EnumQuotients.h\"\nvector<i64> EnumerateQuotients(i64\
    \ N) {\n  vector<i64> res;\n  i64 f = 1;\n  for (; f * f < N; f++) res.push_back(f);\n\
    \  int qp1 = res.size();\n  for (i64 k = 1; k * f <= N; k++) {\n    res.push_back((k\
    \ & 1) ? (N / k) : (res[qp1 + k / 2 - 1] / 2));\n  }\n  reverse(res.begin() +\
    \ qp1, res.end());\n  return res;\n}\n"
  code: "vector<i64> EnumerateQuotients(i64 N) {\n  vector<i64> res;\n  i64 f = 1;\n\
    \  for (; f * f < N; f++) res.push_back(f);\n  int qp1 = res.size();\n  for (i64\
    \ k = 1; k * f <= N; k++) {\n    res.push_back((k & 1) ? (N / k) : (res[qp1 +\
    \ k / 2 - 1] / 2));\n  }\n  reverse(res.begin() + qp1, res.end());\n  return res;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: math/EnumQuotients.h
  requiredBy: []
  timestamp: '2025-11-18 17:31:30+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/Enumerate_Quotients.test.cpp
documentation_of: math/EnumQuotients.h
layout: document
redirect_from:
- /library/math/EnumQuotients.h
- /library/math/EnumQuotients.h.html
title: math/EnumQuotients.h
---
