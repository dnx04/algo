#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_cliques"

#include "../misc/macros.h"
#include "../math/ModInt.h"
#include "../misc/MaximalCliques.h"

using Fp = modint<998244353>;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<Fp> x(n);
  for (int i = 0; i < n; ++i) cin >> x[i];
  vector<bs> g(n, bs(n));
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    g[u][v] = g[v][u] = 1;
  }
  Fp ans = 0;
  cliques(g, [&](const bs& clique) {
    if(!clique.any()) return;
    Fp prod = 1;
    for(int i = clique.find_first(); i < n; i = clique.find_next(i)) prod *= x[i];
    ans += prod; }, ~bs(n), bs(n), bs(n));
  cout << ans << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tc = 1;
  //   cin >> tc;
  for (int i = 1; i <= tc; ++i) {
    solve();
  }
}
