#define PROBLEM "https://judge.yosupo.jp/problem/persistent_unionfind"

#include <bits/extc++.h>

using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

#include "../ds/DSURollback.h"

struct Query {
  int t, k, u, v;
};

void solve() {
  int n, q;
  cin >> n >> q;
  DSURollback dsu(n);
  vector<Query> qry(q + 1);
  vector<vector<int>> qry_g(q + 1);
  for (int i = 1; i <= q; ++i) {
    cin >> qry[i].t >> qry[i].k >> qry[i].u >> qry[i].v;
    ++qry[i].k;
    qry_g[qry[i].k].push_back(i);
  }
  vector<int> ans(q + 1);
  auto dfs = [&](auto self, int idx) -> void {
    int t = dsu.time();
    if (qry[idx].t == 0) {
      dsu.join(qry[idx].u, qry[idx].v);
    } else {
      ans[idx] = dsu.find(qry[idx].u) == dsu.find(qry[idx].v);
    }
    for (int i : qry_g[idx]) {
      self(self, i);
    }
    if (qry[idx].t == 0) {
      dsu.rollback(t);
    }
  };
  dfs(dfs, 0);
  for (int i = 1; i <= q; ++i) {
    if (qry[i].t == 1) {
      cout << ans[i] << '\n';
    }
  }
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
