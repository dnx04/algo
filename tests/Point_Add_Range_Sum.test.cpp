#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "../misc/macros.h"
#include "../ds/Fenwick.h"

void solve() {
  int n, q;
  cin >> n >> q;
  Fenwick<i64> fw(n);
  for (int i = 1; i <= n; ++i) {
    i64 x;
    cin >> x;
    fw.add(i, x);
  }
  while (q--) {
    int cmd;
    cin >> cmd;
    if (cmd == 0) {
      int p, x;
      cin >> p >> x;
      ++p;
      fw.add(p, x);
    } else {
      int l, r;
      cin >> l >> r;
      ++l;
      cout << fw.sum(l, r) << '\n';
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
