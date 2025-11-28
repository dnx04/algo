#define PROBLEM "https://judge.yosupo.jp/problem/maximum_independent_set"

#include "../misc/macros.h"
#include "../graph/Cliques.h"

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, m;
  cin >> n >> m;
  vector<bs> adj(n, bs(n));
  for (int i = 0; i < n; ++i) {
    adj[i].set();     // Full 1
    adj[i][i] = 0;    // QUAN TRỌNG: Tắt self-loop
  }
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u][v] = adj[v][u] = 0;
  }
  bs P(n), R(n), sol(n); 
  u32 ans=0; P.set(); 
  MaxClique(adj, P, R, sol, ans);
  cout << ans << '\n';
  for (int i = sol.find_first(); i < sz(sol); i = sol.find_next(i)) {
    cout << i << ' ';
  }
}
