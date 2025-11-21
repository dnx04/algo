#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial"

#include "misc/macros.h"
#include "math/SumPowerPoly.h"

// calculate pws(i) = i^d for 0 <= i < n using sieve
vector<Fp> getMonomials(int n, int d) {
  vector<Fp> pws(n);
  vector<int> primes, lpf(n);
  pws[1] = 1, pws[0] = (d == 0 ? 1 : 0);
  for (int i = 2; i < n; ++i) {
    if (lpf[i] == 0) lpf[i] = i, primes.eb(i), pws[i] = Fp(i).pow(d);
    for (auto p : primes) {
      if (p > lpf[i] || i * p >= n) break;
      lpf[i * p] = p;
      pws[i * p] = pws[i] * pws[p];
    }
  }
  return pws;
}

void solve() {
  int r, d;
  u64 n;
  cin >> r >> d >> n;
  prepareFac(d + 2);
  cout << sumPoly(Fp(r), getMonomials(d + 1, d), n);
}

int main() {
  solve();
}