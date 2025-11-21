#define PROBLEM "https://judge.yosupo.jp/problem/furthest_pair"

#include "../misc/macros.h"
#include "../geometry/ConvexHull.h"
#include "../geometry/HullDiameter.h"

void solve() {
  int n;
  cin >> n;
  vector<P> pts(n);
  for (auto& [x, y] : pts) cin >> x >> y;
  auto cvh = convexHull(pts);
  auto [pi, pj] = hullDiameter(cvh);
  int i, j;
  for (i = 0; i < n; ++i) {
    if (pts[i] == pi) {
      cout << i << ' ';
      break;
    }
  }
  for (j = 0; j < n; ++j) {
    if (pts[j] == pj && j != i) {
      cout << j << '\n';
      break;
    }
  }
}

int main() {
  int tc;
  cin >> tc;
  while (tc--) solve();
}