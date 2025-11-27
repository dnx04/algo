#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det"

#include "../misc/macros.h"
#include "../math/Matrix.h"
#include "../math/ModInt.h"

using namespace std;

void solve() {
  using Fp = modint<998244353>;
  int n;
  cin >> n;
  Matrix<Fp> a(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
    }
  }
  cout << a.det();
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
}