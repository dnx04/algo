#define PROBLEM "https://judge.yosupo.jp/problem/gcd_convolution"

#include "../misc/macros.h"
#include "../math/ZetaMobius.h"
#include "../math/ModInt.h"

void solve() {
  using Fp = modint<998244353>;
  int n;
  cin >> n;
  sieve(n);
  vector<Fp> a(n + 1), b(n + 1);
  for(int i = 1; i <= n; ++i) cin >> a[i];
  for(int i = 1; i <= n; ++i) cin >> b[i];
  auto c = convolution(a, b, 0);
  // cerr << "ok";
  for(int i = 1; i <= n; ++i) cout << c[i] << ' ';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tc = 1;
  // cin >> tc;
  while (tc--) solve();
}