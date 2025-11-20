#define PROBLEM "https://judge.yosupo.jp/problem/eulerian_trail_undirected"

#include "../misc/macros.h"
#include "../graph/EulerWalk.h"

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<pii>> g(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    g[u].eb(v, i), g[v].eb(u, i);
  }
  auto [nodes, edges] = EulerWalk(n, g, m, false, false);
  if (!nodes.empty()) {
    cout << "Yes\n";
    for (auto u : nodes) cout << u << ' ';
    cout << '\n';
    for (auto e : edges) cout << e << ' ';
    cout << '\n';
  } else {
    cout << "No\n";
  }
}

int main() {
  int tc;
  cin >> tc;
  while (tc--) solve();
}