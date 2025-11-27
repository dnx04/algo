#define PROBLEM "https://judge.yosupo.jp/problem/rational_approximation"

#include "../misc/macros.h"
#include "../math/SternBrocot.h"

void solve() {
  int n, x, y;
  cin >> n >> x >> y;
  auto f = [&](Frac a) {
    return a.p * y <= a.q * x;
  };
  auto [lo, hi] = SternBrocot::bound(f, n, n);
  if(lo.p * y == lo.q * x) hi = lo;
  cout << lo.p << ' ' << lo.q << ' ' << hi.p << ' ' << hi.q << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tc = 1;
  cin >> tc;
  while (tc--) solve();
}