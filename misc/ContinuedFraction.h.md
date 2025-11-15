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
  bundledCode: "#line 1 \"misc/ContinuedFraction.h\"\ntypedef double d;  // for N\
    \ ~ 1e7; long double for N ~ 1e9\npair<ll, ll> approximate(d x, ll N) {\n  ll\
    \ LP = 0, LQ = 1, P = 1, Q = 0, inf = LLONG_MAX;\n  d y = x;\n  for (;;) {\n \
    \   ll lim = min(P ? (N - LP) / P : inf, Q ? (N - LQ) / Q : inf),\n       a =\
    \ (ll) floor(y), b = min(a, lim), NP = b * P + LP, NQ = b * Q + LQ;\n    if (a\
    \ > b) {\n      // If b > a/2, we have a semi-convergent that gives us a\n   \
    \   // better approximation; if b = a/2, we *may* have one.\n      // Return {P,\
    \ Q} here for a more canonical approximation.\n      return (abs(x - (d) NP /\
    \ (d) NQ) < abs(x - (d) P / (d) Q)) ? make_pair(NP, NQ) : make_pair(P, Q);\n \
    \   }\n    if (abs(y = 1 / (y - (d) a)) > 3 * N) return {NP, NQ};\n    LP = P;\n\
    \    P = NP;\n    LQ = Q;\n    Q = NQ;\n  }\n}\n"
  code: "typedef double d;  // for N ~ 1e7; long double for N ~ 1e9\npair<ll, ll>\
    \ approximate(d x, ll N) {\n  ll LP = 0, LQ = 1, P = 1, Q = 0, inf = LLONG_MAX;\n\
    \  d y = x;\n  for (;;) {\n    ll lim = min(P ? (N - LP) / P : inf, Q ? (N - LQ)\
    \ / Q : inf),\n       a = (ll) floor(y), b = min(a, lim), NP = b * P + LP, NQ\
    \ = b * Q + LQ;\n    if (a > b) {\n      // If b > a/2, we have a semi-convergent\
    \ that gives us a\n      // better approximation; if b = a/2, we *may* have one.\n\
    \      // Return {P, Q} here for a more canonical approximation.\n      return\
    \ (abs(x - (d) NP / (d) NQ) < abs(x - (d) P / (d) Q)) ? make_pair(NP, NQ) : make_pair(P,\
    \ Q);\n    }\n    if (abs(y = 1 / (y - (d) a)) > 3 * N) return {NP, NQ};\n   \
    \ LP = P;\n    P = NP;\n    LQ = Q;\n    Q = NQ;\n  }\n}"
  dependsOn: []
  isVerificationFile: false
  path: misc/ContinuedFraction.h
  requiredBy: []
  timestamp: '2025-11-15 18:26:28+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/ContinuedFraction.h
layout: document
redirect_from:
- /library/misc/ContinuedFraction.h
- /library/misc/ContinuedFraction.h.html
title: misc/ContinuedFraction.h
---
