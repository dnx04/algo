// SOS xuôi - z(f(s))
for (int k = 0; k < n; k++)
  for (int mask = 0; mask < (1 << n); mask++)
    if (mask & (1 << k)) dp[mask] += dp[mask ^ (1 << k)];

// Hàm đan dấu - o(f(s))
for (int mask = 0; mask < (1 << n); mask++)
  sos[mask] = f[mask] * (__builtin_parity(mask) ? -1 : 1);

// SOS ngược - mu(f(s)) = ozo(f(s))
// z(mu(f)) = mu(z(f)) = f

// SOS truy hồi chính nó: f(S) = h(sum f(T), T subset S) + a(S)
for (int mask = 0; mask < (1 << n); mask++) {
  dp[mask][0] = 0;  // trường hợp cơ sở
  for (int k = 1; k <= n; k++) {
    // tính Sum over Proper Subset
    if (mask & (1 << (k - 1))) {
      int sub = mask ^ (1 << (k - 1));
      dp[mask][k] = dp[mask][k - 1] + dp[sub][k - 1] + f[sub];
    } else
      dp[mask][k] = dp[mask][k - 1];
  }
  f[mask] = h(dp[mask][n]) + a[mask];  // tính f
}

/*
  SOS 2 hàm gọi chéo nhau
  f(S) = h1(sum g(T), T subset S) + a(S)
  g(S) = h2(sum f(T), T subseteq S) + b(S)
*/
for (int mask = 0; mask < (1 << n); mask++) {
  // tính dpG và f
  for (int k = 1; k <= n; k++) {
    if (mask & (1 << (k - 1))) {  // truy hồi theo kiểu proper subset
      int sub = mask ^ (1 << (k - 1));
      dpG[mask][k] = dpG[mask][k - 1] + dpG[sub][k - 1] + g[sub];
    } else
      dpG[mask][k] = dpG[mask][k - 1];
  }
  f[mask] = h1(dpG[mask][n]) + a[mask];

  // tính dpF và g
  dpF[mask][0] = f[mask];
  for (int k = 1; k <= n; k++) {
    if (mask & (1 << (k - 1)))  // truy hồi theo kiểu subset
      dpF[mask][k] = dpF[mask][k - 1] + dpF[mask ^ (1 << (k - 1))][k - 1];
    else
      dpF[mask][k] = dpF[mask][k - 1];
  }
  g[mask] = h2(dpF[mask][n]) + b[mask];
}

// Tính tích chập SOS của 2 hàm f, g
// Make fhat[][] = {0} and ghat[][] = {0}
for (int mask = 0; mask < (1 << N); mask++) {
  fhat[__builtin_popcount(mask)][mask] = f[mask];
  ghat[__builtin_popcount(mask)][mask] = g[mask];
}

// Apply zeta transform on fhat[][] and ghat[][]
for (int i = 0; i < N; i++) {
  for (int j = 0; j < N; j++) {
    for (int mask = 0; mask < (1 << N); mask++) {
      if ((mask & (1 << j)) != 0) {
        fhat[i][mask] += fhat[i][mask ^ (1 << j)];
        ghat[i][mask] += ghat[i][mask ^ (1 << j)];
      }
    }
  }
}

// Do the convolution and store into h[][] = {0}
for (int mask = 0; mask < (1 << N); mask++) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= i; j++) {
      h[i][mask] += fhat[j][mask] * ghat[i - j][mask];
    }
  }
}

// Apply inverse SOS dp on h[][]
for (int i = 0; i < N; i++) {
  for (int j = 0; j < N; j++) {
    for (int mask = 0; mask < (1 << N); mask++) {
      if ((mask & (1 << j)) != 0) {
        h[i][mask] -= h[i][mask ^ (1 << j)];
      }
    }
  }
}
for (int mask = 0; mask < (1 << N); mask++)
  fog[mask] = h[__builtin_popcount(mask)][mask];