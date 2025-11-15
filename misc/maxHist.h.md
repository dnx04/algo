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
  bundledCode: "#line 1 \"misc/maxHist.h\"\nint maxHist(vector<int>& h) {\n  h.push_back(0);\n\
    \  stack<int> st;\n  int res = 0;\n  for (int i = 0; i < (int)h.size(); i++) {\n\
    \    while (!st.empty() && h[st.top()] >= h[i]) {\n      int height = h[st.top()];\n\
    \      st.pop();\n      int width = st.empty() ? i : i - st.top() - 1;\n     \
    \ res = max(res, height * width);\n    }\n    st.push(i);\n  }\n  return res;\n\
    }\n"
  code: "int maxHist(vector<int>& h) {\n  h.push_back(0);\n  stack<int> st;\n  int\
    \ res = 0;\n  for (int i = 0; i < (int)h.size(); i++) {\n    while (!st.empty()\
    \ && h[st.top()] >= h[i]) {\n      int height = h[st.top()];\n      st.pop();\n\
    \      int width = st.empty() ? i : i - st.top() - 1;\n      res = max(res, height\
    \ * width);\n    }\n    st.push(i);\n  }\n  return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/maxHist.h
  requiredBy: []
  timestamp: '2025-11-15 18:26:28+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/maxHist.h
layout: document
redirect_from:
- /library/misc/maxHist.h
- /library/misc/maxHist.h.html
title: misc/maxHist.h
---
