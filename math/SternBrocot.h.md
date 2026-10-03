---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: tests/Rational_Approximation.test.cpp
    title: tests/Rational_Approximation.test.cpp
  - icon: ':x:'
    path: tests/Stern_Brocot.test.cpp
    title: tests/Stern_Brocot.test.cpp
  _isVerificationFailed: true
  _pathExtension: h
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/SternBrocot.h\"\nstruct Frac { i64 p, q; };\nusing\
    \ Path = vector<pair<char, i64>>;\n\nnamespace SternBrocot {\n  // 1. Encode:\
    \ 1/1 -> p/q\n  Path encode(i64 p, i64 q) {\n    Path res;\n    while (p != q)\
    \ {\n      i64 k = (p < q) ? q/p - !(q%p) : p/q - !(p%q);\n      res.push_back({p\
    \ < q ? 'L' : 'R', k});\n      if (p < q) q -= k * p; else p -= k * q;\n    }\n\
    \    return res;\n  }\n  // 2. Decode: Path -> Frac\n  Frac decode(const Path&\
    \ path) {\n    i64 lp = 0, lq = 1, rp = 1, rq = 0;\n    for (auto [c, k] : path)\n\
    \      if (c == 'L') rp += k * lp, rq += k * lq;\n      else          lp += k\
    \ * rp, lq += k * rq;\n    return {lp + rp, lq + rq};\n  }\n  // 3. LCA: a/b vs\
    \ c/d\n  Frac lca(i64 a, i64 b, i64 c, i64 d) {\n    Path p1 = encode(a, b), p2\
    \ = encode(c, d), res;\n    for (int i = 0; i < min((int)p1.size(), (int)p2.size())\
    \ && p1[i].first == p2[i].first; ++i)\n      res.push_back({p1[i].first, min(p1[i].second,\
    \ p2[i].second)}),\n      p1[i].second == p2[i].second ? 0 : (i = p1.size());\n\
    \    return decode(res);\n  }\n  // 4. Ancestor: Tr\u1EA3 v\u1EC1 n\xFAt \u1EDF\
    \ \u0111\u1ED9 s\xE2u k tr\xEAn \u0111\u01B0\u1EDDng \u0111i t\u1EEB 1/1 \u0111\
    \u1EBFn p/q\n  // k=0 -> 1/1, k=1 -> con tr\u1EF1c ti\u1EBFp c\u1EE7a 1/1...\n\
    \  Frac ancestor(i64 k, i64 p, i64 q) {\n    Path path = encode(p, q);\n    i64\
    \ lp = 0, lq = 1, rp = 1, rq = 0;\n    for (auto [c, step] : path) {\n      i64\
    \ take = min(k, step);\n      if (c == 'L') rp += take * lp, rq += take * lq;\n\
    \      else          lp += take * rp, lq += take * rq;\n      k -= take;\n   \
    \   if (k == 0) return {lp + rp, lq + rq};\n    }\n    return {-1, -1}; // k l\u1EDB\
    n h\u01A1n \u0111\u1ED9 s\xE2u c\u1EE7a p/q\n  }\n  // 5. Range: T\xECm kho\u1EA3\
    ng con (L, R) ch\u1EE9a p/q\n  pair<Frac, Frac> range(i64 p, i64 q) {\n    if\
    \ (p == 0) return {{0, 1}, {1, 0}};\n    i64 lp = 0, lq = 1, rp = 1, rq = 0;\n\
    \    while (p != q) {\n      i64 k = (p < q) ? q/p - !(q%p) : p/q - !(p%q);\n\
    \      if (p < q) rp += k * lp, rq += k * lq, q -= k * p;\n      else       lp\
    \ += k * rp, lq += k * rq, p -= k * q;\n    }\n    return {{lp, lq}, {rp, rq}};\n\
    \  }\n  // 6. Bound: T\xECm {L, R} s\xE1t nh\u1EA5t tr\xEAn SBT th\u1ECFa m\xE3\
    n gi\u1EDBi h\u1EA1n v\xE0 h\xE0m f\n  // f(Frac) -> bool: h\xE0m \u0111\u01A1\
    n \u0111i\u1EC7u tr\xEAn c\xE2y (VD: f(x) = x <= target)\n  // Tr\u1EA3 v\u1EC1\
    \ {L, R} l\xE0 2 ph\xE2n s\u1ED1 k\u1EB9p gi\u1EEFa ranh gi\u1EDBi T/F c\u1EE7\
    a f\n  template <class Func>\n  pair<Frac, Frac> bound(Func f, i64 maxp, i64 maxq)\
    \ {\n    Frac l{0, 1}, r{1, 0}, m;\n    int dir = 1; \n    if (f({1, 1}) == f(l))\
    \ l = {1, 1}; else r = {1, 1}, dir = 0;\n    while (true) {\n      Frac &cur =\
    \ dir ? l : r, &del = dir ? r : l;\n      i64 k = 0;\n      for (i64 step = 1;\
    \ step; ) {\n        i64 nk = k + step;\n        i64 np = cur.p + nk * del.p,\
    \ nq = cur.q + nk * del.q;\n        if (np <= maxp && nq <= maxq && f({np, nq})\
    \ == dir) k = nk, step *= 2;\n        else step /= 2;\n      }\n      cur.p +=\
    \ k * del.p, cur.q += k * del.q;\n      m = {l.p + r.p, l.q + r.q};\n      if\
    \ (m.p > maxp || m.q > maxq) break;\n      if (f(m)) l = m, dir = 1; else r =\
    \ m, dir = 0;\n    }\n    return {l, r};\n  }\n}\n"
  code: "struct Frac { i64 p, q; };\nusing Path = vector<pair<char, i64>>;\n\nnamespace\
    \ SternBrocot {\n  // 1. Encode: 1/1 -> p/q\n  Path encode(i64 p, i64 q) {\n \
    \   Path res;\n    while (p != q) {\n      i64 k = (p < q) ? q/p - !(q%p) : p/q\
    \ - !(p%q);\n      res.push_back({p < q ? 'L' : 'R', k});\n      if (p < q) q\
    \ -= k * p; else p -= k * q;\n    }\n    return res;\n  }\n  // 2. Decode: Path\
    \ -> Frac\n  Frac decode(const Path& path) {\n    i64 lp = 0, lq = 1, rp = 1,\
    \ rq = 0;\n    for (auto [c, k] : path)\n      if (c == 'L') rp += k * lp, rq\
    \ += k * lq;\n      else          lp += k * rp, lq += k * rq;\n    return {lp\
    \ + rp, lq + rq};\n  }\n  // 3. LCA: a/b vs c/d\n  Frac lca(i64 a, i64 b, i64\
    \ c, i64 d) {\n    Path p1 = encode(a, b), p2 = encode(c, d), res;\n    for (int\
    \ i = 0; i < min((int)p1.size(), (int)p2.size()) && p1[i].first == p2[i].first;\
    \ ++i)\n      res.push_back({p1[i].first, min(p1[i].second, p2[i].second)}),\n\
    \      p1[i].second == p2[i].second ? 0 : (i = p1.size());\n    return decode(res);\n\
    \  }\n  // 4. Ancestor: Tr\u1EA3 v\u1EC1 n\xFAt \u1EDF \u0111\u1ED9 s\xE2u k tr\xEA\
    n \u0111\u01B0\u1EDDng \u0111i t\u1EEB 1/1 \u0111\u1EBFn p/q\n  // k=0 -> 1/1,\
    \ k=1 -> con tr\u1EF1c ti\u1EBFp c\u1EE7a 1/1...\n  Frac ancestor(i64 k, i64 p,\
    \ i64 q) {\n    Path path = encode(p, q);\n    i64 lp = 0, lq = 1, rp = 1, rq\
    \ = 0;\n    for (auto [c, step] : path) {\n      i64 take = min(k, step);\n  \
    \    if (c == 'L') rp += take * lp, rq += take * lq;\n      else          lp +=\
    \ take * rp, lq += take * rq;\n      k -= take;\n      if (k == 0) return {lp\
    \ + rp, lq + rq};\n    }\n    return {-1, -1}; // k l\u1EDBn h\u01A1n \u0111\u1ED9\
    \ s\xE2u c\u1EE7a p/q\n  }\n  // 5. Range: T\xECm kho\u1EA3ng con (L, R) ch\u1EE9\
    a p/q\n  pair<Frac, Frac> range(i64 p, i64 q) {\n    if (p == 0) return {{0, 1},\
    \ {1, 0}};\n    i64 lp = 0, lq = 1, rp = 1, rq = 0;\n    while (p != q) {\n  \
    \    i64 k = (p < q) ? q/p - !(q%p) : p/q - !(p%q);\n      if (p < q) rp += k\
    \ * lp, rq += k * lq, q -= k * p;\n      else       lp += k * rp, lq += k * rq,\
    \ p -= k * q;\n    }\n    return {{lp, lq}, {rp, rq}};\n  }\n  // 6. Bound: T\xEC\
    m {L, R} s\xE1t nh\u1EA5t tr\xEAn SBT th\u1ECFa m\xE3n gi\u1EDBi h\u1EA1n v\xE0\
    \ h\xE0m f\n  // f(Frac) -> bool: h\xE0m \u0111\u01A1n \u0111i\u1EC7u tr\xEAn\
    \ c\xE2y (VD: f(x) = x <= target)\n  // Tr\u1EA3 v\u1EC1 {L, R} l\xE0 2 ph\xE2\
    n s\u1ED1 k\u1EB9p gi\u1EEFa ranh gi\u1EDBi T/F c\u1EE7a f\n  template <class\
    \ Func>\n  pair<Frac, Frac> bound(Func f, i64 maxp, i64 maxq) {\n    Frac l{0,\
    \ 1}, r{1, 0}, m;\n    int dir = 1; \n    if (f({1, 1}) == f(l)) l = {1, 1}; else\
    \ r = {1, 1}, dir = 0;\n    while (true) {\n      Frac &cur = dir ? l : r, &del\
    \ = dir ? r : l;\n      i64 k = 0;\n      for (i64 step = 1; step; ) {\n     \
    \   i64 nk = k + step;\n        i64 np = cur.p + nk * del.p, nq = cur.q + nk *\
    \ del.q;\n        if (np <= maxp && nq <= maxq && f({np, nq}) == dir) k = nk,\
    \ step *= 2;\n        else step /= 2;\n      }\n      cur.p += k * del.p, cur.q\
    \ += k * del.q;\n      m = {l.p + r.p, l.q + r.q};\n      if (m.p > maxp || m.q\
    \ > maxq) break;\n      if (f(m)) l = m, dir = 1; else r = m, dir = 0;\n    }\n\
    \    return {l, r};\n  }\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/SternBrocot.h
  requiredBy: []
  timestamp: '2025-11-28 10:18:48+07:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - tests/Stern_Brocot.test.cpp
  - tests/Rational_Approximation.test.cpp
documentation_of: math/SternBrocot.h
layout: document
redirect_from:
- /library/math/SternBrocot.h
- /library/math/SternBrocot.h.html
title: math/SternBrocot.h
---
