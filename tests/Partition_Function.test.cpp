#define PROBLEM "https://judge.yosupo.jp/problem/partition_function"

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
  // Partition: P(x) = product_{k=1} (1 / (1-x^k))
  // Tính mẫu số bằng công thức ngũ giác Euler rồi nghịch đảo:
  // Mẫu số = 1 + sum (-1)^k * x^(k(3k +/- 1)/2)
  int n;
  cin >> n;
  init_fact(n + 1);
  vector<Fp> denom(n + 1, 0);
  denom[0] = 1;
  for (int k = 1;; ++k) {
    int p1 = k * (3 * k - 1) / 2;
    int p2 = k * (3 * k + 1) / 2;
    if (p1 > n && p2 > n) break;
    if (p1 <= n) denom[p1] = (k % 2 == 1 ? -1 : 1);
    if (p2 <= n) denom[p2] = (k % 2 == 1 ? -1 : 1);
  }
  Poly D(denom);
  Poly P = D.inv(n + 1);
  for (int i = 0; i <= n; ++i) {
    cout << P[i] << (i == n ? "" : " ");
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}