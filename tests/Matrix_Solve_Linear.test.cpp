#define PROBLEM "https://judge.yosupo.jp/problem/system_of_linear_equations"

#include "../misc/macros.h"
#include "../math/Matrix.h"
#include "../math/ModInt.h"

using namespace std;

void solve() {
  using Fp = modint<998244353>;
  int n, m;
  cin >> n >> m;
  Matrix<Fp> a(n, m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }
  Matrix<Fp> b(n, 1);
  for (int i = 0; i < n; ++i) cin >> b[i][0];
  auto [sol, ker] = a.solve(b);
  if (sol.empty()) {
    cout << -1;
  } else {
    cout << sz(ker) << '\n';
    for (auto e : sol) cout << e << ' ';
    cout << '\n';
    for (auto v : ker) {
      for (auto e : v) cout << e << ' ';
      cout << '\n';
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
}