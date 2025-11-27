---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: tests/Run_Enumerate.test.cpp
    title: tests/Run_Enumerate.test.cpp
  - icon: ':x:'
    path: tests/Static_RMQ.test.cpp
    title: tests/Static_RMQ.test.cpp
  _isVerificationFailed: true
  _pathExtension: h
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/RMQ.h\"\ntemplate <class T, class F>\nstruct RMQ {\n\
    \  vector<vector<T>> jmp;\n  const F f;\n  RMQ(const vector<T>& V, F f) : jmp(1,\
    \ V), f(f) {\n    for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {\n \
    \     jmp.eb(sz(V) - pw * 2 + 1);\n      for (int j = 0; j < sz(jmp[k]); ++j)\
    \ jmp[k][j] = f(jmp[k - 1][j], jmp[k - 1][j + pw]);\n    }\n  }\n  // [a, b)\n\
    \  T query(int a, int b) {\n    assert(a < b);\n    int dep = 31 - __builtin_clz(b\
    \ - a);\n    return f(jmp[dep][a], jmp[dep][b - (1 << dep)]);\n  }\n};\n"
  code: "template <class T, class F>\nstruct RMQ {\n  vector<vector<T>> jmp;\n  const\
    \ F f;\n  RMQ(const vector<T>& V, F f) : jmp(1, V), f(f) {\n    for (int pw =\
    \ 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {\n      jmp.eb(sz(V) - pw * 2 + 1);\n\
    \      for (int j = 0; j < sz(jmp[k]); ++j) jmp[k][j] = f(jmp[k - 1][j], jmp[k\
    \ - 1][j + pw]);\n    }\n  }\n  // [a, b)\n  T query(int a, int b) {\n    assert(a\
    \ < b);\n    int dep = 31 - __builtin_clz(b - a);\n    return f(jmp[dep][a], jmp[dep][b\
    \ - (1 << dep)]);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/RMQ.h
  requiredBy: []
  timestamp: '2025-11-18 22:42:15+07:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - tests/Static_RMQ.test.cpp
  - tests/Run_Enumerate.test.cpp
documentation_of: ds/RMQ.h
layout: document
redirect_from:
- /library/ds/RMQ.h
- /library/ds/RMQ.h.html
title: ds/RMQ.h
---
