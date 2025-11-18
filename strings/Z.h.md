---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/Z_Algorithm.test.cpp
    title: tests/Z_Algorithm.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"strings/Z.h\"\nvi Z(const string& S) {\n  vi z(sz(S));\n\
    \  int l = -1, r = -1;\n  for (int i = 1; i < sz(S); ++i) {\n    z[i] = i >= r\
    \ ? 0 : min(r - i, z[i - l]);\n    while (i + z[i] < sz(S) && S[i + z[i]] == S[z[i]])\
    \ z[i]++;\n    if (i + z[i] > r) l = i, r = i + z[i];\n  }\n  return z;\n}\n"
  code: "vi Z(const string& S) {\n  vi z(sz(S));\n  int l = -1, r = -1;\n  for (int\
    \ i = 1; i < sz(S); ++i) {\n    z[i] = i >= r ? 0 : min(r - i, z[i - l]);\n  \
    \  while (i + z[i] < sz(S) && S[i + z[i]] == S[z[i]]) z[i]++;\n    if (i + z[i]\
    \ > r) l = i, r = i + z[i];\n  }\n  return z;\n}"
  dependsOn: []
  isVerificationFile: false
  path: strings/Z.h
  requiredBy: []
  timestamp: '2025-11-18 22:42:15+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/Z_Algorithm.test.cpp
documentation_of: strings/Z.h
layout: document
redirect_from:
- /library/strings/Z.h
- /library/strings/Z.h.html
title: strings/Z.h
---
