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
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/work/algo/algo/.venv/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/home/runner/work/algo/algo/.venv/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/home/runner/work/algo/algo/.venv/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ misc/template.cpp: line 5: unable to process #include in #if / #ifdef / #ifndef\
    \ other than include guards\n"
  code: "#include <bits/extc++.h>\n#include <sys/types.h>\n\n#ifdef LOCAL\n#include\
    \ \"algo/misc/prettyprint.hpp\"\n#endif\n\nusing namespace std;\n\n#define len(s)\
    \ (int)s.size()\n#define all(s) s.begin(), s.end()\n\nusing i64 = int64_t;\nusing\
    \ u64 = u_int64_t;\n\nvoid solve(){}\n\nsigned main() {\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(0);\n    solve();\n}"
  dependsOn: []
  isVerificationFile: false
  path: misc/template.cpp
  requiredBy: []
  timestamp: '2026-09-28 04:24:39+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/template.cpp
layout: document
redirect_from:
- /library/misc/template.cpp
- /library/misc/template.cpp.html
title: misc/template.cpp
---
