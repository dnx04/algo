---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"strings/AhoCorasick.h\"\nstruct AhoCorasick {\n  static\
    \ const int K = 26;\n  struct Node {\n    int link = 0, el = 0; // suffix link,\
    \ exit link\n    int nxt[K];\n    vector<int> ids; // pattern indices\n    Node()\
    \ { memset(nxt, -1, sizeof(nxt)); }\n  };\n  vector<Node> g;\n  AhoCorasick()\
    \ { g.eb(); }\n  void insert(const string& s, int id) {\n    int u = 0;\n    for\
    \ (char c : s) {\n      int& v = g[u].nxt[c - 'a'];\n      if (v == -1) v = g.size(),\
    \ g.eb();\n      u = v;\n    }\n    g[u].ids.pb(id);\n  }\n  void build() {\n\
    \    queue<int> q; q.push(0);\n    while (q.size()) {\n      int u = q.front();\
    \ q.pop();\n      int l = g[u].link;\n      if (u) g[u].el = g[l].ids.empty()\
    \ ? g[l].el : l;\n\n      for (int i = 0; i < K; ++i) {\n        int& v = g[u].nxt[i];\n\
    \        int next_l = u ? g[l].nxt[i] : 0;\n        if (v == -1) v = next_l; //\
    \ Automaton: O(1) transition\n        else g[v].link = next_l, q.push(v);\n  \
    \    }\n    }\n  }\n  vector<vector<int>> find_all(const string& text) {\n   \
    \ int u = 0;\n    vector<vector<int>> res(text.size());\n    for (int i = 0; i\
    \ < text.size(); ++i) {\n      u = g[u].nxt[text[i] - 'a'];\n      for (int v\
    \ = g[u].ids.empty() ? g[u].el : u; v; v = g[v].el)\n        for (int id : g[v].ids)\
    \ res[i].pb(id);\n    }\n    return res;\n  }\n};\n"
  code: "struct AhoCorasick {\n  static const int K = 26;\n  struct Node {\n    int\
    \ link = 0, el = 0; // suffix link, exit link\n    int nxt[K];\n    vector<int>\
    \ ids; // pattern indices\n    Node() { memset(nxt, -1, sizeof(nxt)); }\n  };\n\
    \  vector<Node> g;\n  AhoCorasick() { g.eb(); }\n  void insert(const string& s,\
    \ int id) {\n    int u = 0;\n    for (char c : s) {\n      int& v = g[u].nxt[c\
    \ - 'a'];\n      if (v == -1) v = g.size(), g.eb();\n      u = v;\n    }\n   \
    \ g[u].ids.pb(id);\n  }\n  void build() {\n    queue<int> q; q.push(0);\n    while\
    \ (q.size()) {\n      int u = q.front(); q.pop();\n      int l = g[u].link;\n\
    \      if (u) g[u].el = g[l].ids.empty() ? g[l].el : l;\n\n      for (int i =\
    \ 0; i < K; ++i) {\n        int& v = g[u].nxt[i];\n        int next_l = u ? g[l].nxt[i]\
    \ : 0;\n        if (v == -1) v = next_l; // Automaton: O(1) transition\n     \
    \   else g[v].link = next_l, q.push(v);\n      }\n    }\n  }\n  vector<vector<int>>\
    \ find_all(const string& text) {\n    int u = 0;\n    vector<vector<int>> res(text.size());\n\
    \    for (int i = 0; i < text.size(); ++i) {\n      u = g[u].nxt[text[i] - 'a'];\n\
    \      for (int v = g[u].ids.empty() ? g[u].el : u; v; v = g[v].el)\n        for\
    \ (int id : g[v].ids) res[i].pb(id);\n    }\n    return res;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: strings/AhoCorasick.h
  requiredBy: []
  timestamp: '2025-12-09 07:33:19+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: strings/AhoCorasick.h
layout: document
redirect_from:
- /library/strings/AhoCorasick.h
- /library/strings/AhoCorasick.h.html
title: strings/AhoCorasick.h
---
