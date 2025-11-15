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
  bundledCode: "#line 1 \"misc/FracBinarySearch.h\"\nusing ll = long long;\nstruct\
    \ Frac {\n  ll p, q;\n};\n\ntemplate <class Func>\nFrac FracLowerBound(Func f,\
    \ ll maxq, ll maxp) {\n  Frac lo{0, 1}, hi{1, 1}, mid;  // Set hi to 1/0 for (0,\
    \ inf)\n  if (f(lo)) return lo;\n  assert(f(hi));\n  for (int it = 0, dir = 1;\
    \ it < 3 || !dir; ++it) {\n    // invariant: f(lo) == !dir, f(hi) == dir\n   \
    \ for (ll step = 1, adv = 1, now = 0;; adv ? step *= 2 : step /= 2) {\n      now\
    \ += step;\n      mid = {lo.p * now + hi.p, lo.q * now + hi.q};\n      if (abs(mid.p)\
    \ > maxp || mid.q > maxq || f(mid) != dir) now -= step, adv = 0;\n      if (!step)\
    \ break;\n    }\n    if (mid.p != hi.p) it = 0;\n    hi = lo;\n    lo = mid;\n\
    \    dir = !dir;\n  }\n  // (lo, hi) are consecutive with f(lo) == 0, f(hi) ==\
    \ 1\n  return hi;\n}\n"
  code: "using ll = long long;\nstruct Frac {\n  ll p, q;\n};\n\ntemplate <class Func>\n\
    Frac FracLowerBound(Func f, ll maxq, ll maxp) {\n  Frac lo{0, 1}, hi{1, 1}, mid;\
    \  // Set hi to 1/0 for (0, inf)\n  if (f(lo)) return lo;\n  assert(f(hi));\n\
    \  for (int it = 0, dir = 1; it < 3 || !dir; ++it) {\n    // invariant: f(lo)\
    \ == !dir, f(hi) == dir\n    for (ll step = 1, adv = 1, now = 0;; adv ? step *=\
    \ 2 : step /= 2) {\n      now += step;\n      mid = {lo.p * now + hi.p, lo.q *\
    \ now + hi.q};\n      if (abs(mid.p) > maxp || mid.q > maxq || f(mid) != dir)\
    \ now -= step, adv = 0;\n      if (!step) break;\n    }\n    if (mid.p != hi.p)\
    \ it = 0;\n    hi = lo;\n    lo = mid;\n    dir = !dir;\n  }\n  // (lo, hi) are\
    \ consecutive with f(lo) == 0, f(hi) == 1\n  return hi;\n}"
  dependsOn: []
  isVerificationFile: false
  path: misc/FracBinarySearch.h
  requiredBy: []
  timestamp: '2025-11-15 18:26:28+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/FracBinarySearch.h
layout: document
redirect_from:
- /library/misc/FracBinarySearch.h
- /library/misc/FracBinarySearch.h.html
title: misc/FracBinarySearch.h
---
