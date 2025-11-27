#define PROBLEM "https://judge.yosupo.jp/problem/product_of_polynomial_sequence"

#include "../misc/macros.h"
#include "../math/Poly.h"

void solve() {
  int n;
  cin >> n;
  if (n == 0) {
    cout << 1;
    return;
  }
  deque<Poly> dq;
  for (int i = 0; i < n; ++i) {
    int d;
    cin >> d;
    Poly p;
    for (int j = 0; j <= d; ++j) {
      int c;
      cin >> c;
      p.eb(c);
    }
    dq.push_back(p);
  }
  for (int i = 0; i < n - 1; ++i) {
    auto f = dq.front();
    dq.pop_front();
    auto g = dq.front();
    dq.pop_front();
    dq.eb(f * g);
  }
  auto ans = dq.front();
  for (auto v : ans) cout << v << ' ';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tc = 1;
  // cin >> tc;
  while (tc--) solve();
}