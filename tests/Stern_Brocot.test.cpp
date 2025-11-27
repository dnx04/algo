#define PROBLEM "https://judge.yosupo.jp/problem/stern_brocot_tree"

#include "../misc/macros.h"
#include "../math/SternBrocot.h"

void solve() {
  string cmd;
  cin >> cmd;
  if(cmd == "ENCODE_PATH") {
    int a, b;
    cin >> a >> b;
    auto res = SternBrocot::encode(a, b);
    cout << sz(res) << ' ';
    for(auto [ch, mv]: res) cout << ch << ' ' << mv << ' ';
    cout << '\n';
  } else if(cmd == "DECODE_PATH") {
    Path p;
    int k;
    cin >> k;
    while(k--) {
      char ch;
      int mv;
      cin >> ch >> mv;
      p.eb(ch, mv);
    }
    auto res = SternBrocot::decode(p);
    cout << res.p << ' ' << res.q << '\n';
  } else if(cmd == "LCA") {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    auto res = SternBrocot::lca(a, b, c, d);
    cout << res.p << ' ' << res.q << '\n';
  } else if(cmd == "ANCESTOR") {
    int k, a, b;
    cin >> k >> a >> b;
    auto res = SternBrocot::ancestor(k, a, b);
    if(res.p == -1) {
      cout << -1 << '\n';
      return;
    }
    cout << res.p << ' ' << res.q << '\n';
  } else {
    int a, b;
    cin >> a >> b;
    auto [lo, hi] = SternBrocot::range(a, b);
    cout << lo.p << ' ' << lo.q << ' ' << hi.p << ' ' << hi.q << '\n';
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tc = 1;
  cin >> tc;
  while (tc--) solve();
}