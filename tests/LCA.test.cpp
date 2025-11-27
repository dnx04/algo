#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include "../misc/macros.h"
#include "../ds/HLD.h"

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<i64> a(n);
  vector<vi> g(n);
  for (int i = 1; i < n; ++i) {
    int p;
    cin >> p;
    g[p].eb(i), g[i].eb(p);
  }
  auto hld = HLD(g);
  while (q--) {
    int u, v;
    cin >> u >> v;
    cout << hld.lca(u, v) << '\n';
  }
}