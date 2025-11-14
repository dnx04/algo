#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_floor_of_linear"

#include "../misc/macros.h"

#include "../math/DivModSum.h"

void solve() {
  ll n, m, a, b;
  cin >> n >> m >> a >> b;
  cout << divsum(b, a, m, n) << '\n';
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
