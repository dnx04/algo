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
  bundledCode: "#line 1 \"misc/DnCDP.h\"\n// N: s\u1ED1 ph\u1EA7n t\u1EED, K: s\u1ED1\
    \ \u0111o\u1EA1n chia\n// cost(l, r): tr\u1EA3 v\u1EC1 chi ph\xED \u0111o\u1EA1\
    n [l, r]\ntemplate <class F>\ni64 solve_dnc(int N, int K, F cost) {\n  const i64\
    \ INF = 1e18;\n  vector<i64> dp_before(N + 1, INF), dp_cur(N + 1);\n  // Kh\u1EDF\
    i t\u1EA1o t\u1EA7ng k=1\n  for (int i = 1; i <= N; ++i) dp_before[i] = cost(1,\
    \ i);\n  // H\xE0m \u0111\u1EC7 quy x\u1EED l\xFD t\u1EEBng t\u1EA7ng\n  auto\
    \ compute = [&](auto&& self, int L, int R, int optL, int optR) -> void {\n   \
    \ if (L > R) return;\n    int mid = (L + R) / 2;\n    int best_k = -1;\n    dp_cur[mid]\
    \ = INF;\n    // Gi\u1EDBi h\u1EA1n k: t\u1EEB optL \u0111\u1EBFn min(mid - 1,\
    \ optR)\n    for (int k = optL; k <= min(mid - 1, optR); ++k) {\n      i64 val\
    \ = dp_before[k] + cost(k + 1, mid);\n      if (val < dp_cur[mid]) {\n       \
    \ dp_cur[mid] = val;\n        best_k = k;\n      }\n    }\n    self(self, L, mid\
    \ - 1, optL, best_k);\n    self(self, mid + 1, R, best_k, optR);\n  };\n  for\
    \ (int k = 2; k <= K; ++k) compute(compute, 1, N, 1, N), dp_before = dp_cur;\n\
    \  return dp_before[N];\n}\n"
  code: "// N: s\u1ED1 ph\u1EA7n t\u1EED, K: s\u1ED1 \u0111o\u1EA1n chia\n// cost(l,\
    \ r): tr\u1EA3 v\u1EC1 chi ph\xED \u0111o\u1EA1n [l, r]\ntemplate <class F>\n\
    i64 solve_dnc(int N, int K, F cost) {\n  const i64 INF = 1e18;\n  vector<i64>\
    \ dp_before(N + 1, INF), dp_cur(N + 1);\n  // Kh\u1EDFi t\u1EA1o t\u1EA7ng k=1\n\
    \  for (int i = 1; i <= N; ++i) dp_before[i] = cost(1, i);\n  // H\xE0m \u0111\
    \u1EC7 quy x\u1EED l\xFD t\u1EEBng t\u1EA7ng\n  auto compute = [&](auto&& self,\
    \ int L, int R, int optL, int optR) -> void {\n    if (L > R) return;\n    int\
    \ mid = (L + R) / 2;\n    int best_k = -1;\n    dp_cur[mid] = INF;\n    // Gi\u1EDB\
    i h\u1EA1n k: t\u1EEB optL \u0111\u1EBFn min(mid - 1, optR)\n    for (int k =\
    \ optL; k <= min(mid - 1, optR); ++k) {\n      i64 val = dp_before[k] + cost(k\
    \ + 1, mid);\n      if (val < dp_cur[mid]) {\n        dp_cur[mid] = val;\n   \
    \     best_k = k;\n      }\n    }\n    self(self, L, mid - 1, optL, best_k);\n\
    \    self(self, mid + 1, R, best_k, optR);\n  };\n  for (int k = 2; k <= K; ++k)\
    \ compute(compute, 1, N, 1, N), dp_before = dp_cur;\n  return dp_before[N];\n}"
  dependsOn: []
  isVerificationFile: false
  path: misc/DnCDP.h
  requiredBy: []
  timestamp: '2025-11-26 18:05:06+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/DnCDP.h
layout: document
redirect_from:
- /library/misc/DnCDP.h
- /library/misc/DnCDP.h.html
title: misc/DnCDP.h
---
