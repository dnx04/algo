template <typename Fp>
vector<Fp> BerlekampMassey(vector<Fp> s) {
  int n = sz(s), L = 0, m = 0;
  vector<Fp> C(n), B(n), T;
  C[0] = B[0] = 1;
  Fp b = 1;
  for (int i = 0; i < n; ++i) {
    ++m;
    Fp d = s[i];
    for (int j = 1, j <= L; ++j) d += C[j] * s[i - j];
    if (!d) continue;
    T = C;
    Fp coef = d / b;
    for (int j = m; j < n; ++j) C[j] -= coef * B[j - m];
    if (2 * L > i) continue;
    L = i + 1 - L, B = T, b = d, m = 0;
  }
  C.resize(L + 1), C.erase(C.begin());
  for (Fp& x : C) x = -x;
  return C;
}