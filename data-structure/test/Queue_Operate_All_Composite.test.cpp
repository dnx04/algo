#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"

#include "bits/extc++.h"

using namespace std;

#include "../algo/data-structure/swag.hpp"
#include "../algo/number-theory/modint.hpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  using mint = Mod<998244353>;
  struct F {
    mint a, b;
  };
  auto op = [&](F l, F r) -> F {
    mint na = l.a * r.a, nb = l.b * r.a + r.b;
    return F{na, nb};
  };
  SWAG<F, decltype(op)> swag(F{1, 0}, op);

  int Q;
  cin >> Q;
  while (Q--) {
    int t;
    cin >> t;
    if (t == 0) {
      mint a, b;
      cin >> a >> b;
      swag.push(F{a, b});
    } else if (t == 1) {
      swag.pop();
    } else {
      mint x;
      cin >> x;
      auto f = swag.sum();
      cout << f.a * x + f.b << '\n';
    }
  }
}