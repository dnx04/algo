#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include "../misc/macros.h"
#include "../graph/SCC.h"

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vi> g(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    g[u].eb(v);
  }
  SCC scc(g);
  cout << sz(scc.dag) << '\n';
  for (int i = 0; i < sz(scc.dag); ++i) {
    cout << sz(scc.belong(i)) << ' ';
    for (auto v : scc.belong(i)) cout << v << ' ';
    cout << '\n';
  }
}

int main() {
  solve();
}