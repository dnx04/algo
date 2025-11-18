#define PROBLEM "https://judge.yosupo.jp/problem/minimum_enclosing_circle"

#include "../misc/macros.h"
#include "../geometry/MinimumEnclosingCircle.h"

using P = Point<ld>;
void solve() {
  int n;
  cin >> n;
  vector<P> pts(n);
  for (auto& [x, y] : pts) cin >> x >> y;
  auto [o, r] = mec(pts);
  const ld EPS = 1e-10;
  for (int i = 0; i < n; ++i) {
    if (fabsl((o - pts[i]).dist2() - r * r) < EPS) {
      cout << 1;
    } else {
      cout << 0;
    }
  }
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
