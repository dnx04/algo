---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/SternBrocot.h
    title: math/SternBrocot.h
  - icon: ':heavy_check_mark:'
    path: misc/macros.h
    title: misc/macros.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/rational_approximation
    links:
    - https://judge.yosupo.jp/problem/rational_approximation
  bundledCode: "#line 1 \"tests/Rational_Approximation.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/rational_approximation\"\n\n#line 1 \"misc/macros.h\"\
    \n// #pragma GCC optimize(\"Ofast,unroll-loops\")       // unroll long, simple\
    \ loops\n// #pragma GCC target(\"avx2,fma\")                   // vectorizing\
    \ code\n// #pragma GCC target(\"lzcnt,popcnt,abm,bmi,bmi2\")  // for fast bitset\
    \ operation\n\n#include <bits/extc++.h>\n#include <tr2/dynamic_bitset>\n\nusing\
    \ namespace std;\nusing namespace __gnu_pbds;  // ordered_set, gp_hash_table\n\
    // using namespace __gnu_cxx; // rope\n\n// for templates to work\n#define all(x)\
    \ (x).begin(), (x).end()\n#define sz(x) (int) (x).size()\n#define pb push_back\n\
    #define eb emplace_back\nusing i32 = int32_t;\nusing u32 = uint32_t;\nusing i64\
    \ = int64_t;\nusing u64 = uint64_t;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\
    using ld = long double;\nusing pii = pair<i32, i32>;\nusing vi = vector<i32>;\n\
    \n// fast map\nconst int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();\n\
    struct chash {  // customize hash function for gp_hash_table\n  int operator()(int\
    \ x) const { return x ^ RANDOM; }\n};\ngp_hash_table<int, int, chash> table;\n\
    \n/* ordered set\n    find_by_order(k): returns an iterator to the k-th element\
    \ (0-based)\n    order_of_key(k): returns the number of elements in the set that\
    \ are strictly less than k\n*/\ntemplate <class T>\nusing ordered_set = tree<T,\
    \ null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;\n\n/* \
    \ rope\n    rope <int> cur = v.substr(l, r - l + 1);\n    v.erase(l, r - l + 1);\n\
    \    v.insert(v.mutable_begin(), cur);\n*/\n#line 1 \"math/SternBrocot.h\"\nstruct\
    \ Frac { i64 p, q; };\nusing Path = vector<pair<char, i64>>;\n\nnamespace SternBrocot\
    \ {\n  // 1. Encode: 1/1 -> p/q\n  Path encode(i64 p, i64 q) {\n    Path res;\n\
    \    while (p != q) {\n      i64 k = (p < q) ? q/p - !(q%p) : p/q - !(p%q);\n\
    \      res.push_back({p < q ? 'L' : 'R', k});\n      if (p < q) q -= k * p; else\
    \ p -= k * q;\n    }\n    return res;\n  }\n  // 2. Decode: Path -> Frac\n  Frac\
    \ decode(const Path& path) {\n    i64 lp = 0, lq = 1, rp = 1, rq = 0;\n    for\
    \ (auto [c, k] : path)\n      if (c == 'L') rp += k * lp, rq += k * lq;\n    \
    \  else          lp += k * rp, lq += k * rq;\n    return {lp + rp, lq + rq};\n\
    \  }\n  // 3. LCA: a/b vs c/d\n  Frac lca(i64 a, i64 b, i64 c, i64 d) {\n    Path\
    \ p1 = encode(a, b), p2 = encode(c, d), res;\n    for (int i = 0; i < min((int)p1.size(),\
    \ (int)p2.size()) && p1[i].first == p2[i].first; ++i)\n      res.push_back({p1[i].first,\
    \ min(p1[i].second, p2[i].second)}),\n      p1[i].second == p2[i].second ? 0 :\
    \ (i = p1.size());\n    return decode(res);\n  }\n  // 4. Ancestor: Tr\u1EA3 v\u1EC1\
    \ n\xFAt \u1EDF \u0111\u1ED9 s\xE2u k tr\xEAn \u0111\u01B0\u1EDDng \u0111i t\u1EEB\
    \ 1/1 \u0111\u1EBFn p/q\n  // k=0 -> 1/1, k=1 -> con tr\u1EF1c ti\u1EBFp c\u1EE7\
    a 1/1...\n  Frac ancestor(i64 k, i64 p, i64 q) {\n    Path path = encode(p, q);\n\
    \    i64 lp = 0, lq = 1, rp = 1, rq = 0;\n    for (auto [c, step] : path) {\n\
    \      i64 take = min(k, step);\n      if (c == 'L') rp += take * lp, rq += take\
    \ * lq;\n      else          lp += take * rp, lq += take * rq;\n      k -= take;\n\
    \      if (k == 0) return {lp + rp, lq + rq};\n    }\n    return {-1, -1}; //\
    \ k l\u1EDBn h\u01A1n \u0111\u1ED9 s\xE2u c\u1EE7a p/q\n  }\n  // 5. Range: T\xEC\
    m kho\u1EA3ng con (L, R) ch\u1EE9a p/q\n  pair<Frac, Frac> range(i64 p, i64 q)\
    \ {\n    if (p == 0) return {{0, 1}, {1, 0}};\n    i64 lp = 0, lq = 1, rp = 1,\
    \ rq = 0;\n    while (p != q) {\n      i64 k = (p < q) ? q/p - !(q%p) : p/q -\
    \ !(p%q);\n      if (p < q) rp += k * lp, rq += k * lq, q -= k * p;\n      else\
    \       lp += k * rp, lq += k * rq, p -= k * q;\n    }\n    return {{lp, lq},\
    \ {rp, rq}};\n  }\n  // 6. Bound: T\xECm {L, R} s\xE1t nh\u1EA5t tr\xEAn SBT th\u1ECF\
    a m\xE3n gi\u1EDBi h\u1EA1n v\xE0 h\xE0m f\n  // f(Frac) -> bool: h\xE0m \u0111\
    \u01A1n \u0111i\u1EC7u tr\xEAn c\xE2y (VD: f(x) = x <= target)\n  // Tr\u1EA3\
    \ v\u1EC1 {L, R} l\xE0 2 ph\xE2n s\u1ED1 k\u1EB9p gi\u1EEFa ranh gi\u1EDBi T/F\
    \ c\u1EE7a f\n  template <class Func>\n  pair<Frac, Frac> bound(Func f, i64 maxp,\
    \ i64 maxq) {\n    Frac l{0, 1}, r{1, 0}, m;\n    int dir = 1; \n    if (f({1,\
    \ 1}) == f(l)) l = {1, 1}; else r = {1, 1}, dir = 0;\n    while (true) {\n   \
    \   Frac &cur = dir ? l : r, &del = dir ? r : l;\n      i64 k = 0;\n      for\
    \ (i64 step = 1; step; ) {\n        i64 nk = k + step;\n        i64 np = cur.p\
    \ + nk * del.p, nq = cur.q + nk * del.q;\n        if (np <= maxp && nq <= maxq\
    \ && f({np, nq}) == dir) k = nk, step *= 2;\n        else step /= 2;\n      }\n\
    \      cur.p += k * del.p, cur.q += k * del.q;\n      m = {l.p + r.p, l.q + r.q};\n\
    \      if (m.p > maxp || m.q > maxq) break;\n      if (f(m)) l = m, dir = 1; else\
    \ r = m, dir = 0;\n    }\n    return {l, r};\n  }\n}\n#line 5 \"tests/Rational_Approximation.test.cpp\"\
    \n\nvoid solve() {\n  int n, x, y;\n  cin >> n >> x >> y;\n  auto f = [&](Frac\
    \ a) {\n    return a.p * y <= a.q * x;\n  };\n  auto [lo, hi] = SternBrocot::bound(f,\
    \ n, n);\n  if(lo.p * y == lo.q * x) hi = lo;\n  cout << lo.p << ' ' << lo.q <<\
    \ ' ' << hi.p << ' ' << hi.q << '\\n';\n}\n\nsigned main() {\n  ios::sync_with_stdio(false);\n\
    \  cin.tie(0);\n  int tc = 1;\n  cin >> tc;\n  while (tc--) solve();\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/rational_approximation\"\
    \n\n#include \"../misc/macros.h\"\n#include \"../math/SternBrocot.h\"\n\nvoid\
    \ solve() {\n  int n, x, y;\n  cin >> n >> x >> y;\n  auto f = [&](Frac a) {\n\
    \    return a.p * y <= a.q * x;\n  };\n  auto [lo, hi] = SternBrocot::bound(f,\
    \ n, n);\n  if(lo.p * y == lo.q * x) hi = lo;\n  cout << lo.p << ' ' << lo.q <<\
    \ ' ' << hi.p << ' ' << hi.q << '\\n';\n}\n\nsigned main() {\n  ios::sync_with_stdio(false);\n\
    \  cin.tie(0);\n  int tc = 1;\n  cin >> tc;\n  while (tc--) solve();\n}"
  dependsOn:
  - misc/macros.h
  - math/SternBrocot.h
  isVerificationFile: true
  path: tests/Rational_Approximation.test.cpp
  requiredBy: []
  timestamp: '2025-11-28 10:18:48+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/Rational_Approximation.test.cpp
layout: document
redirect_from:
- /verify/tests/Rational_Approximation.test.cpp
- /verify/tests/Rational_Approximation.test.cpp.html
title: tests/Rational_Approximation.test.cpp
---
