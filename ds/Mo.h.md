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
  bundledCode: "#line 1 \"ds/Mo.h\"\nconst int len = 850;  // should be sqrt(3/2 *\
    \ N)\nstruct Query {\n  int l, r, idx;\n  bool operator<(const Query& o) {\n \
    \   if (l / len != o.l / len)\n      return l / len < o.l / len;\n    else {\n\
    \      if ((l / len) & 1)\n        return r / len < o.r / len;\n      else\n \
    \       return r / len > o.r / len;\n    }\n  };\n};\n// handle [l, r] inclusive:\n\
    // int pl = 0, pr = -1;\n// for (auto [l, r, idx] : qry) {\n//   while (pr < r)\
    \ add(x[++pr]);\n//   while (l < pl) add(x[--pl]);\n//   while (pl < l) rem(x[pl++]);\n\
    //   while (r < pr) rem(x[pr--]);\n//   ans[idx] = res;\n// }\n"
  code: "const int len = 850;  // should be sqrt(3/2 * N)\nstruct Query {\n  int l,\
    \ r, idx;\n  bool operator<(const Query& o) {\n    if (l / len != o.l / len)\n\
    \      return l / len < o.l / len;\n    else {\n      if ((l / len) & 1)\n   \
    \     return r / len < o.r / len;\n      else\n        return r / len > o.r /\
    \ len;\n    }\n  };\n};\n// handle [l, r] inclusive:\n// int pl = 0, pr = -1;\n\
    // for (auto [l, r, idx] : qry) {\n//   while (pr < r) add(x[++pr]);\n//   while\
    \ (l < pl) add(x[--pl]);\n//   while (pl < l) rem(x[pl++]);\n//   while (r < pr)\
    \ rem(x[pr--]);\n//   ans[idx] = res;\n// }"
  dependsOn: []
  isVerificationFile: false
  path: ds/Mo.h
  requiredBy: []
  timestamp: '2026-10-03 15:27:40+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/Mo.h
layout: document
redirect_from:
- /library/ds/Mo.h
- /library/ds/Mo.h.html
title: ds/Mo.h
---
