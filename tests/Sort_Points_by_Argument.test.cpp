#define PROBLEM "https://judge.yosupo.jp/problem/sort_points_by_argument"

#include "../misc/macros.h"
#include "../geometry/Point.h"

typedef Point<ll> P;

void solve() {
  int n;
  cin >> n;
  vector<P> pts(n);
  for(int i = 0; i < n; ++i) cin >> pts[i].x >> pts[i].y;
  sort(all(pts), [&](P a, P b) { return a.angle() < b.angle(); });
  for (auto p : pts)
    cout << fixed << setprecision(0) << p.x << ' ' << p.y << '\n';
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
