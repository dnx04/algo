#define PROBLEM "https://judge.yosupo.jp/problem/biconnected_components"

#include "../misc/macros.h"
#include "../graph/2CC.h"

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vi> g(n);
  for(int i= 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    g[u].eb(v), g[v].eb(u);
  }
  BCC t(g);
  cout << sz(t.blks) << '\n';
  for(auto blk: t.blks) {
    cout << sz(blk) << ' ';
    for(auto u: blk) cout << u << ' ';
    cout << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  solve();
  return 0;
}