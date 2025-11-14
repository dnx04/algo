#define PROBLEM "https://judge.yosupo.jp/problem/static_convex_hull"

#include "../misc/macros.h"

#include "../geometry/ConvexHull.h"

void solve() {
  int n;
  cin >> n;
  vector<Point<ll>> pts(n);
  rep(i, 0, n) cin >> pts[i].x >> pts[i].y;
  auto hull = convexHull(pts);
  cout << sz(hull) << '\n';
  for (auto p : hull) cout << p.x << ' ' << p.y << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tc = 1;
  cin >> tc;
  for (int i = 1; i <= tc; ++i) {
    solve();
  }
}
