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
  bundledCode: "#line 1 \"misc/Knight.h\"\ni64 knight(i64 x, i64 y) {\n  i64 cnt =\
    \ max({(x + 1) / 2, (y + 1) / 2, (x + y + 2) / 3});\n  while((cnt % 2) != (x +\
    \ y) % 2) cnt++;\n  if(x == 1 && !y) return 3;\n  if(y == 1 && !x) return 3;\n\
    \  if(x == y && x == 2) return 4;\n  return cnt;\n}\n"
  code: "i64 knight(i64 x, i64 y) {\n  i64 cnt = max({(x + 1) / 2, (y + 1) / 2, (x\
    \ + y + 2) / 3});\n  while((cnt % 2) != (x + y) % 2) cnt++;\n  if(x == 1 && !y)\
    \ return 3;\n  if(y == 1 && !x) return 3;\n  if(x == y && x == 2) return 4;\n\
    \  return cnt;\n}"
  dependsOn: []
  isVerificationFile: false
  path: misc/Knight.h
  requiredBy: []
  timestamp: '2025-12-09 07:33:19+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/Knight.h
layout: document
redirect_from:
- /library/misc/Knight.h
- /library/misc/Knight.h.html
title: misc/Knight.h
---
