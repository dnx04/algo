#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite_large_array"

#include "../misc/macros.h"
#include "../math/ModInt.h"
#include "../math/Affine.h"
#include "../ds/PersistentSegTree.h"

using Fp = modint<998244353>;
using A = affine<Fp>;

void solve() {
  int n, q;
  cin >> n >> q;
  PST pst(n, [&](const A& l, const A& r) { return l * r; }, A{});
  decltype(pst)::Node* root = nullptr;
  while (q--) {
    int cmd;
    cin >> cmd;
    if (cmd == 0) {
      int p, c, d;
      cin >> p >> c >> d;
      auto new_node = pst.apply(root, 0, n - 1, p, A{c, d});
      root = new_node;
    } else {
      int l, r, x;
      cin >> l >> r >> x;
      auto fc = pst.query(root, 0, n - 1, l, r - 1);
      cout << fc(x) << '\n';
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
