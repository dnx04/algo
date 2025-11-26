---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"stash/C.cpp\"\n#include <bits/stdc++.h>\n\nusing namespace\
    \ std;\n\n#define pb push_back\n#define eb emplace_back\n#define fi first\n#define\
    \ se second\nusing i64 = long long;\nusing pii = pair<int, int>;\n\nvoid solve()\
    \ {\n  int n, S;\n  cin >> n >> S;\n  set<pii> ed;\n  for (int i = 0; i < n *\
    \ n - 1; ++i) {\n    int u, v;\n    cin >> u >> v;\n    --u, --v;\n    ed.insert({u,\
    \ v});\n  }\n  vector<vector<pair<int, pii>>> g(n * n);\n  auto valid_tile = [&](int\
    \ x, int y) {\n    return 0 <= x && x <= n - 1 && 0 <= y && y <= n - 1;\n  };\n\
    \  for (int i = 0; i < n - 1; ++i) {\n    for (int j = 0; j < n - 1; ++j) {\n\
    \      int u = i * n + j;\n      if (!ed.count({u, u + 1}) && valid_tile(i - 1,\
    \ j)) {\n        g[i * (n - 1) + j].pb({(i - 1) * (n - 1) + j, {u, u + 1}});\n\
    \        g[(i - 1) * (n - 1) + j].pb({i * (n - 1) + j, {u, u + 1}});\n       \
    \ // cout << i * (n - 1) + j << ' ' << (i - 1) * (n - 1) + j << '\\n';\n     \
    \ }\n      if (!ed.count({u, u + n}) && valid_tile(i, j - 1)) {\n        g[i *\
    \ (n - 1) + j].pb({i * (n - 1) + j - 1, {u, u + n}});\n        g[i * (n - 1) +\
    \ j - 1].pb({i * (n - 1) + j, {u, u + n}});\n        // cout << i * (n - 1) +\
    \ j << ' ' << i * (n - 1) + j - 1\n      }\n    }\n  }\n  vector<int> sub((n -\
    \ 1) * (n - 1)), par((n - 1) * (n - 1), -1);\n  vector<pii> ans;\n  auto dfs =\
    \ [&](auto&& self, int u, int p, pii par_edge) -> void {\n    sub[u] = 1;\n  \
    \  for (auto [v, e] : g[u]) {\n      if (v != p) {\n        par[v] = u;\n    \
    \    self(self, v, u);\n        sub[u] += sub[v];\n      }\n    }\n  };\n  for\
    \ (int i = 0; i < n - 1; ++i) {\n    if (!ed.count({i, i + 1})) {\n      dfs(dfs,\
    \ i, -1);\n      // cout << i << '\\n';\n    }\n    if (!ed.count({n * (n - 1)\
    \ + i, n * (n - 1) + i + 1})) {\n      dfs(dfs, (n - 1) * (n - 2) + i, -1);\n\
    \      // cout << (n - 1) * (n - 2) + i << '\\n';\n    }\n    if (!ed.count({i\
    \ * n, i * n + n})) {\n      dfs(dfs, i * (n - 1), -1);\n      // cout << i *\
    \ (n - 1) << '\\n';\n    }\n    if (!ed.count({i * n + n - 1, i * n + n + n -\
    \ 1})) {\n      dfs(dfs, i * (n - 1) + (n - 2), -1);\n      // cout << i * (n\
    \ - 1) + (n - 2) << '\\n';\n    }\n  }\n  vector<pii> cand;\n  // for (int i =\
    \ 0; i < n - 1; ++i) {\n  //   for (int j = 0; j < n - 1; ++j) {\n  //     if\
    \ (sub[i * (n - 1) + j] == S) {\n  //       find_edge(i * (n - 1) + j, par[i *\
    \ (n - 1) + j]);\n  //     }\n  //   }\n  // }\n}\n\nint main() {\n  ios::sync_with_stdio(false);\n\
    \  cin.tie(nullptr);\n  solve();\n}\n"
  code: "#include <bits/stdc++.h>\n\nusing namespace std;\n\n#define pb push_back\n\
    #define eb emplace_back\n#define fi first\n#define se second\nusing i64 = long\
    \ long;\nusing pii = pair<int, int>;\n\nvoid solve() {\n  int n, S;\n  cin >>\
    \ n >> S;\n  set<pii> ed;\n  for (int i = 0; i < n * n - 1; ++i) {\n    int u,\
    \ v;\n    cin >> u >> v;\n    --u, --v;\n    ed.insert({u, v});\n  }\n  vector<vector<pair<int,\
    \ pii>>> g(n * n);\n  auto valid_tile = [&](int x, int y) {\n    return 0 <= x\
    \ && x <= n - 1 && 0 <= y && y <= n - 1;\n  };\n  for (int i = 0; i < n - 1; ++i)\
    \ {\n    for (int j = 0; j < n - 1; ++j) {\n      int u = i * n + j;\n      if\
    \ (!ed.count({u, u + 1}) && valid_tile(i - 1, j)) {\n        g[i * (n - 1) + j].pb({(i\
    \ - 1) * (n - 1) + j, {u, u + 1}});\n        g[(i - 1) * (n - 1) + j].pb({i *\
    \ (n - 1) + j, {u, u + 1}});\n        // cout << i * (n - 1) + j << ' ' << (i\
    \ - 1) * (n - 1) + j << '\\n';\n      }\n      if (!ed.count({u, u + n}) && valid_tile(i,\
    \ j - 1)) {\n        g[i * (n - 1) + j].pb({i * (n - 1) + j - 1, {u, u + n}});\n\
    \        g[i * (n - 1) + j - 1].pb({i * (n - 1) + j, {u, u + n}});\n        //\
    \ cout << i * (n - 1) + j << ' ' << i * (n - 1) + j - 1\n      }\n    }\n  }\n\
    \  vector<int> sub((n - 1) * (n - 1)), par((n - 1) * (n - 1), -1);\n  vector<pii>\
    \ ans;\n  auto dfs = [&](auto&& self, int u, int p, pii par_edge) -> void {\n\
    \    sub[u] = 1;\n    for (auto [v, e] : g[u]) {\n      if (v != p) {\n      \
    \  par[v] = u;\n        self(self, v, u);\n        sub[u] += sub[v];\n      }\n\
    \    }\n  };\n  for (int i = 0; i < n - 1; ++i) {\n    if (!ed.count({i, i + 1}))\
    \ {\n      dfs(dfs, i, -1);\n      // cout << i << '\\n';\n    }\n    if (!ed.count({n\
    \ * (n - 1) + i, n * (n - 1) + i + 1})) {\n      dfs(dfs, (n - 1) * (n - 2) +\
    \ i, -1);\n      // cout << (n - 1) * (n - 2) + i << '\\n';\n    }\n    if (!ed.count({i\
    \ * n, i * n + n})) {\n      dfs(dfs, i * (n - 1), -1);\n      // cout << i *\
    \ (n - 1) << '\\n';\n    }\n    if (!ed.count({i * n + n - 1, i * n + n + n -\
    \ 1})) {\n      dfs(dfs, i * (n - 1) + (n - 2), -1);\n      // cout << i * (n\
    \ - 1) + (n - 2) << '\\n';\n    }\n  }\n  vector<pii> cand;\n  // for (int i =\
    \ 0; i < n - 1; ++i) {\n  //   for (int j = 0; j < n - 1; ++j) {\n  //     if\
    \ (sub[i * (n - 1) + j] == S) {\n  //       find_edge(i * (n - 1) + j, par[i *\
    \ (n - 1) + j]);\n  //     }\n  //   }\n  // }\n}\n\nint main() {\n  ios::sync_with_stdio(false);\n\
    \  cin.tie(nullptr);\n  solve();\n}"
  dependsOn: []
  isVerificationFile: false
  path: stash/C.cpp
  requiredBy: []
  timestamp: '2025-11-26 18:05:06+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: stash/C.cpp
layout: document
redirect_from:
- /library/stash/C.cpp
- /library/stash/C.cpp.html
title: stash/C.cpp
---
