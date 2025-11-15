#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include "../misc/macros.h"
#include "../math/Affine.h"
#include "../math/ModInt.h"
#include "../ds/SegTree.h"

using Fp = modint<998244353>;
using A = affine<Fp>;

void solve() {
  int n, q;
  cin >> n >> q;
  SegTree st(n, [&](const A& l, const A& r) { return l * r; }, A{});
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    st.upd(i + 1, {a, b});
  }
  while (q--) {
    int cmd;
    cin >> cmd;
    if (cmd == 0) {
      int p, c, d;
      cin >> p >> c >> d;
      ++p;
      st.upd(p, {c, d});
    } else {
      int l, r, x;
      cin >> l >> r >> x;
      ++l, ++r;
      auto fc = st.qry(l, r);
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
