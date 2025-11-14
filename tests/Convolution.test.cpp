#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include "../misc/macros.h"

#include "../math/NTT.h"

void solve() {
  int n, m;
  cin >> n >> m;
  vl a(n), b(m);
  rep(i, 0, n) cin >> a[i];
  rep(i, 0, m) cin >> b[i];
  auto c = convMod<998244353>(a, b);
  for (ll x : c) cout << x << ' ';
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
