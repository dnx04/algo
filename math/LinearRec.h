template <class Fp>
vector<Fp> LinearRec(const vector<Fp>& as) {
  const int n = as.size();
  int d = 0, m = 0;
  vector<Fp> cs(n + 1, 0), bs(n + 1, 0);
  cs[0] = bs[0] = 1;
  Fp invBef = 1;
  for (int i = 0; i < n; ++i) {
    ++m;
    Fp dif = as[i];
    for (int j = 1; j <= d; ++j) dif += cs[j] * as[i - j];
    if (dif.x != 0) {
      auto csDup = cs;
      const Fp r = dif * invBef;
      for (int j = m; j < n; ++j) cs[j] -= r * bs[j - m];
      if (2 * d <= i) {
        d = i + 1 - d, m = 0, bs = csDup, invBef = dif.inv();
      }
    }
  }
  cs.resize(d + 1);
  for (auto& c : cs) c = -c;
  return cs;
}