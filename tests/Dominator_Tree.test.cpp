#define PROBLEM "https://judge.yosupo.jp/problem/dominatortree"

#include "../misc/macros.h"
#include "../graph/Dominator.h"

void solve() {
  int n, m, s;
  cin >> n >> m >> s;
  vector<vi> g(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    g[u].pb(v);
  }
  auto tree = DomTree(g, s);
  tree[s] = s;
  for (int i = 0; i < n; ++i) cout << tree[i] << ' ';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tc = 1;
  // cin >> tc;
  for (int i = 1; i <= tc; ++i) {
    solve();
  }
}
