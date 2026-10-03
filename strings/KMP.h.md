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
  bundledCode: "#line 1 \"strings/KMP.h\"\nvi pi(const string& s) {\n  vi p(len(s));\n\
    \  for (int i = 1; i < len(s); ++i) {\n    int g = p[i - 1];\n    while (g &&\
    \ s[i] != s[g]) g = p[g - 1];\n    p[i] = g + (s[i] == s[g]);\n  }\n  return p;\n\
    }\n"
  code: "vi pi(const string& s) {\n  vi p(len(s));\n  for (int i = 1; i < len(s);\
    \ ++i) {\n    int g = p[i - 1];\n    while (g && s[i] != s[g]) g = p[g - 1];\n\
    \    p[i] = g + (s[i] == s[g]);\n  }\n  return p;\n}"
  dependsOn: []
  isVerificationFile: false
  path: strings/KMP.h
  requiredBy: []
  timestamp: '2026-10-03 15:27:40+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: strings/KMP.h
layout: document
redirect_from:
- /library/strings/KMP.h
- /library/strings/KMP.h.html
title: strings/KMP.h
---
