---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/Longest_Common_Substring.test.cpp
    title: tests/Longest_Common_Substring.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Number_of_Substrings.test.cpp
    title: tests/Number_of_Substrings.test.cpp
  - icon: ':x:'
    path: tests/Run_Enumerate.test.cpp
    title: tests/Run_Enumerate.test.cpp
  - icon: ':x:'
    path: tests/Suffix_Array.test.cpp
    title: tests/Suffix_Array.test.cpp
  _isVerificationFailed: true
  _pathExtension: h
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"strings/SuffixArray.h\"\nstruct SuffixArray {\n  vector<int>\
    \ sa, lcp, rank;\n  SuffixArray(string s, int lim = 256) {\n    int n = s.size()\
    \ + 1, k = 0, a, b;\n    s.push_back(0);\n    vector<int> y(n), cnt(max(n, lim));\n\
    \    sa.resize(n), lcp.resize(n), rank.resize(n);\n    for (int i = 0; i < n;\
    \ ++i) rank[i] = s[i];\n    iota(sa.begin(), sa.end(), 0);\n    \n    for (int\
    \ j = 0, p = 0; p < n; j = max(1, j * 2), lim = p) {\n      p = j;\n      iota(all(y),\
    \ n - j);\n      for (int i = 0; i < n; ++i)\n        if (sa[i] >= j) y[p++] =\
    \ sa[i] - j;\n      fill(all(cnt), 0);\n      for (int i = 0; i < n; ++i) cnt[rank[i]]++;\n\
    \      for (int i = 1; i < lim; ++i) cnt[i] += cnt[i - 1];\n      for (int i =\
    \ n; i--;) sa[--cnt[rank[y[i]]]] = y[i];\n      swap(rank, y), p = 1, rank[sa[0]]\
    \ = 0;\n      for (int i = 1; i < n; ++i) {\n        a = sa[i - 1], b = sa[i];\n\
    \        int val_a = (a + j < n) ? y[a + j] : -1;\n        int val_b = (b + j\
    \ < n) ? y[b + j] : -1;\n        rank[b] = (y[a] == y[b] && val_a == val_b) ?\
    \ p - 1 : p++;\n      }\n    }\n    \n    for (int i = 0; i < n; ++i) rank[sa[i]]\
    \ = i;\n    for (int i = 0, j; i < n - 1; lcp[rank[i++]] = k)\n      for (k &&\
    \ k--, j = sa[rank[i] - 1]; s[i + k] == s[j + k]; k++);\n  }\n};\n"
  code: "struct SuffixArray {\n  vector<int> sa, lcp, rank;\n  SuffixArray(string\
    \ s, int lim = 256) {\n    int n = s.size() + 1, k = 0, a, b;\n    s.push_back(0);\n\
    \    vector<int> y(n), cnt(max(n, lim));\n    sa.resize(n), lcp.resize(n), rank.resize(n);\n\
    \    for (int i = 0; i < n; ++i) rank[i] = s[i];\n    iota(sa.begin(), sa.end(),\
    \ 0);\n    \n    for (int j = 0, p = 0; p < n; j = max(1, j * 2), lim = p) {\n\
    \      p = j;\n      iota(all(y), n - j);\n      for (int i = 0; i < n; ++i)\n\
    \        if (sa[i] >= j) y[p++] = sa[i] - j;\n      fill(all(cnt), 0);\n     \
    \ for (int i = 0; i < n; ++i) cnt[rank[i]]++;\n      for (int i = 1; i < lim;\
    \ ++i) cnt[i] += cnt[i - 1];\n      for (int i = n; i--;) sa[--cnt[rank[y[i]]]]\
    \ = y[i];\n      swap(rank, y), p = 1, rank[sa[0]] = 0;\n      for (int i = 1;\
    \ i < n; ++i) {\n        a = sa[i - 1], b = sa[i];\n        int val_a = (a + j\
    \ < n) ? y[a + j] : -1;\n        int val_b = (b + j < n) ? y[b + j] : -1;\n  \
    \      rank[b] = (y[a] == y[b] && val_a == val_b) ? p - 1 : p++;\n      }\n  \
    \  }\n    \n    for (int i = 0; i < n; ++i) rank[sa[i]] = i;\n    for (int i =\
    \ 0, j; i < n - 1; lcp[rank[i++]] = k)\n      for (k && k--, j = sa[rank[i] -\
    \ 1]; s[i + k] == s[j + k]; k++);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: strings/SuffixArray.h
  requiredBy: []
  timestamp: '2025-11-22 00:26:56+07:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - tests/Longest_Common_Substring.test.cpp
  - tests/Run_Enumerate.test.cpp
  - tests/Suffix_Array.test.cpp
  - tests/Number_of_Substrings.test.cpp
documentation_of: strings/SuffixArray.h
layout: document
redirect_from:
- /library/strings/SuffixArray.h
- /library/strings/SuffixArray.h.html
title: strings/SuffixArray.h
---
