#define PROBLEM "https://judge.yosupo.jp/problem/sort_points_by_argument"

#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#include "../geometry/Point.h"

typedef Point<ll> P;

void solve() {
  int n;
  cin >> n;
  vector<P> pts(n);
  rep(i, 0, n) cin >> pts[i].x >> pts[i].y;
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
