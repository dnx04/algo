#define PROBLEM "https://judge.yosupo.jp/problem/deque_operate_all_composite"

#include "../misc/macros.h"
#include "../math/ModInt.h"
#include "../math/Affine.h"
#include "../ds/SWAG.h"

void solve() {
  using Fp = modint<998244353>;
  using A = affine<Fp>;
  int q;
  cin >> q;
  SlideWindowAggregationDeque swag([](const A& f, const A& g) { return f * g; }, A{});
  while (q--) {
    int cmd;
    cin >> cmd;
    if (cmd == 0) {
      int a, b;
      cin >> a >> b;
      swag.push_front({a, b});
    } else if (cmd == 1) {
      int a, b;
      cin >> a >> b;
      swag.push_back({a, b});
    } else if (cmd == 2) {
      swag.pop_front();
    } else if (cmd == 3) {
      swag.pop_back();
    } else {
      int x;
      cin >> x;
      cout << swag.query()(x) << '\n';
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
