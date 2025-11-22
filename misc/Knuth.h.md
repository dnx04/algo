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
  bundledCode: "#line 1 \"misc/Knuth.h\"\n// N: s\u1ED1 ph\u1EA7n t\u1EED\n// cost(i,\
    \ j): chi ph\xED g\u1ED9p \u0111o\u1EA1n [i, j]\ntemplate <class F>\ni64 knuth(int\
    \ N, F cost) {\n  const i64 INF = 1e18;\n  vector<vector<i64>> dp(N + 2, vector<i64>(N\
    \ + 2, 0));\n  vector<vector<int>> opt(N + 2, vector<int>(N + 2, 0));\n  // Kh\u1EDF\
    i t\u1EA1o base case: \u0111o\u1EA1n \u0111\u1ED9 d\xE0i 1\n  for (int i = 1;\
    \ i <= N; ++i) dp[i][i] = cost(i, i), opt[i][i] = i;\n  // Duy\u1EC7t theo \u0111\
    \u1ED9 d\xE0i len\n  for (int len = 2; len <= N; ++len) {\n    for (int i = 1;\
    \ i <= N - len + 1; ++i) {\n      int j = i + len - 1;\n      dp[i][j] = INF;\n\
    \      i64 c = cost(i, j);\n      for (int k = opt[i][j - 1]; k <= min(j - 1,\
    \ opt[i + 1][j]); ++k) {\n        i64 curr = dp[i][k] + dp[k + 1][j] + c;\n  \
    \      if (curr < dp[i][j]) dp[i][j] = curr, opt[i][j] = k;\n      }\n    }\n\
    \  }\n  return dp[1][N];\n}\n"
  code: "// N: s\u1ED1 ph\u1EA7n t\u1EED\n// cost(i, j): chi ph\xED g\u1ED9p \u0111\
    o\u1EA1n [i, j]\ntemplate <class F>\ni64 knuth(int N, F cost) {\n  const i64 INF\
    \ = 1e18;\n  vector<vector<i64>> dp(N + 2, vector<i64>(N + 2, 0));\n  vector<vector<int>>\
    \ opt(N + 2, vector<int>(N + 2, 0));\n  // Kh\u1EDFi t\u1EA1o base case: \u0111\
    o\u1EA1n \u0111\u1ED9 d\xE0i 1\n  for (int i = 1; i <= N; ++i) dp[i][i] = cost(i,\
    \ i), opt[i][i] = i;\n  // Duy\u1EC7t theo \u0111\u1ED9 d\xE0i len\n  for (int\
    \ len = 2; len <= N; ++len) {\n    for (int i = 1; i <= N - len + 1; ++i) {\n\
    \      int j = i + len - 1;\n      dp[i][j] = INF;\n      i64 c = cost(i, j);\n\
    \      for (int k = opt[i][j - 1]; k <= min(j - 1, opt[i + 1][j]); ++k) {\n  \
    \      i64 curr = dp[i][k] + dp[k + 1][j] + c;\n        if (curr < dp[i][j]) dp[i][j]\
    \ = curr, opt[i][j] = k;\n      }\n    }\n  }\n  return dp[1][N];\n}"
  dependsOn: []
  isVerificationFile: false
  path: misc/Knuth.h
  requiredBy: []
  timestamp: '2025-11-22 08:45:41+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/Knuth.h
layout: document
redirect_from:
- /library/misc/Knuth.h
- /library/misc/Knuth.h.html
title: misc/Knuth.h
---
