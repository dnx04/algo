template <int mod>
struct modint {
  using Fp = modint;
  static constexpr ull im = -1ULL / mod + 1;  // Barrett constant
  int x;
  modint() : x(0) {}
  modint(ll y) {
    y %= mod;
    if (y < 0) y += mod;
    x = y;
  }
  static inline uint32_t reduce(ull z) {
    ull q = (__uint128_t(z) * im) >> 64;
    ll r = z - q * mod;
    return r < mod ? r : r - mod;
  }
  Fp& operator+=(const Fp& p) {
    if ((x += p.x) >= mod) x -= mod;
    return *this;
  }
  Fp& operator-=(const Fp& p) {
    if ((x += mod - p.x) >= mod) x -= mod;
    return *this;
  }
  Fp& operator*=(const Fp& p) {
    x = reduce(uint64_t(x) * p.x);
    return *this;
  }
  Fp& operator/=(const Fp& p) { return *this *= p.inv(); }

  Fp operator-() const { return Fp(-x); }
  Fp operator+(const Fp& p) const { return Fp(*this) += p; }
  Fp operator-(const Fp& p) const { return Fp(*this) -= p; }
  Fp operator*(const Fp& p) const { return Fp(*this) *= p; }
  Fp operator/(const Fp& p) const { return Fp(*this) /= p; }
  bool operator==(const Fp& p) const { return x == p.x; }
  bool operator!=(const Fp& p) const { return x != p.x; }
  Fp inv() const { return *this ^ (mod - 2); }
  Fp operator^(int64_t n) const {
    Fp r = 1, a = *this;
    while (n) {
      if (n & 1) r *= a;
      a *= a;
      n >>= 1;
    }
    return r;
  }
  friend ostream& operator<<(ostream& os, const Fp& p) { return os << p.x; }
  friend istream& operator>>(istream& is, Fp& a) {
    int64_t t;
    is >> t;
    a = Fp(t);
    return is;
  }
};
