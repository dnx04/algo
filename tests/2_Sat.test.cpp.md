---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/2SAT.h
    title: graph/2SAT.h
  - icon: ':question:'
    path: misc/macros.h
    title: misc/macros.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/two_sat
    links:
    - https://judge.yosupo.jp/problem/two_sat
  bundledCode: "#line 1 \"tests/2_Sat.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\
    \n\n#line 1 \"misc/macros.h\"\n// #pragma GCC optimize(\"Ofast,unroll-loops\"\
    )       // unroll long, simple loops\n// #pragma GCC target(\"avx2,fma\")    \
    \               // vectorizing code\n// #pragma GCC target(\"lzcnt,popcnt,abm,bmi,bmi2\"\
    )  // for fast bitset operation\n\n#include <bits/extc++.h>\n\nusing namespace\
    \ std;\nusing namespace __gnu_pbds;  // ordered_set, gp_hash_table\n// using namespace\
    \ __gnu_cxx; // rope\n\n// for templates to work\n#define all(x) (x).begin(),\
    \ (x).end()\n#define len(x) (int) (x).size()\n#define pb push_back\n#define eb\
    \ emplace_back\nusing i32 = int32_t;\nusing u32 = uint32_t;\nusing i64 = int64_t;\n\
    using u64 = uint64_t;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\nusing\
    \ ld = long double;\nusing pii = pair<i32, i32>;\nusing vi = vector<i32>;\n\n\
    // fast map\nconst int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();\n\
    struct chash {  // customize hash function for gp_hash_table\n  int operator()(int\
    \ x) const { return x ^ RANDOM; }\n};\ngp_hash_table<int, int, chash> table;\n\
    \n/* ordered set\n    find_by_order(k): returns an iterator to the k-th element\
    \ (0-based)\n    order_of_key(k): returns the number of elements in the set that\
    \ are strictly less than k\n*/\ntemplate <class T>\nusing ordered_set = tree<T,\
    \ null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;\n\n/* \
    \ rope\n    rope <int> cur = v.substr(l, r - l + 1);\n    v.erase(l, r - l + 1);\n\
    \    v.insert(v.mutable_begin(), cur);\n*/\n#line 1 \"graph/2SAT.h\"\n/**\n *\
    \ Usage: TwoSat ts(number of boolean variables);\n *  ts.either(0, ~3); // Var\
    \ 0 is true or var 3 is false\n *  ts.setValue(2); // Var 2 is true\n *  ts.atMostOne({0,~1,2});\
    \ // <= 1 of vars 0, ~1 and 2 are true\n *  ts.solve(); // Returns true iff it\
    \ is solvable\n *  ts.values[0..N-1] holds the assigned values to the vars\n */\n\
    struct TwoSat {\n  int N;\n  vector<vi> gr;\n  vi values;  // 0 = false, 1 = true\n\
    \  TwoSat(int n = 0) : N(n), gr(2 * n) {}\n  int addVar() {  // (optional)\n \
    \   gr.eb(), gr.eb();\n    return N++;\n  }\n  void either(int f, int j) {\n \
    \   f = max(2 * f, -1 - 2 * f), j = max(2 * j, -1 - 2 * j);\n    gr[f].eb(j ^\
    \ 1), gr[j].eb(f ^ 1);\n  }\n  void setValue(int x) { either(x, x); }\n  void\
    \ atMostOne(const vi& li) {  // (optional)\n    if (len(li) <= 1) return;\n  \
    \  int cur = ~li[0];\n    for (int i = 2; i < len(li); ++i) {\n      int next\
    \ = addVar();\n      either(cur, ~li[i]), either(cur, next), either(~li[i], next);\n\
    \      cur = ~next;\n    }\n    either(cur, ~li[1]);\n  }\n  vi val, comp, z;\n\
    \  int time = 0;\n  int dfs(int i) {\n    int low = val[i] = ++time, x;\n    z.push_back(i);\n\
    \    for (int e : gr[i]) {\n      if (!comp[e]) low = min(low, val[e] ?: dfs(e));\n\
    \    }\n    if (low == val[i]) {\n      do {\n        x = z.back(), z.pop_back(),\
    \ comp[x] = low;\n        if (values[x >> 1] == -1) values[x >> 1] = x & 1;\n\
    \      } while (x != i);\n    }\n    return val[i] = low;\n  }\n  bool solve()\
    \ {\n    values.assign(N, -1);\n    val.assign(2 * N, 0);\n    comp = val;\n \
    \   for (int i = 0; i < 2 * N; ++i)\n      if (!comp[i]) dfs(i);\n    for (int\
    \ i = 0; i < N; ++i)\n      if (comp[2 * i] == comp[2 * i + 1]) return 0;\n  \
    \  return 1;\n  }\n};\n#line 5 \"tests/2_Sat.test.cpp\"\n\nvoid solve() {\n  string\
    \ rid;\n  cin >> rid >> rid;\n  int n, m;\n  cin >> n >> m;\n  TwoSat ts(n);\n\
    \  for (int i = 0; i < m; ++i) {\n    int a, b, rid;\n    cin >> a >> b >> rid;\n\
    \    if (a < 0)\n      a = ~(-a - 1);\n    else\n      --a;\n    if (b < 0)\n\
    \      b = ~(-b - 1);\n    else\n      --b;\n    ts.either(a, b);\n  }\n  if (ts.solve())\
    \ {\n    cout << \"s SATISFIABLE\\n\";\n    cout << \"v \";\n    for (int i =\
    \ 0; i < n; ++i) cout << (ts.values[i] ? i + 1 : -i - 1) << \" \";\n    cout <<\
    \ \"0\\n\";\n  } else {\n    cout << \"s UNSATISFIABLE\\n\";\n  }\n}\n\nint main()\
    \ {\n  cin.tie(0)->sync_with_stdio(0);\n  cin.exceptions(cin.failbit);\n  int\
    \ tc = 1;\n  // cin >> tc;\n  for (int i = 1; i <= tc; ++i) {\n    solve();\n\
    \  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\n\n#include \"\
    ../misc/macros.h\"\n#include \"../graph/2SAT.h\"\n\nvoid solve() {\n  string rid;\n\
    \  cin >> rid >> rid;\n  int n, m;\n  cin >> n >> m;\n  TwoSat ts(n);\n  for (int\
    \ i = 0; i < m; ++i) {\n    int a, b, rid;\n    cin >> a >> b >> rid;\n    if\
    \ (a < 0)\n      a = ~(-a - 1);\n    else\n      --a;\n    if (b < 0)\n      b\
    \ = ~(-b - 1);\n    else\n      --b;\n    ts.either(a, b);\n  }\n  if (ts.solve())\
    \ {\n    cout << \"s SATISFIABLE\\n\";\n    cout << \"v \";\n    for (int i =\
    \ 0; i < n; ++i) cout << (ts.values[i] ? i + 1 : -i - 1) << \" \";\n    cout <<\
    \ \"0\\n\";\n  } else {\n    cout << \"s UNSATISFIABLE\\n\";\n  }\n}\n\nint main()\
    \ {\n  cin.tie(0)->sync_with_stdio(0);\n  cin.exceptions(cin.failbit);\n  int\
    \ tc = 1;\n  // cin >> tc;\n  for (int i = 1; i <= tc; ++i) {\n    solve();\n\
    \  }\n}\n"
  dependsOn:
  - misc/macros.h
  - graph/2SAT.h
  isVerificationFile: true
  path: tests/2_Sat.test.cpp
  requiredBy: []
  timestamp: '2026-10-03 15:27:40+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/2_Sat.test.cpp
layout: document
redirect_from:
- /verify/tests/2_Sat.test.cpp
- /verify/tests/2_Sat.test.cpp.html
title: tests/2_Sat.test.cpp
---
