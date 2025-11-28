#define PROBLEM "https://judge.yosupo.jp/problem/bernoulli_number"

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
  // Bernoulli EGF: x / (e^x - 1)
  // Ta có: (e^x - 1)/x = sum_{i=0} x^i / (i+1)!
  // B(x) = ((e^x - 1)/x)^(-1)
  int n;
  cin >> n;
  init_fact(n + 1);
  vector<Fp> a(n + 1);
  for (int i = 0; i <= n; ++i) {
    a[i] = invFact[i + 1];  // 1/(i+1)!
  }
  Poly A(a);
  Poly B = A.inv(n + 1);  // Tìm nghịch đảo modulo x^(n+1)
  for(int i = 0; i <= n; ++i) {
    cout << B[i] * fact[i] << ' ';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}