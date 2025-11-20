#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"

#include "../misc/macros.h"
#include "../ds/LineContainer.h"

void solve() {
  int n, q;
  cin >> n >> q;
  LineContainer cht;
  for (int i = 0; i < n; ++i) {
    i64 a, b;
    cin >> a >> b;
    cht.add(-a, -b);
  }
  while (q--) {
    int cmd;
    cin >> cmd;
    if (cmd == 0) {
      i64 a, b;
      cin >> a >> b;
      cht.add(-a, -b);
    } else {
      i64 p;
      cin >> p;
      cout << -cht.query(p) << '\n';
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