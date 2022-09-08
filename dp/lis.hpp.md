---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"dp/lis.hpp\"\n// return a vector contains indices of the\
    \ LIS\ntemplate <typename T>\nvector<int> lis(const vector<T>& a) {\n  int n =\
    \ (int)a.size();\n  vector<int> b(n + 1, 0), f(n, 0);\n  int ans = 0;\n  for (int\
    \ i = 0; i < n; i++) {\n    f[i] = lower_bound(begin(b) + 1, begin(b) + ans +\
    \ 1, a[i]) - begin(b);\n    ans = max(ans, f[i]);\n    b[f[i]] = a[i];\n  }\n\
    \  int req = ans;\n  vector<int> res;\n  for (int i = n - 1; i >= 0; i--) {\n\
    \    if (f[i] == req) {\n      res.push_back(i);\n      --req;\n    }\n  }\n \
    \ reverse(begin(res), end(res));\n  return res;\n}\n"
  code: "// return a vector contains indices of the LIS\ntemplate <typename T>\nvector<int>\
    \ lis(const vector<T>& a) {\n  int n = (int)a.size();\n  vector<int> b(n + 1,\
    \ 0), f(n, 0);\n  int ans = 0;\n  for (int i = 0; i < n; i++) {\n    f[i] = lower_bound(begin(b)\
    \ + 1, begin(b) + ans + 1, a[i]) - begin(b);\n    ans = max(ans, f[i]);\n    b[f[i]]\
    \ = a[i];\n  }\n  int req = ans;\n  vector<int> res;\n  for (int i = n - 1; i\
    \ >= 0; i--) {\n    if (f[i] == req) {\n      res.push_back(i);\n      --req;\n\
    \    }\n  }\n  reverse(begin(res), end(res));\n  return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: dp/lis.hpp
  requiredBy: []
  timestamp: '2022-09-08 21:32:23+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: dp/lis.hpp
layout: document
redirect_from:
- /library/dp/lis.hpp
- /library/dp/lis.hpp.html
title: dp/lis.hpp
---