template <int mod>
struct modint {
  using M = modint;
  static_assert(mod > 0 && mod <= 2147483647);
  static constexpr u32 r1 = []() {
    u32 r1 = mod;
    for (int i = 0; i < 5; ++i) r1 *= 2 - mod * r1;
    return -r1;
  }();
  static constexpr u32 r2 = -u64(mod) % mod;
  static u32 reduce(u64 x) {
    u32 y = u32(x) * r1, r = (x + u64(y) * mod) >> 32;
    return r >= mod ? r - mod : r;
  }
  u32 x;
  modint() : x(0) {}
  modint(i64 x) : x(reduce(u64(x % mod + mod) * r2)) {}
  M& operator+=(const M& a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  M& operator-=(const M& a) {
    if ((x += mod - a.x) >= mod) x -= mod;
    return *this;
  }
  M& operator*=(const M& a) {
    x = reduce(u64(x) * a.x);
    return *this;
  }
  M& operator/=(const M& a) { return *this *= a.inv(); }
  M operator-() const { return M(0) - *this; }
  M operator+(const M& a) const { return M(*this) += a; }
  M operator-(const M& a) const { return M(*this) -= a; }
  M operator*(const M& a) const { return M(*this) *= a; }
  M operator/(const M& a) const { return M(*this) /= a; }
  bool operator==(const M& a) const { return x == a.x; }
  bool operator!=(const M& a) const { return x != a.x; }
  M pow(u64 k) const {
    M res(1), b = *this;
    while (k) {
      if (k & 1) res *= b;
      b *= b, k >>= 1;
    }
    return res;
  }
  M inv() const { return pow(mod - 2); }
  friend ostream& operator<<(ostream& os, const M& a) {
    return os << reduce(a.x);
  }
  friend istream& operator>>(istream& is, M& a) {
    i64 v;
    is >> v;
    a = M(v);
    return is;
  }
};

u64 modmul(u64 x, u64 y, u64 m) { return u128(x) * y % m; }
u64 modpow(u64 x, u64 k, u64 m) {
  u64 res = 1;
  while (k) {
    if (k & 1) res = modmul(res, x, m);
    x = modmul(x, x, m);
    k >>= 1;
  }
  return res;
}