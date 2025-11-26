#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define fi first
#define se second
using i64 = long long;
using pii = pair<int, int>;

void solve() {
  int n, S;
  cin >> n >> S;
  set<pii> ed;
  for (int i = 0; i < n * n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    ed.insert({u, v});
  }
  vector<vector<pair<int, pii>>> g(n * n);
  auto valid_tile = [&](int x, int y) {
    return 0 <= x && x <= n - 1 && 0 <= y && y <= n - 1;
  };
  for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j < n - 1; ++j) {
      int u = i * n + j;
      if (!ed.count({u, u + 1}) && valid_tile(i - 1, j)) {
        g[i * (n - 1) + j].pb({(i - 1) * (n - 1) + j, {u, u + 1}});
        g[(i - 1) * (n - 1) + j].pb({i * (n - 1) + j, {u, u + 1}});
        // cout << i * (n - 1) + j << ' ' << (i - 1) * (n - 1) + j << '\n';
      }
      if (!ed.count({u, u + n}) && valid_tile(i, j - 1)) {
        g[i * (n - 1) + j].pb({i * (n - 1) + j - 1, {u, u + n}});
        g[i * (n - 1) + j - 1].pb({i * (n - 1) + j, {u, u + n}});
        // cout << i * (n - 1) + j << ' ' << i * (n - 1) + j - 1
      }
    }
  }
  vector<int> sub((n - 1) * (n - 1)), par((n - 1) * (n - 1), -1);
  vector<pii> ans;
  auto dfs = [&](auto&& self, int u, int p, pii par_edge) -> void {
    sub[u] = 1;
    for (auto [v, e] : g[u]) {
      if (v != p) {
        par[v] = u;
        self(self, v, u);
        sub[u] += sub[v];
      }
    }
  };
  for (int i = 0; i < n - 1; ++i) {
    if (!ed.count({i, i + 1})) {
      dfs(dfs, i, -1);
      // cout << i << '\n';
    }
    if (!ed.count({n * (n - 1) + i, n * (n - 1) + i + 1})) {
      dfs(dfs, (n - 1) * (n - 2) + i, -1);
      // cout << (n - 1) * (n - 2) + i << '\n';
    }
    if (!ed.count({i * n, i * n + n})) {
      dfs(dfs, i * (n - 1), -1);
      // cout << i * (n - 1) << '\n';
    }
    if (!ed.count({i * n + n - 1, i * n + n + n - 1})) {
      dfs(dfs, i * (n - 1) + (n - 2), -1);
      // cout << i * (n - 1) + (n - 2) << '\n';
    }
  }
  vector<pii> cand;
  // for (int i = 0; i < n - 1; ++i) {
  //   for (int j = 0; j < n - 1; ++j) {
  //     if (sub[i * (n - 1) + j] == S) {
  //       find_edge(i * (n - 1) + j, par[i * (n - 1) + j]);
  //     }
  //   }
  // }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
}