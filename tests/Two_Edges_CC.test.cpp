#define PROBLEM "https://judge.yosupo.jp/problem/two_edge_connected_components"

#include "../misc/macros.h"
#include "../graph/2CC.h"

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vi> g(n);
  for(int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    g[u].eb(v), g[v].eb(u);
  }
  ECC t(g);
  cout << sz(t.comps) << '\n';
  for(auto comp: t.comps) {
    cout << sz(comp) << ' ';
    for(auto u: comp) cout << u << ' ';
    cout << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  solve();
  return 0;
}