#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_quotients"

#include "../misc/macros.h"
#include "../math/EnumQuotients.h"

void solve() {
  ll n;
  cin >> n;
  auto q = EnumerateQuotients(n);
  cout << sz(q) << '\n';
  for (auto d : q) cout << d << ' ';
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
