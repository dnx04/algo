---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/2SAT.h
    title: graph/2SAT.h
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
    PROBLEM: https://judge.yosupo.jp/problem/two_sat
    links:
    - https://judge.yosupo.jp/problem/two_sat
  bundledCode: "#line 1 \"tests/2_Sat.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\
    \n\n#line 1 \"misc/macros.h\"\n// #ifdef LOCAL\n// #define __GLIBCXX_DEBUG 1\n\
    // #endif\n\n// #pragma GCC optimize(\"Ofast,unroll-loops\")       // unroll long,\
    \ simple loops\n// #pragma GCC target(\"avx2,fma\")                   // vectorizing\
    \ code\n// #pragma GCC target(\"lzcnt,popcnt,abm,bmi,bmi2\")  // for fast bitset\
    \ operation\n\n#include <bits/extc++.h>\n\n#include <tr2/dynamic_bitset>\n\nusing\
    \ namespace std;\nusing namespace __gnu_pbds;  // ordered_set, gp_hash_table\n\
    using namespace __gnu_cxx;   // rope, cut and insert subarray in O(logn)\n\n//\
    \ for templates to work\n#define all(s) s.begin(), s.end()\n#define sz(x) (int)\
    \ (x).size()\n#define pb push_back\n#define eb emplace_back\ntypedef long long\
    \ ll;\ntypedef unsigned long long ull;\ntypedef pair<int, int> pii;\ntypedef vector<int>\
    \ vi;\n\n// fast map\nconst int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();\n\
    struct chash {  // customize hash function for gp_hash_table\n  int operator()(int\
    \ x) const { return x ^ RANDOM; }\n};\ngp_hash_table<int, int, chash> table;\n\
    \n/* ordered set\n    find_by_order(k): returns an iterator to the k-th element\
    \ (0-based)\n    order_of_key(k): returns the number of elements in the set that\
    \ are strictly less than k\n*/\ntemplate <typename T>\nusing ordered_set = tree<T,\
    \ null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;\n\n// dynamic\
    \ bitset\nusing bs = tr2::dynamic_bitset<uint64_t>;\n\n/*  rope\n    rope <int>\
    \ cur = v.substr(l, r - l + 1);\n    v.erase(l, r - l + 1);\n    v.insert(v.mutable_begin(),\
    \ cur);\n*/\n\n#define CONCAT_(x, y) x##y\n#define CONCAT(x, y) CONCAT_(x, y)\n\
    #ifdef LOCAL\n#define clog cerr << setw(__db_level * 2) << setfill(' ') << \"\"\
    \ << setw(0)\n#define DB() debug_block CONCAT(dbbl, __LINE__)\nint __db_level\
    \ = 0;\nstruct debug_block {\n  debug_block() {\n    clog << \"{\" << endl;\n\
    \    ++__db_level;\n  }\n  ~debug_block() {\n    --__db_level;\n    clog << \"\
    }\" << endl;\n  }\n};\n#else\n#define clog \\\n  if (0) cerr\n#define DB(...)\n\
    #endif\n#line 1 \"graph/2SAT.h\"\n/**\n * Usage: TwoSat ts(number of boolean variables);\n\
    \ *  ts.either(0, ~3); // Var 0 is true or var 3 is false\n *  ts.setValue(2);\
    \ // Var 2 is true\n *  ts.atMostOne({0,~1,2}); // <= 1 of vars 0, ~1 and 2 are\
    \ true\n *  ts.solve(); // Returns true iff it is solvable\n *  ts.values[0..N-1]\
    \ holds the assigned values to the vars\n */\nstruct TwoSat {\n  int N;\n  vector<vi>\
    \ gr;\n  vi values;  // 0 = false, 1 = true\n\n  TwoSat(int n = 0) : N(n), gr(2\
    \ * n) {}\n\n  int addVar() {  // (optional)\n    gr.emplace_back();\n    gr.emplace_back();\n\
    \    return N++;\n  }\n\n  void either(int f, int j) {\n    f = max(2 * f, -1\
    \ - 2 * f);\n    j = max(2 * j, -1 - 2 * j);\n    gr[f].push_back(j ^ 1);\n  \
    \  gr[j].push_back(f ^ 1);\n  }\n  void setValue(int x) { either(x, x); }\n\n\
    \  void atMostOne(const vi& li) {  // (optional)\n    if (sz(li) <= 1) return;\n\
    \    int cur = ~li[0];\n    for (int i = 2; i < sz(li); ++i) {\n      int next\
    \ = addVar();\n      either(cur, ~li[i]);\n      either(cur, next);\n      either(~li[i],\
    \ next);\n      cur = ~next;\n    }\n    either(cur, ~li[1]);\n  }\n\n  vi val,\
    \ comp, z;\n  int time = 0;\n  int dfs(int i) {\n    int low = val[i] = ++time,\
    \ x;\n    z.push_back(i);\n    for (int e : gr[i])\n      if (!comp[e]) low =\
    \ min(low, val[e] ?: dfs(e));\n    if (low == val[i]) {\n      do {\n        x\
    \ = z.back();\n        z.pop_back();\n        comp[x] = low;\n        if (values[x\
    \ >> 1] == -1) values[x >> 1] = x & 1;\n      } while (x != i);\n    }\n    return\
    \ val[i] = low;\n  }\n\n  bool solve() {\n    values.assign(N, -1);\n    val.assign(2\
    \ * N, 0);\n    comp = val;\n    for (int i = 0; i < 2 * N; ++i)\n      if (!comp[i])\
    \ dfs(i);\n    for (int i = 0; i < N; ++i)\n      if (comp[2 * i] == comp[2 *\
    \ i + 1]) return 0;\n    return 1;\n  }\n};\n#line 5 \"tests/2_Sat.test.cpp\"\n\
    \nvoid solve() {\n  string rid;\n  cin >> rid >> rid;\n  int n, m;\n  cin >> n\
    \ >> m;\n  TwoSat ts(n);\n  for (int i = 0; i < m; ++i) {\n    int a, b, rid;\n\
    \    cin >> a >> b >> rid;\n    if (a < 0)\n      a = ~(-a - 1);\n    else\n \
    \     --a;\n    if (b < 0)\n      b = ~(-b - 1);\n    else\n      --b;\n    ts.either(a,\
    \ b);\n  }\n  if (ts.solve()) {\n    cout << \"s SATISFIABLE\\n\";\n    cout <<\
    \ \"v \";\n    for (int i = 0; i < n; ++i) cout << (ts.values[i] ? i + 1 : -i\
    \ - 1) << \" \";\n    cout << \"0\\n\";\n  } else {\n    cout << \"s UNSATISFIABLE\\\
    n\";\n  }\n}\n\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n  cin.exceptions(cin.failbit);\n\
    \  int tc = 1;\n  // cin >> tc;\n  for (int i = 1; i <= tc; ++i) {\n    solve();\n\
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
  timestamp: '2025-11-15 18:26:28+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/2_Sat.test.cpp
layout: document
redirect_from:
- /verify/tests/2_Sat.test.cpp
- /verify/tests/2_Sat.test.cpp.html
title: tests/2_Sat.test.cpp
---
