#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_multiplicative_function"

#include "../misc/macros.h"
#include "../math/Min25.h"
#include "../math/ModInt.h"

using Fp = modint<469762049>;

void solve() {
  Min25<Fp> solver;
  i64 n;
  Fp a, b;
  cin >> n >> a >> b;
  solver.init(n);
  cout << solver.solve(a, b, [&](i64 p, int e) {
    return a * e + b * p;
  }) << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tc = 1;
  cin >> tc;
  while (tc--) solve();
}