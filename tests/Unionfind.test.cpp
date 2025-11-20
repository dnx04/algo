#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include "../misc/macros.h"
#include "../ds/DSU.h"

void solve() {
  int n, q;
  cin >> n >> q;
  DSU d(n);
  while (q--) {
    int cmd, u, v;
    cin >> cmd >> u >> v;
    if (cmd == 0) {
      d.merge(u, v);
    } else {
      cout << d.same(u, v) << '\n';
    }
  }
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