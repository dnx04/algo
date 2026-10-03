#include "Compressor.h"

template <class T, class Fp>
Fp CountSubseq(vector<T> a) {
  a = compressor<T>(a);
  vi last(len(a) + 1, -1);
  vector<Fp> f(len(a) + 1);
  f[0] = 1;
  for (int i = 0; i < len(a); ++i) {
    f[i + 1] = f[i] * 2;
    if (last[a[i]] >= 0) f[i + 1] -= f[last[a[i]]];
    last[a[i]] = i;
  }
  return f.back() - 1;
}