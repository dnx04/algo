#define PROBLEM "https://judge.yosupo.jp/problem/subset_convolution"

#include "../misc/macros.h"
#include "../math/ModInt.h"
#include "../math/FST.h"

using namespace FST;
using Fp = modint<998244353>;

void solve() {
  int n;
  cin >> n;
  vector<Fp> a(1 << n), b(1 << n);
  for (int i = 0; i < (1 << n); ++i) cin >> a[i];
  for (int i = 0; i < (1 << n); ++i) cin >> b[i];
  auto c = subsetConv(a, b);
  for(auto e: c) cout << e << ' ';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tc = 1;
  // cin >> tc;
  while (tc--) solve();
}