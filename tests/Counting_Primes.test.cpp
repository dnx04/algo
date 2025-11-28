#define PROBLEM "https://judge.yosupo.jp/problem/counting_primes"

#include "../misc/macros.h"
#include "../math/Min25.h"

void solve() {
  Min25<i64> solver;
  i64 n;
  cin >> n;
  solver.init(n);
  cout << solver.g0[solver.id(n)];
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tc = 1;
  // cin >> tc;
  while (tc--) solve();
}