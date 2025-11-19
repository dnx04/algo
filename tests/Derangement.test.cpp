#define PROBLEM "https://judge.yosupo.jp/problem/montmort_number_mod"

#include "../misc/macros.h"

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> d(n + 1);
  d[1] = 0, d[2] = 1;
  for (int i = 3; i <= n; ++i) d[i] = 1ll * (i - 1) * (d[i - 1] + d[i - 2]) % m;
  for (int i = 1; i <= n; ++i) cout << d[i] << ' ';
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