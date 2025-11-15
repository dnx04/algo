#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_triangles"

#include "../misc/macros.h"
#include "../math/ModInt.h"
#include "../graph/EnumTriangles.h"

using Fp = modint<998244353>;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  Fp x[n];
  for (int i = 0; i < n; ++i) cin >> x[i];
  vector<pii> ed;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    ed.eb(u, v);
  }
  Fp res = 0;
  EnumTriangles(n, ed, [&](int a, int b, int c) {
    res += x[a] * x[b] * x[c];
  });
  cout << res;
}