---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"misc/Frievalds.cpp\"\nint Freivalds(Mat a, Mat b, Mat c)\
    \ {\n  int n = a.n, iteration = 40;\n  Mat zero(n, 1), r(n, 1);\n  while (iteration--)\
    \ {\n    for (int i = 0; i < n; i++) r.a[i][0] = rnd() % 2;\n    Mat ans = (a\
    \ * (b * r)) - (c * r);\n    if (ans != zero) return 0;\n  }\n  return 1;\n}\n"
  code: "int Freivalds(Mat a, Mat b, Mat c) {\n  int n = a.n, iteration = 40;\n  Mat\
    \ zero(n, 1), r(n, 1);\n  while (iteration--) {\n    for (int i = 0; i < n; i++)\
    \ r.a[i][0] = rnd() % 2;\n    Mat ans = (a * (b * r)) - (c * r);\n    if (ans\
    \ != zero) return 0;\n  }\n  return 1;\n}"
  dependsOn: []
  isVerificationFile: false
  path: misc/Frievalds.cpp
  requiredBy: []
  timestamp: '2025-11-15 18:26:28+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/Frievalds.cpp
layout: document
redirect_from:
- /library/misc/Frievalds.cpp
- /library/misc/Frievalds.cpp.html
title: misc/Frievalds.cpp
---
