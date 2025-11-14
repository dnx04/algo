#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_matrix"

#include "../misc/macros.h"

#include "../math/Matrix.h"
#include "../math/ModInt.h"

using Fp = modint<998244353>;

void solve() {
  int n;
  ll k;
  cin >> n >> k;
  Matrix<Fp> A(n);
  for (int i = 0; i < n; ++i) rep(j, 0, n) cin >> A.d[i][j];
  A = A ^ k;
  for (int i = 0; i < n; ++i) { rep(j, 0, n) cout << A.d[i][j] << " \n"[j == n - 1]; }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tc = 1;
  //   cin >> tc;
  for (int i = 1; i <= tc; ++i) {
    solve();
  }
}
