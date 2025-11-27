#define PROBLEM "https://judge.yosupo.jp/problem/min_of_mod_of_linear"

#include "../misc/macros.h"
#include "../math/DivModSum.h"

void solve() {
  int n, m, a, b;
  cin >> n >> m >> a >> b;
  cout << minmod(n, m, a, b) << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) solve();
}