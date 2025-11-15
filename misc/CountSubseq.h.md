---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: misc/Compressor.h
    title: misc/Compressor.h
  _extendedRequiredBy: []
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
    }\n#line 2 \"misc/CountSubseq.h\"\n\ntemplate <typename T, typename Fp>\nFp CountSubseq(vector<T>\
    \ a) {\n  a = compressor<T>(a);\n  vi last(sz(a) + 1, -1);\n  vector<Fp> f(sz(a)\
    \ + 1);\n  f[0] = 1;\n  for (int i = 0; i < sz(a); ++i) {\n    f[i + 1] = f[i]\
    \ * 2;\n    if (last[a[i]] >= 0) f[i + 1] -= f[last[a[i]]];\n    last[a[i]] =\
    \ i;\n  }\n  return f.back() - 1;\n}\n"
  code: "#include \"Compressor.h\"\n\ntemplate <typename T, typename Fp>\nFp CountSubseq(vector<T>\
    \ a) {\n  a = compressor<T>(a);\n  vi last(sz(a) + 1, -1);\n  vector<Fp> f(sz(a)\
    \ + 1);\n  f[0] = 1;\n  for (int i = 0; i < sz(a); ++i) {\n    f[i + 1] = f[i]\
    \ * 2;\n    if (last[a[i]] >= 0) f[i + 1] -= f[last[a[i]]];\n    last[a[i]] =\
    \ i;\n  }\n  return f.back() - 1;\n}"
  dependsOn:
  - misc/Compressor.h
  isVerificationFile: false
  path: misc/CountSubseq.h
  requiredBy: []
  timestamp: '2025-11-15 18:26:28+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/Number_of_Subsequences.test.cpp
documentation_of: misc/CountSubseq.h
layout: document
redirect_from:
- /library/misc/CountSubseq.h
- /library/misc/CountSubseq.h.html
title: misc/CountSubseq.h
---
