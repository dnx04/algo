#define PROBLEM "https://judge.yosupo.jp/problem/bell_number"

#include "../misc/macros.h"
#include "../math/Poly.h"

vector<Fp> fact, invFact;
void init_fact(int n) {
  fact.resize(n + 1);
  invFact.resize(n + 1);
  fact[0] = 1;
  for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i;
  invFact[n] = fact[n].inv();
  for (int i = n - 1; i >= 0; i--) invFact[i] = invFact[i + 1] * (i + 1);
}

Fp nCk(int n, int k) {
  if (k < 0 || k > n) return 0;
  return fact[n] * invFact[k] * invFact[n - k];
}

void solve() {
  // Bell EGF: exp(e^x - 1)
  // e^x - 1 = sum_{i=1} x^i / i! (Taylor)
  int n;
  cin >> n;
  init_fact(n + 1);
  vector<Fp> f(n + 1);
  for (int i = 1; i <= n; ++i) {
    f[i] = invFact[i];  // 1/i! for i >= 1
  }
  Poly F(f); // F is e^x - 1
  Poly BellEGF = F.exp(n + 1); // F is exp(e^x - 1)
  for(int i = 0; i <= n; ++i) {
    cout << BellEGF[i] * fact[i] << ' ';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}