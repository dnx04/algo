#define PROBLEM "https://judge.yosupo.jp/problem/closest_pair"

#include "../misc/macros.h"
#include "../geometry/ClosestPair.h"

void solve() {
  int n;
  cin >> n;
  vector<Point<ll>> p(n);
  for (int i = 0; i < n; ++i) cin >> p[i].x >> p[i].y;
  auto ans = closest(p);
  int p1, p2;
  for (int i = 0; i < n; ++i) {
    if (p[i] == ans.first) {
      p1 = i;
      break;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (i != p1 && p[i] == ans.second) {
      p2 = i;
      break;
    }
  }
  cout << p1 << ' ' << p2 << '\n';
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
