#include "FFT.h"

typedef vector<i64> vl;
template <int M>
vl convMod(const vl& a, const vl& b) {
  if (a.empty() || b.empty()) return {};
  vl res(sz(a) + sz(b) - 1);
  int B = 32 - __builtin_clz(sz(res)), n = 1 << B, cut = int(sqrt(M));
  vector<C> L(n), R(n), outs(n), outl(n);
  for (int i = 0; i < sz(a); ++i) L[i] = C((int) a[i] / cut, (int) a[i] % cut);
  for (int i = 0; i < sz(b); ++i) R[i] = C((int) b[i] / cut, (int) b[i] % cut);
  fft(L), fft(R);
  for (int i = 0; i < n; ++i) {
    int j = -i & (n - 1);
    outl[j] = (L[i] + conj(L[j])) * R[i] / ld(2.0 * n);
    outs[j] = (L[i] - conj(L[j])) * R[i] / ld(2.0 * n) / 1i;
  }
  fft(outl), fft(outs);
  for (int i = 0; i < sz(res); ++i) {
    i64 av = i64(real(outl[i]) + .5), cv = i64(imag(outs[i]) + .5);
    i64 bv = i64(imag(outl[i]) + .5) + i64(real(outs[i]) + .5);
    res[i] = ((av % M * cut + bv) % M * cut + cv) % M;
  }
  return res;
}