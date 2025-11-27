#include "ModInt.h"

using Fp = modint<998244353>;
namespace ntt {
const Fp G = 3;
void ntt(vector<Fp>& a, bool inv) {
  int n = sz(a);
  for (int i = 1, j = 0; i < n; i++) {
    int bit = n >> 1;
    for (; j & bit; bit >>= 1) j ^= bit;
    j ^= bit;
    if (i < j) swap(a[i], a[j]);
  }
  for (int len = 1; len < n; len <<= 1) {
    Fp wlen = G.pow((Fp::modulo - 1) / (2 * len));
    if (inv) wlen = wlen.inv();
    for (int i = 0; i < n; i += 2 * len) {
      Fp w = 1;
      for (int j = 0; j < len; j++) {
        Fp u = a[i + j], v = a[i + j + len] * w;
        a[i + j] = u + v, a[i + j + len] = u - v;
        w *= wlen;
      }
    }
  }
  if (inv) {
    Fp n_inv = Fp(n).inv();
    for (auto& x : a) x *= n_inv;
  }
}
vector<Fp> conv(vector<Fp> a, vector<Fp> b) {
  if (a.empty() || b.empty()) return {};
  int s = sz(a) + sz(b) - 1, n = 1;
  while (n < s) n <<= 1;
  a.resize(n), b.resize(n);
  ntt(a, 0), ntt(b, 0);
  for (int i = 0; i < n; i++) a[i] *= b[i];
  ntt(a, 1), a.resize(s);
  return a;
}
}  // namespace ntt

struct Poly : vector<Fp> {
  using vector::vector;
  Poly(const vector<Fp>& v) : vector(v) {}

  Poly cut(int n) const {
    Poly res = *this;
    res.resize(n);
    return res;
  }

  Poly operator+(const Poly& r) const {
    Poly res = *this;
    res.resize(max(sz(*this), sz(r)));
    for (int i = 0; i < sz(r); ++i) res[i] += r[i];
    return res;
  }
  Poly operator-(const Poly& r) const {
    Poly res = *this;
    res.resize(max(sz(*this), sz(r)));
    for (int i = 0; i < sz(r); ++i) res[i] -= r[i];
    return res;
  }
  Poly operator*(const Poly& r) const { return ntt::conv(*this, r); }
  Poly operator*(Fp v) const {
    Poly res = *this;
    for (auto& x : res) x *= v;
    return res;
  }
  Poly& operator+=(const Poly& r) { return *this = *this + r; }
  Poly& operator-=(const Poly& r) { return *this = *this - r; }
  Poly& operator*=(const Poly& r) { return *this = *this * r; }

  Poly deriv() const {
    if (empty()) return {};
    Poly res(sz(*this) - 1);
    for (int i = 1; i < sz(*this); ++i) res[i - 1] = data()[i] * i;
    return res;
  }
  Poly integ() const {
    Poly res(sz(*this) + 1);
    for (int i = 0; i < sz(*this); ++i) res[i + 1] = data()[i] * Fp(i + 1).inv();
    return res;
  }
  Poly inv(int n) const {
    Poly b = {data()[0].inv()};
    for (int k = 1; k < n; k <<= 1) {
      Poly a = cut(2 * k), prod = b * b * a;
      b.resize(2 * k);
      for (int i = 0; i < 2 * k; ++i) {
        b[i] = b[i] * 2 - (i < sz(prod) ? prod[i] : Fp(0));
      }
    }
    return b.cut(n);
  }

  Poly log(int n) const { return (deriv() * inv(n)).integ().cut(n); }

  Poly exp(int n) const {
    Poly b = {1};
    for (int k = 1; k < n; k <<= 1) {
      Poly ln_b = b.log(2 * k), a = cut(2 * k), diff = a - ln_b;
      diff[0] += 1, b = (b * diff).cut(2 * k);
    }
    return b.cut(n);
  }

  Poly pow(i64 k, int n) const {
    if (n == 0) return {};
    if (k == 0) {
      Poly res = {1};
      res.resize(n);
      return res;
    }
    int i = 0;
    while (i < sz(*this) && data()[i].x == 0) i++;
    if (i == sz(*this) || (i > 0 && k >= n / i + 2)) {
      Poly res;
      res.resize(n);
      return res;
    }
    i64 shift = (i64) i * k;
    if (shift >= n) {
      Poly res;
      res.resize(n);
      return res;
    }
    Poly a = {begin() + i, end()};
    int limit = n - shift;
    a.resize(limit);
    Fp lead = a[0];
    Fp inv_lead = lead.inv();
    a = a * inv_lead;
    a = (a.log(limit) * Fp(k)).exp(limit);
    a = a * lead.pow(k);
    Poly res(shift, 0);
    res.insert(res.end(), a.begin(), a.end());
    res.resize(n);
    return res;
  }
  friend ostream& operator<<(ostream& os, const Poly& p) {
    for (auto x : p) os << x << " ";
    return os;
  }
};