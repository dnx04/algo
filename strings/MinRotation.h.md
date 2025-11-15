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
  bundledCode: "#line 1 \"strings/MinRotation.h\"\nint minRotation(string s) {\n \
    \ int a = 0, N = sz(s);\n  s += s;\n  for(int b = 0; b < N; ++b) for(int k = 0;\
    \ k < N; ++k) {\n    if (a + k == b || s[a + k] < s[b + k]) {\n      b += max(0,\
    \ k - 1);\n      break;\n    }\n    if (s[a + k] > s[b + k]) {\n      a = b;\n\
    \      break;\n    }\n  }\n  return a;\n}\n"
  code: "int minRotation(string s) {\n  int a = 0, N = sz(s);\n  s += s;\n  for(int\
    \ b = 0; b < N; ++b) for(int k = 0; k < N; ++k) {\n    if (a + k == b || s[a +\
    \ k] < s[b + k]) {\n      b += max(0, k - 1);\n      break;\n    }\n    if (s[a\
    \ + k] > s[b + k]) {\n      a = b;\n      break;\n    }\n  }\n  return a;\n}"
  dependsOn: []
  isVerificationFile: false
  path: strings/MinRotation.h
  requiredBy: []
  timestamp: '2025-11-15 18:26:28+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: strings/MinRotation.h
layout: document
redirect_from:
- /library/strings/MinRotation.h
- /library/strings/MinRotation.h.html
title: strings/MinRotation.h
---
