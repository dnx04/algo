#include "ModInt.h"

using Fp = modint<998244353>;

vector<Fp> fac, invFac;
void prepareFac(int n) {
  fac.resize(n + 1);
  invFac.resize(n + 1);
  fac[0] = 1;
  for (int i = 1; i <= n; ++i) fac[i] = fac[i - 1] * i;
  invFac[n] = fac[n].inv();
  for (int i = n; i >= 1; --i) invFac[i - 1] = invFac[i] * i;
}

// Lagrange interpolation [0,...,n-1] in O(n)
Fp interpolate(const vector<Fp>& y, i64 n) {
  int k = len(y) - 1;
  if (n <= k) return y[n];
  vector<Fp> pre(k + 1), suf(k + 1);
  pre[0] = suf[k] = 1;
  for (int i = 0; i < k; ++i) pre[i + 1] = pre[i] * (n - i);
  for (int i = k; i > 0; --i) suf[i - 1] = suf[i] * (n - i);
  Fp ans = 0;
  for (int i = 0; i <= k; ++i) {
    Fp val = pre[i] * suf[i] * y[i] * invFac[i] * invFac[k - i];
    if ((k - i) & 1)
      ans -= val;
    else
      ans += val;
  }
  return ans;
}

// C = sum_{i=0->inf} r^i * fs[i] (r != 1)
Fp sumPolyLimit(Fp r, const vector<Fp>& fs) {
  int d = fs.size() - 1;
  if (r.x == 0) return fs[0];
  vector<Fp> rr(d + 1);
  rr[0] = 1;
  for (int i = 1; i <= d; ++i) rr[i] = rr[i - 1] * r;
  Fp ans = 0, S = 0;
  for (int i = 0; i <= d; ++i) {
    S += rr[i] * fs[i];
    Fp term = invFac[d - i] * invFac[i + 1] * rr[d - i] * S;
    if ((d - i) & 1)
      ans -= term;
    else
      ans += term;
  }
  return ans * fac[d + 1] / (Fp(1) - r).pow(d + 1);
}

// Sum_{i=0->n-1} r^i * fs[i]
Fp sumPoly(Fp r, const vector<Fp>& fs, u64 n) {
  if (n == 0) return 0;
  if (r == 0) return fs[0];
  int d = len(fs) - 1;
  if (r == 1) {
    vector<Fp> S(d + 2);
    S[0] = 0;
    for (int i = 0; i <= d; ++i) S[i + 1] = S[i] + fs[i];
    return interpolate(S, n);
  }
  Fp C = sumPolyLimit(r, fs), S_curr = 0, rp = 1, rip = 1, ri = r.inv();
  vector<Fp> g(d + 1);
  for (int k = 0; k <= d; ++k) {
    g[k] = (S_curr - C) * rip;
    S_curr += rp * fs[k], rp *= r, rip *= ri;
  }
  return C + r.pow(n) * interpolate(g, n);
}