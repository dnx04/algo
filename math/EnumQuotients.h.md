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
  bundledCode: "#line 1 \"math/EnumQuotients.h\"\nvector<ll> EnumerateQuotients(ll\
    \ N) {\n  vector<ll> res;\n  ll f = 1;\n  for (; f * f < N; f++) res.push_back(f);\n\
    \  int qp1 = res.size();\n  for (ll k = 1; k * f <= N; k++) {\n    res.push_back((k\
    \ & 1) ? (N / k) : (res[qp1 + k / 2 - 1] / 2));\n  }\n  reverse(res.begin() +\
    \ qp1, res.end());\n  return res;\n}\n"
  code: "vector<ll> EnumerateQuotients(ll N) {\n  vector<ll> res;\n  ll f = 1;\n \
    \ for (; f * f < N; f++) res.push_back(f);\n  int qp1 = res.size();\n  for (ll\
    \ k = 1; k * f <= N; k++) {\n    res.push_back((k & 1) ? (N / k) : (res[qp1 +\
    \ k / 2 - 1] / 2));\n  }\n  reverse(res.begin() + qp1, res.end());\n  return res;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: math/EnumQuotients.h
  requiredBy: []
  timestamp: '2025-11-15 18:26:28+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/EnumQuotients.h
layout: document
redirect_from:
- /library/math/EnumQuotients.h
- /library/math/EnumQuotients.h.html
title: math/EnumQuotients.h
---
