#define PROBLEM "https://judge.yosupo.jp/problem/count_points_in_triangle"

#include "../misc/macros.h"
#include "../geometry/TrianglePointCount.h"

using P = Point<i64>;

void solve() {
  vector<P> A, B;
  int n, m;
  cin >> n;
  A.resize(n);
  for (auto& [x, y] : A) cin >> x >> y;
  cin >> m;
  B.resize(m);
  for (auto& [x, y] : B) cin >> x >> y;
  TrianglePointCount<P, 500, 500> tpc(A, B);
  int q;
  cin >> q;
  while (q--) {
    int a, b, c;
    cin >> a >> b >> c;
    cout << tpc.query(a, b, c) << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tc = 1;
  // cin >> tc;
  while (tc--) solve();
}