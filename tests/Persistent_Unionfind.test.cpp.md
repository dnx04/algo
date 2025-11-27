---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: ds/DSURollback.h
    title: ds/DSURollback.h
  - icon: ':question:'
    path: misc/macros.h
    title: misc/macros.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/persistent_unionfind
    links:
    - https://judge.yosupo.jp/problem/persistent_unionfind
  bundledCode: "#line 1 \"tests/Persistent_Unionfind.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/persistent_unionfind\"\n\n#line 1 \"misc/macros.h\"\
    \n// #pragma GCC optimize(\"Ofast,unroll-loops\")       // unroll long, simple\
    \ loops\n// #pragma GCC target(\"avx2,fma\")                   // vectorizing\
    \ code\n// #pragma GCC target(\"lzcnt,popcnt,abm,bmi,bmi2\")  // for fast bitset\
    \ operation\n\n#include <bits/extc++.h>\n\nusing namespace std;\nusing namespace\
    \ __gnu_pbds;  // ordered_set, gp_hash_table\n// using namespace __gnu_cxx; //\
    \ rope\n\n// for templates to work\n#define all(s) s.begin(), s.end()\n#define\
    \ sz(x) (int) (x).size()\n#define pb push_back\n#define eb emplace_back\nusing\
    \ i32 = int32_t;\nusing u32 = uint32_t;\nusing i64 = int64_t;\nusing u64 = uint64_t;\n\
    using i128 = __int128_t;\nusing u128 = __uint128_t;\nusing ld = long double;\n\
    using pii = pair<i32, i32>;\nusing vi = vector<i32>;\n\n// fast map\nconst int\
    \ RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();\n\
    struct chash {  // customize hash function for gp_hash_table\n  int operator()(int\
    \ x) const { return x ^ RANDOM; }\n};\ngp_hash_table<int, int, chash> table;\n\
    \n/* ordered set\n    find_by_order(k): returns an iterator to the k-th element\
    \ (0-based)\n    order_of_key(k): returns the number of elements in the set that\
    \ are strictly less than k\n*/\ntemplate <class T>\nusing ordered_set = tree<T,\
    \ null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;\n\n/* \
    \ rope\n    rope <int> cur = v.substr(l, r - l + 1);\n    v.erase(l, r - l + 1);\n\
    \    v.insert(v.mutable_begin(), cur);\n*/\n#line 1 \"ds/DSURollback.h\"\nstruct\
    \ DSURollback {\n  int n;\n  vector<int> p;\n  vector<pair<int*, int>> his;\n\
    \  DSURollback(int n) : n(n), p(n, -1) {}\n  int root(int s) {\n    while (p[s]\
    \ >= 0) s = p[s];\n    return s;\n  }\n  void merge(int a, int b) {\n    a = root(a);\n\
    \    b = root(b);\n    if (a == b) return;\n    if (p[a] < p[b]) swap(a, b);\n\
    \    his.eb(&p[a], p[a]), his.eb(&p[b], p[b]), his.eb(&n, n);\n    n--, p[b] +=\
    \ p[a], p[a] = b;\n  }\n  void undo(int cnt) {\n    while (cnt--) {\n      auto\
    \ [a, b] = his.back();\n      his.pop_back();\n      *a = b;\n    }\n  }\n};\n\
    #line 5 \"tests/Persistent_Unionfind.test.cpp\"\n\nconst int MAXN = 200005;\n\
    // Map index -1 v\u1EC1 m\u1ED9t ch\u1EC9 s\u1ED1 d\u01B0\u01A1ng \u0111\u1EC3\
    \ d\xF9ng l\xE0m ch\u1EC9 s\u1ED1 m\u1EA3ng (v\xED d\u1EE5 MAXN - 1)\nconst int\
    \ ROOT_IDX = MAXN - 1;\n\nstruct QueryInfo {\n  int t, k, u, v;\n};\n\n// adj[u]:\
    \ Danh s\xE1ch c\xE1c truy v\u1EA5n lo\u1EA1i 0 (t\u1EA1o \u0111\u1ED3 th\u1ECB\
    \ con) xu\u1EA5t ph\xE1t t\u1EEB tr\u1EA1ng th\xE1i u\nvector<int> adj[MAXN];\n\
    \n// checks[u]: Danh s\xE1ch c\xE1c truy v\u1EA5n lo\u1EA1i 1 (ki\u1EC3m tra)\
    \ c\u1EA7n th\u1EF1c hi\u1EC7n t\u1EA1i tr\u1EA1ng th\xE1i u\nvector<int> checks[MAXN];\n\
    \nQueryInfo qs[MAXN];\nint ans[MAXN];     // M\u1EA3ng l\u01B0u k\u1EBFt qu\u1EA3\
    , kh\u1EDFi t\u1EA1o -1\nDSURollback* dsu;  // Con tr\u1ECF to\xE0n c\u1EE5c \u0111\
    \u1EC3 ti\u1EC7n d\xF9ng trong DFS\n\nvoid dfs(int u) {\n  // 1. L\u01B0u k\xED\
    ch th\u01B0\u1EDBc l\u1ECBch s\u1EED tr\u01B0\u1EDBc khi thay \u0111\u1ED5i\n\
    \  int snapshot = dsu->his.size();\n\n  // 2. Th\u1EF1c hi\u1EC7n thay \u0111\u1ED5\
    i (n\u1EBFu kh\xF4ng ph\u1EA3i g\u1ED1c \u1EA3o)\n  if (u != ROOT_IDX) {\n   \
    \ dsu->merge(qs[u].u, qs[u].v);\n  }\n\n  // 3. Tr\u1EA3 l\u1EDDi c\xE1c truy\
    \ v\u1EA5n ki\u1EC3m tra t\u1EA1i tr\u1EA1ng th\xE1i hi\u1EC7n t\u1EA1i\n  for\
    \ (int q_idx : checks[u]) {\n    int root_u = dsu->root(qs[q_idx].u);\n    int\
    \ root_v = dsu->root(qs[q_idx].v);\n    ans[q_idx] = (root_u == root_v ? 1 : 0);\n\
    \  }\n\n  // 4. Duy\u1EC7t ti\u1EBFp xu\u1ED1ng c\xE1c tr\u1EA1ng th\xE1i con\n\
    \  for (int v : adj[u]) {\n    dfs(v);\n  }\n\n  // 5. Rollback (Ho\xE0n t\xE1\
    c) v\u1EC1 tr\u1EA1ng th\xE1i tr\u01B0\u1EDBc \u0111\xF3\n  // S\u1ED1 l\u01B0\
    \u1EE3ng thao t\xE1c c\u1EA7n undo = k\xEDch th\u01B0\u1EDBc hi\u1EC7n t\u1EA1\
    i - k\xEDch th\u01B0\u1EDBc l\xFAc m\u1EDBi v\xE0o\n  int ops_to_undo = dsu->his.size()\
    \ - snapshot;\n  dsu->undo(ops_to_undo);\n}\n\nint main() {\n  ios_base::sync_with_stdio(false);\n\
    \  cin.tie(NULL);\n\n  int N, Q;\n  if (!(cin >> N >> Q)) return 0;\n\n  dsu =\
    \ new DSURollback(N);\n\n  // Kh\u1EDFi t\u1EA1o m\u1EA3ng k\u1EBFt qu\u1EA3\n\
    \  for (int i = 0; i < Q; ++i) ans[i] = -1;\n\n  for (int i = 0; i < Q; ++i) {\n\
    \    cin >> qs[i].t >> qs[i].k >> qs[i].u >> qs[i].v;\n\n    // X\u1EED l\xFD\
    \ ch\u1EC9 s\u1ED1 k: n\u1EBFu l\xE0 -1 th\xEC map v\u1EC1 ROOT_IDX\n    int parent\
    \ = (qs[i].k == -1) ? ROOT_IDX : qs[i].k;\n\n    if (qs[i].t == 0) {\n      //\
    \ Truy v\u1EA5n lo\u1EA1i 0: T\u1EA1o n\xFAt con trong c\xE2y phi\xEAn b\u1EA3\
    n\n      // i l\xE0 ch\u1EC9 s\u1ED1 c\u1EE7a truy v\u1EA5n hi\u1EC7n t\u1EA1\
    i, c\u0169ng l\xE0 \u0111\u1ECBnh danh cho tr\u1EA1ng th\xE1i m\u1EDBi\n     \
    \ adj[parent].push_back(i);\n    } else {\n      // Truy v\u1EA5n lo\u1EA1i 1:\
    \ Th\xEAm v\xE0o danh s\xE1ch ki\u1EC3m tra c\u1EE7a tr\u1EA1ng th\xE1i cha\n\
    \      checks[parent].push_back(i);\n    }\n  }\n\n  // B\u1EAFt \u0111\u1EA7\
    u DFS t\u1EEB tr\u1EA1ng th\xE1i r\u1ED7ng\n  dfs(ROOT_IDX);\n\n  // In k\u1EBF\
    t qu\u1EA3 theo \u0111\xFAng th\u1EE9 t\u1EF1 c\xE1c truy v\u1EA5n lo\u1EA1i 1\n\
    \  for (int i = 0; i < Q; ++i) {\n    if (qs[i].t == 1) {\n      cout << ans[i]\
    \ << \"\\n\";\n    }\n  }\n\n  delete dsu;\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\"\n\
    \n#include \"misc/macros.h\"\n#include \"ds/DSURollback.h\"\n\nconst int MAXN\
    \ = 200005;\n// Map index -1 v\u1EC1 m\u1ED9t ch\u1EC9 s\u1ED1 d\u01B0\u01A1ng\
    \ \u0111\u1EC3 d\xF9ng l\xE0m ch\u1EC9 s\u1ED1 m\u1EA3ng (v\xED d\u1EE5 MAXN -\
    \ 1)\nconst int ROOT_IDX = MAXN - 1;\n\nstruct QueryInfo {\n  int t, k, u, v;\n\
    };\n\n// adj[u]: Danh s\xE1ch c\xE1c truy v\u1EA5n lo\u1EA1i 0 (t\u1EA1o \u0111\
    \u1ED3 th\u1ECB con) xu\u1EA5t ph\xE1t t\u1EEB tr\u1EA1ng th\xE1i u\nvector<int>\
    \ adj[MAXN];\n\n// checks[u]: Danh s\xE1ch c\xE1c truy v\u1EA5n lo\u1EA1i 1 (ki\u1EC3\
    m tra) c\u1EA7n th\u1EF1c hi\u1EC7n t\u1EA1i tr\u1EA1ng th\xE1i u\nvector<int>\
    \ checks[MAXN];\n\nQueryInfo qs[MAXN];\nint ans[MAXN];     // M\u1EA3ng l\u01B0\
    u k\u1EBFt qu\u1EA3, kh\u1EDFi t\u1EA1o -1\nDSURollback* dsu;  // Con tr\u1ECF\
    \ to\xE0n c\u1EE5c \u0111\u1EC3 ti\u1EC7n d\xF9ng trong DFS\n\nvoid dfs(int u)\
    \ {\n  // 1. L\u01B0u k\xEDch th\u01B0\u1EDBc l\u1ECBch s\u1EED tr\u01B0\u1EDB\
    c khi thay \u0111\u1ED5i\n  int snapshot = dsu->his.size();\n\n  // 2. Th\u1EF1\
    c hi\u1EC7n thay \u0111\u1ED5i (n\u1EBFu kh\xF4ng ph\u1EA3i g\u1ED1c \u1EA3o)\n\
    \  if (u != ROOT_IDX) {\n    dsu->merge(qs[u].u, qs[u].v);\n  }\n\n  // 3. Tr\u1EA3\
    \ l\u1EDDi c\xE1c truy v\u1EA5n ki\u1EC3m tra t\u1EA1i tr\u1EA1ng th\xE1i hi\u1EC7\
    n t\u1EA1i\n  for (int q_idx : checks[u]) {\n    int root_u = dsu->root(qs[q_idx].u);\n\
    \    int root_v = dsu->root(qs[q_idx].v);\n    ans[q_idx] = (root_u == root_v\
    \ ? 1 : 0);\n  }\n\n  // 4. Duy\u1EC7t ti\u1EBFp xu\u1ED1ng c\xE1c tr\u1EA1ng\
    \ th\xE1i con\n  for (int v : adj[u]) {\n    dfs(v);\n  }\n\n  // 5. Rollback\
    \ (Ho\xE0n t\xE1c) v\u1EC1 tr\u1EA1ng th\xE1i tr\u01B0\u1EDBc \u0111\xF3\n  //\
    \ S\u1ED1 l\u01B0\u1EE3ng thao t\xE1c c\u1EA7n undo = k\xEDch th\u01B0\u1EDBc\
    \ hi\u1EC7n t\u1EA1i - k\xEDch th\u01B0\u1EDBc l\xFAc m\u1EDBi v\xE0o\n  int ops_to_undo\
    \ = dsu->his.size() - snapshot;\n  dsu->undo(ops_to_undo);\n}\n\nint main() {\n\
    \  ios_base::sync_with_stdio(false);\n  cin.tie(NULL);\n\n  int N, Q;\n  if (!(cin\
    \ >> N >> Q)) return 0;\n\n  dsu = new DSURollback(N);\n\n  // Kh\u1EDFi t\u1EA1\
    o m\u1EA3ng k\u1EBFt qu\u1EA3\n  for (int i = 0; i < Q; ++i) ans[i] = -1;\n\n\
    \  for (int i = 0; i < Q; ++i) {\n    cin >> qs[i].t >> qs[i].k >> qs[i].u >>\
    \ qs[i].v;\n\n    // X\u1EED l\xFD ch\u1EC9 s\u1ED1 k: n\u1EBFu l\xE0 -1 th\xEC\
    \ map v\u1EC1 ROOT_IDX\n    int parent = (qs[i].k == -1) ? ROOT_IDX : qs[i].k;\n\
    \n    if (qs[i].t == 0) {\n      // Truy v\u1EA5n lo\u1EA1i 0: T\u1EA1o n\xFA\
    t con trong c\xE2y phi\xEAn b\u1EA3n\n      // i l\xE0 ch\u1EC9 s\u1ED1 c\u1EE7\
    a truy v\u1EA5n hi\u1EC7n t\u1EA1i, c\u0169ng l\xE0 \u0111\u1ECBnh danh cho tr\u1EA1\
    ng th\xE1i m\u1EDBi\n      adj[parent].push_back(i);\n    } else {\n      // Truy\
    \ v\u1EA5n lo\u1EA1i 1: Th\xEAm v\xE0o danh s\xE1ch ki\u1EC3m tra c\u1EE7a tr\u1EA1\
    ng th\xE1i cha\n      checks[parent].push_back(i);\n    }\n  }\n\n  // B\u1EAF\
    t \u0111\u1EA7u DFS t\u1EEB tr\u1EA1ng th\xE1i r\u1ED7ng\n  dfs(ROOT_IDX);\n\n\
    \  // In k\u1EBFt qu\u1EA3 theo \u0111\xFAng th\u1EE9 t\u1EF1 c\xE1c truy v\u1EA5\
    n lo\u1EA1i 1\n  for (int i = 0; i < Q; ++i) {\n    if (qs[i].t == 1) {\n    \
    \  cout << ans[i] << \"\\n\";\n    }\n  }\n\n  delete dsu;\n  return 0;\n}"
  dependsOn:
  - misc/macros.h
  - ds/DSURollback.h
  isVerificationFile: true
  path: tests/Persistent_Unionfind.test.cpp
  requiredBy: []
  timestamp: '2025-11-28 00:00:09+07:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: tests/Persistent_Unionfind.test.cpp
layout: document
redirect_from:
- /verify/tests/Persistent_Unionfind.test.cpp
- /verify/tests/Persistent_Unionfind.test.cpp.html
title: tests/Persistent_Unionfind.test.cpp
---
