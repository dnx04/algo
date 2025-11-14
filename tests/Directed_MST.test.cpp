#define PROBLEM "https://judge.yosupo.jp/problem/directedmst"

#include "../misc/macros.h"
#include "../graph/DirectedMST.h"

void solve() {
  int n, m, s;
  cin >> n >> m >> s;
  vector<Edge> edges;
  for (int i = 0; i < m; ++i) {
    int a, b;
    ll w;
    cin >> a >> b >> w;
    edges.push_back({a, b, w});
  }
  for (int i = 0; i < n; i++) {
    if (i != s) edges.push_back({i, s, 0});
  }
  auto [res, par] = DMST(n, s, edges);
  vi ans(n);
  ans[s] = s;
  for (auto i : par) {
    ans[edges[i].b] = edges[i].a;
  }
  cout << res << '\n';
  if (res != -1) {
    for (auto x : ans) cout << x << ' ';
  }
  // if (res == -1) {
  //   cout << "NO\n";
  // } else {
  //   cout << "YES\n";
  //   for(int i = 0; i < n; ++i) {
  //     if (i == s) continue;
  //     cout << par[i] << '\n';
  //   }
  // }
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
