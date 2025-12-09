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
  bundledCode: "#line 1 \"misc/magics.h\"\n#pragma GCC optimize(\"Ofast,unroll-loops\"\
    )       // unroll long, simple loops\n#pragma GCC target(\"avx2,fma\")       \
    \            // vectorizing code\n#pragma GCC target(\"lzcnt,popcnt,abm,bmi,bmi2\"\
    )  // for fast bitset operation\n\nusing namespace __gnu_pbds;  // ordered_set,\
    \ gp_hash_table\nusing namespace __gnu_cxx;   // rope\n\n// fast map\nconst int\
    \ RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();\n\
    struct chash {  // customize hash function for gp_hash_table\n  int operator()(int\
    \ x) const { return x ^ RANDOM; }\n};\ngp_hash_table<int, int, chash> table;\n\
    \n/* ordered set\n    find_by_order(k): returns an iterator to the k-th element\
    \ (0-based)\n    order_of_key(k): returns the number of elements in the set that\
    \ are strictly less than k\n*/\ntemplate <class T>\nusing ordered_set = tree<T,\
    \ null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;\n\n/* \
    \ rope\n    rope <int> cur = v.substr(l, r - l + 1);\n    v.erase(l, r - l + 1);\n\
    \    v.insert(v.mutable_begin(), cur);\n*/\n"
  code: "#pragma GCC optimize(\"Ofast,unroll-loops\")       // unroll long, simple\
    \ loops\n#pragma GCC target(\"avx2,fma\")                   // vectorizing code\n\
    #pragma GCC target(\"lzcnt,popcnt,abm,bmi,bmi2\")  // for fast bitset operation\n\
    \nusing namespace __gnu_pbds;  // ordered_set, gp_hash_table\nusing namespace\
    \ __gnu_cxx;   // rope\n\n// fast map\nconst int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();\n\
    struct chash {  // customize hash function for gp_hash_table\n  int operator()(int\
    \ x) const { return x ^ RANDOM; }\n};\ngp_hash_table<int, int, chash> table;\n\
    \n/* ordered set\n    find_by_order(k): returns an iterator to the k-th element\
    \ (0-based)\n    order_of_key(k): returns the number of elements in the set that\
    \ are strictly less than k\n*/\ntemplate <class T>\nusing ordered_set = tree<T,\
    \ null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;\n\n/* \
    \ rope\n    rope <int> cur = v.substr(l, r - l + 1);\n    v.erase(l, r - l + 1);\n\
    \    v.insert(v.mutable_begin(), cur);\n*/"
  dependsOn: []
  isVerificationFile: false
  path: misc/magics.h
  requiredBy: []
  timestamp: '2025-12-09 07:33:19+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/magics.h
layout: document
redirect_from:
- /library/misc/magics.h
- /library/misc/magics.h.html
title: misc/magics.h
---
