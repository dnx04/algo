#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_xor_convolution"

#include "../misc/macros.h"
#include "../math/ModInt.h"

using Fp = modint<998244353>;

#include "../math/FST.h"

void solve() {
  int n;
  cin >> n;
  vector<Fp> a(1 << n), b(1 << n);
  for (int i = 0; i < (1 << n); ++i) cin >> a[i];
  for (int i = 0; i < (1 << n); ++i) cin >> b[i];
  auto c = conv(a, b, "xor");
  for (int i = 0; i < (1 << n); ++i) cout << c[i] << " \n"[i == (1 << n) - 1];
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
