#define PROBLEM "https://judge.yosupo.jp/problem/stirling_number_of_the_first_kind_fixed_k"

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
  // Stirling loại 1 với k cố định
  // Nếu là Stirling loại 1 không dấu thì là số hoán vị n phần tử có đúng k chu trình
  // EGF: (ln(1/(1-x)))^k / k!
  // ln(1/(1-x)) = x + x^2/2 + x^3/3 + ...
  int N, K;
  cin >> N >> K;
  init_fact(N + 1);
  if (K == 0) {
    cout << "1 ";  // S(0,0)
    for (int i = 1; i <= N; ++i) cout << "0 ";
    cout << "\n";
    return;
  }

  // 1. Tạo đa thức A(x) = sum(x^i / i)
  vector<Fp> a(N + 1, 0);
  for (int i = 1; i <= N; ++i) {
    // 1/i = (i-1)! / i! = fact[i-1] * invFact[i]
    a[i] = fact[i - 1] * invFact[i];
  }
  Poly A(a);

  // 2. Tính G(x) = A(x)^K
  Poly G = A.pow(K, N + 1);

  // 3. Kết quả S(n, K) = G[n] * n! / K!
  Fp invK = invFact[K];
  for (int n = K; n <= N; ++n) {
    Fp val = G[n] * fact[n] * invK;
    if((n - K) % 2 == 1) val = -val;
    cout << val << ' ';
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}