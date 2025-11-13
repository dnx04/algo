#define PROBLEM "https://judge.yosupo.jp/problem/static_convex_hull"

#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

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
