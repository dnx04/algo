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
  bundledCode: "#line 1 \"strings/PalindromeTree.h\"\nstruct Node {\n  map<char, int>\
    \ leg;\n  int link, len, cnt = 0;\n};\n\nvector<Node> PalTree(string str) {\n\
    \  vector<Node> T(str.size() + 2);\n  T[1].link = T[1].len = 0;\n  T[0].link =\
    \ T[0].len = -1;\n  int last = 0, nodes = 2;\n\n  for (int i = 0; i < (int)str.size();\
    \ ++i) {\n    char now = str[i];\n    int node = last;\n    while (now != str[i\
    \ - T[node].len - 1]) node = T[node].link;\n    if (T[node].leg.count(now)) {\n\
    \      node = T[node].leg[now];\n      T[node].cnt += 1;\n      last = node;\n\
    \      continue;\n    }\n    int cur = nodes++;\n    T[cur].len = T[node].len\
    \ + 2;\n    T[node].leg[now] = cur;\n    int link = T[node].link;\n    while (link\
    \ != -1) {\n      if (now == str[i - T[link].len - 1] && T[link].leg.count(now))\
    \ {\n        link = T[link].leg[now];\n        break;\n      }\n      link = T[link].link;\n\
    \    }\n    if (link <= 0) link = 1;\n    T[cur].link = link;\n    T[cur].cnt\
    \ = 1;\n    last = cur;\n  }\n  for (int node = nodes - 1; node > 0; --node)\n\
    \    T[T[node].link].cnt += T[node].cnt;\n\n  T.resize(nodes);\n  return T;\n\
    }\n"
  code: "struct Node {\n  map<char, int> leg;\n  int link, len, cnt = 0;\n};\n\nvector<Node>\
    \ PalTree(string str) {\n  vector<Node> T(str.size() + 2);\n  T[1].link = T[1].len\
    \ = 0;\n  T[0].link = T[0].len = -1;\n  int last = 0, nodes = 2;\n\n  for (int\
    \ i = 0; i < (int)str.size(); ++i) {\n    char now = str[i];\n    int node = last;\n\
    \    while (now != str[i - T[node].len - 1]) node = T[node].link;\n    if (T[node].leg.count(now))\
    \ {\n      node = T[node].leg[now];\n      T[node].cnt += 1;\n      last = node;\n\
    \      continue;\n    }\n    int cur = nodes++;\n    T[cur].len = T[node].len\
    \ + 2;\n    T[node].leg[now] = cur;\n    int link = T[node].link;\n    while (link\
    \ != -1) {\n      if (now == str[i - T[link].len - 1] && T[link].leg.count(now))\
    \ {\n        link = T[link].leg[now];\n        break;\n      }\n      link = T[link].link;\n\
    \    }\n    if (link <= 0) link = 1;\n    T[cur].link = link;\n    T[cur].cnt\
    \ = 1;\n    last = cur;\n  }\n  for (int node = nodes - 1; node > 0; --node)\n\
    \    T[T[node].link].cnt += T[node].cnt;\n\n  T.resize(nodes);\n  return T;\n}"
  dependsOn: []
  isVerificationFile: false
  path: strings/PalindromeTree.h
  requiredBy: []
  timestamp: '2025-11-15 18:26:28+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: strings/PalindromeTree.h
layout: document
redirect_from:
- /library/strings/PalindromeTree.h
- /library/strings/PalindromeTree.h.html
title: strings/PalindromeTree.h
---
