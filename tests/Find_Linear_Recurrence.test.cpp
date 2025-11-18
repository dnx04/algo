#define PROBLEM "https://judge.yosupo.jp/problem/find_linear_recurrence"

#include "../misc/macros.h"
#include "../math/ModInt.h"
#include "../math/LinearRec.h"

using Fp = modint<998244353>;

void solve() {
  int d;
  cin >> d;
  vector<Fp> a(d);
  for (int i = 0; i < d; ++i) cin >> a[i];
  auto cs = LinearRec(a);
  cout << sz(cs) - 1 << '\n';
  for (int i = 1; i < sz(cs); ++i) cout << cs[i] << ' ';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tc = 1;
  // cin >> tc;
  for (int i = 1; i <= tc; ++i) {
    solve();
  }
}
