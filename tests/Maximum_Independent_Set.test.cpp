#define PROBLEM "https://judge.yosupo.jp/problem/maximum_independent_set"

#include "../misc/macros.h"
#include "../graph/Cliques.h"

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, m;
  cin >> n >> m;
  vector<bs> adj(n, bs(n));
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u][v] = adj[v][u] = 1;
  }
  for (int i = 0; i < n; ++i) {
    adj[i].set(), adj[i][i] = 0;
  }
  bs P(n), R(n), sol(n); 
  int ans=0; P.set(); 
  MaxClique(adj, P, R, sol, ans);
  cout << ans << '\n';
  // for (int i = sol.find_first(); i != bs::npos; i = sol.find_next(i)) {
  //   cout << i << ' ';
  // }
}
