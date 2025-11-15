---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: includes.h
    title: includes.h
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/2_Sat.test.cpp
    title: tests/2_Sat.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Assignment_Problem.test.cpp
    title: tests/Assignment_Problem.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Bitwise_And_Convolution.test.cpp
    title: tests/Bitwise_And_Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Bitwise_Xor_Convolution.test.cpp
    title: tests/Bitwise_Xor_Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Closest_Pair_of_Points.test.cpp
    title: tests/Closest_Pair_of_Points.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Convolution.test.cpp
    title: tests/Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Convolution_Mod_1_000_000_007.test.cpp
    title: tests/Convolution_Mod_1_000_000_007.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Deque.test.cpp
    title: tests/Deque.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Deque_Operate_All_Composite.test.cpp
    title: tests/Deque_Operate_All_Composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Directed_MST.test.cpp
    title: tests/Directed_MST.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Discrete_Logarithm.test.cpp
    title: tests/Discrete_Logarithm.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Dominator_Tree.test.cpp
    title: tests/Dominator_Tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Enumerate_Cliques.test.cpp
    title: tests/Enumerate_Cliques.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/General_Matching.test.cpp
    title: tests/General_Matching.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Intersection_of_F2_vector_spaces.test.cpp
    title: tests/Intersection_of_F2_vector_spaces.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Matching_on_Bipartite_Graph_HopcroftKarp.test.cpp
    title: tests/Matching_on_Bipartite_Graph_HopcroftKarp.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Maximum_Independent_Set.test.cpp
    title: tests/Maximum_Independent_Set.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Number_of_Subsequences.test.cpp
    title: tests/Number_of_Subsequences.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Point_Set_Range_Composite.test.cpp
    title: tests/Point_Set_Range_Composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Primality_Test.test.cpp
    title: tests/Primality_Test.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Sort_Points_by_Argument.test.cpp
    title: tests/Sort_Points_by_Argument.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Sqrt_Mod.test.cpp
    title: tests/Sqrt_Mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Static_Convex_Hull.test.cpp
    title: tests/Static_Convex_Hull.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Sum_of_Floor_of_Linear.test.cpp
    title: tests/Sum_of_Floor_of_Linear.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/Vertex_Add_Path_Sum.test.cpp
    title: tests/Vertex_Add_Path_Sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"misc/macros.h\"\n// #ifdef LOCAL\n// #define __GLIBCXX_DEBUG\
    \ 1\n// #endif\n\n// #pragma GCC optimize(\"Ofast,unroll-loops\")       // unroll\
    \ long, simple loops\n// #pragma GCC target(\"avx2,fma\")                   //\
    \ vectorizing code\n// #pragma GCC target(\"lzcnt,popcnt,abm,bmi,bmi2\")  // for\
    \ fast bitset operation\n\n#include <bits/extc++.h>\n\n#include <tr2/dynamic_bitset>\n\
    \nusing namespace std;\nusing namespace __gnu_pbds;  // ordered_set, gp_hash_table\n\
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
    #endif\n"
  code: "// #ifdef LOCAL\n// #define __GLIBCXX_DEBUG 1\n// #endif\n\n// #pragma GCC\
    \ optimize(\"Ofast,unroll-loops\")       // unroll long, simple loops\n// #pragma\
    \ GCC target(\"avx2,fma\")                   // vectorizing code\n// #pragma GCC\
    \ target(\"lzcnt,popcnt,abm,bmi,bmi2\")  // for fast bitset operation\n\n#include\
    \ <bits/extc++.h>\n\n#include <tr2/dynamic_bitset>\n\nusing namespace std;\nusing\
    \ namespace __gnu_pbds;  // ordered_set, gp_hash_table\nusing namespace __gnu_cxx;\
    \   // rope, cut and insert subarray in O(logn)\n\n// for templates to work\n\
    #define all(s) s.begin(), s.end()\n#define sz(x) (int) (x).size()\n#define pb\
    \ push_back\n#define eb emplace_back\ntypedef long long ll;\ntypedef unsigned\
    \ long long ull;\ntypedef pair<int, int> pii;\ntypedef vector<int> vi;\n\n// fast\
    \ map\nconst int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();\n\
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
    #endif"
  dependsOn: []
  isVerificationFile: false
  path: misc/macros.h
  requiredBy:
  - includes.h
  timestamp: '2025-11-15 18:26:28+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/Bitwise_Xor_Convolution.test.cpp
  - tests/Static_Convex_Hull.test.cpp
  - tests/2_Sat.test.cpp
  - tests/Deque_Operate_All_Composite.test.cpp
  - tests/Deque.test.cpp
  - tests/General_Matching.test.cpp
  - tests/Maximum_Independent_Set.test.cpp
  - tests/Dominator_Tree.test.cpp
  - tests/Matching_on_Bipartite_Graph_HopcroftKarp.test.cpp
  - tests/Closest_Pair_of_Points.test.cpp
  - tests/Primality_Test.test.cpp
  - tests/Sqrt_Mod.test.cpp
  - tests/Vertex_Add_Path_Sum.test.cpp
  - tests/Discrete_Logarithm.test.cpp
  - tests/Intersection_of_F2_vector_spaces.test.cpp
  - tests/Sort_Points_by_Argument.test.cpp
  - tests/Convolution.test.cpp
  - tests/Enumerate_Cliques.test.cpp
  - tests/Point_Set_Range_Composite.test.cpp
  - tests/Assignment_Problem.test.cpp
  - tests/Directed_MST.test.cpp
  - tests/Bitwise_And_Convolution.test.cpp
  - tests/Convolution_Mod_1_000_000_007.test.cpp
  - tests/Number_of_Subsequences.test.cpp
  - tests/Sum_of_Floor_of_Linear.test.cpp
documentation_of: misc/macros.h
layout: document
redirect_from:
- /library/misc/macros.h
- /library/misc/macros.h.html
title: misc/macros.h
---
