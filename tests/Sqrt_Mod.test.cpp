#define PROBLEM "https://judge.yosupo.jp/problem/sqrt_mod"

#include "../misc/macros.h"
#include "../math/ModInt.h"
#include "../math/ModSQRT.h"

void solve() {
  int y, p;
  cin >> y >> p;
  cout << modsqrt(y, p) << '\n';
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
