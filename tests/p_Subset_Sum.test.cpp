#define PROBLEM "https://judge.yosupo.jp/problem/sharp_p_subset_sum"

#include "../misc/macros.h"
#include "../math/ModInt.h"
#include "../math/Poly.h"

using Fp = modint<998244353>;

void solve() {
  int N, T;
  cin >> N >> T;
  vector<int> cnt(T + 1, 0);
  for (int i = 0; i < N; ++i) {
    int s; cin >> s;
    if (s <= T) cnt[s]++;
  }

  // Chuẩn bị mảng nghịch đảo để tính toán nhanh
  vector<Fp> inv(T + 1);
  inv[1] = 1;
  for (int i = 2; i <= T; i++) 
    inv[i] = Fp(Fp::modulo - Fp::modulo / i) * inv[Fp::modulo % i];

  // Xây dựng Poly ln_P tương ứng với ln(P(x))
  // ln P(x) = sum_{v=1}^T cnt[v] * sum_{k=1} (-1)^(k-1) * x^(kv) / k
  Poly ln_P(T + 1, 0);
  
  for (int v = 1; v <= T; ++v) {
    if (!cnt[v]) continue;
    for (int k = 1; k * v <= T; ++k) {
      Fp term = inv[k] * cnt[v]; // cnt[v] / k
      if (k % 2 == 1) ln_P[k * v] += term;
      else            ln_P[k * v] -= term;
    }
  }

  // P(x) = exp(ln P(x))
  Poly P = ln_P.exp(T + 1);

  // In kết quả từ 1 đến T
  for (int i = 1; i <= T; ++i) {
    cout << P[i] << (i == T ? "" : " ");
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tc = 1;
  // cin >> tc;
  while (tc--) solve();
}