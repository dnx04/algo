struct XorBasis {
  vector<ll> b;
  XorBasis() {}
  void add(int x) {
    x = this->sift(x);
    if (x != 0) this->b.pb(x);
  }
  ll sift(ll x) const {
    for (ll b : this->b) {
      x = min(x, x ^ b);
      if (x == 0) return 0;
    }
    return x;
  }
  bool is_indep(ll x) const {
    return this->sift(x) != 0;
  }
  vector<ll> basis() const {
    return this->b;
  }
};

vector<ll> XorInter(const vector<ll>& u, const vector<ll>& v) {
  XorBasis X;
  for (auto x : u) X.add(x);
  vector<pair<ll, ll>> basis;
  XorBasis inter;
  for (auto x : v) {
    auto y = X.sift(x), pu = y ^ x, sy = y;
    for (auto v : basis) {
      ll tmp = sy ^ v.second;
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