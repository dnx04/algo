#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_matrix"

#include "../misc/macros.h"
#include "../math/ModInt.h"
#include "../math/Matrix.h"

using Fp = modint<998244353>;

void solve() {
  int n;
  u64 k;
  cin >> n >> k;
  Matrix<Fp> a(n);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) cin >> a[i][j];
  a = a.pow(k);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) cout << a[i][j] << " \n"[j + 1 == n];
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tc = 1;
  // cin >> tc;
  for (int i = 1; i <= tc; ++i) {
    solve();
  }
}
