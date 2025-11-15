#define PROBLEM "https://judge.yosupo.jp/problem/general_matching"

#include "../misc/macros.h"
#include "../graph/GeneralMatching.h"

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vi> graph(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    graph[u].pb(v), graph[v].pb(u);
  }
  auto match = GeneralMatching(graph);
  vector<pii> mate;
  for (int i = 0; i < n; ++i) {
    if (i < match[i]) mate.pb({i, match[i]});
  }
  cout << sz(mate) << '\n';
  for (auto [u, v] : mate) cout << u << ' ' << v << '\n';
}