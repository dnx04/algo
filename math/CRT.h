struct CRT {
  i64 res = 0, mod = 1;
  i64 euclid(i64 a, i64 b, i64 &x, i64 &y) {
    if (!b) return x = 1, y = 0, a;
    i64 d = euclid(b, a % b, y, x);
    return y -= a / b * x, d;
  }
  // Add condition: val % m = a
  bool add(i64 m, i64 a) {
    i64 x, y;
    i64 g = euclid(mod, m, x, y);
    if ((a - res) % g) return false;  // Incompatible condition
    i64 m0 = m / g;
    // k = (a - res) / g * inv(mod / g) mod (m / g)
    i128 k = (i128)(a - res) / g * x % m0;
    res += (i64)k * mod;
    mod *= m0;
    res = (res % mod + mod) % mod;
    return true;
  }
};