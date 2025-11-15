---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/MillerRabin.h
    title: math/MillerRabin.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/MillerRabin.h\"\nbool isPrime(ull n) {\n  if (n < 2\
    \ || n % 6 % 4 != 1) return (n | 1) == 3;\n  ull A[] = {2, 325, 9375, 28178, 450775,\
    \ 9780504, 1795265022},\n      s = __builtin_ctzll(n - 1), d = n >> s;\n  for\
    \ (ull a : A) {  // ^ count trailing zeroes\n    ull p = modpow(a % n, d, n),\
    \ i = s;\n    while (p != 1 && p != n - 1 && a % n && i--) p = modmul(p, p, n);\n\
    \    if (p != n - 1 && i != s) return 0;\n  }\n  return 1;\n}\n#line 2 \"math/Factor.h\"\
    \n\null pollard(ull n) {\n  ull x = 0, y = 0, t = 30, prd = 2, i = 1, q;\n  auto\
    \ f = [&](ull x) { return modmul(x, x, n) + i; };\n  while (t++ % 40 || gcd(prd,\
    \ n) == 1) {\n    if (x == y) x = ++i, y = f(x);\n    if ((q = modmul(prd, max(x,\
    \ y) - min(x, y), n))) prd = q;\n    x = f(x), y = f(f(y));\n  }\n  return gcd(prd,\
    \ n);\n}\nvector<ull> factor(ull n) {\n  if (n == 1) return {};\n  if (isPrime(n))\
    \ return {n};\n  ull x = pollard(n);\n  auto l = factor(x), r = factor(n / x);\n\
    \  l.insert(l.end(), all(r));\n  return l;\n}\n"
  code: "#include \"MillerRabin.h\"\n\null pollard(ull n) {\n  ull x = 0, y = 0, t\
    \ = 30, prd = 2, i = 1, q;\n  auto f = [&](ull x) { return modmul(x, x, n) + i;\
    \ };\n  while (t++ % 40 || gcd(prd, n) == 1) {\n    if (x == y) x = ++i, y = f(x);\n\
    \    if ((q = modmul(prd, max(x, y) - min(x, y), n))) prd = q;\n    x = f(x),\
    \ y = f(f(y));\n  }\n  return gcd(prd, n);\n}\nvector<ull> factor(ull n) {\n \
    \ if (n == 1) return {};\n  if (isPrime(n)) return {n};\n  ull x = pollard(n);\n\
    \  auto l = factor(x), r = factor(n / x);\n  l.insert(l.end(), all(r));\n  return\
    \ l;\n}"
  dependsOn:
  - math/MillerRabin.h
  isVerificationFile: false
  path: math/Factor.h
  requiredBy: []
  timestamp: '2025-11-15 18:26:28+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/Factor.h
layout: document
redirect_from:
- /library/math/Factor.h
- /library/math/Factor.h.html
title: math/Factor.h
---
