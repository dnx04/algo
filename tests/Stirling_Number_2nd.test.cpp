#define PROBLEM "https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind"

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
  // Stirling loại 2: // S(n, k) = hệ số của x^k trong A(x) * B(x)
  // A[i] = (-1)^i / i!, B[i] = i^n / i!
  int n;
  cin >> n;
  init_fact(n + 1);
  vector<Fp> a(n + 1), b(n + 1);
  for (int i = 0; i <= n; ++i) {
    a[i] = (i % 2 == 1 ? -Fp(1) : Fp(1)) * invFact[i];  // (-1)^i / i!
    b[i] = Fp(i).pow(n) * invFact[i];                   // i^n / i!
  }
  Poly A(a), B(b);
  Poly S = (A * B).cut(n + 1);
  for (int k = 0; k <= n; ++k) {
    cout << S[k] << (k == n ? "" : " ");
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}