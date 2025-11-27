#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"

#include "../misc/macros.h"
#include "../ds/Fenwick.h"
#include "../ds/HLD.h"

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, q;
  cin >> n >> q;
  Fenwick<i64> fw(n);
  vector<i64> a(n);
  vector<vi> g(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    g[u].eb(v), g[v].eb(u);
  }
  auto hld = HLD(g);
  for (int i = 0; i < n; ++i) fw.add(hld.idx(i), a[i]);
  while (q--) {
    int cmd;
    cin >> cmd;
    if (cmd == 0) {
      int p, x;
      cin >> p >> x;
      fw.add(hld.idx(p), x);
    } else {
      int u, v;
      cin >> u >> v;
      i64 res = 0;
      auto paths = hld.query_path(u, v);
      for (auto [v1, v2] : paths) {
        int u = v1, v = v2;
        if (u > v) swap(u, v);
        res += fw.sum(u, v);
      }
      cout << res << '\n';
    }
  }
}