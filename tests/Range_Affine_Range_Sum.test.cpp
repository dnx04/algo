#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include "../misc/macros.h"
#include "../math/ModInt.h"
#include "../ds/LazySegTree.h"

using Fp = modint<998244353>;

void solve() {
  int n, q;
  cin >> n >> q;

  using P = pair<Fp, Fp>;
  auto f = [](P a, P b) { return P{a.first + b.first, a.second + b.second}; };
  auto m = [](P a, P b) { return P{a.first * b.first + a.second * b.second, a.second}; };
  auto c = [](P a, P b) { return P{a.first * b.first, a.second * b.first + b.second}; };
  P I = {0, 0};
  P L0 = {1, 0};
  LazySegTree t(n, I, L0, f, m, c);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    t.set(i, P{x, 1});
  }
  while (q--) {
    int cmd;
    cin >> cmd;
    if (cmd == 0) {
      int l, r, c, d;
      cin >> l >> r >> c >> d;
      t.apply(l, r, P{c, d});
    } else {
      int l, r;
      cin >> l >> r;
      cout << t.query(l, r).first << '\n';
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
