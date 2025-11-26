#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include "../misc/macros.h"
#include "../math/Poly.h"

void solve() {
  int n, m;
  cin >> n >> m;
  Poly a(n), b(m);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < m; ++i) cin >> b[i];
  auto c = a * b;
  for (auto x : c) cout << x << ' ';
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
