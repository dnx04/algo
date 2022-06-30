auto sieve = [](int n) {
  vector<int> lpf(n + 1);
  iota(begin(lpf), end(lpf), 0);
  for (int i = 2; i <= n; ++i) {
    if (lpf[i] == i) {
      for (int j = 1ll * i * i; j <= n; j += i) {
        if (lpf[j] == j) lpf[j] = i;
      }
    }
  }
  return lpf;
};