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
  bundledCode: "#line 1 \"misc/SOSDP.cpp\"\n// SOS xu\xF4i - z(f(s))\nfor (int k =\
    \ 0; k < n; k++)\n  for (int mask = 0; mask < (1 << n); mask++)\n    if (mask\
    \ & (1 << k)) dp[mask] += dp[mask ^ (1 << k)];\n\n// H\xE0m \u0111an d\u1EA5u\
    \ - o(f(s))\nfor (int mask = 0; mask < (1 << n); mask++)\n  sos[mask] = f[mask]\
    \ * (__builtin_parity(mask) ? -1 : 1);\n\n// SOS ng\u01B0\u1EE3c - mu(f(s)) =\
    \ ozo(f(s))\n// z(mu(f)) = mu(z(f)) = f\n\n// SOS truy h\u1ED3i ch\xEDnh n\xF3\
    : f(S) = h(sum f(T), T subset S) + a(S)\nfor (int mask = 0; mask < (1 << n); mask++)\
    \ {\n  dp[mask][0] = 0;  // tr\u01B0\u1EDDng h\u1EE3p c\u01A1 s\u1EDF\n  for (int\
    \ k = 1; k <= n; k++) {\n    // t\xEDnh Sum over Proper Subset\n    if (mask &\
    \ (1 << (k - 1))) {\n      int sub = mask ^ (1 << (k - 1));\n      dp[mask][k]\
    \ = dp[mask][k - 1] + dp[sub][k - 1] + f[sub];\n    } else\n      dp[mask][k]\
    \ = dp[mask][k - 1];\n  }\n  f[mask] = h(dp[mask][n]) + a[mask];  // t\xEDnh f\n\
    }\n\n/*\n  SOS 2 h\xE0m g\u1ECDi ch\xE9o nhau\n  f(S) = h1(sum g(T), T subset\
    \ S) + a(S)\n  g(S) = h2(sum f(T), T subseteq S) + b(S)\n*/\nfor (int mask = 0;\
    \ mask < (1 << n); mask++) {\n  // t\xEDnh dpG v\xE0 f\n  for (int k = 1; k <=\
    \ n; k++) {\n    if (mask & (1 << (k - 1))) {  // truy h\u1ED3i theo ki\u1EC3\
    u proper subset\n      int sub = mask ^ (1 << (k - 1));\n      dpG[mask][k] =\
    \ dpG[mask][k - 1] + dpG[sub][k - 1] + g[sub];\n    } else\n      dpG[mask][k]\
    \ = dpG[mask][k - 1];\n  }\n  f[mask] = h1(dpG[mask][n]) + a[mask];\n\n  // t\xED\
    nh dpF v\xE0 g\n  dpF[mask][0] = f[mask];\n  for (int k = 1; k <= n; k++) {\n\
    \    if (mask & (1 << (k - 1)))  // truy h\u1ED3i theo ki\u1EC3u subset\n    \
    \  dpF[mask][k] = dpF[mask][k - 1] + dpF[mask ^ (1 << (k - 1))][k - 1];\n    else\n\
    \      dpF[mask][k] = dpF[mask][k - 1];\n  }\n  g[mask] = h2(dpF[mask][n]) + b[mask];\n\
    }\n\n// T\xEDnh t\xEDch ch\u1EADp SOS c\u1EE7a 2 h\xE0m f, g\n// Make fhat[][]\
    \ = {0} and ghat[][] = {0}\nfor (int mask = 0; mask < (1 << N); mask++) {\n  fhat[__builtin_popcount(mask)][mask]\
    \ = f[mask];\n  ghat[__builtin_popcount(mask)][mask] = g[mask];\n}\n\n// Apply\
    \ zeta transform on fhat[][] and ghat[][]\nfor (int i = 0; i < N; i++) {\n  for\
    \ (int j = 0; j < N; j++) {\n    for (int mask = 0; mask < (1 << N); mask++) {\n\
    \      if ((mask & (1 << j)) != 0) {\n        fhat[i][mask] += fhat[i][mask ^\
    \ (1 << j)];\n        ghat[i][mask] += ghat[i][mask ^ (1 << j)];\n      }\n  \
    \  }\n  }\n}\n\n// Do the convolution and store into h[][] = {0}\nfor (int mask\
    \ = 0; mask < (1 << N); mask++) {\n  for (int i = 0; i < N; i++) {\n    for (int\
    \ j = 0; j <= i; j++) {\n      h[i][mask] += fhat[j][mask] * ghat[i - j][mask];\n\
    \    }\n  }\n}\n\n// Apply inverse SOS dp on h[][]\nfor (int i = 0; i < N; i++)\
    \ {\n  for (int j = 0; j < N; j++) {\n    for (int mask = 0; mask < (1 << N);\
    \ mask++) {\n      if ((mask & (1 << j)) != 0) {\n        h[i][mask] -= h[i][mask\
    \ ^ (1 << j)];\n      }\n    }\n  }\n}\nfor (int mask = 0; mask < (1 << N); mask++)\n\
    \  fog[mask] = h[__builtin_popcount(mask)][mask];\n"
  code: "// SOS xu\xF4i - z(f(s))\nfor (int k = 0; k < n; k++)\n  for (int mask =\
    \ 0; mask < (1 << n); mask++)\n    if (mask & (1 << k)) dp[mask] += dp[mask ^\
    \ (1 << k)];\n\n// H\xE0m \u0111an d\u1EA5u - o(f(s))\nfor (int mask = 0; mask\
    \ < (1 << n); mask++)\n  sos[mask] = f[mask] * (__builtin_parity(mask) ? -1 :\
    \ 1);\n\n// SOS ng\u01B0\u1EE3c - mu(f(s)) = ozo(f(s))\n// z(mu(f)) = mu(z(f))\
    \ = f\n\n// SOS truy h\u1ED3i ch\xEDnh n\xF3: f(S) = h(sum f(T), T subset S) +\
    \ a(S)\nfor (int mask = 0; mask < (1 << n); mask++) {\n  dp[mask][0] = 0;  //\
    \ tr\u01B0\u1EDDng h\u1EE3p c\u01A1 s\u1EDF\n  for (int k = 1; k <= n; k++) {\n\
    \    // t\xEDnh Sum over Proper Subset\n    if (mask & (1 << (k - 1))) {\n   \
    \   int sub = mask ^ (1 << (k - 1));\n      dp[mask][k] = dp[mask][k - 1] + dp[sub][k\
    \ - 1] + f[sub];\n    } else\n      dp[mask][k] = dp[mask][k - 1];\n  }\n  f[mask]\
    \ = h(dp[mask][n]) + a[mask];  // t\xEDnh f\n}\n\n/*\n  SOS 2 h\xE0m g\u1ECDi\
    \ ch\xE9o nhau\n  f(S) = h1(sum g(T), T subset S) + a(S)\n  g(S) = h2(sum f(T),\
    \ T subseteq S) + b(S)\n*/\nfor (int mask = 0; mask < (1 << n); mask++) {\n  //\
    \ t\xEDnh dpG v\xE0 f\n  for (int k = 1; k <= n; k++) {\n    if (mask & (1 <<\
    \ (k - 1))) {  // truy h\u1ED3i theo ki\u1EC3u proper subset\n      int sub =\
    \ mask ^ (1 << (k - 1));\n      dpG[mask][k] = dpG[mask][k - 1] + dpG[sub][k -\
    \ 1] + g[sub];\n    } else\n      dpG[mask][k] = dpG[mask][k - 1];\n  }\n  f[mask]\
    \ = h1(dpG[mask][n]) + a[mask];\n\n  // t\xEDnh dpF v\xE0 g\n  dpF[mask][0] =\
    \ f[mask];\n  for (int k = 1; k <= n; k++) {\n    if (mask & (1 << (k - 1))) \
    \ // truy h\u1ED3i theo ki\u1EC3u subset\n      dpF[mask][k] = dpF[mask][k - 1]\
    \ + dpF[mask ^ (1 << (k - 1))][k - 1];\n    else\n      dpF[mask][k] = dpF[mask][k\
    \ - 1];\n  }\n  g[mask] = h2(dpF[mask][n]) + b[mask];\n}\n\n// T\xEDnh t\xEDch\
    \ ch\u1EADp SOS c\u1EE7a 2 h\xE0m f, g\n// Make fhat[][] = {0} and ghat[][] =\
    \ {0}\nfor (int mask = 0; mask < (1 << N); mask++) {\n  fhat[__builtin_popcount(mask)][mask]\
    \ = f[mask];\n  ghat[__builtin_popcount(mask)][mask] = g[mask];\n}\n\n// Apply\
    \ zeta transform on fhat[][] and ghat[][]\nfor (int i = 0; i < N; i++) {\n  for\
    \ (int j = 0; j < N; j++) {\n    for (int mask = 0; mask < (1 << N); mask++) {\n\
    \      if ((mask & (1 << j)) != 0) {\n        fhat[i][mask] += fhat[i][mask ^\
    \ (1 << j)];\n        ghat[i][mask] += ghat[i][mask ^ (1 << j)];\n      }\n  \
    \  }\n  }\n}\n\n// Do the convolution and store into h[][] = {0}\nfor (int mask\
    \ = 0; mask < (1 << N); mask++) {\n  for (int i = 0; i < N; i++) {\n    for (int\
    \ j = 0; j <= i; j++) {\n      h[i][mask] += fhat[j][mask] * ghat[i - j][mask];\n\
    \    }\n  }\n}\n\n// Apply inverse SOS dp on h[][]\nfor (int i = 0; i < N; i++)\
    \ {\n  for (int j = 0; j < N; j++) {\n    for (int mask = 0; mask < (1 << N);\
    \ mask++) {\n      if ((mask & (1 << j)) != 0) {\n        h[i][mask] -= h[i][mask\
    \ ^ (1 << j)];\n      }\n    }\n  }\n}\nfor (int mask = 0; mask < (1 << N); mask++)\n\
    \  fog[mask] = h[__builtin_popcount(mask)][mask];"
  dependsOn: []
  isVerificationFile: false
  path: misc/SOSDP.cpp
  requiredBy: []
  timestamp: '2025-11-15 18:26:28+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/SOSDP.cpp
layout: document
redirect_from:
- /library/misc/SOSDP.cpp
- /library/misc/SOSDP.cpp.html
title: misc/SOSDP.cpp
---
