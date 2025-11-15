---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/Deque_Operate_All_Composite.test.cpp
    title: tests/Deque_Operate_All_Composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/SWAG.h\"\ntemplate <typename T, typename F>\nstruct SlideWindowAggregationDeque\
    \ {\n  vector<T> a0, a1, r0, r1;\n  F f;\n  T I;\n\n  SlideWindowAggregationDeque(F\
    \ f, T i) : f(f), I(i) {}\n\n private:\n  T get0() const { return r0.empty() ?\
    \ I : r0.back(); }\n  T get1() const { return r1.empty() ? I : r1.back(); }\n\n\
    \  void push0(const T& x) {\n    a0.push_back(x);\n    r0.push_back(f(x, get0()));\n\
    \  }\n  void push1(const T& x) {\n    a1.push_back(x);\n    r1.push_back(f(get1(),\
    \ x));\n  }\n  void rebalance() {\n    int n = a0.size() + a1.size();\n    int\
    \ s0 = n / 2 + (a0.empty() ? n % 2 : 0);\n    vector<T> a{a0};\n    reverse(begin(a),\
    \ end(a));\n    copy(begin(a1), end(a1), back_inserter(a));\n    a0.clear(), r0.clear();\n\
    \    a1.clear(), r1.clear();\n    for (int i = s0 - 1; i >= 0; i--) push0(a[i]);\n\
    \    for (int i = s0; i < n; i++) push1(a[i]);\n  }\n\n public:\n  void push_front(const\
    \ T& t) { push0(t); }\n  void push_back(const T& t) { push1(t); }\n  T front()\
    \ const { return a0.empty() ? a1.front() : a0.back(); }\n  T back() const { return\
    \ a1.empty() ? a0.front() : a1.back(); }\n  void pop_front() {\n    if (a0.empty())\
    \ rebalance();\n    assert(!a0.empty());\n    a0.pop_back(), r0.pop_back();\n\
    \  }\n  void pop_back() {\n    if (a1.empty()) rebalance();\n    assert(!a1.empty());\n\
    \    a1.pop_back(), r1.pop_back();\n  }\n  T query() { return f(get0(), get1());\
    \ }\n};\n"
  code: "template <typename T, typename F>\nstruct SlideWindowAggregationDeque {\n\
    \  vector<T> a0, a1, r0, r1;\n  F f;\n  T I;\n\n  SlideWindowAggregationDeque(F\
    \ f, T i) : f(f), I(i) {}\n\n private:\n  T get0() const { return r0.empty() ?\
    \ I : r0.back(); }\n  T get1() const { return r1.empty() ? I : r1.back(); }\n\n\
    \  void push0(const T& x) {\n    a0.push_back(x);\n    r0.push_back(f(x, get0()));\n\
    \  }\n  void push1(const T& x) {\n    a1.push_back(x);\n    r1.push_back(f(get1(),\
    \ x));\n  }\n  void rebalance() {\n    int n = a0.size() + a1.size();\n    int\
    \ s0 = n / 2 + (a0.empty() ? n % 2 : 0);\n    vector<T> a{a0};\n    reverse(begin(a),\
    \ end(a));\n    copy(begin(a1), end(a1), back_inserter(a));\n    a0.clear(), r0.clear();\n\
    \    a1.clear(), r1.clear();\n    for (int i = s0 - 1; i >= 0; i--) push0(a[i]);\n\
    \    for (int i = s0; i < n; i++) push1(a[i]);\n  }\n\n public:\n  void push_front(const\
    \ T& t) { push0(t); }\n  void push_back(const T& t) { push1(t); }\n  T front()\
    \ const { return a0.empty() ? a1.front() : a0.back(); }\n  T back() const { return\
    \ a1.empty() ? a0.front() : a1.back(); }\n  void pop_front() {\n    if (a0.empty())\
    \ rebalance();\n    assert(!a0.empty());\n    a0.pop_back(), r0.pop_back();\n\
    \  }\n  void pop_back() {\n    if (a1.empty()) rebalance();\n    assert(!a1.empty());\n\
    \    a1.pop_back(), r1.pop_back();\n  }\n  T query() { return f(get0(), get1());\
    \ }\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/SWAG.h
  requiredBy: []
  timestamp: '2025-11-15 18:26:28+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/Deque_Operate_All_Composite.test.cpp
documentation_of: ds/SWAG.h
layout: document
redirect_from:
- /library/ds/SWAG.h
- /library/ds/SWAG.h.html
title: ds/SWAG.h
---
