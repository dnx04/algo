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
  bundledCode: "#line 1 \"strings/Z.h\"\nvi Z(const string& S) {\n  vi z(sz(S));\n\
    \  int l = -1, r = -1;\n  for (int i = 1; i < sz(s); ++i) {\n    z[i] = i >= r\
    \ ? 0 : min(r - i, z[i - l]);\n    while (i + z[i] < sz(S) && S[i + z[i]] == S[z[i]])\
    \ z[i]++;\n    if (i + z[i] > r) l = i, r = i + z[i];\n  }\n  return z;\n}\n"
  code: "vi Z(const string& S) {\n  vi z(sz(S));\n  int l = -1, r = -1;\n  for (int\
    \ i = 1; i < sz(s); ++i) {\n    z[i] = i >= r ? 0 : min(r - i, z[i - l]);\n  \
    \  while (i + z[i] < sz(S) && S[i + z[i]] == S[z[i]]) z[i]++;\n    if (i + z[i]\
    \ > r) l = i, r = i + z[i];\n  }\n  return z;\n}"
  dependsOn: []
  isVerificationFile: false
  path: strings/Z.h
  requiredBy: []
  timestamp: '2025-11-15 18:26:28+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: strings/Z.h
layout: document
redirect_from:
- /library/strings/Z.h
- /library/strings/Z.h.html
title: strings/Z.h
---
