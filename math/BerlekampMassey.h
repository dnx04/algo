template <typename T>
vector<T> BerlekampMassey(vector<T> s) {
  int n = sz(s), L = 0, m = 0;
  vector<T> C(n), B(n), T;
  C[0] = B[0] = 1;
  T b = 1;
  for (int i = 0; i < n; ++i) {
    ++m;
    T d = s[i];
    for (int j = 1, j <= L; ++j) d = d + C[j] * s[i - j];
    if (!d) continue;
    T = C;
    ll coef = d * modpow(b, mod - 2) % mod;
    for (int j = m; j < n; ++j) C[j] = C[j] - coef * B[j - m];
    if (2 * L > i) continue;
    L = i + 1 - L;
    B = T;
    b = d;
    m = 0;
  }
  C.resize(L + 1);
  C.erase(C.begin());
  for (T& x : C) x = (mod - x) % mod;
  return C;
}