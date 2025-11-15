#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"

#include "../misc/macros.h"
#include "../ds/Fenwick.h"
#include "../ds/HLD.h"

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, q;
  cin >> n >> q;
  Fenwick<ll> fw(n);
  vector<ll> a(n);
  vector<vi> g(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    g[u].eb(v), g[v].eb(u);
  }
  auto hld = HLD(g);
  for (int i = 0; i < n; ++i) fw.add(hld.idx(i).first + 1, a[i]);
  while (q--) {
    int cmd;
    cin >> cmd;
    if (cmd == 0) {
      int p, x;
      cin >> p >> x;
      fw.add(hld.idx(p).first + 1, x);
    } else {
      int u, v;
      cin >> u >> v;
      ll res = 0;
      hld.path_query(u, v, true, [&](const int& u, const int& v) {
        res += fw.sum(u + 1, v);
      });
      cout << res << '\n';
    }
  }
}