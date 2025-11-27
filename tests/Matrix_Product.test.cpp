#define PROBLEM "https://judge.yosupo.jp/problem/matrix_product"

#include "../misc/macros.h"
#include "../math/Matrix.h"
#include "../math/ModInt.h"

using namespace std;

void solve() {
  using Fp = modint<998244353>;
  int n, m, k;
  cin >> n >> m >> k;
  Matrix<Fp> a(n, m), b(m, k);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < k; ++j) {
      cin >> b[i][j];
    }
  }
  auto c = a * b;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < k; ++j) {
      cout << c[i][j] << " \n"[j == k - 1];
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
}