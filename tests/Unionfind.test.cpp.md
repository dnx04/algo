---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/DSU.h
    title: ds/DSU.h
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
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"tests/Unionfind.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\
    \n\n#line 1 \"misc/macros.h\"\n// #pragma GCC optimize(\"Ofast,unroll-loops\"\
    )       // unroll long, simple loops\n// #pragma GCC target(\"avx2,fma\")    \
    \               // vectorizing code\n// #pragma GCC target(\"lzcnt,popcnt,abm,bmi,bmi2\"\
    )  // for fast bitset operation\n\n#include <bits/extc++.h>\n\n#include <tr2/dynamic_bitset>\n\
    \nusing namespace std;\nusing namespace __gnu_pbds;  // ordered_set, gp_hash_table\n\
    // using namespace __gnu_cxx;\n\n// for templates to work\n#define all(s) s.begin(),\
    \ s.end()\n#define sz(x) (int) (x).size()\n#define pb push_back\n#define eb emplace_back\n\
    using i32 = int32_t;\nusing u32 = uint32_t;\nusing i64 = int64_t;\nusing u64 =\
    \ uint64_t;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\nusing ld = long\
    \ double;\nusing pii = pair<i32, i32>;\nusing vi = vector<i32>;\n\n// fast map\n\
    const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();\n\
    struct chash {  // customize hash function for gp_hash_table\n  int operator()(int\
    \ x) const { return x ^ RANDOM; }\n};\ngp_hash_table<int, int, chash> table;\n\
    \n/* ordered set\n    find_by_order(k): returns an iterator to the k-th element\
    \ (0-based)\n    order_of_key(k): returns the number of elements in the set that\
    \ are strictly less than k\n*/\ntemplate <typename T>\nusing ordered_set = tree<T,\
    \ null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;\n\n// dynamic\
    \ bitset\nusing bs = tr2::dynamic_bitset<u64>;\n\n/*  rope\n    rope <int> cur\
    \ = v.substr(l, r - l + 1);\n    v.erase(l, r - l + 1);\n    v.insert(v.mutable_begin(),\
    \ cur);\n*/\n#line 1 \"ds/DSU.h\"\nstruct DSU {\n  int n;\n  vi p;\n  DSU(int\
    \ n) : n(n), p(n, -1) {}\n  int merge(int a, int b) {\n    int x = head(a), y\
    \ = head(b);\n    if (x == y) return x;\n    if (-p[x] < -p[y]) swap(x, y);\n\
    \    p[x] += p[y], p[y] = x;\n    return x;\n  }\n  bool same(int a, int b) {\
    \ return head(a) == head(b); }\n  int head(int a) {\n    if (p[a] < 0) return\
    \ a;\n    return p[a] = head(p[a]);\n  }\n  int size(int a) { return -p[head(a)];\
    \ }\n};\n#line 5 \"tests/Unionfind.test.cpp\"\n\nvoid solve() {\n  int n, q;\n\
    \  cin >> n >> q;\n  DSU d(n);\n  while (q--) {\n    int cmd, u, v;\n    cin >>\
    \ cmd >> u >> v;\n    if (cmd == 0) {\n      d.merge(u, v);\n    } else {\n  \
    \    cout << d.same(u, v) << '\\n';\n    }\n  }\n}\n\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n\
    \  cin.exceptions(cin.failbit);\n  int tc = 1;\n  // cin >> tc;\n  for (int i\
    \ = 1; i <= tc; ++i) {\n    solve();\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ \"../misc/macros.h\"\n#include \"../ds/DSU.h\"\n\nvoid solve() {\n  int n, q;\n\
    \  cin >> n >> q;\n  DSU d(n);\n  while (q--) {\n    int cmd, u, v;\n    cin >>\
    \ cmd >> u >> v;\n    if (cmd == 0) {\n      d.merge(u, v);\n    } else {\n  \
    \    cout << d.same(u, v) << '\\n';\n    }\n  }\n}\n\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n\
    \  cin.exceptions(cin.failbit);\n  int tc = 1;\n  // cin >> tc;\n  for (int i\
    \ = 1; i <= tc; ++i) {\n    solve();\n  }\n}"
  dependsOn:
  - misc/macros.h
  - ds/DSU.h
  isVerificationFile: true
  path: tests/Unionfind.test.cpp
  requiredBy: []
  timestamp: '2025-11-20 10:20:22+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/Unionfind.test.cpp
layout: document
redirect_from:
- /verify/tests/Unionfind.test.cpp
- /verify/tests/Unionfind.test.cpp.html
title: tests/Unionfind.test.cpp
---
