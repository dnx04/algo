---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: tests/Z_Algorithm.test.cpp
    title: tests/Z_Algorithm.test.cpp
  _isVerificationFailed: true
  _pathExtension: h
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"strings/Z.h\"\nvi Z(const string& S) {\n  vi z(len(S));\n\
    \  int l = -1, r = -1;\n  for (int i = 1; i < len(S); ++i) {\n    z[i] = i >=\
    \ r ? 0 : min(r - i, z[i - l]);\n    while (i + z[i] < len(S) && S[i + z[i]] ==\
    \ S[z[i]]) z[i]++;\n    if (i + z[i] > r) l = i, r = i + z[i];\n  }\n  return\
    \ z;\n}\n"
  code: "vi Z(const string& S) {\n  vi z(len(S));\n  int l = -1, r = -1;\n  for (int\
    \ i = 1; i < len(S); ++i) {\n    z[i] = i >= r ? 0 : min(r - i, z[i - l]);\n \
    \   while (i + z[i] < len(S) && S[i + z[i]] == S[z[i]]) z[i]++;\n    if (i + z[i]\
    \ > r) l = i, r = i + z[i];\n  }\n  return z;\n}"
  dependsOn: []
  isVerificationFile: false
  path: strings/Z.h
  requiredBy: []
  timestamp: '2026-10-03 15:27:40+00:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - tests/Z_Algorithm.test.cpp
documentation_of: strings/Z.h
layout: document
redirect_from:
- /library/strings/Z.h
- /library/strings/Z.h.html
title: strings/Z.h
---
