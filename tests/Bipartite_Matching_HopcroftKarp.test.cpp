#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"

#include "../misc/macros.h"
#include "../graph/HopcroftKarp.h"

void solve() {
  int l, r, m;
  cin >> l >> r >> m;
  HopcroftKarp g(l, r);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    g.add(a, b);
  }
  cout << g.solve() << '\n';
  for (int i = 0; i < r; ++i) {
    if (g.btoa[i] != -1) {
      cout << g.btoa[i] << ' ' << i << '\n';
    }
  }
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
