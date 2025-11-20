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
  bundledCode: "#line 1 \"misc/GrayCode.h\"\nvector<int> gray(int n) {\n  vector<int>\
    \ ret;\n  for (int i = 0; i < n; i++) ret.push_back(i ^ (i >> 1));\n  return ret;\n\
    }\n// gray cycle:\n// m = 2^k >= n, pick n / 2 first and n / 2 last elements\n"
  code: "vector<int> gray(int n) {\n  vector<int> ret;\n  for (int i = 0; i < n; i++)\
    \ ret.push_back(i ^ (i >> 1));\n  return ret;\n}\n// gray cycle:\n// m = 2^k >=\
    \ n, pick n / 2 first and n / 2 last elements"
  dependsOn: []
  isVerificationFile: false
  path: misc/GrayCode.h
  requiredBy: []
  timestamp: '2025-11-20 17:14:03+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/GrayCode.h
layout: document
redirect_from:
- /library/misc/GrayCode.h
- /library/misc/GrayCode.h.html
title: misc/GrayCode.h
---
