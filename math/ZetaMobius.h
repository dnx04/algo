constexpr int MAXN = 1e6 + 5;
vector<int> P;
bitset<MAXN> is_p;

void sieve(int n) {
  is_p.set();
  is_p[0] = is_p[1] = 0;
  for (int i = 2; i <= n; ++i) {
    if (is_p[i]) P.pb(i);
    for (int p : P) {
      if (i * p > n) break;
      is_p[i * p] = 0;
      if (i % p == 0) break;
    }
  }
}

// div=0: Multiple (GCD), div=1: Divisor (LCM)
template <class Fp>
void zeta(vector<Fp>& f, bool div) {
  int n = len(f) - 1;
  for (int p : P) {
    if (p > n) break;
    if (!div)
      for (int j = n / p; j >= 1; --j) f[j] += f[j * p];
    else
      for (int j = 1; j * p <= n; ++j) f[j * p] += f[j];
  }
}

template <class Fp>
void mobius(vector<Fp>& f, bool div) {
  int n = len(f) - 1;
  for (int p : P) {
    if (p > n) break;
    if (!div)
      for (int j = 1; j <= n / p; ++j) f[j] -= f[j * p];
    else
      for (int j = n / p; j >= 1; --j) f[j * p] -= f[j];
  }
}

template <class Fp>
vector<Fp> convolution(vector<Fp> f, vector<Fp> g, bool div) {
  int n = min(len(f), len(g)) - 1;
  f.resize(n + 1);
  g.resize(n + 1);
  zeta(f, div), zeta(g, div);
  vector<Fp> h(n + 1);
  for (int i = 1; i <= n; ++i) h[i] = f[i] * g[i];
  mobius(h, div);
  return h;
}