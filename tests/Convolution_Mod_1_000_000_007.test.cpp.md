---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/FFT.h
    title: math/FFT.h
  - icon: ':heavy_check_mark:'
    path: math/NTT.h
    title: math/NTT.h
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
    PROBLEM: https://judge.yosupo.jp/problem/convolution_mod_1000000007
    links:
    - https://judge.yosupo.jp/problem/convolution_mod_1000000007
  bundledCode: "#line 1 \"tests/Convolution_Mod_1_000_000_007.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod_1000000007\"\n\n#line\
    \ 1 \"misc/macros.h\"\n// #ifdef LOCAL\n// #define __GLIBCXX_DEBUG 1\n// #endif\n\
    \n// #pragma GCC optimize(\"Ofast,unroll-loops\")       // unroll long, simple\
    \ loops\n// #pragma GCC target(\"avx2,fma\")                   // vectorizing\
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
    #endif\n#line 1 \"math/FFT.h\"\ntypedef complex<double> C;\ntypedef vector<double>\
    \ vd;\nvoid fft(vector<C>& a) {\n  int n = a.size(), L = 31 - __builtin_clz(n);\n\
    \  static vector<complex<long double>> R(2, 1);\n  static vector<C> rt(2, 1);\n\
    \  for (static int k = 2; k < n; k *= 2) {\n    R.resize(n);\n    rt.resize(n);\n\
    \    auto x = polar(1.0L, acos(-1.0L) / k);\n    for (int i = k; i < 2 * k; ++i)\
    \ rt[i] = R[i] = i & 1 ? R[i / 2] * x : R[i / 2];\n  }\n  vi rev(n);\n  for (int\
    \ i = 0; i < n; ++i) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;\n  for (int i =\
    \ 0; i < n; ++i)\n    if (i < rev[i]) swap(a[i], a[rev[i]]);\n  for (int k = 1;\
    \ k < n; k *= 2) {\n    for (int i = 0; i < n; i += 2 * k) {\n      for (int j\
    \ = 0; j < k; ++j) {\n        auto x = (double*) &rt[j + k], y = (double*) &a[i\
    \ + j + k];\n        C z(x[0] * y[0] - x[1] * y[1], x[0] * y[1] + x[1] * y[0]);\n\
    \        a[i + j + k] = a[i + j] - z;\n        a[i + j] += z;\n      }\n    }\n\
    \  }\n}\nvd convolution(const vd& a, const vd& b) {\n  if (a.empty() || b.empty())\
    \ return {};\n  vd res(sz(a) + sz(b) - 1);\n  int L = 32 - __builtin_clz(sz(res)),\
    \ n = 1 << L;\n  vector<C> in(n), out(n);\n  copy(all(a), begin(in));\n  for (int\
    \ i = 0; i < sz(b); ++i) in[i].imag(b[i]);\n  fft(in);\n  for (C& x : in) x *=\
    \ x;\n  for (int i = 0; i < n; ++i) out[i] = in[-i & (n - 1)] - conj(in[i]);\n\
    \  fft(out);\n  for (int i = 0; i < sz(res); ++i) res[i] = imag(out[i]) / (4 *\
    \ n);\n  return res;\n}\n#line 2 \"math/NTT.h\"\n\ntypedef vector<ll> vl;\ntemplate\
    \ <int M>\nvl convMod(const vl& a, const vl& b) {\n  if (a.empty() || b.empty())\
    \ return {};\n  vl res(sz(a) + sz(b) - 1);\n  int B = 32 - __builtin_clz(sz(res)),\
    \ n = 1 << B, cut = int(sqrt(M));\n  vector<C> L(n), R(n), outs(n), outl(n);\n\
    \  for (int i = 0; i < sz(a); ++i) L[i] = C((int) a[i] / cut, (int) a[i] % cut);\n\
    \  for (int i = 0; i < sz(b); ++i) R[i] = C((int) b[i] / cut, (int) b[i] % cut);\n\
    \  fft(L), fft(R);\n  for (int i = 0; i < n; ++i) {\n    int j = -i & (n - 1);\n\
    \    outl[j] = (L[i] + conj(L[j])) * R[i] / (2.0 * n);\n    outs[j] = (L[i] -\
    \ conj(L[j])) * R[i] / (2.0 * n) / 1i;\n  }\n  fft(outl), fft(outs);\n  for (int\
    \ i = 0; i < sz(res); ++i) {\n    ll av = ll(real(outl[i]) + .5), cv = ll(imag(outs[i])\
    \ + .5);\n    ll bv = ll(imag(outl[i]) + .5) + ll(real(outs[i]) + .5);\n    res[i]\
    \ = ((av % M * cut + bv) % M * cut + cv) % M;\n  }\n  return res;\n}\n#line 5\
    \ \"tests/Convolution_Mod_1_000_000_007.test.cpp\"\n\nvoid solve() {\n  int n,\
    \ m;\n  cin >> n >> m;\n  vl a(n), b(m);\n  for (int i = 0; i < n; ++i) cin >>\
    \ a[i];\n  for (int i = 0; i < m; ++i) cin >> b[i];\n  auto c = convMod<1000000007>(a,\
    \ b);\n  for (ll& x : c) cout << x << ' ';\n}\n\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n\
    \  cin.exceptions(cin.failbit);\n  int tc = 1;\n  //   cin >> tc;\n  for (int\
    \ i = 1; i <= tc; ++i) {\n    solve();\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod_1000000007\"\
    \n\n#include \"../misc/macros.h\"\n#include \"../math/NTT.h\"\n\nvoid solve()\
    \ {\n  int n, m;\n  cin >> n >> m;\n  vl a(n), b(m);\n  for (int i = 0; i < n;\
    \ ++i) cin >> a[i];\n  for (int i = 0; i < m; ++i) cin >> b[i];\n  auto c = convMod<1000000007>(a,\
    \ b);\n  for (ll& x : c) cout << x << ' ';\n}\n\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n\
    \  cin.exceptions(cin.failbit);\n  int tc = 1;\n  //   cin >> tc;\n  for (int\
    \ i = 1; i <= tc; ++i) {\n    solve();\n  }\n}\n"
  dependsOn:
  - misc/macros.h
  - math/NTT.h
  - math/FFT.h
  isVerificationFile: true
  path: tests/Convolution_Mod_1_000_000_007.test.cpp
  requiredBy: []
  timestamp: '2025-11-15 18:26:28+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/Convolution_Mod_1_000_000_007.test.cpp
layout: document
redirect_from:
- /verify/tests/Convolution_Mod_1_000_000_007.test.cpp
- /verify/tests/Convolution_Mod_1_000_000_007.test.cpp.html
title: tests/Convolution_Mod_1_000_000_007.test.cpp
---
