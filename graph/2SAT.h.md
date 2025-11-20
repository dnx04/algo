---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/2_Sat.test.cpp
    title: tests/2_Sat.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/2SAT.h\"\n/**\n * Usage: TwoSat ts(number of boolean\
    \ variables);\n *  ts.either(0, ~3); // Var 0 is true or var 3 is false\n *  ts.setValue(2);\
    \ // Var 2 is true\n *  ts.atMostOne({0,~1,2}); // <= 1 of vars 0, ~1 and 2 are\
    \ true\n *  ts.solve(); // Returns true iff it is solvable\n *  ts.values[0..N-1]\
    \ holds the assigned values to the vars\n */\nstruct TwoSat {\n  int N;\n  vector<vi>\
    \ gr;\n  vi values;  // 0 = false, 1 = true\n  TwoSat(int n = 0) : N(n), gr(2\
    \ * n) {}\n  int addVar() {  // (optional)\n    gr.eb(), gr.eb();\n    return\
    \ N++;\n  }\n  void either(int f, int j) {\n    f = max(2 * f, -1 - 2 * f), j\
    \ = max(2 * j, -1 - 2 * j);\n    gr[f].eb(j ^ 1), gr[j].eb(f ^ 1);\n  }\n  void\
    \ setValue(int x) { either(x, x); }\n  void atMostOne(const vi& li) {  // (optional)\n\
    \    if (sz(li) <= 1) return;\n    int cur = ~li[0];\n    for (int i = 2; i <\
    \ sz(li); ++i) {\n      int next = addVar();\n      either(cur, ~li[i]), either(cur,\
    \ next), either(~li[i], next);\n      cur = ~next;\n    }\n    either(cur, ~li[1]);\n\
    \  }\n  vi val, comp, z;\n  int time = 0;\n  int dfs(int i) {\n    int low = val[i]\
    \ = ++time, x;\n    z.push_back(i);\n    for (int e : gr[i]) {\n      if (!comp[e])\
    \ low = min(low, val[e] ?: dfs(e));\n    }\n    if (low == val[i]) {\n      do\
    \ {\n        x = z.back(), z.pop_back(), comp[x] = low;\n        if (values[x\
    \ >> 1] == -1) values[x >> 1] = x & 1;\n      } while (x != i);\n    }\n    return\
    \ val[i] = low;\n  }\n  bool solve() {\n    values.assign(N, -1);\n    val.assign(2\
    \ * N, 0);\n    comp = val;\n    for (int i = 0; i < 2 * N; ++i)\n      if (!comp[i])\
    \ dfs(i);\n    for (int i = 0; i < N; ++i)\n      if (comp[2 * i] == comp[2 *\
    \ i + 1]) return 0;\n    return 1;\n  }\n};\n"
  code: "/**\n * Usage: TwoSat ts(number of boolean variables);\n *  ts.either(0,\
    \ ~3); // Var 0 is true or var 3 is false\n *  ts.setValue(2); // Var 2 is true\n\
    \ *  ts.atMostOne({0,~1,2}); // <= 1 of vars 0, ~1 and 2 are true\n *  ts.solve();\
    \ // Returns true iff it is solvable\n *  ts.values[0..N-1] holds the assigned\
    \ values to the vars\n */\nstruct TwoSat {\n  int N;\n  vector<vi> gr;\n  vi values;\
    \  // 0 = false, 1 = true\n  TwoSat(int n = 0) : N(n), gr(2 * n) {}\n  int addVar()\
    \ {  // (optional)\n    gr.eb(), gr.eb();\n    return N++;\n  }\n  void either(int\
    \ f, int j) {\n    f = max(2 * f, -1 - 2 * f), j = max(2 * j, -1 - 2 * j);\n \
    \   gr[f].eb(j ^ 1), gr[j].eb(f ^ 1);\n  }\n  void setValue(int x) { either(x,\
    \ x); }\n  void atMostOne(const vi& li) {  // (optional)\n    if (sz(li) <= 1)\
    \ return;\n    int cur = ~li[0];\n    for (int i = 2; i < sz(li); ++i) {\n   \
    \   int next = addVar();\n      either(cur, ~li[i]), either(cur, next), either(~li[i],\
    \ next);\n      cur = ~next;\n    }\n    either(cur, ~li[1]);\n  }\n  vi val,\
    \ comp, z;\n  int time = 0;\n  int dfs(int i) {\n    int low = val[i] = ++time,\
    \ x;\n    z.push_back(i);\n    for (int e : gr[i]) {\n      if (!comp[e]) low\
    \ = min(low, val[e] ?: dfs(e));\n    }\n    if (low == val[i]) {\n      do {\n\
    \        x = z.back(), z.pop_back(), comp[x] = low;\n        if (values[x >> 1]\
    \ == -1) values[x >> 1] = x & 1;\n      } while (x != i);\n    }\n    return val[i]\
    \ = low;\n  }\n  bool solve() {\n    values.assign(N, -1);\n    val.assign(2 *\
    \ N, 0);\n    comp = val;\n    for (int i = 0; i < 2 * N; ++i)\n      if (!comp[i])\
    \ dfs(i);\n    for (int i = 0; i < N; ++i)\n      if (comp[2 * i] == comp[2 *\
    \ i + 1]) return 0;\n    return 1;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/2SAT.h
  requiredBy: []
  timestamp: '2025-11-20 10:20:22+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/2_Sat.test.cpp
documentation_of: graph/2SAT.h
layout: document
redirect_from:
- /library/graph/2SAT.h
- /library/graph/2SAT.h.html
title: graph/2SAT.h
---
