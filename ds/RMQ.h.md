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
  bundledCode: "#line 1 \"ds/RMQ.h\"\ntemplate <class T>\nstruct RMQ {\n  vector<vector<T>>\
    \ jmp;\n  RMQ(const vector<T>& V) : jmp(1, V) {\n    for (int pw = 1, k = 1; pw\
    \ * 2 <= sz(V); pw *= 2, ++k) {\n      jmp.emplace_back(sz(V) - pw * 2 + 1);\n\
    \      for (int j = 0; j < sz(jmp[k]); ++j) jmp[k][j] = min(jmp[k - 1][j], jmp[k\
    \ - 1][j + pw]);\n    }\n  }\n  T query(int a, int b) {\n    assert(a < b);  //\
    \ or return inf if a == b\n    int dep = 31 - __builtin_clz(b - a);\n    return\
    \ min(jmp[dep][a], jmp[dep][b - (1 << dep)]);\n  }\n};\n"
  code: "template <class T>\nstruct RMQ {\n  vector<vector<T>> jmp;\n  RMQ(const vector<T>&\
    \ V) : jmp(1, V) {\n    for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k)\
    \ {\n      jmp.emplace_back(sz(V) - pw * 2 + 1);\n      for (int j = 0; j < sz(jmp[k]);\
    \ ++j) jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);\n    }\n  }\n  T query(int\
    \ a, int b) {\n    assert(a < b);  // or return inf if a == b\n    int dep = 31\
    \ - __builtin_clz(b - a);\n    return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);\n\
    \  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/RMQ.h
  requiredBy: []
  timestamp: '2025-11-15 18:26:28+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/RMQ.h
layout: document
redirect_from:
- /library/ds/RMQ.h
- /library/ds/RMQ.h.html
title: ds/RMQ.h
---
