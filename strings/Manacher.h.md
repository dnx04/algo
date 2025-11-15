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
  bundledCode: "#line 1 \"strings/Manacher.h\"\narray<vi, 2> manacher(const string&\
    \ s) {\n  int n = sz(s);\n  array<vi, 2> p = {vi(n + 1), vi(n)};\n  for (int i\
    \ = 0; i < n; ++i)z, 0, 2) for (int i = 0, l = 0, r = 0; i < n; i++) {\n     \
    \ int t = r - i + !z;\n      if (i < r) p[z][i] = min(t, p[z][l + t]);\n     \
    \ int L = i - p[z][i], R = i + p[z][i] - !z;\n      while (L >= 1 && R + 1 < n\
    \ && s[L - 1] == s[R + 1]) p[z][i]++, L--, R++;\n      if (R > r) l = L, r = R;\n\
    \    }\n  return p;\n}\n"
  code: "array<vi, 2> manacher(const string& s) {\n  int n = sz(s);\n  array<vi, 2>\
    \ p = {vi(n + 1), vi(n)};\n  for (int i = 0; i < n; ++i)z, 0, 2) for (int i =\
    \ 0, l = 0, r = 0; i < n; i++) {\n      int t = r - i + !z;\n      if (i < r)\
    \ p[z][i] = min(t, p[z][l + t]);\n      int L = i - p[z][i], R = i + p[z][i] -\
    \ !z;\n      while (L >= 1 && R + 1 < n && s[L - 1] == s[R + 1]) p[z][i]++, L--,\
    \ R++;\n      if (R > r) l = L, r = R;\n    }\n  return p;\n}"
  dependsOn: []
  isVerificationFile: false
  path: strings/Manacher.h
  requiredBy: []
  timestamp: '2025-11-15 18:26:28+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: strings/Manacher.h
layout: document
redirect_from:
- /library/strings/Manacher.h
- /library/strings/Manacher.h.html
title: strings/Manacher.h
---
