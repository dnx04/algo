#define PROBLEM "https://judge.yosupo.jp/problem/maximum_independent_set"

#include "../misc/macros.h"
#include "../misc/MaximumClique.h"

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, m;
  cin >> n >> m;
  vector<bs> eds(n, bs(n));
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    eds[u][v] = eds[v][u] = 1;
  }
  for (int i = 0; i < n; ++i) {
    eds[i].flip();
    eds[i][i] = 0;
  }
  Maxclique mc(eds);
  auto ans = mc.maxClique();
  cout << sz(ans) << '\n';
  for (auto i : mc.qmax) cout << i << ' ';
}
