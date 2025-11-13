using C = complex<double>;

vector<C> PolyRoots(vector<C> p) {
  int n = p.size() - 1;
  vector<C> ret(n);
  for (int i = 0; i < n; ++i) ret[i] = pow(C{0.456, 0.976}, i);
  for (int it = 0; it < 1000; ++it) {
    for (int i = 0; i < n; ++i) {
      C up = 0, dw = 1;
      for (int j = n; j >= 0; --j) {
        up = up * ret[i] + p[j];
        if (j != i && j != n) dw = dw * (ret[i] - ret[j]);
      }
      ret[i] -= up / dw / p[n];
    }
  }
  return ret;
}