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
  bundledCode: "#line 1 \"ds/WaveletTree.h\"\nstruct Node {\n  Node *l = 0, *r = 0;\n\
    \  int lo, hi;\n  vi C;  // C[i] = # of first i elements going left\n  Node(const\
    \ vi& A, int lo, int hi) : lo(lo), hi(hi), C(1, 0) {\n    if (lo + 1 == hi) return;\n\
    \    int mid = (lo + hi) / 2;\n    vi L, R;\n    for (int a : A) {\n      C.push_back(C.back());\n\
    \      if (a < mid)\n        L.push_back(a), C.back()++;\n      else\n       \
    \ R.push_back(a);\n    }\n    l = new Node(L, lo, mid), r = new Node(R, mid, hi);\n\
    \  }\n  // k'th (0-indexed) element in the sorted range [L, R)\n  int quantile(int\
    \ k, int L, int R) {\n    if (lo + 1 == hi) return lo;\n    int c = C[R] - C[L];\n\
    \    if (k < c) return l->quantile(k, C[L], C[R]);\n    return r->quantile(k -\
    \ c, L - C[L], R - C[R]);\n  }\n  // number of elements in range [0, R) equal\
    \ to x\n  int rank(int x, int R) {\n    if (lo + 1 == hi) return R;\n    if (x\
    \ < l->hi) return l->rank(x, C[R]);\n    return r->rank(x, R - C[R]);\n  }\n \
    \ // number of elements x in range [L, R) st. a <= x < b\n  int rectangle(int\
    \ a, int b, int L, int R) {\n    if (a <= lo && hi <= b) return R - L;\n    if\
    \ (a >= hi || b <= lo) return 0;\n    return l->rectangle(a, b, C[L], C[R]) +\n\
    \           r->rectangle(a, b, L - C[L], R - C[R]);\n  }\n};\n"
  code: "struct Node {\n  Node *l = 0, *r = 0;\n  int lo, hi;\n  vi C;  // C[i] =\
    \ # of first i elements going left\n  Node(const vi& A, int lo, int hi) : lo(lo),\
    \ hi(hi), C(1, 0) {\n    if (lo + 1 == hi) return;\n    int mid = (lo + hi) /\
    \ 2;\n    vi L, R;\n    for (int a : A) {\n      C.push_back(C.back());\n    \
    \  if (a < mid)\n        L.push_back(a), C.back()++;\n      else\n        R.push_back(a);\n\
    \    }\n    l = new Node(L, lo, mid), r = new Node(R, mid, hi);\n  }\n  // k'th\
    \ (0-indexed) element in the sorted range [L, R)\n  int quantile(int k, int L,\
    \ int R) {\n    if (lo + 1 == hi) return lo;\n    int c = C[R] - C[L];\n    if\
    \ (k < c) return l->quantile(k, C[L], C[R]);\n    return r->quantile(k - c, L\
    \ - C[L], R - C[R]);\n  }\n  // number of elements in range [0, R) equal to x\n\
    \  int rank(int x, int R) {\n    if (lo + 1 == hi) return R;\n    if (x < l->hi)\
    \ return l->rank(x, C[R]);\n    return r->rank(x, R - C[R]);\n  }\n  // number\
    \ of elements x in range [L, R) st. a <= x < b\n  int rectangle(int a, int b,\
    \ int L, int R) {\n    if (a <= lo && hi <= b) return R - L;\n    if (a >= hi\
    \ || b <= lo) return 0;\n    return l->rectangle(a, b, C[L], C[R]) +\n       \
    \    r->rectangle(a, b, L - C[L], R - C[R]);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/WaveletTree.h
  requiredBy: []
  timestamp: '2025-11-15 18:26:28+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/WaveletTree.h
layout: document
redirect_from:
- /library/ds/WaveletTree.h
- /library/ds/WaveletTree.h.html
title: ds/WaveletTree.h
---
