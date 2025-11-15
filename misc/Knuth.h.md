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
  bundledCode: "#line 1 \"misc/Knuth.h\"\nauto C = [&](int i, int j) {\n  ...  //\
    \ Implement cost function C.\n};\n\nfor (int i = 0; i < N; i++) {\n  opt[i][i]\
    \ = i;\n  ...  // Initialize dp[i][i] according to the problem\n}\n\nfor (int\
    \ i = N - 2; i >= 0; i--) {\n  for (int j = i + 1; j < N; j++) {\n    int mn =\
    \ INT_MAX;\n    int cost = C(i, j);\n    for (int k = opt[i][j - 1]; k <= min(j\
    \ - 1, opt[i + 1][j]); k++) {\n      if (mn >= dp[i][k] + dp[k + 1][j] + cost)\
    \ {\n        opt[i][j] = k;\n        mn = dp[i][k] + dp[k + 1][j] + cost;\n  \
    \    }\n    }\n    dp[i][j] = mn;\n  }\n}\n\nreturn dp[0][N - 1];\n"
  code: "auto C = [&](int i, int j) {\n  ...  // Implement cost function C.\n};\n\n\
    for (int i = 0; i < N; i++) {\n  opt[i][i] = i;\n  ...  // Initialize dp[i][i]\
    \ according to the problem\n}\n\nfor (int i = N - 2; i >= 0; i--) {\n  for (int\
    \ j = i + 1; j < N; j++) {\n    int mn = INT_MAX;\n    int cost = C(i, j);\n \
    \   for (int k = opt[i][j - 1]; k <= min(j - 1, opt[i + 1][j]); k++) {\n     \
    \ if (mn >= dp[i][k] + dp[k + 1][j] + cost) {\n        opt[i][j] = k;\n      \
    \  mn = dp[i][k] + dp[k + 1][j] + cost;\n      }\n    }\n    dp[i][j] = mn;\n\
    \  }\n}\n\nreturn dp[0][N - 1];"
  dependsOn: []
  isVerificationFile: false
  path: misc/Knuth.h
  requiredBy: []
  timestamp: '2025-11-15 18:26:28+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/Knuth.h
layout: document
redirect_from:
- /library/misc/Knuth.h
- /library/misc/Knuth.h.html
title: misc/Knuth.h
---
