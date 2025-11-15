---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: misc/CountSubseq.h
    title: misc/CountSubseq.h
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/Number_of_Subsequences.test.cpp
    title: tests/Number_of_Subsequences.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"misc/Compressor.h\"\ntemplate <typename T>\nvi compressor(vector<T>&\
    \ v) {\n  auto cv = v;\n  sort(all(cv));\n  cv.erase(unique(all(cv)), cv.end());\n\
    \  for (auto& e : v) e = lower_bound(all(cv), e) - cv.begin();\n  return v;\n\
    }\n"
  code: "template <typename T>\nvi compressor(vector<T>& v) {\n  auto cv = v;\n  sort(all(cv));\n\
    \  cv.erase(unique(all(cv)), cv.end());\n  for (auto& e : v) e = lower_bound(all(cv),\
    \ e) - cv.begin();\n  return v;\n}"
  dependsOn: []
  isVerificationFile: false
  path: misc/Compressor.h
  requiredBy:
  - misc/CountSubseq.h
  timestamp: '2025-11-15 18:26:28+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/Number_of_Subsequences.test.cpp
documentation_of: misc/Compressor.h
layout: document
redirect_from:
- /library/misc/Compressor.h
- /library/misc/Compressor.h.html
title: misc/Compressor.h
---
