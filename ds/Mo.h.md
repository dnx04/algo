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
  bundledCode: "#line 1 \"ds/Mo.h\"\nconst int sz = 850; // should be sqrt(3/2 * N)\n\
    struct Query {\n  int l, r, idx;\n  bool operator<(const Query& o) {\n    if (l\
    \ / sz != o.l / sz) return l / sz < o.l / sz;\n    else {\n      if ((l / sz)\
    \ & 1) return r / sz < o.r / sz;\n      else return r / sz > o.r / sz;\n    }\n\
    \  };\n};\n// handle [l, r] inclusive:\n// int pl = 0, pr = -1;\n// for (auto\
    \ [l, r, idx] : qry) {\n//   while (pr < r) add(x[++pr]);\n//   while (l < pl)\
    \ add(x[--pl]);\n//   while (pl < l) rem(x[pl++]);\n//   while (r < pr) rem(x[pr--]);\n\
    //   ans[idx] = res;\n// }\n"
  code: "const int sz = 850; // should be sqrt(3/2 * N)\nstruct Query {\n  int l,\
    \ r, idx;\n  bool operator<(const Query& o) {\n    if (l / sz != o.l / sz) return\
    \ l / sz < o.l / sz;\n    else {\n      if ((l / sz) & 1) return r / sz < o.r\
    \ / sz;\n      else return r / sz > o.r / sz;\n    }\n  };\n};\n// handle [l,\
    \ r] inclusive:\n// int pl = 0, pr = -1;\n// for (auto [l, r, idx] : qry) {\n\
    //   while (pr < r) add(x[++pr]);\n//   while (l < pl) add(x[--pl]);\n//   while\
    \ (pl < l) rem(x[pl++]);\n//   while (r < pr) rem(x[pr--]);\n//   ans[idx] = res;\n\
    // }"
  dependsOn: []
  isVerificationFile: false
  path: ds/Mo.h
  requiredBy: []
  timestamp: '2025-11-19 14:43:55+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/Mo.h
layout: document
redirect_from:
- /library/ds/Mo.h
- /library/ds/Mo.h.html
title: ds/Mo.h
---
