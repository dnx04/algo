#define PROBLEM "https://judge.yosupo.jp/problem/discrete_logarithm_mod"
#define IGNORE

#include "../misc/macros.h"
#include "../math/ModLog.h"

void solve() {
  ll a, b, m;
  cin >> a >> b >> m;
  if (m == 1 || b == 1) {  // because of the bs nonnegative and 0^0 = 1
    cout << 0 << '\n';
    return;
  }
  cout << modLog(a, b, m) << '\n';
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
