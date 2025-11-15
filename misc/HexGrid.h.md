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
  bundledCode: "#line 1 \"misc/HexGrid.h\"\nint roundCount(int round) { return (6\
    \ * round); }\nint roundSum(int round) { return (6 * round * (round + 1) / 2);\
    \ }\nint findRound(int n) {\n  int res = 1;\n  while (roundSum(res) < n) res++;\n\
    \  return (res);\n}\npair<int, int> cord(int n) {\n  if (n == 0) return (make_pair(0,\
    \ 0));\n  int c = findRound(n);\n  int prev = roundSum(c - 1);\n  if (n <= prev\
    \ + c) return (make_pair(c, n - prev));\n  if (n <= prev + 2 * c) return (make_pair(prev\
    \ + 2 * c - n, c));\n  if (n <= prev + 3 * c) return (make_pair(prev + 2 * c -\
    \ n, prev + 3 * c - n));\n  if (n <= prev + 4 * c) return (make_pair(-c, prev\
    \ + 3 * c - n));\n  if (n <= prev + 5 * c) return (make_pair(n - prev - 5 * c,\
    \ -c));\n  return (make_pair(n - prev - 5 * c, n - prev - 6 * c));\n}\nbool inRound(int\
    \ x, int y, int c) {\n  if (0 <= y && y <= c && x == c) return (true);\n  if (0\
    \ <= x && x <= c && y == c) return (true);\n  if (0 <= y && y <= c && y - x ==\
    \ c) return (true);\n  if (-c <= y && y <= 0 && x == -c) return (true);\n  if\
    \ (-c <= x && x <= 0 && y == -c) return (true);\n  if (0 <= x && x <= c && x -\
    \ y == c) return (true);\n  return (false);\n}\nint findRound(int x, int y) {\n\
    \  int res = 1;\n  while (!inRound(x, y, res)) res++;\n  return (res);\n}\nint\
    \ number(int x, int y) {\n  if (x == 0 && y == 0) return (0);\n  int c = findRound(x,\
    \ y);\n  int prev = roundSum(c - 1);\n  if (1 <= y && y <= c && x == c) return\
    \ (prev + y);\n  if (0 <= x && x <= c && y == c) return (prev + 2 * c - x);\n\
    \  if (0 <= y && y <= c && y - x == c) return (prev + 2 * c - x);\n  if (-c <=\
    \ y && y <= 0 && x == -c) return (prev + 3 * c - y);\n  if (-c <= x && x <= 0\
    \ && y == -c) return (prev + 5 * c + x);\n  return (prev + 5 * c + x);\n}\n"
  code: "int roundCount(int round) { return (6 * round); }\nint roundSum(int round)\
    \ { return (6 * round * (round + 1) / 2); }\nint findRound(int n) {\n  int res\
    \ = 1;\n  while (roundSum(res) < n) res++;\n  return (res);\n}\npair<int, int>\
    \ cord(int n) {\n  if (n == 0) return (make_pair(0, 0));\n  int c = findRound(n);\n\
    \  int prev = roundSum(c - 1);\n  if (n <= prev + c) return (make_pair(c, n -\
    \ prev));\n  if (n <= prev + 2 * c) return (make_pair(prev + 2 * c - n, c));\n\
    \  if (n <= prev + 3 * c) return (make_pair(prev + 2 * c - n, prev + 3 * c - n));\n\
    \  if (n <= prev + 4 * c) return (make_pair(-c, prev + 3 * c - n));\n  if (n <=\
    \ prev + 5 * c) return (make_pair(n - prev - 5 * c, -c));\n  return (make_pair(n\
    \ - prev - 5 * c, n - prev - 6 * c));\n}\nbool inRound(int x, int y, int c) {\n\
    \  if (0 <= y && y <= c && x == c) return (true);\n  if (0 <= x && x <= c && y\
    \ == c) return (true);\n  if (0 <= y && y <= c && y - x == c) return (true);\n\
    \  if (-c <= y && y <= 0 && x == -c) return (true);\n  if (-c <= x && x <= 0 &&\
    \ y == -c) return (true);\n  if (0 <= x && x <= c && x - y == c) return (true);\n\
    \  return (false);\n}\nint findRound(int x, int y) {\n  int res = 1;\n  while\
    \ (!inRound(x, y, res)) res++;\n  return (res);\n}\nint number(int x, int y) {\n\
    \  if (x == 0 && y == 0) return (0);\n  int c = findRound(x, y);\n  int prev =\
    \ roundSum(c - 1);\n  if (1 <= y && y <= c && x == c) return (prev + y);\n  if\
    \ (0 <= x && x <= c && y == c) return (prev + 2 * c - x);\n  if (0 <= y && y <=\
    \ c && y - x == c) return (prev + 2 * c - x);\n  if (-c <= y && y <= 0 && x ==\
    \ -c) return (prev + 3 * c - y);\n  if (-c <= x && x <= 0 && y == -c) return (prev\
    \ + 5 * c + x);\n  return (prev + 5 * c + x);\n}"
  dependsOn: []
  isVerificationFile: false
  path: misc/HexGrid.h
  requiredBy: []
  timestamp: '2025-11-15 18:26:28+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/HexGrid.h
layout: document
redirect_from:
- /library/misc/HexGrid.h
- /library/misc/HexGrid.h.html
title: misc/HexGrid.h
---
