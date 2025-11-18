struct XorBasis {
  vector<i64> b;
  XorBasis() {}
  void add(int x) {
    x = this->sift(x);
    if (x != 0) this->b.pb(x);
  }
  i64 sift(i64 x) const {
    for (i64 b : this->b) {
      x = min(x, x ^ b);
      if (x == 0) return 0;
    }
    return x;
  }
  bool is_indep(i64 x) const {
    return this->sift(x) != 0;
  }
  vector<i64> basis() const {
    return this->b;
  }
};

vector<i64> XorInter(const vector<i64>& u, const vector<i64>& v) {
  XorBasis X;
  for (auto x : u) X.add(x);
  vector<pair<i64, i64>> basis;
  XorBasis inter;
  for (auto x : v) {
    auto y = X.sift(x), pu = y ^ x, sy = y;
    for (auto v : basis) {
      i64 tmp = sy ^ v.second;
      if (tmp < sy) {
        sy = tmp;
        pu ^= v.first;
      }
    }
    if (sy != 0) {
      basis.pb({pu, sy});
    } else {
      inter.add(pu);
    }
  }
  return inter.basis();
}