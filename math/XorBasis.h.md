---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/Intersection_of_F2_vector_spaces.test.cpp
    title: tests/Intersection_of_F2_vector_spaces.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/XorBasis.h\"\nstruct XorBasis {\n  vector<ll> b;\n\
    \  XorBasis() {}\n  void add(int x) {\n    x = this->sift(x);\n    if (x != 0)\
    \ this->b.pb(x);\n  }\n  ll sift(ll x) const {\n    for (ll b : this->b) {\n \
    \     x = min(x, x ^ b);\n      if (x == 0) return 0;\n    }\n    return x;\n\
    \  }\n  bool is_indep(ll x) const {\n    return this->sift(x) != 0;\n  }\n  vector<ll>\
    \ basis() const {\n    return this->b;\n  }\n};\n\nvector<ll> XorInter(const vector<ll>&\
    \ u, const vector<ll>& v) {\n  XorBasis X;\n  for (auto x : u) X.add(x);\n  vector<pair<ll,\
    \ ll>> basis;\n  XorBasis inter;\n  for (auto x : v) {\n    auto y = X.sift(x),\
    \ pu = y ^ x, sy = y;\n    for (auto v : basis) {\n      ll tmp = sy ^ v.second;\n\
    \      if (tmp < sy) {\n        sy = tmp;\n        pu ^= v.first;\n      }\n \
    \   }\n    if (sy != 0) {\n      basis.pb({pu, sy});\n    } else {\n      inter.add(pu);\n\
    \    }\n  }\n  return inter.basis();\n}\n"
  code: "struct XorBasis {\n  vector<ll> b;\n  XorBasis() {}\n  void add(int x) {\n\
    \    x = this->sift(x);\n    if (x != 0) this->b.pb(x);\n  }\n  ll sift(ll x)\
    \ const {\n    for (ll b : this->b) {\n      x = min(x, x ^ b);\n      if (x ==\
    \ 0) return 0;\n    }\n    return x;\n  }\n  bool is_indep(ll x) const {\n   \
    \ return this->sift(x) != 0;\n  }\n  vector<ll> basis() const {\n    return this->b;\n\
    \  }\n};\n\nvector<ll> XorInter(const vector<ll>& u, const vector<ll>& v) {\n\
    \  XorBasis X;\n  for (auto x : u) X.add(x);\n  vector<pair<ll, ll>> basis;\n\
    \  XorBasis inter;\n  for (auto x : v) {\n    auto y = X.sift(x), pu = y ^ x,\
    \ sy = y;\n    for (auto v : basis) {\n      ll tmp = sy ^ v.second;\n      if\
    \ (tmp < sy) {\n        sy = tmp;\n        pu ^= v.first;\n      }\n    }\n  \
    \  if (sy != 0) {\n      basis.pb({pu, sy});\n    } else {\n      inter.add(pu);\n\
    \    }\n  }\n  return inter.basis();\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/XorBasis.h
  requiredBy: []
  timestamp: '2025-11-15 18:26:28+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/Intersection_of_F2_vector_spaces.test.cpp
documentation_of: math/XorBasis.h
layout: document
redirect_from:
- /library/math/XorBasis.h
- /library/math/XorBasis.h.html
title: math/XorBasis.h
---
